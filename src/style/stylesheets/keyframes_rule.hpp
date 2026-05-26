/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

/**
 * @file keyframes_rule.hpp
 * @brief @keyframes rules including keyframe percentage selectors and animation steps.
 *
 * Translated from servo/components/style/stylesheets/keyframes_rule.rs
 */

#pragma once

#include "style/stylesheets/stylesheets.hpp"
#include "style/stylesheets/style_rule.hpp"

#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <cmath>
#include <algorithm>

namespace style {
namespace stylesheets {

// ============================================================================
// KeyframePercentage - A number from 0 to 1
// ============================================================================

/**
 * A number from 0 to 1, indicating the percentage of the animation when
 * this keyframe should run.
 *
 * Translated from: struct KeyframePercentage(pub f32)
 */
class KeyframePercentage {
public:
    float value;

    /**
     * Construct a new KeyframePercentage.
     * @param val Value in range [0.0, 1.0]
     */
    explicit KeyframePercentage(float val = 0.0f)
        : value(val)
    {
        // Clamp to valid range
        if (value < 0.0f) value = 0.0f;
        if (value > 1.0f) value = 1.0f;
    }

    /**
     * Trivially constructs a new KeyframePercentage.
     * Translated from: KeyframePercentage::new()
     */
    static KeyframePercentage New(float val) {
        return KeyframePercentage(val);
    }

    /**
     * Serialize as percentage string.
     */
    std::string ToCss() const {
        std::ostringstream oss;
        oss << (value * 100.0f) << "%";
        return oss.str();
    }

    /**
     * Parse a keyframe percentage from CSS input.
     * Translates: KeyframePercentage::parse()
     */
    static KeyframePercentage Parse(const std::string& input) {
        // Handle "from" -> 0%, "to" -> 100%
        if (input == "from") return KeyframePercentage(0.0f);
        if (input == "to") return KeyframePercentage(1.0f);

        // Handle percentage values
        std::string s = input;
        if (!s.empty() && s.back() == '%') {
            s.pop_back();
            try {
                float pct = std::stof(s) / 100.0f;
                return KeyframePercentage(pct);
            } catch (...) {
                // Invalid, return 0
            }
        }
        // Try as raw float
        try {
            float val = std::stof(s);
            return KeyframePercentage(val);
        } catch (...) {
        }
        return KeyframePercentage(0.0f);
    }

    // Comparison operators for sorting
    bool operator<(const KeyframePercentage& other) const { return value < other.value; }
    bool operator<=(const KeyframePercentage& other) const { return value <= other.value; }
    bool operator>(const KeyframePercentage& other) const { return value > other.value; }
    bool operator>=(const KeyframePercentage& other) const { return value >= other.value; }
    bool operator==(const KeyframePercentage& other) const { return value == other.value; }
    bool operator!=(const KeyframePercentage& other) const { return value != other.value; }
};

// ============================================================================
// KeyframeSelector - A list of percentages or from/to symbols
// ============================================================================

/**
 * A keyframes selector is a list of percentages or from/to symbols,
 * converted at parse time to percentages.
 *
 * Translated from: struct KeyframeSelector(Vec<KeyframePercentage>)
 */
class KeyframeSelector {
public:
    KeyframeSelector() = default;

    explicit KeyframeSelector(const std::vector<KeyframePercentage>& percentages)
        : percentages_(percentages) {}

    /**
     * Return the list of percentages this selector contains.
     */
    const std::vector<KeyframePercentage>& Percentages() const { return percentages_; }

    /**
     * A dummy public function for unit testing.
     */
    static KeyframeSelector NewForUnitTesting(const std::vector<KeyframePercentage>& percentages) {
        return KeyframeSelector(percentages);
    }

    /**
     * Parse a keyframe selector from CSS input.
     * Translates: KeyframeSelector::parse()
     */
    static KeyframeSelector Parse(const std::string& input) {
        std::vector<KeyframePercentage> percentages;
        // Split on commas
        size_t start = 0;
        size_t comma;
        while ((comma = input.find(',', start)) != std::string::npos) {
            std::string part = input.substr(start, comma - start);
            while (!part.empty() && part.front() == ' ') part.erase(0, 1);
            while (!part.empty() && part.back() == ' ') part.pop_back();
            if (!part.empty()) {
                percentages.push_back(KeyframePercentage::Parse(part));
            }
            start = comma + 1;
        }
        std::string part = input.substr(start);
        while (!part.empty() && part.front() == ' ') part.erase(0, 1);
        while (!part.empty() && part.back() == ' ') part.pop_back();
        if (!part.empty()) {
            percentages.push_back(KeyframePercentage::Parse(part));
        }
        return KeyframeSelector(percentages);
    }

