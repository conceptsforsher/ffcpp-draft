/* MPL 2.0 */
//! CSS Property Serialization — computed value to CSS string for all properties
#include "style/properties/properties.hpp"
#include "style/color/types.hpp"
#include <sstream>
#include <unordered_map>
#include <cassert>

namespace style { namespace properties {

// Serialize a computed property value to CSS
std::string serialize_width(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_min_width(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_max_width(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_height(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_min_height(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_max_height(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_margin_top(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_margin_right(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_margin_bottom(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_margin_left(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_padding_top(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_padding_right(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_padding_bottom(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_padding_left(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_border_top_width(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_border_right_width(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_border_bottom_width(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_border_left_width(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_border_top_style(const std::string& val) {
    return val;
}

std::string serialize_border_right_style(const std::string& val) {
    return val;
}

std::string serialize_border_bottom_style(const std::string& val) {
    return val;
}

std::string serialize_border_left_style(const std::string& val) {
    return val;
}

std::string serialize_border_top_color(const std::string& val) {
    return val;
}

std::string serialize_border_right_color(const std::string& val) {
    return val;
}

std::string serialize_border_bottom_color(const std::string& val) {
    return val;
}

std::string serialize_border_left_color(const std::string& val) {
    return val;
}

std::string serialize_border_top_left_radius(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_border_top_right_radius(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_border_bottom_right_radius(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_border_bottom_left_radius(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_display(const std::string& val) {
    return val;
}

std::string serialize_position(const std::string& val) {
    return val;
}

std::string serialize_top(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_right(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_bottom(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_left(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_z_index(const std::string& val) {
    return val;
}

std::string serialize_float(const std::string& val) {
    return val;
}

std::string serialize_clear(const std::string& val) {
    return val;
}

std::string serialize_overflow_x(const std::string& val) {
    return val;
}

std::string serialize_overflow_y(const std::string& val) {
    return val;
}

std::string serialize_visibility(const std::string& val) {
    return val;
}

std::string serialize_opacity(const std::string& val) {
    return val;
}

std::string serialize_color(const std::string& val) {
    return val;
}

std::string serialize_background_color(const std::string& val) {
    return val;
}

std::string serialize_background_image(const std::string& val) {
    return val;
}

std::string serialize_background_size(const std::string& val) {
    return val;
}

std::string serialize_background_repeat(const std::string& val) {
    return val;
}

std::string serialize_background_position_x(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"%";
}

std::string serialize_background_position_y(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"%";
}

std::string serialize_background_attachment(const std::string& val) {
    return val;
}

std::string serialize_background_clip(const std::string& val) {
    return val;
}

std::string serialize_background_origin(const std::string& val) {
    return val;
}

std::string serialize_font_family(const std::string& val) {
    return val;
}

std::string serialize_font_size(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_font_weight(const std::string& val) {
    return val;
}

std::string serialize_font_style(const std::string& val) {
    return val;
}

std::string serialize_font_stretch(const std::string& val) {
    return val;
}

std::string serialize_line_height(const std::string& val) {
    return val;
}

std::string serialize_text_align(const std::string& val) {
    return val;
}

std::string serialize_text_decoration_line(const std::string& val) {
    return val;
}

std::string serialize_text_decoration_style(const std::string& val) {
    return val;
}

std::string serialize_text_decoration_color(const std::string& val) {
    return val;
}

std::string serialize_text_transform(const std::string& val) {
    return val;
}

std::string serialize_text_indent(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_text_overflow(const std::string& val) {
    return val;
}

std::string serialize_white_space(const std::string& val) {
    return val;
}

std::string serialize_word_break(const std::string& val) {
    return val;
}

std::string serialize_overflow_wrap(const std::string& val) {
    return val;
}

std::string serialize_hyphens(const std::string& val) {
    return val;
}

std::string serialize_letter_spacing(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_word_spacing(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_tab_size(const std::string& val) {
    return val;
}

std::string serialize_direction(const std::string& val) {
    return val;
}

std::string serialize_writing_mode(const std::string& val) {
    return val;
}

std::string serialize_text_orientation(const std::string& val) {
    return val;
}

std::string serialize_unicode_bidi(const std::string& val) {
    return val;
}

std::string serialize_flex_direction(const std::string& val) {
    return val;
}

std::string serialize_flex_wrap(const std::string& val) {
    return val;
}

std::string serialize_flex_grow(const std::string& val) {
    return val;
}

std::string serialize_flex_shrink(const std::string& val) {
    return val;
}

std::string serialize_flex_basis(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_order(const std::string& val) {
    return val;
}

std::string serialize_justify_content(const std::string& val) {
    return val;
}

std::string serialize_align_items(const std::string& val) {
    return val;
}

std::string serialize_align_self(const std::string& val) {
    return val;
}

std::string serialize_align_content(const std::string& val) {
    return val;
}

std::string serialize_row_gap(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_column_gap(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_transform(const std::string& val) {
    return val;
}

std::string serialize_transform_origin(const std::string& val) {
    return val;
}

std::string serialize_transform_style(const std::string& val) {
    return val;
}

std::string serialize_perspective(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_perspective_origin(const std::string& val) {
    return val;
}

std::string serialize_backface_visibility(const std::string& val) {
    return val;
}

std::string serialize_transition_property(const std::string& val) {
    return val;
}

std::string serialize_transition_duration(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"s";
}

std::string serialize_transition_timing_function(const std::string& val) {
    return val;
}

std::string serialize_transition_delay(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"s";
}

std::string serialize_animation_name(const std::string& val) {
    return val;
}

std::string serialize_animation_duration(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"s";
}

std::string serialize_animation_timing_function(const std::string& val) {
    return val;
}

std::string serialize_animation_delay(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"s";
}

std::string serialize_animation_iteration_count(const std::string& val) {
    return val;
}

std::string serialize_animation_direction(const std::string& val) {
    return val;
}

std::string serialize_animation_fill_mode(const std::string& val) {
    return val;
}

std::string serialize_animation_play_state(const std::string& val) {
    return val;
}

std::string serialize_box_shadow(const std::string& val) {
    return val;
}

std::string serialize_filter(const std::string& val) {
    return val;
}

std::string serialize_backdrop_filter(const std::string& val) {
    return val;
}

std::string serialize_cursor(const std::string& val) {
    return val;
}

std::string serialize_outline_style(const std::string& val) {
    return val;
}

std::string serialize_outline_width(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_outline_color(const std::string& val) {
    return val;
}

std::string serialize_outline_offset(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_resize(const std::string& val) {
    return val;
}

std::string serialize_user_select(const std::string& val) {
    return val;
}

std::string serialize_pointer_events(const std::string& val) {
    return val;
}

std::string serialize_touch_action(const std::string& val) {
    return val;
}

std::string serialize_border_collapse(const std::string& val) {
    return val;
}

std::string serialize_border_spacing(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_caption_side(const std::string& val) {
    return val;
}

std::string serialize_empty_cells(const std::string& val) {
    return val;
}

std::string serialize_table_layout(const std::string& val) {
    return val;
}

std::string serialize_vertical_align(const std::string& val) {
    return val;
}

std::string serialize_list_style_type(const std::string& val) {
    return val;
}

std::string serialize_list_style_position(const std::string& val) {
    return val;
}

std::string serialize_list_style_image(const std::string& val) {
    return val;
}

std::string serialize_content(const std::string& val) {
    return val;
}

std::string serialize_quotes(const std::string& val) {
    return val;
}

std::string serialize_counter_increment(const std::string& val) {
    return val;
}

std::string serialize_counter_reset(const std::string& val) {
    return val;
}

std::string serialize_box_sizing(const std::string& val) {
    return val;
}

std::string serialize_aspect_ratio(const std::string& val) {
    return val;
}

std::string serialize_object_fit(const std::string& val) {
    return val;
}

std::string serialize_object_position(const std::string& val) {
    return val;
}

std::string serialize_contain(const std::string& val) {
    return val;
}

std::string serialize_container_type(const std::string& val) {
    return val;
}

std::string serialize_container_name(const std::string& val) {
    return val;
}

std::string serialize_scroll_behavior(const std::string& val) {
    return val;
}

std::string serialize_scrollbar_width(const std::string& val) {
    return val;
}

std::string serialize_scrollbar_color(const std::string& val) {
    return val;
}

std::string serialize_scroll_snap_type(const std::string& val) {
    return val;
}

std::string serialize_scroll_snap_align(const std::string& val) {
    return val;
}

std::string serialize_accent_color(const std::string& val) {
    return val;
}

std::string serialize_caret_color(const std::string& val) {
    return val;
}

std::string serialize_appearance(const std::string& val) {
    return val;
}

std::string serialize_mix_blend_mode(const std::string& val) {
    return val;
}

std::string serialize_isolation(const std::string& val) {
    return val;
}

std::string serialize_gap(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_columns(const std::string& val) {
    return val;
}

std::string serialize_column_rule(const std::string& val) {
    return val;
}

std::string serialize_inset(const std::string& val) {
    if(val=="auto"||val=="none"||val=="normal"||val=="inherit"||val=="initial")return val;
    return val+"px";
}

std::string serialize_place_items(const std::string& val) {
    return val;
}

std::string serialize_place_content(const std::string& val) {
    return val;
}

std::string serialize_place_self(const std::string& val) {
    return val;
}

// Dispatch serialization by property name
using SerializeFn = std::string(*)(const std::string&);
SerializeFn get_serializer(const std::string& name) {
    static const std::unordered_map<std::string,SerializeFn> map = {
        {"width",serialize_width},
        {"min_width",serialize_min_width},
        {"max_width",serialize_max_width},
        {"height",serialize_height},
        {"min_height",serialize_min_height},
        {"max_height",serialize_max_height},
        {"margin_top",serialize_margin_top},
        {"margin_right",serialize_margin_right},
        {"margin_bottom",serialize_margin_bottom},
        {"margin_left",serialize_margin_left},
        {"padding_top",serialize_padding_top},
        {"padding_right",serialize_padding_right},
        {"padding_bottom",serialize_padding_bottom},
        {"padding_left",serialize_padding_left},
        {"border_top_width",serialize_border_top_width},
        {"border_right_width",serialize_border_right_width},
        {"border_bottom_width",serialize_border_bottom_width},
        {"border_left_width",serialize_border_left_width},
        {"border_top_style",serialize_border_top_style},
        {"border_right_style",serialize_border_right_style},
        {"border_bottom_style",serialize_border_bottom_style},
        {"border_left_style",serialize_border_left_style},
        {"border_top_color",serialize_border_top_color},
        {"border_right_color",serialize_border_right_color},
        {"border_bottom_color",serialize_border_bottom_color},
        {"border_left_color",serialize_border_left_color},
        {"border_top_left_radius",serialize_border_top_left_radius},
        {"border_top_right_radius",serialize_border_top_right_radius},
        {"border_bottom_right_radius",serialize_border_bottom_right_radius},
        {"border_bottom_left_radius",serialize_border_bottom_left_radius},
        {"display",serialize_display},
        {"position",serialize_position},
        {"top",serialize_top},
        {"right",serialize_right},
        {"bottom",serialize_bottom},
        {"left",serialize_left},
        {"z_index",serialize_z_index},
        {"float",serialize_float},
        {"clear",serialize_clear},
        {"overflow_x",serialize_overflow_x},
        {"overflow_y",serialize_overflow_y},
        {"visibility",serialize_visibility},
        {"opacity",serialize_opacity},
        {"color",serialize_color},
        {"background_color",serialize_background_color},
        {"background_image",serialize_background_image},
        {"background_size",serialize_background_size},
        {"background_repeat",serialize_background_repeat},
        {"background_position_x",serialize_background_position_x},
        {"background_position_y",serialize_background_position_y},
        {"background_attachment",serialize_background_attachment},
        {"background_clip",serialize_background_clip},
        {"background_origin",serialize_background_origin},
        {"font_family",serialize_font_family},
        {"font_size",serialize_font_size},
        {"font_weight",serialize_font_weight},
        {"font_style",serialize_font_style},
        {"font_stretch",serialize_font_stretch},
        {"line_height",serialize_line_height},
        {"text_align",serialize_text_align},
        {"text_decoration_line",serialize_text_decoration_line},
        {"text_decoration_style",serialize_text_decoration_style},
        {"text_decoration_color",serialize_text_decoration_color},
        {"text_transform",serialize_text_transform},
        {"text_indent",serialize_text_indent},
        {"text_overflow",serialize_text_overflow},
        {"white_space",serialize_white_space},
        {"word_break",serialize_word_break},
        {"overflow_wrap",serialize_overflow_wrap},
        {"hyphens",serialize_hyphens},
        {"letter_spacing",serialize_letter_spacing},
        {"word_spacing",serialize_word_spacing},
        {"tab_size",serialize_tab_size},
        {"direction",serialize_direction},
        {"writing_mode",serialize_writing_mode},
        {"text_orientation",serialize_text_orientation},
        {"unicode_bidi",serialize_unicode_bidi},
        {"flex_direction",serialize_flex_direction},
        {"flex_wrap",serialize_flex_wrap},
        {"flex_grow",serialize_flex_grow},
        {"flex_shrink",serialize_flex_shrink},
        {"flex_basis",serialize_flex_basis},
        {"order",serialize_order},
        {"justify_content",serialize_justify_content},
        {"align_items",serialize_align_items},
        {"align_self",serialize_align_self},
        {"align_content",serialize_align_content},
        {"row_gap",serialize_row_gap},
        {"column_gap",serialize_column_gap},
        {"transform",serialize_transform},
        {"transform_origin",serialize_transform_origin},
        {"transform_style",serialize_transform_style},
        {"perspective",serialize_perspective},
        {"perspective_origin",serialize_perspective_origin},
        {"backface_visibility",serialize_backface_visibility},
        {"transition_property",serialize_transition_property},
        {"transition_duration",serialize_transition_duration},
        {"transition_timing_function",serialize_transition_timing_function},
        {"transition_delay",serialize_transition_delay},
        {"animation_name",serialize_animation_name},
        {"animation_duration",serialize_animation_duration},
        {"animation_timing_function",serialize_animation_timing_function},
        {"animation_delay",serialize_animation_delay},
        {"animation_iteration_count",serialize_animation_iteration_count},
        {"animation_direction",serialize_animation_direction},
        {"animation_fill_mode",serialize_animation_fill_mode},
        {"animation_play_state",serialize_animation_play_state},
        {"box_shadow",serialize_box_shadow},
        {"filter",serialize_filter},
        {"backdrop_filter",serialize_backdrop_filter},
        {"cursor",serialize_cursor},
        {"outline_style",serialize_outline_style},
        {"outline_width",serialize_outline_width},
        {"outline_color",serialize_outline_color},
        {"outline_offset",serialize_outline_offset},
        {"resize",serialize_resize},
        {"user_select",serialize_user_select},
        {"pointer_events",serialize_pointer_events},
        {"touch_action",serialize_touch_action},
        {"border_collapse",serialize_border_collapse},
        {"border_spacing",serialize_border_spacing},
        {"caption_side",serialize_caption_side},
        {"empty_cells",serialize_empty_cells},
        {"table_layout",serialize_table_layout},
        {"vertical_align",serialize_vertical_align},
        {"list_style_type",serialize_list_style_type},
        {"list_style_position",serialize_list_style_position},
        {"list_style_image",serialize_list_style_image},
        {"content",serialize_content},
        {"quotes",serialize_quotes},
        {"counter_increment",serialize_counter_increment},
        {"counter_reset",serialize_counter_reset},
        {"box_sizing",serialize_box_sizing},
        {"aspect_ratio",serialize_aspect_ratio},
        {"object_fit",serialize_object_fit},
        {"object_position",serialize_object_position},
        {"contain",serialize_contain},
        {"container_type",serialize_container_type},
        {"container_name",serialize_container_name},
        {"scroll_behavior",serialize_scroll_behavior},
        {"scrollbar_width",serialize_scrollbar_width},
        {"scrollbar_color",serialize_scrollbar_color},
        {"scroll_snap_type",serialize_scroll_snap_type},
        {"scroll_snap_align",serialize_scroll_snap_align},
        {"accent_color",serialize_accent_color},
        {"caret_color",serialize_caret_color},
        {"appearance",serialize_appearance},
        {"mix_blend_mode",serialize_mix_blend_mode},
        {"isolation",serialize_isolation},
        {"gap",serialize_gap},
        {"columns",serialize_columns},
        {"column_rule",serialize_column_rule},
        {"inset",serialize_inset},
        {"place_items",serialize_place_items},
        {"place_content",serialize_place_content},
        {"place_self",serialize_place_self},
    };
    auto it=map.find(name);return it!=map.end()?it->second:nullptr;
}

// Serialize all computed properties to a CSS string
std::string serialize_computed_style(const std::unordered_map<std::string,std::string>& computed) {
    std::ostringstream oss;
    for(const auto&[prop,val]:computed){
        if(val.empty())continue;
        auto ser=get_serializer(prop);
        std::string out=ser?ser(val):val;
        oss<<prop<<":"<<out<<";";
    }
    return oss.str();
}

#ifdef STYLE_TEST
bool test_serialization() {
    assert(serialize_width("100")=="100px");
    assert(serialize_opacity("0.5")=="0.5");
    assert(serialize_display("block")=="block");
    assert(serialize_color("red")=="red");
    assert(serialize_font_size("16")=="16px");
    return true;
}
#endif

} // namespace properties
} // namespace style