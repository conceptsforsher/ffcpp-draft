#pragma once
// SPDX-License-Identifier: MPL-2.0
// Translated from servo/components/style/values/specified/font.rs

#include <string>
#include <variant>
#include <optional>
#include <vector>
#include <memory>
#include <cstdint>
#include <cmath>
#include <algorithm>
#include <sstream>

namespace style::values {

// Forward declarations
struct CSSPixelLength;
struct Context;
struct LengthPercentage;
struct Angle;
struct Number;
struct NonNegativeNumber;
struct NonNegativePercentage;
struct CustomIdent;

namespace computed {
  struct FontWeight;
  struct FontStyle;
  struct FontStretch;
  struct FontSize;
  struct FontFamily;
  struct FontLanguageOverride;
}

namespace specified {

// SystemFont enum - represents system font values
enum class SystemFont : uint8_t {
  Caption = 0,
  Icon,
  Menu,
  MessageBox,
  SmallCaption,
  StatusBar,
  MozPullDownMenu,
  MozButton,
  MozList,
  MozField,
  End  // For indexing purposes only
};

/// Minimum font-weight value: https://drafts.csswg.org/css-fonts-4/#font-weight-numeric-values
constexpr float MIN_FONT_WEIGHT = 1.0f;
/// Maximum font-weight value: https://drafts.csswg.org/css-fonts-4/#font-weight-numeric-values
constexpr float MAX_FONT_WEIGHT = 1000.0f;
/// Default font size in pixels
constexpr float FONT_MEDIUM_PX = 16.0f;
/// Default line height in pixels
constexpr float FONT_MEDIUM_LINE_HEIGHT_PX = FONT_MEDIUM_PX * 1.2f;
/// Default script minimum size in points
constexpr uint32_t DEFAULT_SCRIPT_MIN_SIZE_PT = 8;
/// Default script size multiplier
constexpr double DEFAULT_SCRIPT_SIZE_MULTIPLIER = 0.71;
/// Larger font size ratio
constexpr float LARGER_FONT_SIZE_RATIO = 1.2f;
/// Maximum oblique angle in degrees
constexpr float FONT_STYLE_OBLIQUE_MAX_ANGLE_DEGREES = 90.0f;
/// Minimum oblique angle in degrees
constexpr float FONT_STYLE_OBLIQUE_MIN_ANGLE_DEGREES = -90.0f;

// Font size keyword sizing tables
// Mapping from base size and HTML size to pixels
// First index: (base_size - 9), second: HTML size
constexpr int32_t FONT_SIZE_MAPPING[8][8] = {
  {9, 9, 9, 9, 11, 14, 18, 27},
  {9, 9, 9, 10, 12, 15, 20, 30},
  {9, 9, 10, 11, 13, 17, 22, 33},
  {9, 9, 10, 12, 14, 18, 24, 36},
  {9, 10, 12, 13, 16, 20, 26, 39},
  {9, 10, 12, 14, 17, 21, 28, 42},
  {9, 10, 13, 15, 18, 23, 30, 45},
  {9, 10, 13, 16, 18, 24, 32, 48},
};

// Quirks mode font size mapping table
constexpr int32_t QUIRKS_FONT_SIZE_MAPPING[8][8] = {
  {9, 9, 9, 9, 11, 14, 18, 28},
  {9, 9, 9, 10, 12, 15, 20, 31},
  {9, 9, 9, 11, 13, 17, 22, 34},
  {9, 9, 10, 12, 14, 18, 24, 37},
  {9, 9, 10, 13, 16, 20, 26, 40},
  {9, 9, 11, 14, 17, 21, 28, 42},
  {9, 10, 12, 15, 17, 23, 30, 45},
  {9, 10, 13, 16, 18, 24, 32, 48},
};

// Font size factors per HTML size index
constexpr int32_t FONT_SIZE_FACTORS[8] = {60, 75, 89, 100, 120, 150, 200, 300};

/// AbsoluteFontWeight - an absolute font-weight value for @font-face rules
/// https://drafts.csswg.org/css-fonts-4/#font-weight-absolute-values
struct AbsoluteFontWeight {
  enum class Kind { Normal, Bold, Weight };
  Kind kind = Kind::Normal;
  float weight_value = 400.0f;

  AbsoluteFontWeight() = default;
  static AbsoluteFontWeight normal() { AbsoluteFontWeight w; w.kind = Kind::Normal; return w; }
  static AbsoluteFontWeight bold() { AbsoluteFontWeight w; w.kind = Kind::Bold; return w; }
  static AbsoluteFontWeight weight(float v) { AbsoluteFontWeight w; w.kind = Kind::Weight; w.weight_value = v; return w; }

