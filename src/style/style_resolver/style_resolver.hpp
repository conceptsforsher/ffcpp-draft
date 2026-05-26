/* MPL 2.0 */
//! Style resolver — resolves computed styles for elements.
//! Corresponds to style_resolver.rs (699 lines)
#pragma once
#include <memory>
#include "style/context/context.hpp"

namespace style {

class GeckoElement;
struct ComputedValues;
class CascadeData;

/// Resolves styles for elements: matches selectors, cascades declarations,
/// computes values, and handles inheritance.
class StyleResolver {
public:
    explicit StyleResolver(const StyleContext& context);

    /// Resolve style for an element.
    /// Returns the computed values (either computed fresh or shared from cache).
    const ComputedValues* resolve_style(const GeckoElement& element);

    /// Resolve style for a pseudo-element.
    const ComputedValues* resolve_pseudo_style(const GeckoElement& element,
                                                PseudoElement pseudo);

    /// Get the current style context.
    const StyleContext& context() const { return context_; }

private:
    StyleContext context_;

    /// Match selectors against an element to find applicable declarations.
    void match_selectors(const GeckoElement& element,
                         std::vector<CascadedProperty>& result);

    /// Cascade declarations to find winning values.
    void cascade(const std::vector<CascadedProperty>& declarations,
                 ComputedValues& result);

    /// Apply default (initial + inherited) values.
    void apply_defaults(ComputedValues& result);

    /// Compute specified values to computed values.
    void compute_values(const GeckoElement& element, ComputedValues& result);

    /// Resolve inheritance: propagate parent values to child.
    void inherit_from_parent(const GeckoElement& element, ComputedValues& result);
};

} // namespace style
