/* MPL 2.0 */
//! CSS Custom Properties (variables)
#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include <optional>

namespace style { namespace custom_properties {

struct VariableValue {
    std::string value_;
    bool has_references_=false;
    VariableValue();
    VariableValue(std::string value, bool has_refs);
    ~VariableValue();
    static VariableValue parse(const std::string& input);
    const std::string& value() const;
    bool has_references() const;
    bool empty() const;
};

class CustomPropertiesMap {
public:
    CustomPropertiesMap();
    ~CustomPropertiesMap();
    void set(const std::string& name, VariableValue value);
    const VariableValue* get(const std::string& name) const;
    void remove(const std::string& name);
    bool contains(const std::string& name) const;
    size_t size() const;
    void clear();
    void inherit_from(const CustomPropertiesMap& parent);
    const std::unordered_map<std::string,VariableValue>& map() const { return map_; }
private:
    std::unordered_map<std::string,VariableValue> map_;
};

struct CustomPropertyRegistration {
    std::string name_, syntax_;
    bool inherits_=false;
    std::string initial_value_;
    CustomPropertyRegistration();
    CustomPropertyRegistration(std::string name,std::string syntax,bool inherits,std::string initial);
    const std::string& name()const; const std::string& syntax()const;
    bool inherits()const; const std::string& initial_value()const;
};

using ComputedCustomProperties = CustomPropertiesMap;

std::string resolve_variable_references(const std::string& input,const CustomPropertiesMap& props,const CustomPropertiesMap* parent,size_t max_depth=10);
ComputedCustomProperties compute_custom_properties(const CustomPropertiesMap& specified,const CustomPropertiesMap* parent,const std::unordered_map<std::string,CustomPropertyRegistration>& registrations);

}} // namespace
