/* MPL 2.0 */
//! CSS @property rule and registered custom properties.
//! Covers properties_and_values/mod.rs, registry.rs, rule.rs, value.rs (665), syntax/
#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <functional>
#include <regex>

namespace style { namespace properties_and_values {

// ─── Syntax definition ───
enum class SyntaxComponentType : uint8_t {
    Length, Number, Percentage, LengthPercentage, Color, Image,
    Url, Integer, Angle, Time, Resolution, TransformFunction,
    CustomIdent, String, Any,
};

struct SyntaxComponent {
    SyntaxComponentType type = SyntaxComponentType::Any;
    std::string ident;  // for custom-ident components
    bool multiplier_space = false;
    bool multiplier_comma = false;
};

struct SyntaxDefinition {
    std::vector<SyntaxComponent> components;
    bool is_universal = false;  // "*" syntax

    /// Parse a syntax string like "<length> | <color>".
    static SyntaxDefinition parse(const std::string& syntax_str);

    /// Check if a value matches this syntax.
    bool matches(const std::string& value) const;
};

// ─── Property registration ───
struct PropertyRegistration {
    std::string name;          // including "--" prefix
    SyntaxDefinition syntax;
    bool inherits = false;
    std::string initial_value;

    bool is_universal() const { return syntax.is_universal; }
};

// ─── Property registry ───
class PropertyRegistrationRegistry {
public:
    void register_property(const PropertyRegistration& reg);
    void unregister_property(const std::string& name);
    const PropertyRegistration* find(const std::string& name) const;
    bool is_registered(const std::string& name) const;
    std::vector<std::string> registered_names() const;
    size_t size() const { return registry_.size(); }
    void clear() { registry_.clear(); }

private:
    std::unordered_map<std::string, PropertyRegistration> registry_;
};

// ─── Value computation for registered properties ───
struct ComputedRegisteredProperty {
    std::string value;
    bool valid = false;
};

ComputedRegisteredProperty compute_registered_value(
    const std::string& specified,
    const PropertyRegistration* registration,
    const std::string* parent_value);

}}} // namespace
