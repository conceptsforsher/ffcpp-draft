#include "headless/headless.hpp"
#include "js/js_engine_quickjs.hpp"
#include <iostream>
#include <cassert>
#include <cstring>

using namespace headless;
using namespace js;

// --- Test runner ---
static int passed = 0, failed = 0;

#define TEST(name) do { std::cout << "  TEST: " << name << " ... "; } while(0)
#define OK() do { std::cout << "OK" << std::endl; passed++; } while(0)
#define FAIL(msg) do { std::cout << "FAIL: " << msg << std::endl; failed++; } while(0)
#define ASSERT(cond, msg) do { if (!(cond)) { FAIL(msg); return; } } while(0)

void test_engine_version(JSEngine& e) {
    TEST("engineVersion()");
    auto v = e.engineVersion();
    ASSERT(v.find("QuickJS") != std::string::npos, v);
    ASSERT(e.supportsModernJS(), "supportsModernJS");
    std::cout << "  (" << v << ")" << std::endl;
    OK();
}

void test_basic_types(JSEngine& e) {
    TEST("number literal");
    auto r = e.evaluate("42");
    ASSERT(r.isNumber(), "not number");
    ASSERT(r.number_val == 42.0, std::to_string(r.number_val));
    OK();

    TEST("string literal");
    r = e.evaluate("\"hello world\"");
    ASSERT(r.isString(), "not string");
    ASSERT(r.string_val == "hello world", r.string_val);
    OK();

    TEST("boolean literal");
    r = e.evaluate("true");
    ASSERT(r.type == JSType::Boolean, "not bool");
    ASSERT(r.bool_val == true, "not true");
    OK();

    TEST("null literal");
    r = e.evaluate("null");
    ASSERT(r.isNull(), "not null");
    OK();

    TEST("undefined");
    r = e.evaluate("undefined");
    ASSERT(r.isUndefined(), "not undefined");
    OK();
}

void test_arithmetic(JSEngine& e) {
    TEST("2+3");        ASSERT(e.evaluate("2 + 3").number_val == 5.0, "!=5"); OK();
    TEST("7*8");        ASSERT(e.evaluate("7 * 8").number_val == 56.0, "!=56"); OK();
    TEST("100/4");      ASSERT(e.evaluate("100 / 4").number_val == 25.0, "!=25"); OK();
    TEST("17%5");       ASSERT(e.evaluate("17 % 5").number_val == 2.0, "!=2"); OK();
    TEST("2+3*4");      ASSERT(e.evaluate("2 + 3 * 4").number_val == 14.0, "!=14"); OK();
    TEST("negatives");  ASSERT(e.evaluate("-42 + 100").number_val == 58.0, "!=58"); OK();
}

void test_variables(JSEngine& e) {
    TEST("var");
    e.evaluate("var x = 10;");
    ASSERT(e.getGlobal("x").number_val == 10.0, std::to_string(e.getGlobal("x").number_val));
    OK();

    TEST("let (ES6)");
    e.evaluate("let y = 20;");
    ASSERT(e.getGlobal("y").isUndefined(), "let should not pollute global");
    OK();

    TEST("const (ES6)");
    e.evaluate("const z = 30;");
    ASSERT(e.getGlobal("z").isUndefined(), "const should not pollute global");
    OK();
}

void test_strings(JSEngine& e) {
    TEST("concatenation");
    auto r = e.evaluate("\"hello\" + \" \" + \"world\"");
    ASSERT(r.string_val == "hello world", r.string_val);
    OK();

    TEST("template literals (ES6)");
    r = e.evaluate("var n=42; `The answer is ${n}`");
    ASSERT(r.string_val == "The answer is 42", r.string_val);
    OK();

    TEST("string.length");
    ASSERT(e.evaluate("\"hello\".length").number_val == 5.0, "!=5");
    OK();
}

