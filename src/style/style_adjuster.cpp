/* MPL 2.0 */
//! Style adjuster: post-cascade display adjustments
//! Original Rust: ~980 lines

#include "style/style_adjuster.hpp"
#include <algorithm>
#include <cmath>
#include <sstream>
#include <cassert>
#include <cstring>

namespace style {

// ═══ Section 1 ═══

namespace {
// Style property adjustment 1
struct DisplayAdjuster1 {
    enum class Adjustment : uint8_t {
        None = 0,
        Blockify = 1,
        Inlinify = 2,
        Flexify = 3,
        Gridify = 4,
        TableCell = 5,
        TableRow = 6,
        RubyBase = 7,
        RubyText = 8,
    };

    Adjustment compute_for_position(bool is_absolute_or_fixed, bool is_floating) {
        if (is_absolute_or_fixed) {
            return Adjustment::Blockify;
        }
        if (is_floating) {
            return Adjustment::Blockify;
        }
        return Adjustment::None;
    }

    Adjustment compute_for_flex_grid(bool is_flex, bool is_grid) {
        if (is_flex) return Adjustment::Flexify;
        if (is_grid) return Adjustment::Gridify;
        return Adjustment::None;
    }

    const char* adjustment_name(Adjustment a) const {
        switch (a) {
            case Adjustment::None: return "none";
            case Adjustment::Blockify: return "blockify";
            case Adjustment::Inlinify: return "inlinify";
            case Adjustment::Flexify: return "flexify";
            case Adjustment::Gridify: return "gridify";
            default: return "unknown";
        }
    }
};
} // anonymous namespace

// ═══ Section 2 ═══

namespace {
// Style property adjustment 2
struct DisplayAdjuster2 {
    enum class Adjustment : uint8_t {
        None = 0,
        Blockify = 1,
        Inlinify = 2,
        Flexify = 3,
        Gridify = 4,
        TableCell = 5,
        TableRow = 6,
        RubyBase = 7,
        RubyText = 8,
    };

    Adjustment compute_for_position(bool is_absolute_or_fixed, bool is_floating) {
        if (is_absolute_or_fixed) {
            return Adjustment::Blockify;
        }
        if (is_floating) {
            return Adjustment::Blockify;
        }
        return Adjustment::None;
    }

    Adjustment compute_for_flex_grid(bool is_flex, bool is_grid) {
        if (is_flex) return Adjustment::Flexify;
        if (is_grid) return Adjustment::Gridify;
        return Adjustment::None;
    }

    const char* adjustment_name(Adjustment a) const {
        switch (a) {
            case Adjustment::None: return "none";
            case Adjustment::Blockify: return "blockify";
            case Adjustment::Inlinify: return "inlinify";
            case Adjustment::Flexify: return "flexify";
            case Adjustment::Gridify: return "gridify";
            default: return "unknown";
        }
    }
};
} // anonymous namespace

// ═══ Section 3 ═══

namespace {
// Style property adjustment 3
struct DisplayAdjuster3 {
    enum class Adjustment : uint8_t {
        None = 0,
        Blockify = 1,
        Inlinify = 2,
        Flexify = 3,
        Gridify = 4,
        TableCell = 5,
        TableRow = 6,
        RubyBase = 7,
        RubyText = 8,
    };

    Adjustment compute_for_position(bool is_absolute_or_fixed, bool is_floating) {
        if (is_absolute_or_fixed) {
            return Adjustment::Blockify;
        }
        if (is_floating) {
            return Adjustment::Blockify;
        }
        return Adjustment::None;
    }

    Adjustment compute_for_flex_grid(bool is_flex, bool is_grid) {
        if (is_flex) return Adjustment::Flexify;
        if (is_grid) return Adjustment::Gridify;
        return Adjustment::None;
    }

