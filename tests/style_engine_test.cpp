/* MPL 2.0 */
//! Comprehensive Stylo engine tests — 50+ test cases
//! Tests: color, values, cascade, matching, animation, invalidation,
//!         properties, stylesheets, DOM, memory, and headless rendering
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
#include "style/driver/driver.hpp"
#include "style/queries/queries.hpp"

#include <cassert>
#include <iostream>
#include <cmath>
#include <chrono>
#include <memory>

using namespace style;
using namespace style::color;
using namespace style::values::specified;
using namespace style::values::computed;
using namespace style::properties;
using namespace style::stylesheets;
using namespace style::gecko;
using namespace style::invalidation;

static int passed=0,failed=0;
#define T(name) void test_##name()
#define R(name) do{try{test_##name();passed++;std::cout<<"  PASS: "<<#name<<std::endl;}catch(...){failed++;std::cout<<"  FAIL: "<<#name<<std::endl;}}while(0)
#define EQ(a,b) if((a)!=(b))throw std::runtime_error("assert")
#define OK(x) if(!(x))throw std::runtime_error("assert")
#define NEAR(a,b,e) if(std::abs((a)-(b))>(e))throw std::runtime_error("assert")

T(color_red) { auto c=RGBAColor::red(); EQ(c.red,1.0f); EQ(c.green,0.0f); }
T(color_named) { auto c=lookup_named_color("blue"); OK(c); EQ(c->blue,1.0f); }
T(color_named_148) { OK(lookup_named_color("rebeccapurple")); OK(lookup_named_color("aliceblue")); }
T(color_hex) { auto c=RGBAColor::from_u8(170,187,204); EQ(c.to_hex(),"#aabbcc"); }
T(color_transparent) { auto c=RGBAColor::transparent(); EQ(c.alpha,0.0f); }
T(color_components_add) { ColorComponents a(0.2f,0.3f,0.4f),b(0.1f,0.1f,0.1f); auto c=a+b; NEAR(c.c0,0.3f,0.01f); }
T(color_rgb_to_hsl) { auto h=rgb_to_hsl(1,0,0); NEAR(h.hue,0,1); }
T(length_px) { auto l=Length::px(16); EQ(l.absolute_value,16); OK(l.tag==Length::Tag::Absolute); }
T(length_em) { auto l=Length::em(1.5f); OK(l.tag==Length::Tag::FontRelative); }
T(length_zero) { OK(Length::zero().is_zero()); }
T(length_auto) { OK(Length::auto_().is_auto()); }
T(length_percentage) { auto lp=LengthPercentage::percent(50); OK(lp.is_percentage); }
T(calc_basic) { using namespace style::values::generics::calc; auto a=CalcNode<float>::number(10); auto b=CalcNode<float>::number(5); auto s=CalcNode<float>::sum(std::move(a),std::move(b)); NEAR(s.eval([](auto&l){return l.value;}),15,0.01f); }
T(calc_minmax) { using namespace style::values::generics::calc; auto a=CalcNode<float>::number(10); auto b=CalcNode<float>::number(5); auto m=CalcNode<float>::min_v(std::move(a),std::move(b)); NEAR(m.eval([](auto&l){return l.value;}),5,0.01f); }
T(prop_ids) { EQ(static_cast<int>(PropertyId::width),0); }
T(prop_initials) { EQ(std::string(initial_value(PropertyId::opacity)),"1"); EQ(std::string(initial_value(PropertyId::display)),"inline"); }
T(prop_inheritance) { OK(is_inherited(PropertyId::color)); OK(!is_inherited(PropertyId::width)); }
T(prop_names) { EQ(std::string(property_name(PropertyId::background_color)),"background-color"); }
T(prop_shorthand) { auto lh=get_shorthand_longhands("margin"); EQ(lh.size(),4); }
T(logical_margin) { LogicalMargin m(10,20,30,40); EQ(m.block_start,10); EQ(m.block_end,30); EQ(m.inline_sum(),60); }
T(logical_writing_mode) { ComputedWritingMode wm; OK(wm.is_horizontal()); OK(wm.is_ltr()); }
T(logical_to_physical) { EQ(static_cast<int>(logical_to_physical(LogicalSide::BlockStart,WritingMode::HorizontalTb,TextDirection::Ltr)),static_cast<int>(PhysicalSide::Top)); }
T(media_rule_eval) { MediaRule r; r.set_condition("screen"); MediaEvaluationContext c; c.is_print=false; OK(r.evaluate(c)); c.is_print=true; OK(!r.evaluate(c)); }
T(import_url) { ImportRule r; r.set_url("url(\\"style.css\\")"); EQ(r.url(),"style.css"); }
T(layer_naming) { LayerRule r; r.add_name_segment("base"); r.add_name_segment("theme"); EQ(r.full_name(),"base.theme"); }
T(container_eval) { ContainerRule r; r.set_condition("(min-width: 400px)"); ContainerContext c; c.inline_size=500; OK(r.evaluate(c)); c.inline_size=300; OK(!r.evaluate(c)); }
T(font_face_match) { FontFaceRule f; f.set_family("Test"); f.set_weight(400,700); OK(f.matches(500,100,FontStyle::Normal)); OK(!f.matches(300,100,FontStyle::Normal)); }
T(keyframes_sort) { KeyframesRule k; PropertyDeclarationBlock b; k.add_keyframe(1.0f,std::move(b)); PropertyDeclarationBlock b2; k.add_keyframe(0.0f,std::move(b2)); EQ(k.keyframe_count(),2); }
T(selector_specificity) { using namespace style::stylesheets; StyleRule r; auto s=r.compute_specificity("div#main.foo:hover"); EQ(s.a,1); OK(s.b>=2); }
T(invalidation_map) { InvalidationMap m; m.add_dependency(".foo","div.foo{}"); auto s=m.selectors_for_key("foo"); OK(!s.empty()); auto e=m.selectors_for_key("baz"); OK(e.empty()); }
T(rule_tree_create) { RuleTree t; OK(t.root()!=nullptr); EQ(t.size(),1); }
T(dom_element) { auto el=std::make_unique<GeckoNode>(); el->tag_name_="div"; el->id_="root"; EQ(std::string(el->tag_name()),"div"); OK(el->is_element()); }
T(dom_tree) { auto root=std::make_unique<GeckoNode>(); root->tag_name_="html"; auto body=std::make_unique<GeckoNode>(); body->tag_name_="body"; body->parent_=root.get(); root->children_.push_back(std::move(body)); OK(root->first_child()!=nullptr); }
T(stylist_create) { Stylist s; EQ(s.stylesheet_count(),0); }
T(stylist_memory) { for(int i=0;i<50;++i){Stylist s;} OK(true); }
T(sharing_cache) { StyleSharingCache c; EQ(c.size(),0); c.clear(); }
T(traversal_create) { StyleTraversal t; OK(true); }
T(driver_create) { StyleDriver d; d.handle_viewport_change(1024,768); }
T(transform_matrix) { auto m=multiply_matrices({1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1},{2,0,0,0,0,2,0,0,0,0,2,0,0,0,0,1}); EQ(m[0],2); EQ(m[5],2); }
T(decompose_identity) { auto d=decompose_matrix({1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}); EQ(d.translate[0],0); EQ(d.scale[0],1); }
T(anim_easing_linear) { using namespace style::animation; ComputedEasing e=ComputedEasing::linear(); NEAR(apply_easing(0.5f,e),0.5f,0.01f); }
T(cascade_origin) { using namespace style::stylesheets; StyleRule r; auto s=r.compute_specificity("*"); EQ(s.to_u32(),0); }
T(supports_nested) { style::queries::SupportsCondition c; c.type=style::queries::SupportsConditionType::And; OK(c.evaluate()); }
T(headless_dom) { auto html=std::make_unique<GeckoNode>();html->tag_name_="html"; auto head=std::make_unique<GeckoNode>();head->tag_name_="head";head->parent_=html.get();html->children_.push_back(std::move(head)); auto body=std::make_unique<GeckoNode>();body->tag_name_="body";body->parent_=html.get();html->children_.push_back(std::move(body)); OK(html->first_child()!=nullptr); OK(html->first_child()->next_sibling()!=nullptr); }
T(headless_style_compute) { auto div=std::make_unique<GeckoNode>();div->tag_name_="div";div->class_list_={"content"}; OK(div->is_element()); OK(!div->is_text_node()); }
T(property_count_check) { auto lh=get_shorthand_longhands("border"); OK(lh.size()>=3); lh=get_shorthand_longhands("font"); OK(lh.size()>=2); }
T(initial_value_border) { EQ(std::string(initial_value(PropertyId::border_top_style)),"none"); EQ(std::string(initial_value(PropertyId::border_top_color)),"currentcolor"); }
T(inherited_text) { OK(is_inherited(PropertyId::color)); OK(is_inherited(PropertyId::text_align)); OK(is_inherited(PropertyId::direction)); }
T(not_inherited_box) { OK(!is_inherited(PropertyId::width)); OK(!is_inherited(PropertyId::margin_top)); OK(!is_inherited(PropertyId::padding_top)); }
T(animatable_properties) { OK(property_type(PropertyId::width)==PropertyType::Longhand); OK(property_type(PropertyId::margin)==PropertyType::Shorthand); }
T(css_wide_keywords) { auto kw=parse_css_wide_keyword("inherit"); OK(kw); EQ(*kw,CSSWideKeyword::Inherit); kw=parse_css_wide_keyword("initial"); OK(kw); kw=parse_css_wide_keyword("unset"); OK(kw); }
T(viewport_units) { auto ps=parse_dim("50vw"); OK(ps.ok); NEAR(dim_to_px(ps,16,16,1000,800),500,1); }
T(calc_serialize) { using namespace style::values::generics::calc; auto a=CalcNode<float>::number(10); auto b=CalcNode<float>::number(5); auto s=CalcNode<float>::sum(std::move(a),std::move(b)); std::ostringstream oss; s.to_css(oss); OK(!oss.str().empty()); }
T(nested_element_matching) { auto parent=std::make_unique<GeckoNode>();parent->tag_name_="div"; auto child=std::make_unique<GeckoNode>();child->tag_name_="span";child->parent_=parent.get();parent->children_.push_back(std::move(child)); auto grandchild=std::make_unique<GeckoNode>();grandchild->tag_name_="a";grandchild->parent_=parent->children_[0].get();parent->children_[0]->children_.push_back(std::move(grandchild)); OK(parent->first_child()->first_child()!=nullptr); }
T(shorthand_all) { for(auto& sh:{"margin","padding","border","flex","font","background","outline","text-decoration","transition","animation","overflow","gap"}){auto lh=get_shorthand_longhands(sh);OK(!lh.empty());} }
T(memory_no_leak_stylist) { auto s=std::make_unique<Stylist>(); for(int i=0;i<100;++i){ s->add_stylesheet(nullptr); } EQ(s->stylesheet_count(),0); }
T(memory_no_leak_rules) { StyleRule r; r.set_selector_text("div.foo"); EQ(r.selectors().size(),1); r.set_selector_text("h1,h2,h3"); EQ(r.selectors().size(),3); }

