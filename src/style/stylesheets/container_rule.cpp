/* MPL 2.0 */
//! @container rule: container queries per CSS Containment Level 3.
//! https://drafts.csswg.org/css-contain-3/#container-rule
#include "style/stylesheets/container_rule.hpp"
#include <algorithm>

namespace style { namespace stylesheets {

ContainerRule::ContainerRule() = default;
ContainerRule::~ContainerRule() = default;

void ContainerRule::set_container_name(const std::string& name) {
    container_name_ = name;
    has_name_ = !name.empty();
}

void ContainerRule::set_condition(const std::string& condition) {
    condition_text_ = condition;
    parse_condition();
}

void ContainerRule::parse_condition() {
    queries_.clear();
    // Parse size queries: (min-width: Npx), (max-width: Npx), etc.
    std::string cond = condition_text_;
    // Remove whitespace
    auto trim = [](std::string& s) {
        size_t start = s.find_first_not_of(" \t\n\r");
        size_t end = s.find_last_not_of(" \t\n\r");
        if (start != std::string::npos && end != std::string::npos) {
            s = s.substr(start, end - start + 1);
        }
    };
    trim(cond);
    
    // Split on "and"
    std::vector<std::string> parts;
    size_t pos = 0;
    while ((pos = cond.find(" and ")) != std::string::npos) {
        parts.push_back(cond.substr(0, pos));
        cond = cond.substr(pos + 5);
    }
    parts.push_back(cond);
    
    for (auto& part : parts) {
        trim(part);
        ContainerQuery q;
        if (part.find("min-width:") != std::string::npos) {
            q.type = ContainerQuery::MIN_WIDTH;
            q.value = extract_value(part);
        } else if (part.find("max-width:") != std::string::npos) {
            q.type = ContainerQuery::MAX_WIDTH;
            q.value = extract_value(part);
        } else if (part.find("min-height:") != std::string::npos) {
            q.type = ContainerQuery::MIN_HEIGHT;
            q.value = extract_value(part);
        } else if (part.find("max-height:") != std::string::npos) {
            q.type = ContainerQuery::MAX_HEIGHT;
            q.value = extract_value(part);
        } else if (part.find("orientation:") != std::string::npos) {
            q.type = ContainerQuery::ORIENTATION;
            q.orientation_portrait = (part.find("portrait") != std::string::npos);
        } else if (part.find("aspect-ratio:") != std::string::npos) {
            q.type = ContainerQuery::ASPECT_RATIO;
            q.aspect = parse_aspect_ratio(part);
        } else if (part.find("inline-size:") != std::string::npos) {
            q.type = ContainerQuery::INLINE_SIZE;
            q.value = extract_value(part);
        } else if (part.find("block-size:") != std::string::npos) {
            q.type = ContainerQuery::BLOCK_SIZE;
            q.value = extract_value(part);
        } else {
            q.type = ContainerQuery::STYLE;  // Style query
        }
        queries_.push_back(q);
    }
}

float ContainerRule::extract_value(const std::string& condition) const {
    size_t colon = condition.find(':');
    if (colon == std::string::npos) return 0.0f;
    std::string val = condition.substr(colon + 1);
    size_t px = val.find("px");
    if (px != std::string::npos) val = val.substr(0, px);
    auto trim = [](std::string& s) {
        size_t start = s.find_first_not_of(" ()");
        size_t end = s.find_last_not_of(" ()");
        if (start != std::string::npos && end != std::string::npos) s = s.substr(start, end - start + 1);
    };
    trim(val);
    try { return std::stof(val); } catch (...) { return 0.0f; }
}

float ContainerRule::parse_aspect_ratio(const std::string& cond) const {
    size_t colon = cond.find(':');
    if (colon == std::string::npos) return 1.0f;
    std::string ratio = cond.substr(colon + 1);
    auto trim = [](std::string& s) {
        size_t start = s.find_first_not_of(" ()");
        size_t end = s.find_last_not_of(" ()");
        if (start != std::string::npos && end != std::string::npos) s = s.substr(start, end - start + 1);
    };
    trim(ratio);
    size_t slash = ratio.find('/');
    if (slash != std::string::npos) {
        try {
            float num = std::stof(ratio.substr(0, slash));
            float den = std::stof(ratio.substr(slash + 1));
            return den != 0.0f ? num / den : 1.0f;
        } catch (...) {}
    }
    try { return std::stof(ratio); } catch (...) { return 1.0f; }
}

bool ContainerRule::evaluate(const ContainerContext& ctx) const {
    for (const auto& q : queries_) {
        if (!evaluate_query(q, ctx)) return false;
    }
    return true;
}

bool ContainerRule::evaluate_query(const ContainerQuery& q, const ContainerContext& ctx) const {
    switch (q.type) {
        case ContainerQuery::MIN_WIDTH:
            return ctx.inline_size >= q.value;
        case ContainerQuery::MAX_WIDTH:
            return ctx.inline_size <= q.value;
        case ContainerQuery::MIN_HEIGHT:
            return ctx.block_size >= q.value;
        case ContainerQuery::MAX_HEIGHT:
            return ctx.block_size <= q.value;
        case ContainerQuery::ORIENTATION:
            return (ctx.inline_size >= ctx.block_size) != q.orientation_portrait;
        case ContainerQuery::ASPECT_RATIO: {
            float actual = ctx.block_size > 0.0f ? ctx.inline_size / ctx.block_size : 0.0f;
            return std::abs(actual - q.aspect) < 0.01f;
        }
        case ContainerQuery::INLINE_SIZE:
            return std::abs(ctx.inline_size - q.value) < 1.0f;
        case ContainerQuery::BLOCK_SIZE:
            return std::abs(ctx.block_size - q.value) < 1.0f;
        case ContainerQuery::STYLE:
            return true;  // Style queries not yet implemented
    }
    return true;
}

void ContainerRule::add_rule(std::unique_ptr<CssRule> rule) {
    rules_.push_back(std::move(rule));
}

void ContainerRule::to_css(std::ostream& dest) const {
    dest << "@container";
    if (has_name_) dest << " " << container_name_;
    dest << " " << condition_text_ << " {\n";
    for (const auto& rule : rules_) {
        rule->to_css(dest);
    }
    dest << "}";
}

#ifdef STYLE_TEST
bool test_container_rule() {
    ContainerRule rule;
    rule.set_container_name("card");
    rule.set_condition("(min-width: 400px)");
    
    ContainerContext ctx;
    ctx.inline_size = 500;
    ctx.block_size = 300;
    assert(rule.evaluate(ctx));
    
    ctx.inline_size = 300;
    assert(!rule.evaluate(ctx));
    
    return true;
}
#endif

}} // namespace
