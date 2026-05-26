/* MPL 2.0 */
//! DOM traits and helpers for style resolution.
//! Corresponds to dom.rs (968 lines)
#pragma once
#include <string>
#include <optional>
#include "style/values/types.hpp"

namespace style { namespace dom {

using values::AtomIdent;

/// Information about an element needed for style resolution.
enum class ElementState : uint64_t {
    None = 0, Focus = 1, Hover = 2, Active = 4, Enabled = 8, Disabled = 16,
    Checked = 32, Indeterminate = 64, ReadOnly = 128, ReadWrite = 256,
    PlaceholderShown = 512, Default = 1024, Optional = 2048, Required = 4096,
    Valid = 8192, Invalid = 16384, InRange = 32768, OutOfRange = 65536,
    Visited = 131072, Unvisited = 262144, Target = 524288, Fullscreen = 1048576,
    Modal = 2097152, PopoverOpen = 4194304, DirAttrLTR = 8388608, DirAttrRTL = 16777216,
};
inline ElementState operator|(ElementState a, ElementState b) { return static_cast<ElementState>(static_cast<uint64_t>(a)|static_cast<uint64_t>(b)); }
inline ElementState operator&(ElementState a, ElementState b) { return static_cast<ElementState>(static_cast<uint64_t>(a)&static_cast<uint64_t>(b)); }
inline bool has_state(ElementState flags, ElementState test) { return (static_cast<uint64_t>(flags)&static_cast<uint64_t>(test))!=0; }

/// TElement trait: interface that DOM elements must implement for Stylo.
class TElement {
public:
    virtual ~TElement() = default;
    virtual bool is_element() const = 0;
    virtual bool is_text_node() const = 0;
    virtual const char* tag_name() const = 0;
    virtual const char* namespace_uri() const = 0;
    virtual std::optional<AtomIdent> id() const = 0;
    virtual bool has_id() const = 0;
    virtual std::vector<AtomIdent> class_list() const = 0;
    virtual bool has_class(const AtomIdent& cls) const = 0;
    virtual std::optional<std::string> attr(const char* name) const = 0;
    virtual bool has_attr(const char* name) const = 0;
    virtual ElementState state() const = 0;
    virtual bool has_state(ElementState s) const = 0;
    virtual const TElement* parent_element() const = 0;
    virtual const TElement* first_child() const = 0;
    virtual const TElement* next_sibling() const = 0;
    virtual const TElement* prev_sibling() const = 0;
    virtual bool is_root() const = 0;
    virtual bool is_in_document() const = 0;
    virtual bool is_in_shadow_tree() const = 0;
    virtual const TElement* shadow_root() const = 0;
    virtual const TElement* containing_shadow_host() const = 0;
    virtual std::string lang() const = 0;
    virtual bool has_snapshot() const = 0;
    virtual bool has_pending_restyle() const = 0;
    virtual void* get_existing_style() const = 0;
    virtual bool has_css_animations() const = 0;
    virtual bool has_css_transitions() const = 0;
    virtual bool is_link() const = 0;
    virtual bool is_visited_link() const = 0;
};

/// TNode trait: base interface for DOM nodes.
class TNode {
public:
    virtual ~TNode() = default;
    virtual const TNode* parent_node() const = 0;
    virtual const TNode* first_child() const = 0;
    virtual const TNode* last_child() const = 0;
    virtual const TNode* prev_sibling() const = 0;
    virtual const TNode* next_sibling() const = 0;
    virtual bool is_element() const = 0;
    virtual bool is_document() const = 0;
    virtual const TElement* as_element() const = 0;
    virtual TElement* as_element() = 0;
};

/// TDocument trait: document-level information.
class TDocument {
public:
    virtual ~TDocument() = default;
    virtual const TElement* root_element() const = 0;
    virtual bool is_html_document() const = 0;
    virtual int quirks_mode() const = 0;  // 0=no quirks, 1=limited, 2=quirks
};

/// Opaque node pointer for FFI compatibility.
using OpaqueNode = const void*;
inline OpaqueNode opaque(const TNode& node) { return &node; }

} // namespace dom
} // namespace style
