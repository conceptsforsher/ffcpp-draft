/* MPL 2.0 */
//! Specified grid layout values.
//! Covers various grid-related specified value types.
#pragma once
#include <string>
#include <vector>
#include <variant>
#include "style/values/specified/length.hpp"

namespace style { namespace values { namespace specified {

using NonNegativeLengthPercentage = generics::grid::GridTrackSize; // simplified

enum class GridAutoFlow : uint8_t { Row, Column, RowDense, ColumnDense };

struct GridTemplateColumns { std::vector<GridTrackSize> tracks; bool is_none=true; };
struct GridTemplateRows { std::vector<GridTrackSize> tracks; bool is_none=true; };
struct GridAutoColumns { std::vector<GridTrackSize> tracks; };
struct GridAutoRows { std::vector<GridTrackSize> tracks; };

struct GridLine {
    int32_t line_num = 0;  // 0 = auto
    std::string ident;
    bool is_span = false;
};

struct GridArea {
    GridLine row_start, row_end, column_start, column_end;
};

}}} // namespace
