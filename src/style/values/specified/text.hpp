/* MPL 2.0 */
//! Specified CSS text properties.
//! Corresponds to values/specified/text.rs (1188 lines)
#pragma once
#include <string>
#include <variant>
#include <vector>

namespace style { namespace values { namespace specified {

// ─── Text align ───
enum class TextAlign : uint8_t {
    Start, End, Left, Right, Center, Justify, MatchParent, JustifyAll
};
inline const char* text_align_name(TextAlign a) {
    switch(a){case TextAlign::Start:return"start";case TextAlign::End:return"end";
    case TextAlign::Left:return"left";case TextAlign::Right:return"right";
    case TextAlign::Center:return"center";case TextAlign::Justify:return"justify";}
    return"start";
}

// ─── Text decoration line ───
struct TextDecorationLine {
    bool underline = false;
    bool overline = false;
    bool line_through = false;
    bool blink = false;
    bool is_none() const { return !underline && !overline && !line_through && !blink; }
};

enum class TextDecorationStyle : uint8_t { Solid, Double, Dotted, Dashed, Wavy };
enum class TextUnderlinePosition : uint8_t { Auto, Under, Left, Right };

// ─── Text overflow ───
enum class TextOverflow : uint8_t { Clip, Ellipsis, Fade };

// ─── White space ───
enum class WhiteSpace : uint8_t {
    Normal, Pre, Nowrap, PreWrap, BreakSpaces, PreLine
};
inline bool white_space_preserves_newlines(WhiteSpace w) {
    return w==WhiteSpace::Pre||w==WhiteSpace::PreWrap||w==WhiteSpace::BreakSpaces||w==WhiteSpace::PreLine;
}
inline bool white_space_preserves_spaces(WhiteSpace w) {
    return w==WhiteSpace::Pre||w==WhiteSpace::PreWrap||w==WhiteSpace::BreakSpaces;
}
inline bool white_space_wraps(WhiteSpace w) {
    return w==WhiteSpace::Normal||w==WhiteSpace::Nowrap||w==WhiteSpace::PreLine;
}

// ─── Word break ───
enum class WordBreak : uint8_t { Normal, BreakAll, KeepAll, BreakWord };
enum class OverflowWrap : uint8_t { Normal, BreakWord, Anywhere };
enum class Hyphens : uint8_t { None, Manual, Auto };

// ─── Text transform ───
enum class TextTransform : uint8_t { None, Capitalize, Uppercase, Lowercase, FullWidth, FullSizeKana };

// ─── Direction ───
enum class Direction : uint8_t { Ltr, Rtl };
enum class UnicodeBidi : uint8_t { Normal, Embed, Isolate, BidiOverride, IsolateOverride, Plaintext };

// ─── Writing mode ───
enum class WritingModeValue : uint8_t {
    HorizontalTb, VerticalRl, VerticalLr, SidewaysRl, SidewaysLr
};
enum class TextOrientation : uint8_t { Mixed, Upright, Sideways };

// ─── Text shadow ───
struct TextShadow {
    float offset_x = 0.0f;
    float offset_y = 0.0f;
    float blur_radius = 0.0f;
    // Color color (deferred to color module)
};

// ─── Letter/word spacing ───
struct LetterSpacing { float value = 0.0f; bool normal = true; };
struct WordSpacing { float value = 0.0f; bool normal = true; };

// ─── Tab size ───
struct TabSize { float value = 8.0f; bool is_number = true; };

// ─── Line break ───
enum class LineBreak : uint8_t { Auto, Loose, Normal, Strict, Anywhere };

}}} // namespace