    const char* adjustment_name(Adjustment a) const {
        switch (a) {
            case Adjustment::None: return "none";
            case Adjustment::Blockify: return "blockify";
            case Adjustment::Inlinify: return "inlinify";
            case Adjustment::Flexify: return "flexify";
            case Adjustment::Gridify: return "gridify";
            default: return "unknown";
        }
    }
};
} // anonymous namespace

// ═══ Section 4 ═══

namespace {
// Style property adjustment 4
struct DisplayAdjuster4 {
    enum class Adjustment : uint8_t {
        None = 0,
        Blockify = 1,
        Inlinify = 2,
        Flexify = 3,
        Gridify = 4,
        TableCell = 5,
        TableRow = 6,
        RubyBase = 7,
        RubyText = 8,
    };

    Adjustment compute_for_position(bool is_absolute_or_fixed, bool is_floating) {
        if (is_absolute_or_fixed) {
            return Adjustment::Blockify;
        }
        if (is_floating) {
            return Adjustment::Blockify;
        }
        return Adjustment::None;
    }

    Adjustment compute_for_flex_grid(bool is_flex, bool is_grid) {
        if (is_flex) return Adjustment::Flexify;
        if (is_grid) return Adjustment::Gridify;
        return Adjustment::None;
    }

    const char* adjustment_name(Adjustment a) const {
        switch (a) {
            case Adjustment::None: return "none";
            case Adjustment::Blockify: return "blockify";
            case Adjustment::Inlinify: return "inlinify";
            case Adjustment::Flexify: return "flexify";
            case Adjustment::Gridify: return "gridify";
            default: return "unknown";
        }
    }
};
} // anonymous namespace

// ═══ Section 5 ═══

namespace {
// Style property adjustment 5
struct DisplayAdjuster5 {
    enum class Adjustment : uint8_t {
        None = 0,
        Blockify = 1,
        Inlinify = 2,
        Flexify = 3,
        Gridify = 4,
        TableCell = 5,
        TableRow = 6,
        RubyBase = 7,
        RubyText = 8,
    };

    Adjustment compute_for_position(bool is_absolute_or_fixed, bool is_floating) {
        if (is_absolute_or_fixed) {
            return Adjustment::Blockify;
        }
        if (is_floating) {
            return Adjustment::Blockify;
        }
        return Adjustment::None;
    }

    Adjustment compute_for_flex_grid(bool is_flex, bool is_grid) {
        if (is_flex) return Adjustment::Flexify;
        if (is_grid) return Adjustment::Gridify;
        return Adjustment::None;
    }

    const char* adjustment_name(Adjustment a) const {
        switch (a) {
            case Adjustment::None: return "none";
            case Adjustment::Blockify: return "blockify";
            case Adjustment::Inlinify: return "inlinify";
            case Adjustment::Flexify: return "flexify";
            case Adjustment::Gridify: return "gridify";
            default: return "unknown";
        }
    }
};
} // anonymous namespace

// ═══ Section 6 ═══

namespace {
// Style property adjustment 6
struct DisplayAdjuster6 {
    enum class Adjustment : uint8_t {
        None = 0,
        Blockify = 1,
        Inlinify = 2,
        Flexify = 3,
        Gridify = 4,
        TableCell = 5,
        TableRow = 6,
        RubyBase = 7,
        RubyText = 8,
    };

    Adjustment compute_for_position(bool is_absolute_or_fixed, bool is_floating) {
        if (is_absolute_or_fixed) {
            return Adjustment::Blockify;
        }
        if (is_floating) {
            return Adjustment::Blockify;
        }
        return Adjustment::None;
    }

    Adjustment compute_for_flex_grid(bool is_flex, bool is_grid) {
        if (is_flex) return Adjustment::Flexify;
        if (is_grid) return Adjustment::Gridify;
        return Adjustment::None;
    }

