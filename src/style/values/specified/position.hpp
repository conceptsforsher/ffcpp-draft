#pragma once
// SPDX-License-Identifier: MPL-2.0
// Translated from servo/components/style/values/specified/position.rs

#include <string>
#include <variant>
#include <optional>
#include <vector>
#include <memory>
#include <cstdint>
#include <cmath>
#include <algorithm>
#include <sstream>

namespace style::values::specified {

// Forward declarations
struct LengthPercentage;

/// HorizontalPositionKeyword - X-axis position keywords
enum class HorizontalPositionKeyword : uint8_t {
  Left = 0,
  Right,
};

/// VerticalPositionKeyword - Y-axis position keywords
enum class VerticalPositionKeyword : uint8_t {
  Top = 0,
  Bottom,
};

/// PositionComponent - a component of a CSS <position>
/// https://drafts.csswg.org/css-backgrounds-3/#position
template<typename S>
class PositionComponent {
public:
  enum class Kind { Center, Length, Side };
  Kind kind = Kind::Center;
  S keyword;  // Only used for Side variant
  std::optional<LengthPercentage> length;  // For Length or Side variant

  PositionComponent() = default;

  static PositionComponent center() {
    PositionComponent pc; pc.kind = Kind::Center; return pc;
  }

  static PositionComponent length_val(const LengthPercentage& lp) {
    PositionComponent pc; pc.kind = Kind::Length; pc.length = lp; return pc;
  }

  static PositionComponent side_val(S kw, std::optional<LengthPercentage> lp = std::nullopt) {
    PositionComponent pc; pc.kind = Kind::Side; pc.keyword = kw; pc.length = lp; return pc;
  }

  /// Returns the number of components (1 for center/length/side-alone, 2 for side+length)
  int component_count() const {
    switch (kind) {
      case Kind::Length:
      case Kind::Center:
        return 1;
      case Kind::Side:
        return length.has_value() ? 2 : 1;
    }
    return 1;
  }

  /// Returns true if this is a center value (including percentage 50%)
  bool is_center() const {
    switch (kind) {
      case Kind::Center: return true;
      case Kind::Length: {
        // Check if percentage is 50%
        if (length.has_value()) {
          // Placeholder: check percentage value
        }
        return false;
      }
      case Kind::Side: {
        if (length.has_value()) {
          // Check if percentage from side is 50%
        }
        return false;
      }
    }
    return false;
  }

  /// The initial specified value (start side)
  static PositionComponent initial_specified_value() {
    return side_val(S::start());
  }

  std::string to_css() const;
  static std::optional<PositionComponent> parse(const ParserContext& ctx, class cssparser::Parser& input);

  template<typename S2>
  bool operator==(const PositionComponent<S2>& other) const {
    if (kind != other.kind) return false;
    if (kind == Kind::Side && keyword != other.keyword) return false;
    return true;
  }

  PositionComponent clone() const { return *this; }
};

/// Position - specified CSS <position> value
/// https://drafts.csswg.org/css-backgrounds-3/#position
class Position {
public:
  PositionComponent<HorizontalPositionKeyword> horizontal;
  PositionComponent<VerticalPositionKeyword> vertical;

  Position() = default;
  Position(PositionComponent<HorizontalPositionKeyword> h, PositionComponent<VerticalPositionKeyword> v)
    : horizontal(h), vertical(v) {}

  static Position center() {
    return Position(
      PositionComponent<HorizontalPositionKeyword>::center(),
      PositionComponent<VerticalPositionKeyword>::center()
    );
  }

  /// Returns true if this uses 3-value syntax
  bool is_three_value_syntax() const {
    return horizontal.component_count() != vertical.component_count();
  }

  std::string to_css() const;
  static std::optional<Position> parse(const ParserContext& ctx, class cssparser::Parser& input);
  static std::optional<Position> parse_three_value_quirky(const ParserContext& ctx, class cssparser::Parser& input, bool allow_quirks);

  Position clone() const { return *this; }
  bool operator==(const Position& other) const = default;
};

/// AnchorScope - scope value for anchor positioning
enum class AnchorScopeKind : uint8_t {
  None,
  All,
  Idents,  // list of dashed-idents
};

class AnchorScope {
public:
  AnchorScopeKind kind = AnchorScopeKind::None;
  std::vector<std::string> idents;  // For Idents variant

  AnchorScope() = default;
  static AnchorScope none() { return AnchorScope(); }
  static AnchorScope all();

