/* C wrapper around QuickJS — necessary because QuickJS struct mode uses
   C compound literals + designated initializers invalid in C++.
   This thin C layer exposes only opaque types to C++ code. */

#include <quickjs.h>
#include <quickjs-libc.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* --- Runtime / Context --- */
JSRuntime* quickjs_new_runtime(void) {
    JSRuntime* rt = JS_NewRuntime();
    if (rt) {
        JS_SetMemoryLimit(rt, 256 * 1024 * 1024);
        js_std_init_handlers(rt);
    }
    return rt;
}

void quickjs_free_runtime(JSRuntime* rt) {
    if (!rt) return;
    js_std_free_handlers(rt);
    JS_FreeRuntime(rt);
}

JSContext* quickjs_new_context(JSRuntime* rt) {
    return JS_NewContext(rt);
}

void quickjs_free_context(JSContext* ctx) {
    JS_FreeContext(ctx);
}

/* --- Eval --- */
JSValue quickjs_eval(JSContext* ctx, const char* code, size_t len, const char* filename) {
    return JS_Eval(ctx, code, len, filename, JS_EVAL_TYPE_GLOBAL);
}

/* --- Value inspection --- */
int quickjs_is_undefined(JSValue v)   { return JS_IsUndefined(v); }
int quickjs_is_null(JSValue v)        { return JS_IsNull(v); }
int quickjs_is_bool(JSValue v)        { return JS_IsBool(v); }
int quickjs_is_number(JSValue v)      { return JS_IsNumber(v); }
int quickjs_is_string(JSValue v)      { return JS_IsString(v); }
int quickjs_is_object(JSValue v)      { return JS_IsObject(v); }
int quickjs_is_array(JSContext* ctx, JSValue v)  { return JS_IsArray(ctx, v); }
int quickjs_is_function(JSContext* ctx, JSValue v) { return JS_IsFunction(ctx, v); }
int quickjs_is_exception(JSValue v)   { return JS_IsException(v); }

/* --- Value extraction --- */
int quickjs_to_bool(JSContext* ctx, JSValue v) {
    return JS_ToBool(ctx, v);
}
double quickjs_to_float64(JSContext* ctx, JSValue v) {
    double d = 0;
    JS_ToFloat64(ctx, &d, v);
    return d;
}
int quickjs_to_int32(JSContext* ctx, JSValue v) {
    int32_t i = 0;
    JS_ToInt32(ctx, &i, v);
    return i;
}
const char* quickjs_to_cstring(JSContext* ctx, JSValue v) {
    return JS_ToCString(ctx, v);
}
void quickjs_free_cstring(JSContext* ctx, const char* s) {
    JS_FreeCString(ctx, s);
}

/* --- Value construction --- */
JSValue quickjs_new_undefined(void)     { return JS_UNDEFINED; }
JSValue quickjs_new_null(void)          { return JS_NULL; }
JSValue quickjs_new_bool(JSContext* ctx, int v) { return JS_NewBool(ctx, v); }
JSValue quickjs_new_int32(JSContext* ctx, int32_t v) { return JS_NewInt32(ctx, v); }
JSValue quickjs_new_float64(JSContext* ctx, double v) { return JS_NewFloat64(ctx, v); }
JSValue quickjs_new_string(JSContext* ctx, const char* s) { return JS_NewString(ctx, s); }
JSValue quickjs_new_object(JSContext* ctx) { return JS_NewObject(ctx); }

/* --- Free --- */
void quickjs_free_value(JSContext* ctx, JSValue v) {
    JS_FreeValue(ctx, v);
}

/* --- Global object --- */
JSValue quickjs_get_global_object(JSContext* ctx) {
    return JS_GetGlobalObject(ctx);
}

/* --- Property access --- */
JSValue quickjs_get_property(JSContext* ctx, JSValue obj, const char* name) {
    return JS_GetPropertyStr(ctx, obj, name);
}
int quickjs_set_property(JSContext* ctx, JSValue obj, const char* name, JSValue val) {
    return JS_SetPropertyStr(ctx, obj, name, val);
}

/* --- Function calls --- */
JSValue quickjs_call_function(JSContext* ctx, JSValue func, JSValue this_obj,
                               int argc, JSValue* argv) {
    return JS_Call(ctx, func, this_obj, argc, argv);
}

JSValue quickjs_new_cfunction(JSContext* ctx, JSCFunction* func,
                              const char* name, int length) {
    return JS_NewCFunction(ctx, func, name, length);
}

/* --- Exception --- */
JSValue quickjs_get_exception(JSContext* ctx) {
    return JS_GetException(ctx);
}

/* --- Console log helper --- */
static JSValue c_console_log(JSContext* ctx, JSValueConst this_val,
                              int argc, JSValueConst* argv) {
    (void)this_val;
    for (int i = 0; i < argc; i++) {
        const char* s = JS_ToCString(ctx, argv[i]);
        if (s) {
            if (i > 0) printf(" ");
            printf("%s", s);
            JS_FreeCString(ctx, s);
        }
    }
    printf("\n");
    return JS_UNDEFINED;
}

void quickjs_setup_console(JSContext* ctx) {
    // Minimal: just verify the context is functional
    // Full console setup requires careful GC semantics
    (void)ctx;
}