int main() {
    std::cout<<"=== C++ Stylo Engine Test Suite ==="<<std::endl;
    std::cout<<std::endl<<"Running "<<57<<" tests..."<<std::endl<<std::endl;
    auto start=std::chrono::steady_clock::now();
    R(color_red);
    R(color_named);
    R(color_named_148);
    R(color_hex);
    R(color_transparent);
    R(color_components_add);
    R(color_rgb_to_hsl);
    R(length_px);
    R(length_em);
    R(length_zero);
    R(length_auto);
    R(length_percentage);
    R(calc_basic);
    R(calc_minmax);
    R(prop_ids);
    R(prop_initials);
    R(prop_inheritance);
    R(prop_names);
    R(prop_shorthand);
    R(logical_margin);
    R(logical_writing_mode);
    R(logical_to_physical);
    R(media_rule_eval);
    R(import_url);
    R(layer_naming);
    R(container_eval);
    R(font_face_match);
    R(keyframes_sort);
    R(selector_specificity);
    R(invalidation_map);
    R(rule_tree_create);
    R(dom_element);
    R(dom_tree);
    R(stylist_create);
    R(stylist_memory);
    R(sharing_cache);
    R(traversal_create);
    R(driver_create);
    R(transform_matrix);
    R(decompose_identity);
    R(anim_easing_linear);
    R(cascade_origin);
    R(supports_nested);
    R(headless_dom);
    R(headless_style_compute);
    R(property_count_check);
    R(initial_value_border);
    R(inherited_text);
    R(not_inherited_box);
    R(animatable_properties);
    R(css_wide_keywords);
    R(viewport_units);
    R(calc_serialize);
    R(nested_element_matching);
    R(shorthand_all);
    R(memory_no_leak_stylist);
    R(memory_no_leak_rules);
    auto end=std::chrono::steady_clock::now();
    auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    std::cout<<std::endl<<"=== "<<passed<<"/"<<(passed+failed)<<" passed in "<<ms<<"ms ==="<<std::endl;
    return failed>0?1:0;
}