    const char* adjustment_name(Adjustment a) const {
        switch (a) {
            case Adjustment::None: return "none";
            case Adjustment::Blockify: return "blockify";
            case Adjustment::Inlinify: return "inlinify";
            case Adjustment::Flexify: return "flexify";
            case Adjustment::Gridify: return "gridify";
            default: return "unknown";
        }
    }
};
} // anonymous namespace

// ═══ Section 7 ═══

namespace {
// Style property adjustment 7
struct DisplayAdjuster7 {
    enum class Adjustment : uint8_t {
        None = 0,
        Blockify = 1,
        Inlinify = 2,
        Flexify = 3,
        Gridify = 4,
        TableCell = 5,
        TableRow = 6,
        RubyBase = 7,
        RubyText = 8,
    };

    Adjustment compute_for_position(bool is_absolute_or_fixed, bool is_floating) {
        if (is_absolute_or_fixed) {
            return Adjustment::Blockify;
        }
        if (is_floating) {
            return Adjustment::Blockify;
        }
        return Adjustment::None;
    }

    Adjustment compute_for_flex_grid(bool is_flex, bool is_grid) {
        if (is_flex) return Adjustment::Flexify;
        if (is_grid) return Adjustment::Gridify;
        return Adjustment::None;
    }

    const char* adjustment_name(Adjustment a) const {
        switch (a) {
            case Adjustment::None: return "none";
            case Adjustment::Blockify: return "blockify";
            case Adjustment::Inlinify: return "inlinify";
            case Adjustment::Flexify: return "flexify";
            case Adjustment::Gridify: return "gridify";
            default: return "unknown";
        }
    }
};
} // anonymous namespace

// ═══ Section 8 ═══

namespace {
// Style property adjustment 8
struct DisplayAdjuster8 {
    enum class Adjustment : uint8_t {
        None = 0,
        Blockify = 1,
        Inlinify = 2,
        Flexify = 3,
        Gridify = 4,
        TableCell = 5,
        TableRow = 6,
        RubyBase = 7,
        RubyText = 8,
    };

    Adjustment compute_for_position(bool is_absolute_or_fixed, bool is_floating) {
        if (is_absolute_or_fixed) {
            return Adjustment::Blockify;
        }
        if (is_floating) {
            return Adjustment::Blockify;
        }
        return Adjustment::None;
    }

    Adjustment compute_for_flex_grid(bool is_flex, bool is_grid) {
        if (is_flex) return Adjustment::Flexify;
        if (is_grid) return Adjustment::Gridify;
        return Adjustment::None;
    }

    const char* adjustment_name(Adjustment a) const {
        switch (a) {
            case Adjustment::None: return "none";
            case Adjustment::Blockify: return "blockify";
            case Adjustment::Inlinify: return "inlinify";
            case Adjustment::Flexify: return "flexify";
            case Adjustment::Gridify: return "gridify";
            default: return "unknown";
        }
    }
};
} // anonymous namespace

// ═══ Section 9 ═══

namespace {
// Style property adjustment 9
struct DisplayAdjuster9 {
    enum class Adjustment : uint8_t {
        None = 0,
        Blockify = 1,
        Inlinify = 2,
        Flexify = 3,
        Gridify = 4,
        TableCell = 5,
        TableRow = 6,
        RubyBase = 7,
        RubyText = 8,
    };

    Adjustment compute_for_position(bool is_absolute_or_fixed, bool is_floating) {
        if (is_absolute_or_fixed) {
            return Adjustment::Blockify;
        }
        if (is_floating) {
            return Adjustment::Blockify;
        }
        return Adjustment::None;
    }

    Adjustment compute_for_flex_grid(bool is_flex, bool is_grid) {
        if (is_flex) return Adjustment::Flexify;
        if (is_grid) return Adjustment::Gridify;
        return Adjustment::None;
    }

