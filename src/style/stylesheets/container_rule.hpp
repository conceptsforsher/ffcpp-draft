/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

/**
 * @file container_rule.hpp
 * @brief A @container rule for container queries (CSS Containment Level 3).
 *
 * Translated from servo/components/style/stylesheets/container_rule.rs
 */

#pragma once

#include "style/stylesheets/stylesheets.hpp"

#include <string>
#include <memory>
#include <sstream>
#include <optional>

namespace style {
namespace stylesheets {

// ============================================================================
// ContainerCondition - Container condition and filter, combined
// ============================================================================

/**
 * A container condition and filter, combined.
 *
 * Translated from: struct ContainerCondition
 */
class ContainerCondition {
public:
    /// The container name filter (optional).
    std::optional<std::string> name;

    /// The query condition text.
    std::string condition_text;

    /// Feature flags for the container axes required.
    uint32_t flags = 0;

    // Container axis feature flags
    static constexpr uint32_t CONTAINER_REQUIRES_WIDTH_AXIS = 1 << 0;
    static constexpr uint32_t CONTAINER_REQUIRES_HEIGHT_AXIS = 1 << 1;
    static constexpr uint32_t CONTAINER_REQUIRES_INLINE_AXIS = 1 << 2;
    static constexpr uint32_t CONTAINER_REQUIRES_BLOCK_AXIS = 1 << 3;

    ContainerCondition() = default;

    ContainerCondition(const std::string& cond,
                       std::optional<std::string> filter_name = std::nullopt,
                       uint32_t f = 0)
        : name(std::move(filter_name))
        , condition_text(cond)
        , flags(f)
    {}

    /**
     * Parse a container condition from CSS text.
     *
     * Simplified version for C++ translation.
     */
    static ContainerCondition Parse(const std::string& input) {
        ContainerCondition cond;
        // Simplified: store the raw text
        cond.condition_text = input;
        // Try to extract name if present (before condition)
        size_t space = input.find(' ');
        if (space != std::string::npos) {
            std::string first_word = input.substr(0, space);
            // Check if first word looks like a name (not a known keyword)
            if (first_word != "width" && first_word != "height" &&
                first_word != "inline-size" && first_word != "block-size" &&
                first_word != "aspect-ratio" && first_word != "orientation") {
                cond.name = first_word;
                cond.condition_text = input.substr(space + 1);
            }
        }
        return cond;
    }

    /**
     * Check if the container name filter is present.
     */
    bool IsNameNone() const { return !name.has_value() || name->empty(); }

    /**
     * Evaluate the container condition.
     * Simplified: always returns Unknown.
     */
    enum class KleeneValue { False, True, Unknown };
    KleeneValue Eval() const {
        // In real implementation, actual evaluation would happen here
        return KleeneValue::Unknown;
    }

    /**
     * Serialize to CSS text.
     */
    std::string ToCss() const {
        std::ostringstream oss;
        if (name.has_value() && !name->empty()) {
            oss << name.value() << " ";
        }
        oss << condition_text;
        return oss.str();
    }
};

// ============================================================================
// ContainerInfo - Information needed to evaluate a container query
// ============================================================================

/**
 * Information needed to evaluate an individual container query.
 *
 * Translated from: struct ContainerInfo
 */
struct ContainerInfo {
    std::optional<float> width;   // in CSS pixels
    std::optional<float> height;  // in CSS pixels
    bool horizontal_writing_mode = true;

    ContainerInfo() = default;

    bool HasSize() const { return width.has_value() && height.has_value(); }

    std::string ToDebugString() const {
        std::ostringstream oss;
        oss << "ContainerInfo{ w=" << (width.has_value() ? std::to_string(width.value()) : "none")
            << ", h=" << (height.has_value() ? std::to_string(height.value()) : "none")
            << ", hwm=" << horizontal_writing_mode << " }";
        return oss.str();
    }
};

// ============================================================================
// ContainerRule - A @container rule
// ============================================================================

/**
 * A container rule.
 *
 * Translated from: struct ContainerRule
 */
class ContainerRule {
public:
    /// The container query and name.
    std::shared_ptr<ContainerCondition> condition;

