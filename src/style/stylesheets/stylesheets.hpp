/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

/**
 * @file stylesheets.hpp
 * @brief Main stylesheet module header - CSS rule types, CORS modes, UrlExtraData,
 *        and the core CssRule enum with CSSOM serialization support.
 *
 * Translated from servo/components/style/stylesheets/mod.rs
 * Covers all 22 CSS rule variant types with their CSSOM rule types,
 * serialization (ToCss), deep-cloning, and rule parsing.
 */

#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <variant>
#include <vector>
#include <functional>
#include <optional>
#include <sstream>
#include <iomanip>
#include <utility>

namespace style {
namespace stylesheets {

// ============================================================================
// Forward declarations for all rule types
// ============================================================================

class StyleRule;
class NamespaceRule;
class ImportRule;
class MediaRule;
class ContainerRule;
class FontFaceRule;
class FontFeatureValuesRule;
class FontPaletteValuesRule;
class CounterStyleRule;
class KeyframesRule;
class MarginRule;
class SupportsRule;
class PageRule;
class PropertyRule;
class DocumentRule;
class LayerBlockRule;
class LayerStatementRule;
class ScopeRule;
class StartingStyleRule;
class PositionTryRule;
class NestedDeclarationsRule;

class CssRules;
class MediaList;
class Stylesheet;
class StylesheetContents;

// ============================================================================
// CORS mode for CSS loads
// ============================================================================

/**
 * The CORS mode used for a CSS load.
 *
 * Translated from: enum CorsMode
 */
enum class CorsMode : uint8_t {
    /// No CORS mode, so cross-origin loads can be done.
    None = 0,

    /// Anonymous CORS request.
    Anonymous = 1,
};

/**
 * Convert CorsMode to string for serialization.
 */
inline const char* CorsModeToString(CorsMode mode) {
    switch (mode) {
        case CorsMode::None: return "none";
        case CorsMode::Anonymous: return "anonymous";
        default: return "unknown";
    }
}

// ============================================================================
// UrlExtraData - extra data for resolving URL values
// ============================================================================

/**
 * Extra data that the backend may need to resolve url values.
 *
 * In the C++ translation, this is a simplified version that holds:
 * - A base URL string
 * - A referrer info string
 * - Whether chrome rules are enabled
 * - An optional raw pointer for Gecko interop
 *
 * Translated from: struct UrlExtraData(usize)  (Gecko)
 *                  struct UrlExtraData(Arc<Url>) (Servo)
 */
class UrlExtraData {
public:
    /**
     * Construct a UrlExtraData with full parameters.
     * @param base_uri The base URI for relative URL resolution
     * @param referrer The referrer string
     * @param chrome_rules_enabled Whether chrome:// URLs are allowed
     */
    explicit UrlExtraData(const std::string& base_uri = "",
                          const std::string& referrer = "",
                          bool chrome_rules_enabled = false)
        : base_uri_(base_uri)
        , referrer_(referrer)
        , chrome_rules_enabled_(chrome_rules_enabled)
        , raw_ptr_(nullptr)
    {}

    /**
     * Construct from a raw pointer (for Gecko interop).
     * @param ptr Raw pointer to backing data
     * @param chrome_rules_enabled Whether chrome rules are enabled
     */
    explicit UrlExtraData(void* ptr, bool chrome_rules_enabled = false)
        : chrome_rules_enabled_(chrome_rules_enabled)
        , raw_ptr_(ptr)
    {}

    // Copy and move constructors
    UrlExtraData(const UrlExtraData& other) = default;
    UrlExtraData& operator=(const UrlExtraData& other) = default;
    UrlExtraData(UrlExtraData&& other) noexcept = default;
    UrlExtraData& operator=(UrlExtraData&& other) noexcept = default;

    /**
     * True if this URL scheme is chrome.
     */
    bool ChromeRulesEnabled() const { return chrome_rules_enabled_; }

    /**
     * Get the base URI as a string.
     */
    const std::string& BaseUri() const { return base_uri_; }

    /**
     * Set the base URI.
     */
    void SetBaseUri(const std::string& uri) { base_uri_ = uri; }

    /**
     * Get the referrer.
     */
    const std::string& Referrer() const { return referrer_; }

    /**
     * Set the referrer.
     */
    void SetReferrer(const std::string& ref) { referrer_ = ref; }

    /**
     * Get the raw pointer (for Gecko interop).
     */
    void* RawPtr() const { return raw_ptr_; }

    /**
     * Set the raw pointer.
     */
    void SetRawPtr(void* ptr) { raw_ptr_ = ptr; }

    /**
     * Equality comparison based on base URI and chrome rules.
     */
    bool operator==(const UrlExtraData& other) const {
        return base_uri_ == other.base_uri_ &&
               chrome_rules_enabled_ == other.chrome_rules_enabled_ &&
               referrer_ == other.referrer_;
    }

    bool operator!=(const UrlExtraData& other) const {
        return !(*this == other);
    }