void test_conditionals(JSEngine& e) {
    TEST("if/else");
    auto r = e.evaluate("var a = 10; if (a > 5) { 1; } else { 0; }");
    ASSERT(r.number_val == 1.0, std::to_string(r.number_val));
    OK();

    TEST("ternary");
    r = e.evaluate("var a = 3; a > 5 ? 100 : 200");
    ASSERT(r.number_val == 200.0, std::to_string(r.number_val));
    OK();

    TEST("logical && || !");
    ASSERT(e.evaluate("true && false").bool_val == false, "&&");
    ASSERT(e.evaluate("true || false").bool_val == true, "||");
    ASSERT(e.evaluate("!true").bool_val == false, "!");
    OK();
}

void test_functions(JSEngine& e) {
    TEST("function declaration");
    e.evaluate("function add(a, b) { return a + b; }");
    std::vector<js::JSValue> args1 = {js::JSValue::number(3), js::JSValue::number(7)};
    auto r = e.callFunction("add", args1);
    ASSERT(r.number_val == 10.0, r.toString());
    OK();

    TEST("arrow functions (ES6)");
    e.evaluate("var multiply = (a, b) => a * b;");
    std::vector<js::JSValue> args2 = {js::JSValue::number(6), js::JSValue::number(7)};
    r = e.callFunction("multiply", args2);
    ASSERT(r.number_val == 42.0, r.toString());
    OK();

    TEST("closure (ES6)");
    e.evaluate("function makeCounter() { let count = 0; return function() { count++; return count; }; }");
    e.evaluate("var counter = makeCounter();");
    ASSERT(e.evaluate("counter()").number_val == 1, "()!=1");
    ASSERT(e.evaluate("counter()").number_val == 2, "()!=2");
    ASSERT(e.evaluate("counter()").number_val == 3, "()!=3");
    OK();
}

void test_arrays(JSEngine& e) {
    TEST("array literal");
    auto r = e.evaluate("[1, 2, 3, 4, 5]");
    ASSERT(r.type == JSType::Array, "not array");
    OK();

    TEST("array length");
    ASSERT(e.evaluate("[1,2,3].length").number_val == 3.0, "!=3");
    OK();

    TEST("Array.map (ES5)");
    r = e.evaluate("[1, 2, 3].map(function(x) { return x * 2; })");
    ASSERT(r.type == JSType::Array, "not array");
    OK();

    TEST("Array.filter (ES5)");
    r = e.evaluate("[1, 2, 3, 4, 5, 6].filter(function(x) { return x % 2 === 0; })");
    ASSERT(r.type == JSType::Array, "not array");
    OK();

    TEST("Array.reduce (ES5)");
    r = e.evaluate("[1, 2, 3, 4].reduce(function(acc, x) { return acc + x; }, 0)");
    ASSERT(r.number_val == 10.0, r.toString());
    OK();

    TEST("Spread operator (ES6)");
    r = e.evaluate("Math.max(...[1, 5, 3, 9, 2])");
    ASSERT(r.number_val == 9.0, r.toString());
    OK();
}

void test_objects(JSEngine& e) {
    TEST("object literal");
    auto r = e.evaluate("({name: 'test', value: 42})");
    ASSERT(r.type == JSType::Object, "not object");
    OK();

    TEST("property access");
    e.evaluate("var obj = {x: 10, y: 20};");
    r = e.evaluate("obj.x + obj.y");
    ASSERT(r.number_val == 30.0, r.toString());
    OK();

    TEST("destructuring (ES6)");
    e.evaluate("var {a, b} = {a: 1, b: 2, c: 3};");
    ASSERT(e.evaluate("a + b").number_val == 3.0, "!=");
    OK();
}

void test_loops(JSEngine& e) {
    TEST("for loop");
    e.evaluate("var sum = 0; for (var i = 0; i <= 10; i++) { sum += i; }");
    ASSERT(e.evaluate("sum").number_val == 55.0, "!=55");
    OK();

    TEST("while loop");
    e.evaluate("var x = 1; var n = 1; while (n <= 5) { x *= n; n++; }");
    ASSERT(e.evaluate("x").number_val == 120.0, "!=120");
    OK();
}

