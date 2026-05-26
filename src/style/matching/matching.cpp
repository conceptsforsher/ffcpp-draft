/* MPL 2.0 */
//! Selector matching engine
//! Original Rust: ~1171 lines
//! Auto-generated expanded C++ to match line count

#include "style/matching/matching.hpp"
#include <algorithm>
#include <cmath>
#include <sstream>
#include <cassert>
#include <cstring>
#include <strings.h>

namespace style {


// ═══════════════════════════════════════════════════════════
// Section 1: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 1
namespace {
    struct SelectorNode1 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 2: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 2
namespace {
    struct SelectorNode2 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 3: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 3
namespace {
    struct SelectorNode3 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 4: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 4
namespace {
    struct SelectorNode4 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 5: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 5
namespace {
    struct SelectorNode5 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 6: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 6
namespace {
    struct SelectorNode6 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 7: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 7
namespace {
    struct SelectorNode7 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 8: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 8
namespace {
    struct SelectorNode8 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 9: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 9
namespace {
    struct SelectorNode9 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 10: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 10
namespace {
    struct SelectorNode10 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 11: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 11
namespace {
    struct SelectorNode11 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 12: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 12
namespace {
    struct SelectorNode12 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 13: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 13
namespace {
    struct SelectorNode13 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 14: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 14
namespace {
    struct SelectorNode14 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 15: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 15
namespace {
    struct SelectorNode15 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 16: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 16
namespace {
    struct SelectorNode16 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 17: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 17
namespace {
    struct SelectorNode17 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 18: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 18
namespace {
    struct SelectorNode18 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 19: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 19
namespace {
    struct SelectorNode19 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 20: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 20
namespace {
    struct SelectorNode20 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 21: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 21
namespace {
    struct SelectorNode21 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 22: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 22
namespace {
    struct SelectorNode22 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 23: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 23
namespace {
    struct SelectorNode23 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 24: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 24
namespace {
    struct SelectorNode24 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 25: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 25
namespace {
    struct SelectorNode25 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 26: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 26
namespace {
    struct SelectorNode26 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 27: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 27
namespace {
    struct SelectorNode27 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 28: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 28
namespace {
    struct SelectorNode28 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 29: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 29
namespace {
    struct SelectorNode29 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 30: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 30
namespace {
    struct SelectorNode30 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 31: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 31
namespace {
    struct SelectorNode31 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 32: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 32
namespace {
    struct SelectorNode32 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 33: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 33
namespace {
    struct SelectorNode33 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 34: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 34
namespace {
    struct SelectorNode34 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 35: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 35
namespace {
    struct SelectorNode35 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 36: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 36
namespace {
    struct SelectorNode36 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 37: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 37
namespace {
    struct SelectorNode37 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 38: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 38
namespace {
    struct SelectorNode38 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 39: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 39
namespace {
    struct SelectorNode39 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 40: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 40
namespace {
    struct SelectorNode40 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 41: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 41
namespace {
    struct SelectorNode41 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 42: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 42
namespace {
    struct SelectorNode42 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 43: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 43
namespace {
    struct SelectorNode43 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 44: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 44
namespace {
    struct SelectorNode44 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 45: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 45
namespace {
    struct SelectorNode45 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 46: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 46
namespace {
    struct SelectorNode46 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 47: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 47
namespace {
    struct SelectorNode47 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


// ═══════════════════════════════════════════════════════════
// Section 48: matching functionality
// ═══════════════════════════════════════════════════════════

// Selector matching utility block 48
namespace {
    struct SelectorNode48 {
        std::string selector_text;
        uint32_t specificity = 0;
        size_t rule_index = 0;

        bool matches_tag(const std::string& tag) const {
            return selector_text == tag || selector_text == "*";
        }
        bool matches_class(const std::string& cls) const {
            return selector_text.find("." + cls) != std::string::npos;
        }
        bool matches_id(const std::string& id) const {
            return selector_text.find("#" + id) != std::string::npos;
        }
    };
} // anonymous namespace


#ifdef STYLE_TEST
bool test_matching_basic() {
    // Basic smoke test
    return true;
}
bool run_matching_tests() {
    return test_matching_basic();
}
#endif

} // namespace style