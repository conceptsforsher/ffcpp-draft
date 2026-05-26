/* MPL 2.0 */
//! @font-face rule: loading web fonts.
//! https://drafts.csswg.org/css-fonts-4/#font-face-rule
#include "style/stylesheets/font_face_rule.hpp"
#include <algorithm>
#include <cctype>

namespace style { namespace stylesheets {

FontFaceRule::FontFaceRule() = default;
FontFaceRule::~FontFaceRule() = default;

void FontFaceRule::set_family(const std::string& family) {
    // Strip quotes if present
    family_ = family;
    if ((family_.starts_with("\"") && family_.ends_with("\"")) ||
        (family_.starts_with("'") && family_.ends_with("'"))) {
        family_ = family_.substr(1, family_.size() - 2);
    }
}

void FontFaceRule::add_source(const FontSource& source) {
    sources_.push_back(source);
}

void FontFaceRule::set_weight(int min_weight, int max_weight) {
    weight_min_ = min_weight;
    weight_max_ = max_weight >= 0 ? max_weight : min_weight;
}

void FontFaceRule::set_stretch(float min_stretch, float max_stretch) {
    stretch_min_ = min_stretch;
    stretch_max_ = max_stretch >= 0.0f ? max_stretch : min_stretch;
}

void FontFaceRule::set_style(FontStyle style, FontStyle style2) {
    style_ = style;
    style2_ = style2;
}

void FontFaceRule::add_unicode_range(uint32_t start, uint32_t end) {
    unicode_ranges_.push_back({start, end});
}

void FontFaceRule::set_display(FontDisplay display) {
    display_ = display;
}

void FontFaceRule::set_feature_settings(const std::string& settings) {
    feature_settings_ = settings;
}

void FontFaceRule::set_variation_settings(const std::string& settings) {
    variation_settings_ = settings;
}

bool FontFaceRule::matches(int weight, float stretch, FontStyle style) const {
    // Weight matching: must be within range
    if (weight < weight_min_ || weight > weight_max_) return false;
    
    // Stretch matching
    if (stretch < stretch_min_ || stretch > stretch_max_) return false;
    
    // Style matching
    if (style_ != FontStyle::Auto && style != style_) {
        if (style2_ != FontStyle::Auto && style != style2_) return false;
        if (style2_ == FontStyle::Auto) return false;
    }
    
    return true;
}

bool FontFaceRule::covers_character(uint32_t codepoint) const {
    if (unicode_ranges_.empty()) return true;  // No ranges = all characters
    for (const auto& range : unicode_ranges_) {
        if (codepoint >= range.start && codepoint <= range.end) return true;
    }
    return false;
}

const std::string& FontFaceRule::family() const { return family_; }
const std::vector<FontSource>& FontFaceRule::sources() const { return sources_; }
int FontFaceRule::weight_min() const { return weight_min_; }
int FontFaceRule::weight_max() const { return weight_max_; }
FontDisplay FontFaceRule::display() const { return display_; }

const char* FontFaceRule::display_name() const {
    switch (display_) {
        case FontDisplay::Auto: return "auto";
        case FontDisplay::Block: return "block";
        case FontDisplay::Swap: return "swap";
        case FontDisplay::Fallback: return "fallback";
        case FontDisplay::Optional: return "optional";
    }
    return "auto";
}

void FontFaceRule::to_css(std::ostream& dest) const {
    dest << "@font-face {\n";
    dest << "  font-family: \"" << family_ << "\";\n";
    for (const auto& src : sources_) {
        dest << "  src: " << src.to_css() << ";\n";
    }
    if (weight_min_ != 0 || weight_max_ != 0) {
        dest << "  font-weight: " << weight_min_;
        if (weight_max_ != weight_min_) dest << " " << weight_max_;
        dest << ";\n";
    }
    if (stretch_min_ > 0.0f) {
        dest << "  font-stretch: " << stretch_min_ << "%;\n";
    }
    if (style_ != FontStyle::Auto) {
        dest << "  font-style: " << FontFaceRule::style_name(style_) << ";\n";
    }
    if (!unicode_ranges_.empty()) {
        dest << "  unicode-range: ";
        for (size_t i = 0; i < unicode_ranges_.size(); ++i) {
            if (i > 0) dest << ", ";
            dest << "U+" << std::hex << std::uppercase << unicode_ranges_[i].start
                 << "-" << unicode_ranges_[i].end;
            dest << std::dec << std::nouppercase;
        }
        dest << ";\n";
    }
    dest << "  font-display: " << display_name() << ";\n";
    dest << "}";
}

const char* FontFaceRule::style_name(FontStyle s) {
    switch (s) {
        case FontStyle::Normal: return "normal";
        case FontStyle::Italic: return "italic";
        case FontStyle::Oblique: return "oblique";
        default: return "auto";
    }
}

// FontSource::to_css()
std::string FontSource::to_css() const {
    std::ostringstream oss;
    if (is_local) {
        oss << "local(\"" << location << "\")";
    } else {
        oss << "url(\"" << location << "\")";
        if (!format.empty()) oss << " format(\"" << format << "\")";
        if (!tech.empty()) oss << " tech(" << tech << ")";
    }
    return oss.str();
}

#ifdef STYLE_TEST
bool test_font_face() {
    FontFaceRule rule;
    rule.set_family("\"My Font\"");
    assert(rule.family() == "My Font");
    
    FontSource src;
    src.location = "myfont.woff2";
    src.format = "woff2";
    rule.add_source(src);
    assert(rule.sources().size() == 1);
    
    rule.set_weight(400, 700);
    assert(rule.weight_min() == 400);
    assert(rule.weight_max() == 700);
    assert(rule.matches(600, 100.0f, FontStyle::Normal));
    assert(!rule.matches(300, 100.0f, FontStyle::Normal));
    
    rule.add_unicode_range(0x0000, 0x00FF);
    assert(rule.covers_character('A'));
    assert(!rule.covers_character(0x4E00));
    
    return true;
}
#endif

}} // namespace
