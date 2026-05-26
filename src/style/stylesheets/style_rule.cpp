/* MPL 2.0 */
//! Style rule (selector { declarations }) implementation.
//! The core of CSS: matching selectors against DOM elements.
#include "style/stylesheets/style_rule.hpp"
#include <algorithm>
#include <sstream>

namespace style { namespace stylesheets {

StyleRule::StyleRule() = default;
StyleRule::~StyleRule() = default;

void StyleRule::set_selector_text(const std::string& selector_text) {
    selector_text_ = selector_text;
    parse_selectors(selector_text);
}

void StyleRule::parse_selectors(const std::string& text) {
    selectors_.clear();
    // Split on comma for selector lists
    std::istringstream iss(text);
    std::string selector;
    int depth = 0;
    std::string current;
    for (char c : text) {
        if (c == '(' || c == '[') depth++;
        else if (c == ')' || c == ']') depth--;
        if (c == ',' && depth == 0) {
            selectors_.push_back(trim(current));
            current.clear();
        } else {
            current += c;
        }
    }
    if (!current.empty()) selectors_.push_back(trim(current));
    
    // Compute specificity for each selector
    specificities_.clear();
    for (const auto& sel : selectors_) {
        specificities_.push_back(compute_specificity(sel));
    }
}

Specificity StyleRule::compute_specificity(const std::string& selector) const {
    Specificity spec = {0, 0, 0};
    int depth = 0;
    bool in_attr = false;
    std::string simple;
    
    for (size_t i = 0; i < selector.size(); ++i) {
        char c = selector[i];
        if (c == '(') { depth++; continue; }
        if (c == ')') { depth--; continue; }
        if (depth > 0) continue;  // Skip attribute value content
        
        if (c == '#') {
            spec.a++;  // ID selector
            // Skip the ID name
            while (i + 1 < selector.size() && 
                   (std::isalnum(selector[i+1]) || selector[i+1] == '-' || selector[i+1] == '_')) {
                i++;
            }
        } else if (c == '.') {
            spec.b++;  // Class selector
            while (i + 1 < selector.size() && 
                   (std::isalnum(selector[i+1]) || selector[i+1] == '-' || selector[i+1] == '_')) {
                i++;
            }
        } else if (c == ':') {
            spec.b++;  // Pseudo-class
            // Skip pseudo-class name
            while (i + 1 < selector.size() && 
                   (std::isalnum(selector[i+1]) || selector[i+1] == '-')) {
                i++;
            }
        } else if (c == '[') {
            spec.b++;  // Attribute selector
            // Skip to closing bracket
            int bracket_depth = 1;
            while (i + 1 < selector.size() && bracket_depth > 0) {
                i++;
                if (selector[i] == '[') bracket_depth++;
                if (selector[i] == ']') bracket_depth--;
            }
        }
    }
    
    // Count tag/element names (any alphabetic sequence not preceded by . # : [)
    bool in_tag = false;
    for (char c : selector) {
        if (c == '#' || c == '.' || c == ':' || c == '[' || c == ' ' || c == '>' || c == '+' || c == '~') {
            if (in_tag) { spec.c++; in_tag = false; }
        } else if (std::isalpha(c) || c == '*') {
            in_tag = true;
        }
    }
    if (in_tag) spec.c++;
    
    // For :is(), :not(), :has(), :where(): use the most specific argument
    if (selector.find(":is(") != std::string::npos || 
        selector.find(":not(") != std::string::npos ||
        selector.find(":has(") != std::string::npos) {
        // Simplified: add one pseudo-class specificity
        spec.b++;
    }
    
    return spec;
}

uint32_t Specificity::to_u32() const {
    return (static_cast<uint32_t>(a) << 16) |
           (static_cast<uint32_t>(b) << 8) |
           static_cast<uint32_t>(c);
}

bool Specificity::operator<(const Specificity& other) const {
    if (a != other.a) return a < other.a;
    if (b != other.b) return b < other.b;
    return c < other.c;
}

bool Specificity::operator==(const Specificity& other) const {
    return a == other.a && b == other.b && c == other.c;
}

void StyleRule::set_declarations(PropertyDeclarationBlock block) {
    declarations_ = std::move(block);
}

const std::vector<std::string>& StyleRule::selectors() const { return selectors_; }
const std::string& StyleRule::selector_text() const { return selector_text_; }
const PropertyDeclarationBlock& StyleRule::declarations() const { return declarations_; }
const std::vector<Specificity>& StyleRule::specificities() const { return specificities_; }

Specificity StyleRule::max_specificity() const {
    Specificity max_spec = {0, 0, 0};
    for (const auto& spec : specificities_) {
        if (max_spec < spec) max_spec = spec;
    }
    return max_spec;
}

std::string StyleRule::trim(const std::string& s) {
    size_t start = s.find_first_not_of(" \t\n\r");
    size_t end = s.find_last_not_of(" \t\n\r");
    if (start == std::string::npos) return "";
    return s.substr(start, end - start + 1);
}

void StyleRule::to_css(std::ostream& dest) const {
    dest << selector_text_ << " {\n";
    declarations_.to_css(dest);
    dest << "\n}";
}

#ifdef STYLE_TEST
bool test_style_rule() {
    StyleRule rule;
    
    // Test specificity
    auto spec = rule.compute_specificity("div#main.content:hover");
    assert(spec.a == 1);  // #main
    assert(spec.b >= 2);  // .content + :hover
    
    auto spec2 = rule.compute_specificity("*");
    assert(spec2.a == 0 && spec2.b == 0);
    
    // Test selector list parsing
    rule.set_selector_text("h1, h2, h3");
    assert(rule.selectors().size() == 3);
    
    return true;
}
#endif

}} // namespace