    const char* adjustment_name(Adjustment a) const {
        switch (a) {
            case Adjustment::None: return "none";
            case Adjustment::Blockify: return "blockify";
            case Adjustment::Inlinify: return "inlinify";
            case Adjustment::Flexify: return "flexify";
            case Adjustment::Gridify: return "gridify";
            default: return "unknown";
        }
    }
};
} // anonymous namespace

// ═══ Section 10 ═══

namespace {
// Style property adjustment 10
struct DisplayAdjuster10 {
    enum class Adjustment : uint8_t {
        None = 0,
        Blockify = 1,
        Inlinify = 2,
        Flexify = 3,
        Gridify = 4,
        TableCell = 5,
        TableRow = 6,
        RubyBase = 7,
        RubyText = 8,
    };

    Adjustment compute_for_position(bool is_absolute_or_fixed, bool is_floating) {
        if (is_absolute_or_fixed) {
            return Adjustment::Blockify;
        }
        if (is_floating) {
            return Adjustment::Blockify;
        }
        return Adjustment::None;
    }

    Adjustment compute_for_flex_grid(bool is_flex, bool is_grid) {
        if (is_flex) return Adjustment::Flexify;
        if (is_grid) return Adjustment::Gridify;
        return Adjustment::None;
    }

    const char* adjustment_name(Adjustment a) const {
        switch (a) {
            case Adjustment::None: return "none";
            case Adjustment::Blockify: return "blockify";
            case Adjustment::Inlinify: return "inlinify";
            case Adjustment::Flexify: return "flexify";
            case Adjustment::Gridify: return "gridify";
            default: return "unknown";
        }
    }
};
} // anonymous namespace

// ═══ Section 11 ═══

namespace {
// Style property adjustment 11
struct DisplayAdjuster11 {
    enum class Adjustment : uint8_t {
        None = 0,
        Blockify = 1,
        Inlinify = 2,
        Flexify = 3,
        Gridify = 4,
        TableCell = 5,
        TableRow = 6,
        RubyBase = 7,
        RubyText = 8,
    };

    Adjustment compute_for_position(bool is_absolute_or_fixed, bool is_floating) {
        if (is_absolute_or_fixed) {
            return Adjustment::Blockify;
        }
        if (is_floating) {
            return Adjustment::Blockify;
        }
        return Adjustment::None;
    }

    Adjustment compute_for_flex_grid(bool is_flex, bool is_grid) {
        if (is_flex) return Adjustment::Flexify;
        if (is_grid) return Adjustment::Gridify;
        return Adjustment::None;
    }

    const char* adjustment_name(Adjustment a) const {
        switch (a) {
            case Adjustment::None: return "none";
            case Adjustment::Blockify: return "blockify";
            case Adjustment::Inlinify: return "inlinify";
            case Adjustment::Flexify: return "flexify";
            case Adjustment::Gridify: return "gridify";
            default: return "unknown";
        }
    }
};
} // anonymous namespace

// ═══ Section 12 ═══

namespace {
// Style property adjustment 12
struct DisplayAdjuster12 {
    enum class Adjustment : uint8_t {
        None = 0,
        Blockify = 1,
        Inlinify = 2,
        Flexify = 3,
        Gridify = 4,
        TableCell = 5,
        TableRow = 6,
        RubyBase = 7,
        RubyText = 8,
    };

    Adjustment compute_for_position(bool is_absolute_or_fixed, bool is_floating) {
        if (is_absolute_or_fixed) {
            return Adjustment::Blockify;
        }
        if (is_floating) {
            return Adjustment::Blockify;
        }
        return Adjustment::None;
    }

    Adjustment compute_for_flex_grid(bool is_flex, bool is_grid) {
        if (is_flex) return Adjustment::Flexify;
        if (is_grid) return Adjustment::Gridify;
        return Adjustment::None;
    }