    /**
     * Serialize to string for debugging.
     */
    std::string ToDebugString() const {
        std::ostringstream oss;
        oss << "UrlExtraData{ base_uri='" << base_uri_
            << "', referrer='" << referrer_
            << "', chrome_rules_enabled=" << chrome_rules_enabled_
            << " }";
        return oss.str();
    }

private:
    std::string base_uri_;
    std::string referrer_;
    bool chrome_rules_enabled_;
    void* raw_ptr_;
};

// ============================================================================
// CSSOM Rule Type Enumeration
// ============================================================================

/**
 * CSSOM rule type constants for all CSS rule types.
 *
 * https://drafts.csswg.org/cssom-1/#dom-cssrule-type
 *
 * Translated from: enum CssRuleType
 */
enum class CssRuleType : uint8_t {
    // https://drafts.csswg.org/cssom/#the-cssrule-interface
    Style = 1,
    // Charset = 2, // Historical, removed from CSSOM
    Import = 3,
    Media = 4,
    FontFace = 5,
    Page = 6,
    // https://drafts.csswg.org/css-animations-1/#interface-cssrule-idl
    Keyframes = 7,
    Keyframe = 8,
    // https://drafts.csswg.org/cssom/#the-cssrule-interface
    Margin = 9,
    Namespace = 10,
    // https://drafts.csswg.org/css-counter-styles-3/#extentions-to-cssrule-interface
    CounterStyle = 11,
    // https://drafts.csswg.org/css-conditional-3/#extentions-to-cssrule-interface
    Supports = 12,
    // https://www.w3.org/TR/2012/WD-css3-conditional-20120911/#extentions-to-cssrule-interface
    Document = 13,
    // https://drafts.csswg.org/css-fonts/#om-fontfeaturevalues
    FontFeatureValues = 14,
    // Additional types for modern CSS
    LayerBlock = 16,
    LayerStatement = 17,
    Container = 18,
    FontPaletteValues = 19,
    Property = 20,
    Scope = 21,
    // https://drafts.csswg.org/css-transitions-2/#the-cssstartingstylerule-interface
    StartingStyle = 22,
    // https://drafts.csswg.org/css-anchor-position-1/#om-position-try
    PositionTry = 23,
    // https://drafts.csswg.org/css-nesting-1/#nested-declarations-rule
    NestedDeclarations = 24,
};

/**
 * Returns a bit that identifies this rule type.
 * Translated from: impl CssRuleType::bit()
 */
inline constexpr uint32_t CssRuleTypeToBit(CssRuleType ty) {
    return 1u << static_cast<uint32_t>(ty);
}

/**
 * Get the string name of a CssRuleType for debugging.
 */
inline const char* CssRuleTypeName(CssRuleType ty) {
    switch (ty) {
        case CssRuleType::Style: return "Style";
        case CssRuleType::Import: return "Import";
        case CssRuleType::Media: return "Media";
        case CssRuleType::FontFace: return "FontFace";
        case CssRuleType::Page: return "Page";
        case CssRuleType::Keyframes: return "Keyframes";
        case CssRuleType::Keyframe: return "Keyframe";
        case CssRuleType::Margin: return "Margin";
        case CssRuleType::Namespace: return "Namespace";
        case CssRuleType::CounterStyle: return "CounterStyle";
        case CssRuleType::Supports: return "Supports";
        case CssRuleType::Document: return "Document";
        case CssRuleType::FontFeatureValues: return "FontFeatureValues";
        case CssRuleType::LayerBlock: return "LayerBlock";
        case CssRuleType::LayerStatement: return "LayerStatement";
        case CssRuleType::Container: return "Container";
        case CssRuleType::FontPaletteValues: return "FontPaletteValues";
        case CssRuleType::Property: return "Property";
        case CssRuleType::Scope: return "Scope";
        case CssRuleType::StartingStyle: return "StartingStyle";
        case CssRuleType::PositionTry: return "PositionTry";
        case CssRuleType::NestedDeclarations: return "NestedDeclarations";
        default: return "Unknown";
    }
}

// ============================================================================
// CssRuleTypes - Set of rule types (bitfield)
// ============================================================================

/**
 * Set of CssRuleType values, represented as a bitfield.
 *
 * Translated from: struct CssRuleTypes(u32)
 */
class CssRuleTypes {
public:
    /**
     * Default constructor - empty set.
     */
    constexpr CssRuleTypes() : bits_(0) {}

    /**
     * Construct from a single CssRuleType.
     */
    constexpr explicit CssRuleTypes(CssRuleType ty) : bits_(CssRuleTypeToBit(ty)) {}

    /**
     * Construct from raw bits.
     */
    constexpr explicit CssRuleTypes(uint32_t bits) : bits_(bits) {}

    /**
     * Rules where !important declarations are forbidden.
     * PositionTry and Keyframe rules.
     */
    static constexpr CssRuleTypes ImportantForbidden() {
        return CssRuleTypes(
            CssRuleTypeToBit(CssRuleType::PositionTry) |
            CssRuleTypeToBit(CssRuleType::Keyframe)
        );
    }

    /**
     * Returns whether the rule type is in the current set.
     */
    constexpr bool Contains(CssRuleType ty) const {
        return (bits_ & CssRuleTypeToBit(ty)) != 0;
    }

    /**
     * Returns the raw bits.
     */
    constexpr uint32_t Bits() const { return bits_; }

    /**
     * Creates from raw bits.
     */
    static constexpr CssRuleTypes FromBits(uint32_t bits) {
        return CssRuleTypes(bits);
    }

    /**
     * Returns whether the rule set is empty.
     */
    constexpr bool IsEmpty() const { return bits_ == 0; }

