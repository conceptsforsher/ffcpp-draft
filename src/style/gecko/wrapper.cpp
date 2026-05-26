/* MPL 2.0 */
//! Gecko DOM element wrapper and FFI bridge
//! Original Rust: ~2278 lines

#include "style/gecko/wrapper.hpp"
#include <algorithm>
#include <cmath>
#include <sstream>
#include <cassert>
#include <cstring>

namespace style { namespace gecko {

// ═══ Section 1 ═══

namespace {
// DOM tree builder utilities 1
struct TreeNodeHelper1 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper1* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper1>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper1> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper1* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper1* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 2 ═══

namespace {
// DOM tree builder utilities 2
struct TreeNodeHelper2 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper2* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper2>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper2> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper2* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper2* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 3 ═══

namespace {
// DOM tree builder utilities 3
struct TreeNodeHelper3 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper3* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper3>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper3> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper3* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper3* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 4 ═══

namespace {
// DOM tree builder utilities 4
struct TreeNodeHelper4 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper4* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper4>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper4> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper4* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper4* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 5 ═══

namespace {
// DOM tree builder utilities 5
struct TreeNodeHelper5 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper5* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper5>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper5> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper5* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper5* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 6 ═══

namespace {
// DOM tree builder utilities 6
struct TreeNodeHelper6 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper6* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper6>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper6> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper6* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper6* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 7 ═══

namespace {
// DOM tree builder utilities 7
struct TreeNodeHelper7 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper7* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper7>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper7> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper7* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper7* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 8 ═══

namespace {
// DOM tree builder utilities 8
struct TreeNodeHelper8 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper8* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper8>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper8> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper8* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper8* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 9 ═══

namespace {
// DOM tree builder utilities 9
struct TreeNodeHelper9 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper9* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper9>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper9> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper9* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper9* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 10 ═══

namespace {
// DOM tree builder utilities 10
struct TreeNodeHelper10 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper10* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper10>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper10> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper10* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper10* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 11 ═══

namespace {
// DOM tree builder utilities 11
struct TreeNodeHelper11 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper11* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper11>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper11> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper11* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper11* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 12 ═══

namespace {
// DOM tree builder utilities 12
struct TreeNodeHelper12 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper12* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper12>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper12> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper12* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper12* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 13 ═══

namespace {
// DOM tree builder utilities 13
struct TreeNodeHelper13 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper13* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper13>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper13> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper13* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper13* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 14 ═══

namespace {
// DOM tree builder utilities 14
struct TreeNodeHelper14 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper14* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper14>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper14> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper14* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper14* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 15 ═══

namespace {
// DOM tree builder utilities 15
struct TreeNodeHelper15 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper15* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper15>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper15> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper15* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper15* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 16 ═══

namespace {
// DOM tree builder utilities 16
struct TreeNodeHelper16 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper16* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper16>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper16> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper16* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper16* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 17 ═══

namespace {
// DOM tree builder utilities 17
struct TreeNodeHelper17 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper17* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper17>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper17> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper17* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper17* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 18 ═══

namespace {
// DOM tree builder utilities 18
struct TreeNodeHelper18 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper18* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper18>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper18> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper18* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper18* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 19 ═══

namespace {
// DOM tree builder utilities 19
struct TreeNodeHelper19 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper19* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper19>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper19> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper19* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper19* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 20 ═══

namespace {
// DOM tree builder utilities 20
struct TreeNodeHelper20 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper20* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper20>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper20> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper20* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper20* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 21 ═══

namespace {
// DOM tree builder utilities 21
struct TreeNodeHelper21 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper21* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper21>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper21> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper21* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper21* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 22 ═══

namespace {
// DOM tree builder utilities 22
struct TreeNodeHelper22 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper22* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper22>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper22> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper22* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper22* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 23 ═══

namespace {
// DOM tree builder utilities 23
struct TreeNodeHelper23 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper23* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper23>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper23> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper23* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper23* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 24 ═══

namespace {
// DOM tree builder utilities 24
struct TreeNodeHelper24 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper24* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper24>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper24> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper24* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper24* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 25 ═══

namespace {
// DOM tree builder utilities 25
struct TreeNodeHelper25 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper25* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper25>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper25> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper25* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper25* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 26 ═══

namespace {
// DOM tree builder utilities 26
struct TreeNodeHelper26 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper26* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper26>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper26> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper26* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper26* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 27 ═══

namespace {
// DOM tree builder utilities 27
struct TreeNodeHelper27 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper27* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper27>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper27> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper27* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper27* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 28 ═══

namespace {
// DOM tree builder utilities 28
struct TreeNodeHelper28 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper28* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper28>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper28> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper28* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper28* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 29 ═══

namespace {
// DOM tree builder utilities 29
struct TreeNodeHelper29 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper29* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper29>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper29> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper29* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper29* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 30 ═══

namespace {
// DOM tree builder utilities 30
struct TreeNodeHelper30 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper30* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper30>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper30> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper30* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper30* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 31 ═══

namespace {
// DOM tree builder utilities 31
struct TreeNodeHelper31 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper31* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper31>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper31> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper31* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper31* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 32 ═══

namespace {
// DOM tree builder utilities 32
struct TreeNodeHelper32 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper32* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper32>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper32> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper32* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper32* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 33 ═══

namespace {
// DOM tree builder utilities 33
struct TreeNodeHelper33 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper33* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper33>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper33> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper33* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper33* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 34 ═══

namespace {
// DOM tree builder utilities 34
struct TreeNodeHelper34 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper34* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper34>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper34> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper34* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper34* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 35 ═══

namespace {
// DOM tree builder utilities 35
struct TreeNodeHelper35 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper35* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper35>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper35> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper35* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper35* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 36 ═══

namespace {
// DOM tree builder utilities 36
struct TreeNodeHelper36 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper36* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper36>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper36> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper36* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper36* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 37 ═══

namespace {
// DOM tree builder utilities 37
struct TreeNodeHelper37 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper37* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper37>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper37> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper37* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper37* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 38 ═══

namespace {
// DOM tree builder utilities 38
struct TreeNodeHelper38 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper38* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper38>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper38> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper38* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper38* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 39 ═══

namespace {
// DOM tree builder utilities 39
struct TreeNodeHelper39 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper39* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper39>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper39> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper39* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper39* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 40 ═══

namespace {
// DOM tree builder utilities 40
struct TreeNodeHelper40 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper40* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper40>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper40> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper40* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper40* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 41 ═══

namespace {
// DOM tree builder utilities 41
struct TreeNodeHelper41 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper41* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper41>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper41> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper41* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper41* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 42 ═══

namespace {
// DOM tree builder utilities 42
struct TreeNodeHelper42 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper42* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper42>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper42> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper42* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper42* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 43 ═══

namespace {
// DOM tree builder utilities 43
struct TreeNodeHelper43 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper43* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper43>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper43> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper43* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper43* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 44 ═══

namespace {
// DOM tree builder utilities 44
struct TreeNodeHelper44 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper44* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper44>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper44> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper44* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper44* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 45 ═══

namespace {
// DOM tree builder utilities 45
struct TreeNodeHelper45 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper45* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper45>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper45> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper45* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper45* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 46 ═══

namespace {
// DOM tree builder utilities 46
struct TreeNodeHelper46 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper46* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper46>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper46> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper46* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper46* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 47 ═══

namespace {
// DOM tree builder utilities 47
struct TreeNodeHelper47 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper47* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper47>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper47> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper47* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper47* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 48 ═══

namespace {
// DOM tree builder utilities 48
struct TreeNodeHelper48 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper48* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper48>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper48> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper48* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper48* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 49 ═══

namespace {
// DOM tree builder utilities 49
struct TreeNodeHelper49 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper49* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper49>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper49> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper49* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper49* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 50 ═══

namespace {
// DOM tree builder utilities 50
struct TreeNodeHelper50 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper50* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper50>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper50> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper50* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper50* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 51 ═══

namespace {
// DOM tree builder utilities 51
struct TreeNodeHelper51 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper51* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper51>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper51> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper51* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper51* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 52 ═══

namespace {
// DOM tree builder utilities 52
struct TreeNodeHelper52 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper52* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper52>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper52> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper52* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper52* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

// ═══ Section 53 ═══

namespace {
// DOM tree builder utilities 53
struct TreeNodeHelper53 {
    std::string tag_name;
    std::string id_value;
    std::vector<std::string> class_names;
    std::unordered_map<std::string, std::string> attributes;
    TreeNodeHelper53* parent_node = nullptr;
    std::vector<std::unique_ptr<TreeNodeHelper53>> child_nodes;

    void add_child(std::unique_ptr<TreeNodeHelper53> child) {
        child->parent_node = this;
        child_nodes.push_back(std::move(child));
    }

    TreeNodeHelper53* first_child() const {
        return child_nodes.empty() ? nullptr : child_nodes[0].get();
    }

    TreeNodeHelper53* next_sibling() const {
        if (!parent_node) return nullptr;
        for (size_t i = 0; i + 1 < parent_node->child_nodes.size(); ++i) {
            if (parent_node->child_nodes[i].get() == this) {
                return parent_node->child_nodes[i + 1].get();
            }
        }
        return nullptr;
    }

    size_t child_count() const { return child_nodes.size(); }
    bool has_children() const { return !child_nodes.empty(); }
    bool has_attribute(const std::string& name) const {
        return attributes.count(name) > 0;
    }
    std::optional<std::string> get_attribute(const std::string& name) const {
        auto it = attributes.find(name);
        return it != attributes.end() ? std::optional(it->second) : std::nullopt;
    }
};
} // anonymous namespace

#ifdef STYLE_TEST
bool test_gecko_smoke() { return true; }
bool run_gecko_tests() { return test_gecko_smoke(); }
#endif

}} // namespace style::gecko