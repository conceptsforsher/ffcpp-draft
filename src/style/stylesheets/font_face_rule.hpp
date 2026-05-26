/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

/**
 * @file font_face_rule.hpp
 * @brief A @font-face rule for defining custom fonts.
 *
 * Translated from servo/components/style/stylesheets/font_face_rule.rs
 * which re-exports crate::font_face::FontFaceRuleData as FontFaceRule.
 */

#pragma once

#include "style/stylesheets/stylesheets.hpp"

#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <optional>

namespace style {
namespace stylesheets {

// ============================================================================
// FontFaceSourceFormatKeyword - Font format identifiers
// ============================================================================

/**
 * Font format keywords for the src descriptor.
 *
 * https://drafts.csswg.org/css-fonts-4/#font-face-src-parsing
 */
enum class FontFaceSourceFormatKeyword {
    Woff,
    Woff2,
    Truetype,
    Opentype,
    EmbeddedOpentype,
    Svg,
    Collection,
    Unknown,
};

inline const char* FontFormatToString(FontFaceSourceFormatKeyword kw) {
    switch (kw) {
        case FontFaceSourceFormatKeyword::Woff: return "woff";
        case FontFaceSourceFormatKeyword::Woff2: return "woff2";
        case FontFaceSourceFormatKeyword::Truetype: return "truetype";
        case FontFaceSourceFormatKeyword::Opentype: return "opentype";
        case FontFaceSourceFormatKeyword::EmbeddedOpentype: return "embedded-opentype";
        case FontFaceSourceFormatKeyword::Svg: return "svg";
        case FontFaceSourceFormatKeyword::Collection: return "collection";
        default: return "unknown";
    }
}

inline FontFaceSourceFormatKeyword FontFormatFromString(const std::string& s) {
    if (s == "woff") return FontFaceSourceFormatKeyword::Woff;
    if (s == "woff2") return FontFaceSourceFormatKeyword::Woff2;
    if (s == "truetype") return FontFaceSourceFormatKeyword::Truetype;
    if (s == "opentype") return FontFaceSourceFormatKeyword::Opentype;
    if (s == "embedded-opentype") return FontFaceSourceFormatKeyword::EmbeddedOpentype;
    if (s == "svg") return FontFaceSourceFormatKeyword::Svg;
    if (s == "collection") return FontFaceSourceFormatKeyword::Collection;
    return FontFaceSourceFormatKeyword::Unknown;
}

// ============================================================================
// FontFaceSourceTechFlags - Font technology flags
// ============================================================================

/**
 * Font technology flags for the tech() function in src descriptor.
 *
 * https://drafts.csswg.org/css-fonts-4/#font-face-src-parsing
 */
enum class FontFaceSourceTechFlags : uint32_t {
    None = 0,
    FeatureOpentype = 1 << 0,
    FeatureAat = 1 << 1,
    FeatureGraphite = 1 << 2,
    ColorCbdt = 1 << 3,
    ColorColrv0 = 1 << 4,
    ColorColrv1 = 1 << 5,
    ColorSvg = 1 << 6,
    ColorSbix = 1 << 7,
    Variations = 1 << 8,
    Palette = 1 << 9,
    Incremental = 1 << 10,
};

inline const char* FontTechToString(FontFaceSourceTechFlags flag) {
    switch (flag) {
        case FontFaceSourceTechFlags::FeatureOpentype: return "feature-opentype";
        case FontFaceSourceTechFlags::FeatureAat: return "feature-aat";
        case FontFaceSourceTechFlags::FeatureGraphite: return "feature-graphite";
        case FontFaceSourceTechFlags::ColorCbdt: return "color-cbdt";
        case FontFaceSourceTechFlags::ColorColrv0: return "color-COLRv0";
        case FontFaceSourceTechFlags::ColorColrv1: return "color-COLRv1";
        case FontFaceSourceTechFlags::ColorSvg: return "color-SVG";
        case FontFaceSourceTechFlags::ColorSbix: return "color-sbix";
        case FontFaceSourceTechFlags::Variations: return "variations";
        case FontFaceSourceTechFlags::Palette: return "palettes";
        case FontFaceSourceTechFlags::Incremental: return "incremental";
        default: return "unknown";
    }
}

// ============================================================================
// FontFaceRule - A @font-face rule
// ============================================================================

/**
 * A @font-face rule defining a custom font face.
 *
 * Key CSS descriptors:
 * - font-family: The family name
 * - src: The source URL(s) for the font
 * - font-style: The font style (normal, italic, oblique)
 * - font-weight: The font weight (100-900, bold, normal)
 * - font-stretch: The font stretch
 * - unicode-range: The range of Unicode characters
 * - font-display: How the font is displayed while loading
 *
 * Translated from: FontFaceRuleData (font_face crate)
 */
class FontFaceRule {
public:
    /// The font-family descriptor.
    std::optional<std::string> family;

