/* MPL 2.0 */
//! Logical geometry: WritingMode-aware dimensions for CSS layout.
//! Maps physical directions (top/right/bottom/left) to logical
//! (block-start/inline-end/block-end/inline-start) based on writing mode.
//!
//! Corresponds to servo/components/style/logical_geometry.rs (1672 lines)
#pragma once
#include <cstdint>
#include <string>

namespace style {

/// CSS Writing Mode.
/// https://drafts.csswg.org/css-writing-modes-4/
enum class WritingMode : uint8_t {
    HorizontalTb = 0,  // horizontal-tb (default, Latin-like)
    VerticalRl,         // vertical-rl (Japanese-like)
    VerticalLr,         // vertical-lr (Mongolian-like)
    SidewaysRl,         // sideways-rl
    SidewaysLr,         // sideways-lr
};

inline const char* writing_mode_name(WritingMode wm) {
    switch (wm) {
        case WritingMode::HorizontalTb: return "horizontal-tb";
        case WritingMode::VerticalRl:   return "vertical-rl";
        case WritingMode::VerticalLr:   return "vertical-lr";
        case WritingMode::SidewaysRl:   return "sideways-rl";
        case WritingMode::SidewaysLr:   return "sideways-lr";
    }
    return "horizontal-tb";
}

/// Text direction.
enum class TextDirection : uint8_t { Ltr = 0, Rtl = 1 };

enum class LogicalSide : uint8_t {
    BlockStart = 0, BlockEnd, InlineStart, InlineEnd
};

enum class PhysicalSide : uint8_t {
    Top = 0, Right, Bottom, Left
};

/// Convert a logical side to physical side based on writing mode.
inline PhysicalSide logical_to_physical(LogicalSide side, WritingMode wm, TextDirection dir) {
    if (wm == WritingMode::HorizontalTb) {
        // Normal horizontal layout
        switch (side) {
            case LogicalSide::BlockStart:  return PhysicalSide::Top;
            case LogicalSide::BlockEnd:    return PhysicalSide::Bottom;
            case LogicalSide::InlineStart: return dir == TextDirection::Ltr ? PhysicalSide::Left : PhysicalSide::Right;
            case LogicalSide::InlineEnd:   return dir == TextDirection::Ltr ? PhysicalSide::Right : PhysicalSide::Left;
        }
    } else {
        // Vertical layout
        switch (side) {
            case LogicalSide::BlockStart:  return wm == WritingMode::VerticalLr ? PhysicalSide::Left : PhysicalSide::Right;
            case LogicalSide::BlockEnd:    return wm == WritingMode::VerticalLr ? PhysicalSide::Right : PhysicalSide::Left;
            case LogicalSide::InlineStart: return PhysicalSide::Top;
            case LogicalSide::InlineEnd:   return PhysicalSide::Bottom;
        }
    }
    return PhysicalSide::Top;
}

/// Margin represented in logical (writing-mode-relative) coordinates.
struct LogicalMargin {
    float block_start = 0.0f;
    float inline_end = 0.0f;
    float block_end = 0.0f;
    float inline_start = 0.0f;
    
    LogicalMargin() = default;
    LogicalMargin(float bs, float ie, float be, float is_)
        : block_start(bs), inline_end(ie), block_end(be), inline_start(is_) {}
    
    /// Set all sides to the same value.
    static LogicalMargin all(float v) { return {v, v, v, v}; }
    
    /// Zero margin.
    static LogicalMargin zero() { return {}; }
    
    /// Convert to physical margin for a given writing mode.
    struct PhysicalMargin { float top, right, bottom, left; };
    
    PhysicalMargin to_physical(WritingMode wm, TextDirection dir) const {
        PhysicalMargin pm = {};
        if (wm == WritingMode::HorizontalTb) {
            pm.top = block_start;
            pm.bottom = block_end;
            if (dir == TextDirection::Ltr) { pm.left = inline_start; pm.right = inline_end; }
            else { pm.left = inline_end; pm.right = inline_start; }
        } else {
            if (wm == WritingMode::VerticalLr) { pm.left = block_start; pm.right = block_end; }
            else { pm.right = block_start; pm.left = block_end; }
            pm.top = inline_start;
            pm.bottom = inline_end;
        }
        return pm;
    }
    
    /// Sum all sides.
    float block_sum() const { return block_start + block_end; }
    float inline_sum() const { return inline_start + inline_end; }
    float total() const { return block_sum() + inline_sum(); }
    
    LogicalMargin operator+(const LogicalMargin& o) const { return {block_start+o.block_start, inline_end+o.inline_end, block_end+o.block_end, inline_start+o.inline_start}; }
    LogicalMargin& operator+=(const LogicalMargin& o) { block_start+=o.block_start; inline_end+=o.inline_end; block_end+=o.block_end; inline_start+=o.inline_start; return *this; }
};

struct LogicalSize {
    float block_size = 0.0f;   // height in horizontal mode
    float inline_size = 0.0f;  // width in horizontal mode
    
    LogicalSize() = default;
    LogicalSize(float b, float i) : block_size(b), inline_size(i) {}
    static LogicalSize zero() { return {}; }
    bool is_zero() const { return block_size == 0.0f && inline_size == 0.0f; }
};

struct LogicalPoint {
    float block_offset = 0.0f;
    float inline_offset = 0.0f;
    LogicalPoint() = default;
    LogicalPoint(float b, float i) : block_offset(b), inline_offset(i) {}
};

struct LogicalRect {
    LogicalPoint origin;
    LogicalSize size;
    
    LogicalRect() = default;
    LogicalRect(LogicalPoint o, LogicalSize s) : origin(o), size(s) {}
    
    float block_start() const { return origin.block_offset; }
    float block_end() const { return origin.block_offset + size.block_size; }
    float inline_start() const { return origin.inline_offset; }
    float inline_end() const { return origin.inline_offset + size.inline_size; }
    
    bool contains(const LogicalPoint& p) const {
        return p.block_offset >= block_start() && p.block_offset < block_end() &&
               p.inline_offset >= inline_start() && p.inline_offset < inline_end();
    }
};

/// Writing mode with direction, for resolving logical properties.
struct ComputedWritingMode {
    WritingMode writing_mode = WritingMode::HorizontalTb;
    TextDirection direction = TextDirection::Ltr;
    
    bool is_horizontal() const { return writing_mode == WritingMode::HorizontalTb; }
    bool is_vertical() const { return !is_horizontal(); }
    bool is_ltr() const { return direction == TextDirection::Ltr; }
    bool is_rtl() const { return !is_ltr(); }
    
    PhysicalSide to_physical(LogicalSide side) const { return logical_to_physical(side, writing_mode, direction); }
};

} // namespace style