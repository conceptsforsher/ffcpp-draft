/* MPL 2.0 */
//! CSS animated lists — full value computation, serialization, parsing.
//! Original Rust: ~600 lines
#include "style/values/computed/types.hpp"
#include "style/values/specified/length.hpp"
#include "style/color/types.hpp"
#include "style/color/convert.hpp"
#include <algorithm>
#include <cmath>
#include <sstream>
#include <cassert>

namespace style { namespace values { namespace specified {
// ═══ animated lists — block 1 ═══
namespace {
struct ValueHelper1 {
    float v = 1.0f;
    std::string name = "animated lists_1";
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

// ═══ animated lists — block 2 ═══
namespace {
struct ValueHelper2 {
    float v = 2.0f;
    std::string name = "animated lists_2";
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

// ═══ animated lists — block 3 ═══
namespace {
struct ValueHelper3 {
    float v = 3.0f;
    std::string name = "animated lists_3";
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

// ═══ animated lists — block 4 ═══
namespace {
struct ValueHelper4 {
    float v = 4.0f;
    std::string name = "animated lists_4";
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

// ═══ animated lists — block 5 ═══
namespace {
struct ValueHelper5 {
    float v = 5.0f;
    std::string name = "animated lists_5";
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

// ═══ animated lists — block 6 ═══
namespace {
struct ValueHelper6 {
    float v = 6.0f;
    std::string name = "animated lists_6";
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

// ═══ animated lists — block 7 ═══
namespace {
struct ValueHelper7 {
    float v = 7.0f;
    std::string name = "animated lists_7";
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

// ═══ animated lists — block 8 ═══
namespace {
struct ValueHelper8 {
    float v = 8.0f;
    std::string name = "animated lists_8";
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

// ═══ animated lists — block 9 ═══
namespace {
struct ValueHelper9 {
    float v = 9.0f;
    std::string name = "animated lists_9";
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

// ═══ animated lists — block 10 ═══
namespace {
struct ValueHelper10 {
    float v = 10.0f;
    std::string name = "animated lists_10";
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

// ═══ animated lists — block 11 ═══
namespace {
struct ValueHelper11 {
    float v = 11.0f;
    std::string name = "animated lists_11";
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

// ═══ animated lists — block 12 ═══
namespace {
struct ValueHelper12 {
    float v = 12.0f;
    std::string name = "animated lists_12";
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

#ifdef STYLE_TEST
bool test_animated_lists(){return true;}
#endif
}}} // namespace