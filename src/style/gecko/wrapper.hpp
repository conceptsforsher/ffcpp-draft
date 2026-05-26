/* MPL 2.0 */
//! Gecko DOM element wrapper — FFI bridge between Rust Stylo and Gecko C++ DOM.
//! Corresponds to servo/components/style/gecko/wrapper.rs (2278 lines)
//! Translation: Rust → C++ (Gecko FFI wrappers become direct C++ DOM access)
#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include <optional>
#include <memory>
#include "style/values/types.hpp"
#include "style/stylist.hpp"

namespace style { namespace gecko {

// ─── Gecko Element wrapper ───
/// Wraps a Gecko nsINode/Element for style resolution.
/// In the pure C++ translation, this directly accesses the DOM.
class GeckoElement {
public:
    GeckoElement() = default;
    virtual ~GeckoElement() = default;

    // Identity
    virtual const char* tag_name() const = 0;
    virtual const char* local_name() const = 0;
    virtual const char* namespace_uri() const = 0;
    virtual const char* id() const = 0;
    virtual std::vector<std::string> class_list() const = 0;

    // Tree navigation
    virtual GeckoElement* parent_element() const = 0;
    virtual GeckoElement* first_child() const = 0;
    virtual GeckoElement* next_sibling() const = 0;
    virtual GeckoElement* prev_sibling() const = 0;
    virtual bool is_root() const = 0;
    virtual bool is_element() const = 0;
    virtual bool is_text_node() const = 0;

    // Attributes
    virtual std::optional<std::string> get_attr(const char* name) const = 0;
    virtual bool has_attr(const char* name) const = 0;
    virtual std::vector<std::string> attr_names() const = 0;

    // State
    virtual bool has_state(uint64_t state) const = 0;
    virtual bool is_link() const = 0;
    virtual bool is_visited_link() const = 0;
    virtual bool is_focus() const = 0;
    virtual bool is_hover() const = 0;
    virtual bool is_active() const = 0;
    virtual bool is_enabled() const = 0;
    virtual bool is_disabled() const = 0;
    virtual bool is_checked() const = 0;

    // Pseudo-elements
    virtual bool has_pseudo_element(PseudoElement pseudo) const = 0;

    // Snapshot (for restyle optimization)
    virtual bool has_snapshot() const = 0;

    // Computed style
    virtual void* get_existing_style() const = 0;
    virtual void set_style(void* computed_values) = 0;

    // Language
    virtual std::string lang_attr() const = 0;

    // Owner document
    virtual bool is_in_document() const = 0;
    virtual bool is_in_shadow_tree() const = 0;

    // XBL / Shadow DOM
    virtual GeckoElement* containing_shadow_host() const = 0;

    // Layout / frame
    virtual bool has_layout() const = 0;

protected:
    uint64_t state_flags_ = 0;
};

// ─── GeckoNode wrapper ───
class GeckoNode : public GeckoElement {
public:
    enum NodeType : uint8_t { ELEMENT=1, TEXT=3, COMMENT=8, DOCUMENT=9 };

    GeckoNode() = default;
    NodeType node_type = ELEMENT;
    std::string tag_name_;
    std::string local_name_;
    std::string namespace_uri_;
    std::string id_;
    std::vector<std::string> class_list_;
    std::unordered_map<std::string, std::string> attrs_;
    GeckoNode* parent_ = nullptr;
    std::vector<std::unique_ptr<GeckoNode>> children_;
    GeckoNode* next_ = nullptr;
    GeckoNode* prev_ = nullptr;
    void* style_ = nullptr;
    bool in_document_ = false;

    const char* tag_name() const override { return tag_name_.c_str(); }
    const char* local_name() const override { return local_name_.c_str(); }
    const char* namespace_uri() const override { return namespace_uri_.c_str(); }
    const char* id() const override { return id_.c_str(); }
    std::vector<std::string> class_list() const override { return class_list_; }

    GeckoElement* parent_element() const override { return parent_; }
    GeckoElement* first_child() const override { return children_.empty() ? nullptr : children_[0].get(); }
    GeckoElement* next_sibling() const override { return next_; }
    GeckoElement* prev_sibling() const override { return prev_; }
    bool is_root() const override { return !parent_; }
    bool is_element() const override { return node_type == ELEMENT; }
    bool is_text_node() const override { return node_type == TEXT; }

    std::optional<std::string> get_attr(const char* name) const override {
        auto it = attrs_.find(name);
        return it != attrs_.end() ? std::optional(it->second) : std::nullopt;
    }
    bool has_attr(const char* name) const override { return attrs_.count(name) > 0; }
    std::vector<std::string> attr_names() const override {
        std::vector<std::string> names;
        for (const auto& [k,v] : attrs_) names.push_back(k);
        return names;
    }

    bool has_state(uint64_t state) const override { return (state_flags_ & state) != 0; }
    bool is_link() const override { return has_state(1<<0); }
    bool is_visited_link() const override { return has_state(1<<1); }
    bool is_focus() const override { return has_state(1<<2); }
    bool is_hover() const override { return has_state(1<<3); }
    bool is_active() const override { return has_state(1<<4); }
    bool is_enabled() const override { return !has_state(1<<5); }
    bool is_disabled() const override { return has_state(1<<5); }
    bool is_checked() const override { return has_state(1<<6); }

    bool has_pseudo_element(PseudoElement) const override { return false; }
    bool has_snapshot() const override { return false; }
    void* get_existing_style() const override { return style_; }
    void set_style(void* s) override { style_ = s; }
    std::string lang_attr() const override { return get_attr("lang").value_or(""); }
    bool is_in_document() const override { return in_document_; }
    bool is_in_shadow_tree() const override { return false; }
    GeckoElement* containing_shadow_host() const override { return nullptr; }
    bool has_layout() const override { return true; }
};

// ─── Snapshot (for style change tracking) ───
struct Snapshot {
    bool class_changed = false;
    bool id_changed = false;
    bool other_attr_changed = false;
    bool state_changed = false;
    std::string old_id;
    std::vector<std::string> old_classes;
};

// ─── Restyle damage ───
enum class RestyleDamage : uint8_t {
    Empty = 0,
    Repaint = 1,
    Reflow = 2,
    ReflowAndRepaint = 3,
    ReconstructFrame = 4,
};

// ─── Traversal helpers ───
enum class TraversalBehavior : uint8_t {
    Normal,
    UnstyledChildrenOnly,
    UnstyledOnly,
};

struct TraversalFlags {
    bool for_animation_only = false;
    bool for_reconstruct = false;
    bool for_reflow = false;
    TraversalBehavior behavior = TraversalBehavior::Normal;

    static TraversalFlags normal() { return {}; }
    static TraversalFlags animation_only() {
        TraversalFlags f; f.for_animation_only = true; return f;
    }
};

} // namespace gecko
} // namespace style
