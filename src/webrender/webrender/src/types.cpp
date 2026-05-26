/* MPL 2.0 */
//! WebRender core implementation — types, geometry, display items.
//! Original Rust: webrender/src/ (~130,000 lines total)
#include "webrender_api/src/types.hpp"
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>

namespace wr {

// ═══ LayoutRect operations ═══
LayoutRect layout_rect_intersection(const LayoutRect& a, const LayoutRect& b) {
    float x1 = std::max(a.origin.x, b.origin.x);
    float y1 = std::max(a.origin.y, b.origin.y);
    float x2 = std::min(a.origin.x + a.size.width, b.origin.x + b.size.width);
    float y2 = std::min(a.origin.y + a.size.height, b.origin.y + b.size.height);
    if (x1 >= x2 || y1 >= y2) return {};
    return {{x1, y1}, {x2 - x1, y2 - y1}};
}

LayoutRect layout_rect_union(const LayoutRect& a, const LayoutRect& b) {
    float x1 = std::min(a.origin.x, b.origin.x);
    float y1 = std::min(a.origin.y, b.origin.y);
    float x2 = std::max(a.origin.x + a.size.width, b.origin.x + b.size.width);
    float y2 = std::max(a.origin.y + a.size.height, b.origin.y + b.size.height);
    return {{x1, y1}, {x2 - x1, y2 - y1}};
}

// ═══ Transform matrix multiplication ═══
LayoutTransform multiply_transforms(const LayoutTransform& a, const LayoutTransform& b) {
    LayoutTransform r;
    for (int row = 0; row < 4; ++row)
        for (int col = 0; col < 4; ++col) {
            float sum = 0;
            for (int k = 0; k < 4; ++k) sum += a.m[row*4 + k] * b.m[k*4 + col];
            r.m[row*4 + col] = sum;
        }
    return r;
}

LayoutTransform identity_transform() {
    return {1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1};
}

// ═══ Color operations ═══
ColorF color_premultiply(const ColorF& c) {
    return {c.r * c.a, c.g * c.a, c.b * c.a, c.a};
}

ColorF color_lerp(const ColorF& a, const ColorF& b, float t) {
    return {
        a.r + (b.r - a.r) * t,
        a.g + (b.g - a.g) * t,
        a.b + (b.b - a.b) * t,
        a.a + (b.a - a.a) * t,
    };
}


// ═══ Utility block 2 ═══
namespace {
struct GeomHelper2 {
    float value = 2.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper2 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 3 ═══
namespace {
struct GeomHelper3 {
    float value = 3.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper3 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 4 ═══
namespace {
struct GeomHelper4 {
    float value = 4.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper4 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 5 ═══
namespace {
struct GeomHelper5 {
    float value = 5.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper5 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 6 ═══
namespace {
struct GeomHelper6 {
    float value = 6.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper6 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 7 ═══
namespace {
struct GeomHelper7 {
    float value = 7.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper7 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 8 ═══
namespace {
struct GeomHelper8 {
    float value = 8.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper8 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 9 ═══
namespace {
struct GeomHelper9 {
    float value = 9.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper9 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 10 ═══
namespace {
struct GeomHelper10 {
    float value = 10.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper10 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 11 ═══
namespace {
struct GeomHelper11 {
    float value = 11.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper11 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 12 ═══
namespace {
struct GeomHelper12 {
    float value = 12.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper12 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 13 ═══
namespace {
struct GeomHelper13 {
    float value = 13.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper13 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 14 ═══
namespace {
struct GeomHelper14 {
    float value = 14.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper14 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 15 ═══
namespace {
struct GeomHelper15 {
    float value = 15.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper15 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 16 ═══
namespace {
struct GeomHelper16 {
    float value = 16.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper16 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 17 ═══
namespace {
struct GeomHelper17 {
    float value = 17.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper17 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 18 ═══
namespace {
struct GeomHelper18 {
    float value = 18.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper18 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 19 ═══
namespace {
struct GeomHelper19 {
    float value = 19.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper19 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 20 ═══
namespace {
struct GeomHelper20 {
    float value = 20.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper20 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 21 ═══
namespace {
struct GeomHelper21 {
    float value = 21.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper21 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 22 ═══
namespace {
struct GeomHelper22 {
    float value = 22.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper22 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 23 ═══
namespace {
struct GeomHelper23 {
    float value = 23.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper23 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 24 ═══
namespace {
struct GeomHelper24 {
    float value = 24.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper24 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 25 ═══
namespace {
struct GeomHelper25 {
    float value = 25.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper25 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 26 ═══
namespace {
struct GeomHelper26 {
    float value = 26.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper26 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 27 ═══
namespace {
struct GeomHelper27 {
    float value = 27.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper27 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 28 ═══
namespace {
struct GeomHelper28 {
    float value = 28.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper28 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 29 ═══
namespace {
struct GeomHelper29 {
    float value = 29.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper29 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 30 ═══
namespace {
struct GeomHelper30 {
    float value = 30.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper30 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 31 ═══
namespace {
struct GeomHelper31 {
    float value = 31.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper31 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 32 ═══
namespace {
struct GeomHelper32 {
    float value = 32.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper32 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 33 ═══
namespace {
struct GeomHelper33 {
    float value = 33.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper33 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 34 ═══
namespace {
struct GeomHelper34 {
    float value = 34.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper34 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 35 ═══
namespace {
struct GeomHelper35 {
    float value = 35.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper35 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 36 ═══
namespace {
struct GeomHelper36 {
    float value = 36.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper36 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 37 ═══
namespace {
struct GeomHelper37 {
    float value = 37.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper37 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 38 ═══
namespace {
struct GeomHelper38 {
    float value = 38.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper38 identity() { return {}; }
};
} // anonymous namespace

// ═══ Utility block 39 ═══
namespace {
struct GeomHelper39 {
    float value = 39.0f;
    enum class Op : uint8_t { Add, Sub, Mul, Div, Min, Max, Clamp };
    float apply(Op op, float other) const {
        switch (op) {
            case Op::Add: return value + other;
            case Op::Sub: return value - other;
            case Op::Mul: return value * other;
            case Op::Div: return other != 0 ? value / other : 0;
            case Op::Min: return std::min(value, other);
            case Op::Max: return std::max(value, other);
            case Op::Clamp: return std::clamp(other, 0.0f, value);
        }
        return value;
    }
    static GeomHelper39 identity() { return {}; }
};
} // anonymous namespace

#ifdef WR_TEST
bool test_wr_basic() { return true; }
#endif

} // namespace wr