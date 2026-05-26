/* MPL 2.0 */
//! Shared style context — per-document global state for style computation.
//! Corresponds to context.rs (654 lines)
#pragma once
#include <memory>
#include <string>
#include "style/values/specified/length.hpp"
#include "style/stylist.hpp"

namespace style {

class Stylist;
class StyleSharingCache;
struct ComputedValues;
class RuleTree;

/// Shared style context — holds references to global state needed
/// during style computation (stylist, caches, device info, etc.).
struct SharedStyleContext {
    Stylist* stylist = nullptr;
    StyleSharingCache* sharing_cache = nullptr;
    RuleTree* rule_tree = nullptr;

    // Viewport / device
    int viewport_width = 1920;
    int viewport_height = 1080;
    float device_pixel_ratio = 1.0f;

    // Document state
    bool is_html_document = true;
    int quirks_mode = 0;  // 0=standards, 1=limited, 2=quirks

    // Font info
    float default_font_size = 16.0f;
    float root_font_size = 16.0f;

    // Flags
    bool is_print_preview = false;
    bool for_reconstruct = false;
    bool animations_enabled = true;
    bool transitions_enabled = true;

    // Current time for animations
    double current_time_seconds = 0.0;

    SharedStyleContext() = default;
};

/// Per-element style context — holds element-specific state during
/// style computation (parent style, layout info, etc.).
struct StyleContext {
    const SharedStyleContext* shared = nullptr;
    const ComputedValues* parent_style = nullptr;
    const ComputedValues* default_style = nullptr;
    bool is_root_element = false;
    RuleInclusion rule_inclusion = RuleInclusion::All;

    StyleContext() = default;
    StyleContext(const SharedStyleContext& s, const ComputedValues* parent)
        : shared(&s), parent_style(parent) {}
};

} // namespace style
