/* MPL 2.0 */
//! @font-face descriptor types and font matching.
//! Corresponds to font_face.rs (753 lines)
#pragma once
#include <string>
#include <vector>
#include <cstdint>
#include "style/values/specified/length.hpp"

namespace style { namespace font_face {

enum class FontStyle : uint8_t { Normal, Italic, Oblique };
enum class FontStretch : uint8_t { UltraCondensed=1, ExtraCondensed, Condensed, SemiCondensed, Normal=5, SemiExpanded, Expanded, ExtraExpanded, UltraExpanded };
enum class FontDisplay : uint8_t { Auto, Block, Swap, Fallback, Optional };

struct FontWeight { int min=400, max=400; FontWeight()=default; FontWeight(int w):min(w),max(w){} };

struct UnicodeRange { uint32_t start=0, end=0x10FFFF; };

struct FontFaceSource { std::string url; std::string format; bool is_local=false; };

struct FontFaceDescriptors {
    std::string family;
    std::vector<FontFaceSource> sources;
    FontWeight weight;
    FontStyle style=FontStyle::Normal;
    FontStretch stretch=FontStretch::Normal;
    FontDisplay display=FontDisplay::Auto;
    std::vector<UnicodeRange> unicode_ranges;
    std::string feature_settings;
    std::string variation_settings;
    float ascent_override=-1, descent_override=-1, line_gap_override=-1;
    float size_adjust=100.0f;

    bool matches_weight(int w) const { return w>=weight.min&&w<=weight.max; }
    bool matches_style(FontStyle s) const { return style==FontStyle::Normal||s==style; }
    bool matches_stretch(FontStretch s) const { return stretch==FontStretch::Normal||s==stretch; }
    bool covers_character(uint32_t cp) const {
        for(auto&r:unicode_ranges) if(cp>=r.start&&cp<=r.end) return true;
        return unicode_ranges.empty();
    }
};

}}} // namespace