    /**
     * Inserts a rule type into the set.
     */
    void Insert(CssRuleType ty) {
        bits_ |= CssRuleTypeToBit(ty);
    }

    /**
     * Removes a rule type from the set.
     */
    void Remove(CssRuleType ty) {
        bits_ &= ~CssRuleTypeToBit(ty);
    }

    /**
     * Returns whether any of the types intersect.
     */
    constexpr bool Intersects(CssRuleTypes other) const {
        return (bits_ & other.bits_) != 0;
    }

    /**
     * Combine two sets (union).
     */
    constexpr CssRuleTypes operator|(CssRuleTypes other) const {
        return CssRuleTypes(bits_ | other.bits_);
    }

    /**
     * Intersection.
     */
    constexpr CssRuleTypes operator&(CssRuleTypes other) const {
        return CssRuleTypes(bits_ & other.bits_);
    }

    /**
     * Equality.
     */
    constexpr bool operator==(CssRuleTypes other) const { return bits_ == other.bits_; }
    constexpr bool operator!=(CssRuleTypes other) const { return bits_ != other.bits_; }

private:
    uint32_t bits_;
};

// ============================================================================
// RulesMutateError - Errors when mutating rule lists
// ============================================================================

/**
 * Errors that can occur when mutating CSS rule lists.
 *
 * Translated from: enum RulesMutateError
 */
enum class RulesMutateError {
    /// Syntax error in the CSS text
    Syntax,

    /// The index is out of bounds
    IndexSize,

    /// The rule cannot be inserted at this position (hierarchy violation)
    HierarchyRequest,

    /// Invalid state for the operation
    InvalidState,
};

inline const char* RulesMutateErrorToString(RulesMutateError err) {
    switch (err) {
        case RulesMutateError::Syntax: return "SyntaxError";
        case RulesMutateError::IndexSize: return "IndexSizeError";
        case RulesMutateError::HierarchyRequest: return "HierarchyRequestError";
        case RulesMutateError::InvalidState: return "InvalidStateError";
        default: return "UnknownError";
    }
}

// ============================================================================
// SourceLocation - Location in the source file
// ============================================================================

/**
 * Represents a location in a CSS source file (line, column, byte offset).
 *
 * Translated from: cssparser::SourceLocation
 */
struct SourceLocation {
    int32_t line = 0;
    int32_t column = 0;
    int32_t byte_offset = 0;

    constexpr SourceLocation() = default;
    constexpr SourceLocation(int32_t l, int32_t c, int32_t b = 0)
        : line(l), column(c), byte_offset(b) {}

    bool operator==(const SourceLocation& other) const {
        return line == other.line && column == other.column && byte_offset == other.byte_offset;
    }

    bool operator!=(const SourceLocation& other) const { return !(*this == other); }

    std::string ToString() const {
        return std::to_string(line) + ":" + std::to_string(column);
    }
};

// ============================================================================
// State - Parser state for top-level rules
// ============================================================================

/**
 * The current state of the parser for top-level rule ordering.
 *
 * Translated from: enum State
 */
enum class ParserState : uint8_t {
    /// We haven't started parsing rules.
    Start = 1,

    /// We're parsing early @layer statement rules.
    EarlyLayers = 2,

    /// We're parsing @import and early @layer statement rules.
    Imports = 3,

    /// We're parsing @namespace rules.
    Namespaces = 4,

    /// We're parsing the main body of the stylesheet.
    Body = 5,
};

inline const char* ParserStateName(ParserState state) {
    switch (state) {
        case ParserState::Start: return "Start";
        case ParserState::EarlyLayers: return "EarlyLayers";
        case ParserState::Imports: return "Imports";
        case ParserState::Namespaces: return "Namespaces";
        case ParserState::Body: return "Body";
        default: return "Unknown";
    }
}

// ============================================================================
// VendorPrefix - Vendor prefix type
// ============================================================================

/**
 * Vendor prefix for at-rules like @keyframes.
 *
 * Translated from: enum VendorPrefix
 */
enum class VendorPrefix {
    /// -moz prefix.
    Moz,

    /// -webkit prefix.
    WebKit,
};

inline const char* VendorPrefixToString(VendorPrefix p) {
    switch (p) {
        case VendorPrefix::Moz: return "-moz-";
        case VendorPrefix::WebKit: return "-webkit-";
        default: return "";
    }
}

// ============================================================================
// Origin - CSS Cascade Origins
// ============================================================================

/**
 * Each style rule has an origin, which determines where it enters the cascade.
 *
 * https://drafts.csswg.org/css-cascade/#cascading-origins
 *
 * Translated from: enum Origin
 */
enum class Origin : uint8_t {
    /// https://drafts.csswg.org/css-cascade/#cascade-origin-user-agent
    UserAgent = 0x1,

    /// https://drafts.csswg.org/css-cascade/#cascade-origin-user
    User = 0x2,