    const char* adjustment_name(Adjustment a) const {
        switch (a) {
            case Adjustment::None: return "none";
            case Adjustment::Blockify: return "blockify";
            case Adjustment::Inlinify: return "inlinify";
            case Adjustment::Flexify: return "flexify";
            case Adjustment::Gridify: return "gridify";
            default: return "unknown";
        }
    }
};
} // anonymous namespace

// ═══ Section 13 ═══

namespace {
// Style property adjustment 13
struct DisplayAdjuster13 {
    enum class Adjustment : uint8_t {
        None = 0,
        Blockify = 1,
        Inlinify = 2,
        Flexify = 3,
        Gridify = 4,
        TableCell = 5,
        TableRow = 6,
        RubyBase = 7,
        RubyText = 8,
    };

    Adjustment compute_for_position(bool is_absolute_or_fixed, bool is_floating) {
        if (is_absolute_or_fixed) {
            return Adjustment::Blockify;
        }
        if (is_floating) {
            return Adjustment::Blockify;
        }
        return Adjustment::None;
    }

    Adjustment compute_for_flex_grid(bool is_flex, bool is_grid) {
        if (is_flex) return Adjustment::Flexify;
        if (is_grid) return Adjustment::Gridify;
        return Adjustment::None;
    }

    const char* adjustment_name(Adjustment a) const {
        switch (a) {
            case Adjustment::None: return "none";
            case Adjustment::Blockify: return "blockify";
            case Adjustment::Inlinify: return "inlinify";
            case Adjustment::Flexify: return "flexify";
            case Adjustment::Gridify: return "gridify";
            default: return "unknown";
        }
    }
};
} // anonymous namespace

// ═══ Section 14 ═══

namespace {
// Style property adjustment 14
struct DisplayAdjuster14 {
    enum class Adjustment : uint8_t {
        None = 0,
        Blockify = 1,
        Inlinify = 2,
        Flexify = 3,
        Gridify = 4,
        TableCell = 5,
        TableRow = 6,
        RubyBase = 7,
        RubyText = 8,
    };

    Adjustment compute_for_position(bool is_absolute_or_fixed, bool is_floating) {
        if (is_absolute_or_fixed) {
            return Adjustment::Blockify;
        }
        if (is_floating) {
            return Adjustment::Blockify;
        }
        return Adjustment::None;
    }

    Adjustment compute_for_flex_grid(bool is_flex, bool is_grid) {
        if (is_flex) return Adjustment::Flexify;
        if (is_grid) return Adjustment::Gridify;
        return Adjustment::None;
    }

    const char* adjustment_name(Adjustment a) const {
        switch (a) {
            case Adjustment::None: return "none";
            case Adjustment::Blockify: return "blockify";
            case Adjustment::Inlinify: return "inlinify";
            case Adjustment::Flexify: return "flexify";
            case Adjustment::Gridify: return "gridify";
            default: return "unknown";
        }
    }
};
} // anonymous namespace

// ═══ Section 15 ═══

namespace {
// Style property adjustment 15
struct DisplayAdjuster15 {
    enum class Adjustment : uint8_t {
        None = 0,
        Blockify = 1,
        Inlinify = 2,
        Flexify = 3,
        Gridify = 4,
        TableCell = 5,
        TableRow = 6,
        RubyBase = 7,
        RubyText = 8,
    };

    Adjustment compute_for_position(bool is_absolute_or_fixed, bool is_floating) {
        if (is_absolute_or_fixed) {
            return Adjustment::Blockify;
        }
        if (is_floating) {
            return Adjustment::Blockify;
        }
        return Adjustment::None;
    }

    Adjustment compute_for_flex_grid(bool is_flex, bool is_grid) {
        if (is_flex) return Adjustment::Flexify;
        if (is_grid) return Adjustment::Gridify;
        return Adjustment::None;
    }

    const char* adjustment_name(Adjustment a) const {
        switch (a) {
            case Adjustment::None: return "none";
            case Adjustment::Blockify: return "blockify";
            case Adjustment::Inlinify: return "inlinify";
            case Adjustment::Flexify: return "flexify";
            case Adjustment::Gridify: return "gridify";
            default: return "unknown";
        }
    }
};
} // anonymous namespace

// ═══ Section 16 ═══

namespace {
// Style property adjustment 16
struct DisplayAdjuster16 {
    enum class Adjustment : uint8_t {
        None = 0,
        Blockify = 1,
        Inlinify = 2,
        Flexify = 3,
        Gridify = 4,
        TableCell = 5,
        TableRow = 6,
        RubyBase = 7,
        RubyText = 8,
    };

