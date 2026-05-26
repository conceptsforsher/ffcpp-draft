/* MPL 2.0 */
//! Specified color values.
#pragma once
#include <string>
#include "style/color/types.hpp"

namespace style { namespace values { namespace specified {

using color::RGBAColor;

enum class ColorTag : uint8_t { CurrentColor, Transparent, Named, Hex, RGBA };

struct SpecifiedColor {
    ColorTag tag = ColorTag::Transparent;
    RGBAColor rgba;
    std::string parsed_value;

    SpecifiedColor() = default;
    static SpecifiedColor current_color() { SpecifiedColor c; c.tag=ColorTag::CurrentColor; return c; }
    static SpecifiedColor transparent() { SpecifiedColor c; c.tag=ColorTag::Transparent; c.rgba=RGBAColor::transparent(); return c; }
    static SpecifiedColor rgba_val(float r,float g,float b,float a=1.0f) { SpecifiedColor c; c.tag=ColorTag::RGBA; c.rgba=RGBAColor(r,g,b,a); return c; }
    static SpecifiedColor hex(uint8_t r,uint8_t g,uint8_t b) { SpecifiedColor c; c.tag=ColorTag::Hex; c.rgba=RGBAColor::from_u8(r,g,b); return c; }
    static SpecifiedColor named(const std::string& n) { SpecifiedColor c; c.tag=ColorTag::Named; c.parsed_value=n; auto f=color::lookup_named_color(n); c.rgba=f.value_or(RGBAColor::transparent()); return c; }
    bool is_current_color() const { return tag==ColorTag::CurrentColor; }
};

}}} // namespace
