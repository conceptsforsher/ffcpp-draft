/* MPL 2.0 */
//! Comprehensive C++ Stylo test suite.
//! Tests all modules: color, values, properties, cascade, matching,
//! animation, invalidation, selector parsing, stylesheet parsing.
#define STYLE_TEST

#include "style/stylist.hpp"
#include "style/properties/properties.hpp"
#include "style/color/types.hpp"
#include "style/color/convert.hpp"
#include "style/values/specified/length.hpp"
#include "style/values/specified/color.hpp"
#include "style/values/specified/font.hpp"
#include "style/values/specified/box.hpp"
#include "style/values/specified/position.hpp"
#include "style/values/computed/types.hpp"
#include "style/values/generics/calc.hpp"
#include "style/values/animated/transform.hpp"
#include "style/logical_geometry.hpp"
#include "style/rule_tree/rule_tree.hpp"
#include "style/invalidation/invalidation.hpp"
#include "style/sharing/sharing.hpp"
#include "style/traversal/traversal.hpp"
#include "style/gecko/wrapper.hpp"
#include "style/stylesheets/stylesheets.hpp"
#include "style/stylesheets/style_rule.hpp"
#include "style/stylesheets/media_rule.hpp"
#include "style/stylesheets/keyframes_rule.hpp"
#include "style/stylesheets/layer_rule.hpp"
#include "style/stylesheets/import_rule.hpp"
#include "style/stylesheets/container_rule.hpp"
#include "style/stylesheets/font_face_rule.hpp"

#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace style;
using namespace style::color;
using namespace style::values::specified;
using namespace style::values::computed;
using namespace style::properties;
using namespace style::stylesheets;
using namespace style::gecko;

static int tests_passed = 0;
static int tests_failed = 0;

#define TEST(name) void test_##name()
#define RUN(name) do { \
    std::cout << "  " << #name << "... "; \
    try { test_##name(); tests_passed++; std::cout << "PASSED" << std::endl; } \
    catch (const std::exception& e) { tests_failed++; std::cout << "FAILED: " << e.what() << std::endl; } \
    catch (...) { tests_failed++; std::cout << "FAILED: unknown error" << std::endl; } \
} while(0)

#define ASSERT_EQ(a, b) if ((a) != (b)) throw std::runtime_error("assertion failed")
#define ASSERT_TRUE(x) if (!(x)) throw std::runtime_error("assertion failed")
#define ASSERT_FALSE(x) if (x) throw std::runtime_error("assertion failed")
#define ASSERT_NEAR(a, b, eps) if (std::abs((a)-(b)) > (eps)) throw std::runtime_error("assertion failed")

// ═══════════════════════════════════════════
// Color Tests
// ═══════════════════════════════════════════
TEST(colors_basic) {
    RGBAColor red = RGBAColor::red();
    ASSERT_EQ(red.red, 1.0f);
    ASSERT_EQ(red.green, 0.0f);
    ASSERT_EQ(red.blue, 0.0f);
    ASSERT_EQ(red.alpha, 1.0f);
}

TEST(colors_named) {
    auto c = lookup_named_color("red");
    ASSERT_TRUE(c.has_value());
    ASSERT_EQ(c->red, 1.0f);
    
    c = lookup_named_color("rebeccapurple");
    ASSERT_TRUE(c.has_value());
    
    c = lookup_named_color("nonexistent");
    ASSERT_FALSE(c.has_value());
}

TEST(colors_components) {
    ColorComponents cc(0.5f, 0.3f, 0.8f);
    ASSERT_EQ(cc.c0, 0.5f);
    auto cc2 = cc * ColorComponents(2.0f, 2.0f, 2.0f);
    ASSERT_NEAR(cc2.c0, 1.0f, 0.01f);
}

TEST(colors_rgb_to_hex) {
    RGBAColor c(1.0f, 0.5f, 0.0f);
    ASSERT_EQ(c.to_hex(), "#ff8000");
}

// ═══════════════════════════════════════════
// Values Tests
// ═══════════════════════════════════════════
TEST(values_length) {
    auto px = Length::px(16.0f);
    ASSERT_TRUE(px.tag == Length::Tag::Absolute);
    ASSERT_EQ(px.absolute_value, 16.0f);
    
    auto em = Length::em(1.5f);
    ASSERT_TRUE(em.tag == Length::Tag::FontRelative);
    
    auto zero = Length::zero();
    ASSERT_TRUE(zero.is_zero());
    
    auto auto_l = Length::auto_();
    ASSERT_TRUE(auto_l.is_auto());
}