  float get() const { return (kind == Kind::Weight) ? weight_value : (kind == Kind::Bold ? 700.0f : 400.0f); }

  /// Compute the computed font weight value
  computed::FontWeight compute() const;

  /// CSS serialization
  std::string to_css() const;

  /// Parse from CSS

  AbsoluteFontWeight clone() const { return *this; }
};

/// FontWeight - specified font-weight value
/// https://drafts.csswg.org/css-fonts-4/#propdef-font-weight
struct FontWeight {
  enum class Kind { Absolute, Bolder, Lighter, System };
  Kind kind = Kind::Absolute;
  AbsoluteFontWeight absolute;
  SystemFont system_font = SystemFont::End;

  FontWeight() : absolute(AbsoluteFontWeight::normal()) {}
  static FontWeight normal() { return FontWeight(); }
  static FontWeight bold() { FontWeight w; w.absolute = AbsoluteFontWeight::bold(); return w; }
  static FontWeight bolder() { FontWeight w; w.kind = Kind::Bolder; return w; }
  static FontWeight lighter() { FontWeight w; w.kind = Kind::Lighter; return w; }
  static FontWeight system(SystemFont sf) { FontWeight w; w.kind = Kind::System; w.system_font = sf; return w; }
  static FontWeight from_gecko_keyword(uint32_t kw);

  /// Get system font if this is a system value
  std::optional<SystemFont> get_system() const;

  /// Convert to computed value
  computed::FontWeight to_computed_value(const Context& context) const;

  /// Create from computed value
  static FontWeight from_computed_value(const computed::FontWeight& computed);

  /// CSS serialization
  std::string to_css() const;

  /// Parse from CSS

  FontWeight clone() const { return *this; }
};

/// FontStyle - specified font-style property value
struct FontStyle {
  enum class Kind { Normal, Italic, Oblique, System };
  Kind kind = Kind::Normal;
  float oblique_degrees = 14.0f;  // Default oblique angle
  SystemFont system_font = SystemFont::End;

  FontStyle() = default;
  static FontStyle normal() { return FontStyle(); }
  static FontStyle italic() { FontStyle s; s.kind = Kind::Italic; return s; }
  static FontStyle oblique(float degrees) { FontStyle s; s.kind = Kind::Oblique; s.oblique_degrees = degrees; return s; }
  static FontStyle system(SystemFont sf) { FontStyle s; s.kind = Kind::System; s.system_font = sf; return s; }

  std::optional<SystemFont> get_system() const;
  static float compute_angle_degrees(float angle_degrees);
  static float default_angle();

  /// Convert to computed value
  computed::FontStyle to_computed_value(const Context& context) const;
  static FontStyle from_computed_value(const computed::FontStyle& computed);

  std::string to_css() const;
  FontStyle clone() const { return *this; }
};

/// FontStretchKeyword - keywords for font-stretch
enum class FontStretchKeyword : uint8_t {
  Normal = 0,
  Condensed,
  UltraCondensed,
  ExtraCondensed,
  SemiCondensed,
  SemiExpanded,
  Expanded,
  ExtraExpanded,
  UltraExpanded,
};

/// FontStretch - specified font-stretch property
/// https://drafts.csswg.org/css-fonts-4/#font-stretch-prop
struct FontStretch {
  enum class Kind { Stretch, Keyword, System };
  Kind kind = Kind::Keyword;
  float percentage = 100.0f;
  FontStretchKeyword keyword = FontStretchKeyword::Normal;
  SystemFont system_font = SystemFont::End;

  FontStretch() = default;
  static FontStretch normal();
  static FontStretch keyword(FontStretchKeyword kw);
  static FontStretch stretch(float pct);
  static FontStretch system(SystemFont sf);

  std::optional<SystemFont> get_system() const;

  /// Compute keyword value
  computed::FontStretch compute() const;

  /// Convert to computed value
  computed::FontStretch to_computed_value(const Context& context) const;
  static FontStretch from_computed_value(const computed::FontStretch& computed);

  std::string to_css() const;
  FontStretch clone() const { return *this; }
};

/// FontSizeKeyword - CSS font size keywords
enum class FontSizeKeyword : uint8_t {
  XXSmall = 0,
  XSmall,
  Small,
  Medium,
  Large,
  XLarge,
  XXLarge,
  XXXLarge,
  Math,
  None,
};

/// KeywordInfo - additional information for keyword-derived font sizes
struct KeywordInfo {
  FontSizeKeyword kw = FontSizeKeyword::Medium;
  float factor = 1.0f;
  float offset_px = 0.0f;

  KeywordInfo() = default;
  KeywordInfo(FontSizeKeyword k, float f = 1.0f, float o = 0.0f)
    : kw(k), factor(f), offset_px(o) {}