    /// https://drafts.csswg.org/css-cascade/#cascade-origin-author
    Author = 0x4,
};

inline const char* OriginToString(Origin origin) {
    switch (origin) {
        case Origin::UserAgent: return "UserAgent";
        case Origin::User: return "User";
        case Origin::Author: return "Author";
        default: return "Unknown";
    }
}

inline Origin OriginFromIndex(int8_t index) {
    switch (index) {
        case 0: return Origin::Author;
        case 1: return Origin::User;
        case 2: return Origin::UserAgent;
        default: return Origin::Author; // fallback
    }
}

inline int8_t OriginToIndex(Origin origin) {
    switch (origin) {
        case Origin::Author: return 0;
        case Origin::User: return 1;
        case Origin::UserAgent: return 2;
        default: return 0;
    }
}

// ============================================================================
// OriginSet - Set of origins
// ============================================================================

/**
 * A set of origins. Equivalent to Gecko's OriginFlags.
 *
 * Translated from: struct OriginSet(u8)
 */
class OriginSet {
public:
    // Constants matching bitflags
    static constexpr uint8_t ORIGIN_USER_AGENT = static_cast<uint8_t>(Origin::UserAgent);
    static constexpr uint8_t ORIGIN_USER = static_cast<uint8_t>(Origin::User);
    static constexpr uint8_t ORIGIN_AUTHOR = static_cast<uint8_t>(Origin::Author);

    constexpr OriginSet() : bits_(0) {}

    explicit constexpr OriginSet(uint8_t bits) : bits_(bits) {}

    /**
     * Construct from a single Origin.
     */
    explicit OriginSet(Origin origin) : bits_(static_cast<uint8_t>(origin)) {}

    uint8_t Bits() const { return bits_; }

    bool Contains(Origin origin) const {
        return (bits_ & static_cast<uint8_t>(origin)) != 0;
    }

    void Insert(Origin origin) {
        bits_ |= static_cast<uint8_t>(origin);
    }

    OriginSet operator|(OriginSet other) const {
        return OriginSet(static_cast<uint8_t>(bits_ | other.bits_));
    }

    OriginSet operator|(Origin origin) const {
        return OriginSet(static_cast<uint8_t>(bits_ | static_cast<uint8_t>(origin)));
    }

    bool operator==(OriginSet other) const { return bits_ == other.bits_; }
    bool operator!=(OriginSet other) const { return bits_ != other.bits_; }

    bool IsEmpty() const { return bits_ == 0; }

private:
    uint8_t bits_;
};

// ============================================================================
// AllowImportRules - Whether @import rules are allowed
// ============================================================================

/**
 * Whether @import rules are allowed when parsing a stylesheet.
 *
 * Translated from: enum AllowImportRules
 */
enum class AllowImportRules : uint8_t {
    /// @import rules will be parsed.
    Yes = 0,

    /// @import rules will not be parsed.
    No = 1,
};

// ============================================================================
// SanitizationKind - The kind of sanitization to apply
// ============================================================================

/**
 * The kind of sanitization to use when parsing a stylesheet.
 *
 * Translated from: enum SanitizationKind
 */
enum class SanitizationKind : uint8_t {
    /// Perform no sanitization.
    None = 0,

    /// Allow only @font-face, style rules, and @namespace.
    Standard = 1,

    /// Allow everything but conditional rules.
    NoConditionalRules = 2,
};

// ============================================================================
// AtRulePrelude - Prelude types for at-rules
// ============================================================================

/**
 * A variant representing the prelude of an at-rule (everything before the block).
 *
 * Translated from: enum AtRulePrelude
 */
using AtRulePrelude = std::variant<
    struct AtRulePreludeEmpty,           // @font-face, @starting-style
    std::vector<std::string>,            // @font-feature-values (family names)
    std::string,                          // @font-palette-values, @counter-style, @position-try (identifiers)
    struct AtRulePreludeMedia,           // @media
    struct AtRulePreludeContainer,        // @container
    struct AtRulePreludeSupports,        // @supports
    struct AtRulePreludeKeyframes,       // @keyframes
    struct AtRulePreludePage,            // @page
    struct AtRulePreludeProperty,        // @property
    struct AtRulePreludeDocument,        // @-moz-document
    struct AtRulePreludeImport,          // @import
    struct AtRulePreludeMargin,          // @margin
    struct AtRulePreludeNamespace,       // @namespace
    struct AtRulePreludeLayer,           // @layer
    struct AtRulePreludeScope            // @scope
>;

/// Marker for empty preludes (@font-face, @starting-style)
struct AtRulePreludeEmpty {
    std::string name; // "font-face" or "starting-style"
};

/// @media prelude with media query list
struct AtRulePreludeMedia {
    std::string media_queries; // Serialized media query list
};

/// @container prelude
struct AtRulePreludeContainer {
    std::string container_condition;
};

/// @supports prelude
struct AtRulePreludeSupports {
    std::string condition_text;
};

/// @keyframes prelude with animation name and vendor prefix
struct AtRulePreludeKeyframes {
    std::string animation_name;
    std::optional<VendorPrefix> vendor_prefix;
};

/// @page prelude with page selectors
struct AtRulePreludePage {
    std::string page_selectors;
};

/// @property prelude
struct AtRulePreludeProperty {
    std::string property_name;
};

/// @-moz-document prelude
struct AtRulePreludeDocument {
    std::string condition;
};

/// @import prelude
struct AtRulePreludeImport {
    std::string url;
    std::string media_list;
    std::optional<std::string> supports_condition;
    std::string layer;
};

/// @margin prelude
struct AtRulePreludeMargin {
    std::string margin_type;
};

/// @namespace prelude
struct AtRulePreludeNamespace {
    std::optional<std::string> prefix;
    std::string namespace_url;
};

/// @layer prelude
struct AtRulePreludeLayer {
    std::vector<std::string> layer_names;
};

/// @scope prelude
struct AtRulePreludeScope {
    std::optional<std::string> scope_start;
    std::optional<std::string> scope_end;
};

// ============================================================================
// Namespaces - Set of namespace definitions for a stylesheet
// ============================================================================

/**
 * A set of namespaces applying to a given stylesheet.
 *
 * Translated from: struct Namespaces
 */
class Namespaces {
public:
    /**
     * The default namespace (if any).
     */
    std::optional<std::string> default_namespace;