void test_classes(JSEngine& e) {
    TEST("class (ES6)");
    e.evaluate(R"JS(
class Rectangle {
    constructor(w, h) {
        this.width = w;
        this.height = h;
    }
    area() {
        return this.width * this.height;
    }
}
var rect = new Rectangle(10, 5);
)JS");
    auto r = e.evaluate("rect.area()");
    ASSERT(r.number_val == 50.0, r.toString());
    OK();
}

void test_console(JSEngine& e) {
    TEST("typeof console");
    // console not set up yet — verify typeof returns 'undefined'
    auto r = e.evaluate("typeof console");
    ASSERT(r.string_val == "undefined", r.string_val);
    OK();
}

void test_complex_expression(JSEngine& e) {
    TEST("complex (IIFE + fib)");
    auto r = e.evaluate(R"JS(
(function() {
    var fib = [0, 1];
    for (var i = 2; i < 15; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[14];
})()
)JS");
    ASSERT(r.number_val == 377.0, r.toString());
    OK();
}

void test_headless_browser_with_modern_js() {
    TEST("Headless browser + JS");
    HeadlessBrowser browser(1920, 1080);
    const char* html = "<html><body><div id=\"app\"><h1>QuickJS Test</h1><p>Count: 0</p></div><script>var testJS = 42; var msg = \"Hello from QuickJS!\"; var arr = [1,2,3].map(function(x){return x*2;}); console.log(msg);</script></body></html>";
    browser.load_page(html);
    auto out = browser.render();
    auto s = browser.stats();

    std::cout << "  Page loaded: " << s.elements_styled << " elements" << std::endl;
    std::cout << "  Render: " << s.pixels_rendered << " pixels" << std::endl;
    std::cout << "  Style: " << s.style_ms << "ms / Render: " << s.render_ms << "ms" << std::endl;
    std::cout << "  Scripts: " << (s.scripts_executed ? "YES" : "NO") << std::endl;

    ASSERT(s.elements_styled >= 3, "Expected 3+ elements");
    ASSERT(s.pixels_rendered == 1920 * 1080, "Expected full render");
    ASSERT(s.scripts_executed == 1, "Expected 1 script");
    ASSERT(browser.verify_no_leaks(), "Memory leak!");
    OK();
}

int main() {
    std::cout << "Firefox C++ — Modern JS Test Suite (QuickJS ES2020+)" << std::endl;
    std::cout << "=====================================================" << std::endl;

    auto engine = createJSEngine();
    if (!engine->init()) {
        std::cerr << "FAIL: Engine init failed" << std::endl;
        return 1;
    }

    std::cout << "\nEngine: " << engine->engineVersion() << std::endl;
    std::cout << "Modern JS: " << (engine->supportsModernJS() ? "YES" : "NO") << std::endl;

    std::cout << "\n--- Basic Types ---" << std::endl;
    test_engine_version(*engine);
    test_basic_types(*engine);

    std::cout << "\n--- Arithmetic ---" << std::endl;
    test_arithmetic(*engine);

    std::cout << "\n--- Variables ---" << std::endl;
    test_variables(*engine);

    std::cout << "\n--- Strings ---" << std::endl;
    test_strings(*engine);

    std::cout << "\n--- Conditionals ---" << std::endl;
    test_conditionals(*engine);

    std::cout << "\n--- Functions ---" << std::endl;
    test_functions(*engine);

    std::cout << "\n--- Arrays ---" << std::endl;
    test_arrays(*engine);

    std::cout << "\n--- Objects ---" << std::endl;
    test_objects(*engine);

    std::cout << "\n--- Loops ---" << std::endl;
    test_loops(*engine);

    std::cout << "\n--- Classes ---" << std::endl;
    test_classes(*engine);

    std::cout << "\n--- Console ---" << std::endl;
    test_console(*engine);

    std::cout << "\n--- Complex ---" << std::endl;
    test_complex_expression(*engine);

    test_headless_browser_with_modern_js();

    std::cout << "\n=====================================================" << std::endl;
    std::cout << "Results: " << passed << " passed, " << failed << " failed" << std::endl;
    std::cout << "=====================================================" << std::endl;

    return failed > 0 ? 1 : 0;
}
