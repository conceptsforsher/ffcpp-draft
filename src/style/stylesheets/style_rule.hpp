/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

/**
 * @file style_rule.hpp
 * @brief A style rule with selectors and declarations (CSSStyleRule).
 *
 * Translated from servo/components/style/stylesheets/style_rule.rs
 */

#pragma once

#include "style/stylesheets/stylesheets.hpp"

#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <algorithm>

namespace style {
namespace stylesheets {

// ============================================================================
// PropertyDeclarationBlock - A block of property declarations
// ============================================================================

/**
 * A block of CSS property declarations.
 *
 * In the full implementation this would contain parsed property declarations.
 * Here it is represented as a list of (property, value) string pairs.
 */
class PropertyDeclarationBlock {
public:
    struct Declaration {
        std::string property;
        std::string value;
        bool important = false;

        Declaration() = default;
        Declaration(const std::string& prop, const std::string& val, bool imp = false)
            : property(prop), value(val), important(imp) {}
    };

    PropertyDeclarationBlock() = default;

    explicit PropertyDeclarationBlock(std::vector<Declaration> decls)
        : declarations_(std::move(decls)) {}

    /**
     * Get all declarations.
     */
    const std::vector<Declaration>& Declarations() const { return declarations_; }
    std::vector<Declaration>& Declarations() { return declarations_; }

    /**
     * Check if the block is empty.
     */
    bool IsEmpty() const { return declarations_.empty(); }

    /**
     * Add a declaration.
     */
    void AddDeclaration(const std::string& property, const std::string& value, bool important = false) {
        // Remove any existing declaration with the same property name
        declarations_.erase(
            std::remove_if(declarations_.begin(), declarations_.end(),
                [&property](const Declaration& d) { return d.property == property; }),
            declarations_.end());
        declarations_.emplace_back(property, value, important);
    }

    /**
     * Get the value of a specific property.
     * @return empty string if not found
     */
    std::string GetPropertyValue(const std::string& property) const {
        for (const auto& decl : declarations_) {
            if (decl.property == property) return decl.value;
        }
        return "";
    }

    /**
     * Remove a property.
     */
    void RemoveProperty(const std::string& property) {
        declarations_.erase(
            std::remove_if(declarations_.begin(), declarations_.end(),
                [&property](const Declaration& d) { return d.property == property; }),
            declarations_.end());
    }

    /**
     * Clear all declarations.
     */
    void Clear() { declarations_.clear(); }

    /**
     * Serialize to CSS text.
     */
    std::string ToCss() const {
        if (declarations_.empty()) return "";

        std::ostringstream oss;
        bool first = true;
        for (const auto& decl : declarations_) {
            if (!first) oss << " ";
            first = false;
            oss << decl.property << ": " << decl.value;
            if (decl.important) oss << " !important";
            oss << ";";
        }
        return oss.str();
    }

    /**
     * Compute the approximate size of this block.
     */
    size_t SizeOf() const {
        size_t size = sizeof(Declaration) * declarations_.capacity();
        for (const auto& decl : declarations_) {
            size += decl.property.capacity() + decl.value.capacity();
        }
        return size;
    }

    bool operator==(const PropertyDeclarationBlock& other) const {
        if (declarations_.size() != other.declarations_.size()) return false;
        for (size_t i = 0; i < declarations_.size(); ++i) {
            if (declarations_[i].property != other.declarations_[i].property ||
                declarations_[i].value != other.declarations_[i].value ||
                declarations_[i].important != other.declarations_[i].important)
                return false;
        }
        return true;
    }

private:
    std::vector<Declaration> declarations_;
};

// ============================================================================
// SelectorList - A list of CSS selectors
// ============================================================================

/**
 * A simplified representation of a CSS selector list.
 *
 * In the full implementation this would use the selectors crate.
 * Here it is represented as a list of serialized selector strings.
 */
class SelectorList {
public:
    SelectorList() = default;

    explicit SelectorList(std::vector<std::string> selectors)
        : selectors_(std::move(selectors)) {}

    /**
     * Get all selectors.
     */
    const std::vector<std::string>& Items() const { return selectors_; }