  bool is_none() const { return kind == AnchorScopeKind::None; }

  std::string to_css() const;
  static std::optional<AnchorScope> parse(const ParserContext& ctx, class cssparser::Parser& input);
  AnchorScope clone() const { return *this; }
};

/// AnchorName - anchor-name property value
class AnchorName {
public:
  std::vector<std::string> idents;

  AnchorName() = default;
  static AnchorName none() { return AnchorName(); }
  bool is_none() const { return idents.empty(); }

  std::string to_css() const;
  static std::optional<AnchorName> parse(const ParserContext& ctx, class cssparser::Parser& input);
  AnchorName clone() const { return *this; }
};

/// PositionAnchor - position-anchor property value
enum class PositionAnchorKind : uint8_t {
  Auto,
  Ident,
};

class PositionAnchor {
public:
  PositionAnchorKind kind = PositionAnchorKind::Auto;
  std::string ident;  // For Ident variant

  PositionAnchor() = default;
  static PositionAnchor auto_val() { return PositionAnchor(); }

  bool is_auto() const { return kind == PositionAnchorKind::Auto; }

  std::string to_css() const;
  static std::optional<PositionAnchor> parse(const ParserContext& ctx, class cssparser::Parser& input);
  PositionAnchor clone() const { return *this; }
};

/// PositionAreaKeyword - keywords for position-area property
/// https://drafts.csswg.org/css-anchor-position-1/#propdef-position-area
enum class PositionAreaKeyword : uint8_t {
  None = 0,

  // Common keywords
  Center,
  SpanAll,

  // Horizontal keywords
  Left, Right,
  SpanLeft, SpanRight,
  XStart, XEnd,
  SpanXStart, SpanXEnd,
  XSelfStart, XSelfEnd,
  SpanXSelfStart, SpanXSelfEnd,

  // Vertical keywords
  Top, Bottom,
  SpanTop, SpanBottom,
  YStart, YEnd,
  SpanYStart, SpanYEnd,
  YSelfStart, YSelfEnd,
  SpanYSelfStart, SpanYSelfEnd,

  // Block keywords
  BlockStart, BlockEnd,
  SpanBlockStart, SpanBlockEnd,

  // Inline keywords
  InlineStart, InlineEnd,
  SpanInlineStart, SpanInlineEnd,

  // Self block/inline keywords
  SelfBlockStart, SelfBlockEnd,
  SpanSelfBlockStart, SpanSelfBlockEnd,
  SelfInlineStart, SelfInlineEnd,
  SpanSelfInlineStart, SpanSelfInlineEnd,

  // Inferred axis keywords
  Start, End,
  SpanStart, SpanEnd,

  // Self inferred keywords
  SelfStart, SelfEnd,
  SpanSelfStart, SpanSelfEnd,
};

// Helper functions for PositionAreaKeyword
bool is_compatible_pairing(PositionAreaKeyword first, PositionAreaKeyword second);

/// PositionArea - position-area property value
class PositionArea {
public:
  PositionAreaKeyword first = PositionAreaKeyword::None;
  PositionAreaKeyword second = PositionAreaKeyword::None;

  PositionArea() = default;
  PositionArea(PositionAreaKeyword f, PositionAreaKeyword s) : first(f), second(s) {}

  static PositionArea none();
  bool is_none() const { return first == PositionAreaKeyword::None; }

  std::string to_css() const;
  static std::optional<PositionArea> parse(const ParserContext& ctx, class cssparser::Parser& input);

  PositionArea clone() const { return *this; }
  bool operator==(const PositionArea& other) const = default;
};

/// PositionVisibility - bitflags for position-visibility
class PositionVisibility {
public:
  enum Flags : uint8_t {
    ALWAYS = 0,
    ANCHORS_VALID = 1 << 0,
    ANCHORS_VISIBLE = 1 << 1,
    NO_OVERFLOW = 1 << 2,
  };

private:
  uint8_t flags_ = ALWAYS;

public:
  PositionVisibility() = default;
  explicit PositionVisibility(uint8_t f) : flags_(f) {}

  static PositionVisibility always_val() { return PositionVisibility(ALWAYS); }

  bool contains(uint8_t f) const { return (flags_ & f) == f; }
  uint8_t bits() const { return flags_; }

