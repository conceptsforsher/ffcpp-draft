/* MPL 2.0 */
//! CSS Properties — PropertyId enum and declarations.
#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include <optional>

namespace style { namespace properties {

enum class PropertyId : uint16_t {
    all=0,animation=1,background=2,border=3,border_block=4,border_block_end=5,
    border_block_start=6,border_bottom=7,border_color=8,border_image=9,
    border_inline=10,border_inline_end=11,border_inline_start=12,border_left=13,
    border_radius=14,border_right=15,border_style=16,border_top=17,border_width=18,
    column_rule=19,columns=20,contain_intrinsic_size=21,container=22,flex=23,
    flex_flow=24,font=25,font_synthesis=26,font_variant=27,gap=28,grid=29,
    grid_area=30,grid_column=31,grid_row=32,grid_template=33,inset=34,
    list_style=35,margin=36,margin_block=37,margin_inline=38,mask=39,
    offset=40,outline=41,overflow=42,overscroll_behavior=43,padding=44,
    padding_block=45,padding_inline=46,place_content=47,place_items=48,
    place_self=49,scroll_margin=50,scroll_padding=51,scroll_timeline=52,
    text_decoration=53,text_emphasis=54,transition=55,view_timeline=56,
    webkit_border_before=57,webkit_mask=58,webkit_text_stroke=59,
    // Longhands
    width=60,min_width=61,max_width=62,height=63,min_height=64,max_height=65,
    margin_top=66,margin_right=67,margin_bottom=68,margin_left=69,
    padding_top=70,padding_right=71,padding_bottom=72,padding_left=73,
    border_top_width=74,border_right_width=75,border_bottom_width=76,border_left_width=77,
    border_top_style=78,border_right_style=79,border_bottom_style=80,border_left_style=81,
    border_top_color=82,border_right_color=83,border_bottom_color=84,border_left_color=85,
    border_top_left_radius=86,border_top_right_radius=87,border_bottom_right_radius=88,border_bottom_left_radius=89,
    display=90,position=91,top=92,right=93,bottom=94,left=95,
    z_index=96,float_val=97,clear=98,overflow_x=99,overflow_y=100,
    visibility=101,opacity=102,color=103,background_color=104,background_image=105,
    background_size=106,background_repeat=107,background_position_x=108,background_position_y=109,
    background_attachment=110,background_clip=111,background_origin=112,
    font_family=113,font_size=114,font_weight=115,font_style=116,font_stretch=117,
    line_height=118,text_align=119,text_decoration_line=120,text_decoration_style=121,
    text_decoration_color=122,text_transform=123,text_indent=124,text_overflow=125,
    white_space=126,word_break=127,overflow_wrap=128,hyphens=129,
    letter_spacing=130,word_spacing=131,tab_size=132,direction=133,writing_mode=134,
    text_orientation=135,unicode_bidi=136,
    flex_direction=137,flex_wrap=138,flex_grow=139,flex_shrink=140,flex_basis=141,
    order=142,justify_content=143,align_items=144,align_self=145,align_content=146,
    row_gap=147,column_gap=148,
    transform=149,transform_origin=150,transform_style=151,perspective=152,
    perspective_origin=153,backface_visibility=154,
    transition_property=155,transition_duration=156,transition_timing_function=157,transition_delay=158,
    animation_name=159,animation_duration=160,animation_timing_function=161,animation_delay=162,
    animation_iteration_count=163,animation_direction=164,animation_fill_mode=165,animation_play_state=166,
    box_shadow=167,filter=168,backdrop_filter=169,cursor=170,
    outline_style=171,outline_width=172,outline_color=173,outline_offset=174,
    resize=175,user_select=176,pointer_events=177,touch_action=178,
    border_collapse=179,border_spacing=180,caption_side=181,empty_cells=182,table_layout=183,
    vertical_align=184,list_style_type=185,list_style_position=186,list_style_image=187,
    content=188,quotes=189,counter_increment=190,counter_reset=191,
    box_sizing=192,aspect_ratio=193,object_fit=194,object_position=195,
    contain=196,container_type=197,container_name=198,
    scroll_behavior=199,scrollbar_width=200,scrollbar_color=201,
    scroll_snap_type=202,scroll_snap_align=203,
    accent_color=204,caret_color=205,appearance=206,mix_blend_mode=207,isolation=208,
    _COUNT=209
};

enum class PropertyType : uint8_t { Longhand, Shorthand, Alias };

const char* property_name(PropertyId id);
const char* initial_value(PropertyId id);
bool is_inherited(PropertyId id);
PropertyType property_type(PropertyId id);
std::vector<std::string> get_shorthand_longhands(const std::string& sh);

struct PropertyDeclaration { PropertyId id; std::string value; bool important=false; };
struct PropertyDeclarationBlock {
    std::vector<PropertyDeclaration> decls;
    void set(PropertyId id, std::string val, bool imp=false);
    const std::string* get(PropertyId id) const;
    size_t size() const { return decls.size(); }
    bool empty() const { return decls.empty(); }
};

enum class CSSWideKeyword { Inherit, Initial, Unset, Revert, RevertLayer };
std::optional<CSSWideKeyword> parse_css_wide_keyword(const std::string& val);

} // namespace properties
} // namespace style