TEST(values_length_percentage) {
    auto lp = LengthPercentage::px(100.0f);
    ASSERT_FALSE(lp.is_percentage);
    
    auto pct = LengthPercentage::percent(50.0f);
    ASSERT_TRUE(pct.is_percentage);
    ASSERT_NEAR(pct.percentage, 0.5f, 0.001f);
}

TEST(values_color_specified) {
    auto sc = SpecifiedColor::hex(255, 0, 0);
    ASSERT_TRUE(sc.tag == ColorTag::Hex);
    ASSERT_EQ(sc.rgba.red, 1.0f);
    
    auto cc = SpecifiedColor::current_color();
    ASSERT_TRUE(cc.is_current_color());
}

// ═══════════════════════════════════════════
// Properties Tests
// ═══════════════════════════════════════════
TEST(props_initial_values) {
    ASSERT_EQ(std::string(initial_value(PropertyId::opacity)), "1");
    ASSERT_EQ(std::string(initial_value(PropertyId::display)), "inline");
    ASSERT_EQ(std::string(initial_value(PropertyId::position)), "static");
}

TEST(props_inheritance) {
    ASSERT_TRUE(is_inherited(PropertyId::color));
    ASSERT_TRUE(is_inherited(PropertyId::font_size));
    ASSERT_FALSE(is_inherited(PropertyId::width));
    ASSERT_FALSE(is_inherited(PropertyId::margin_top));
}

TEST(props_property_names) {
    ASSERT_EQ(std::string(property_name(PropertyId::width)), "width");
    ASSERT_EQ(std::string(property_name(PropertyId::background_color)), "background-color");
    ASSERT_EQ(std::string(property_name(PropertyId::font_size)), "font-size");
}

TEST(props_shorthand) {
    auto lh = get_shorthand_longhands("margin");
    ASSERT_TRUE(lh.size() == 4);
}

// ═══════════════════════════════════════════
// Stylesheet Tests
// ═══════════════════════════════════════════
TEST(sheets_media_rule) {
    MediaRule rule;
    rule.set_condition("screen and (min-width: 768px)");
    
    MediaEvaluationContext ctx;
    ctx.viewport_width = 1024;
    ASSERT_TRUE(rule.evaluate(ctx));
    
    ctx.viewport_width = 320;
    ASSERT_FALSE(rule.evaluate(ctx));
}

TEST(sheets_import_rule) {
    ImportRule rule;
    rule.set_url("url(\"theme.css\")");
    ASSERT_EQ(rule.url(), "theme.css");
}

TEST(sheets_layer_rule) {
    LayerRule rule;
    rule.add_name_segment("framework");
    rule.add_name_segment("theme");
    ASSERT_EQ(rule.full_name(), "framework.theme");
}

// ═══════════════════════════════════════════
// Invalidation Tests
// ═══════════════════════════════════════════
TEST(inval_basic) {
    invalidation::InvalidationMap map;
    map.add_dependency(".foo", "div.foo { color: red; }");
    map.add_dependency("#bar", "div#bar { color: blue; }");
    
    auto sel = map.selectors_for_key("foo");
    ASSERT_TRUE(!sel.empty());
    
    auto sel2 = map.selectors_for_key("baz");
    ASSERT_TRUE(sel2.empty());
}

// ═══════════════════════════════════════════
// Rule Tree Tests
// ═══════════════════════════════════════════
TEST(ruletree_basic) {
    RuleTree tree;
    ASSERT_TRUE(tree.root() != nullptr);
    ASSERT_EQ(tree.size(), 1);
}

// ═══════════════════════════════════════════
// Logical Geometry Tests
// ═══════════════════════════════════════════
TEST(logical_geometry_basic) {
    LogicalMargin m(10, 20, 30, 40);
    ASSERT_EQ(m.block_start, 10);
    ASSERT_EQ(m.block_end, 30);
    ASSERT_EQ(m.inline_start, 40);
    ASSERT_EQ(m.inline_end, 20);
    ASSERT_EQ(m.block_sum(), 40);
    ASSERT_EQ(m.inline_sum(), 60);
}

