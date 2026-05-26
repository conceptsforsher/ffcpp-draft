/* MPL 2.0 */
//! Rule tree — prefix tree for efficient cascade storage.
//! Corresponds to rule_tree/core.rs (772 lines), mod.rs, level.rs, map.rs, source.rs
#pragma once
#include <memory>
#include <vector>
#include <optional>
#include <cstdint>
#include <unordered_map>
#include <functional>

namespace style {

struct Rule;
struct PropertyDeclaration;

/// A node in the rule tree. The tree stores cascaded property values
/// in a prefix tree structure: shared rule paths are stored once,
/// with overrides at deeper nodes.
class RuleNode {
public:
    using Ptr = std::shared_ptr<RuleNode>;

    RuleNode* parent = nullptr;
    std::vector<Ptr> children;
    const Rule* rule = nullptr;
    uint32_t source_order = 0;

    // Cascaded property overrides at this node
    struct PropertyOverride {
        std::string name;
        std::string value;
        bool important = false;
    };
    std::vector<PropertyOverride> overrides;

    // Lazy-computed accumulated style
    mutable std::optional<void*> cached_style;

    RuleNode() = default;
    explicit RuleNode(const Rule* r, uint32_t order) : rule(r), source_order(order) {}

    /// Find or create a child node for a given rule.
    Ptr find_or_create_child(const Rule* r, uint32_t order);

    /// Walk up the tree accumulating all property overrides.
    void accumulate(std::vector<PropertyOverride>& result) const;

    /// Number of nodes in subtree.
    size_t subtree_size() const;
    size_t depth() const;

    /// Set a property override.
    void set_property(const std::string& name, const std::string& value, bool important = false);
    const std::string* get_property(const std::string& name) const;
};

/// The rule tree itself — root plus all nodes.
class RuleTree {
public:
    RuleTree();
    ~RuleTree();

    /// Get the root node (represents no rules / initial values).
    RuleNode::Ptr root() const { return root_; }

    /// Insert a cascade path (ordered list of rules) into the tree.
    RuleNode::Ptr insert(const std::vector<const Rule*>& rules,
                         const std::vector<uint32_t>& source_orders);

    /// Remove all nodes (e.g., on stylesheet change).
    void clear();

    /// Total number of nodes.
    size_t size() const;
    size_t max_depth() const;

    /// Memory usage estimate.
    size_t memory_usage() const;

private:
    RuleNode::Ptr root_;
    size_t node_count_ = 0;
};

// ─── Rule tree source ───
enum class RuleSource : uint8_t {
    StyleAttribute,
    Animation,
    Transition,
    CascadeLayer,
    Important,
    Inherited,
};

// ─── Cascade level ───
enum class CascadeLevel : uint8_t {
    Transitions = 0,
    ImportantAuthor = 1,
    Animations = 2,
    AuthorNormal = 3,
    ImportantUser = 4,
    UserNormal = 5,
    ImportantUA = 6,
    UANormal = 7,
};

inline int cascade_level_rank(CascadeLevel level) {
    switch (level) {
        case CascadeLevel::Transitions:     return 0;
        case CascadeLevel::ImportantAuthor: return 1;
        case CascadeLevel::Animations:      return 2;
        case CascadeLevel::AuthorNormal:    return 3;
        case CascadeLevel::ImportantUser:   return 4;
        case CascadeLevel::UserNormal:      return 5;
        case CascadeLevel::ImportantUA:     return 6;
        case CascadeLevel::UANormal:        return 7;
    }
    return 7;
}

} // namespace style
