/* MPL 2.0 */
//! Selector map — fast O(1) selector-to-element matching.
//! Corresponds to selector_map.rs (891 lines)
#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <set>
#include <memory>

namespace style {

class GeckoElement;

/// A map from CSS selectors (by class, ID, tag, attribute) to matching rules.
/// Enables fast filtering of candidate rules during style resolution.
template <typename RuleType>
class SelectorMap {
public:
    SelectorMap() = default;

    /// Insert a rule indexed by a specific selector component.
    void insert(const std::string& class_name, size_t rule_index, bool is_class) {
        if (is_class) class_to_rules_[class_name].push_back(rule_index);
        else id_to_rules_[class_name].push_back(rule_index);
    }

    void insert_tag(const std::string& tag, size_t rule_index) {
        tag_to_rules_[tag].push_back(rule_index);
    }

    void insert_universal(size_t rule_index) {
        universal_rules_.push_back(rule_index);
    }

    /// Find all rules that MIGHT match this element (candidate filtering).
    std::vector<size_t> find_candidates(const GeckoElement& element) const;

    /// Find rules for a specific class.
    const std::vector<size_t>* find_class(const std::string& cls) const {
        auto it = class_to_rules_.find(cls);
        return it != class_to_rules_.end() ? &it->second : nullptr;
    }

    /// Find rules for a specific ID.
    const std::vector<size_t>* find_id(const std::string& id) const {
        auto it = id_to_rules_.find(id);
        return it != id_to_rules_.end() ? &it->second : nullptr;
    }

    /// Total number of rule references across all buckets.
    size_t total_entries() const {
        size_t count = universal_rules_.size();
        for (const auto& [_, v] : class_to_rules_) count += v.size();
        for (const auto& [_, v] : id_to_rules_) count += v.size();
        for (const auto& [_, v] : tag_to_rules_) count += v.size();
        return count;
    }

    void clear() {
        class_to_rules_.clear();
        id_to_rules_.clear();
        tag_to_rules_.clear();
        universal_rules_.clear();
    }

private:
    std::unordered_map<std::string, std::vector<size_t>> class_to_rules_;
    std::unordered_map<std::string, std::vector<size_t>> id_to_rules_;
    std::unordered_map<std::string, std::vector<size_t>> tag_to_rules_;
    std::vector<size_t> universal_rules_;
};

// ─── SimpleBucketMap (small-N optimization) ───
template <typename K, typename V, size_t BUCKETS = 4>
class SimpleBucketMap {
public:
    bool insert(const K& key, const V& value) {
        size_t bucket = hasher_(key) % BUCKETS;
        for (auto& [k, v] : buckets_[bucket]) {
            if (k == key) { v = value; return false; }
        }
        buckets_[bucket].emplace_back(key, value);
        return true;
    }

    const V* find(const K& key) const {
        size_t bucket = hasher_(key) % BUCKETS;
        for (const auto& [k, v] : buckets_[bucket]) {
            if (k == key) return &v;
        }
        return nullptr;
    }

    void clear() { for (auto& b : buckets_) b.clear(); }
    size_t size() const {
        size_t s = 0;
        for (const auto& b : buckets_) s += b.size();
        return s;
    }

private:
    std::array<std::vector<std::pair<K, V>>, BUCKETS> buckets_;
    std::hash<K> hasher_;
};

} // namespace style