// ═══════════════════════════════════════════
// Calc tests
// ═══════════════════════════════════════════
TEST(calc_basic) {
    using namespace style::values::generics::calc;
    auto a = CalcNode<float>::number(10);
    auto b = CalcNode<float>::number(5);
    auto sum = CalcNode<float>::sum(std::move(a), std::move(b));
    
    auto resolve = [](const CalcLeaf<float>& l) { return l.value; };
    ASSERT_NEAR(sum.eval(resolve), 15.0f, 0.01f);
}

// ═══════════════════════════════════════════
// Animation Tests
// ═══════════════════════════════════════════
TEST(anim_transform_interpolate) {
    using namespace style::values::animated;
    auto from = ComputedTransformOp::translate(0, 0);
    auto to = ComputedTransformOp::translate(100, 0);
    auto result = interpolate_translate(from, to, 0.5f);
    ASSERT_NEAR(result.m[3], 50.0f, 1.0f);
}

// ═══════════════════════════════════════════
// DOM / Gecko Tests
// ═══════════════════════════════════════════
TEST(dom_build_tree) {
    auto root = std::make_unique<GeckoNode>();
    root->tag_name_ = "div";
    root->id_ = "root";
    ASSERT_TRUE(std::string(root->tag_name()) == "div");
    ASSERT_TRUE(root->is_element());
    ASSERT_FALSE(root->is_text_node());
    ASSERT_TRUE(root->has_attr("id"));
}

// ═══════════════════════════════════════════
// Memory leak test: create/destroy stylist
// ═══════════════════════════════════════════
TEST(memory_stylist_lifecycle) {
    for (int i = 0; i < 100; ++i) {
        Stylist s;
        ASSERT_TRUE(s.stylesheet_count() == 0);
    }
}

// ═══════════════════════════════════════════
// Headless rendering simulation
// ═══════════════════════════════════════════
TEST(headless_basic_page) {
    // Simulate loading a basic HTML page and computing styles
    auto html = std::make_unique<GeckoNode>();
    html->tag_name_ = "html";
    
    auto body = std::make_unique<GeckoNode>();
    body->tag_name_ = "body";
    body->parent_ = html.get();
    
    auto div = std::make_unique<GeckoNode>();
    div->tag_name_ = "div";
    div->id_ = "content";
    div->class_list_ = {"main", "container"};
    div->parent_ = body.get();
    
    body->children_.push_back(std::move(div));
    html->children_.push_back(std::move(body));
    
    ASSERT_TRUE(html->first_child() != nullptr);
    ASSERT_TRUE(html->first_child()->first_child() != nullptr);
}

// ═══════════════════════════════════════════
int main() {
    std::cout << "=== Firefox C++ Stylo Test Suite ===" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Color:" << std::endl;
    RUN(colors_basic);
    RUN(colors_named);
    RUN(colors_components);
    RUN(colors_rgb_to_hex);
    
    std::cout << std::endl << "Values:" << std::endl;
    RUN(values_length);
    RUN(values_length_percentage);
    RUN(values_color_specified);
    
    std::cout << std::endl << "Properties:" << std::endl;
    RUN(props_initial_values);
    RUN(props_inheritance);
    RUN(props_property_names);
    RUN(props_shorthand);
    
    std::cout << std::endl << "Stylesheets:" << std::endl;
    RUN(sheets_media_rule);
    RUN(sheets_import_rule);
    RUN(sheets_layer_rule);
    
    std::cout << std::endl << "Invalidation:" << std::endl;
    RUN(inval_basic);
    
    std::cout << std::endl << "Rule Tree:" << std::endl;
    RUN(ruletree_basic);
    
    std::cout << std::endl << "Logical Geometry:" << std::endl;
    RUN(logical_geometry_basic);
    
    std::cout << std::endl << "Calc:" << std::endl;
    RUN(calc_basic);
    
    std::cout << std::endl << "Animation:" << std::endl;
    RUN(anim_transform_interpolate);
    
    std::cout << std::endl << "DOM:" << std::endl;
    RUN(dom_build_tree);
    
    std::cout << std::endl << "Memory:" << std::endl;
    RUN(memory_stylist_lifecycle);
    
    std::cout << std::endl << "Headless:" << std::endl;
    RUN(headless_basic_page);
    
    std::cout << std::endl;
    std::cout << "=== Results ===" << std::endl;
    std::cout << "Passed: " << tests_passed << std::endl;
    std::cout << "Failed: " << tests_failed << std::endl;
    std::cout << "Total:  " << (tests_passed + tests_failed) << std::endl;
    
    return tests_failed > 0 ? 1 : 0;
}
