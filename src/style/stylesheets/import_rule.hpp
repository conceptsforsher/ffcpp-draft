/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

/**
 * @file import_rule.hpp
 * @brief The @import at-rule for importing external stylesheets.
 *
 * Translated from servo/components/style/stylesheets/import_rule.rs
 */

#pragma once

#include "style/stylesheets/stylesheets.hpp"
#include "style/stylesheets/media_rule.hpp"
#include "style/stylesheets/layer_rule.hpp"

#include <string>
#include <memory>
#include <optional>
#include <sstream>

namespace style {
namespace stylesheets {

// ============================================================================
// ImportLayer - The layer specified in an import rule
// ============================================================================

/**
 * The layer specified in an import rule (can be none, anonymous, or named).
 *
 * Translated from: enum ImportLayer
 */
class ImportLayer {
public:
    enum class Kind {
        None,
        Anonymous,
        Named,
    };

    Kind kind = Kind::None;
    std::vector<std::string> layer_name; // Only valid for Named

    static ImportLayer MakeNone() { return ImportLayer(); }
    static ImportLayer MakeAnonymous() {
        ImportLayer l;
        l.kind = Kind::Anonymous;
        return l;
    }
    static ImportLayer MakeNamed(const std::vector<std::string>& name) {
        ImportLayer l;
        l.kind = Kind::Named;
        l.layer_name = name;
        return l;
    }

    /**
     * Serialize to CSS text.
     * Translated from: impl ToCss for ImportLayer
     */
    std::string ToCss() const {
        switch (kind) {
            case Kind::None: return "";
            case Kind::Anonymous: return "layer";
            case Kind::Named: {
                std::ostringstream oss;
                oss << "layer(";
                bool first = true;
                for (const auto& name : layer_name) {
                    if (!first) oss << ".";
                    first = false;
                    oss << name;
                }
                oss << ")";
                return oss.str();
            }
        }
        return "";
    }
};

// ============================================================================
// ImportSupportsCondition - Supports condition for import rules
// ============================================================================

/**
 * The supports condition in an import rule.
 *
 * Translated from: struct ImportSupportsCondition
 */
struct ImportSupportsCondition {
    /// The supports condition text.
    std::string condition;

    /// If the import is enabled, from the result of the import condition.
    bool enabled = true;

    ImportSupportsCondition() = default;
    ImportSupportsCondition(const std::string& cond, bool en = true)
        : condition(cond), enabled(en) {}

    std::string ToCss() const {
        return "supports(" + condition + ")";
    }
};

// ============================================================================
// ImportSheet - A sheet held from an import rule
// ============================================================================

/**
 * A sheet that is held from an import rule.
 *
 * Translated from: enum ImportSheet
 */
class ImportSheet {
public:
    enum class Kind {
        /// A bonafide stylesheet.
        Sheet,

        /// An @import created while parsing off-main-thread (Gecko).
        Pending,

        /// An @import created with a false supports condition.
        Refused,
    };

    Kind kind = Kind::Refused;

    ImportSheet() = default;
    explicit ImportSheet(Kind k) : kind(k) {}

    static ImportSheet MakeSheet() { return ImportSheet(Kind::Sheet); }
    static ImportSheet MakePending() { return ImportSheet(Kind::Pending); }
    static ImportSheet MakeRefused() { return ImportSheet(Kind::Refused); }

    /**
     * Returns whether this sheet is active.
     */
    bool IsActive() const { return kind == Kind::Sheet; }
    bool IsPending() const { return kind == Kind::Pending; }
    bool IsRefused() const { return kind == Kind::Refused; }

    std::string ToDebugString() const {
        switch (kind) {
            case Kind::Sheet: return "Sheet";
            case Kind::Pending: return "Pending";
            case Kind::Refused: return "Refused";
        }
        return "Unknown";
    }
};

// ============================================================================
// ImportRule - The @import at-rule
// ============================================================================

/**
 * The @import at-rule.
 *
 * https://drafts.csswg.org/css-cascade-3/#at-import
 *
 * Translated from: struct ImportRule
 */
class ImportRule {
public:
    /// The <url> this @import rule is loading.
    std::string url;

    /// The stylesheet is always present. In the case of gecko async parsing,
    /// we don't actually have a Gecko sheet at first, so the ImportSheet
    /// just has stub behavior until it appears.
    ImportSheet stylesheet;