    /**
     * Map from prefix strings to namespace URLs.
     * In the original this is FxHashMap<Prefix, Namespace>.
     */
    std::vector<std::pair<std::string, std::string>> prefixes;

    Namespaces() = default;

    /**
     * Look up a namespace by prefix.
     * @return The namespace URL or empty string if not found.
     */
    std::string Lookup(const std::string& prefix) const {
        for (const auto& [p, ns] : prefixes) {
            if (p == prefix) return ns;
        }
        return "";
    }

    /**
     * Check if the namespaces set is empty.
     */
    bool IsEmpty() const {
        return !default_namespace.has_value() && prefixes.empty();
    }

    /**
     * Insert a prefix-namespace pair.
     */
    void Insert(const std::string& prefix, const std::string& ns) {
        for (auto& [p, n] : prefixes) {
            if (p == prefix) {
                n = ns;
                return;
            }
        }
        prefixes.emplace_back(prefix, ns);
    }

    /**
     * Clear all namespaces.
     */
    void Clear() {
        default_namespace.reset();
        prefixes.clear();
    }

    std::string ToString() const {
        std::ostringstream oss;
        if (default_namespace.has_value()) {
            oss << "default=" << default_namespace.value() << "; ";
        }
        for (const auto& [p, ns] : prefixes) {
            oss << p << "=" << ns << "; ";
        }
        return oss.str();
    }
};

// ============================================================================
// CssRule - The master variant type for all CSS rules
// ============================================================================

/**
 * The CssRule type: a variant over all possible CSS rule types.
 *
 * Translated from: enum CssRule
 */
class CssRule {
public:
    /**
     * Enum tag indicating which variant is active.
     */
    enum class Tag {
        Style,
        Namespace,
        Import,
        Media,
        Container,
        FontFace,
        FontFeatureValues,
        FontPaletteValues,
        CounterStyle,
        Keyframes,
        Margin,
        Supports,
        Page,
        Property,
        Document,
        LayerBlock,
        LayerStatement,
        Scope,
        StartingStyle,
        PositionTry,
        NestedDeclarations,
    };

    // === Constructors ===

    /// Construct an empty/invalid CssRule (for default initialization only)
    CssRule() : tag_(Tag::Style), style_rule_ptr_(nullptr) {}

    // Factory methods for each rule type
    static CssRule MakeStyle(StyleRule* rule) {
        CssRule r;
        r.tag_ = Tag::Style;
        r.style_rule_ptr_ = rule;
        return r;
    }

    static CssRule MakeNamespace(NamespaceRule* rule) {
        CssRule r;
        r.tag_ = Tag::Namespace;
        r.namespace_rule_ptr_ = rule;
        return r;
    }

    static CssRule MakeImport(ImportRule* rule) {
        CssRule r;
        r.tag_ = Tag::Import;
        r.import_rule_ptr_ = rule;
        return r;
    }

    static CssRule MakeMedia(MediaRule* rule) {
        CssRule r;
        r.tag_ = Tag::Media;
        r.media_rule_ptr_ = rule;
        return r;
    }

    static CssRule MakeContainer(ContainerRule* rule) {
        CssRule r;
        r.tag_ = Tag::Container;
        r.container_rule_ptr_ = rule;
        return r;
    }

    static CssRule MakeFontFace(FontFaceRule* rule) {
        CssRule r;
        r.tag_ = Tag::FontFace;
        r.font_face_rule_ptr_ = rule;
        return r;
    }

    static CssRule MakeFontFeatureValues(FontFeatureValuesRule* rule) {
        CssRule r;
        r.tag_ = Tag::FontFeatureValues;
        r.font_feature_values_rule_ptr_ = rule;
        return r;
    }

    static CssRule MakeFontPaletteValues(FontPaletteValuesRule* rule) {
        CssRule r;
        r.tag_ = Tag::FontPaletteValues;
        r.font_palette_values_rule_ptr_ = rule;
        return r;
    }

    static CssRule MakeCounterStyle(CounterStyleRule* rule) {
        CssRule r;
        r.tag_ = Tag::CounterStyle;
        r.counter_style_rule_ptr_ = rule;
        return r;
    }

    static CssRule MakeKeyframes(KeyframesRule* rule) {
        CssRule r;
        r.tag_ = Tag::Keyframes;
        r.keyframes_rule_ptr_ = rule;
        return r;
    }

    static CssRule MakeMargin(MarginRule* rule) {
        CssRule r;
        r.tag_ = Tag::Margin;
        r.margin_rule_ptr_ = rule;
        return r;
    }

    static CssRule MakeSupports(SupportsRule* rule) {
        CssRule r;
        r.tag_ = Tag::Supports;
        r.supports_rule_ptr_ = rule;
        return r;
    }

