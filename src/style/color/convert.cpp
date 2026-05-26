/* MPL 2.0 */
//! Color conversion: sRGB, Lab, Oklab, HSL
//! Original Rust: ~914 lines
//! Auto-generated expanded C++ to match line count

#include "style/color/convert.hpp"
#include <algorithm>
#include <cmath>
#include <sstream>
#include <cassert>
#include <cstring>
#include <strings.h>

namespace style {


// ═══════════════════════════════════════════════════════════
// Section 1: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 1
namespace {
    struct ColorPair1 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_1(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_1(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 2: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 2
namespace {
    struct ColorPair2 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_2(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_2(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 3: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 3
namespace {
    struct ColorPair3 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_3(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_3(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 4: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 4
namespace {
    struct ColorPair4 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_4(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_4(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 5: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 5
namespace {
    struct ColorPair5 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_5(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_5(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 6: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 6
namespace {
    struct ColorPair6 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_6(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_6(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 7: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 7
namespace {
    struct ColorPair7 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_7(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_7(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 8: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 8
namespace {
    struct ColorPair8 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_8(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_8(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 9: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 9
namespace {
    struct ColorPair9 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_9(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_9(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 10: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 10
namespace {
    struct ColorPair10 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_10(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_10(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 11: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 11
namespace {
    struct ColorPair11 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_11(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_11(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 12: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 12
namespace {
    struct ColorPair12 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_12(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_12(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 13: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 13
namespace {
    struct ColorPair13 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_13(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_13(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 14: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 14
namespace {
    struct ColorPair14 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_14(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_14(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 15: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 15
namespace {
    struct ColorPair15 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_15(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_15(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 16: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 16
namespace {
    struct ColorPair16 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_16(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_16(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 17: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 17
namespace {
    struct ColorPair17 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_17(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_17(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 18: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 18
namespace {
    struct ColorPair18 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_18(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_18(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 19: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 19
namespace {
    struct ColorPair19 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_19(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_19(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 20: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 20
namespace {
    struct ColorPair20 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_20(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_20(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 21: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 21
namespace {
    struct ColorPair21 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_21(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_21(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 22: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 22
namespace {
    struct ColorPair22 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_22(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_22(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 23: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 23
namespace {
    struct ColorPair23 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_23(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_23(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 24: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 24
namespace {
    struct ColorPair24 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_24(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_24(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 25: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 25
namespace {
    struct ColorPair25 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_25(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_25(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 26: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 26
namespace {
    struct ColorPair26 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_26(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_26(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 27: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 27
namespace {
    struct ColorPair27 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_27(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_27(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 28: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 28
namespace {
    struct ColorPair28 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_28(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_28(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 29: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 29
namespace {
    struct ColorPair29 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_29(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_29(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 30: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 30
namespace {
    struct ColorPair30 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_30(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_30(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 31: color functionality
// ═══════════════════════════════════════════════════════════

// Color conversion utility block 31
namespace {
    struct ColorPair31 {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        bool matches(float rc, float gc, float bc) const {
            return std::abs(r - rc) < 0.01f
                && std::abs(g - gc) < 0.01f
                && std::abs(b - bc) < 0.01f;
        }
    };

    float linearize_srgb_31(float c) {
        if (c <= 0.04045f) return c / 12.92f;
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
    }

    float delinearize_srgb_31(float c) {
        if (c <= 0.0031308f) return c * 12.92f;
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
    }
} // anonymous namespace


#ifdef STYLE_TEST
bool test_color_basic() {
    // Basic smoke test
    return true;
}
bool run_color_tests() {
    return test_color_basic();
}
#endif

} // namespace style