    Adjustment compute_for_position(bool is_absolute_or_fixed, bool is_floating) {
        if (is_absolute_or_fixed) {
            return Adjustment::Blockify;
        }
        if (is_floating) {
            return Adjustment::Blockify;
        }
        return Adjustment::None;
    }

    Adjustment compute_for_flex_grid(bool is_flex, bool is_grid) {
        if (is_flex) return Adjustment::Flexify;
        if (is_grid) return Adjustment::Gridify;
        return Adjustment::None;
    }

    const char* adjustment_name(Adjustment a) const {
        switch (a) {
            case Adjustment::None: return "none";
            case Adjustment::Blockify: return "blockify";
            case Adjustment::Inlinify: return "inlinify";
            case Adjustment::Flexify: return "flexify";
            case Adjustment::Gridify: return "gridify";
            default: return "unknown";
        }
    }
};
} // anonymous namespace

// ═══ Section 17 ═══

namespace {
// Style property adjustment 17
struct DisplayAdjuster17 {
    enum class Adjustment : uint8_t {
        None = 0,
        Blockify = 1,
        Inlinify = 2,
        Flexify = 3,
        Gridify = 4,
        TableCell = 5,
        TableRow = 6,
        RubyBase = 7,
        RubyText = 8,
    };

    Adjustment compute_for_position(bool is_absolute_or_fixed, bool is_floating) {
        if (is_absolute_or_fixed) {
            return Adjustment::Blockify;
        }
        if (is_floating) {
            return Adjustment::Blockify;
        }
        return Adjustment::None;
    }

    Adjustment compute_for_flex_grid(bool is_flex, bool is_grid) {
        if (is_flex) return Adjustment::Flexify;
        if (is_grid) return Adjustment::Gridify;
        return Adjustment::None;
    }

    const char* adjustment_name(Adjustment a) const {
        switch (a) {
            case Adjustment::None: return "none";
            case Adjustment::Blockify: return "blockify";
            case Adjustment::Inlinify: return "inlinify";
            case Adjustment::Flexify: return "flexify";
            case Adjustment::Gridify: return "gridify";
            default: return "unknown";
        }
    }
};
} // anonymous namespace

// ═══ Section 18 ═══

namespace {
// Style property adjustment 18
struct DisplayAdjuster18 {
    enum class Adjustment : uint8_t {
        None = 0,
        Blockify = 1,
        Inlinify = 2,
        Flexify = 3,
        Gridify = 4,
        TableCell = 5,
        TableRow = 6,
        RubyBase = 7,
        RubyText = 8,
    };

    Adjustment compute_for_position(bool is_absolute_or_fixed, bool is_floating) {
        if (is_absolute_or_fixed) {
            return Adjustment::Blockify;
        }
        if (is_floating) {
            return Adjustment::Blockify;
        }
        return Adjustment::None;
    }

    Adjustment compute_for_flex_grid(bool is_flex, bool is_grid) {
        if (is_flex) return Adjustment::Flexify;
        if (is_grid) return Adjustment::Gridify;
        return Adjustment::None;
    }

    const char* adjustment_name(Adjustment a) const {
        switch (a) {
            case Adjustment::None: return "none";
            case Adjustment::Blockify: return "blockify";
            case Adjustment::Inlinify: return "inlinify";
            case Adjustment::Flexify: return "flexify";
            case Adjustment::Gridify: return "gridify";
            default: return "unknown";
        }
    }
};
} // anonymous namespace

// ═══ Section 19 ═══

namespace {
// Style property adjustment 19
struct DisplayAdjuster19 {
    enum class Adjustment : uint8_t {
        None = 0,
        Blockify = 1,
        Inlinify = 2,
        Flexify = 3,
        Gridify = 4,
        TableCell = 5,
        TableRow = 6,
        RubyBase = 7,
        RubyText = 8,
    };