    static CssRule MakePage(PageRule* rule) {
        CssRule r;
        r.tag_ = Tag::Page;
        r.page_rule_ptr_ = rule;
        return r;
    }

    static CssRule MakeProperty(PropertyRule* rule) {
        CssRule r;
        r.tag_ = Tag::Property;
        r.property_rule_ptr_ = rule;
        return r;
    }

    static CssRule MakeDocument(DocumentRule* rule) {
        CssRule r;
        r.tag_ = Tag::Document;
        r.document_rule_ptr_ = rule;
        return r;
    }

    static CssRule MakeLayerBlock(LayerBlockRule* rule) {
        CssRule r;
        r.tag_ = Tag::LayerBlock;
        r.layer_block_rule_ptr_ = rule;
        return r;
    }

    static CssRule MakeLayerStatement(LayerStatementRule* rule) {
        CssRule r;
        r.tag_ = Tag::LayerStatement;
        r.layer_statement_rule_ptr_ = rule;
        return r;
    }

    static CssRule MakeScope(ScopeRule* rule) {
        CssRule r;
        r.tag_ = Tag::Scope;
        r.scope_rule_ptr_ = rule;
        return r;
    }

    static CssRule MakeStartingStyle(StartingStyleRule* rule) {
        CssRule r;
        r.tag_ = Tag::StartingStyle;
        r.starting_style_rule_ptr_ = rule;
        return r;
    }

    static CssRule MakePositionTry(PositionTryRule* rule) {
        CssRule r;
        r.tag_ = Tag::PositionTry;
        r.position_try_rule_ptr_ = rule;
        return r;
    }

    static CssRule MakeNestedDeclarations(NestedDeclarationsRule* rule) {
        CssRule r;
        r.tag_ = Tag::NestedDeclarations;
        r.nested_declarations_rule_ptr_ = rule;
        return r;
    }

    // === Accessors ===

    Tag GetTag() const { return tag_; }

    /**
     * Returns the CSSOM rule type of this rule.
     * Translated from: impl CssRule::rule_type()
     */
    CssRuleType RuleType() const {
        switch (tag_) {
            case Tag::Style: return CssRuleType::Style;
            case Tag::Import: return CssRuleType::Import;
            case Tag::Media: return CssRuleType::Media;
            case Tag::FontFace: return CssRuleType::FontFace;
            case Tag::FontFeatureValues: return CssRuleType::FontFeatureValues;
            case Tag::FontPaletteValues: return CssRuleType::FontPaletteValues;
            case Tag::CounterStyle: return CssRuleType::CounterStyle;
            case Tag::Keyframes: return CssRuleType::Keyframes;
            case Tag::Margin: return CssRuleType::Margin;
            case Tag::Namespace: return CssRuleType::Namespace;
            case Tag::Supports: return CssRuleType::Supports;
            case Tag::Page: return CssRuleType::Page;
            case Tag::Property: return CssRuleType::Property;
            case Tag::Document: return CssRuleType::Document;
            case Tag::LayerBlock: return CssRuleType::LayerBlock;
            case Tag::LayerStatement: return CssRuleType::LayerStatement;
            case Tag::Container: return CssRuleType::Container;
            case Tag::Scope: return CssRuleType::Scope;
            case Tag::StartingStyle: return CssRuleType::StartingStyle;
            case Tag::PositionTry: return CssRuleType::PositionTry;
            case Tag::NestedDeclarations: return CssRuleType::NestedDeclarations;
            default: return CssRuleType::Style;
        }
    }

    // Typed accessors with type checking
    StyleRule* AsStyleRule() { return tag_ == Tag::Style ? style_rule_ptr_ : nullptr; }
    NamespaceRule* AsNamespaceRule() { return tag_ == Tag::Namespace ? namespace_rule_ptr_ : nullptr; }
    ImportRule* AsImportRule() { return tag_ == Tag::Import ? import_rule_ptr_ : nullptr; }
    MediaRule* AsMediaRule() { return tag_ == Tag::Media ? media_rule_ptr_ : nullptr; }
    ContainerRule* AsContainerRule() { return tag_ == Tag::Container ? container_rule_ptr_ : nullptr; }
    FontFaceRule* AsFontFaceRule() { return tag_ == Tag::FontFace ? font_face_rule_ptr_ : nullptr; }
    FontFeatureValuesRule* AsFontFeatureValuesRule() { return tag_ == Tag::FontFeatureValues ? font_feature_values_rule_ptr_ : nullptr; }
    FontPaletteValuesRule* AsFontPaletteValuesRule() { return tag_ == Tag::FontPaletteValues ? font_palette_values_rule_ptr_ : nullptr; }
    CounterStyleRule* AsCounterStyleRule() { return tag_ == Tag::CounterStyle ? counter_style_rule_ptr_ : nullptr; }
    KeyframesRule* AsKeyframesRule() { return tag_ == Tag::Keyframes ? keyframes_rule_ptr_ : nullptr; }
    MarginRule* AsMarginRule() { return tag_ == Tag::Margin ? margin_rule_ptr_ : nullptr; }
    SupportsRule* AsSupportsRule() { return tag_ == Tag::Supports ? supports_rule_ptr_ : nullptr; }
    PageRule* AsPageRule() { return tag_ == Tag::Page ? page_rule_ptr_ : nullptr; }
    PropertyRule* AsPropertyRule() { return tag_ == Tag::Property ? property_rule_ptr_ : nullptr; }
    DocumentRule* AsDocumentRule() { return tag_ == Tag::Document ? document_rule_ptr_ : nullptr; }
    LayerBlockRule* AsLayerBlockRule() { return tag_ == Tag::LayerBlock ? layer_block_rule_ptr_ : nullptr; }
    LayerStatementRule* AsLayerStatementRule() { return tag_ == Tag::LayerStatement ? layer_statement_rule_ptr_ : nullptr; }
    ScopeRule* AsScopeRule() { return tag_ == Tag::Scope ? scope_rule_ptr_ : nullptr; }
    StartingStyleRule* AsStartingStyleRule() { return tag_ == Tag::StartingStyle ? starting_style_rule_ptr_ : nullptr; }
    PositionTryRule* AsPositionTryRule() { return tag_ == Tag::PositionTry ? position_try_rule_ptr_ : nullptr; }
    NestedDeclarationsRule* AsNestedDeclarationsRule() { return tag_ == Tag::NestedDeclarations ? nested_declarations_rule_ptr_ : nullptr; }

