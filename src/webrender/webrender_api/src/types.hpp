/* MPL 2.0 */
//! WebRender core types — color, transform, rectangle, image, font, display items.
//! Original Rust: webrender_api/src/ (display_item.rs: 2356, display_list.rs: 2343, etc.)
#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include <array>
#include <optional>
#include <variant>
#include <memory>
#include <cmath>

namespace wr {

// ═══ Color ═══
struct ColorF { float r=0,g=0,b=0,a=1; ColorF()=default; ColorF(float r_,float g_,float b_,float a_=1):r(r_),g(g_),b(b_),a(a_){} };
struct ColorU { uint8_t r=0,g=0,b=0,a=255; ColorU()=default; ColorU(uint8_t r_,uint8_t g_,uint8_t b_,uint8_t a_=255):r(r_),g(g_),b(b_),a(a_){} };

// ═══ Geometry ═══
struct LayoutPoint { float x=0,y=0; };
struct LayoutSize { float width=0,height=0; };
struct LayoutRect { LayoutPoint origin; LayoutSize size; bool contains(const LayoutPoint& p)const{return p.x>=origin.x&&p.x<origin.x+size.width&&p.y>=origin.y&&p.y<origin.y+size.height;} };
struct DevicePoint { int x=0,y=0; };
struct DeviceSize { int width=0,height=0; };
struct DeviceRect { DevicePoint origin; DeviceSize size; };
struct DeviceIntPoint { int x=0,y=0; };
struct DeviceIntSize { int width=0,height=0; };
struct DeviceIntRect { DeviceIntPoint origin; DeviceIntSize size; };

// ═══ Transform ═══
struct LayoutTransform { std::array<float,16> m={1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}; };
struct LayoutToDeviceTransform { LayoutTransform transform; float scale=1; };

// ═══ Border ═══
enum class BorderStyle : uint8_t { None, Solid, Double, Dotted, Dashed, Hidden, Groove, Ridge, Inset, Outset };
struct BorderSide { ColorF color; BorderStyle style=BorderStyle::None; };
struct BorderRadius { LayoutSize top_left,top_right,bottom_left,bottom_right; };
struct BorderWidths { float top=0,right=0,bottom=0,left=0; };
struct BorderDetails { BorderWidths widths; BorderRadius radius; BorderSide top,right,bottom,left; };

// ═══ Gradient ═══
struct GradientStop { float offset=0; ColorF color; };
enum class ExtendMode : uint8_t { Clamp, Repeat, Mirror };
struct Gradient { LayoutPoint start, end; std::vector<GradientStop> stops; ExtendMode extend=ExtendMode::Clamp; };
struct RadialGradient { LayoutPoint center; LayoutSize radius; std::vector<GradientStop> stops; ExtendMode extend=ExtendMode::Clamp; };

// ═══ Image ═══  
using ImageKey = uint64_t;
struct ImageDescriptor { DeviceIntSize size; int format=0; int stride=0; bool is_opaque=false; };
struct ImageData { std::vector<uint8_t> bytes; };
struct ImageRendering { enum { Auto, CrispEdges, Pixelated }; int value=0; };

// ═══ Font ═══
using FontKey = uint64_t;
using FontInstanceKey = uint64_t;
struct GlyphInstance { uint32_t index=0; LayoutPoint point; };
struct FontInstanceOptions { int render_mode=0; int flags=0; float synthetic_italics=0; };

// ═══ Display items ═══
using PipelineId = uint64_t;
using SpatialId = uint64_t;
using ClipId = uint64_t;
using ItemTag = uint64_t;

enum class DisplayItemType : uint8_t {
    Rectangle, ClearRectangle, Text, Image, Border, Gradient, RadialGradient, BoxShadow,
    Line, Iframe, PushStackingContext, PopStackingContext, PushReferenceFrame, PopReferenceFrame,
    PushClip, PopClip, PushClipAndScrollInfo, PopClipAndScrollInfo,
    SetPoints, BackdropFilter, Filter, CacheMarker, GradientBorder,
};

struct CommonItemProperties {
    LayoutRect clip_rect;
    SpatialId spatial_id=0;
    ClipId clip_id=0;
    bool is_backface_visible=true;
    ItemTag tag=0;
};

struct RectangleDisplayItem { CommonItemProperties common; ColorF color; };
struct ClearRectangleDisplayItem { CommonItemProperties common; };
struct TextDisplayItem { CommonItemProperties common; FontInstanceKey font_key=0; ColorF color; uint32_t glyph_range_start=0, glyph_range_length=0; std::vector<GlyphInstance> glyphs; };
struct ImageDisplayItem { CommonItemProperties common; ImageKey image_key=0; float opacity=1; ImageRendering rendering; ColorF color; };
struct BorderDisplayItem { CommonItemProperties common; BorderDetails border; };
struct GradientDisplayItem { CommonItemProperties common; Gradient gradient; LayoutSize tile_size; LayoutPoint tile_spacing; };
struct RadialGradientDisplayItem { CommonItemProperties common; RadialGradient gradient; LayoutSize tile_size; LayoutPoint tile_spacing; };
struct BoxShadowDisplayItem { CommonItemProperties common; LayoutRect box_bounds; float blur_radius=0,spread_radius=0; ColorF color; int clip_mode=0; };
struct LineDisplayItem { CommonItemProperties common; LayoutPoint start,end; float wavy_line_thickness=0; int orientation=0; ColorF color; int style=0; };

// ═══ Stacking context ═══
enum class MixBlendMode : uint8_t { Normal, Multiply, Screen, Overlay, Darken, Lighten, ColorDodge, ColorBurn, HardLight, SoftLight, Difference, Exclusion, Hue, Saturation, Color, Luminosity };
enum class TransformStyle : uint8_t { Flat, Preserve3D };
struct StackingContext {
    LayoutTransform transform;
    MixBlendMode mix_blend_mode=MixBlendMode::Normal;
    float opacity=1;
    std::vector<int> filters;
    bool is_backface_visible=true;
    TransformStyle transform_style=TransformStyle::Flat;
};

// ═══ Display list ═══
struct DisplayListBuilder {
    std::vector<uint8_t> data;
    std::vector<LayoutRect> clip_chain;
    PipelineId pipeline_id=0;
    LayoutSize content_size;
};

// ═══ Hit testing ═══
struct HitTestItem { PipelineId pipeline=0; ItemTag tag=0; LayoutRect rect; SpatialId spatial_id=0; };
struct HitTestResult { std::vector<HitTestItem> items; };

} // namespace wr
