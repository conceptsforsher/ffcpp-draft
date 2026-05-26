/* MPL 2.0 */
//! CSS Selector parser types.
//! Minimal types needed for selector matching in the style system.
#pragma once
#include <string>
#include <vector>
#include <cstdint>

namespace style {

/// Pseudo-element types
enum class PseudoElement : uint16_t {
    None = 0, Before, After, Marker, Backdrop, Selection,
    FirstLine, FirstLetter, Placeholder, Cue, FileSelectorButton,
    Highlight, TargetText
};

/// Selector implementation type (placeholder for full parser)
struct SelectorImpl {
    std::string text;
    uint32_t specificity = 0;
};

} // namespace style