    /// A <supports-condition> for the rule.
    std::optional<ImportSupportsCondition> supports;

    /// A layer() function name.
    ImportLayer layer;

    /// The line and column of the rule's source code.
    SourceLocation source_location;

    ImportRule() = default;

    ImportRule(const std::string& u,
               ImportSheet sheet = ImportSheet::MakeRefused(),
               std::optional<ImportSupportsCondition> supp = std::nullopt,
               ImportLayer lyr = ImportLayer::MakeNone(),
               SourceLocation loc = SourceLocation())
        : url(u)
        , stylesheet(std::move(sheet))
        , supports(std::move(supp))
        , layer(std::move(lyr))
        , source_location(loc)
    {}

    // Copy
    ImportRule(const ImportRule&) = default;
    ImportRule& operator=(const ImportRule&) = default;
    // Move
    ImportRule(ImportRule&&) noexcept = default;
    ImportRule& operator=(ImportRule&&) noexcept = default;

    /**
     * Parse the layer() / layer / supports() part of the import header.
     *
     * Translated from: ImportRule::parse_layer_and_supports()
     */
    static std::pair<ImportLayer, std::optional<ImportSupportsCondition>>
    ParseLayerAndSupports(const std::string& input);

    /**
     * Serialize to CSS text.
     */
    std::string ToCss() const {
        std::ostringstream oss;
        oss << "@import \"" << url << "\"";

        if (layer.kind != ImportLayer::Kind::None) {
            oss << " " << layer.ToCss();
        }

        if (supports.has_value()) {
            oss << " " << supports->ToCss();
        }

        // Media is handled by the stylesheet's media list

        oss << ";";
        return oss.str();
    }

    /**
     * Deep clone this import rule.
     */
    ImportRule DeepClone() const {
        return ImportRule(url, stylesheet, supports, layer, source_location);
    }

    std::string ToDebugString() const {
        std::ostringstream oss;
        oss << "ImportRule{ url=" << url
            << ", sheet=" << stylesheet.ToDebugString()
            << ", source=" << source_location.ToString()
            << " }";
        return oss.str();
    }
};

// ParseLayerAndSupports implementation
inline std::pair<ImportLayer, std::optional<ImportSupportsCondition>>
ImportRule::ParseLayerAndSupports(const std::string& input) {
    ImportLayer layer;
    std::optional<ImportSupportsCondition> supports;

    // Simplified parser: look for "layer" keyword and "supports()" function
    size_t pos = 0;
    std::string remaining = input;

    // Check for "layer" or "layer(name)"
    if (remaining.find("layer") == 0) {
        if (remaining.size() >= 6 && remaining.substr(0, 6) == "layer(") {
            size_t end = remaining.find(')', 6);
            if (end != std::string::npos) {
                std::string name_str = remaining.substr(6, end - 6);
                std::vector<std::string> name_parts;
                size_t dot;
                while ((dot = name_str.find('.', 0)) != std::string::npos) {
                    name_parts.push_back(name_str.substr(0, dot));
                    name_str = name_str.substr(dot + 1);
                }
                if (!name_str.empty()) name_parts.push_back(name_str);
                layer = ImportLayer::MakeNamed(name_parts);
                pos = end + 1;
            }
        } else {
            layer = ImportLayer::MakeAnonymous();
            pos = 5; // "layer"
        }
    }

    // Check for supports(condition)
    if (pos < remaining.size()) {
        std::string rest = remaining.substr(pos);
        while (!rest.empty() && rest.front() == ' ') rest.erase(0, 1);
        if (rest.find("supports(") == 0) {
            size_t start = 9; // "supports("
            size_t end = rest.find(')', start);
            if (end != std::string::npos) {
                std::string cond = rest.substr(start, end - start);
                supports = ImportSupportsCondition(cond, true);
            }
        }
    }

    return {layer, supports};
}

// ============================================================================
// Test utilities
// ============================================================================

namespace test {

inline ImportRule MakeTestImportRule(const std::string& url = "https://example.com/style.css") {
    ImportRule rule;
    rule.url = url;
    rule.stylesheet = ImportSheet::MakeRefused();
    return rule;
}

} // namespace test

} // namespace stylesheets
} // namespace style