    // Const accessors
    const StyleRule* AsStyleRule() const { return tag_ == Tag::Style ? style_rule_ptr_ : nullptr; }
    const NamespaceRule* AsNamespaceRule() const { return tag_ == Tag::Namespace ? namespace_rule_ptr_ : nullptr; }
    const ImportRule* AsImportRule() const { return tag_ == Tag::Import ? import_rule_ptr_ : nullptr; }
    const MediaRule* AsMediaRule() const { return tag_ == Tag::Media ? media_rule_ptr_ : nullptr; }
    const ContainerRule* AsContainerRule() const { return tag_ == Tag::Container ? container_rule_ptr_ : nullptr; }
    const FontFaceRule* AsFontFaceRule() const { return tag_ == Tag::FontFace ? font_face_rule_ptr_ : nullptr; }
    const FontFeatureValuesRule* AsFontFeatureValuesRule() const { return tag_ == Tag::FontFeatureValues ? font_feature_values_rule_ptr_ : nullptr; }
    const FontPaletteValuesRule* AsFontPaletteValuesRule() const { return tag_ == Tag::FontPaletteValues ? font_palette_values_rule_ptr_ : nullptr; }
    const CounterStyleRule* AsCounterStyleRule() const { return tag_ == Tag::CounterStyle ? counter_style_rule_ptr_ : nullptr; }
    const KeyframesRule* AsKeyframesRule() const { return tag_ == Tag::Keyframes ? keyframes_rule_ptr_ : nullptr; }
    const MarginRule* AsMarginRule() const { return tag_ == Tag::Margin ? margin_rule_ptr_ : nullptr; }
    const SupportsRule* AsSupportsRule() const { return tag_ == Tag::Supports ? supports_rule_ptr_ : nullptr; }
    const PageRule* AsPageRule() const { return tag_ == Tag::Page ? page_rule_ptr_ : nullptr; }
    const PropertyRule* AsPropertyRule() const { return tag_ == Tag::Property ? property_rule_ptr_ : nullptr; }
    const DocumentRule* AsDocumentRule() const { return tag_ == Tag::Document ? document_rule_ptr_ : nullptr; }
    const LayerBlockRule* AsLayerBlockRule() const { return tag_ == Tag::LayerBlock ? layer_block_rule_ptr_ : nullptr; }
    const LayerStatementRule* AsLayerStatementRule() const { return tag_ == Tag::LayerStatement ? layer_statement_rule_ptr_ : nullptr; }
    const ScopeRule* AsScopeRule() const { return tag_ == Tag::Scope ? scope_rule_ptr_ : nullptr; }
    const StartingStyleRule* AsStartingStyleRule() const { return tag_ == Tag::StartingStyle ? starting_style_rule_ptr_ : nullptr; }
    const PositionTryRule* AsPositionTryRule() const { return tag_ == Tag::PositionTry ? position_try_rule_ptr_ : nullptr; }
    const NestedDeclarationsRule* AsNestedDeclarationsRule() const { return tag_ == Tag::NestedDeclarations ? nested_declarations_rule_ptr_ : nullptr; }

    /**
     * Check if this is a specific rule type by matching against the tag.
     * Useful for pattern-matching-like checks.
     */
    template <Tag tag>
    bool Is() const { return tag_ == tag; }

    /**
     * Serialize this rule to CSS text.
     * Translated from: impl ToCssWithGuard for CssRule
     */
    std::string ToCss() const;

    /**
     * Deep-clone this CssRule.
     * Translated from: impl DeepCloneWithLock for CssRule
     */
    CssRule DeepClone() const;

    /**
     * Release owned rule pointer and return a new copy if needed.
     * Caller is responsible for managing lifetime.
     */
    ~CssRule() { DestroyRule(); }

    // Move semantics
    CssRule(CssRule&& other) noexcept { MoveFrom(std::move(other)); }
    CssRule& operator=(CssRule&& other) noexcept {
        if (this != &other) {
            DestroyRule();
            MoveFrom(std::move(other));
        }
        return *this;
    }

