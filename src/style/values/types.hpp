/* MPL 2.0 */
//! Fundamental CSS value types.
#pragma once
#include <cmath>
#include <cstdint>
#include <string>
#include <sstream>
#include <optional>
#include <variant>

namespace style { namespace values {

using CSSFloat = float;
using CSSInteger = int32_t;

inline CSSFloat normalize(CSSFloat v) { return std::isnan(v) ? 0.0f : v; }

// Atom types
class AtomString {
public:
    AtomString() = default;
    explicit AtomString(std::string v) : value_(std::move(v)) {}
    const std::string& str() const { return value_; }
    uint32_t precomputed_hash() const { return std::hash<std::string>{}(value_); }
    bool operator==(const AtomString& o) const { return value_==o.value_; }
    struct Hash { size_t operator()(const AtomString& s) const { return std::hash<std::string>{}(s.str()); } };
private:
    std::string value_;
};

class AtomIdent {
public:
    AtomIdent() = default;
    explicit AtomIdent(std::string v) : value_(std::move(v)) {}
    const std::string& str() const { return value_; }
    uint32_t precomputed_hash() const { return std::hash<std::string>{}(value_); }
    bool operator==(const AtomIdent& o) const { return value_==o.value_; }
    bool operator<(const AtomIdent& o) const { return value_<o.value_; }
    struct Hash { size_t operator()(const AtomIdent& id) const { return std::hash<std::string>{}(id.str()); } };
private:
    std::string value_;
};

}} // namespace