    /// The nested rules inside the block.
    std::unique_ptr<CssRules> rules;

    /// The source position where this rule was found.
    SourceLocation source_location;

    ContainerRule()
        : condition(std::make_shared<ContainerCondition>())
        , rules(std::make_unique<CssRules>())
    {}

    ContainerRule(std::shared_ptr<ContainerCondition> cond,
                  std::unique_ptr<CssRules> nested_rules,
                  SourceLocation loc = SourceLocation())
        : condition(std::move(cond))
        , rules(std::move(nested_rules))
        , source_location(loc)
    {}

    // Copy
    ContainerRule(const ContainerRule& other)
        : condition(other.condition ? std::make_shared<ContainerCondition>(*other.condition)
                                    : std::make_shared<ContainerCondition>())
        , rules(other.rules ? std::make_unique<CssRules>(*other.rules) : std::make_unique<CssRules>())
        , source_location(other.source_location)
    {}

    // Move
    ContainerRule(ContainerRule&&) noexcept = default;
    ContainerRule& operator=(ContainerRule&&) noexcept = default;

    ContainerRule& operator=(const ContainerRule& other) {
        if (this != &other) {
            condition = other.condition ? std::make_shared<ContainerCondition>(*other.condition)
                                        : std::make_shared<ContainerCondition>();
            rules = other.rules ? std::make_unique<CssRules>(*other.rules) : std::make_unique<CssRules>();
            source_location = other.source_location;
        }
        return *this;
    }

    /**
     * Returns the query condition text.
     */
    const std::string& QueryCondition() const { return condition->condition_text; }

    /**
     * Returns the container name filter.
     */
    const std::optional<std::string>& ContainerName() const { return condition->name; }

    /**
     * Measure heap usage.
     */
    size_t SizeOf() const {
        return sizeof(ContainerRule);
    }

    /**
     * Serialize to CSS text.
     */
    std::string ToCss() const {
        std::ostringstream oss;
        oss << "@container ";
        oss << condition->ToCss();
        if (rules) {
            oss << " " << rules->ToCssBlock();
        } else {
            oss << " {}";
        }
        return oss.str();
    }

    /**
     * Deep clone this container rule.
     */
    ContainerRule DeepClone() const {
        return ContainerRule(
            condition ? std::make_shared<ContainerCondition>(*condition)
                      : std::make_shared<ContainerCondition>(),
            rules ? std::make_unique<CssRules>(*rules) : std::make_unique<CssRules>(),
            source_location
        );
    }

    std::string ToDebugString() const {
        std::ostringstream oss;
        oss << "ContainerRule{ condition=" << condition->ToCss()
            << ", source=" << source_location.ToString()
            << ", rules_count=" << (rules ? std::to_string(rules->Size()) : "0")
            << " }";
        return oss.str();
    }
};

// ============================================================================
// ContainerSizeQueryResult - Result of container size query
// ============================================================================

/**
 * Result of a container size query, signifying the hypothetical containment
 * boundary in terms of physical axes.
 *
 * Translated from: struct ContainerSizeQueryResult
 */
struct ContainerSizeQueryResult {
    std::optional<float> width;   // in app units
    std::optional<float> height;  // in app units

    ContainerSizeQueryResult() = default;

    bool IsComplete() const { return width.has_value() && height.has_value(); }
};

// ============================================================================
// Test utilities
// ============================================================================

namespace test {

inline ContainerRule MakeTestContainerRule(
    const std::string& condition_text = "width > 400px",
    const std::optional<std::string>& container_name = std::nullopt)
{
    auto cond = std::make_shared<ContainerCondition>(condition_text, container_name);
    return ContainerRule(cond, std::make_unique<CssRules>(), MakeTestSourceLocation());
}

} // namespace test

} // namespace stylesheets
} // namespace style