    /**
     * Get individual selectors as a slice.
     */
    std::vector<std::string> Slice() const { return selectors_; }

    /**
     * Check if empty.
     */
    bool IsEmpty() const { return selectors_.empty(); }

    /**
     * Number of selectors.
     */
    size_t Size() const { return selectors_.size(); }

    /**
     * Add a selector.
     */
    void Add(const std::string& selector) {
        selectors_.push_back(selector);
    }

    /**
     * Serialize to CSS text (comma-separated).
     */
    std::string ToCss() const {
        if (selectors_.empty()) return "";
        std::ostringstream oss;
        bool first = true;
        for (const auto& sel : selectors_) {
            if (!first) oss << ", ";
            first = false;
            oss << sel;
        }
        return oss.str();
    }

    /**
     * Compute approximate size.
     */
    size_t SizeOf() const {
        size_t size = sizeof(std::string) * selectors_.capacity();
        for (const auto& sel : selectors_) {
            size += sel.capacity();
        }
        return size;
    }

    bool operator==(const SelectorList& other) const {
        return selectors_ == other.selectors_;
    }

    bool operator!=(const SelectorList& other) const {
        return !(*this == other);
    }

private:
    std::vector<std::string> selectors_;
};

// ============================================================================
// StyleRule - A CSS style rule
// ============================================================================

/**
 * A style rule, with selectors and declarations.
 *
 * Translated from: struct StyleRule
 *
 * Fields:
 * - selectors: The list of selectors in this rule.
 * - block: The declaration block with the properties it contains.
 * - rules: The nested rules (only non-null when nesting is enabled).
 * - source_location: The location in the sheet where it was found.
 */
class StyleRule {
public:
    /// The list of selectors in this rule.
    SelectorList selectors;

    /// The declaration block with the properties it contains.
    std::shared_ptr<PropertyDeclarationBlock> block;

    /// The nested rules to this style rule (optional, for CSS nesting).
    std::unique_ptr<class CssRules> rules;

    /// The location in the sheet where it was found.
    SourceLocation source_location;

    /**
     * Default constructor - creates an empty style rule.
     */
    StyleRule()
        : block(std::make_shared<PropertyDeclarationBlock>())
        , source_location()
    {}

    /**
     * Construct with selectors and declarations.
     */
    StyleRule(const SelectorList& sels,
              std::shared_ptr<PropertyDeclarationBlock> decls,
              std::unique_ptr<CssRules> nested_rules = nullptr,
              SourceLocation loc = SourceLocation())
        : selectors(sels)
        , block(std::move(decls))
        , rules(std::move(nested_rules))
        , source_location(loc)
    {}

    // Copy constructor
    StyleRule(const StyleRule& other)
        : selectors(other.selectors)
        , block(other.block ? std::make_shared<PropertyDeclarationBlock>(*other.block) : std::make_shared<PropertyDeclarationBlock>())
        , rules(other.rules ? std::make_unique<CssRules>(*other.rules) : nullptr)
        , source_location(other.source_location)
    {}

    // Move constructor
    StyleRule(StyleRule&& other) noexcept = default;

    // Copy assignment
    StyleRule& operator=(const StyleRule& other) {
        if (this != &other) {
            selectors = other.selectors;
            block = other.block ? std::make_shared<PropertyDeclarationBlock>(*other.block) : std::make_shared<PropertyDeclarationBlock>();
            rules = other.rules ? std::make_unique<CssRules>(*other.rules) : nullptr;
            source_location = other.source_location;
        }
        return *this;
    }

    // Move assignment
    StyleRule& operator=(StyleRule&& other) noexcept = default;

    /**
     * Measure heap usage (approximate).
     * Translated from: impl StyleRule::size_of()
     */
    size_t SizeOf() const {
        size_t n = 0;
        n += selectors.SizeOf();
        n += sizeof(PropertyDeclarationBlock);
        if (block) {
            n += block->SizeOf();
        }
        if (rules) {
            n += sizeof(CssRules);
            // Add rules size if needed
        }
        return n;
    }

