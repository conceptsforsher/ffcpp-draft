/* MPL 2.0 */
//! CSS animation and transition specified values.
//! Corresponds to values/specified/animation.rs (794 lines)
#pragma once
#include <string>
#include <vector>
#include "style/values/computed/types.hpp"

namespace style { namespace values { namespace specified {

using computed::ComputedEasing;

enum class AnimationDirection : uint8_t { Normal, Reverse, Alternate, AlternateReverse };
enum class AnimationFillMode : uint8_t { None, Forwards, Backwards, Both };
enum class AnimationPlayState : uint8_t { Running, Paused };
enum class AnimationTimeline : uint8_t { Auto, None, Scroll, View };

struct AnimationName {
    std::string name;
    bool is_none = true;
};
struct AnimationDuration { float seconds = 0.0f; };
struct AnimationDelay { float seconds = 0.0f; };
struct AnimationIterationCount { float value = 1.0f; bool infinite = false; };

// Transition property
struct TransitionProperty {
    std::string name;  // "all", "none", or specific property
    bool is_all = false;
    bool is_none = false;
};

}}} // namespace