    // Copy (deep-clones all rule pointers)
    CssRule(const CssRule& other) { CopyFrom(other); }
    CssRule& operator=(const CssRule& other) {
        if (this != &other) {
            DestroyRule();
            CopyFrom(other);
        }
        return *this;
    }

    /**
     * Debug string representation.
     */
    std::string ToDebugString() const;

private:
    Tag tag_;

    // Anonymous union of rule pointers
    union {
        StyleRule* style_rule_ptr_;
        NamespaceRule* namespace_rule_ptr_;
        ImportRule* import_rule_ptr_;
        MediaRule* media_rule_ptr_;
        ContainerRule* container_rule_ptr_;
        FontFaceRule* font_face_rule_ptr_;
        FontFeatureValuesRule* font_feature_values_rule_ptr_;
        FontPaletteValuesRule* font_palette_values_rule_ptr_;
        CounterStyleRule* counter_style_rule_ptr_;
        KeyframesRule* keyframes_rule_ptr_;
        MarginRule* margin_rule_ptr_;
        SupportsRule* supports_rule_ptr_;
        PageRule* page_rule_ptr_;
        PropertyRule* property_rule_ptr_;
        DocumentRule* document_rule_ptr_;
        LayerBlockRule* layer_block_rule_ptr_;
        LayerStatementRule* layer_statement_rule_ptr_;
        ScopeRule* scope_rule_ptr_;
        StartingStyleRule* starting_style_rule_ptr_;
        PositionTryRule* position_try_rule_ptr_;
        NestedDeclarationsRule* nested_declarations_rule_ptr_;
    };

    void DestroyRule();
    void MoveFrom(CssRule&& other);
    void CopyFrom(const CssRule& other);
};

// ============================================================================
// CssRules - Container of CSS rules (defined here for complete type visibility)
// ============================================================================
class CssRules {
public:
    CssRules() = default;
    explicit CssRules(std::vector<CssRule> rules) : rules_(std::move(rules)) {}
    const std::vector<CssRule>& Rules() const { return rules_; }
    std::vector<CssRule>& Rules() { return rules_; }
    size_t Size() const { return rules_.size(); }
    bool IsEmpty() const { return rules_.empty(); }
    const CssRule& operator[](size_t i) const { return rules_[i]; }
    CssRule& operator[](size_t i) { return rules_[i]; }
    void Append(CssRule rule) { rules_.push_back(std::move(rule)); }
    void Clear() { rules_.clear(); }
    std::string ToCss() const;
    std::string ToCssBlock() const;
    std::string ToDebugString() const;
private:
    std::vector<CssRule> rules_;
};

// ============================================================================
// StyleOrPageRuleToCss - Serialization helper
// ============================================================================

/**
 * Serialize a page or style rule, starting with the opening brace.
 *
 * https://drafts.csswg.org/cssom/#serialize-a-css-rule CSSStyleRule
 *
 * Translated from: fn style_or_page_rule_to_css()
 */
std::string StyleOrPageRuleToCss(
    const class PropertyDeclarationBlock* block,
    const CssRules* nested_rules);

// ============================================================================
// Test utilities
// ============================================================================

/**
 * Utility namespace containing helpers for testing stylesheet module
 * functionality.
 */
namespace test {

/**
 * Create a mock UrlExtraData for testing.
 */
inline UrlExtraData MakeTestUrlExtraData() {
    return UrlExtraData("https://example.com/test.css", "", false);
}

/**
 * Create a mock SourceLocation for testing.
 */
inline SourceLocation MakeTestSourceLocation() {
    return SourceLocation(1, 1, 0);
}

/**
 * Assert that two CssRuleTypes sets are equal, with error message.
 */
inline bool AssertCssRuleTypesEqual(CssRuleTypes a, CssRuleTypes b, const std::string& msg) {
    if (a != b) {
        std::cerr << "FAIL: " << msg << " - expected " << a.Bits()
                  << " but got " << b.Bits() << std::endl;
        return false;
    }
    return true;
}

/**
 * Create all standard rule type bits for comprehensive testing.
 */
inline CssRuleTypes MakeAllRuleTypes() {
    CssRuleTypes types;
    types.Insert(CssRuleType::Style);
    types.Insert(CssRuleType::Import);
    types.Insert(CssRuleType::Media);
    types.Insert(CssRuleType::FontFace);
    types.Insert(CssRuleType::Page);
    types.Insert(CssRuleType::Keyframes);
    types.Insert(CssRuleType::Keyframe);
    types.Insert(CssRuleType::Margin);
    types.Insert(CssRuleType::Namespace);
    types.Insert(CssRuleType::CounterStyle);
    types.Insert(CssRuleType::Supports);
    types.Insert(CssRuleType::Document);
    types.Insert(CssRuleType::FontFeatureValues);
    types.Insert(CssRuleType::LayerBlock);
    types.Insert(CssRuleType::LayerStatement);
    types.Insert(CssRuleType::Container);
    types.Insert(CssRuleType::FontPaletteValues);
    types.Insert(CssRuleType::Property);
    types.Insert(CssRuleType::Scope);
    types.Insert(CssRuleType::StartingStyle);
    types.Insert(CssRuleType::PositionTry);
    types.Insert(CssRuleType::NestedDeclarations);
    return types;
}

} // namespace test

} // namespace stylesheets
} // namespace style
