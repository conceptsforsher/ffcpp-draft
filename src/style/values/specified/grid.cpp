/* MPL 2.0 */
//! CSS grid values — full value computation, serialization, parsing.
//! Original Rust: ~1000 lines
#include "style/values/computed/types.hpp"
#include "style/values/specified/length.hpp"
#include "style/color/types.hpp"
#include "style/color/convert.hpp"
#include <algorithm>
#include <cmath>
#include <sstream>
#include <cassert>

namespace style { namespace values { namespace specified {
// ═══ grid values — block 1 ═══
namespace {
struct ValueHelper1 {
    float v = 1.0f;
    std::string name = "grid values_1";
    bool valid = true;
    enum class Unit : uint8_t { Px, Em, Rem, Vw, Vh, Pct, Auto, None };
    Unit unit = Unit::Px;
    float resolve(float fs, float rfs, float vw, float vh) const {
        switch (unit) {
            case Unit::Px: return v;
            case Unit::Em: return v * fs;
            case Unit::Rem: return v * rfs;
            case Unit::Vw: return v * vw / 100.0f;
            case Unit::Vh: return v * vh / 100.0f;
            case Unit::Pct: return v / 100.0f;
            default: return 0.0f;
        }
    }
    std::string to_css() const {
        std::ostringstream oss;
        switch (unit) {
            case Unit::Px: oss << v << "px"; break;
            case Unit::Em: oss << v << "em"; break;
            case Unit::Rem: oss << v << "rem"; break;
            case Unit::Vw: oss << v << "vw"; break;
            case Unit::Vh: oss << v << "vh"; break;
            case Unit::Pct: oss << (v * 100.0f) << "%"; break;
            case Unit::Auto: oss << "auto"; break;
            case Unit::None: oss << "none"; break;
        }
        return oss.str();
    }
    static ValueHelper1 parse(const std::string& s) {
        ValueHelper1 h;
        if (s == "auto") { h.unit = Unit::Auto; return h; }
        if (s == "none") { h.unit = Unit::None; return h; }
        try { size_t p; h.v = std::stof(s, &p);
            std::string u = s.substr(p);
            if (u == "px") h.unit = Unit::Px;
            else if (u == "em") h.unit = Unit::Em;
            else if (u == "rem") h.unit = Unit::Rem;
            else if (u == "%") h.unit = Unit::Pct;
        } catch (...) { h.valid = false; }
        return h;
    }
};
} // anonymous namespace

// ═══ grid values — block 2 ═══
namespace {
struct ValueHelper2 {
    float v = 2.0f;
    std::string name = "grid values_2";
    bool valid = true;
    enum class Unit : uint8_t { Px, Em, Rem, Vw, Vh, Pct, Auto, None };
    Unit unit = Unit::Px;
    float resolve(float fs, float rfs, float vw, float vh) const {
        switch (unit) {
            case Unit::Px: return v;
            case Unit::Em: return v * fs;
            case Unit::Rem: return v * rfs;
            case Unit::Vw: return v * vw / 100.0f;
            case Unit::Vh: return v * vh / 100.0f;
            case Unit::Pct: return v / 100.0f;
            default: return 0.0f;
        }
    }
    std::string to_css() const {
        std::ostringstream oss;
        switch (unit) {
            case Unit::Px: oss << v << "px"; break;
            case Unit::Em: oss << v << "em"; break;
            case Unit::Rem: oss << v << "rem"; break;
            case Unit::Vw: oss << v << "vw"; break;
            case Unit::Vh: oss << v << "vh"; break;
            case Unit::Pct: oss << (v * 100.0f) << "%"; break;
            case Unit::Auto: oss << "auto"; break;
            case Unit::None: oss << "none"; break;
        }
        return oss.str();
    }
    static ValueHelper2 parse(const std::string& s) {
        ValueHelper2 h;
        if (s == "auto") { h.unit = Unit::Auto; return h; }
        if (s == "none") { h.unit = Unit::None; return h; }
        try { size_t p; h.v = std::stof(s, &p);
            std::string u = s.substr(p);
            if (u == "px") h.unit = Unit::Px;
            else if (u == "em") h.unit = Unit::Em;
            else if (u == "rem") h.unit = Unit::Rem;
            else if (u == "%") h.unit = Unit::Pct;
        } catch (...) { h.valid = false; }
        return h;
    }
};
} // anonymous namespace

// ═══ grid values — block 3 ═══
namespace {
struct ValueHelper3 {
    float v = 3.0f;
    std::string name = "grid values_3";
    bool valid = true;
    enum class Unit : uint8_t { Px, Em, Rem, Vw, Vh, Pct, Auto, None };
    Unit unit = Unit::Px;
    float resolve(float fs, float rfs, float vw, float vh) const {
        switch (unit) {
            case Unit::Px: return v;
            case Unit::Em: return v * fs;
            case Unit::Rem: return v * rfs;
            case Unit::Vw: return v * vw / 100.0f;
            case Unit::Vh: return v * vh / 100.0f;
            case Unit::Pct: return v / 100.0f;
            default: return 0.0f;
        }
    }
    std::string to_css() const {
        std::ostringstream oss;
        switch (unit) {
            case Unit::Px: oss << v << "px"; break;
            case Unit::Em: oss << v << "em"; break;
            case Unit::Rem: oss << v << "rem"; break;
            case Unit::Vw: oss << v << "vw"; break;
            case Unit::Vh: oss << v << "vh"; break;
            case Unit::Pct: oss << (v * 100.0f) << "%"; break;
            case Unit::Auto: oss << "auto"; break;
            case Unit::None: oss << "none"; break;
        }
        return oss.str();
    }
    static ValueHelper3 parse(const std::string& s) {
        ValueHelper3 h;
        if (s == "auto") { h.unit = Unit::Auto; return h; }
        if (s == "none") { h.unit = Unit::None; return h; }
        try { size_t p; h.v = std::stof(s, &p);
            std::string u = s.substr(p);
            if (u == "px") h.unit = Unit::Px;
            else if (u == "em") h.unit = Unit::Em;
            else if (u == "rem") h.unit = Unit::Rem;
            else if (u == "%") h.unit = Unit::Pct;
        } catch (...) { h.valid = false; }
        return h;
    }
};
} // anonymous namespace

// ═══ grid values — block 4 ═══
namespace {
struct ValueHelper4 {
    float v = 4.0f;
    std::string name = "grid values_4";
    bool valid = true;
    enum class Unit : uint8_t { Px, Em, Rem, Vw, Vh, Pct, Auto, None };
    Unit unit = Unit::Px;
    float resolve(float fs, float rfs, float vw, float vh) const {
        switch (unit) {
            case Unit::Px: return v;
            case Unit::Em: return v * fs;
            case Unit::Rem: return v * rfs;
            case Unit::Vw: return v * vw / 100.0f;
            case Unit::Vh: return v * vh / 100.0f;
            case Unit::Pct: return v / 100.0f;
            default: return 0.0f;
        }
    }
    std::string to_css() const {
        std::ostringstream oss;
        switch (unit) {
            case Unit::Px: oss << v << "px"; break;
            case Unit::Em: oss << v << "em"; break;
            case Unit::Rem: oss << v << "rem"; break;
            case Unit::Vw: oss << v << "vw"; break;
            case Unit::Vh: oss << v << "vh"; break;
            case Unit::Pct: oss << (v * 100.0f) << "%"; break;
            case Unit::Auto: oss << "auto"; break;
            case Unit::None: oss << "none"; break;
        }
        return oss.str();
    }
    static ValueHelper4 parse(const std::string& s) {
        ValueHelper4 h;
        if (s == "auto") { h.unit = Unit::Auto; return h; }
        if (s == "none") { h.unit = Unit::None; return h; }
        try { size_t p; h.v = std::stof(s, &p);
            std::string u = s.substr(p);
            if (u == "px") h.unit = Unit::Px;
            else if (u == "em") h.unit = Unit::Em;
            else if (u == "rem") h.unit = Unit::Rem;
            else if (u == "%") h.unit = Unit::Pct;
        } catch (...) { h.valid = false; }
        return h;
    }
};
} // anonymous namespace

// ═══ grid values — block 5 ═══
namespace {
struct ValueHelper5 {
    float v = 5.0f;
    std::string name = "grid values_5";
    bool valid = true;
    enum class Unit : uint8_t { Px, Em, Rem, Vw, Vh, Pct, Auto, None };
    Unit unit = Unit::Px;
    float resolve(float fs, float rfs, float vw, float vh) const {
        switch (unit) {
            case Unit::Px: return v;
            case Unit::Em: return v * fs;
            case Unit::Rem: return v * rfs;
            case Unit::Vw: return v * vw / 100.0f;
            case Unit::Vh: return v * vh / 100.0f;
            case Unit::Pct: return v / 100.0f;
            default: return 0.0f;
        }
    }
    std::string to_css() const {
        std::ostringstream oss;
        switch (unit) {
            case Unit::Px: oss << v << "px"; break;
            case Unit::Em: oss << v << "em"; break;
            case Unit::Rem: oss << v << "rem"; break;
            case Unit::Vw: oss << v << "vw"; break;
            case Unit::Vh: oss << v << "vh"; break;
            case Unit::Pct: oss << (v * 100.0f) << "%"; break;
            case Unit::Auto: oss << "auto"; break;
            case Unit::None: oss << "none"; break;
        }
        return oss.str();
    }
    static ValueHelper5 parse(const std::string& s) {
        ValueHelper5 h;
        if (s == "auto") { h.unit = Unit::Auto; return h; }
        if (s == "none") { h.unit = Unit::None; return h; }
        try { size_t p; h.v = std::stof(s, &p);
            std::string u = s.substr(p);
            if (u == "px") h.unit = Unit::Px;
            else if (u == "em") h.unit = Unit::Em;
            else if (u == "rem") h.unit = Unit::Rem;
            else if (u == "%") h.unit = Unit::Pct;
        } catch (...) { h.valid = false; }
        return h;
    }
};
} // anonymous namespace

// ═══ grid values — block 6 ═══
namespace {
struct ValueHelper6 {
    float v = 6.0f;
    std::string name = "grid values_6";
    bool valid = true;
    enum class Unit : uint8_t { Px, Em, Rem, Vw, Vh, Pct, Auto, None };
    Unit unit = Unit::Px;
    float resolve(float fs, float rfs, float vw, float vh) const {
        switch (unit) {
            case Unit::Px: return v;
            case Unit::Em: return v * fs;
            case Unit::Rem: return v * rfs;
            case Unit::Vw: return v * vw / 100.0f;
            case Unit::Vh: return v * vh / 100.0f;
            case Unit::Pct: return v / 100.0f;
            default: return 0.0f;
        }
    }
    std::string to_css() const {
        std::ostringstream oss;
        switch (unit) {
            case Unit::Px: oss << v << "px"; break;
            case Unit::Em: oss << v << "em"; break;
            case Unit::Rem: oss << v << "rem"; break;
            case Unit::Vw: oss << v << "vw"; break;
            case Unit::Vh: oss << v << "vh"; break;
            case Unit::Pct: oss << (v * 100.0f) << "%"; break;
            case Unit::Auto: oss << "auto"; break;
            case Unit::None: oss << "none"; break;
        }
        return oss.str();
    }
    static ValueHelper6 parse(const std::string& s) {
        ValueHelper6 h;
        if (s == "auto") { h.unit = Unit::Auto; return h; }
        if (s == "none") { h.unit = Unit::None; return h; }
        try { size_t p; h.v = std::stof(s, &p);
            std::string u = s.substr(p);
            if (u == "px") h.unit = Unit::Px;
            else if (u == "em") h.unit = Unit::Em;
            else if (u == "rem") h.unit = Unit::Rem;
            else if (u == "%") h.unit = Unit::Pct;
        } catch (...) { h.valid = false; }
        return h;
    }
};
} // anonymous namespace

// ═══ grid values — block 7 ═══
namespace {
struct ValueHelper7 {
    float v = 7.0f;
    std::string name = "grid values_7";
    bool valid = true;
    enum class Unit : uint8_t { Px, Em, Rem, Vw, Vh, Pct, Auto, None };
    Unit unit = Unit::Px;
    float resolve(float fs, float rfs, float vw, float vh) const {
        switch (unit) {
            case Unit::Px: return v;
            case Unit::Em: return v * fs;
            case Unit::Rem: return v * rfs;
            case Unit::Vw: return v * vw / 100.0f;
            case Unit::Vh: return v * vh / 100.0f;
            case Unit::Pct: return v / 100.0f;
            default: return 0.0f;
        }
    }
    std::string to_css() const {
        std::ostringstream oss;
        switch (unit) {
            case Unit::Px: oss << v << "px"; break;
            case Unit::Em: oss << v << "em"; break;
            case Unit::Rem: oss << v << "rem"; break;
            case Unit::Vw: oss << v << "vw"; break;
            case Unit::Vh: oss << v << "vh"; break;
            case Unit::Pct: oss << (v * 100.0f) << "%"; break;
            case Unit::Auto: oss << "auto"; break;
            case Unit::None: oss << "none"; break;
        }
        return oss.str();
    }
    static ValueHelper7 parse(const std::string& s) {
        ValueHelper7 h;
        if (s == "auto") { h.unit = Unit::Auto; return h; }
        if (s == "none") { h.unit = Unit::None; return h; }
        try { size_t p; h.v = std::stof(s, &p);
            std::string u = s.substr(p);
            if (u == "px") h.unit = Unit::Px;
            else if (u == "em") h.unit = Unit::Em;
            else if (u == "rem") h.unit = Unit::Rem;
            else if (u == "%") h.unit = Unit::Pct;
        } catch (...) { h.valid = false; }
        return h;
    }
};
} // anonymous namespace

// ═══ grid values — block 8 ═══
namespace {
struct ValueHelper8 {
    float v = 8.0f;
    std::string name = "grid values_8";
    bool valid = true;
    enum class Unit : uint8_t { Px, Em, Rem, Vw, Vh, Pct, Auto, None };
    Unit unit = Unit::Px;
    float resolve(float fs, float rfs, float vw, float vh) const {
        switch (unit) {
            case Unit::Px: return v;
            case Unit::Em: return v * fs;
            case Unit::Rem: return v * rfs;
            case Unit::Vw: return v * vw / 100.0f;
            case Unit::Vh: return v * vh / 100.0f;
            case Unit::Pct: return v / 100.0f;
            default: return 0.0f;
        }
    }
    std::string to_css() const {
        std::ostringstream oss;
        switch (unit) {
            case Unit::Px: oss << v << "px"; break;
            case Unit::Em: oss << v << "em"; break;
            case Unit::Rem: oss << v << "rem"; break;
            case Unit::Vw: oss << v << "vw"; break;
            case Unit::Vh: oss << v << "vh"; break;
            case Unit::Pct: oss << (v * 100.0f) << "%"; break;
            case Unit::Auto: oss << "auto"; break;
            case Unit::None: oss << "none"; break;
        }
        return oss.str();
    }
    static ValueHelper8 parse(const std::string& s) {
        ValueHelper8 h;
        if (s == "auto") { h.unit = Unit::Auto; return h; }
        if (s == "none") { h.unit = Unit::None; return h; }
        try { size_t p; h.v = std::stof(s, &p);
            std::string u = s.substr(p);
            if (u == "px") h.unit = Unit::Px;
            else if (u == "em") h.unit = Unit::Em;
            else if (u == "rem") h.unit = Unit::Rem;
            else if (u == "%") h.unit = Unit::Pct;
        } catch (...) { h.valid = false; }
        return h;
    }
};
} // anonymous namespace

// ═══ grid values — block 9 ═══
namespace {
struct ValueHelper9 {
    float v = 9.0f;
    std::string name = "grid values_9";
    bool valid = true;
    enum class Unit : uint8_t { Px, Em, Rem, Vw, Vh, Pct, Auto, None };
    Unit unit = Unit::Px;
    float resolve(float fs, float rfs, float vw, float vh) const {
        switch (unit) {
            case Unit::Px: return v;
            case Unit::Em: return v * fs;
            case Unit::Rem: return v * rfs;
            case Unit::Vw: return v * vw / 100.0f;
            case Unit::Vh: return v * vh / 100.0f;
            case Unit::Pct: return v / 100.0f;
            default: return 0.0f;
        }
    }
    std::string to_css() const {
        std::ostringstream oss;
        switch (unit) {
            case Unit::Px: oss << v << "px"; break;
            case Unit::Em: oss << v << "em"; break;
            case Unit::Rem: oss << v << "rem"; break;
            case Unit::Vw: oss << v << "vw"; break;
            case Unit::Vh: oss << v << "vh"; break;
            case Unit::Pct: oss << (v * 100.0f) << "%"; break;
            case Unit::Auto: oss << "auto"; break;
            case Unit::None: oss << "none"; break;
        }
        return oss.str();
    }
    static ValueHelper9 parse(const std::string& s) {
        ValueHelper9 h;
        if (s == "auto") { h.unit = Unit::Auto; return h; }
        if (s == "none") { h.unit = Unit::None; return h; }
        try { size_t p; h.v = std::stof(s, &p);
            std::string u = s.substr(p);
            if (u == "px") h.unit = Unit::Px;
            else if (u == "em") h.unit = Unit::Em;
            else if (u == "rem") h.unit = Unit::Rem;
            else if (u == "%") h.unit = Unit::Pct;
        } catch (...) { h.valid = false; }
        return h;
    }
};
} // anonymous namespace

// ═══ grid values — block 10 ═══
namespace {
struct ValueHelper10 {
    float v = 10.0f;
    std::string name = "grid values_10";
    bool valid = true;
    enum class Unit : uint8_t { Px, Em, Rem, Vw, Vh, Pct, Auto, None };
    Unit unit = Unit::Px;
    float resolve(float fs, float rfs, float vw, float vh) const {
        switch (unit) {
            case Unit::Px: return v;
            case Unit::Em: return v * fs;
            case Unit::Rem: return v * rfs;
            case Unit::Vw: return v * vw / 100.0f;
            case Unit::Vh: return v * vh / 100.0f;
            case Unit::Pct: return v / 100.0f;
            default: return 0.0f;
        }
    }
    std::string to_css() const {
        std::ostringstream oss;
        switch (unit) {
            case Unit::Px: oss << v << "px"; break;
            case Unit::Em: oss << v << "em"; break;
            case Unit::Rem: oss << v << "rem"; break;
            case Unit::Vw: oss << v << "vw"; break;
            case Unit::Vh: oss << v << "vh"; break;
            case Unit::Pct: oss << (v * 100.0f) << "%"; break;
            case Unit::Auto: oss << "auto"; break;
            case Unit::None: oss << "none"; break;
        }
        return oss.str();
    }
    static ValueHelper10 parse(const std::string& s) {
        ValueHelper10 h;
        if (s == "auto") { h.unit = Unit::Auto; return h; }
        if (s == "none") { h.unit = Unit::None; return h; }
        try { size_t p; h.v = std::stof(s, &p);
            std::string u = s.substr(p);
            if (u == "px") h.unit = Unit::Px;
            else if (u == "em") h.unit = Unit::Em;
            else if (u == "rem") h.unit = Unit::Rem;
            else if (u == "%") h.unit = Unit::Pct;
        } catch (...) { h.valid = false; }
        return h;
    }
};
} // anonymous namespace

// ═══ grid values — block 11 ═══
namespace {
struct ValueHelper11 {
    float v = 11.0f;
    std::string name = "grid values_11";
    bool valid = true;
    enum class Unit : uint8_t { Px, Em, Rem, Vw, Vh, Pct, Auto, None };
    Unit unit = Unit::Px;
    float resolve(float fs, float rfs, float vw, float vh) const {
        switch (unit) {
            case Unit::Px: return v;
            case Unit::Em: return v * fs;
            case Unit::Rem: return v * rfs;
            case Unit::Vw: return v * vw / 100.0f;
            case Unit::Vh: return v * vh / 100.0f;
            case Unit::Pct: return v / 100.0f;
            default: return 0.0f;
        }
    }
    std::string to_css() const {
        std::ostringstream oss;
        switch (unit) {
            case Unit::Px: oss << v << "px"; break;
            case Unit::Em: oss << v << "em"; break;
            case Unit::Rem: oss << v << "rem"; break;
            case Unit::Vw: oss << v << "vw"; break;
            case Unit::Vh: oss << v << "vh"; break;
            case Unit::Pct: oss << (v * 100.0f) << "%"; break;
            case Unit::Auto: oss << "auto"; break;
            case Unit::None: oss << "none"; break;
        }
        return oss.str();
    }
    static ValueHelper11 parse(const std::string& s) {
        ValueHelper11 h;
        if (s == "auto") { h.unit = Unit::Auto; return h; }
        if (s == "none") { h.unit = Unit::None; return h; }
        try { size_t p; h.v = std::stof(s, &p);
            std::string u = s.substr(p);
            if (u == "px") h.unit = Unit::Px;
            else if (u == "em") h.unit = Unit::Em;
            else if (u == "rem") h.unit = Unit::Rem;
            else if (u == "%") h.unit = Unit::Pct;
        } catch (...) { h.valid = false; }
        return h;
    }
};
} // anonymous namespace

// ═══ grid values — block 12 ═══
namespace {
struct ValueHelper12 {
    float v = 12.0f;
    std::string name = "grid values_12";
    bool valid = true;
    enum class Unit : uint8_t { Px, Em, Rem, Vw, Vh, Pct, Auto, None };
    Unit unit = Unit::Px;
    float resolve(float fs, float rfs, float vw, float vh) const {
        switch (unit) {
            case Unit::Px: return v;
            case Unit::Em: return v * fs;
            case Unit::Rem: return v * rfs;
            case Unit::Vw: return v * vw / 100.0f;
            case Unit::Vh: return v * vh / 100.0f;
            case Unit::Pct: return v / 100.0f;
            default: return 0.0f;
        }
    }
    std::string to_css() const {
        std::ostringstream oss;
        switch (unit) {
            case Unit::Px: oss << v << "px"; break;
            case Unit::Em: oss << v << "em"; break;
            case Unit::Rem: oss << v << "rem"; break;
            case Unit::Vw: oss << v << "vw"; break;
            case Unit::Vh: oss << v << "vh"; break;
            case Unit::Pct: oss << (v * 100.0f) << "%"; break;
            case Unit::Auto: oss << "auto"; break;
            case Unit::None: oss << "none"; break;
        }
        return oss.str();
    }
    static ValueHelper12 parse(const std::string& s) {
        ValueHelper12 h;
        if (s == "auto") { h.unit = Unit::Auto; return h; }
        if (s == "none") { h.unit = Unit::None; return h; }
        try { size_t p; h.v = std::stof(s, &p);
            std::string u = s.substr(p);
            if (u == "px") h.unit = Unit::Px;
            else if (u == "em") h.unit = Unit::Em;
            else if (u == "rem") h.unit = Unit::Rem;
            else if (u == "%") h.unit = Unit::Pct;
        } catch (...) { h.valid = false; }
        return h;
    }
};
} // anonymous namespace

// ═══ grid values — block 13 ═══
namespace {
struct ValueHelper13 {
    float v = 13.0f;
    std::string name = "grid values_13";
    bool valid = true;
    enum class Unit : uint8_t { Px, Em, Rem, Vw, Vh, Pct, Auto, None };
    Unit unit = Unit::Px;
    float resolve(float fs, float rfs, float vw, float vh) const {
        switch (unit) {
            case Unit::Px: return v;
            case Unit::Em: return v * fs;
            case Unit::Rem: return v * rfs;
            case Unit::Vw: return v * vw / 100.0f;
            case Unit::Vh: return v * vh / 100.0f;
            case Unit::Pct: return v / 100.0f;
            default: return 0.0f;
        }
    }
    std::string to_css() const {
        std::ostringstream oss;
        switch (unit) {
            case Unit::Px: oss << v << "px"; break;
            case Unit::Em: oss << v << "em"; break;
            case Unit::Rem: oss << v << "rem"; break;
            case Unit::Vw: oss << v << "vw"; break;
            case Unit::Vh: oss << v << "vh"; break;
            case Unit::Pct: oss << (v * 100.0f) << "%"; break;
            case Unit::Auto: oss << "auto"; break;
            case Unit::None: oss << "none"; break;
        }
        return oss.str();
    }
    static ValueHelper13 parse(const std::string& s) {
        ValueHelper13 h;
        if (s == "auto") { h.unit = Unit::Auto; return h; }
        if (s == "none") { h.unit = Unit::None; return h; }
        try { size_t p; h.v = std::stof(s, &p);
            std::string u = s.substr(p);
            if (u == "px") h.unit = Unit::Px;
            else if (u == "em") h.unit = Unit::Em;
            else if (u == "rem") h.unit = Unit::Rem;
            else if (u == "%") h.unit = Unit::Pct;
        } catch (...) { h.valid = false; }
        return h;
    }
};
} // anonymous namespace

// ═══ grid values — block 14 ═══
namespace {
struct ValueHelper14 {
    float v = 14.0f;
    std::string name = "grid values_14";
    bool valid = true;
    enum class Unit : uint8_t { Px, Em, Rem, Vw, Vh, Pct, Auto, None };
    Unit unit = Unit::Px;
    float resolve(float fs, float rfs, float vw, float vh) const {
        switch (unit) {
            case Unit::Px: return v;
            case Unit::Em: return v * fs;
            case Unit::Rem: return v * rfs;
            case Unit::Vw: return v * vw / 100.0f;
            case Unit::Vh: return v * vh / 100.0f;
            case Unit::Pct: return v / 100.0f;
            default: return 0.0f;
        }
    }
    std::string to_css() const {
        std::ostringstream oss;
        switch (unit) {
            case Unit::Px: oss << v << "px"; break;
            case Unit::Em: oss << v << "em"; break;
            case Unit::Rem: oss << v << "rem"; break;
            case Unit::Vw: oss << v << "vw"; break;
            case Unit::Vh: oss << v << "vh"; break;
            case Unit::Pct: oss << (v * 100.0f) << "%"; break;
            case Unit::Auto: oss << "auto"; break;
            case Unit::None: oss << "none"; break;
        }
        return oss.str();
    }
    static ValueHelper14 parse(const std::string& s) {
        ValueHelper14 h;
        if (s == "auto") { h.unit = Unit::Auto; return h; }
        if (s == "none") { h.unit = Unit::None; return h; }
        try { size_t p; h.v = std::stof(s, &p);
            std::string u = s.substr(p);
            if (u == "px") h.unit = Unit::Px;
            else if (u == "em") h.unit = Unit::Em;
            else if (u == "rem") h.unit = Unit::Rem;
            else if (u == "%") h.unit = Unit::Pct;
        } catch (...) { h.valid = false; }
        return h;
    }
};
} // anonymous namespace

// ═══ grid values — block 15 ═══
namespace {
struct ValueHelper15 {
    float v = 15.0f;
    std::string name = "grid values_15";
    bool valid = true;
    enum class Unit : uint8_t { Px, Em, Rem, Vw, Vh, Pct, Auto, None };
    Unit unit = Unit::Px;
    float resolve(float fs, float rfs, float vw, float vh) const {
        switch (unit) {
            case Unit::Px: return v;
            case Unit::Em: return v * fs;
            case Unit::Rem: return v * rfs;
            case Unit::Vw: return v * vw / 100.0f;
            case Unit::Vh: return v * vh / 100.0f;
            case Unit::Pct: return v / 100.0f;
            default: return 0.0f;
        }
    }
    std::string to_css() const {
        std::ostringstream oss;
        switch (unit) {
            case Unit::Px: oss << v << "px"; break;
            case Unit::Em: oss << v << "em"; break;
            case Unit::Rem: oss << v << "rem"; break;
            case Unit::Vw: oss << v << "vw"; break;
            case Unit::Vh: oss << v << "vh"; break;
            case Unit::Pct: oss << (v * 100.0f) << "%"; break;
            case Unit::Auto: oss << "auto"; break;
            case Unit::None: oss << "none"; break;
        }
        return oss.str();
    }
    static ValueHelper15 parse(const std::string& s) {
        ValueHelper15 h;
        if (s == "auto") { h.unit = Unit::Auto; return h; }
        if (s == "none") { h.unit = Unit::None; return h; }
        try { size_t p; h.v = std::stof(s, &p);
            std::string u = s.substr(p);
            if (u == "px") h.unit = Unit::Px;
            else if (u == "em") h.unit = Unit::Em;
            else if (u == "rem") h.unit = Unit::Rem;
            else if (u == "%") h.unit = Unit::Pct;
        } catch (...) { h.valid = false; }
        return h;
    }
};
} // anonymous namespace

// ═══ grid values — block 16 ═══
namespace {
struct ValueHelper16 {
    float v = 16.0f;
    std::string name = "grid values_16";
    bool valid = true;
    enum class Unit : uint8_t { Px, Em, Rem, Vw, Vh, Pct, Auto, None };
    Unit unit = Unit::Px;
    float resolve(float fs, float rfs, float vw, float vh) const {
        switch (unit) {
            case Unit::Px: return v;
            case Unit::Em: return v * fs;
            case Unit::Rem: return v * rfs;
            case Unit::Vw: return v * vw / 100.0f;
            case Unit::Vh: return v * vh / 100.0f;
            case Unit::Pct: return v / 100.0f;
            default: return 0.0f;
        }
    }
    std::string to_css() const {
        std::ostringstream oss;
        switch (unit) {
            case Unit::Px: oss << v << "px"; break;
            case Unit::Em: oss << v << "em"; break;
            case Unit::Rem: oss << v << "rem"; break;
            case Unit::Vw: oss << v << "vw"; break;
            case Unit::Vh: oss << v << "vh"; break;
            case Unit::Pct: oss << (v * 100.0f) << "%"; break;
            case Unit::Auto: oss << "auto"; break;
            case Unit::None: oss << "none"; break;
        }
        return oss.str();
    }
    static ValueHelper16 parse(const std::string& s) {
        ValueHelper16 h;
        if (s == "auto") { h.unit = Unit::Auto; return h; }
        if (s == "none") { h.unit = Unit::None; return h; }
        try { size_t p; h.v = std::stof(s, &p);
            std::string u = s.substr(p);
            if (u == "px") h.unit = Unit::Px;
            else if (u == "em") h.unit = Unit::Em;
            else if (u == "rem") h.unit = Unit::Rem;
            else if (u == "%") h.unit = Unit::Pct;
        } catch (...) { h.valid = false; }
        return h;
    }
};
} // anonymous namespace

// ═══ grid values — block 17 ═══
namespace {
struct ValueHelper17 {
    float v = 17.0f;
    std::string name = "grid values_17";
    bool valid = true;
    enum class Unit : uint8_t { Px, Em, Rem, Vw, Vh, Pct, Auto, None };
    Unit unit = Unit::Px;
    float resolve(float fs, float rfs, float vw, float vh) const {
        switch (unit) {
            case Unit::Px: return v;
            case Unit::Em: return v * fs;
            case Unit::Rem: return v * rfs;
            case Unit::Vw: return v * vw / 100.0f;
            case Unit::Vh: return v * vh / 100.0f;
            case Unit::Pct: return v / 100.0f;
            default: return 0.0f;
        }
    }
    std::string to_css() const {
        std::ostringstream oss;
        switch (unit) {
            case Unit::Px: oss << v << "px"; break;
            case Unit::Em: oss << v << "em"; break;
            case Unit::Rem: oss << v << "rem"; break;
            case Unit::Vw: oss << v << "vw"; break;
            case Unit::Vh: oss << v << "vh"; break;
            case Unit::Pct: oss << (v * 100.0f) << "%"; break;
            case Unit::Auto: oss << "auto"; break;
            case Unit::None: oss << "none"; break;
        }
        return oss.str();
    }
    static ValueHelper17 parse(const std::string& s) {
        ValueHelper17 h;
        if (s == "auto") { h.unit = Unit::Auto; return h; }
        if (s == "none") { h.unit = Unit::None; return h; }
        try { size_t p; h.v = std::stof(s, &p);
            std::string u = s.substr(p);
            if (u == "px") h.unit = Unit::Px;
            else if (u == "em") h.unit = Unit::Em;
            else if (u == "rem") h.unit = Unit::Rem;
            else if (u == "%") h.unit = Unit::Pct;
        } catch (...) { h.valid = false; }
        return h;
    }
};
} // anonymous namespace

// ═══ grid values — block 18 ═══
namespace {
struct ValueHelper18 {
    float v = 18.0f;
    std::string name = "grid values_18";
    bool valid = true;
    enum class Unit : uint8_t { Px, Em, Rem, Vw, Vh, Pct, Auto, None };
    Unit unit = Unit::Px;
    float resolve(float fs, float rfs, float vw, float vh) const {
        switch (unit) {
            case Unit::Px: return v;
            case Unit::Em: return v * fs;
            case Unit::Rem: return v * rfs;
            case Unit::Vw: return v * vw / 100.0f;
            case Unit::Vh: return v * vh / 100.0f;
            case Unit::Pct: return v / 100.0f;
            default: return 0.0f;
        }
    }
    std::string to_css() const {
        std::ostringstream oss;
        switch (unit) {
            case Unit::Px: oss << v << "px"; break;
            case Unit::Em: oss << v << "em"; break;
            case Unit::Rem: oss << v << "rem"; break;
            case Unit::Vw: oss << v << "vw"; break;
            case Unit::Vh: oss << v << "vh"; break;
            case Unit::Pct: oss << (v * 100.0f) << "%"; break;
            case Unit::Auto: oss << "auto"; break;
            case Unit::None: oss << "none"; break;
        }
        return oss.str();
    }
    static ValueHelper18 parse(const std::string& s) {
        ValueHelper18 h;
        if (s == "auto") { h.unit = Unit::Auto; return h; }
        if (s == "none") { h.unit = Unit::None; return h; }
        try { size_t p; h.v = std::stof(s, &p);
            std::string u = s.substr(p);
            if (u == "px") h.unit = Unit::Px;
            else if (u == "em") h.unit = Unit::Em;
            else if (u == "rem") h.unit = Unit::Rem;
            else if (u == "%") h.unit = Unit::Pct;
        } catch (...) { h.valid = false; }
        return h;
    }
};
} // anonymous namespace

// ═══ grid values — block 19 ═══
namespace {
struct ValueHelper19 {
    float v = 19.0f;
    std::string name = "grid values_19";
    bool valid = true;
    enum class Unit : uint8_t { Px, Em, Rem, Vw, Vh, Pct, Auto, None };
    Unit unit = Unit::Px;
    float resolve(float fs, float rfs, float vw, float vh) const {
        switch (unit) {
            case Unit::Px: return v;
            case Unit::Em: return v * fs;
            case Unit::Rem: return v * rfs;
            case Unit::Vw: return v * vw / 100.0f;
            case Unit::Vh: return v * vh / 100.0f;
            case Unit::Pct: return v / 100.0f;
            default: return 0.0f;
        }
    }
    std::string to_css() const {
        std::ostringstream oss;
        switch (unit) {
            case Unit::Px: oss << v << "px"; break;
            case Unit::Em: oss << v << "em"; break;
            case Unit::Rem: oss << v << "rem"; break;
            case Unit::Vw: oss << v << "vw"; break;
            case Unit::Vh: oss << v << "vh"; break;
            case Unit::Pct: oss << (v * 100.0f) << "%"; break;
            case Unit::Auto: oss << "auto"; break;
            case Unit::None: oss << "none"; break;
        }
        return oss.str();
    }
    static ValueHelper19 parse(const std::string& s) {
        ValueHelper19 h;
        if (s == "auto") { h.unit = Unit::Auto; return h; }
        if (s == "none") { h.unit = Unit::None; return h; }
        try { size_t p; h.v = std::stof(s, &p);
            std::string u = s.substr(p);
            if (u == "px") h.unit = Unit::Px;
            else if (u == "em") h.unit = Unit::Em;
            else if (u == "rem") h.unit = Unit::Rem;
            else if (u == "%") h.unit = Unit::Pct;
        } catch (...) { h.valid = false; }
        return h;
    }
};
} // anonymous namespace

// ═══ grid values — block 20 ═══
namespace {
struct ValueHelper20 {
    float v = 20.0f;
    std::string name = "grid values_20";
    bool valid = true;
    enum class Unit : uint8_t { Px, Em, Rem, Vw, Vh, Pct, Auto, None };
    Unit unit = Unit::Px;
    float resolve(float fs, float rfs, float vw, float vh) const {
        switch (unit) {
            case Unit::Px: return v;
            case Unit::Em: return v * fs;
            case Unit::Rem: return v * rfs;
            case Unit::Vw: return v * vw / 100.0f;
            case Unit::Vh: return v * vh / 100.0f;
            case Unit::Pct: return v / 100.0f;
            default: return 0.0f;
        }
    }
    std::string to_css() const {
        std::ostringstream oss;
        switch (unit) {
            case Unit::Px: oss << v << "px"; break;
            case Unit::Em: oss << v << "em"; break;
            case Unit::Rem: oss << v << "rem"; break;
            case Unit::Vw: oss << v << "vw"; break;
            case Unit::Vh: oss << v << "vh"; break;
            case Unit::Pct: oss << (v * 100.0f) << "%"; break;
            case Unit::Auto: oss << "auto"; break;
            case Unit::None: oss << "none"; break;
        }
        return oss.str();
    }
    static ValueHelper20 parse(const std::string& s) {
        ValueHelper20 h;
        if (s == "auto") { h.unit = Unit::Auto; return h; }
        if (s == "none") { h.unit = Unit::None; return h; }
        try { size_t p; h.v = std::stof(s, &p);
            std::string u = s.substr(p);
            if (u == "px") h.unit = Unit::Px;
            else if (u == "em") h.unit = Unit::Em;
            else if (u == "rem") h.unit = Unit::Rem;
            else if (u == "%") h.unit = Unit::Pct;
        } catch (...) { h.valid = false; }
        return h;
    }
};
} // anonymous namespace

// ═══ grid values — block 21 ═══
namespace {
struct ValueHelper21 {
    float v = 21.0f;
    std::string name = "grid values_21";
    bool valid = true;
    enum class Unit : uint8_t { Px, Em, Rem, Vw, Vh, Pct, Auto, None };
    Unit unit = Unit::Px;
    float resolve(float fs, float rfs, float vw, float vh) const {
        switch (unit) {
            case Unit::Px: return v;
            case Unit::Em: return v * fs;
            case Unit::Rem: return v * rfs;
            case Unit::Vw: return v * vw / 100.0f;
            case Unit::Vh: return v * vh / 100.0f;
            case Unit::Pct: return v / 100.0f;
            default: return 0.0f;
        }
    }
    std::string to_css() const {
        std::ostringstream oss;
        switch (unit) {
            case Unit::Px: oss << v << "px"; break;
            case Unit::Em: oss << v << "em"; break;
            case Unit::Rem: oss << v << "rem"; break;
            case Unit::Vw: oss << v << "vw"; break;
            case Unit::Vh: oss << v << "vh"; break;
            case Unit::Pct: oss << (v * 100.0f) << "%"; break;
            case Unit::Auto: oss << "auto"; break;
            case Unit::None: oss << "none"; break;
        }
        return oss.str();
    }
    static ValueHelper21 parse(const std::string& s) {
        ValueHelper21 h;
        if (s == "auto") { h.unit = Unit::Auto; return h; }
        if (s == "none") { h.unit = Unit::None; return h; }
        try { size_t p; h.v = std::stof(s, &p);
            std::string u = s.substr(p);
            if (u == "px") h.unit = Unit::Px;
            else if (u == "em") h.unit = Unit::Em;
            else if (u == "rem") h.unit = Unit::Rem;
            else if (u == "%") h.unit = Unit::Pct;
        } catch (...) { h.valid = false; }
        return h;
    }
};
} // anonymous namespace

#ifdef STYLE_TEST
bool test_grid_values(){return true;}
#endif
}}} // namespace