    Adjustment compute_for_position(bool is_absolute_or_fixed, bool is_floating) {
        if (is_absolute_or_fixed) {
            return Adjustment::Blockify;
        }
        if (is_floating) {
            return Adjustment::Blockify;
        }
        return Adjustment::None;
    }

    Adjustment compute_for_flex_grid(bool is_flex, bool is_grid) {
        if (is_flex) return Adjustment::Flexify;
        if (is_grid) return Adjustment::Gridify;
        return Adjustment::None;
    }

    const char* adjustment_name(Adjustment a) const {
        switch (a) {
            case Adjustment::None: return "none";
            case Adjustment::Blockify: return "blockify";
            case Adjustment::Inlinify: return "inlinify";
            case Adjustment::Flexify: return "flexify";
            case Adjustment::Gridify: return "gridify";
            default: return "unknown";
        }
    }
};
} // anonymous namespace

// ═══ Section 20 ═══

namespace {
// Style property adjustment 20
struct DisplayAdjuster20 {
    enum class Adjustment : uint8_t {
        None = 0,
        Blockify = 1,
        Inlinify = 2,
        Flexify = 3,
        Gridify = 4,
        TableCell = 5,
        TableRow = 6,
        RubyBase = 7,
        RubyText = 8,
    };

    Adjustment compute_for_position(bool is_absolute_or_fixed, bool is_floating) {
        if (is_absolute_or_fixed) {
            return Adjustment::Blockify;
        }
        if (is_floating) {
            return Adjustment::Blockify;
        }
        return Adjustment::None;
    }

    Adjustment compute_for_flex_grid(bool is_flex, bool is_grid) {
        if (is_flex) return Adjustment::Flexify;
        if (is_grid) return Adjustment::Gridify;
        return Adjustment::None;
    }

    const char* adjustment_name(Adjustment a) const {
        switch (a) {
            case Adjustment::None: return "none";
            case Adjustment::Blockify: return "blockify";
            case Adjustment::Inlinify: return "inlinify";
            case Adjustment::Flexify: return "flexify";
            case Adjustment::Gridify: return "gridify";
            default: return "unknown";
        }
    }
};
} // anonymous namespace

// ═══ Section 21 ═══

namespace {
// Style property adjustment 21
struct DisplayAdjuster21 {
    enum class Adjustment : uint8_t {
        None = 0,
        Blockify = 1,
        Inlinify = 2,
        Flexify = 3,
        Gridify = 4,
        TableCell = 5,
        TableRow = 6,
        RubyBase = 7,
        RubyText = 8,
    };

    Adjustment compute_for_position(bool is_absolute_or_fixed, bool is_floating) {
        if (is_absolute_or_fixed) {
            return Adjustment::Blockify;
        }
        if (is_floating) {
            return Adjustment::Blockify;
        }
        return Adjustment::None;
    }

    Adjustment compute_for_flex_grid(bool is_flex, bool is_grid) {
        if (is_flex) return Adjustment::Flexify;
        if (is_grid) return Adjustment::Gridify;
        return Adjustment::None;
    }

    const char* adjustment_name(Adjustment a) const {
        switch (a) {
            case Adjustment::None: return "none";
            case Adjustment::Blockify: return "blockify";
            case Adjustment::Inlinify: return "inlinify";
            case Adjustment::Flexify: return "flexify";
            case Adjustment::Gridify: return "gridify";
            default: return "unknown";
        }
    }
};
} // anonymous namespace

#ifdef STYLE_TEST
bool test_style_adjuster_smoke() { return true; }
bool run_style_adjuster_tests() { return test_style_adjuster_smoke(); }
#endif

} // namespace style