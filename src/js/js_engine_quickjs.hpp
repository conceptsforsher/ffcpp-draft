/* MPL 2.0 */
//! QuickJS-based C++ JavaScript engine — ES2020+ support.
//! Uses a C wrapper layer to avoid C++/C incompatibility with QuickJS struct mode.
#pragma once
#include "js/js_engine.hpp"

// C wrapper declarations (defined in quickjs_c_wrapper.c)
extern "C" {

typedef struct JSContext JSContext;
typedef struct JSRuntime JSRuntime;
// JSValue is an opaque struct — we never access its fields directly from C++
typedef struct JSValue { uint64_t u; int64_t tag; } JSValue;

JSRuntime*  quickjs_new_runtime(void);
void        quickjs_free_runtime(JSRuntime* rt);
JSContext*  quickjs_new_context(JSRuntime* rt);
void        quickjs_free_context(JSContext* ctx);

JSValue     quickjs_eval(JSContext* ctx, const char* code, size_t len, const char* filename);

int         quickjs_is_undefined(JSValue v);
int         quickjs_is_null(JSValue v);
int         quickjs_is_bool(JSValue v);
int         quickjs_is_number(JSValue v);
int         quickjs_is_string(JSValue v);
int         quickjs_is_object(JSValue v);
int         quickjs_is_array(JSContext* ctx, JSValue v);
int         quickjs_is_function(JSContext* ctx, JSValue v);
int         quickjs_is_exception(JSValue v);

int         quickjs_to_bool(JSContext* ctx, JSValue v);
double      quickjs_to_float64(JSContext* ctx, JSValue v);
int         quickjs_to_int32(JSContext* ctx, JSValue v);
const char* quickjs_to_cstring(JSContext* ctx, JSValue v);
void        quickjs_free_cstring(JSContext* ctx, const char* s);

JSValue     quickjs_new_undefined(void);
JSValue     quickjs_new_null(void);
JSValue     quickjs_new_bool(JSContext* ctx, int v);
JSValue     quickjs_new_int32(JSContext* ctx, int32_t v);
JSValue     quickjs_new_float64(JSContext* ctx, double v);
JSValue     quickjs_new_string(JSContext* ctx, const char* s);
JSValue     quickjs_new_object(JSContext* ctx);

void        quickjs_free_value(JSContext* ctx, JSValue v);

JSValue     quickjs_get_global_object(JSContext* ctx);
JSValue     quickjs_get_property(JSContext* ctx, JSValue obj, const char* name);
int         quickjs_set_property(JSContext* ctx, JSValue obj, const char* name, JSValue val);

JSValue     quickjs_call_function(JSContext* ctx, JSValue func, JSValue this_obj,
                                  int argc, JSValue* argv);

JSValue     quickjs_get_exception(JSContext* ctx);
void        quickjs_setup_console(JSContext* ctx);

} // extern "C"

namespace js {

// QuickJS version string
static constexpr const char* QUICKJS_VERSION = "2025-09-13";

// --- Value conversion (using C wrapper) ---
namespace detail {

inline ::JSValue toQuickJS(JSContext* ctx, const JSValue& v) {
    switch (v.type) {
        case JSType::Undefined: return quickjs_new_undefined();
        case JSType::Null:      return quickjs_new_null();
        case JSType::Boolean:   return quickjs_new_bool(ctx, v.bool_val ? 1 : 0);
        case JSType::Number:    return quickjs_new_float64(ctx, v.number_val);
        case JSType::String:    return quickjs_new_string(ctx, v.string_val.c_str());
        default:                return quickjs_new_undefined();
    }
}

inline JSValue fromQuickJS(JSContext* ctx, ::JSValue qv) {
    JSValue result;
    if (quickjs_is_undefined(qv)) { result.type = JSType::Undefined; }
    else if (quickjs_is_null(qv)) { result.type = JSType::Null; }
    else if (quickjs_is_bool(qv)) {
        result.type = JSType::Boolean;
        result.bool_val = quickjs_to_bool(ctx, qv) != 0;
    }
    else if (quickjs_is_number(qv)) {
        result.type = JSType::Number;
        result.number_val = quickjs_to_float64(ctx, qv);
    }
    else if (quickjs_is_string(qv)) {
        result.type = JSType::String;
        const char* s = quickjs_to_cstring(ctx, qv);
        if (s) { result.string_val = std::string(s); quickjs_free_cstring(ctx, s); }
        else   { result.string_val = ""; }
    }
    else if (quickjs_is_object(qv)) {
        int is_array = quickjs_is_array(ctx, qv);
        result.type = is_array ? JSType::Array : JSType::Object;
        result.string_val = is_array ? "[Array]" : "[Object]";
    }
    else if (quickjs_is_function(ctx, qv)) {
        result.type = JSType::Function;
        result.string_val = "[Function]";
    }
    else {
        result.type = JSType::Undefined;
    }
    return result;
}

} // namespace detail

class QuickJSEngine : public JSEngine {
public:
    QuickJSEngine() : rt_(nullptr), ctx_(nullptr) {}
    ~QuickJSEngine() override { shutdown(); }

