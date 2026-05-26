/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

/**
 * @file layer_rule.hpp
 * @brief @layer rules for CSS Cascade Layers.
 *
 * Translated from servo/components/style/stylesheets/layer_rule.rs
 */

#pragma once

#include "style/stylesheets/stylesheets.hpp"

#include <string>
#include <vector>
#include <memory>
#include <sstream>

namespace style {
namespace stylesheets {

// ============================================================================
// LayerOrder - The order of a given layer
// ============================================================================

/**
 * The order of a given layer. Uses 16 bits.
 *
 * Translated from: struct LayerOrder(u16)
 */
class LayerOrder {
public:
    uint16_t value;

    constexpr LayerOrder() : value(0) {}
    explicit constexpr LayerOrder(uint16_t v) : value(v) {}

    /**
     * The order of the root layer.
     */
    static constexpr LayerOrder Root() { return LayerOrder(UINT16_MAX - 1); }

    /**
     * The order of the style attribute layer.
     */
    static constexpr LayerOrder StyleAttribute() { return LayerOrder(UINT16_MAX); }

    /**
     * The first cascade layer order.
     */
    static constexpr LayerOrder First() { return LayerOrder(0); }

    /**
     * Returns whether this layer is for the style attribute.
     */
    bool IsStyleAttributeLayer() const { return value == UINT16_MAX; }

    /**
     * Increment the cascade layer order.
     */
    void Inc() {
        if (value != UINT16_MAX - 1) {
            value++;
        }
    }

    bool operator==(LayerOrder other) const { return value == other.value; }
    bool operator!=(LayerOrder other) const { return value != other.value; }
    bool operator<(LayerOrder other) const { return value < other.value; }
    bool operator<=(LayerOrder other) const { return value <= other.value; }

    std::string ToString() const {
        return std::to_string(value);
    }
};

// ============================================================================
// LayerName - A <layer-name>
// ============================================================================

/**
 * A <layer-name>: https://drafts.csswg.org/css-cascade-5/#typedef-layer-name
 *
 * Translated from: struct LayerName(pub SmallVec<[AtomIdent; 1]>)
 */
class LayerName {
public:
    std::vector<std::string> parts;

    LayerName() = default;

    explicit LayerName(const std::vector<std::string>& p) : parts(p) {}

    /**
     * Returns an empty layer name.
     */
    static LayerName NewEmpty() { return LayerName(); }

    /**
     * Returns a synthesized name for an anonymous layer.
     */
    static LayerName NewAnonymous() {
        static int next_id = 0;
        LayerName name;
        name.parts.push_back("-moz-anon-layer(" + std::to_string(next_id++) + ")");
        return name;
    }

    /**
     * Returns the names of the layers.
     */
    const std::vector<std::string>& LayerNames() const { return parts; }

    /**
     * Check if this name is empty.
     */
    bool IsEmpty() const { return parts.empty(); }

    /**
     * Parse a layer name from CSS.
     * Translates: impl Parse for LayerName
     */
    static LayerName Parse(const std::string& input) {
        LayerName name;
        size_t start = 0;
        while (start < input.size()) {
            size_t dot = input.find('.', start);
            if (dot == std::string::npos) {
                std::string part = input.substr(start);
                while (!part.empty() && part.front() == ' ') part.erase(0, 1);
                while (!part.empty() && part.back() == ' ') part.pop_back();
                if (!part.empty()) name.parts.push_back(part);
                break;
            }
            std::string part = input.substr(start, dot - start);
            while (!part.empty() && part.front() == ' ') part.erase(0, 1);
            while (!part.empty() && part.back() == ' ') part.pop_back();
            if (!part.empty()) name.parts.push_back(part);
            start = dot + 1;
        }
        return name;
    }

    /**
     * Serialize to CSS text.
     */
    std::string ToCss() const {
        std::ostringstream oss;
        bool first = true;
        for (const auto& part : parts) {
            if (!first) oss << ".";
            first = false;
            oss << part;
        }
        return oss.str();
    }

    bool operator==(const LayerName& other) const { return parts == other.parts; }
    bool operator!=(const LayerName& other) const { return parts != other.parts; }
};

// ============================================================================
// LayerBlockRule - A block @layer rule
// ============================================================================

/**
 * A block `@layer <name>? { ... }`
 * https://drafts.csswg.org/css-cascade-5/#layer-block
 *
 * Translated from: struct LayerBlockRule
 */
class LayerBlockRule {
public:
    /// The layer name, or empty if anonymous.
    std::optional<LayerName> name;

