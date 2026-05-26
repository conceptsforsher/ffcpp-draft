/* MPL 2.0 */
//! Specified box model values: display, overflow, visibility, etc.
#pragma once
#include <string>
#include <cstdint>

namespace style { namespace values { namespace specified {

enum class DisplayType : uint8_t {
    None, Contents, Block, Inline, InlineBlock, Flex, InlineFlex, Grid, InlineGrid,
    Table, InlineTable, TableRowGroup, TableHeaderGroup, TableFooterGroup,
    TableRow, TableCell, TableColumnGroup, TableColumn, TableCaption,
    ListItem, FlowRoot, Ruby, RubyBase, RubyText, WebkitBox, WebkitInlineBox,
};

enum class Overflow : uint8_t { Visible, Hidden, Clip, Scroll, Auto };
enum class Visibility : uint8_t { Visible, Hidden, Collapse };
enum class BoxSizing : uint8_t { ContentBox, BorderBox };
enum class Float : uint8_t { None, Left, Right };
enum class Clear : uint8_t { None, Left, Right, Both };
enum class Resize : uint8_t { None, Both, Horizontal, Vertical };
enum class ScrollSnapType : uint8_t { None, Mandatory, Proximity };
enum class OverscrollBehavior : uint8_t { Auto, Contain, None };

struct Display {
    DisplayType type = DisplayType::Inline;
    bool is_none() const { return type == DisplayType::None; }
    bool is_block() const { return type == DisplayType::Block; }
    bool is_flex() const { return type == DisplayType::Flex || type == DisplayType::InlineFlex; }
    bool is_grid() const { return type == DisplayType::Grid || type == DisplayType::InlineGrid; }
};

}}} // namespace