    /// The src descriptor (comma-separated font sources).
    std::optional<std::string> src;

    /// The font-style descriptor.
    std::optional<std::string> style;

    /// The font-weight descriptor.
    std::optional<std::string> weight;

    /// The font-stretch descriptor.
    std::optional<std::string> stretch;

    /// The unicode-range descriptor.
    std::optional<std::string> unicode_range;

    /// The font-display descriptor.
    std::optional<std::string> display;

    /// The font-feature-settings descriptor.
    std::optional<std::string> feature_settings;

    /// The font-variation-settings descriptor.
    std::optional<std::string> variation_settings;

    /// The ascent-override descriptor.
    std::optional<std::string> ascent_override;

    /// The descent-override descriptor.
    std::optional<std::string> descent_override;

    /// The line-gap-override descriptor.
    std::optional<std::string> line_gap_override;

    /// The size-adjust descriptor.
    std::optional<std::string> size_adjust;

    /// The source location where this rule was found.
    SourceLocation source_location;

    FontFaceRule() = default;

    // Copy and move
    FontFaceRule(const FontFaceRule&) = default;
    FontFaceRule& operator=(const FontFaceRule&) = default;
    FontFaceRule(FontFaceRule&&) noexcept = default;
    FontFaceRule& operator=(FontFaceRule&&) noexcept = default;

    /**
     * Get a descriptor value by name.
     */
    std::optional<std::string> GetDescriptor(const std::string& name) const {
        if (name == "font-family") return family;
        if (name == "src") return src;
        if (name == "font-style") return style;
        if (name == "font-weight") return weight;
        if (name == "font-stretch") return stretch;
        if (name == "unicode-range") return unicode_range;
        if (name == "font-display") return display;
        if (name == "font-feature-settings") return feature_settings;
        if (name == "font-variation-settings") return variation_settings;
        if (name == "ascent-override") return ascent_override;
        if (name == "descent-override") return descent_override;
        if (name == "line-gap-override") return line_gap_override;
        if (name == "size-adjust") return size_adjust;
        return std::nullopt;
    }

    /**
     * Set a descriptor value by name.
     */
    void SetDescriptor(const std::string& name, const std::string& value) {
        if (name == "font-family") family = value;
        else if (name == "src") src = value;
        else if (name == "font-style") style = value;
        else if (name == "font-weight") weight = value;
        else if (name == "font-stretch") stretch = value;
        else if (name == "unicode-range") unicode_range = value;
        else if (name == "font-display") display = value;
        else if (name == "font-feature-settings") feature_settings = value;
        else if (name == "font-variation-settings") variation_settings = value;
        else if (name == "ascent-override") ascent_override = value;
        else if (name == "descent-override") descent_override = value;
        else if (name == "line-gap-override") line_gap_override = value;
        else if (name == "size-adjust") size_adjust = value;
    }

    /**
     * Serialize to CSS text.
     */
    std::string ToCss() const {
        std::ostringstream oss;
        oss << "@font-face {";
        bool has_content = false;

        auto emit_descriptor = [&](const char* name, const std::optional<std::string>& val) {
            if (val.has_value()) {
                oss << "\n  " << name << ": " << val.value() << ";";
                has_content = true;
            }
        };

        emit_descriptor("font-family", family);
        emit_descriptor("src", src);
        emit_descriptor("font-style", style);
        emit_descriptor("font-weight", weight);
        emit_descriptor("font-stretch", stretch);
        emit_descriptor("unicode-range", unicode_range);
        emit_descriptor("font-display", display);
        emit_descriptor("font-feature-settings", feature_settings);
        emit_descriptor("font-variation-settings", variation_settings);
        emit_descriptor("ascent-override", ascent_override);
        emit_descriptor("descent-override", descent_override);
        emit_descriptor("line-gap-override", line_gap_override);
        emit_descriptor("size-adjust", size_adjust);

        if (has_content) oss << "\n";
        oss << "}";
        return oss.str();
    }

    /**
     * Deep clone this font-face rule.
     */
    FontFaceRule DeepClone() const {
        return *this; // All members are copyable
    }

    std::string ToDebugString() const {
        std::ostringstream oss;
        oss << "FontFaceRule{ family=" << (family.value_or("(none)"))
            << ", source=" << source_location.ToString() << " }";
        return oss.str();
    }
};

// ============================================================================
// Test utilities
// ============================================================================

namespace test {

inline FontFaceRule MakeTestFontFaceRule(const std::string& family_name = "MyFont") {
    FontFaceRule rule;
    rule.family = family_name;
    rule.src = "url(\"" + family_name + ".woff2\") format(\"woff2\")";
    rule.weight = "400";
    rule.style = "normal";
    rule.display = "swap";
    return rule;
}

} // namespace test

} // namespace stylesheets
} // namespace style
