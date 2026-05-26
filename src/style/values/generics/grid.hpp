/* MPL 2.0 */
//! Generic CSS grid values.
//! Corresponds to values/generics/grid.rs (877 lines)
#pragma once
#include <string>
#include <vector>
#include <variant>
#include "style/values/specified/length.hpp"

namespace style { namespace values { namespace generics { namespace grid {

using specified::NonNegativeLengthPercentage;

enum class GridTrackSizeType : uint8_t { Fixed, Flexible, MinContent, MaxContent, Auto, MinMax, FitContent };

struct GridTrackSize {
    GridTrackSizeType type = GridTrackSizeType::Auto;
    NonNegativeLengthPercentage fixed_size;
    float flex_factor = 0.0f;  // for fr units
};

struct TrackBreadth { GridTrackSize size; };
struct TrackListValue { std::vector<TrackBreadth> tracks; };
struct AutoTrackList { std::vector<TrackBreadth> auto_tracks; };

enum class GridLine : int32_t { Auto = -1 };

struct GenericGridLine {
    int32_t line_num = 0;  // 0 = auto
    std::string ident;
    bool is_span = false;
};

struct GridTemplateAreas {
    std::vector<std::string> areas;
};

struct GridAutoFlow {
    bool row = true;
    bool dense = false;
};

}}}} // namespace
