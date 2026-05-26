/* MPL 2.0 */
//! @keyframes rule: defines animation sequences.
//! https://drafts.csswg.org/css-animations-1/#keyframes
#include "style/stylesheets/keyframes_rule.hpp"
#include <algorithm>
#include <sstream>
#include <cmath>

namespace style { namespace stylesheets {

KeyframesRule::KeyframesRule() = default;
KeyframesRule::~KeyframesRule() = default;

void KeyframesRule::set_name(const std::string& n) { name_ = n; }
const std::string& KeyframesRule::name() const { return name_; }

void KeyframesRule::add_keyframe(float percentage, PropertyDeclarationBlock declarations) {
    Keyframe kf;
    kf.percentage = std::clamp(percentage, 0.0f, 1.0f);
    kf.declarations = std::move(declarations);
    keyframes_.push_back(std::move(kf));
    sort_keyframes();
}

void KeyframesRule::sort_keyframes() {
    std::sort(keyframes_.begin(), keyframes_.end(),
        [](const Keyframe& a, const Keyframe& b) {
            return a.percentage < b.percentage;
        });
}

std::vector<std::pair<float, PropertyDeclarationBlock>> 
KeyframesRule::interpolate_at(float progress) const {
    std::vector<std::pair<float, PropertyDeclarationBlock>> result;
    if (keyframes_.empty()) return result;
    
    float t = std::clamp(progress, 0.0f, 1.0f);
    
    // Find bracketing keyframes
    const Keyframe* prev = &keyframes_.front();
    const Keyframe* next = &keyframes_.back();
    for (size_t i = 0; i + 1 < keyframes_.size(); ++i) {
        if (t >= keyframes_[i].percentage && t <= keyframes_[i + 1].percentage) {
            prev = &keyframes_[i];
            next = &keyframes_[i + 1];
            break;
        }
    }
    
    // Collect all properties from both keyframes
    std::set<std::string> props;
    auto collect = [&](const PropertyDeclarationBlock& block) {
        for (const auto& decl : block.declarations()) {
            props.insert(decl.name);
        }
    };
    collect(prev->declarations);
    collect(next->declarations);
    
    // Interpolate each property
    float segment = 0.0f;
    if (next->percentage != prev->percentage) {
        segment = (t - prev->percentage) / (next->percentage - prev->percentage);
    }
    
    for (const auto& prop : props) {
        auto from_val = prev->declarations.get(prop);
        auto to_val = next->declarations.get(prop);
        if (from_val && to_val) {
            std::string interpolated = interpolate_value(prop, *from_val, *to_val, segment);
            PropertyDeclarationBlock block;
            block.set(prop, interpolated);
            result.push_back({t, std::move(block)});
        }
    }
    
    return result;
}

std::string KeyframesRule::interpolate_value(
    const std::string& prop, const std::string& from, 
    const std::string& to, float t) const {
    // Try numeric interpolation
    try {
        size_t pos1, pos2;
        float f = std::stof(from, &pos1);
        float t_val = std::stof(to, &pos2);
        std::string unit = from.substr(pos1);
        float result = f + (t_val - f) * t;
        std::ostringstream oss;
        oss << result << unit;
        return oss.str();
    } catch (...) {
        // Discrete: switch at 0.5
        return t < 0.5f ? from : to;
    }
}

const std::vector<Keyframe>& KeyframesRule::keyframes() const { return keyframes_; }
size_t KeyframesRule::keyframe_count() const { return keyframes_.size(); }

void KeyframesRule::to_css(std::ostream& dest) const {
    dest << "@keyframes " << name_ << " {\n";
    for (const auto& kf : keyframes_) {
        dest << "  " << (kf.percentage * 100.0f) << "% { ";
        kf.declarations.to_css(dest);
        dest << " }\n";
    }
    dest << "}";
}

#ifdef STYLE_TEST
bool test_keyframes() {
    KeyframesRule rule;
    rule.set_name("fadeIn");
    
    PropertyDeclarationBlock from_block;
    from_block.set("opacity", "0");
    rule.add_keyframe(0.0f, std::move(from_block));
    
    PropertyDeclarationBlock to_block;
    to_block.set("opacity", "1");
    rule.add_keyframe(1.0f, std::move(to_block));
    
    assert(rule.keyframe_count() == 2);
    auto result = rule.interpolate_at(0.5f);
    assert(!result.empty());
    
    return true;
}
#endif

}} // namespace
