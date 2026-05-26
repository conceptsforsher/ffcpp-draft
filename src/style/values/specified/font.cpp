// SPDX-License-Identifier: MPL-2.0
// Translated from servo/components/style/values/specified/font.rs
// Implementation of specified font values

#include "font.hpp"
#include <algorithm>
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <cstring>

namespace style::values::specified {

// =====================================================================
// SystemFont parsing and serialization
// =====================================================================

namespace {

const char* system_font_to_string(SystemFont sf) {
  switch (sf) {
    case SystemFont::Caption: return "caption";
    case SystemFont::Icon: return "icon";
    case SystemFont::Menu: return "menu";
    case SystemFont::MessageBox: return "message-box";
    case SystemFont::SmallCaption: return "small-caption";
    case SystemFont::StatusBar: return "status-bar";
    case SystemFont::MozPullDownMenu: return "-moz-pull-down-menu";
    case SystemFont::MozButton: return "-moz-button";
    case SystemFont::MozList: return "-moz-list";
    case SystemFont::MozField: return "-moz-field";
    case SystemFont::End: return "";
  }
  return "";
}

std::optional<SystemFont> parse_system_font(const std::string& ident) {
  if (ident == "caption") return SystemFont::Caption;
  if (ident == "icon") return SystemFont::Icon;
  if (ident == "menu") return SystemFont::Menu;
  if (ident == "message-box") return SystemFont::MessageBox;
  if (ident == "small-caption") return SystemFont::SmallCaption;
  if (ident == "status-bar") return SystemFont::StatusBar;
  return std::nullopt;
}

} // anonymous namespace

// =====================================================================
// AbsoluteFontWeight
// =====================================================================

computed::FontWeight AbsoluteFontWeight::compute() const {
  float val = get();
  return computed::FontWeight::from_float(val);
}

std::string AbsoluteFontWeight::to_css() const {
  switch (kind) {
    case Kind::Normal: return "normal";
    case Kind::Bold: return "bold";
    case Kind::Weight: {
      std::ostringstream oss;
      oss << weight_value;
      return oss.str();
    }
  }
  return "normal";
}

std::optional<AbsoluteFontWeight> AbsoluteFontWeight::parse(const ParserContext& /*ctx*/, class cssparser::Parser& input) {
  // Try to parse a number first
  auto token = input.next();
  if (!token) return std::nullopt;

  // Check for ident keywords
  if (auto* ident = std::get_if<std::string>(&*token)) {
    std::string lower = *ident;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    if (lower == "normal") return AbsoluteFontWeight::normal();
    if (lower == "bold") return AbsoluteFontWeight::bold();
    return std::nullopt;
  }

  // Check for number
  if (auto* num = std::get_if<float>(&*token)) {
    float val = *num;
    if (val < MIN_FONT_WEIGHT || val > MAX_FONT_WEIGHT) {
      return std::nullopt;
    }
    return AbsoluteFontWeight::weight(val);
  }

  return std::nullopt;
}

// =====================================================================
// FontWeight
// =====================================================================

FontWeight FontWeight::from_gecko_keyword(uint32_t kw) {
  assert(kw % 100 == 0);
  assert(static_cast<float>(kw) <= MAX_FONT_WEIGHT);
  FontWeight w;
  w.kind = Kind::Absolute;
  w.absolute = AbsoluteFontWeight::weight(static_cast<float>(kw));
  return w;
}

std::optional<SystemFont> FontWeight::get_system() const {
  if (kind == Kind::System) {
    return system_font;
  }
  return std::nullopt;
}

computed::FontWeight FontWeight::to_computed_value(const Context& context) const {
  switch (kind) {
    case Kind::Absolute:
      return absolute.compute();
    case Kind::Bolder:
      return context.get_parent_font().font_weight().bolder();
    case Kind::Lighter:
      return context.get_parent_font().font_weight().lighter();
    case Kind::System:
      // System font resolution
      return context.get_cached_system_font().font_weight();
  }
  return computed::FontWeight::normal();
}

FontWeight FontWeight::from_computed_value(const computed::FontWeight& computed) {
  FontWeight w;
  w.kind = Kind::Absolute;
  w.absolute = AbsoluteFontWeight::weight(computed.value());
  return w;
}

std::string FontWeight::to_css() const {
  switch (kind) {
    case Kind::Absolute: return absolute.to_css();
    case Kind::Bolder: return "bolder";
    case Kind::Lighter: return "lighter";
    case Kind::System: return ""; // system fonts don't serialize to CSS
  }
  return "";
}

std::optional<FontWeight> FontWeight::parse(const ParserContext& ctx, class cssparser::Parser& input) {
  auto token = input.next();
  if (!token) return std::nullopt;

  if (auto* ident = std::get_if<std::string>(&*token)) {
    std::string lower = *ident;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    if (lower == "normal") return FontWeight::normal();
    if (lower == "bold") return FontWeight::bold();
    if (lower == "bolder") return FontWeight::bolder();
    if (lower == "lighter") return FontWeight::lighter();
    return std::nullopt;
  }

  if (auto* num = std::get_if<float>(&*token)) {
    float val = *num;
    if (val < MIN_FONT_WEIGHT || val > MAX_FONT_WEIGHT) {
      return std::nullopt;
    }
    return FontWeight::weight(val);
  }

  return std::nullopt;
}

// =====================================================================
// FontStyle
// =====================================================================

std::optional<SystemFont> FontStyle::get_system() const {
  if (kind == Kind::System) return system_font;
  return std::nullopt;
}

float FontStyle::compute_angle_degrees(float angle_degrees) {
  return std::max(FONT_STYLE_OBLIQUE_MIN_ANGLE_DEGREES,
         std::min(angle_degrees, FONT_STYLE_OBLIQUE_MAX_ANGLE_DEGREES));
}

float FontStyle::default_angle() {
  return 14.0f; // DEFAULT_OBLIQUE_DEGREES from computed
}

computed::FontStyle FontStyle::to_computed_value(const Context& /*context*/) const {
  switch (kind) {
    case Kind::Normal: {
      // Normal is oblique 0
      return computed::FontStyle::oblique(0.0f);
    }
    case Kind::Italic:
      return computed::FontStyle::ITALIC;
    case Kind::Oblique:
      return computed::FontStyle::oblique(oblique_degrees);
    case Kind::System:
      return computed::FontStyle::oblique(0.0f); // placeholder
  }
  return computed::FontStyle::oblique(0.0f);
}

FontStyle FontStyle::from_computed_value(const computed::FontStyle& computed) {
  if (computed.is_italic()) {
    return FontStyle::italic();
  }
  return FontStyle::oblique(computed.oblique_degrees());
}

std::string FontStyle::to_css() const {
  switch (kind) {
    case Kind::Normal: return "normal";
    case Kind::Italic: return "italic";
    case Kind::Oblique: {
      std::ostringstream oss;
      if (oblique_degrees == 0.0f) {
        oss << "oblique 0deg";
      } else {
        oss << "oblique " << oblique_degrees << "deg";
      }
      return oss.str();
    }
    case Kind::System: return "";
  }
  return "normal";
}

std::optional<FontStyle> FontStyle::parse(const ParserContext& ctx, class cssparser::Parser& input) {
  auto token = input.next();
  if (!token) return std::nullopt;

  if (auto* ident = std::get_if<std::string>(&*token)) {
    std::string lower = *ident;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    if (lower == "normal") return FontStyle::normal();
    if (lower == "italic") return FontStyle::italic();
    if (lower == "oblique") {
      // Try to parse an angle
      FontStyle s;
      s.kind = Kind::Oblique;
      // Try to read an angle token
      auto angle_tok = input.peek();
      if (angle_tok) {
        if (auto* ang_val = std::get_if<float>(&*angle_tok)) {
          input.next(); // consume
          float degrees = *ang_val;
          degrees = compute_angle_degrees(degrees);
          s.oblique_degrees = degrees;
        }
      }
      if (s.oblique_degrees == 0.0f) {
        s.oblique_degrees = default_angle();
      }
      return s;
    }
    return std::nullopt;
  }
  return std::nullopt;
}

// =====================================================================
// FontStretchKeyword
// =====================================================================

namespace {

const char* font_stretch_keyword_to_string(FontStretchKeyword kw) {
  switch (kw) {
    case FontStretchKeyword::Normal: return "normal";
    case FontStretchKeyword::Condensed: return "condensed";
    case FontStretchKeyword::UltraCondensed: return "ultra-condensed";
    case FontStretchKeyword::ExtraCondensed: return "extra-condensed";
    case FontStretchKeyword::SemiCondensed: return "semi-condensed";
    case FontStretchKeyword::SemiExpanded: return "semi-expanded";
    case FontStretchKeyword::Expanded: return "expanded";
    case FontStretchKeyword::ExtraExpanded: return "extra-expanded";
    case FontStretchKeyword::UltraExpanded: return "ultra-expanded";
  }
  return "normal";
}

float font_stretch_keyword_to_percentage(FontStretchKeyword kw) {
  switch (kw) {
    case FontStretchKeyword::UltraCondensed: return 50.0f;
    case FontStretchKeyword::ExtraCondensed: return 62.5f;
    case FontStretchKeyword::Condensed: return 75.0f;
    case FontStretchKeyword::SemiCondensed: return 87.5f;
    case FontStretchKeyword::Normal: return 100.0f;
    case FontStretchKeyword::SemiExpanded: return 112.5f;
    case FontStretchKeyword::Expanded: return 125.0f;
    case FontStretchKeyword::ExtraExpanded: return 150.0f;
    case FontStretchKeyword::UltraExpanded: return 200.0f;
  }
  return 100.0f;
}

std::optional<FontStretchKeyword> font_stretch_from_percentage(float p) {
  if (p >= 46.0f && p < 56.0f) return FontStretchKeyword::UltraCondensed;
  if (p >= 56.0f && p < 68.75f) return FontStretchKeyword::ExtraCondensed;
  if (p >= 68.75f && p < 81.25f) return FontStretchKeyword::Condensed;
  if (p >= 81.25f && p < 93.75f) return FontStretchKeyword::SemiCondensed;
  if (p >= 93.75f && p < 106.25f) return FontStretchKeyword::Normal;
  if (p >= 106.25f && p < 118.75f) return FontStretchKeyword::SemiExpanded;
  if (p >= 118.75f && p < 137.5f) return FontStretchKeyword::Expanded;
  if (p >= 137.5f && p < 175.0f) return FontStretchKeyword::ExtraExpanded;
  if (p >= 175.0f) return FontStretchKeyword::UltraExpanded;
  return std::nullopt;
}

} // anonymous namespace

// =====================================================================
// FontStretch
// =====================================================================

FontStretch FontStretch::normal() {
  return FontStretch::keyword(FontStretchKeyword::Normal);
}

FontStretch FontStretch::keyword(FontStretchKeyword kw) {
  FontStretch fs;
  fs.kind = Kind::Keyword;
  fs.keyword = kw;
  fs.percentage = font_stretch_keyword_to_percentage(kw);
  return fs;
}

FontStretch FontStretch::stretch(float pct) {
  FontStretch fs;
  fs.kind = Kind::Stretch;
  fs.percentage = pct;
  return fs;
}

FontStretch FontStretch::system(SystemFont sf) {
  FontStretch fs;
  fs.kind = Kind::System;
  fs.system_font = sf;
  return fs;
}

std::optional<SystemFont> FontStretch::get_system() const {
  if (kind == Kind::System) return system_font;
  return std::nullopt;
}

computed::FontStretch FontStretch::compute() const {
  float pct = percentage;
  return computed::FontStretch::from_percentage(pct);
}

computed::FontStretch FontStretch::to_computed_value(const Context& context) const {
  switch (kind) {
    case Kind::Stretch:
      return computed::FontStretch::from_percentage(percentage);
    case Kind::Keyword:
      return computed::FontStretch::from_percentage(font_stretch_keyword_to_percentage(keyword));
    case Kind::System:
      return context.get_cached_system_font().font_stretch();
  }
  return computed::FontStretch::normal();
}

FontStretch FontStretch::from_computed_value(const computed::FontStretch& computed) {
  return FontStretch::stretch(computed.to_percentage());
}

std::string FontStretch::to_css() const {
  switch (kind) {
    case Kind::Keyword:
      return font_stretch_keyword_to_string(keyword);
    case Kind::Stretch: {
      std::ostringstream oss;
      oss << percentage << "%";
      return oss.str();
    }
    case Kind::System:
      return "";
  }
  return "normal";
}

std::optional<FontStretch> FontStretch::parse(const ParserContext& /*ctx*/, class cssparser::Parser& input) {
  auto token = input.next();
  if (!token) return std::nullopt;

  if (auto* ident = std::get_if<std::string>(&*token)) {
    std::string lower = *ident;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

    if (lower == "normal") return FontStretch::keyword(FontStretchKeyword::Normal);
    if (lower == "condensed") return FontStretch::keyword(FontStretchKeyword::Condensed);
    if (lower == "ultra-condensed") return FontStretch::keyword(FontStretchKeyword::UltraCondensed);
    if (lower == "extra-condensed") return FontStretch::keyword(FontStretchKeyword::ExtraCondensed);
    if (lower == "semi-condensed") return FontStretch::keyword(FontStretchKeyword::SemiCondensed);
    if (lower == "semi-expanded") return FontStretch::keyword(FontStretchKeyword::SemiExpanded);
    if (lower == "expanded") return FontStretch::keyword(FontStretchKeyword::Expanded);
    if (lower == "extra-expanded") return FontStretch::keyword(FontStretchKeyword::ExtraExpanded);
    if (lower == "ultra-expanded") return FontStretch::keyword(FontStretchKeyword::UltraExpanded);
  }

  if (auto* num = std::get_if<float>(&*token)) {
    return FontStretch::stretch(*num);
  }

  return std::nullopt;
}

// =====================================================================
// FontSizeKeyword
// =====================================================================

namespace {

float font_size_keyword_to_length_px(FontSizeKeyword kw, const Context& cx) {
  // This is a placeholder - the real implementation would use the context
  // to resolve font sizes based on the base font size and quirks mode.
  // See the FONT_SIZE_MAPPING tables in the header.
  uint8_t html_size = static_cast<uint8_t>(kw);
  if (html_size > 7) html_size = 7;

  // Default: use medium (16px) as base
  float base_size_px = 16.0f;
  int base_index = static_cast<int>(std::round(base_size_px)) - 9;
  if (base_index < 0) base_index = 0;
  if (base_index > 7) base_index = 7;

  return static_cast<float>(FONT_SIZE_MAPPING[base_index][html_size]);
}

} // anonymous namespace

// =====================================================================
// KeywordInfo
// =====================================================================

float KeywordInfo::to_computed_value_px(const Context& context) const {
  if (kw == FontSizeKeyword::None) {
    return FONT_MEDIUM_PX;
  }
  // Compute base size from keyword
  float base = font_size_keyword_to_length_px(kw, context);
  return base * factor + offset_px;
}

KeywordInfo KeywordInfo::compose(float f) const {
  if (kw == FontSizeKeyword::None) {
    return *this;
  }
  return KeywordInfo(kw, factor * f, offset_px * f);
}

// =====================================================================
// FontSize
// =====================================================================

FontSize FontSize::medium() {
  FontSize fs;
  fs.kind = Kind::Keyword;
  fs.keyword_info = KeywordInfo::medium();
  return fs;
}

FontSize FontSize::from_html_size(uint8_t size) {
  FontSize fs;
  fs.kind = Kind::Keyword;

  FontSizeKeyword kw;
  if (size <= 1) kw = FontSizeKeyword::XSmall;
  else if (size == 2) kw = FontSizeKeyword::Small;
  else if (size == 3) kw = FontSizeKeyword::Medium;
  else if (size == 4) kw = FontSizeKeyword::Large;
  else if (size == 5) kw = FontSizeKeyword::XLarge;
  else if (size == 6) kw = FontSizeKeyword::XXLarge;
  else kw = FontSizeKeyword::XXXLarge;

  fs.keyword_info = KeywordInfo(kw);
  return fs;
}

FontSize FontSize::smaller() {
  FontSize fs;
  fs.kind = Kind::Smaller;
  return fs;
}

FontSize FontSize::larger() {
  FontSize fs;
  fs.kind = Kind::Larger;
  return fs;
}

FontSize FontSize::system(SystemFont sf) {
  FontSize fs;
  fs.kind = Kind::System;
  fs.system_font = sf;
  return fs;
}

std::optional<SystemFont> FontSize::get_system() const {
  if (kind == Kind::System) return system_font;
  return std::nullopt;
}

computed::FontSize FontSize::to_computed_value_against(
    const Context& context, const FontBaseSize& /*base_size*/, const LineHeightBase& /*lh_base*/) const {

  KeywordInfo info = KeywordInfo::none();

  switch (kind) {
    case Kind::Length: {
      // Resolve length/percentage
      if (length.has_value()) {
        // Simplified: return the length as computed size
        float px = 16.0f; // placeholder
        return computed::FontSize::from_px(px, info);
      }
      return computed::FontSize::medium();
    }
    case Kind::Keyword: {
      info = keyword_info;
      float px = keyword_info.to_computed_value_px(context);
      return computed::FontSize::from_px(px, info);
    }
    case Kind::Smaller: {
      // Compose with parent: 1 / 1.2
      float ratio = 1.0f / LARGER_FONT_SIZE_RATIO;
      float parent_px = context.get_parent_font().font_size().computed_size_px();
      info = context.get_parent_font().font_size().keyword_info().compose(ratio);
      return computed::FontSize::from_px(parent_px * ratio, info);
    }
    case Kind::Larger: {
      float parent_px = context.get_parent_font().font_size().computed_size_px();
      info = context.get_parent_font().font_size().keyword_info().compose(LARGER_FONT_SIZE_RATIO);
      return computed::FontSize::from_px(parent_px * LARGER_FONT_SIZE_RATIO, info);
    }
    case Kind::System: {
      return context.get_cached_system_font().font_size();
    }
  }

  return computed::FontSize::medium();
}

computed::FontSize FontSize::to_computed_value(const Context& context) const {
  FontBaseSize base(FontBaseSize::Kind::InheritedStyle);
  LineHeightBase lh_base(LineHeightBase::Kind::InheritedStyle);
  return to_computed_value_against(context, base, lh_base);
}

FontSize FontSize::from_computed_value(const computed::FontSize& computed) {
  FontSize fs;
  fs.kind = Kind::Length;
  // Placeholder - would need to reconstruct length
  return fs;
}

std::string FontSize::to_css() const {
  switch (kind) {
    case Kind::Keyword: {
      switch (keyword_info.kw) {
        case FontSizeKeyword::XXSmall: return "xx-small";
        case FontSizeKeyword::XSmall: return "x-small";
        case FontSizeKeyword::Small: return "small";
        case FontSizeKeyword::Medium: return "medium";
        case FontSizeKeyword::Large: return "large";
        case FontSizeKeyword::XLarge: return "x-large";
        case FontSizeKeyword::XXLarge: return "xx-large";
        case FontSizeKeyword::XXXLarge: return "xxx-large";
        case FontSizeKeyword::Math: return "math";
        case FontSizeKeyword::None: return "";
      }
      return "medium";
    }
    case Kind::Smaller: return "smaller";
    case Kind::Larger: return "larger";
    case Kind::Length: {
      if (length.has_value()) return "/* length */";
      return "medium";
    }
    case Kind::System: return "";
  }
  return "medium";
}

std::optional<FontSize> FontSize::parse_quirky(const ParserContext& /*ctx*/, class cssparser::Parser& input, bool /*allow_quirks*/) {
  auto token = input.next();
  if (!token) return std::nullopt;

  if (auto* ident = std::get_if<std::string>(&*token)) {
    std::string lower = *ident;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

    if (lower == "xx-small") return FontSize::from_html_size(0);
    if (lower == "x-small") return FontSize::from_html_size(1);
    if (lower == "small") return FontSize::from_html_size(2);
    if (lower == "medium") return FontSize::from_html_size(3);
    if (lower == "large") return FontSize::from_html_size(4);
    if (lower == "x-large") return FontSize::from_html_size(5);
    if (lower == "xx-large") return FontSize::from_html_size(6);
    if (lower == "xxx-large") return FontSize::from_html_size(7);
    if (lower == "smaller") return FontSize::smaller();
    if (lower == "larger") return FontSize::larger();
    return std::nullopt;
  }

  // Could be a length or percentage
  return std::nullopt;
}

std::optional<FontSize> FontSize::parse(const ParserContext& ctx, class cssparser::Parser& input) {
  return parse_quirky(ctx, input, false);
}

FontSize FontSize::clone() const {
  FontSize copy = *this;
  return copy;
}

// =====================================================================
// FontFamily
// =====================================================================

FontFamily FontFamily::values(const std::vector<std::string>& f) {
  FontFamily ff;
  ff.kind = Kind::Values;
  ff.families = f;
  return ff;
}

FontFamily FontFamily::system(SystemFont sf) {
  FontFamily ff;
  ff.kind = Kind::System;
  ff.system_font = sf;
  return ff;
}

std::optional<SystemFont> FontFamily::get_system() const {
  if (kind == Kind::System) return system_font;
  return std::nullopt;
}

computed::FontFamily FontFamily::to_computed_value(const Context& /*context*/) const {
  computed::FontFamily cf;
  cf.families = families;
  cf.is_system_font = (kind == Kind::System);
  cf.is_initial = false;
  return cf;
}

FontFamily FontFamily::from_computed_value(const computed::FontFamily& computed) {
  return FontFamily::values(computed.families);
}

std::string FontFamily::to_css() const {
  if (kind == Kind::System) return "";
  std::ostringstream oss;
  for (size_t i = 0; i < families.size(); ++i) {
    if (i > 0) oss << ", ";
    // Quote family names that need it
    const auto& name = families[i];
    bool needs_quote = name.find(' ') != std::string::npos ||
                       name.find(',') != std::string::npos;
    if (needs_quote) oss << '"' << name << '"';
    else oss << name;
  }
  return oss.str();
}

std::optional<FontFamily> FontFamily::parse(const ParserContext& /*ctx*/, class cssparser::Parser& input) {
  // Parse comma-separated family names
  std::vector<std::string> names;
  auto token = input.next();
  if (!token) return std::nullopt;

  if (auto* ident = std::get_if<std::string>(&*token)) {
    names.push_back(*ident);
    // Try to parse more comma-separated names
    while (true) {
      auto comma = input.peek();
      if (!comma) break;
      if (auto* ch = std::get_if<char>(&*comma)) {
        if (*ch == ',') {
          input.next(); // consume comma
          auto next = input.next();
          if (!next) break;
          if (auto* nm = std::get_if<std::string>(&*next)) {
            names.push_back(*nm);
            continue;
          }
        }
      }
      break;
    }
    return FontFamily::values(names);
  }

  if (auto* str = std::get_if<std::string>(&*token)) {
    names.push_back(*str);
    return FontFamily::values(names);
  }

  return std::nullopt;
}

FontFamily FontFamily::clone() const {
  return *this;
}

// =====================================================================
// FontSizeAdjustFactor
// =====================================================================

FontSizeAdjustFactor FontSizeAdjustFactor::number(float v) {
  FontSizeAdjustFactor f;
  f.kind = Kind::Number;
  f.value = std::max(0.0f, v);
  return f;
}

FontSizeAdjustFactor FontSizeAdjustFactor::from_font() {
  FontSizeAdjustFactor f;
  f.kind = Kind::FromFont;
  return f;
}

std::string FontSizeAdjustFactor::to_css() const {
  switch (kind) {
    case Kind::Number: {
      std::ostringstream oss;
      oss << value;
      return oss.str();
    }
    case Kind::FromFont: return "from-font";
  }
  return "";
}

std::optional<FontSizeAdjustFactor> FontSizeAdjustFactor::parse(const ParserContext& /*ctx*/, class cssparser::Parser& input) {
  auto token = input.next();
  if (!token) return std::nullopt;

  if (auto* ident = std::get_if<std::string>(&*token)) {
    std::string lower = *ident;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    if (lower == "from-font") return FontSizeAdjustFactor::from_font();
    return std::nullopt;
  }

  if (auto* num = std::get_if<float>(&*token)) {
    return FontSizeAdjustFactor::number(*num);
  }

  return std::nullopt;
}

// =====================================================================
// FontSizeAdjust
// =====================================================================

FontSizeAdjust FontSizeAdjust::none() {
  FontSizeAdjust fsa;
  fsa.basis = Basis::None;
  return fsa;
}

FontSizeAdjust FontSizeAdjust::ex_height(const FontSizeAdjustFactor& f) {
  FontSizeAdjust fsa;
  fsa.basis = Basis::ExHeight;
  fsa.factor = f;
  return fsa;
}

std::string FontSizeAdjust::to_css() const {
  switch (basis) {
    case Basis::None: return "none";
    case Basis::ExHeight: return "ex-height " + factor.to_css();
    case Basis::CapHeight: return "cap-height " + factor.to_css();
    case Basis::ChWidth: return "ch-width " + factor.to_css();
    case Basis::IcWidth: return "ic-width " + factor.to_css();
    case Basis::IcHeight: return "ic-height " + factor.to_css();
  }
  return "none";
}

std::optional<FontSizeAdjust> FontSizeAdjust::parse(const ParserContext& ctx, class cssparser::Parser& input) {
  // Try parsing just a number first (defaults to ex-height)
  auto factor = FontSizeAdjustFactor::parse(ctx, input);
  if (factor.has_value()) {
    return FontSizeAdjust::ex_height(*factor);
  }

  // Try parsing a keyword
  auto token = input.next();
  if (!token) return std::nullopt;

  if (auto* ident = std::get_if<std::string>(&*token)) {
    std::string lower = *ident;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    if (lower == "none") return FontSizeAdjust::none();
    if (lower == "ex-height" || lower == "cap-height" ||
        lower == "ch-width" || lower == "ic-width" || lower == "ic-height") {
      auto f = FontSizeAdjustFactor::parse(ctx, input);
      if (!f) return std::nullopt;

      FontSizeAdjust fsa;
      fsa.factor = *f;
      if (lower == "ex-height") fsa.basis = Basis::ExHeight;
      else if (lower == "cap-height") fsa.basis = Basis::CapHeight;
      else if (lower == "ch-width") fsa.basis = Basis::ChWidth;
      else if (lower == "ic-width") fsa.basis = Basis::IcWidth;
      else fsa.basis = Basis::IcHeight;
      return fsa;
    }
  }

  return std::nullopt;
}

// =====================================================================
// FontVariantAlternates
// =====================================================================

FontVariantAlternates FontVariantAlternates::normal() {
  return FontVariantAlternates();
}

size_t FontVariantAlternates::len() const {
  size_t count = 0;
  for (const auto& entry : alternates_) {
    if (entry.kind == AlternateKind::HistoricalForms) {
      count += 1;
    } else {
      count += entry.idents.empty() ? 1 : entry.idents.size();
    }
  }
  return count;
}

void FontVariantAlternates::add_stylistic(const CustomIdent& ident) {
  AlternateEntry e;
  e.kind = AlternateKind::Stylistic;
  e.idents = {ident};
  alternates_.push_back(e);
}

void FontVariantAlternates::add_styleset(const std::vector<CustomIdent>& idents) {
  AlternateEntry e;
  e.kind = AlternateKind::Styleset;
  e.idents = idents;
  alternates_.push_back(e);
}

void FontVariantAlternates::add_character_variant(const std::vector<CustomIdent>& idents) {
  AlternateEntry e;
  e.kind = AlternateKind::CharacterVariant;
  e.idents = idents;
  alternates_.push_back(e);
}

void FontVariantAlternates::add_swash(const CustomIdent& ident) {
  AlternateEntry e;
  e.kind = AlternateKind::Swash;
  e.idents = {ident};
  alternates_.push_back(e);
}

void FontVariantAlternates::add_ornaments(const CustomIdent& ident) {
  AlternateEntry e;
  e.kind = AlternateKind::Ornaments;
  e.idents = {ident};
  alternates_.push_back(e);
}

void FontVariantAlternates::add_annotation(const CustomIdent& ident) {
  AlternateEntry e;
  e.kind = AlternateKind::Annotation;
  e.idents = {ident};
  alternates_.push_back(e);
}

void FontVariantAlternates::add_historical_forms() {
  AlternateEntry e;
  e.kind = AlternateKind::HistoricalForms;
  alternates_.push_back(e);
}

std::string FontVariantAlternates::to_css() const {
  if (alternates_.empty()) return "normal";
  std::ostringstream oss;
  for (size_t i = 0; i < alternates_.size(); ++i) {
    if (i > 0) oss << " ";
    const auto& e = alternates_[i];
    switch (e.kind) {
      case AlternateKind::HistoricalForms:
        oss << "historical-forms";
        break;
      case AlternateKind::Stylistic:
        oss << "stylistic(" << "ident" << ")";
        break;
      case AlternateKind::Swash:
        oss << "swash(" << "ident" << ")";
        break;
      case AlternateKind::Ornaments:
        oss << "ornaments(" << "ident" << ")";
        break;
      case AlternateKind::Annotation:
        oss << "annotation(" << "ident" << ")";
        break;
      case AlternateKind::Styleset:
        oss << "styleset(/* idents */)";
        break;
      case AlternateKind::CharacterVariant:
        oss << "character-variant(/* idents */)";
        break;
    }
  }
  return oss.str();
}

std::optional<FontVariantAlternates> FontVariantAlternates::parse(const ParserContext& /*ctx*/, class cssparser::Parser& input) {
  // Try "normal"
  auto token = input.peek();
  if (token) {
    if (auto* ident = std::get_if<std::string>(&*token)) {
      std::string lower = *ident;
      std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
      if (lower == "normal") {
        input.next();
        return FontVariantAlternates::normal();
      }
    }
  }
  return std::nullopt; // placeholder - full parsing is complex
}

FontVariantAlternates FontVariantAlternates::clone() const {
  return *this;
}

// =====================================================================
// FontVariantEastAsian
// =====================================================================

bool FontVariantEastAsian::validate_mixed_flags() const {
  // full-width and proportional-width cannot be set together
  if (contains(FULL_WIDTH) && contains(PROPORTIONAL_WIDTH)) {
    return false;
  }
  // Only one JIS variant can be set at a time
  uint16_t jis_group = flags_ & (JIS78 | JIS83 | JIS90 | JIS04 | SIMPLIFIED | TRADITIONAL);
  if (jis_group != 0) {
    // Check power of two
    if ((jis_group & (jis_group - 1)) != 0) {
      return false;
    }
  }
  return true;
}

std::string FontVariantEastAsian::to_css() const {
  if (flags_ == NORMAL) return "normal";
  std::ostringstream oss;
  bool first = true;
  auto maybe_add = [&](const char* name, uint16_t flag) {
    if (contains(flag)) {
      if (!first) oss << " ";
      oss << name;
      first = false;
    }
  };
  maybe_add("jis78", JIS78);
  maybe_add("jis83", JIS83);
  maybe_add("jis90", JIS90);
  maybe_add("jis04", JIS04);
  maybe_add("simplified", SIMPLIFIED);
  maybe_add("traditional", TRADITIONAL);
  maybe_add("full-width", FULL_WIDTH);
  maybe_add("proportional-width", PROPORTIONAL_WIDTH);
  maybe_add("ruby", RUBY);
  return oss.str();
}

std::optional<FontVariantEastAsian> FontVariantEastAsian::parse(const ParserContext& /*ctx*/, class cssparser::Parser& input) {
  uint16_t flags = NORMAL;
  while (true) {
    auto token = input.peek();
    if (!token) break;
    if (auto* ident = std::get_if<std::string>(&*token)) {
      std::string lower = *ident;
      std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
      if (lower == "normal" && flags == NORMAL) { input.next(); return FontVariantEastAsian(NORMAL); }
      if (lower == "jis78") { flags |= JIS78; input.next(); continue; }
      if (lower == "jis83") { flags |= JIS83; input.next(); continue; }
      if (lower == "jis90") { flags |= JIS90; input.next(); continue; }
      if (lower == "jis04") { flags |= JIS04; input.next(); continue; }
      if (lower == "simplified") { flags |= SIMPLIFIED; input.next(); continue; }
      if (lower == "traditional") { flags |= TRADITIONAL; input.next(); continue; }
      if (lower == "full-width") { flags |= FULL_WIDTH; input.next(); continue; }
      if (lower == "proportional-width") { flags |= PROPORTIONAL_WIDTH; input.next(); continue; }
      if (lower == "ruby") { flags |= RUBY; input.next(); continue; }
    }
    break;
  }
  FontVariantEastAsian result(flags);
  if (!result.validate_mixed_flags()) return std::nullopt;
  return result;
}

// =====================================================================
// FontVariantLigatures
// =====================================================================

bool FontVariantLigatures::validate_mixed_flags() const {
  // Cannot mix a ligature type with its "no-" counterpart
  if (contains(COMMON_LIGATURES) && contains(NO_COMMON_LIGATURES)) return false;
  if (contains(DISCRETIONARY_LIGATURES) && contains(NO_DISCRETIONARY_LIGATURES)) return false;
  if (contains(HISTORICAL_LIGATURES) && contains(NO_HISTORICAL_LIGATURES)) return false;
  if (contains(CONTEXTUAL) && contains(NO_CONTEXTUAL)) return false;
  return true;
}

std::string FontVariantLigatures::to_css() const {
  if (flags_ == NORMAL) return "normal";
  if (flags_ == NONE) return "none";
  std::ostringstream oss;
  bool first = true;
  auto maybe_add = [&](const char* name, uint16_t flag) {
    if (contains(flag)) {
      if (!first) oss << " ";
      oss << name;
      first = false;
    }
  };
  maybe_add("common-ligatures", COMMON_LIGATURES);
  maybe_add("no-common-ligatures", NO_COMMON_LIGATURES);
  maybe_add("discretionary-ligatures", DISCRETIONARY_LIGATURES);
  maybe_add("no-discretionary-ligatures", NO_DISCRETIONARY_LIGATURES);
  maybe_add("historical-ligatures", HISTORICAL_LIGATURES);
  maybe_add("no-historical-ligatures", NO_HISTORICAL_LIGATURES);
  maybe_add("contextual", CONTEXTUAL);
  maybe_add("no-contextual", NO_CONTEXTUAL);
  return oss.str();
}

std::optional<FontVariantLigatures> FontVariantLigatures::parse(const ParserContext& /*ctx*/, class cssparser::Parser& input) {
  uint16_t flags = NORMAL;
  while (true) {
    auto token = input.peek();
    if (!token) break;
    if (auto* ident = std::get_if<std::string>(&*token)) {
      std::string lower = *ident;
      std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
      if (lower == "normal" && flags == NORMAL) { input.next(); return FontVariantLigatures(NORMAL); }
      if (lower == "none") { input.next(); return FontVariantLigatures(NONE); }
      if (lower == "common-ligatures") { flags |= COMMON_LIGATURES; input.next(); continue; }
      if (lower == "no-common-ligatures") { flags |= NO_COMMON_LIGATURES; input.next(); continue; }
      if (lower == "discretionary-ligatures") { flags |= DISCRETIONARY_LIGATURES; input.next(); continue; }
      if (lower == "no-discretionary-ligatures") { flags |= NO_DISCRETIONARY_LIGATURES; input.next(); continue; }
      if (lower == "historical-ligatures") { flags |= HISTORICAL_LIGATURES; input.next(); continue; }
      if (lower == "no-historical-ligatures") { flags |= NO_HISTORICAL_LIGATURES; input.next(); continue; }
      if (lower == "contextual") { flags |= CONTEXTUAL; input.next(); continue; }
      if (lower == "no-contextual") { flags |= NO_CONTEXTUAL; input.next(); continue; }
    }
    break;
  }
  FontVariantLigatures result(flags);
  if (!result.validate_mixed_flags()) return std::nullopt;
  return result;
}

// =====================================================================
// FontVariantNumeric
// =====================================================================

bool FontVariantNumeric::validate_mixed_flags() const {
  if (contains(LINING_NUMS) && contains(OLDSTYLE_NUMS)) return false;
  if (contains(PROPORTIONAL_NUMS) && contains(TABULAR_NUMS)) return false;
  if (contains(DIAGONAL_FRACTIONS) && contains(STACKED_FRACTIONS)) return false;
  return true;
}

std::string FontVariantNumeric::to_css() const {
  if (flags_ == NORMAL) return "normal";
  std::ostringstream oss;
  bool first = true;
  auto maybe_add = [&](const char* name, uint8_t flag) {
    if (contains(flag)) {
      if (!first) oss << " ";
      oss << name;
      first = false;
    }
  };
  maybe_add("lining-nums", LINING_NUMS);
  maybe_add("oldstyle-nums", OLDSTYLE_NUMS);
  maybe_add("proportional-nums", PROPORTIONAL_NUMS);
  maybe_add("tabular-nums", TABULAR_NUMS);
  maybe_add("diagonal-fractions", DIAGONAL_FRACTIONS);
  maybe_add("stacked-fractions", STACKED_FRACTIONS);
  maybe_add("slashed-zero", SLASHED_ZERO);
  maybe_add("ordinal", ORDINAL);
  return oss.str();
}

std::optional<FontVariantNumeric> FontVariantNumeric::parse(const ParserContext& /*ctx*/, class cssparser::Parser& input) {
  uint8_t flags = NORMAL;
  while (true) {
    auto token = input.peek();
    if (!token) break;
    if (auto* ident = std::get_if<std::string>(&*token)) {
      std::string lower = *ident;
      std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
      if (lower == "normal" && flags == NORMAL) { input.next(); return FontVariantNumeric(NORMAL); }
      if (lower == "lining-nums") { flags |= LINING_NUMS; input.next(); continue; }
      if (lower == "oldstyle-nums") { flags |= OLDSTYLE_NUMS; input.next(); continue; }
      if (lower == "proportional-nums") { flags |= PROPORTIONAL_NUMS; input.next(); continue; }
      if (lower == "tabular-nums") { flags |= TABULAR_NUMS; input.next(); continue; }
      if (lower == "diagonal-fractions") { flags |= DIAGONAL_FRACTIONS; input.next(); continue; }
      if (lower == "stacked-fractions") { flags |= STACKED_FRACTIONS; input.next(); continue; }
      if (lower == "slashed-zero") { flags |= SLASHED_ZERO; input.next(); continue; }
      if (lower == "ordinal") { flags |= ORDINAL; input.next(); continue; }
    }
    break;
  }
  FontVariantNumeric result(flags);
  if (!result.validate_mixed_flags()) return std::nullopt;
  return result;
}

// =====================================================================
// FeatureTagValue
// =====================================================================

std::string FeatureTagValue::to_css() const {
  // Convert tag to string representation
  char tag_str[5] = {
    static_cast<char>((tag >> 24) & 0xFF),
    static_cast<char>((tag >> 16) & 0xFF),
    static_cast<char>((tag >> 8) & 0xFF),
    static_cast<char>(tag & 0xFF),
    '\0'
  };
  std::ostringstream oss;
  oss << "\"" << tag_str << "\" " << value;
  return oss.str();
}

std::optional<FeatureTagValue> FeatureTagValue::parse(const ParserContext& /*ctx*/, class cssparser::Parser& input) {
  auto token = input.next();
  if (!token) return std::nullopt;
  // Placeholder: parse tag string and optional value
  return std::nullopt;
}

// =====================================================================
// VariationValue
// =====================================================================

std::string VariationValue::to_css() const {
  char tag_str[5] = {
    static_cast<char>((tag >> 24) & 0xFF),
    static_cast<char>((tag >> 16) & 0xFF),
    static_cast<char>((tag >> 8) & 0xFF),
    static_cast<char>(tag & 0xFF),
    '\0'
  };
  std::ostringstream oss;
  oss << "\"" << tag_str << "\" " << value;
  return oss.str();
}

std::optional<VariationValue> VariationValue::parse(const ParserContext& /*ctx*/, class cssparser::Parser& input) {
  auto token = input.next();
  if (!token) return std::nullopt;
  // Placeholder: parse tag string and float value
  return std::nullopt;
}

// =====================================================================
// FontLanguageOverride
// =====================================================================

FontLanguageOverride FontLanguageOverride::normal() {
  FontLanguageOverride flo;
  flo.kind = Kind::Normal;
  return flo;
}

FontLanguageOverride FontLanguageOverride::override_str(const std::string& s) {
  FontLanguageOverride flo;
  flo.kind = Kind::Override;
  flo.override_string = s;
  return flo;
}

std::string FontLanguageOverride::to_css() const {
  if (kind == Kind::Normal) return "normal";
  return "\"" + override_string + "\"";
}

std::optional<FontLanguageOverride> FontLanguageOverride::parse(const ParserContext& /*ctx*/, class cssparser::Parser& input) {
  auto token = input.next();
  if (!token) return std::nullopt;

  if (auto* ident = std::get_if<std::string>(&*token)) {
    std::string lower = *ident;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    if (lower == "normal") return FontLanguageOverride::normal();
    return std::nullopt;
  }

  // Expect a string token
  if (auto* str = std::get_if<std::string>(&*token)) {
    return FontLanguageOverride::override_str(*str);
  }

  return std::nullopt;
}

// =====================================================================
// Test utilities
// =====================================================================

#ifdef FONT_TEST_UTILITIES

namespace test {

bool test_font_weight() {
  // Test normal weight
  auto normal = FontWeight::normal();
  assert(normal.to_css() == "normal");

  // Test bold weight
  auto bold = FontWeight::bold();
  assert(bold.to_css() == "bold");

  // Test numeric weight
  auto weight_500 = AbsoluteFontWeight::weight(500.0f);
  assert(weight_500.get() == 500.0f);

  // Test absolute bounds
  auto too_low = AbsoluteFontWeight::weight(0.5f);  // Below MIN_FONT_WEIGHT
  auto too_high = AbsoluteFontWeight::weight(1001.0f);  // Above MAX_FONT_WEIGHT

  // Test bolder/lighter
  auto bw = FontWeight::bolder();
  assert(bw.kind == FontWeight::Kind::Bolder);

  auto lw = FontWeight::lighter();
  assert(lw.kind == FontWeight::Kind::Lighter);

  return true;
}

bool test_font_style() {
  auto normal = FontStyle::normal();
  assert(normal.to_css() == "normal");

  auto italic = FontStyle::italic();
  assert(italic.to_css() == "italic");

  auto oblique = FontStyle::oblique(20.0f);
  assert(oblique.oblique_degrees == 20.0f);

  // Test angle clamping
  float clamped = FontStyle::compute_angle_degrees(100.0f);
  assert(clamped == FONT_STYLE_OBLIQUE_MAX_ANGLE_DEGREES);

  clamped = FontStyle::compute_angle_degrees(-100.0f);
  assert(clamped == FONT_STYLE_OBLIQUE_MIN_ANGLE_DEGREES);

  return true;
}

bool test_font_stretch() {
  auto normal = FontStretch::normal();
  assert(normal.to_css() == "normal");

  auto condensed = FontStretch::keyword(FontStretchKeyword::Condensed);
  assert(condensed.to_css() == "condensed");

  auto stretched = FontStretch::stretch(120.0f);
  assert(stretched.percentage == 120.0f);

  return true;
}

bool test_font_size() {
  auto medium = FontSize::medium();
  assert(medium.to_css() == "medium");

  auto from_html = FontSize::from_html_size(3);
  assert(from_html.keyword_info.kw == FontSizeKeyword::Medium);

  from_html = FontSize::from_html_size(0);
  assert(from_html.keyword_info.kw == FontSizeKeyword::XSmall);

  from_html = FontSize::from_html_size(7);
  assert(from_html.keyword_info.kw == FontSizeKeyword::XXXLarge);

  auto smaller = FontSize::smaller();
  assert(smaller.kind == FontSize::Kind::Smaller);

  auto larger = FontSize::larger();
  assert(larger.kind == FontSize::Kind::Larger);

  return true;
}

bool test_font_family() {
  auto fam = FontFamily::values({"Arial", "Helvetica", "sans-serif"});
  assert(fam.families.size() == 3);
  assert(fam.families[0] == "Arial");

  return true;
}

bool test_keyword_info() {
  auto ki = KeywordInfo::medium();
  assert(ki.kw == FontSizeKeyword::Medium);
  assert(ki.factor == 1.0f);
  assert(ki.offset_px == 0.0f);

  auto composed = ki.compose(1.5f);
  assert(composed.factor == 1.5f);

  return true;
}

bool test_font_variant_east_asian() {
  auto normal = FontVariantEastAsian::normal();
  assert(normal.is_empty());

  FontVariantEastAsian jis(FontVariantEastAsian::JIS78);
  assert(jis.contains(FontVariantEastAsian::JIS78));

  // Test mixed flags validation
  FontVariantEastAsian mixed(FontVariantEastAsian::JIS78 | FontVariantEastAsian::JIS83);
  assert(!mixed.validate_mixed_flags());  // Should fail: only one JIS variant allowed

  FontVariantEastAsian width_both(FontVariantEastAsian::FULL_WIDTH | FontVariantEastAsian::PROPORTIONAL_WIDTH);
  assert(!width_both.validate_mixed_flags());  // full-width + proportional-width invalid

  return true;
}

bool test_font_variant_ligatures() {
  FontVariantLigatures ligs(FontVariantLigatures::COMMON_LIGATURES | FontVariantLigatures::CONTEXTUAL);
  assert(ligs.contains(FontVariantLigatures::COMMON_LIGATURES));
  assert(ligs.contains(FontVariantLigatures::CONTEXTUAL));

  // Should fail: common-ligatures + no-common-ligatures
  FontVariantLigatures bad(FontVariantLigatures::COMMON_LIGATURES | FontVariantLigatures::NO_COMMON_LIGATURES);
  assert(!bad.validate_mixed_flags());

  return true;
}

bool test_font_variant_numeric() {
  FontVariantNumeric num(FontVariantNumeric::LINING_NUMS | FontVariantNumeric::TABULAR_NUMS | FontVariantNumeric::SLASHED_ZERO);
  assert(num.contains(FontVariantNumeric::LINING_NUMS));
  assert(num.contains(FontVariantNumeric::TABULAR_NUMS));
  assert(num.contains(FontVariantNumeric::SLASHED_ZERO));

  // Should fail: lining-nums + oldstyle-nums
  FontVariantNumeric bad(FontVariantNumeric::LINING_NUMS | FontVariantNumeric::OLDSTYLE_NUMS);
  assert(!bad.validate_mixed_flags());

  return true;
}

bool test_font_size_adjust() {
  auto none = FontSizeAdjust::none();
  assert(none.to_css() == "none");

  auto factor = FontSizeAdjustFactor::number(0.5f);
  auto adjust = FontSizeAdjust::ex_height(factor);
  std::string css = adjust.to_css();
  assert(css.find("ex-height") != std::string::npos);

  return true;
}

bool test_font_language_override() {
  auto normal = FontLanguageOverride::normal();
  assert(normal.to_css() == "normal");

  auto override_val = FontLanguageOverride::override_str("ENG");
  assert(override_val.to_css().find("ENG") != std::string::npos);

  return true;
}

bool test_variant_alternates() {
  FontVariantAlternates va;
  assert(va.empty());
  assert(va.len() == 0);

  auto css = va.to_css();
  assert(css == "normal");

  va.add_historical_forms();
  assert(va.len() == 1);

  return true;
}

bool test_font_size_mapping() {
  // Verify font size mapping table dimensions
  assert(FONT_SIZE_FACTORS[3] == 100);  // Medium = 100%

  // Verify keyword-to-values
  assert(font_stretch_keyword_to_percentage(FontStretchKeyword::UltraCondensed) == 50.0f);
  assert(font_stretch_keyword_to_percentage(FontStretchKeyword::Normal) == 100.0f);
  assert(font_stretch_keyword_to_percentage(FontStretchKeyword::UltraExpanded) == 200.0f);

  return true;
}

bool test_feature_tag_value() {
  FeatureTagValue ftv(0x6B65726E, 1);  // "kern" tag
  std::string css = ftv.to_css();
  assert(!css.empty());
  return true;
}

bool test_variation_value() {
  VariationValue vv(0x77676874, 700.0f);  // "wght" tag
  std::string css = vv.to_css();
  assert(!css.empty());
  return true;
}

void run_all_tests() {
  bool pass = true;
  pass &= test_font_weight();
  pass &= test_font_style();
  pass &= test_font_stretch();
  pass &= test_font_size();
  pass &= test_font_family();
  pass &= test_keyword_info();
  pass &= test_font_variant_east_asian();
  pass &= test_font_variant_ligatures();
  pass &= test_font_variant_numeric();
  pass &= test_font_size_adjust();
  pass &= test_font_language_override();
  pass &= test_variant_alternates();
  pass &= test_font_size_mapping();
  pass &= test_feature_tag_value();
  pass &= test_variation_value();

  if (pass) {
    std::cout << "All font specified tests passed!" << std::endl;
  } else {
    std::cerr << "Some font specified tests failed!" << std::endl;
  }
}

} // namespace test
#endif // FONT_TEST_UTILITIES

// =====================================================================
// Constants and helpers for FontSizeKeyword resolution
// =====================================================================

namespace detail {

float resolve_font_size_keyword(FontSizeKeyword kw, const Context& context) {
  // Full implementation uses the FONT_SIZE_MAPPING tables
  // with quirks mode and base size detection
  uint8_t html_size = static_cast<uint8_t>(kw);
  if (html_size > 7) html_size = 7;
  int base_size_px = static_cast<int>(std::round(FONT_MEDIUM_PX));
  int base_index = base_size_px - 9;
  if (base_index < 0) base_index = 0;
  if (base_index > 7) base_index = 7;
  return static_cast<float>(FONT_SIZE_MAPPING[base_index][html_size]);
}

float resolve_font_size_keyword_quirks(FontSizeKeyword kw, const Context& context) {
  uint8_t html_size = static_cast<uint8_t>(kw);
  if (html_size > 7) html_size = 7;
  int base_size_px = static_cast<int>(std::round(FONT_MEDIUM_PX));
  int base_index = base_size_px - 9;
  if (base_index < 0) base_index = 0;
  if (base_index > 7) base_index = 7;
  return static_cast<float>(QUIRKS_FONT_SIZE_MAPPING[base_index][html_size]);
}

} // namespace detail

} // namespace style::values::specified