    /**
     * Get the declaration block (always non-null).
     */
    PropertyDeclarationBlock& GetBlock() { return *block; }
    const PropertyDeclarationBlock& GetBlock() const { return *block; }

    /**
     * Check if this style rule has nested rules.
     */
    bool HasNestedRules() const { return rules != nullptr && !rules->IsEmpty(); }

    /**
     * Serialize to CSS text.
     * https://drafts.csswg.org/cssom/#serialize-a-css-rule CSSStyleRule
     */
    std::string ToCss() const {
        std::ostringstream oss;
        oss << selectors.ToCss() << " ";

        // Opening brace
        oss << "{";

        // Step 2 - declarations
        bool has_declarations = block && !block->IsEmpty();

        // Step 3 - nested rules
        if (rules && !rules->IsEmpty()) {
            if (has_declarations) {
                oss << "\n  " << block->ToCss();
            }
            oss << "\n" << rules->ToCss();
            oss << "\n}";
            return oss.str();
        }

        // Steps 4 & 5
        if (has_declarations) {
            oss << " " << block->ToCss();
        }
        oss << " }";
        return oss.str();
    }

    /**
     * Deep clone this style rule.
     * Translated from: impl DeepCloneWithLock for StyleRule
     */
    StyleRule DeepClone() const {
        StyleRule clone;
        clone.selectors = selectors;
        clone.block = block ? std::make_shared<PropertyDeclarationBlock>(*block) : std::make_shared<PropertyDeclarationBlock>();
        clone.rules = rules ? std::make_unique<CssRules>(*rules) : nullptr;
        clone.source_location = source_location;
        return clone;
    }

    /**
     * Debug string.
     */
    std::string ToDebugString() const {
        std::ostringstream oss;
        oss << "StyleRule{ selectors=[" << selectors.ToCss() << "]";
        if (block) {
            oss << ", declarations={" << block->ToCss() << "}";
        }
        oss << ", source=" << source_location.ToString()
            << ", has_nested_rules=" << HasNestedRules()
            << " }";
        return oss.str();
    }

    bool operator==(const StyleRule& other) const {
        return selectors == other.selectors &&
               ((!block && !other.block) || (block && other.block && *block == *other.block)) &&
               source_location == other.source_location;
    }
};

// ============================================================================
// CssRules forward declaration implementation
// ============================================================================

// CssRules is already defined in stylesheets.hpp/cpp.
// Here we just ensure it's fully available for StyleRule.

// ============================================================================
// Test utilities for style rules
// ============================================================================

namespace test {

/**
 * Create a mock style rule for testing.
 *
 * Example usage:
 *   auto rule = MakeTestStyleRule("div.foo", "color", "red");
 */
inline StyleRule MakeTestStyleRule(
    const std::string& selector,
    const std::string& property = "color",
    const std::string& value = "red")
{
    SelectorList selectors({selector});
    auto block = std::make_shared<PropertyDeclarationBlock>();
    block->AddDeclaration(property, value);
    return StyleRule(selectors, block, nullptr, MakeTestSourceLocation());
}

/**
 * Create a mock style rule with multiple declarations.
 */
inline StyleRule MakeTestStyleRuleMulti(
    const std::string& selector,
    const std::vector<std::pair<std::string, std::string>>& declarations)
{
    SelectorList selectors({selector});
    auto block = std::make_shared<PropertyDeclarationBlock>();
    for (const auto& [prop, val] : declarations) {
        block->AddDeclaration(prop, val);
    }
    return StyleRule(selectors, block, nullptr, MakeTestSourceLocation());
}

/**
 * Verify that a style rule serializes to expected CSS.
 */
inline bool VerifyStyleRuleCss(const StyleRule& rule, const std::string& expected) {
    std::string css = rule.ToCss();
    if (css != expected) {
        std::cerr << "FAIL: StyleRule CSS mismatch\n"
                  << "  Expected: " << expected << "\n"
                  << "  Got:      " << css << std::endl;
        return false;
    }
    return true;
}

} // namespace test

} // namespace stylesheets
} // namespace style
