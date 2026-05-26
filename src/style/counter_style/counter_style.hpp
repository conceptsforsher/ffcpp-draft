/* MPL 2.0 */
//! CSS @counter-style descriptors and predefined counter styles.
//! Corresponds to counter_style/mod.rs (863) and predefined.rs
#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

namespace style { namespace counter_style {

// ─── Counter style system ───
enum class CounterSystem : uint8_t {
    Cyclic, Numeric, Alphabetic, Symbolic, Additive, Fixed, Extends
};

struct CounterStyleDescriptor {
    std::string name;
    CounterSystem system = CounterSystem::Symbolic;
    std::vector<std::string> symbols;
    std::vector<std::pair<int, std::string>> additive_symbols;
    std::string negative_prefix;
    std::string negative_suffix;
    std::string prefix;
    std::string suffix;
    std::string range;       // "auto" or "N M"
    std::string pad;         // "N X"
    std::string fallback;    // another counter style name
    std::string speak_as;
    bool is_predefined = false;

    /// Generate a counter representation.
    std::string generate(int value) const;

    /// Check if this style can represent the given value.
    bool in_range(int value) const;
};

/// Registry of all known counter styles.
class CounterStyleRegistry {
public:
    static CounterStyleRegistry& instance();

    /// Get a counter style by name.
    const CounterStyleDescriptor* find(const std::string& name) const;

    /// Register a user-defined counter style.
    void register_style(const CounterStyleDescriptor& style);

    /// List all registered styles.
    std::vector<std::string> names() const;

private:
    CounterStyleRegistry();
    void register_predefined();
    std::unordered_map<std::string, CounterStyleDescriptor> styles_;
};

// Predefined style names
extern const char* PREDEFINED_STYLES[];

}}} // namespace
