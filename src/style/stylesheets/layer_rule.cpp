/* MPL 2.0 */
//! @layer rule: cascade layers per CSS Cascading Level 5.
//! https://drafts.csswg.org/css-cascade-5/#layering
#include "style/stylesheets/layer_rule.hpp"
#include <algorithm>

namespace style { namespace stylesheets {

LayerRule::LayerRule() = default;
LayerRule::~LayerRule() = default;

void LayerRule::add_name_segment(const std::string& segment) {
    layer_names_.push_back(segment);
}

std::string LayerRule::full_name() const {
    if (layer_names_.empty()) return "";
    std::ostringstream oss;
    for (size_t i = 0; i < layer_names_.size(); ++i) {
        if (i > 0) oss << ".";
        oss << layer_names_[i];
    }
    return oss.str();
}

void LayerRule::add_rule(std::unique_ptr<CssRule> rule) {
    rules_.push_back(std::move(rule));
}

const std::vector<std::string>& LayerRule::layer_names() const { return layer_names_; }
const std::vector<std::unique_ptr<CssRule>>& LayerRule::rules() const { return rules_; }

void LayerRule::to_css(std::ostream& dest) const {
    dest << "@layer " << full_name() << " {\n";
    for (const auto& rule : rules_) {
        rule->to_css(dest);
        dest << "\n";
    }
    dest << "}";
}

bool LayerRule::is_unnamed() const { return layer_names_.empty(); }
size_t LayerRule::rule_count() const { return rules_.size(); }
bool LayerRule::empty() const { return rules_.empty(); }

// Layer order resolution
int LayerRule::compare_layer_order(const LayerRule& a, const LayerRule& b) {
    // Compare layer name segments lexicographically
    size_t min_len = std::min(a.layer_names_.size(), b.layer_names_.size());
    for (size_t i = 0; i < min_len; ++i) {
        int cmp = a.layer_names_[i].compare(b.layer_names_[i]);
        if (cmp != 0) return cmp;
    }
    // Shorter name = more general = higher priority for unlayered styles
    if (a.layer_names_.size() != b.layer_names_.size()) {
        return a.layer_names_.size() < b.layer_names_.size() ? 1 : -1;
    }
    return 0;
}

// Layer statement: @layer name1, name2; (establishes layer order without rules)
void LayerStatementRule::set_layer_names(const std::vector<std::string>& names) {
    layer_names_ = names;
}

void LayerStatementRule::to_css(std::ostream& dest) const {
    dest << "@layer ";
    for (size_t i = 0; i < layer_names_.size(); ++i) {
        if (i > 0) dest << ", ";
        dest << layer_names_[i];
    }
    dest << ";";
}

#ifdef STYLE_TEST
bool test_layer_rule() {
    LayerRule rule;
    rule.add_name_segment("framework");
    rule.add_name_segment("theme");
    assert(rule.full_name() == "framework.theme");
    assert(!rule.is_unnamed());
    
    LayerRule empty_layer;
    assert(empty_layer.is_unnamed());
    assert(empty_layer.empty());
    
    return true;
}
#endif

}} // namespace