    /// The nested rules.
    std::unique_ptr<CssRules> rules;

    /// The source position where this rule was found.
    SourceLocation source_location;

    LayerBlockRule()
        : rules(std::make_unique<CssRules>())
    {}

    LayerBlockRule(std::optional<LayerName> n,
                   std::unique_ptr<CssRules> r,
                   SourceLocation loc = SourceLocation())
        : name(std::move(n)), rules(std::move(r)), source_location(loc)
    {}

    // Copy
    LayerBlockRule(const LayerBlockRule& other)
        : name(other.name)
        , rules(other.rules ? std::make_unique<CssRules>(*other.rules) : std::make_unique<CssRules>())
        , source_location(other.source_location)
    {}

    // Move
    LayerBlockRule(LayerBlockRule&&) noexcept = default;
    LayerBlockRule& operator=(LayerBlockRule&&) noexcept = default;

    LayerBlockRule& operator=(const LayerBlockRule& other) {
        if (this != &other) {
            name = other.name;
            rules = other.rules ? std::make_unique<CssRules>(*other.rules) : std::make_unique<CssRules>();
            source_location = other.source_location;
        }
        return *this;
    }

    /**
     * Serialize to CSS text.
     */
    std::string ToCss() const {
        std::ostringstream oss;
        oss << "@layer";
        if (name.has_value() && !name->IsEmpty()) {
            oss << " " << name->ToCss();
        }
        if (rules) {
            oss << " " << rules->ToCssBlock();
        } else {
            oss << " {}";
        }
        return oss.str();
    }

    std::string ToDebugString() const {
        std::ostringstream oss;
        oss << "LayerBlockRule{ name=" << (name.has_value() ? name->ToCss() : "(anonymous)")
            << ", source=" << source_location.ToString()
            << ", rules_count=" << (rules ? std::to_string(rules->Size()) : "0")
            << " }";
        return oss.str();
    }
};

// ============================================================================
// LayerStatementRule - A statement @layer rule
// ============================================================================

/**
 * A statement `@layer <name>, <name>, <name>;`
 * https://drafts.csswg.org/css-cascade-5/#layer-empty
 *
 * Translated from: struct LayerStatementRule
 */
class LayerStatementRule {
public:
    /// The list of layers to sort.
    std::vector<LayerName> names;

    /// The source position where this rule was found.
    SourceLocation source_location;

    LayerStatementRule() = default;

    explicit LayerStatementRule(std::vector<LayerName> n,
                                SourceLocation loc = SourceLocation())
        : names(std::move(n)), source_location(loc)
    {}

    // Copy and move (default is fine)
    LayerStatementRule(const LayerStatementRule&) = default;
    LayerStatementRule& operator=(const LayerStatementRule&) = default;
    LayerStatementRule(LayerStatementRule&&) noexcept = default;
    LayerStatementRule& operator=(LayerStatementRule&&) noexcept = default;

    /**
     * Serialize to CSS text.
     */
    std::string ToCss() const {
        std::ostringstream oss;
        oss << "@layer ";
        bool first = true;
        for (const auto& name : names) {
            if (!first) oss << ", ";
            first = false;
            oss << name.ToCss();
        }
        oss << ";";
        return oss.str();
    }

    std::string ToDebugString() const {
        std::ostringstream oss;
        oss << "LayerStatementRule{ names=[";
        bool first = true;
        for (const auto& name : names) {
            if (!first) oss << ", ";
            first = false;
            oss << name.ToCss();
        }
        oss << "], source=" << source_location.ToString() << " }";
        return oss.str();
    }
};

// ============================================================================
// Test utilities
// ============================================================================

namespace test {

inline LayerName MakeTestLayerName(const std::string& name) {
    return LayerName::Parse(name);
}

inline LayerBlockRule MakeTestLayerBlockRule(
    const std::optional<std::string>& name = std::nullopt)
{
    LayerBlockRule rule;
    if (name.has_value()) {
        rule.name = LayerName::Parse(name.value());
    }
    return rule;
}

inline LayerStatementRule MakeTestLayerStatementRule(
    const std::vector<std::string>& names)
{
    std::vector<LayerName> layer_names;
    for (const auto& n : names) {
        layer_names.push_back(LayerName::Parse(n));
    }
    return LayerStatementRule(layer_names, MakeTestSourceLocation());
}

} // namespace test

} // namespace stylesheets
} // namespace style