  static KeywordInfo medium() { return KeywordInfo(FontSizeKeyword::Medium); }
  static KeywordInfo none() { return KeywordInfo(FontSizeKeyword::None); }

  float to_computed_value_px(const Context& context) const;
  KeywordInfo compose(float f) const;

  KeywordInfo clone() const { return *this; }
};

/// FontSize - specified font-size value
struct FontSize {
  enum class Kind { Length, Keyword, Smaller, Larger, System };
  Kind kind = Kind::Keyword;
  // For Length variant: the LengthPercentage value
  std::optional<LengthPercentage> length;
  // For Keyword variant:
  KeywordInfo keyword_info;
  // For System variant:
  SystemFont system_font = SystemFont::End;

  FontSize() : keyword_info(KeywordInfo::medium()) {}
  static FontSize medium();
  static FontSize from_html_size(uint8_t size);
  static FontSize smaller();
  static FontSize larger();
  static FontSize system(SystemFont sf);

  std::optional<SystemFont> get_system() const;

  /// Compute against a given base font size
  computed::FontSize to_computed_value_against(const Context& context,
                                                const FontBaseSize& base_size,
                                                const LineHeightBase& lh_base) const;
  computed::FontSize to_computed_value(const Context& context) const;
  static FontSize from_computed_value(const computed::FontSize& computed);

  std::string to_css() const;
  static std::optional<FontSize> parse_quirky(const ParserContext& ctx, class cssparser::Parser& input, bool allow_quirks);

  FontSize clone() const;
};

/// FontFamily - specified font-family value
struct FontFamily {
  enum class Kind { Values, System };
  Kind kind = Kind::Values;
  // For Values variant: list of family name strings
  std::vector<std::string> families;
  SystemFont system_font = SystemFont::End;

  FontFamily() = default;
  static FontFamily values(const std::vector<std::string>& f);
  static FontFamily system(SystemFont sf);

  std::optional<SystemFont> get_system() const;
  computed::FontFamily to_computed_value(const Context& context) const;
  static FontFamily from_computed_value(const computed::FontFamily& computed);

  std::string to_css() const;

  FontFamily clone() const;
};

/// FontSizeAdjustFactor - number or from-font keyword
struct FontSizeAdjustFactor {
  enum class Kind { Number, FromFont };
  Kind kind = Kind::Number;
  float value = 1.0f;

  FontSizeAdjustFactor() = default;
  static FontSizeAdjustFactor number(float v);
  static FontSizeAdjustFactor from_font();

  std::string to_css() const;
  FontSizeAdjustFactor clone() const { return *this; }
};

/// FontSizeAdjust - specified value for font-size-adjust
struct FontSizeAdjust {
  enum class Basis { ExHeight, CapHeight, ChWidth, IcWidth, IcHeight, None };
  Basis basis = Basis::ExHeight;
  FontSizeAdjustFactor factor;

  FontSizeAdjust() = default;
  static FontSizeAdjust none();
  static FontSizeAdjust ex_height(const FontSizeAdjustFactor& f);

  std::string to_css() const;
  FontSizeAdjust clone() const { return *this; }
};

/// FontVariantAlternates - list of variant alternates
class FontVariantAlternates {
public:
  enum class AlternateKind {
    Stylistic, Styleset, CharacterVariant,
    Swash, Ornaments, Annotation, HistoricalForms
  };

private:
  struct AlternateEntry {
    AlternateKind kind;
    std::vector<CustomIdent> idents;
  };
  std::vector<AlternateEntry> alternates_;

public:
  FontVariantAlternates() = default;
  static FontVariantAlternates normal();

  size_t len() const;
  bool empty() const { return alternates_.empty(); }

  void add_stylistic(const CustomIdent& ident);
  void add_styleset(const std::vector<CustomIdent>& idents);
  void add_character_variant(const std::vector<CustomIdent>& idents);
  void add_swash(const CustomIdent& ident);
  void add_ornaments(const CustomIdent& ident);
  void add_annotation(const CustomIdent& ident);
  void add_historical_forms();

  std::string to_css() const;

  FontVariantAlternates clone() const;
};

/// FontVariantEastAsian - bitflags for east asian font variants
class FontVariantEastAsian {
public:
  enum Flags : uint16_t {
    NORMAL = 0,
    JIS78 = 1 << 0,
    JIS83 = 1 << 1,
    JIS90 = 1 << 2,
    JIS04 = 1 << 3,
    SIMPLIFIED = 1 << 4,
    TRADITIONAL = 1 << 5,
    FULL_WIDTH = 1 << 6,
    PROPORTIONAL_WIDTH = 1 << 7,
    RUBY = 1 << 8,
  };

private:
  uint16_t flags_ = NORMAL;

public:
  FontVariantEastAsian() = default;
  explicit FontVariantEastAsian(uint16_t f) : flags_(f) {}

