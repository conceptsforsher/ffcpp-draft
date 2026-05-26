/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

//! CSS transitions and animations.
//!
//! This module provides the C++ translation of the Servo animation system,
//! handling both CSS animations (@keyframes) and CSS transitions.
//!
//! Architecture overview:
//!   - PropertyAnimation: Core interpolation unit for a single property
//!   - Animation: A CSS @keyframes animation instance
//!   - Transition: A CSS transition instance
//!   - ElementAnimationSet: Per-element collection of all animations/transitions
//!
//! The animation system integrates with the rule tree via CascadeLevel::Animations
//! and CascadeLevel::Transitions, allowing animated values to participate in
//! the CSS cascade.

#pragma once

#include <cmath>
#include <cstdint>
#include <functional>
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace style {
namespace animation {

// =============================================================================
// Forward Declarations
// =============================================================================

class PropertyAnimation;
class Animation;
class Transition;
class ElementAnimationSet;

// =============================================================================
// Animation Direction
// =============================================================================

/// The animation-direction property values.
enum class AnimationDirection : uint8_t {
    Normal = 0,
    Reverse,
    Alternate,
    AlternateReverse,

    // Sentinel value for array sizing
    COUNT = 4
};

/// Convert AnimationDirection to its CSS string representation.
const char* AnimationDirectionToString(AnimationDirection dir);
AnimationDirection AnimationDirectionFromString(const std::string& s);

/// Returns whether this direction should start reversed.
inline bool IsReversedDirection(AnimationDirection dir) {
    return dir == AnimationDirection::Reverse ||
           dir == AnimationDirection::AlternateReverse;
}

// =============================================================================
// Animation Fill Mode
// =============================================================================

/// The animation-fill-mode property values.
enum class AnimationFillMode : uint8_t {
    None = 0,
    Forwards,
    Backwards,
    Both,

    COUNT = 4
};

const char* AnimationFillModeToString(AnimationFillMode mode);
AnimationFillMode AnimationFillModeFromString(const std::string& s);

// =============================================================================
// Animation Play State
// =============================================================================

/// The animation-play-state property values.
enum class AnimationPlayState : uint8_t {
    Running = 0,
    Paused,

    COUNT = 2
};

const char* AnimationPlayStateToString(AnimationPlayState state);
AnimationPlayState AnimationPlayStateFromString(const std::string& s);

// =============================================================================
// Animation State Enum
// =============================================================================

/// Represents the state of an animation at a given time.
///
/// This tracks the lifecycle of both animations and transitions:
///   Pending  -> Running -> Finished
///                    \-> Canceled
///
/// Paused is a special state entered during Running.
enum class AnimationStateType : uint8_t {
    /// The animation has been created but is not running yet.
    /// Also used during the first delay phase.
    Pending = 0,

    /// The animation is currently running.
    Running,

    /// The animation is paused, with the associated progress (0.0 to 1.0+).
    Paused,

    /// The animation has finished normally.
    Finished,

    /// The animation has been canceled.
    Canceled,

    COUNT = 5
};

/// The AnimationState class, wrapping the state enum with optional progress.
class AnimationState {
public:
    // --- Construction ---

    AnimationState() : state_(AnimationStateType::Pending), progress_(0.0) {}
    explicit AnimationState(AnimationStateType state, double progress = 0.0)
        : state_(state), progress_(progress) {}

    static AnimationState Pending() { return AnimationState(AnimationStateType::Pending); }
    static AnimationState Running() { return AnimationState(AnimationStateType::Running); }
    static AnimationState Paused(double progress) {
        return AnimationState(AnimationStateType::Paused, progress);
    }
    static AnimationState Finished() { return AnimationState(AnimationStateType::Finished); }
    static AnimationState Canceled() { return AnimationState(AnimationStateType::Canceled); }

    // --- Accessors ---

    AnimationStateType state() const { return state_; }
    double progress() const { return progress_; }

    void set_state(AnimationStateType s) { state_ = s; }
    void set_progress(double p) { progress_ = p; }

    /// Whether this state requires its owning animation to be ticked.
    bool needs_to_be_ticked() const {
        return state_ == AnimationStateType::Running ||
               state_ == AnimationStateType::Pending;
    }

    /// Whether the animation is effectively still alive (not canceled/finished).
    bool is_active() const {
        return state_ != AnimationStateType::Canceled &&
               state_ != AnimationStateType::Finished;
    }

    // --- Comparison ---

    bool operator==(const AnimationState& other) const {
        return state_ == other.state_ && progress_ == other.progress_;
    }
    bool operator!=(const AnimationState& other) const { return !(*this == other); }

    // --- Serialization ---
    std::string ToString() const;
    static std::optional<AnimationState> FromString(const std::string& s);

private:
    AnimationStateType state_;
    double progress_;  // Only meaningful for Paused state
};

// =============================================================================
// Keyframes Iteration State
// =============================================================================

/// Tracks the current iteration state of a keyframes animation.
///
/// For finite iteration counts, we track both current and max.
/// For infinite, just the current iteration number (for event dispatch).
class KeyframesIterationState {
public:
    // --- Construction ---

    /// Infinite iterations, starting at 0.
    static KeyframesIterationState Infinite() {
        KeyframesIterationState k;
        k.is_infinite_ = true;
        k.current_ = 0.0;
        k.max_ = 0.0;
        return k;
    }

    /// Infinite iterations with a given current count.
    static KeyframesIterationState InfiniteAt(double current) {
        KeyframesIterationState k;
        k.is_infinite_ = true;
        k.current_ = current;
        k.max_ = 0.0;
        return k;
    }

    /// Finite iterations with current and max counts.
    static KeyframesIterationState Finite(double current, double max) {
        KeyframesIterationState k;
        k.is_infinite_ = false;
        k.current_ = current;
        k.max_ = max;
        return k;
    }

    // --- Accessors ---

    bool is_infinite() const { return is_infinite_; }
    double current() const { return current_; }
    double max() const { return max_; }

    void set_current(double c) { current_ = c; }
    void increment_current() { current_ += 1.0; }
    void cap_current_at_max() { if (current_ > max_) current_ = max_; }

    /// Returns the remaining iterations as a fraction (0..1).
    double remaining_progress() const {
        if (is_infinite_) return 1.0;
        return std::min(max_ - current_, 1.0);
    }

    /// Whether we are on the last iteration.
    bool on_last_iteration() const {
        if (is_infinite_) return false;
        return current_ >= (max_ - 1.0);
    }

    // --- Serialization ---

    std::string ToString() const;
    static KeyframesIterationState FromString(const std::string& s);

private:
    KeyframesIterationState() : is_infinite_(false), current_(0.0), max_(0.0) {}

    bool is_infinite_;
    double current_;
    double max_;
};

// =============================================================================
// Animation Value (placeholder - references actual AnimationValue type)
// =============================================================================

// Forward-declared; the real type lives in properties/animated_properties
struct AnimationValue;
using AnimationValuePtr = std::shared_ptr<AnimationValue>;
using AnimationValueMap = std::unordered_map<uint32_t, AnimationValue>;

// =============================================================================
// Property Animation
// =============================================================================

/// A PropertyAnimation represents the interpolation of a single CSS property
/// between two computed values over time, driven by a timing function.
///
/// This is the core unit for both CSS animations (keyframes) and transitions.
class PropertyAnimation {
public:
    // --- Construction ---

    PropertyAnimation() : duration_(0.0) {}

    PropertyAnimation(const AnimationValue& from,
                      const AnimationValue& to,
                      const class TimingFunction& timing_function,
                      double duration)
        : from_(from), to_(to),
          timing_function_(timing_function), duration_(duration) {}

    /// Attempt to create a PropertyAnimation from a property declaration change.
    /// Returns std::nullopt if no animation is needed (same values or zero duration).
    static std::optional<PropertyAnimation> FromPropertyDeclaration(
        const struct PropertyDeclarationId& property_declaration,
        const TimingFunction& timing_function,
        const struct Time& duration,
        const class ComputedValues& old_style,
        const class ComputedValues& new_style);

    // --- Accessors ---

    /// Returns the property ID being animated.
    PropertyDeclarationId property_id() const;

    const AnimationValue& from() const { return from_; }
    const AnimationValue& to() const { return to_; }
    const TimingFunction& timing_function() const { return timing_function_; }
    double duration() const { return duration_; }

    void set_from(const AnimationValue& v) { from_ = v; }
    void set_to(const AnimationValue& v) { to_ = v; }
    void set_duration(double d) { duration_ = d; }

    // --- Computation ---

    /// Compute the timing function output for the given progress ratio.
    /// Uses the epsilon appropriate for SMIL-style step calculation.
    double timing_function_output(double progress) const;

    /// Update the animation value at a given point of progress (0.0 to 1.0).
    /// Falls back to discrete interpolation (threshold at 0.5) if smooth fails.
    AnimationValue calculate_value(double progress) const;

    /// Whether the from and to values can be smoothly interpolated.
    bool interpolable() const;

    // --- Serialization ---

    std::string ToString() const;

    bool operator==(const PropertyAnimation& other) const;
    bool operator!=(const PropertyAnimation& other) const { return !(*this == other); }

private:
    AnimationValue from_;
    AnimationValue to_;
    TimingFunction timing_function_;
    double duration_;  // in seconds
};

// =============================================================================
// Computed Keyframe
// =============================================================================

/// A single computed keyframe for a CSS animation.
///
/// Each keyframe represents a percentage point in the animation with:
///   - A timing function for transitions between this and the next keyframe
///   - A start percentage (0.0-1.0)
///   - Animation values for each animating property
class ComputedKeyframe {
public:
    ComputedKeyframe()
        : start_percentage_(0.0f) {}

    ComputedKeyframe(const TimingFunction& timing_function,
                     float start_percentage,
                     std::vector<AnimationValue> values)
        : timing_function_(timing_function),
          start_percentage_(start_percentage),
          values_(std::move(values)) {}

    // --- Accessors ---

    const TimingFunction& timing_function() const { return timing_function_; }
    float start_percentage() const { return start_percentage_; }
    const std::vector<AnimationValue>& values() const { return values_; }
    size_t value_count() const { return values_.size(); }

    const AnimationValue& value_at(size_t index) const { return values_[index]; }
    AnimationValue& value_at(size_t index) { return values_[index]; }

    // --- Serialization ---

    std::string ToString() const;
    static std::optional<ComputedKeyframe> FromString(const std::string& s);

private:
    TimingFunction timing_function_;
    float start_percentage_;  // 0.0 to 1.0
    std::vector<AnimationValue> values_;
};

// =============================================================================
// Animation (CSS @keyframes)
// =============================================================================

/// A CSS Animation instance, representing one named @keyframes animation
/// applied to an element.
///
/// Tracks the animation lifecycle, iteration state, and computes animated
/// property values at any given time.
class Animation {
public:
    // --- Construction ---

    Animation();
    Animation(std::string name,
              std::vector<ComputedKeyframe> computed_steps,
              double started_at,
              double duration,
              double delay,
              AnimationFillMode fill_mode,
              AnimationDirection direction);

    // --- Accessors ---

    const std::string& name() const { return name_; }
    const std::vector<ComputedKeyframe>& computed_steps() const { return computed_steps_; }
    double started_at() const { return started_at_; }
    double duration() const { return duration_; }
    double delay() const { return delay_; }
    AnimationFillMode fill_mode() const { return fill_mode_; }
    AnimationDirection direction() const { return direction_; }
    AnimationDirection current_direction() const { return current_direction_; }
    const AnimationState& state() const { return state_; }
    const KeyframesIterationState& iteration_state() const { return iteration_state_; }
    bool is_new() const { return is_new_; }

    void set_started_at(double t) { started_at_ = t; }
    void set_current_direction(AnimationDirection d) { current_direction_ = d; }
    void set_state(const AnimationState& s) { state_ = s; }
    void set_is_new(bool n) { is_new_ = n; }

    // --- Iteration Management ---

    /// Whether the current iteration is over at the given time.
    /// Assumes the animation is still running.
    bool iteration_over(double time) const;

    /// Whether we are on the last iteration.
    bool on_last_iteration() const {
        return iteration_state_.on_last_iteration();
    }

    /// Advance to the next iteration if the current one is over.
    /// Returns true if the animation iterated.
    bool iterate_if_necessary(double time);

    /// Progress through the current iteration (0.0 to 1.0).
    /// Returns < 1.0 if a non-integral iteration count makes the final
    /// iteration shorter.
    double current_iteration_end_progress() const {
        return iteration_state_.remaining_progress();
    }

    /// Duration of the current iteration (may be shorter than full duration).
    double current_iteration_duration() const {
        return current_iteration_end_progress() * duration_;
    }

    // --- Lifecycle ---

    /// Whether this animation has ended at the given time.
    /// Does not account for cancellation.
    bool has_ended(double time) const;

    /// Whether this animation would be canceled by a new computed style.
    bool is_cancelled_in_new_style(const class ComputedValues& new_style) const;

    /// Update internal state from another animation (for re-submission after
    /// style changes). Preserves start time but adopts new configuration.
    void update_from_other(const Animation& other, double now);

    // --- Value Computation ---

    /// Fill an AnimationValueMap with computed values at the given time.
    void get_property_declaration_at_time(double now, AnimationValueMap& map) const;

    // --- Serialization ---

    std::string ToString() const;
    static std::optional<Animation> FromString(const std::string& s);

    bool operator==(const Animation& other) const;
    bool operator!=(const Animation& other) const { return !(*this == other); }

private:
    /// Advance to the next iteration, handling direction alternation.
    void iterate();

    std::string name_;
    std::vector<ComputedKeyframe> computed_steps_;
    double started_at_;
    double duration_;
    double delay_;
    AnimationFillMode fill_mode_;
    AnimationDirection direction_;
    AnimationDirection current_direction_;
    AnimationState state_;
    KeyframesIterationState iteration_state_;
    bool is_new_;

    // Optional: a reference to the cascade style used to generate keyframes.
    // Stored as a pointer; may be nullptr if not available.
    // Note: In the Rust code this is an Arc<ComputedValues>, here we use a
    // shared_ptr or raw pointer depending on ownership semantics.
    std::shared_ptr<const class ComputedValues> cascade_style_;
};

// =============================================================================
// Transition
// =============================================================================

/// A CSS Transition instance, representing the smooth interpolation of a
/// single property value change.
class Transition {
public:
    // --- Construction ---

    Transition();
    Transition(double start_time, double delay,
               PropertyAnimation property_animation,
               AnimationState state,
               AnimationValue reversing_adjusted_start_value,
               double reversing_shortening_factor);

    // --- Accessors ---

    double start_time() const { return start_time_; }
    double delay() const { return delay_; }
    const PropertyAnimation& property_animation() const { return property_animation_; }
    PropertyAnimation& property_animation() { return property_animation_; }
    AnimationState state() const { return state_; }
    bool is_new() const { return is_new_; }

    const AnimationValue& reversing_adjusted_start_value() const {
        return reversing_adjusted_start_value_;
    }
    double reversing_shortening_factor() const { return reversing_shortening_factor_; }

    void set_start_time(double t) { start_time_ = t; }
    void set_state(const AnimationState& s) { state_ = s; }
    void set_is_new(bool n) { is_new_ = n; }

    // --- Lifecycle ---

    /// Whether this transition has ended at the given time.
    bool has_ended(double time) const;

    /// Handle reversed transition logic when replacing a running transition.
    /// Per: https://drafts.csswg.org/css-transitions/#starting
    void update_for_possibly_reversed_transition(
        const Transition& replaced_transition, double delay, double now);

    // --- Value Computation ---

    /// Compute the animated value at the given time.
    AnimationValue calculate_value(double time) const;

    // --- Serialization ---

    std::string ToString() const;
    static std::optional<Transition> FromString(const std::string& s);

    bool operator==(const Transition& other) const;
    bool operator!=(const Transition& other) const { return !(*this == other); }

private:
    double start_time_;
    double delay_;
    PropertyAnimation property_animation_;
    AnimationState state_;
    bool is_new_;

    /// Used for reversed transition calculations.
    AnimationValue reversing_adjusted_start_value_;

    /// The reversing shortening factor (0.0 to 1.0).
    double reversing_shortening_factor_;
};

// =============================================================================
// Element Animation Set
// =============================================================================

/// Holds the animation state for a particular element.
///
/// Each element (or pseudo-element) has one ElementAnimationSet that tracks
/// all active animations and transitions, along with a dirty flag for
/// signaling when changes need to be propagated to the script thread.
class ElementAnimationSet {
public:
    // --- Construction ---

    ElementAnimationSet();
    ~ElementAnimationSet();

    ElementAnimationSet(const ElementAnimationSet&) = default;
    ElementAnimationSet& operator=(const ElementAnimationSet&) = default;
    ElementAnimationSet(ElementAnimationSet&&) noexcept = default;
    ElementAnimationSet& operator=(ElementAnimationSet&&) noexcept = default;

    // --- Accessors ---

    const std::vector<Animation>& animations() const { return animations_; }
    std::vector<Animation>& animations() { return animations_; }
    const std::vector<Transition>& transitions() const { return transitions_; }
    std::vector<Transition>& transitions() { return transitions_; }
    bool dirty() const { return dirty_; }
    void set_dirty(bool d) { dirty_ = d; }

    // --- Queries ---

    /// Whether this set is empty (no animations or transitions in any state).
    bool is_empty() const;

    /// Whether we need animation ticks (any pending or running items).
    bool needs_animation_ticks() const;

    /// Number of running animations and transitions.
    size_t running_animation_and_transition_count() const;

    /// Whether there are any active (non-canceled) animations.
    bool has_active_animation() const;

    /// Whether there are any active (non-canceled) transitions.
    bool has_active_transition() const;

    // --- Lifecycle Management ---

    /// Cancel all animations and active transitions.
    void cancel_all_animations();

    /// Cancel only active (non-finished) transitions.
    void cancel_active_transitions();

    /// Remove all canceled animations and transitions from the set.
    void clear_canceled_animations();

    // --- Style Application (Servo path) ---

    /// Apply all active animation and transition values to a style.
    void apply_active_animations(const class SharedStyleContext& context,
                                  class ComputedValues& style);

    // --- Update from New Style ---

    /// Update animations based on a new computed style.
    /// Cancels animations not present in the new style and starts new ones.
    template <typename Element>
    void update_animations_for_new_style(
        Element& element,
        const class SharedStyleContext& context,
        const class ComputedValues& new_style,
        class StyleResolverForElement<Element>& resolver);

    /// Update transitions based on a new computed style.
    /// Cancels transitions whose properties no longer transition and
    /// starts new ones where applicable.
    void update_transitions_for_new_style(
        bool might_need_transitions_update,
        const class SharedStyleContext& context,
        const std::optional<std::shared_ptr<const ComputedValues>>& old_style,
        const ComputedValues& after_change_style);

    // --- Serialization ---

    std::string ToString() const;
    static ElementAnimationSet FromString(const std::string& s);

private:
    /// Attempt to start a transition for a single property.
    void start_transition_if_applicable(
        const class SharedStyleContext& context,
        const PropertyDeclarationId& property_declaration_id,
        size_t index,
        const ComputedValues& old_style,
        const ComputedValues& new_style);

    /// Get the value map for active animations at the given time.
    std::optional<AnimationValueMap> get_value_map_for_active_animations(
        double now) const;

    /// Get the value map for active transitions at the given time.
    std::optional<AnimationValueMap> get_value_map_for_active_transitions(
        double now) const;

    std::vector<Animation> animations_;
    std::vector<Transition> transitions_;
    bool dirty_;
};

// =============================================================================
// Free Functions
// =============================================================================

/// Start new CSS animations for an element if the new style specifies them.
template <typename Element>
void maybe_start_animations(
    Element& element,
    const class SharedStyleContext& context,
    const ComputedValues& new_style,
    ElementAnimationSet& animation_set,
    class StyleResolverForElement<Element>& resolver);

/// Start new CSS transitions based on style changes.
/// Returns the set of property IDs that are now transitioning.
std::vector<PropertyDeclarationId> start_transitions_if_applicable(
    const class SharedStyleContext& context,
    const ComputedValues& old_style,
    const ComputedValues& new_style,
    ElementAnimationSet& animation_set);

/// Generate computed keyframes for a @keyframes animation.
template <typename Element>
std::vector<ComputedKeyframe> generate_computed_keyframes(
    Element& element,
    const struct KeyframesAnimation& animation,
    const class SharedStyleContext& context,
    std::shared_ptr<const ComputedValues> base_style,
    const TimingFunction& default_timing_function,
    class StyleResolverForElement<Element>& resolver);

// =============================================================================
// Debug / Test Utilities
// =============================================================================

/// Dump the state of an Animation to an output stream.
std::ostream& operator<<(std::ostream& os, const Animation& anim);

/// Dump the state of a Transition to an output stream.
std::ostream& operator<<(std::ostream& os, const Transition& trans);

/// Dump the state of an ElementAnimationSet to an output stream.
std::ostream& operator<<(std::ostream& os, const ElementAnimationSet& set);

/// Validate that an animation's computed steps are consistent.
bool validate_animation(const Animation& anim);

/// Count the total number of animation values across all keyframes.
size_t count_animation_values(const Animation& anim);

}  // namespace animation
}  // namespace style
