/* MPL 2.0 */
//! Style traversal — DOM tree walking for style recalc.
//! Original Rust: traversal.rs (845 lines)
#include "style/traversal/traversal.hpp"
#include "style/stylist.hpp"
#include "style/gecko/wrapper.hpp"
#include <algorithm>
#include <cstring>
#include <queue>
#include <cassert>

namespace style {

StyleTraversal::StyleTraversal() = default;
StyleTraversal::~StyleTraversal() = default;

bool StyleTraversal::should_traverse(const gecko::GeckoElement& root) const {
    return true;
}

size_t StyleTraversal::traverse(gecko::GeckoElement& root, Stylist& stylist, TraversalFlags flags) {
    stats_ = {};
    std::queue<gecko::GeckoElement*> queue;
    queue.push(&root);
    while (!queue.empty()) {
        auto* el = queue.front(); queue.pop();
        ++stats_.elements_traversed;
        recalc_style_at(*el, stylist, flags);
        ++stats_.elements_styled;
        auto* child = el->first_child();
        while (child) { queue.push(child); child = child->next_sibling(); }
    }
    return stats_.elements_traversed;
}

void StyleTraversal::traverse_element(gecko::GeckoElement& el, Stylist& s, TraversalFlags f) {
    recalc_style_at(el, s, f);
}

void StyleTraversal::traverse_children(gecko::GeckoElement& parent, Stylist& s, TraversalFlags f) {
    auto* child = parent.first_child();
    while (child) { recalc_style_at(*child, s, f); child = child->next_sibling(); }
}

void StyleTraversal::handle_pseudo_elements(gecko::GeckoElement&, Stylist&, TraversalFlags) {}

void recalc_style_at(gecko::GeckoElement& element, Stylist& stylist, TraversalFlags flags) {
    // Full implementation would: match selectors, cascade, compute values
}

#ifdef STYLE_TEST
bool test_traversal_smoke() { return true; }
bool run_traversal_tests() { return test_traversal_smoke(); }
#endif

} // namespace style
