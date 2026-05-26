/* MPL 2.0 */
//! Style traversal — DOM tree walking for style recalc.
#pragma once
#include <cstdint>
#include <functional>

namespace style {

namespace gecko { class GeckoElement; }
class Stylist;

struct TraversalFlags {
    bool for_animation_only = false;
    bool for_reconstruct = false;
    enum Behavior : uint8_t { Normal, UnstyledOnly };
    Behavior behavior = Normal;
    static TraversalFlags normal() { return {}; }
};

class StyleTraversal {
public:
    StyleTraversal();~StyleTraversal();
    size_t traverse(gecko::GeckoElement& root, Stylist& stylist, TraversalFlags flags);
    void traverse_element(gecko::GeckoElement& el, Stylist& s, TraversalFlags f);
    bool should_traverse(const gecko::GeckoElement& root) const;
    struct Stats { size_t elements_traversed=0, elements_styled=0; };
    const Stats& stats() const { return stats_; }
private:
    Stats stats_;
    void traverse_children(gecko::GeckoElement& p, Stylist& s, TraversalFlags f);
    void handle_pseudo_elements(gecko::GeckoElement& el, Stylist& s, TraversalFlags f);
};

void recalc_style_at(gecko::GeckoElement& element, Stylist& stylist, TraversalFlags flags);

} // namespace style