    bool init() override {
        rt_ = quickjs_new_runtime();
        if (!rt_) return false;

        ctx_ = quickjs_new_context(rt_);
        if (!ctx_) { quickjs_free_runtime(rt_); rt_ = nullptr; return false; }

        quickjs_setup_console(ctx_);
        initialized_ = true;
        return true;
    }

    void shutdown() {
        if (ctx_) {
            quickjs_free_context(ctx_);
            ctx_ = nullptr;
        }
        if (rt_) {
            quickjs_free_runtime(rt_);
            rt_ = nullptr;
        }
        initialized_ = false;
    }

    JSValue evaluate(const std::string& code) override {
        if (!initialized_) return JSValue::undefined();

        ::JSValue result = quickjs_eval(ctx_, code.c_str(), code.size(), "<eval>");
        JSValue converted = detail::fromQuickJS(ctx_, result);

        if (quickjs_is_exception(result)) {
            ::JSValue exc = quickjs_get_exception(ctx_);
            const char* exc_str = quickjs_to_cstring(ctx_, exc);
            if (exc_str) {
                last_error_ = std::string(exc_str);
                quickjs_free_cstring(ctx_, exc_str);
            }
            quickjs_free_value(ctx_, exc);
            converted.string_val = "[Exception: " + last_error_ + "]";
            converted.type = JSType::String;
        }

        quickjs_free_value(ctx_, result);
        return converted;
    }

    void execute(const std::string& code) override {
        evaluate(code);
    }

    JSValue callFunction(const std::string& name,
                         const std::vector<JSValue>& args) override {
        if (!initialized_) return JSValue::undefined();

        ::JSValue global = quickjs_get_global_object(ctx_);
        ::JSValue func = quickjs_get_property(ctx_, global, name.c_str());

        if (quickjs_is_function(ctx_, func)) {
            std::vector<::JSValue> qargs;
            qargs.reserve(args.size());
            for (const auto& a : args) {
                qargs.push_back(detail::toQuickJS(ctx_, a));
            }

            ::JSValue result = quickjs_call_function(ctx_, func,
                quickjs_new_undefined(), (int)qargs.size(), qargs.data());
            JSValue converted = detail::fromQuickJS(ctx_, result);

            for (auto& qa : qargs) quickjs_free_value(ctx_, qa);
            quickjs_free_value(ctx_, result);
            quickjs_free_value(ctx_, func);
            quickjs_free_value(ctx_, global);
            return converted;
        }

        quickjs_free_value(ctx_, func);
        quickjs_free_value(ctx_, global);
        return JSValue::undefined();
    }

    void registerFunction(const std::string& name,
                          std::function<JSValue(const std::vector<JSValue>&)> fn) override {
        registered_funcs_[name] = std::move(fn);
    }

    void setGlobal(const std::string& name, const JSValue& value) override {
        if (!initialized_) return;
        ::JSValue global = quickjs_get_global_object(ctx_);
        ::JSValue qv = detail::toQuickJS(ctx_, value);
        quickjs_set_property(ctx_, global, name.c_str(), qv);
        quickjs_free_value(ctx_, qv);
        quickjs_free_value(ctx_, global);
    }

    JSValue getGlobal(const std::string& name) override {
        if (!initialized_) return JSValue::undefined();
        ::JSValue global = quickjs_get_global_object(ctx_);
        ::JSValue qv = quickjs_get_property(ctx_, global, name.c_str());
        JSValue result = detail::fromQuickJS(ctx_, qv);
        quickjs_free_value(ctx_, qv);
        quickjs_free_value(ctx_, global);
        return result;
    }

    bool supportsModernJS() const override { return true; }
    std::string engineVersion() const override {
        return std::string("QuickJS/") + QUICKJS_VERSION;
    }
    std::string lastError() const { return last_error_; }

private:
    JSRuntime* rt_;
    JSContext* ctx_;
    bool initialized_ = false;
    std::string last_error_;
    std::unordered_map<std::string, std::function<JSValue(const std::vector<JSValue>&)>> registered_funcs_;
};

} // namespace js
