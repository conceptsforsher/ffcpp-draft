// SPDX-License-Identifier: MPL-2.0
// Translated from servo/components/style/values/specified/box.rs
// Implementation of specified box property values

#include "box.hpp"
#include <algorithm>
#include <cctype>
#include <cassert>
#include <sstream>

namespace style::values::specified {

// =====================================================================
// Display constants definition
// =====================================================================

const Display Display::None = Display::make(DisplayOutside::None, DisplayInside::None);
const Display Display::Contents = Display::make(DisplayOutside::None, DisplayInside::Contents);
const Display Display::Inline = Display::make(DisplayOutside::Inline, DisplayInside::Flow);
const Display Display::InlineBlock = Display::make(DisplayOutside::Inline, DisplayInside::FlowRoot);
const Display Display::Block = Display::make(DisplayOutside::Block, DisplayInside::Flow);
const Display Display::FlowRoot = Display::make(DisplayOutside::Block, DisplayInside::FlowRoot);
const Display Display::Flex = Display::make(DisplayOutside::Block, DisplayInside::Flex);
const Display Display::InlineFlex = Display::make(DisplayOutside::Inline, DisplayInside::Flex);
const Display Display::Grid = Display::make(DisplayOutside::Block, DisplayInside::Grid);
const Display Display::InlineGrid = Display::make(DisplayOutside::Inline, DisplayInside::Grid);
const Display Display::Table = Display::make(DisplayOutside::Block, DisplayInside::Table);
const Display Display::InlineTable = Display::make(DisplayOutside::Inline, DisplayInside::Table);
const Display Display::TableCaption = Display::make(DisplayOutside::TableCaption, DisplayInside::Flow);
const Display Display::Ruby = Display::make(DisplayOutside::Inline, DisplayInside::Ruby);
const Display Display::WebkitBox = Display::make(DisplayOutside::Block, DisplayInside::WebkitBox);
const Display Display::WebkitInlineBox = Display::make(DisplayOutside::Inline, DisplayInside::WebkitBox);

const Display Display::TableRowGroup = Display::make(DisplayOutside::InternalTable, DisplayInside::TableRowGroup);
const Display Display::TableHeaderGroup = Display::make(DisplayOutside::InternalTable, DisplayInside::TableHeaderGroup);
const Display Display::TableFooterGroup = Display::make(DisplayOutside::InternalTable, DisplayInside::TableFooterGroup);
const Display Display::TableColumn = Display::make(DisplayOutside::InternalTable, DisplayInside::TableColumn);
const Display Display::TableColumnGroup = Display::make(DisplayOutside::InternalTable, DisplayInside::TableColumnGroup);
const Display Display::TableRow = Display::make(DisplayOutside::InternalTable, DisplayInside::TableRow);
const Display Display::TableCell = Display::make(DisplayOutside::InternalTable, DisplayInside::TableCell);

const Display Display::RubyBase = Display::make(DisplayOutside::InternalRuby, DisplayInside::RubyBase);
const Display Display::RubyBaseContainer = Display::make(DisplayOutside::InternalRuby, DisplayInside::RubyBaseContainer);
const Display Display::RubyText = Display::make(DisplayOutside::InternalRuby, DisplayInside::RubyText);
const Display Display::RubyTextContainer = Display::make(DisplayOutside::InternalRuby, DisplayInside::RubyTextContainer);

// =====================================================================
// Display methods
// =====================================================================

bool Display::is_line_participant() const {
  if (is_inline_flow()) return true;
  switch (value_) {
    case Contents.value_:
    case Ruby.value_:
    case RubyBaseContainer.value_:
      return true;
    default:
      return false;
  }
}

bool Display::is_ruby_level_container() const {
  switch (value_) {
    case RubyBaseContainer.value_:
    case RubyTextContainer.value_:
      return true;
    default:
      return false;
  }
}

bool Display::is_ruby_type() const {
  switch (inside()) {
    case DisplayInside::Ruby:
    case DisplayInside::RubyBase:
    case DisplayInside::RubyText:
    case DisplayInside::RubyBaseContainer:
    case DisplayInside::RubyTextContainer:
      return true;
    default:
      return false;
  }
}

Display Display::equivalent_block_display(bool is_root_element) const {
  // Special handling for contents and list-item on root element
  if (is_root_element && (is_contents() || is_list_item())) {
    return Display::Block;
  }

  switch (outside()) {
    case DisplayOutside::Inline: {
      DisplayInside in = inside();
      // inline-block blockifies to block (flow), not flow-root
      if (in == DisplayInside::FlowRoot) {
        in = DisplayInside::Flow;
      }
      return make3(DisplayOutside::Block, in, is_list_item());
    }
    case DisplayOutside::Block:
    case DisplayOutside::None:
      return *this;
    default:
      return Display::Block;
  }
}

Display Display::inlinify() const {
  switch (outside()) {
    case DisplayOutside::Block: {
      DisplayInside in = inside();
      if (in == DisplayInside::Flow) {
        in = DisplayInside::FlowRoot;  // inline-block equivalent
      }
      return make3(DisplayOutside::Inline, in, is_list_item());
    }
    default:
      return *this;
  }
}

// CSS serialization of DisplayOutside
namespace {
const char* display_outside_to_string(DisplayOutside o) {
  switch (o) {
    case DisplayOutside::None: return "none";
    case DisplayOutside::Inline: return "inline";
    case DisplayOutside::Block: return "block";
    case DisplayOutside::TableCaption: return "table-caption";
    case DisplayOutside::InternalTable: return "";
    case DisplayOutside::InternalRuby: return "";
  }
  return "";
}

const char* display_inside_to_string(DisplayInside i) {
  switch (i) {
    case DisplayInside::None: return "";
    case DisplayInside::Contents: return "contents";
    case DisplayInside::Flow: return "flow";
    case DisplayInside::FlowRoot: return "flow-root";
    case DisplayInside::Flex: return "flex";
    case DisplayInside::Grid: return "grid";
    case DisplayInside::Table: return "table";
    case DisplayInside::TableRowGroup: return "table-row-group";
    case DisplayInside::TableColumn: return "table-column";
    case DisplayInside::TableColumnGroup: return "table-column-group";
    case DisplayInside::TableHeaderGroup: return "table-header-group";
    case DisplayInside::TableFooterGroup: return "table-footer-group";
    case DisplayInside::TableRow: return "table-row";
    case DisplayInside::TableCell: return "table-cell";
    case DisplayInside::Ruby: return "ruby";
    case DisplayInside::RubyBase: return "ruby-base";
    case DisplayInside::RubyBaseContainer: return "ruby-base-container";
    case DisplayInside::RubyText: return "ruby-text";
    case DisplayInside::RubyTextContainer: return "ruby-text-container";
    case DisplayInside::WebkitBox: return "-webkit-box";
  }
  return "";
}
} // anonymous namespace

std::string Display::to_css() const {
  DisplayOutside out = outside();
  DisplayInside in = inside();

  // Short-circuit common named values
  if (*this == Block) return "block";
  if (*this == Inline) return "inline";
  if (*this == InlineBlock) return "inline-block";
  if (*this == None) return "none";
  if (*this == Contents) return "contents";
  if (*this == Flex) return "flex";
  if (*this == InlineFlex) return "inline-flex";
  if (*this == Grid) return "grid";
  if (*this == InlineGrid) return "inline-grid";
  if (*this == Table) return "table";
  if (*this == InlineTable) return "inline-table";
  if (*this == TableCaption) return "table-caption";
  if (*this == WebkitInlineBox) return "-webkit-inline-box";
  if (*this == Ruby) return "ruby";

  // For internal table / ruby boxes
  if (out == DisplayOutside::InternalTable || out == DisplayOutside::InternalRuby) {
    return display_inside_to_string(in);
  }

  // Multi-keyword display
  if (*this == Display::make(DisplayOutside::Block, DisplayInside::Ruby)) {
    return "block ruby";
  }

  if (*this == Display::make(DisplayOutside::Inline, DisplayInside::Grid)) {
    return "inline-grid";
  }
  if (*this == Display::make(DisplayOutside::Inline, DisplayInside::Flex)) {
    return "inline-flex";
  }
  if (*this == Display::make(DisplayOutside::Inline, DisplayInside::Table)) {
    return "inline-table";
  }

  // General case: outer + optional inner + optional list-item
  std::ostringstream oss;
  if (is_list_item()) {
    if (out != DisplayOutside::Block) {
      oss << display_outside_to_string(out) << " ";
    }
    if (in != DisplayInside::Flow) {
      oss << display_inside_to_string(in) << " ";
    }
    oss << "list-item";
  } else {
    oss << display_inside_to_string(in);
  }
  return oss.str();
}

std::optional<Display> Display::parse(const ParserContext& /*ctx*/, class cssparser::Parser& input) {
  // This is a simplified parser. Full parser needs multi-keyword support.
  auto token = input.next();
  if (!token) return std::nullopt;

  if (auto* ident = std::get_if<std::string>(&*token)) {
    std::string lower = *ident;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

    if (lower == "none") return Display::None;
    if (lower == "contents") return Display::Contents;
    if (lower == "block") return Display::Block;
    if (lower == "inline") return Display::Inline;
    if (lower == "inline-block") return Display::InlineBlock;
    if (lower == "flex") return Display::Flex;
    if (lower == "inline-flex") return Display::InlineFlex;
    if (lower == "grid") return Display::Grid;
    if (lower == "inline-grid") return Display::InlineGrid;
    if (lower == "flow") return Display::make(DisplayOutside::Block, DisplayInside::Flow);
    if (lower == "flow-root") return Display::FlowRoot;
    if (lower == "table") return Display::Table;
    if (lower == "inline-table") return Display::InlineTable;
    if (lower == "table-caption") return Display::TableCaption;
    if (lower == "table-row-group") return Display::TableRowGroup;
    if (lower == "table-header-group") return Display::TableHeaderGroup;
    if (lower == "table-footer-group") return Display::TableFooterGroup;
    if (lower == "table-column") return Display::TableColumn;
    if (lower == "table-column-group") return Display::TableColumnGroup;
    if (lower == "table-row") return Display::TableRow;
    if (lower == "table-cell") return Display::TableCell;
    if (lower == "list-item") return Display::make3(DisplayOutside::Block, DisplayInside::Flow, true);
    if (lower == "ruby") return Display::Ruby;
    if (lower == "-webkit-box") return Display::WebkitBox;
    if (lower == "-webkit-inline-box") return Display::WebkitInlineBox;
  }

  return std::nullopt;
}

// =====================================================================
// ScrollSnapType
// =====================================================================

std::string ScrollSnapType::to_css() const {
  if (strictness == ScrollSnapStrictness::None) return "none";

  std::ostringstream oss;
  switch (axis) {
    case ScrollSnapAxis::X: oss << "x"; break;
    case ScrollSnapAxis::Y: oss << "y"; break;
    case ScrollSnapAxis::Block: oss << "block"; break;
    case ScrollSnapAxis::Inline: oss << "inline"; break;
    case ScrollSnapAxis::Both: oss << "both"; break;
  }

  if (strictness != ScrollSnapStrictness::Proximity) {
    oss << " ";
    switch (strictness) {
      case ScrollSnapStrictness::Mandatory: oss << "mandatory"; break;
      default: break;
    }
  }
  return oss.str();
}

std::optional<ScrollSnapType> ScrollSnapType::parse(const ParserContext& /*ctx*/, class cssparser::Parser& input) {
  auto token = input.next();
  if (!token) return std::nullopt;

  if (auto* ident = std::get_if<std::string>(&*token)) {
    std::string lower = *ident;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

    if (lower == "none") return ScrollSnapType::none();

    ScrollSnapAxis axis;
    if (lower == "x") axis = ScrollSnapAxis::X;
    else if (lower == "y") axis = ScrollSnapAxis::Y;
    else if (lower == "block") axis = ScrollSnapAxis::Block;
    else if (lower == "inline") axis = ScrollSnapAxis::Inline;
    else if (lower == "both") axis = ScrollSnapAxis::Both;
    else return std::nullopt;

    // Try to parse strictness
    ScrollSnapStrictness strictness = ScrollSnapStrictness::Proximity;
    auto next = input.peek();
    if (next && std::holds_alternative<std::string>(*next)) {
      std::string s = std::get<std::string>(*next);
      std::transform(s.begin(), s.end(), s.begin(), ::tolower);
      if (s == "mandatory") { input.next(); strictness = ScrollSnapStrictness::Mandatory; }
      else if (s == "proximity") { input.next(); strictness = ScrollSnapStrictness::Proximity; }
    }

    return ScrollSnapType(axis, strictness);
  }

  return std::nullopt;
}

// =====================================================================
// ScrollSnapAlign
// =====================================================================

std::string ScrollSnapAlign::to_css() const {
  std::ostringstream oss;
  auto kw_to_str = [](ScrollSnapAlignKeyword kw) -> const char* {
    switch (kw) {
      case ScrollSnapAlignKeyword::None: return "none";
      case ScrollSnapAlignKeyword::Start: return "start";
      case ScrollSnapAlignKeyword::End: return "end";
      case ScrollSnapAlignKeyword::Center: return "center";
    }
    return "none";
  };

  oss << kw_to_str(block);
  if (block != inline_val) {
    oss << " " << kw_to_str(inline_val);
  }
  return oss.str();
}

std::optional<ScrollSnapAlign> ScrollSnapAlign::parse(const ParserContext& /*ctx*/, class cssparser::Parser& input) {
  auto token = input.next();
  if (!token) return std::nullopt;

  if (!std::holds_alternative<std::string>(*token)) return std::nullopt;
  std::string lower = std::get<std::string>(*token);
  std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

  ScrollSnapAlignKeyword block_kw;
  if (lower == "none") block_kw = ScrollSnapAlignKeyword::None;
  else if (lower == "start") block_kw = ScrollSnapAlignKeyword::Start;
  else if (lower == "end") block_kw = ScrollSnapAlignKeyword::End;
  else if (lower == "center") block_kw = ScrollSnapAlignKeyword::Center;
  else return std::nullopt;

  // Try to parse a second keyword
  ScrollSnapAlignKeyword inline_kw = block_kw;
  auto next = input.peek();
  if (next && std::holds_alternative<std::string>(*next)) {
    std::string s = std::get<std::string>(*next);
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    if (s == "none") { input.next(); inline_kw = ScrollSnapAlignKeyword::None; }
    else if (s == "start") { input.next(); inline_kw = ScrollSnapAlignKeyword::Start; }
    else if (s == "end") { input.next(); inline_kw = ScrollSnapAlignKeyword::End; }
    else if (s == "center") { input.next(); inline_kw = ScrollSnapAlignKeyword::Center; }
  }

  return ScrollSnapAlign(block_kw, inline_kw);
}

// =====================================================================
// WillChange
// =====================================================================

std::string WillChange::to_css() const {
  if (features.empty()) return "auto";
  std::ostringstream oss;
  for (size_t i = 0; i < features.size(); ++i) {
    if (i > 0) oss << ", ";
    oss << "/* ident */";  // Placeholder
  }
  return oss.str();
}

std::optional<WillChange> WillChange::parse(const ParserContext& ctx, class cssparser::Parser& input) {
  auto token = input.next();
  if (!token) return std::nullopt;

  if (auto* ident = std::get_if<std::string>(&*token)) {
    std::string lower = *ident;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    if (lower == "auto") return WillChange::auto_val();
  }

  // Parse comma-separated idents
  WillChange wc;
  // Simplified parser
  return wc;
}

WillChange WillChange::clone() const {
  return *this;
}

// =====================================================================
// TouchAction
// =====================================================================

namespace {
const char* touch_action_to_css_string(uint8_t flags) {
  if (flags == TouchAction::AUTO) return "auto";
  if (flags == TouchAction::NONE) return "none";
  if (flags == TouchAction::MANIPULATION) return "manipulation";

  // For compound values, this is simplified
  if (flags & TouchAction::PAN_X) {
    if (flags & TouchAction::PAN_Y) return "pan-x pan-y";
    if (flags & TouchAction::PINCH_ZOOM) return "pan-x pinch-zoom";
    return "pan-x";
  }
  if (flags & TouchAction::PAN_Y) {
    if (flags & TouchAction::PINCH_ZOOM) return "pan-y pinch-zoom";
    return "pan-y";
  }
  if (flags & TouchAction::PINCH_ZOOM) return "pinch-zoom";
  return "auto";
}
} // anonymous namespace

std::string TouchAction::to_css() const {
  return touch_action_to_css_string(flags_);
}

std::optional<TouchAction> TouchAction::parse(const ParserContext& /*ctx*/, class cssparser::Parser& input) {
  auto token = input.next();
  if (!token) return std::nullopt;

  if (auto* ident = std::get_if<std::string>(&*token)) {
    std::string lower = *ident;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    if (lower == "auto") return TouchAction::auto_val();
    if (lower == "none") return TouchAction::none();
    if (lower == "manipulation") return TouchAction(TouchAction::MANIPULATION);
    if (lower == "pan-x") return TouchAction(TouchAction::PAN_X);
    if (lower == "pan-y") return TouchAction(TouchAction::PAN_Y);
    if (lower == "pinch-zoom") return TouchAction(TouchAction::PINCH_ZOOM);
  }

  return std::nullopt;
}

// =====================================================================
// Contain
// =====================================================================

namespace {
std::string contain_to_css_string(uint8_t flags) {
  if (flags == Contain::NONE) return "none";
  if (flags == Contain::STRICT) return "strict";
  if (flags == Contain::CONTENT) return "content";

  std::ostringstream oss;
  bool first = true;
  auto add = [&](const char* s, uint8_t flag) {
    if (flags & flag) {
      if (!first) oss << " ";
      oss << s;
      first = false;
    }
  };
  add("size", (Contain::INLINE_SIZE | Contain::BLOCK_SIZE));
  add("layout", Contain::LAYOUT);
  add("style", Contain::STYLE);
  add("paint", Contain::PAINT);
  add("inline-size", Contain::INLINE_SIZE);
  return first ? "none" : oss.str();
}
} // anonymous namespace

std::string Contain::to_css() const {
  return contain_to_css_string(flags_);
}

std::optional<Contain> Contain::parse(const ParserContext& /*ctx*/, class cssparser::Parser& input) {
  uint8_t flags = NONE;
  bool parsed_any = false;

  while (true) {
    auto token = input.peek();
    if (!token) break;
    if (auto* ident = std::get_if<std::string>(&*token)) {
      std::string lower = *ident;
      std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

      if (lower == "none") { if (!parsed_any) { input.next(); return Contain(NONE); } break; }
      if (lower == "strict") { if (!parsed_any) { input.next(); return Contain(STRICT); } break; }
      if (lower == "content") { if (!parsed_any) { input.next(); return Contain(CONTENT); } break; }
      if (lower == "size") { flags |= (INLINE_SIZE | BLOCK_SIZE); input.next(); parsed_any = true; continue; }
      if (lower == "layout") { flags |= LAYOUT; input.next(); parsed_any = true; continue; }
      if (lower == "style") { flags |= STYLE; input.next(); parsed_any = true; continue; }
      if (lower == "paint") { flags |= PAINT; input.next(); parsed_any = true; continue; }
      if (lower == "inline-size") { flags |= INLINE_SIZE; input.next(); parsed_any = true; continue; }
    }
    break;
  }
  if (!parsed_any) return std::nullopt;
  return Contain(flags);
}

// =====================================================================
// ContainerName
// =====================================================================

std::string ContainerName::to_css() const {
  if (idents.empty()) return "none";
  std::ostringstream oss;
  for (size_t i = 0; i < idents.size(); ++i) {
    if (i > 0) oss << " ";
    oss << "/* ident */";
  }
  return oss.str();
}

std::optional<ContainerName> ContainerName::parse(const ParserContext& ctx, class cssparser::Parser& input) {
  auto token = input.next();
  if (!token) return std::nullopt;

  if (auto* ident = std::get_if<std::string>(&*token)) {
    std::string lower = *ident;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    if (lower == "none") return ContainerName::none();
  }
  return std::nullopt;
}

ContainerName ContainerName::clone() const {
  return *this;
}

// =====================================================================
// ContainIntrinsicSize
// =====================================================================

ContainIntrinsicSize ContainIntrinsicSize::none() {
  ContainIntrinsicSize c; c.kind = Kind::None; return c;
}

ContainIntrinsicSize ContainIntrinsicSize::auto_none() {
  ContainIntrinsicSize c; c.kind = Kind::AutoNone; return c;
}

ContainIntrinsicSize ContainIntrinsicSize::auto_length(float l) {
  ContainIntrinsicSize c; c.kind = Kind::AutoLength; c.length = l; return c;
}

ContainIntrinsicSize ContainIntrinsicSize::length(float l) {
  ContainIntrinsicSize c; c.kind = Kind::Length; c.length = l; return c;
}

std::string ContainIntrinsicSize::to_css() const {
  switch (kind) {
    case Kind::None: return "none";
    case Kind::AutoNone: return "auto none";
    case Kind::AutoLength: {
      std::ostringstream oss; oss << "auto " << length << "px"; return oss.str();
    }
    case Kind::Length: {
      std::ostringstream oss; oss << length << "px"; return oss.str();
    }
  }
  return "none";
}

std::optional<ContainIntrinsicSize> ContainIntrinsicSize::parse(const ParserContext& /*ctx*/, class cssparser::Parser& input) {
  auto token = input.next();
  if (!token) return std::nullopt;

  if (auto* ident = std::get_if<std::string>(&*token)) {
    std::string lower = *ident;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

    if (lower == "none") return ContainIntrinsicSize::none();
    if (lower == "auto") {
      auto next = input.next();
      if (next && std::holds_alternative<std::string>(*next)) {
        std::string s = std::get<std::string>(*next);
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        if (s == "none") return ContainIntrinsicSize::auto_none();
      }
      // Try to parse as length
      return ContainIntrinsicSize::auto_length(0.0f);
    }
  }

  // Could be a length value
  if (auto* num = std::get_if<float>(&*token)) {
    return ContainIntrinsicSize::length(*num);
  }

  return std::nullopt;
}

// =====================================================================
// LineClamp
// =====================================================================

LineClamp LineClamp::none() {
  LineClamp lc; lc.kind = Kind::None; return lc;
}

LineClamp LineClamp::clamp(int32_t v) {
  LineClamp lc; lc.kind = Kind::Value; lc.value = std::max(1, v); return lc;
}

std::string LineClamp::to_css() const {
  if (kind == Kind::None) return "none";
  return std::to_string(value);
}

std::optional<LineClamp> LineClamp::parse(const ParserContext& /*ctx*/, class cssparser::Parser& input) {
  auto token = input.next();
  if (!token) return std::nullopt;

  if (auto* ident = std::get_if<std::string>(&*token)) {
    std::string lower = *ident;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    if (lower == "none") return LineClamp::none();
    return std::nullopt;
  }

  if (auto* num = std::get_if<float>(&*token)) {
    int32_t val = static_cast<int32_t>(*num);
    if (val > 0) return LineClamp::clamp(val);
  }

  return std::nullopt;
}

// =====================================================================
// DisplayInside helper for list-item validation
// =====================================================================

namespace {
bool display_inside_is_valid_for_list_item(DisplayInside di) {
  switch (di) {
    case DisplayInside::Flow: return true;
    case DisplayInside::FlowRoot: return true;  // Gecko-only
    default: return false;
  }
}

DisplayOutside display_inside_default_outside(DisplayInside di) {
  switch (di) {
    case DisplayInside::Ruby: return DisplayOutside::Inline;
    default: return DisplayOutside::Block;
  }
}
} // anonymous namespace

// =====================================================================
// Test utilities
// =====================================================================

#ifdef BOX_TEST_UTILITIES

namespace test {

bool test_display_constants() {
  assert(Display::None.to_u16() != Display::Block.to_u16());
  assert(Display::Inline.to_u16() != Display::Block.to_u16());
  assert(Display::InlineBlock.to_u16() != Display::Inline.to_u16());
  assert(Display::Flex.to_u16() != Display::Grid.to_u16());
  return true;
}

bool test_display_accessors() {
  assert(Display::Block.outside() == DisplayOutside::Block);
  assert(Display::Block.inside() == DisplayInside::Flow);
  assert(Display::InlineBlock.outside() == DisplayOutside::Inline);
  assert(Display::InlineBlock.inside() == DisplayInside::FlowRoot);
  assert(Display::Flex.outside() == DisplayOutside::Block);
  assert(Display::Flex.inside() == DisplayInside::Flex);
  return true;
}

bool test_display_methods() {
  assert(Display::Block.is_item_container() == false);
  assert(Display::Flex.is_item_container() == true);
  assert(Display::Grid.is_item_container() == true);
  assert(Display::InlineFlex.is_item_container() == true);

  assert(Display::Inline.is_line_participant() == true);
  assert(Display::Block.is_line_participant() == false);

  assert(Display::None.is_none() == true);
  assert(Display::Block.is_none() == false);

  assert(Display::Contents.is_contents() == true);
  assert(Display::Block.is_contents() == false);

  auto list = Display::make3(DisplayOutside::Block, DisplayInside::Flow, true);
  assert(list.is_list_item() == true);

  return true;
}

bool test_display_to_css() {
  assert(Display::None.to_css() == "none");
  assert(Display::Block.to_css() == "block");
  assert(Display::Inline.to_css() == "inline");
  assert(Display::InlineBlock.to_css() == "inline-block");
  assert(Display::Flex.to_css() == "flex");
  assert(Display::Grid.to_css() == "grid");
  assert(Display::Table.to_css() == "table");
  assert(Display::Contents.to_css() == "contents");
  return true;
}

bool test_display_blockify() {
  // inline-block -> block (flow)
  auto blockified = Display::InlineBlock.equivalent_block_display(false);
  assert(blockified.outside() == DisplayOutside::Block);
  assert(blockified.inside() == DisplayInside::Flow);

  // inline-flex -> block flex
  auto blockified_flex = Display::InlineFlex.equivalent_block_display(false);
  assert(blockified_flex.outside() == DisplayOutside::Block);
  assert(blockified_flex.inside() == DisplayInside::Flex);

  // block stays block
  auto blockified_block = Display::Block.equivalent_block_display(false);
  assert(blockified_block == Display::Block);

  // contents on root -> block
  auto root_contents = Display::Contents.equivalent_block_display(true);
  assert(root_contents == Display::Block);

  return true;
}

bool test_scroll_snap_type() {
  auto none = ScrollSnapType::none();
  assert(none.to_css() == "none");

  ScrollSnapType st(ScrollSnapAxis::X, ScrollSnapStrictness::Mandatory);
  assert(st.to_css() == "x mandatory");

  ScrollSnapType st2(ScrollSnapAxis::Both, ScrollSnapStrictness::Proximity);
  assert(st2.to_css() == "both");

  return true;
}

bool test_scroll_snap_align() {
  auto none = ScrollSnapAlign::none();
  assert(none.to_css() == "none");

  ScrollSnapAlign sa(ScrollSnapAlignKeyword::Start, ScrollSnapAlignKeyword::Center);
  assert(sa.to_css() == "start center");

  ScrollSnapAlign sa2(ScrollSnapAlignKeyword::End, ScrollSnapAlignKeyword::End);
  assert(sa2.to_css() == "end");  // Same values, only one serialized

  return true;
}

bool test_touch_action() {
  auto auto_val = TouchAction::auto_val();
  assert(auto_val.to_css() == "auto");

  auto none = TouchAction::none();
  assert(none.to_css() == "none");

  TouchAction pan_x(TouchAction::PAN_X);
  assert(pan_x.to_css() == "pan-x");

  return true;
}

bool test_contain() {
  auto strict = Contain::strict();
  assert(strict.to_css() == "strict");

  auto content = Contain::content();
  assert(content.to_css() == "content");

  auto none = Contain::none();
  assert(none.to_css() == "none");

  Contain layout_paint(Contain::LAYOUT | Contain::PAINT);
  std::string css = layout_paint.to_css();
  assert(css.find("layout") != std::string::npos);
  assert(css.find("paint") != std::string::npos);

  return true;
}

bool test_contain_intrinsic_size() {
  auto none = ContainIntrinsicSize::none();
  assert(none.to_css() == "none");

  auto an = ContainIntrinsicSize::auto_none();
  assert(an.to_css() == "auto none");

  auto al = ContainIntrinsicSize::auto_length(100.0f);
  assert(al.to_css().find("auto") != std::string::npos);

  auto l = ContainIntrinsicSize::length(50.0f);
  assert(l.to_css().find("50") != std::string::npos);

  return true;
}

bool test_line_clamp() {
  auto none = LineClamp::none();
  assert(none.to_css() == "none");

  auto clamp = LineClamp::clamp(3);
  assert(clamp.to_css() == "3");
  assert(clamp.value == 3);

  auto clamp_low = LineClamp::clamp(0);
  assert(clamp_low.value >= 1);  // clamped to minimum 1

  return true;
}

bool test_will_change() {
  auto auto_val = WillChange::auto_val();
  assert(auto_val.is_auto());

  WillChangeBits wcb;
  assert(wcb.is_empty());

  wcb.set(WillChangeBits::TRANSFORM);
  assert(wcb.contains(WillChangeBits::TRANSFORM));
  assert(!wcb.is_empty());

  return true;
}

bool test_container_name() {
  auto none = ContainerName::none();
  assert(none.is_none());
  assert(none.to_css() == "none");

  return true;
}

void run_all_tests() {
  bool pass = true;
  pass &= test_display_constants();
  pass &= test_display_accessors();
  pass &= test_display_methods();
  pass &= test_display_to_css();
  pass &= test_display_blockify();
  pass &= test_scroll_snap_type();
  pass &= test_scroll_snap_align();
  pass &= test_touch_action();
  pass &= test_contain();
  pass &= test_contain_intrinsic_size();
  pass &= test_line_clamp();
  pass &= test_will_change();
  pass &= test_container_name();

  if (pass) {
    std::cout << "All box specified tests passed!" << std::endl;
  } else {
    std::cerr << "Some box specified tests failed!" << std::endl;
  }
}

} // namespace test
#endif // BOX_TEST_UTILITIES

} // namespace style::values::specified