    /**
     * Serialize to CSS text (comma-separated percentages).
     */
    std::string ToCss() const {
        std::ostringstream oss;
        bool first = true;
        for (const auto& kp : percentages_) {
            if (!first) oss << ", ";
            first = false;
            oss << kp.ToCss();
        }
        return oss.str();
    }

    bool IsEmpty() const { return percentages_.empty(); }

    bool operator==(const KeyframeSelector& other) const {
        if (percentages_.size() != other.percentages_.size()) return false;
        for (size_t i = 0; i < percentages_.size(); ++i) {
            if (percentages_[i].value != other.percentages_[i].value) return false;
        }
        return true;
    }

private:
    std::vector<KeyframePercentage> percentages_;
};

// ============================================================================
// Keyframe - A single keyframe rule
// ============================================================================

/**
 * A keyframe.
 *
 * Translated from: struct Keyframe
 */
class Keyframe {
public:
    /// The selector this keyframe was specified from.
    KeyframeSelector selector;

    /// The declaration block that was declared inside this keyframe.
    std::shared_ptr<PropertyDeclarationBlock> block;

    /// The line and column of the rule's source code.
    SourceLocation source_location;

    Keyframe()
        : block(std::make_shared<PropertyDeclarationBlock>())
    {}

    Keyframe(const KeyframeSelector& sel,
             std::shared_ptr<PropertyDeclarationBlock> b,
             SourceLocation loc = SourceLocation())
        : selector(sel), block(std::move(b)), source_location(loc)
    {}

    // Copy
    Keyframe(const Keyframe& other)
        : selector(other.selector)
        , block(other.block ? std::make_shared<PropertyDeclarationBlock>(*other.block)
                            : std::make_shared<PropertyDeclarationBlock>())
        , source_location(other.source_location)
    {}

    // Move
    Keyframe(Keyframe&&) noexcept = default;
    Keyframe& operator=(Keyframe&&) noexcept = default;

    Keyframe& operator=(const Keyframe& other) {
        if (this != &other) {
            selector = other.selector;
            block = other.block ? std::make_shared<PropertyDeclarationBlock>(*other.block)
                                : std::make_shared<PropertyDeclarationBlock>();
            source_location = other.source_location;
        }
        return *this;
    }

    /**
     * Serialize this keyframe to CSS text.
     */
    std::string ToCss() const {
        std::ostringstream oss;
        oss << selector.ToCss() << " { ";
        if (block) {
            oss << block->ToCss();
        }
        oss << " }";
        return oss.str();
    }

    /**
     * Deep clone this keyframe.
     */
    Keyframe DeepClone() const {
        return Keyframe(
            selector,
            block ? std::make_shared<PropertyDeclarationBlock>(*block)
                  : std::make_shared<PropertyDeclarationBlock>(),
            source_location
        );
    }

    std::string ToDebugString() const {
        std::ostringstream oss;
        oss << "Keyframe{ selector=" << selector.ToCss()
            << ", source=" << source_location.ToString() << " }";
        return oss.str();
    }
};

// ============================================================================
// KeyframesRule - A @keyframes rule
// ============================================================================

/**
 * A @keyframes rule.
 *
 * https://drafts.csswg.org/css-animations/#keyframes
 *
 * Translated from: struct KeyframesRule
 */
class KeyframesRule {
public:
    /// The name of the current animation.
    std::string name;

    /// The keyframes specified for this CSS rule.
    std::vector<std::shared_ptr<Keyframe>> keyframes;

    /// Vendor prefix type the @keyframes has.
    std::optional<VendorPrefix> vendor_prefix;

    /// The line and column of the rule's source code.
    SourceLocation source_location;

    KeyframesRule() = default;