  static FontVariantEastAsian normal() { return FontVariantEastAsian(NORMAL); }

  bool contains(uint16_t f) const { return (flags_ & f) == f; }
  void set(uint16_t f, bool value = true) { if (value) flags_ |= f; else flags_ &= ~f; }
  uint16_t bits() const { return flags_; }
  bool is_empty() const { return flags_ == 0; }

  bool validate_mixed_flags() const;

  std::string to_css() const;

  FontVariantEastAsian clone() const { return *this; }
};

/// FontVariantLigatures - bitflags for ligature font variants
class FontVariantLigatures {
public:
  enum Flags : uint16_t {
    NORMAL = 0,
    NONE = 1,
    COMMON_LIGATURES = 1 << 1,
    NO_COMMON_LIGATURES = 1 << 2,
    DISCRETIONARY_LIGATURES = 1 << 3,
    NO_DISCRETIONARY_LIGATURES = 1 << 4,
    HISTORICAL_LIGATURES = 1 << 5,
    NO_HISTORICAL_LIGATURES = 1 << 6,
    CONTEXTUAL = 1 << 7,
    NO_CONTEXTUAL = 1 << 8,
  };

private:
  uint16_t flags_ = NORMAL;

public:
  FontVariantLigatures() = default;
  explicit FontVariantLigatures(uint16_t f) : flags_(f) {}

  static FontVariantLigatures normal() { return FontVariantLigatures(NORMAL); }

  bool contains(uint16_t f) const { return (flags_ & f) == f; }
  void set(uint16_t f, bool value = true) { if (value) flags_ |= f; else flags_ &= ~f; }
  uint16_t bits() const { return flags_; }
  bool is_empty() const { return flags_ == 0; }

  bool validate_mixed_flags() const;

  std::string to_css() const;

  FontVariantLigatures clone() const { return *this; }
};

/// FontVariantNumeric - bitflags for numeric font variants
class FontVariantNumeric {
public:
  enum Flags : uint8_t {
    NORMAL = 0,
    LINING_NUMS = 1 << 0,
    OLDSTYLE_NUMS = 1 << 1,
    PROPORTIONAL_NUMS = 1 << 2,
    TABULAR_NUMS = 1 << 3,
    DIAGONAL_FRACTIONS = 1 << 4,
    STACKED_FRACTIONS = 1 << 5,
    SLASHED_ZERO = 1 << 6,
    ORDINAL = 1 << 7,
  };

private:
  uint8_t flags_ = NORMAL;

public:
  FontVariantNumeric() = default;
  explicit FontVariantNumeric(uint8_t f) : flags_(f) {}

  static FontVariantNumeric normal() { return FontVariantNumeric(NORMAL); }

  bool contains(uint8_t f) const { return (flags_ & f) == f; }
  void set(uint8_t f, bool value = true) { if (value) flags_ |= f; else flags_ &= ~f; }
  uint8_t bits() const { return flags_; }
  bool is_empty() const { return flags_ == 0; }

  bool validate_mixed_flags() const;

  std::string to_css() const;

  FontVariantNumeric clone() const { return *this; }
};

// Type aliases
using FontFeatureSettings = std::vector<FeatureTagValue>;
using FontVariationSettings = std::vector<VariationValue>;

/// FeatureTagValue - a single OpenType feature tag value
struct FeatureTagValue {
  uint32_t tag = 0;  // Four-byte tag
  int32_t value = 0;

  FeatureTagValue() = default;
  FeatureTagValue(uint32_t t, int32_t v) : tag(t), value(v) {}

  std::string to_css() const;
};

/// VariationValue - a single font variation axis value
struct VariationValue {
  uint32_t tag = 0;
  float value = 0.0f;

  VariationValue() = default;
  VariationValue(uint32_t t, float v) : tag(t), value(v) {}

  std::string to_css() const;
};

/// FontLanguageOverride - specified font-language-override value
struct FontLanguageOverride {
  enum class Kind { Normal, Override };
  Kind kind = Kind::Normal;
  std::string override_string;

  FontLanguageOverride() = default;
  static FontLanguageOverride normal();
  static FontLanguageOverride override_str(const std::string& s);

  std::string to_css() const;
  FontLanguageOverride clone() const { return *this; }
};

/// Result of font size keyword resolution
struct FontSizeKeywordResult {
  float computed_px;
  KeywordInfo keyword_info;
};

// Size-of-test constant (Rust: size_of_test!(Image, 16))
// In C++, this is just a documentation note that font objects should remain small.

} // namespace specified
} // namespace style::values

// Include dependent headers
#include "../computed/font_fwd.hpp"
