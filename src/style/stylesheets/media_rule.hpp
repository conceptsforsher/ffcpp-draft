/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

/**
 * @file media_rule.hpp
 * @brief A @media rule with media queries and nested rules.
 *
 * Translated from servo/components/style/stylesheets/media_rule.rs
 */

#pragma once

#include "style/stylesheets/stylesheets.hpp"
#include <string>
#include <memory>
#include <sstream>
#include <vector>

namespace style {
namespace stylesheets {

// ============================================================================
// MediaList - A list of media queries
// ============================================================================

/**
 * A list of media queries.
 *
 * In the full implementation this uses the media_queries module.
 * Here it's represented as a list of serialized media query strings.
 */
class MediaList {
public:
    MediaList() = default;

    explicit MediaList(const std::vector<std::string>& queries)
        : queries_(queries) {}

    /**
     * Parse a media list from a CSS string.
     * Simplified version that stores the raw string.
     */
    static MediaList Parse(const std::string& css) {
        MediaList list;
        list.raw_css_ = css;
        // Split on commas for multiple queries
        if (css.empty()) return list;
        size_t start = 0;
        size_t comma;
        while ((comma = css.find(',', start)) != std::string::npos) {
            std::string q = css.substr(start, comma - start);
            // Trim whitespace
            while (!q.empty() && q.front() == ' ') q.erase(0, 1);
            while (!q.empty() && q.back() == ' ') q.pop_back();
            if (!q.empty()) list.queries_.push_back(q);
            start = comma + 1;
        }
        std::string q = css.substr(start);
        while (!q.empty() && q.front() == ' ') q.erase(0, 1);
        while (!q.empty() && q.back() == ' ') q.pop_back();
        if (!q.empty()) list.queries_.push_back(q);
        return list;
    }

    const std::vector<std::string>& Queries() const { return queries_; }
    std::vector<std::string>& Queries() { return queries_; }

    bool IsEmpty() const { return queries_.empty(); }
    size_t Size() const { return queries_.size(); }

    /**
     * Evaluate the media queries against a device.
     * Simplified: always returns true (matching all).
     */
    bool Evaluate(class Device* device = nullptr) const {
        // In a real implementation, this would check media features.
        return true;
    }

    /**
     * Serialize to CSS text.
     */
    std::string ToCss() const {
        if (!raw_css_.empty()) return raw_css_;
        if (queries_.empty()) return "all";
        std::ostringstream oss;
        bool first = true;
        for (const auto& q : queries_) {
            if (!first) oss << ", ";
            first = false;
            oss << q;
        }
        return oss.str();
    }

    bool operator==(const MediaList& other) const {
        return queries_ == other.queries_;
    }

private:
    std::vector<std::string> queries_;
    std::string raw_css_; // Original CSS text
};

// ============================================================================
// MediaRule - A @media rule
// ============================================================================

/**
 * An @media rule.
 *
 * https://drafts.csswg.org/css-conditional/#at-ruledef-media
 *
 * Translated from: struct MediaRule
 */
class MediaRule {
public:
    /// The list of media queries used by this media rule.
    MediaList media_queries;

    /// The nested rules to this media rule.
    std::unique_ptr<CssRules> rules;

    /// The source position where this media rule was found.
    SourceLocation source_location;

    MediaRule()
        : rules(std::make_unique<CssRules>())
    {}

    MediaRule(const MediaList& mq,
              std::unique_ptr<CssRules> nested_rules,
              SourceLocation loc = SourceLocation())
        : media_queries(mq)
        , rules(std::move(nested_rules))
        , source_location(loc)
    {}

    // Copy
    MediaRule(const MediaRule& other)
        : media_queries(other.media_queries)
        , rules(other.rules ? std::make_unique<CssRules>(*other.rules) : std::make_unique<CssRules>())
        , source_location(other.source_location)
    {}

    // Move
    MediaRule(MediaRule&&) noexcept = default;
    MediaRule& operator=(MediaRule&&) noexcept = default;

    MediaRule& operator=(const MediaRule& other) {
        if (this != &other) {
            media_queries = other.media_queries;
            rules = other.rules ? std::make_unique<CssRules>(*other.rules) : std::make_unique<CssRules>();
            source_location = other.source_location;
        }
        return *this;
    }

    /**
     * Measure heap usage.
     */
    size_t SizeOf() const {
        size_t n = sizeof(MediaRule);
        // Add rules size
        return n;
    }

    /**
     * Serialize to CSS text.
     * https://drafts.csswg.org/cssom/#serialize-a-css-rule CSSMediaRule
     */
    std::string ToCss() const {
        std::ostringstream oss;
        oss << "@media " << media_queries.ToCss();
        if (rules) {
            oss << " " << rules->ToCssBlock();
        } else {
            oss << " {}";
        }
        return oss.str();
    }

    /**
     * Deep clone this media rule.
     */
    MediaRule DeepClone() const {
        return MediaRule(
            media_queries,
            rules ? std::make_unique<CssRules>(*rules) : std::make_unique<CssRules>(),
            source_location
        );
    }

    std::string ToDebugString() const {
        std::ostringstream oss;
        oss << "MediaRule{ media=" << media_queries.ToCss()
            << ", source=" << source_location.ToString()
            << ", rules_count=" << (rules ? std::to_string(rules->Size()) : "0")
            << " }";
        return oss.str();
    }
};

// ============================================================================
// Test utilities
// ============================================================================

namespace test {

inline MediaRule MakeTestMediaRule(
    const std::string& media_query = "screen",
    std::unique_ptr<CssRules> rules = nullptr)
{
    MediaList ml({media_query});
    return MediaRule(ml, rules ? std::move(rules) : std::make_unique<CssRules>(),
                     MakeTestSourceLocation());
}

} // namespace test

} // namespace stylesheets
} // namespace style
