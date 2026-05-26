/* MPL 2.0 */
//! CSS alignment properties: justify-*, align-*, place-*.
//! Corresponds to values/specified/align.rs (782 lines)
#pragma once
#include <string>
#include <cstdint>

namespace style { namespace values { namespace specified {

enum class AlignFlags : uint8_t {
    Auto = 0, Normal, Stretch, Baseline, LastBaseline,
    FlexStart, FlexEnd, Center, Left, Right, SpaceBetween,
    SpaceAround, SpaceEvenly, Start, End, LegacyLeft,
    LegacyRight, LegacyCenter, Safe, Unsafe,
};

struct AlignItems { AlignFlags flags = AlignFlags::Normal; AlignFlags overflow = AlignFlags::Safe; };
struct AlignSelf { AlignFlags flags = AlignFlags::Auto; AlignFlags overflow = AlignFlags::Safe; };
struct AlignContent { AlignFlags flags = AlignFlags::Normal; AlignFlags overflow = AlignFlags::Safe; };
struct JustifyContent { AlignFlags flags = AlignFlags::Normal; AlignFlags overflow = AlignFlags::Safe; };
struct JustifyItems { AlignFlags flags = AlignFlags::Normal; AlignFlags overflow = AlignFlags::Safe; };
struct JustifySelf { AlignFlags flags = AlignFlags::Auto; AlignFlags overflow = AlignFlags::Safe; };
struct PlaceContent { AlignContent align; JustifyContent justify; };
struct PlaceItems { AlignItems align; JustifyItems justify; };
struct PlaceSelf { AlignSelf align; JustifySelf justify; };

}}} // namespace
