/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "style/stylesheets/stylesheets.hpp"
#include "style/stylesheets/style_rule.hpp"
#include "style/stylesheets/namespace_rule.hpp"
#include "style/stylesheets/import_rule.hpp"
#include "style/stylesheets/media_rule.hpp"
#include "style/stylesheets/container_rule.hpp"
#include "style/stylesheets/font_face_rule.hpp"
#include "style/stylesheets/keyframes_rule.hpp"
#include "style/stylesheets/supports_rule.hpp"
#include "style/stylesheets/page_rule.hpp"
#include "style/stylesheets/layer_rule.hpp"
#include "style/stylesheets/scope_rule.hpp"
#include "style/stylesheets/counter_style_rule.hpp"

#include <iostream>
#include <cassert>
#include <algorithm>

namespace style {
namespace stylesheets {

// ============================================================================
// CssRule destructor and copy/move helpers
// ============================================================================

void CssRule::DestroyRule() {
    switch (tag_) {
        case Tag::Style: delete style_rule_ptr_; break;
        case Tag::Namespace: delete namespace_rule_ptr_; break;
        case Tag::Import: delete import_rule_ptr_; break;
        case Tag::Media: delete media_rule_ptr_; break;
        case Tag::Container: delete container_rule_ptr_; break;
        case Tag::FontFace: delete font_face_rule_ptr_; break;
        case Tag::FontFeatureValues: delete font_feature_values_rule_ptr_; break;
        case Tag::FontPaletteValues: delete font_palette_values_rule_ptr_; break;
        case Tag::CounterStyle: delete counter_style_rule_ptr_; break;
        case Tag::Keyframes: delete keyframes_rule_ptr_; break;
        case Tag::Margin: delete margin_rule_ptr_; break;
        case Tag::Supports: delete supports_rule_ptr_; break;
        case Tag::Page: delete page_rule_ptr_; break;
        case Tag::Property: delete property_rule_ptr_; break;
        case Tag::Document: delete document_rule_ptr_; break;
        case Tag::LayerBlock: delete layer_block_rule_ptr_; break;
        case Tag::LayerStatement: delete layer_statement_rule_ptr_; break;
        case Tag::Scope: delete scope_rule_ptr_; break;
        case Tag::StartingStyle: delete starting_style_rule_ptr_; break;
        case Tag::PositionTry: delete position_try_rule_ptr_; break;
        case Tag::NestedDeclarations: delete nested_declarations_rule_ptr_; break;
    }
    // Null all pointers to prevent double-free
    style_rule_ptr_ = nullptr;
}

void CssRule::MoveFrom(CssRule&& other) {
    tag_ = other.tag_;
    switch (tag_) {
        case Tag::Style: style_rule_ptr_ = other.style_rule_ptr_; break;
        case Tag::Namespace: namespace_rule_ptr_ = other.namespace_rule_ptr_; break;
        case Tag::Import: import_rule_ptr_ = other.import_rule_ptr_; break;
        case Tag::Media: media_rule_ptr_ = other.media_rule_ptr_; break;
        case Tag::Container: container_rule_ptr_ = other.container_rule_ptr_; break;
        case Tag::FontFace: font_face_rule_ptr_ = other.font_face_rule_ptr_; break;
        case Tag::FontFeatureValues: font_feature_values_rule_ptr_ = other.font_feature_values_rule_ptr_; break;
        case Tag::FontPaletteValues: font_palette_values_rule_ptr_ = other.font_palette_values_rule_ptr_; break;
        case Tag::CounterStyle: counter_style_rule_ptr_ = other.counter_style_rule_ptr_; break;
        case Tag::Keyframes: keyframes_rule_ptr_ = other.keyframes_rule_ptr_; break;
        case Tag::Margin: margin_rule_ptr_ = other.margin_rule_ptr_; break;
        case Tag::Supports: supports_rule_ptr_ = other.supports_rule_ptr_; break;
        case Tag::Page: page_rule_ptr_ = other.page_rule_ptr_; break;
        case Tag::Property: property_rule_ptr_ = other.property_rule_ptr_; break;
        case Tag::Document: document_rule_ptr_ = other.document_rule_ptr_; break;
        case Tag::LayerBlock: layer_block_rule_ptr_ = other.layer_block_rule_ptr_; break;
        case Tag::LayerStatement: layer_statement_rule_ptr_ = other.layer_statement_rule_ptr_; break;
        case Tag::Scope: scope_rule_ptr_ = other.scope_rule_ptr_; break;
        case Tag::StartingStyle: starting_style_rule_ptr_ = other.starting_style_rule_ptr_; break;
        case Tag::PositionTry: position_try_rule_ptr_ = other.position_try_rule_ptr_; break;
        case Tag::NestedDeclarations: nested_declarations_rule_ptr_ = other.nested_declarations_rule_ptr_; break;
    }
    // Nullify the source so its destructor does not delete
    other.style_rule_ptr_ = nullptr;
}

void CssRule::CopyFrom(const CssRule& other) {
    tag_ = other.tag_;
    switch (tag_) {
        case Tag::Style:
            style_rule_ptr_ = other.style_rule_ptr_ ? new StyleRule(*other.style_rule_ptr_) : nullptr;
            break;
        case Tag::Namespace:
            namespace_rule_ptr_ = other.namespace_rule_ptr_ ? new NamespaceRule(*other.namespace_rule_ptr_) : nullptr;
            break;
        case Tag::Import:
            import_rule_ptr_ = other.import_rule_ptr_ ? new ImportRule(*other.import_rule_ptr_) : nullptr;
            break;
        case Tag::Media:
            media_rule_ptr_ = other.media_rule_ptr_ ? new MediaRule(*other.media_rule_ptr_) : nullptr;
            break;
        case Tag::Container:
            container_rule_ptr_ = other.container_rule_ptr_ ? new ContainerRule(*other.container_rule_ptr_) : nullptr;
            break;
        case Tag::FontFace:
            font_face_rule_ptr_ = other.font_face_rule_ptr_ ? new FontFaceRule(*other.font_face_rule_ptr_) : nullptr;
            break;
        case Tag::FontFeatureValues:
            font_feature_values_rule_ptr_ = other.font_feature_values_rule_ptr_ ? new FontFeatureValuesRule(*other.font_feature_values_rule_ptr_) : nullptr;
            break;
        case Tag::FontPaletteValues:
            font_palette_values_rule_ptr_ = other.font_palette_values_rule_ptr_ ? new FontPaletteValuesRule(*other.font_palette_values_rule_ptr_) : nullptr;
            break;
        case Tag::CounterStyle:
            counter_style_rule_ptr_ = other.counter_style_rule_ptr_ ? new CounterStyleRule(*other.counter_style_rule_ptr_) : nullptr;
            break;
        case Tag::Keyframes:
            keyframes_rule_ptr_ = other.keyframes_rule_ptr_ ? new KeyframesRule(*other.keyframes_rule_ptr_) : nullptr;
            break;
        case Tag::Margin:
            margin_rule_ptr_ = other.margin_rule_ptr_ ? new MarginRule(*other.margin_rule_ptr_) : nullptr;
            break;
        case Tag::Supports:
            supports_rule_ptr_ = other.supports_rule_ptr_ ? new SupportsRule(*other.supports_rule_ptr_) : nullptr;
            break;
        case Tag::Page:
            page_rule_ptr_ = other.page_rule_ptr_ ? new PageRule(*other.page_rule_ptr_) : nullptr;
            break;
        case Tag::Property:
            property_rule_ptr_ = other.property_rule_ptr_ ? new PropertyRule(*other.property_rule_ptr_) : nullptr;
            break;
        case Tag::Document:
            document_rule_ptr_ = other.document_rule_ptr_ ? new DocumentRule(*other.document_rule_ptr_) : nullptr;
            break;
        case Tag::LayerBlock:
            layer_block_rule_ptr_ = other.layer_block_rule_ptr_ ? new LayerBlockRule(*other.layer_block_rule_ptr_) : nullptr;
            break;
        case Tag::LayerStatement:
            layer_statement_rule_ptr_ = other.layer_statement_rule_ptr_ ? new LayerStatementRule(*other.layer_statement_rule_ptr_) : nullptr;
            break;
        case Tag::Scope:
            scope_rule_ptr_ = other.scope_rule_ptr_ ? new ScopeRule(*other.scope_rule_ptr_) : nullptr;
            break;
        case Tag::StartingStyle:
            starting_style_rule_ptr_ = other.starting_style_rule_ptr_ ? new StartingStyleRule(*other.starting_style_rule_ptr_) : nullptr;
            break;
        case Tag::PositionTry:
            position_try_rule_ptr_ = other.position_try_rule_ptr_ ? new PositionTryRule(*other.position_try_rule_ptr_) : nullptr;
            break;
        case Tag::NestedDeclarations:
            nested_declarations_rule_ptr_ = other.nested_declarations_rule_ptr_ ? new NestedDeclarationsRule(*other.nested_declarations_rule_ptr_) : nullptr;
            break;
    }
}

// ============================================================================
// CssRule::ToCss() - Serialize to CSS text
// ============================================================================

std::string CssRule::ToCss() const {
    // In the real implementation, this delegates to each rule type's ToCss method.
    // Here we provide a simplified version.
    switch (tag_) {
        case Tag::Namespace:
            if (namespace_rule_ptr_) return namespace_rule_ptr_->ToCss();
            break;
        case Tag::Import:
            if (import_rule_ptr_) return import_rule_ptr_->ToCss();
            break;
        case Tag::Style:
            if (style_rule_ptr_) return style_rule_ptr_->ToCss();
            break;
        case Tag::FontFace:
            if (font_face_rule_ptr_) return font_face_rule_ptr_->ToCss();
            break;
        case Tag::FontFeatureValues:
            if (font_feature_values_rule_ptr_) return font_feature_values_rule_ptr_->ToCss();
            break;
        case Tag::FontPaletteValues:
            if (font_palette_values_rule_ptr_) return font_palette_values_rule_ptr_->ToCss();
            break;
        case Tag::CounterStyle:
            if (counter_style_rule_ptr_) return counter_style_rule_ptr_->ToCss();
            break;
        case Tag::Keyframes:
            if (keyframes_rule_ptr_) return keyframes_rule_ptr_->ToCss();
            break;
        case Tag::Margin:
            if (margin_rule_ptr_) return margin_rule_ptr_->ToCss();
            break;
        case Tag::Media:
            if (media_rule_ptr_) return media_rule_ptr_->ToCss();
            break;
        case Tag::Supports:
            if (supports_rule_ptr_) return supports_rule_ptr_->ToCss();
            break;
        case Tag::Page:
            if (page_rule_ptr_) return page_rule_ptr_->ToCss();
            break;
        case Tag::Property:
            if (property_rule_ptr_) return property_rule_ptr_->ToCss();
            break;
        case Tag::Document:
            if (document_rule_ptr_) return document_rule_ptr_->ToCss();
            break;
        case Tag::LayerBlock:
            if (layer_block_rule_ptr_) return layer_block_rule_ptr_->ToCss();
            break;
        case Tag::LayerStatement:
            if (layer_statement_rule_ptr_) return layer_statement_rule_ptr_->ToCss();
            break;
        case Tag::Container:
            if (container_rule_ptr_) return container_rule_ptr_->ToCss();
            break;
        case Tag::Scope:
            if (scope_rule_ptr_) return scope_rule_ptr_->ToCss();
            break;
        case Tag::StartingStyle:
            if (starting_style_rule_ptr_) return starting_style_rule_ptr_->ToCss();
            break;
        case Tag::PositionTry:
            if (position_try_rule_ptr_) return position_try_rule_ptr_->ToCss();
            break;
        case Tag::NestedDeclarations:
            if (nested_declarations_rule_ptr_) return nested_declarations_rule_ptr_->ToCss();
            break;
    }
    return "/* unknown rule */";
}

// ============================================================================
// CssRule::DeepClone() - Deep-clone this CssRule
// ============================================================================

CssRule CssRule::DeepClone() const {
    CssRule result;
    result.tag_ = tag_;
    switch (tag_) {
        case Tag::Style:
            result.style_rule_ptr_ = style_rule_ptr_ ? new StyleRule(*style_rule_ptr_) : nullptr;
            break;
        case Tag::Namespace:
            result.namespace_rule_ptr_ = namespace_rule_ptr_ ? new NamespaceRule(*namespace_rule_ptr_) : nullptr;
            break;
        case Tag::Import:
            result.import_rule_ptr_ = import_rule_ptr_ ? new ImportRule(*import_rule_ptr_) : nullptr;
            break;
        case Tag::Media:
            result.media_rule_ptr_ = media_rule_ptr_ ? new MediaRule(*media_rule_ptr_) : nullptr;
            break;
        case Tag::Container:
            result.container_rule_ptr_ = container_rule_ptr_ ? new ContainerRule(*container_rule_ptr_) : nullptr;
            break;
        case Tag::FontFace:
            result.font_face_rule_ptr_ = font_face_rule_ptr_ ? new FontFaceRule(*font_face_rule_ptr_) : nullptr;
            break;
        case Tag::FontFeatureValues:
            result.font_feature_values_rule_ptr_ = font_feature_values_rule_ptr_ ? new FontFeatureValuesRule(*font_feature_values_rule_ptr_) : nullptr;
            break;
        case Tag::FontPaletteValues:
            result.font_palette_values_rule_ptr_ = font_palette_values_rule_ptr_ ? new FontPaletteValuesRule(*font_palette_values_rule_ptr_) : nullptr;
            break;
        case Tag::CounterStyle:
            result.counter_style_rule_ptr_ = counter_style_rule_ptr_ ? new CounterStyleRule(*counter_style_rule_ptr_) : nullptr;
            break;
        case Tag::Keyframes:
            result.keyframes_rule_ptr_ = keyframes_rule_ptr_ ? new KeyframesRule(*keyframes_rule_ptr_) : nullptr;
            break;
        case Tag::Margin:
            result.margin_rule_ptr_ = margin_rule_ptr_ ? new MarginRule(*margin_rule_ptr_) : nullptr;
            break;
        case Tag::Supports:
            result.supports_rule_ptr_ = supports_rule_ptr_ ? new SupportsRule(*supports_rule_ptr_) : nullptr;
            break;
        case Tag::Page:
            result.page_rule_ptr_ = page_rule_ptr_ ? new PageRule(*page_rule_ptr_) : nullptr;
            break;
        case Tag::Property:
            result.property_rule_ptr_ = property_rule_ptr_ ? new PropertyRule(*property_rule_ptr_) : nullptr;
            break;
        case Tag::Document:
            result.document_rule_ptr_ = document_rule_ptr_ ? new DocumentRule(*document_rule_ptr_) : nullptr;
            break;
        case Tag::LayerBlock:
            result.layer_block_rule_ptr_ = layer_block_rule_ptr_ ? new LayerBlockRule(*layer_block_rule_ptr_) : nullptr;
            break;
        case Tag::LayerStatement:
            result.layer_statement_rule_ptr_ = layer_statement_rule_ptr_ ? new LayerStatementRule(*layer_statement_rule_ptr_) : nullptr;
            break;
        case Tag::Scope:
            result.scope_rule_ptr_ = scope_rule_ptr_ ? new ScopeRule(*scope_rule_ptr_) : nullptr;
            break;
        case Tag::StartingStyle:
            result.starting_style_rule_ptr_ = starting_style_rule_ptr_ ? new StartingStyleRule(*starting_style_rule_ptr_) : nullptr;
            break;
        case Tag::PositionTry:
            result.position_try_rule_ptr_ = position_try_rule_ptr_ ? new PositionTryRule(*position_try_rule_ptr_) : nullptr;
            break;
        case Tag::NestedDeclarations:
            result.nested_declarations_rule_ptr_ = nested_declarations_rule_ptr_ ? new NestedDeclarationsRule(*nested_declarations_rule_ptr_) : nullptr;
            break;
    }
    return result;
}

// ============================================================================
// CssRule::ToDebugString()
// ============================================================================

std::string CssRule::ToDebugString() const {
    std::ostringstream oss;
    oss << "CssRule{ type=" << CssRuleTypeName(RuleType())
        << ", tag=" << static_cast<int>(tag_);
    switch (tag_) {
        case Tag::Style: oss << ", has_style_rule=" << (style_rule_ptr_ != nullptr); break;
        case Tag::Namespace: oss << ", has_namespace=" << (namespace_rule_ptr_ != nullptr); break;
        case Tag::Import: oss << ", has_import=" << (import_rule_ptr_ != nullptr); break;
        case Tag::Media: oss << ", has_media=" << (media_rule_ptr_ != nullptr); break;
        case Tag::Container: oss << ", has_container=" << (container_rule_ptr_ != nullptr); break;
        case Tag::FontFace: oss << ", has_font_face=" << (font_face_rule_ptr_ != nullptr); break;
        case Tag::FontFeatureValues: oss << ", has_ffv=" << (font_feature_values_rule_ptr_ != nullptr); break;
        case Tag::FontPaletteValues: oss << ", has_fpv=" << (font_palette_values_rule_ptr_ != nullptr); break;
        case Tag::CounterStyle: oss << ", has_cs=" << (counter_style_rule_ptr_ != nullptr); break;
        case Tag::Keyframes: oss << ", has_kf=" << (keyframes_rule_ptr_ != nullptr); break;
        case Tag::Margin: oss << ", has_margin=" << (margin_rule_ptr_ != nullptr); break;
        case Tag::Supports: oss << ", has_supports=" << (supports_rule_ptr_ != nullptr); break;
        case Tag::Page: oss << ", has_page=" << (page_rule_ptr_ != nullptr); break;
        case Tag::Property: oss << ", has_property=" << (property_rule_ptr_ != nullptr); break;
        case Tag::Document: oss << ", has_document=" << (document_rule_ptr_ != nullptr); break;
        case Tag::LayerBlock: oss << ", has_layer_block=" << (layer_block_rule_ptr_ != nullptr); break;
        case Tag::LayerStatement: oss << ", has_layer_stmt=" << (layer_statement_rule_ptr_ != nullptr); break;
        case Tag::Scope: oss << ", has_scope=" << (scope_rule_ptr_ != nullptr); break;
        case Tag::StartingStyle: oss << ", has_starting_style=" << (starting_style_rule_ptr_ != nullptr); break;
        case Tag::PositionTry: oss << ", has_position_try=" << (position_try_rule_ptr_ != nullptr); break;
        case Tag::NestedDeclarations: oss << ", has_nested_decls=" << (nested_declarations_rule_ptr_ != nullptr); break;
    }
    oss << " }";
    return oss.str();
}

// ============================================================================
// StyleOrPageRuleToCss - Helper for serializing style/page rule bodies
// ============================================================================

std::string StyleOrPageRuleToCss(
    const PropertyDeclarationBlock* block,
    const CssRules* nested_rules)
{
    std::ostringstream oss;
    oss << " {";
    if (block) {
        oss << " " << block->ToCss();
    }
    if (nested_rules) {
        oss << "\n" << nested_rules->ToCss();
    }
    oss << " }";
    return oss.str();
}

// ============================================================================
// CssRules - List of CSS rules
// ============================================================================

/**
 * A list of CSS rules in a stylesheet or nested rule.
 *
 * Translated from: struct CssRules(Vec<CssRule>)
 */
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
    void Insert(size_t index, CssRule rule) {
        rules_.insert(rules_.begin() + static_cast<long>(index), std::move(rule));
    }
    void Remove(size_t index) {
        rules_.erase(rules_.begin() + static_cast<long>(index));
    }
    void Clear() { rules_.clear(); }

