/* MPL 2.0 */
#include <cstdint>
//! JavaScript Engine abstraction layer.
#pragma once
#include <string>
#include <functional>
#include <memory>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstdlib>

namespace js {

enum class JSType : uint8_t { Undefined, Null, Boolean, Number, String, Object, Array, Function };

struct JSValue {
    JSType type = JSType::Undefined;
    bool bool_val = false;
    double number_val = 0.0;
    std::string string_val;
    
    static JSValue undefined() { return {}; }
    static JSValue null() { JSValue v; v.type = JSType::Null; return v; }
    static JSValue boolean(bool b) { JSValue v; v.type = JSType::Boolean; v.bool_val = b; return v; }
    static JSValue number(double n) { JSValue v; v.type = JSType::Number; v.number_val = n; return v; }
    static JSValue string(const std::string& s) { JSValue v; v.type = JSType::String; v.string_val = s; return v; }
    
    bool isUndefined() const { return type == JSType::Undefined; }
    bool isNull() const { return type == JSType::Null; }
    bool isNumber() const { return type == JSType::Number; }
    bool isString() const { return type == JSType::String; }
    
    std::string toString() const {
        switch (type) {
            case JSType::Undefined: return "undefined";
            case JSType::Null: return "null";
            case JSType::Boolean: return bool_val ? "true" : "false";
            case JSType::Number: return std::to_string(number_val);
            case JSType::String: return string_val;
            default: return "[object]";
        }
    }
};

class JSEngine {
public:
    virtual ~JSEngine() = default;
    virtual bool init() = 0;
    virtual JSValue evaluate(const std::string& code) = 0;
    virtual void execute(const std::string& code) = 0;
    virtual JSValue callFunction(const std::string& name, const std::vector<JSValue>& args = {}) = 0;
    virtual void registerFunction(const std::string& name, std::function<JSValue(const std::vector<JSValue>&)> fn) = 0;
    virtual void setGlobal(const std::string& name, const JSValue& value) = 0;
    virtual JSValue getGlobal(const std::string& name) = 0;
    virtual bool supportsModernJS() const = 0;
    virtual std::string engineVersion() const = 0;
};

class StubJSEngine : public JSEngine {
public:
    bool init() override { return true; }
    
    JSValue evaluate(const std::string& code) override {
        if (code.empty()) return JSValue::undefined();
        try { size_t pos; double num = std::stod(code, &pos); if (pos == code.size()) return JSValue::number(num); } catch (...) {}
        if (code == "true") return JSValue::boolean(true);
        if (code == "false") return JSValue::boolean(false);
        if (code == "null") return JSValue::null();
        if (code == "undefined") return JSValue::undefined();
        if (code.size() >= 2 && code[0] == '"' && code[code.size()-1] == '"')
            return JSValue::string(code.substr(1, code.size() - 2));
        for (char op : {'+', '-', '*', '/'}) {
            size_t pos = code.find(op);
            if (pos != std::string::npos && pos > 0) {
                try {
                    double left = std::stod(code.substr(0, pos));
                    double right = std::stod(code.substr(pos + 1));
                    switch (op) {
                        case '+': return JSValue::number(left + right);
                        case '-': return JSValue::number(left - right);
                        case '*': return JSValue::number(left * right);
                        case '/': return right != 0 ? JSValue::number(left / right) : JSValue::undefined();
                    }
                } catch (...) {}
            }
        }
        return JSValue::undefined();
    }
    
    void execute(const std::string& code) override { evaluate(code); }
    JSValue callFunction(const std::string&, const std::vector<JSValue>&) override { return JSValue::undefined(); }
    void registerFunction(const std::string& name, std::function<JSValue(const std::vector<JSValue>&)> fn) override { funcs_[name] = fn; }
    void setGlobal(const std::string& name, const JSValue& value) override { globals_[name] = value; }
    JSValue getGlobal(const std::string& name) override { auto it = globals_.find(name); return it != globals_.end() ? it->second : JSValue::undefined(); }
    bool supportsModernJS() const override { return false; }
    std::string engineVersion() const override { return "StubJS/1.0"; }
private:
    std::unordered_map<std::string, JSValue> globals_;
    std::unordered_map<std::string, std::function<JSValue(const std::vector<JSValue>&)>> funcs_;
};

std::unique_ptr<JSEngine> createJSEngine();

} // namespace js