    KeyframesRule(const std::string& anim_name,
                  std::vector<std::shared_ptr<Keyframe>> kf,
                  std::optional<VendorPrefix> vp = std::nullopt,
                  SourceLocation loc = SourceLocation())
        : name(anim_name)
        , keyframes(std::move(kf))
        , vendor_prefix(vp)
        , source_location(loc)
    {}

    // Copy
    KeyframesRule(const KeyframesRule& other)
        : name(other.name)
        , vendor_prefix(other.vendor_prefix)
        , source_location(other.source_location)
    {
        for (const auto& kf : other.keyframes) {
            keyframes.push_back(std::make_shared<Keyframe>(*kf));
        }
    }

    // Move
    KeyframesRule(KeyframesRule&&) noexcept = default;
    KeyframesRule& operator=(KeyframesRule&&) noexcept = default;

    KeyframesRule& operator=(const KeyframesRule& other) {
        if (this != &other) {
            name = other.name;
            vendor_prefix = other.vendor_prefix;
            source_location = other.source_location;
            keyframes.clear();
            for (const auto& kf : other.keyframes) {
                keyframes.push_back(std::make_shared<Keyframe>(*kf));
            }
        }
        return *this;
    }

    /**
     * Returns the index of the last keyframe that matches the given selector.
     * If the selector is not valid, or no keyframe is found, returns -1.
     *
     * Translated from: KeyframesRule::find_rule()
     */
    int FindRule(const std::string& selector_str) const {
        KeyframeSelector parsed = KeyframeSelector::Parse(selector_str);
        if (parsed.IsEmpty()) return -1;

        for (int i = static_cast<int>(keyframes.size()) - 1; i >= 0; --i) {
            if (keyframes[i]->selector == parsed) {
                return i;
            }
        }
        return -1;
    }

    /**
     * Add a keyframe rule.
     */
    void AddKeyframe(std::shared_ptr<Keyframe> kf) {
        keyframes.push_back(std::move(kf));
    }

    /**
     * Remove a keyframe at the given index.
     */
    void RemoveKeyframe(size_t index) {
        if (index < keyframes.size()) {
            keyframes.erase(keyframes.begin() + static_cast<long>(index));
        }
    }

    /**
     * Serialize to CSS text.
     */
    std::string ToCss() const {
        std::ostringstream oss;
        if (vendor_prefix.has_value()) {
            oss << "@" << VendorPrefixToString(vendor_prefix.value()) << "keyframes ";
        } else {
            oss << "@keyframes ";
        }
        oss << name << " {";
        for (const auto& kf : keyframes) {
            oss << "\n  " << kf->ToCss();
        }
        oss << "\n}";
        return oss.str();
    }

    /**
     * Deep clone this keyframes rule.
     */
    KeyframesRule DeepClone() const {
        KeyframesRule clone;
        clone.name = name;
        clone.vendor_prefix = vendor_prefix;
        clone.source_location = source_location;
        for (const auto& kf : keyframes) {
            clone.keyframes.push_back(std::make_shared<Keyframe>(kf->DeepClone()));
        }
        return clone;
    }

    std::string ToDebugString() const {
        std::ostringstream oss;
        oss << "KeyframesRule{ name=" << name
            << ", keyframes_count=" << keyframes.size()
            << ", source=" << source_location.ToString()
            << " }";
        return oss.str();
    }
};

// ============================================================================
// KeyframesStepValue - Value for a keyframes animation step
// ============================================================================

/**
 * A keyframes step value. This can be a synthesized keyframes animation,
 * or a list of declarations to apply.
 *
 * Translated from: enum KeyframesStepValue
 */
enum class KeyframesStepValueKind {
    Declarations,
    ComputedValues,
};

class KeyframesStepValue {
public:
    KeyframesStepValueKind kind;
    std::shared_ptr<PropertyDeclarationBlock> block; // Only valid for Declarations

    static KeyframesStepValue MakeDeclarations(std::shared_ptr<PropertyDeclarationBlock> block) {
        KeyframesStepValue v;
        v.kind = KeyframesStepValueKind::Declarations;
        v.block = std::move(block);
        return v;
    }

    static KeyframesStepValue MakeComputedValues() {
        KeyframesStepValue v;
        v.kind = KeyframesStepValueKind::ComputedValues;
        return v;
    }
};

// ============================================================================
// KeyframesStep - A single step from a keyframe animation
// ============================================================================

/**
 * A single step from a keyframe animation.
 *
 * Translated from: struct KeyframesStep
 */
struct KeyframesStep {
    /// The percentage of the animation duration when this step starts.
    KeyframePercentage start_percentage;