    std::string ToCss() const {
        std::ostringstream oss;
        for (const auto& rule : rules_) {
            oss << rule.ToCss() << "\n";
        }
        return oss.str();
    }

    std::string ToCssBlock() const {
        std::ostringstream oss;
        oss << "{";
        if (!rules_.empty()) {
            oss << "\n";
            for (const auto& rule : rules_) {
                oss << "  " << rule.ToCss() << "\n";
            }
        }
        oss << "}";
        return oss.str();
    }

private:
    std::vector<CssRule> rules_;
};

// ============================================================================
// SanitizationKind::Allows - Check if a rule type is allowed
// ============================================================================

bool SanitizationKindAllows(SanitizationKind kind, CssRuleType rule_type) {
    if (kind == SanitizationKind::None) return true;

    bool is_standard = (kind == SanitizationKind::Standard);

    // Rules that are always allowed (in any sanitization mode)
    switch (rule_type) {
        case CssRuleType::FontFace:
        case CssRuleType::Namespace:
        case CssRuleType::Style:
        case CssRuleType::NestedDeclarations:
        case CssRuleType::PositionTry:
            return true;

        // Rules that are never allowed during sanitization
        case CssRuleType::Document:
        case CssRuleType::Media:
        case CssRuleType::Supports:
        case CssRuleType::Import:
        case CssRuleType::Container:
        case CssRuleType::LayerStatement:
        case CssRuleType::LayerBlock:
        case CssRuleType::Scope:
        case CssRuleType::StartingStyle:
            return false;

        // Rules only allowed in non-standard sanitization
        case CssRuleType::Keyframes:
        case CssRuleType::Page:
        case CssRuleType::Margin:
        case CssRuleType::Property:
        case CssRuleType::FontFeatureValues:
        case CssRuleType::FontPaletteValues:
        case CssRuleType::CounterStyle:
            return !is_standard;

        default:
            return false;
    }
}

} // namespace stylesheets
} // namespace style
