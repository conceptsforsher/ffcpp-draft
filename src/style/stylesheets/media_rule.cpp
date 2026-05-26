/* MPL 2.0 */
//! @media rule implementation: media query evaluation, conditional rule application.
//! https://drafts.csswg.org/css-conditional-3/#at-media
#include "style/stylesheets/media_rule.hpp"
#include <algorithm>
#include <sstream>

namespace style { namespace stylesheets {

MediaRule::MediaRule() = default;
MediaRule::~MediaRule() = default;

void MediaRule::set_condition(const std::string& condition) {
    condition_text_ = condition;
    // Parse media query list: split on commas
    queries_.clear();
    std::istringstream iss(condition);
    std::string token;
    while (std::getline(iss, token, ',')) {
        // Trim whitespace
        size_t start = token.find_first_not_of(" \t\n\r");
        size_t end = token.find_last_not_of(" \t\n\r");
        if (start != std::string::npos) {
            token = token.substr(start, end - start + 1);
            queries_.push_back(token);
        }
    }
    condition_text_ = condition;
}

bool MediaRule::evaluate(const MediaEvaluationContext& ctx) const {
    if (queries_.empty()) return true;  // No condition = matches all
    for (const auto& query : queries_) {
        if (evaluate_single_query(query, ctx)) return true;
    }
    return false;
}

bool MediaRule::evaluate_single_query(const std::string& query, const MediaEvaluationContext& ctx) const {
    // Handle "all", "screen", "print" media types
    if (query == "all") return true;
    if (query == "screen" && !ctx.is_print) return true;
    if (query == "print" && ctx.is_print) return true;
    
    // Handle width/height features: (min-width: Npx), (max-width: Npx)
    if (query.find("min-width:") != std::string::npos) {
        float val = extract_pixel_value(query);
        return ctx.viewport_width >= val;
    }
    if (query.find("max-width:") != std::string::npos) {
        float val = extract_pixel_value(query);
        return ctx.viewport_width <= val;
    }
    if (query.find("min-height:") != std::string::npos) {
        float val = extract_pixel_value(query);
        return ctx.viewport_height >= val;
    }
    if (query.find("max-height:") != std::string::npos) {
        float val = extract_pixel_value(query);
        return ctx.viewport_height <= val;
    }
    
    // Handle orientation
    if (query == "orientation: portrait") return ctx.viewport_height >= ctx.viewport_width;
    if (query == "orientation: landscape") return ctx.viewport_width > ctx.viewport_height;
    
    // Handle aspect-ratio
    if (query.find("aspect-ratio:") != std::string::npos) {
        // Simplified: always match
        return true;
    }
    
    // Handle resolution
    if (query.find("resolution:") != std::string::npos || query.find("min-resolution:") != std::string::npos) {
        return true;  // Simplified
    }
    
    // Handle prefers-color-scheme
    if (query == "prefers-color-scheme: dark") return ctx.prefers_dark_mode;
    if (query == "prefers-color-scheme: light") return !ctx.prefers_dark_mode;
    
    // Handle prefers-reduced-motion
    if (query == "prefers-reduced-motion: reduce") return ctx.prefers_reduced_motion;
    if (query == "prefers-reduced-motion: no-preference") return !ctx.prefers_reduced_motion;
    
    // Handle prefers-contrast
    if (query == "prefers-contrast: high") return ctx.prefers_high_contrast;
    if (query == "prefers-contrast: no-preference") return !ctx.prefers_high_contrast;
    
    // Handle hover/pointer
    if (query == "hover: hover") return ctx.has_hover;
    if (query == "hover: none") return !ctx.has_hover;
    if (query == "pointer: fine") return ctx.has_fine_pointer;
    if (query == "pointer: coarse") return !ctx.has_fine_pointer;
    
    // Handle display-mode
    if (query == "display-mode: fullscreen") return ctx.is_fullscreen;
    if (query == "display-mode: standalone") return ctx.is_standalone;
    
    // Default: match if we don't understand the feature
    return true;
}

float MediaRule::extract_pixel_value(const std::string& query) const {
    // Extract numeric value from "(min-width: 768px)"
    size_t colon = query.find(':');
    if (colon == std::string::npos) return 0.0f;
    std::string val_part = query.substr(colon + 1);
    // Remove "px", spaces, and closing paren
    size_t px = val_part.find("px");
    if (px != std::string::npos) val_part = val_part.substr(0, px);
    // Trim
    size_t start = val_part.find_first_not_of(" \t");
    size_t end = val_part.find_last_not_of(" )\t");
    if (start != std::string::npos && end != std::string::npos) {
        val_part = val_part.substr(start, end - start + 1);
    }
    try {
        return std::stof(val_part);
    } catch (...) {
        return 0.0f;
    }
}

void MediaRule::add_rule(std::unique_ptr<CssRule> rule) {
    rules_.push_back(std::move(rule));
}

const std::vector<std::unique_ptr<CssRule>>& MediaRule::rules() const {
    return rules_;
}

void MediaRule::to_css(std::ostream& dest) const {
    dest << "@media " << condition_text_ << " {\n";
    for (const auto& rule : rules_) {
        rule->to_css(dest);
        dest << "\n";
    }
    dest << "}";
}

size_t MediaRule::rule_count() const { return rules_.size(); }
bool MediaRule::empty() const { return rules_.empty(); }

// Tests
#ifdef STYLE_TEST
bool test_media_rule() {
    MediaRule rule;
    rule.set_condition("screen and (min-width: 768px)");
    
    MediaEvaluationContext ctx;
    ctx.viewport_width = 1024;
    ctx.viewport_height = 768;
    ctx.is_print = false;
    assert(rule.evaluate(ctx));
    
    ctx.viewport_width = 320;
    assert(!rule.evaluate(ctx));
    
    MediaRule empty_rule;
    assert(empty_rule.evaluate(ctx));  // Empty condition = all
    
    return true;
}
#endif

}} // namespace