    /// Declarations or computed values for this step.
    KeyframesStepValue value;

    /// Whether an animation-timing-function declaration exists.
    bool declared_timing_function = false;

    /// Whether an animation-composition declaration exists.
    bool declared_composition = false;

    KeyframesStep() : start_percentage(0.0f), value(KeyframesStepValue::MakeComputedValues()) {}
};

// ============================================================================
// KeyframesAnimation - List of animation steps
// ============================================================================

/**
 * This structure represents a list of animation steps computed from the
 * list of keyframes, in order.
 *
 * Translated from: struct KeyframesAnimation
 */
class KeyframesAnimation {
public:
    /// The difference steps of the animation.
    std::vector<KeyframesStep> steps;

    /// Vendor prefix type the @keyframes has.
    std::optional<VendorPrefix> vendor_prefix;

    KeyframesAnimation() = default;

    /**
     * Create a keyframes animation from a given list of keyframes.
     *
     * Translated from: KeyframesAnimation::from_keyframes()
     */
    static KeyframesAnimation FromKeyframes(
        const std::vector<std::shared_ptr<Keyframe>>& keyframes,
        std::optional<VendorPrefix> vendor_prefix)
    {
        KeyframesAnimation result;
        result.vendor_prefix = vendor_prefix;

        if (keyframes.empty()) return result;

        // Collect all steps from keyframe selectors
        for (const auto& kf : keyframes) {
            for (const auto& pct : kf->selector.Percentages()) {
                KeyframesStep step;
                step.start_percentage = pct;
                step.value = KeyframesStepValue::MakeDeclarations(kf->block);

                // Check for timing function and composition declarations
                if (kf->block) {
                    for (const auto& decl : kf->block->Declarations()) {
                        if (decl.property == "animation-timing-function") {
                            step.declared_timing_function = true;
                        }
                        if (decl.property == "animation-composition") {
                            step.declared_composition = true;
                        }
                    }
                }
                result.steps.push_back(std::move(step));
            }
        }

        // Sort by start percentage
        std::sort(result.steps.begin(), result.steps.end(),
            [](const KeyframesStep& a, const KeyframesStep& b) {
                return a.start_percentage < b.start_percentage;
            });

        // Prepend autogenerated 0% keyframe if needed
        if (result.steps[0].start_percentage.value != 0.0f) {
            KeyframesStep zero_step;
            zero_step.start_percentage = KeyframePercentage(0.0f);
            zero_step.value = KeyframesStepValue::MakeComputedValues();
            result.steps.insert(result.steps.begin(), std::move(zero_step));
        }

        // Append autogenerated 100% keyframe if needed
        if (result.steps.back().start_percentage.value != 1.0f) {
            KeyframesStep full_step;
            full_step.start_percentage = KeyframePercentage(1.0f);
            full_step.value = KeyframesStepValue::MakeComputedValues();
            result.steps.push_back(std::move(full_step));
        }

        return result;
    }

    bool IsEmpty() const { return steps.empty(); }
};

// ============================================================================
// Test utilities
// ============================================================================

namespace test {

inline std::shared_ptr<KeyframesRule> MakeTestKeyframesRule(
    const std::string& name = "fadeIn")
{
    auto rule = std::make_shared<KeyframesRule>();
    rule->name = name;

    // Add "from" keyframe (0%)
    auto from_kf = std::make_shared<Keyframe>();
    from_kf->selector = KeyframeSelector::Parse("from");
    auto from_block = std::make_shared<PropertyDeclarationBlock>();
    from_block->AddDeclaration("opacity", "0");
    from_kf->block = from_block;
    rule->keyframes.push_back(from_kf);

    // Add "to" keyframe (100%)
    auto to_kf = std::make_shared<Keyframe>();
    to_kf->selector = KeyframeSelector::Parse("to");
    auto to_block = std::make_shared<PropertyDeclarationBlock>();
    to_block->AddDeclaration("opacity", "1");
    to_kf->block = to_block;
    rule->keyframes.push_back(to_kf);

    return rule;
}

} // namespace test

} // namespace stylesheets
} // namespace style