  std::string to_css() const;
  static std::optional<PositionVisibility> parse(const ParserContext& ctx, class cssparser::Parser& input);
  PositionVisibility clone() const { return *this; }
};

/// GridAutoFlow - bitflags for grid-auto-flow property
/// https://drafts.csswg.org/css-grid-2/#grid-auto-flow-property
class GridAutoFlow {
public:
  enum Flags : uint8_t {
    ROW = 1 << 0,
    COLUMN = 1 << 1,
    DENSE = 1 << 2,
  };

private:
  uint8_t flags_ = ROW;

public:
  GridAutoFlow() = default;
  explicit GridAutoFlow(uint8_t f) : flags_(f) {}

  bool contains(uint8_t f) const { return (flags_ & f) != 0; }
  void set(uint8_t f, bool value = true) { if (value) flags_ |= f; else flags_ &= ~f; }
  bool intersects(uint8_t f) const { return (flags_ & f) != 0; }

  bool validate_and_simplify();

  std::string to_css() const;
  static std::optional<GridAutoFlow> parse(const ParserContext& ctx, class cssparser::Parser& input);
  GridAutoFlow clone() const { return *this; }
};

/// MasonryPlacement - packing algorithm for masonry layout
enum class MasonryPlacement : uint8_t {
  Pack = 0,
  Next,
};

/// MasonryItemOrder - item ordering for masonry layout
enum class MasonryItemOrder : uint8_t {
  DefiniteFirst = 0,
  Ordered,
};

/// MasonryAutoFlow - controls masonry layout auto-placement
/// https://drafts.csswg.org/css-grid-3/#masonry-auto-flow
class MasonryAutoFlow {
public:
  MasonryPlacement placement = MasonryPlacement::Pack;
  MasonryItemOrder order = MasonryItemOrder::DefiniteFirst;

  MasonryAutoFlow() = default;
  static MasonryAutoFlow initial() { return MasonryAutoFlow(); }

  std::string to_css() const;
  static std::optional<MasonryAutoFlow> parse(const ParserContext& ctx, class cssparser::Parser& input);
  MasonryAutoFlow clone() const { return *this; }
};

/// PositionTryFallbacksTryTacticKeyword
enum class PositionTryFallbacksTryTacticKeyword : uint8_t {
  None = 0,
  FlipBlock,
  FlipInline,
  FlipStart,
};

/// PositionTryFallbacksTryTactic - 3-keyword tactic value
class PositionTryFallbacksTryTactic {
public:
  PositionTryFallbacksTryTacticKeyword first = PositionTryFallbacksTryTacticKeyword::None;
  PositionTryFallbacksTryTacticKeyword second = PositionTryFallbacksTryTacticKeyword::None;
  PositionTryFallbacksTryTacticKeyword third = PositionTryFallbacksTryTacticKeyword::None;

  PositionTryFallbacksTryTactic() = default;
  PositionTryFallbacksTryTactic(PositionTryFallbacksTryTacticKeyword f,
                                 PositionTryFallbacksTryTacticKeyword s,
                                 PositionTryFallbacksTryTacticKeyword t)
    : first(f), second(s), third(t) {}

  bool is_empty() const { return first == PositionTryFallbacksTryTacticKeyword::None; }

  std::string to_css() const;
  static std::optional<PositionTryFallbacksTryTactic> parse(const ParserContext& ctx, class cssparser::Parser& input);
  PositionTryFallbacksTryTactic clone() const { return *this; }
};

/// DashedIdentAndOrTryTactic - used in position-try-fallbacks
class DashedIdentAndOrTryTactic {
public:
  std::string ident;
  PositionTryFallbacksTryTactic try_tactic;

  DashedIdentAndOrTryTactic() = default;

  std::string to_css() const;
  static std::optional<DashedIdentAndOrTryTactic> parse(const ParserContext& ctx, class cssparser::Parser& input);
  DashedIdentAndOrTryTactic clone() const { return *this; }
};

/// PositionTryOrder - ordering for position try fallbacks
enum class PositionTryOrder : uint8_t {
  Normal = 0,
  MostWidth,
  MostHeight,
  MostBlockSize,
  MostInlineSize,
};

/// Side trait equivalent - implemented as free functions
namespace side_trait {
  HorizontalPositionKeyword horizontal_start();
  bool horizontal_is_start(HorizontalPositionKeyword kw);
  VerticalPositionKeyword vertical_start();
  bool vertical_is_start(VerticalPositionKeyword kw);
}

} // namespace style::values::specified
