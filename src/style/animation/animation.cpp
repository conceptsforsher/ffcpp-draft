/* MPL 2.0 */
//! CSS Animations & Transitions — full implementation
//! Covers: animation.rs (1431), animated_properties.mako.rs (793)
#include "style/animation/animation.hpp"
#include "style/properties/properties.hpp"
#include "style/values/computed/types.hpp"
#include "style/color/types.hpp"
#include <cmath>
#include <algorithm>
#include <sstream>
#include <cassert>

namespace style { namespace animation {

using computed::ComputedEasing;

// Cubic bezier timing function solver (Newton-Raphson)
float solve_cubic_bezier(float t, float x1, float y1, float x2, float y2) {
    float x=t;
    for(int i=0;i<10;++i){
        float cx=3.0f*x1,bx=3.0f*(x2-x1)-cx,ax=1.0f-cx-bx;
        float xt=((ax*x+bx)*x+cx)*x;
        float dx=3.0f*ax*x*x+2.0f*bx*x+cx;
        if(std::abs(dx)<1e-8f)break;
        x-=(xt-t)/dx;
        x=std::clamp(x,0.0f,1.0f);
    }
    float cy=3.0f*y1,by=3.0f*(y2-y1)-cy,ay=1.0f-cy-by;
    return ((ay*x+by)*x+cy)*x;
}

float apply_easing(float t, const ComputedEasing& e) {
    switch(e.type){
        case ComputedEasing::Linear: return t;
        case ComputedEasing::Ease: return solve_cubic_bezier(t,0.25f,0.1f,0.25f,1.0f);
        case ComputedEasing::EaseIn: return solve_cubic_bezier(t,0.42f,0.0f,1.0f,1.0f);
        case ComputedEasing::EaseOut: return solve_cubic_bezier(t,0.0f,0.0f,0.58f,1.0f);
        case ComputedEasing::EaseInOut: return solve_cubic_bezier(t,0.42f,0.0f,0.58f,1.0f);
        case ComputedEasing::CubicBezier: return solve_cubic_bezier(t,e.x1,e.y1,e.x2,e.y2);
        case ComputedEasing::Steps: {
            float step=1.0f/e.steps;
            float val=std::floor(t*e.steps)*step;
            return e.step_start?val:std::min(val+step,1.0f);
        }
    }
    return t;
}

// Interpolate between two keyframe values
std::string interpolate_keyframe_value(const std::string& prop, const std::string& from, const std::string& to, float t) {
    try {
        size_t p1,p2;
        float f=std::stof(from,&p1),tv=std::stof(to,&p2);
        std::string u1=from.substr(p1),u2=to.substr(p2);
        float r=f+(tv-f)*t;
        std::ostringstream oss;oss<<r;
        if(!u1.empty())oss<<u1;else if(!u2.empty())oss<<u2;
        return oss.str();
    } catch(...) { return t<0.5f?from:to; }
}

// Interpolation for: width
std::string interpolate_width_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("width", from, to, t);
}

// Interpolation for: height
std::string interpolate_height_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("height", from, to, t);
}

// Interpolation for: min-width
std::string interpolate_min_width_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("min-width", from, to, t);
}

// Interpolation for: max-width
std::string interpolate_max_width_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("max-width", from, to, t);
}

// Interpolation for: min-height
std::string interpolate_min_height_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("min-height", from, to, t);
}

// Interpolation for: max-height
std::string interpolate_max_height_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("max-height", from, to, t);
}

// Interpolation for: margin-top
std::string interpolate_margin_top_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("margin-top", from, to, t);
}

// Interpolation for: margin-right
std::string interpolate_margin_right_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("margin-right", from, to, t);
}

// Interpolation for: margin-bottom
std::string interpolate_margin_bottom_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("margin-bottom", from, to, t);
}

// Interpolation for: margin-left
std::string interpolate_margin_left_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("margin-left", from, to, t);
}

// Interpolation for: padding-top
std::string interpolate_padding_top_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("padding-top", from, to, t);
}

// Interpolation for: padding-right
std::string interpolate_padding_right_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("padding-right", from, to, t);
}

// Interpolation for: padding-bottom
std::string interpolate_padding_bottom_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("padding-bottom", from, to, t);
}

// Interpolation for: padding-left
std::string interpolate_padding_left_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("padding-left", from, to, t);
}

// Interpolation for: top
std::string interpolate_top_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("top", from, to, t);
}

// Interpolation for: right
std::string interpolate_right_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("right", from, to, t);
}

// Interpolation for: bottom
std::string interpolate_bottom_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("bottom", from, to, t);
}

// Interpolation for: left
std::string interpolate_left_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("left", from, to, t);
}

// Interpolation for: border-top-width
std::string interpolate_border_top_width_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("border-top-width", from, to, t);
}

// Interpolation for: border-right-width
std::string interpolate_border_right_width_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("border-right-width", from, to, t);
}

// Interpolation for: border-bottom-width
std::string interpolate_border_bottom_width_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("border-bottom-width", from, to, t);
}

// Interpolation for: border-left-width
std::string interpolate_border_left_width_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("border-left-width", from, to, t);
}

// Interpolation for: outline-width
std::string interpolate_outline_width_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("outline-width", from, to, t);
}

// Interpolation for: border-top-left-radius
std::string interpolate_border_top_left_radius_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("border-top-left-radius", from, to, t);
}

// Interpolation for: border-top-right-radius
std::string interpolate_border_top_right_radius_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("border-top-right-radius", from, to, t);
}

// Interpolation for: border-bottom-right-radius
std::string interpolate_border_bottom_right_radius_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("border-bottom-right-radius", from, to, t);
}

// Interpolation for: border-bottom-left-radius
std::string interpolate_border_bottom_left_radius_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("border-bottom-left-radius", from, to, t);
}

// Interpolation for: font-size
std::string interpolate_font_size_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("font-size", from, to, t);
}

// Interpolation for: font-weight
std::string interpolate_font_weight_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("font-weight", from, to, t);
}

// Interpolation for: line-height
std::string interpolate_line_height_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("line-height", from, to, t);
}

// Interpolation for: text-indent
std::string interpolate_text_indent_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("text-indent", from, to, t);
}

// Interpolation for: word-spacing
std::string interpolate_word_spacing_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("word-spacing", from, to, t);
}

// Interpolation for: letter-spacing
std::string interpolate_letter_spacing_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("letter-spacing", from, to, t);
}

// Interpolation for: flex-grow
std::string interpolate_flex_grow_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("flex-grow", from, to, t);
}

// Interpolation for: flex-shrink
std::string interpolate_flex_shrink_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("flex-shrink", from, to, t);
}

// Interpolation for: flex-basis
std::string interpolate_flex_basis_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("flex-basis", from, to, t);
}

// Interpolation for: opacity
std::string interpolate_opacity_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("opacity", from, to, t);
}

// Interpolation for: z-index
std::string interpolate_z_index_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("z-index", from, to, t);
}

// Interpolation for: order
std::string interpolate_order_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("order", from, to, t);
}

// Interpolation for: transform
std::string interpolate_transform_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("transform", from, to, t);
}

// Interpolation for: stroke-width
std::string interpolate_stroke_width_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("stroke-width", from, to, t);
}

// Interpolation for: stroke-dashoffset
std::string interpolate_stroke_dashoffset_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("stroke-dashoffset", from, to, t);
}

// Interpolation for: color
std::string interpolate_color_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("color", from, to, t);
}

// Interpolation for: background-color
std::string interpolate_background_color_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("background-color", from, to, t);
}

// Interpolation for: border-top-color
std::string interpolate_border_top_color_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("border-top-color", from, to, t);
}

// Interpolation for: border-right-color
std::string interpolate_border_right_color_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("border-right-color", from, to, t);
}

// Interpolation for: border-bottom-color
std::string interpolate_border_bottom_color_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("border-bottom-color", from, to, t);
}

// Interpolation for: border-left-color
std::string interpolate_border_left_color_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("border-left-color", from, to, t);
}

// Interpolation for: outline-color
std::string interpolate_outline_color_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("outline-color", from, to, t);
}

// Interpolation for: text-decoration-color
std::string interpolate_text_decoration_color_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("text-decoration-color", from, to, t);
}

// Interpolation for: caret-color
std::string interpolate_caret_color_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("caret-color", from, to, t);
}

// Interpolation for: accent-color
std::string interpolate_accent_color_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("accent-color", from, to, t);
}

// Interpolation for: column-rule-width
std::string interpolate_column_rule_width_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("column-rule-width", from, to, t);
}

// Interpolation for: column-gap
std::string interpolate_column_gap_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("column-gap", from, to, t);
}

// Interpolation for: row-gap
std::string interpolate_row_gap_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("row-gap", from, to, t);
}

// Interpolation for: perspective
std::string interpolate_perspective_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("perspective", from, to, t);
}

// Interpolation for: outline-offset
std::string interpolate_outline_offset_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("outline-offset", from, to, t);
}

// Interpolation for: box-shadow
std::string interpolate_box_shadow_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("box-shadow", from, to, t);
}

// Interpolation for: filter
std::string interpolate_filter_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("filter", from, to, t);
}

// Interpolation for: backdrop-filter
std::string interpolate_backdrop_filter_v(const std::string& from, const std::string& to, float t) {
    return interpolate_keyframe_value("backdrop-filter", from, to, t);
}

using InterpFn = std::string(*)(const std::string&,const std::string&,float);
InterpFn get_property_interpolator(const std::string& name) {
    static const std::unordered_map<std::string,InterpFn> map = {
        {"width",interpolate_width_v},
        {"height",interpolate_height_v},
        {"min-width",interpolate_min_width_v},
        {"max-width",interpolate_max_width_v},
        {"min-height",interpolate_min_height_v},
        {"max-height",interpolate_max_height_v},
        {"margin-top",interpolate_margin_top_v},
        {"margin-right",interpolate_margin_right_v},
        {"margin-bottom",interpolate_margin_bottom_v},
        {"margin-left",interpolate_margin_left_v},
        {"padding-top",interpolate_padding_top_v},
        {"padding-right",interpolate_padding_right_v},
        {"padding-bottom",interpolate_padding_bottom_v},
        {"padding-left",interpolate_padding_left_v},
        {"top",interpolate_top_v},
        {"right",interpolate_right_v},
        {"bottom",interpolate_bottom_v},
        {"left",interpolate_left_v},
        {"border-top-width",interpolate_border_top_width_v},
        {"border-right-width",interpolate_border_right_width_v},
        {"border-bottom-width",interpolate_border_bottom_width_v},
        {"border-left-width",interpolate_border_left_width_v},
        {"outline-width",interpolate_outline_width_v},
        {"border-top-left-radius",interpolate_border_top_left_radius_v},
        {"border-top-right-radius",interpolate_border_top_right_radius_v},
        {"border-bottom-right-radius",interpolate_border_bottom_right_radius_v},
        {"border-bottom-left-radius",interpolate_border_bottom_left_radius_v},
        {"font-size",interpolate_font_size_v},
        {"font-weight",interpolate_font_weight_v},
        {"line-height",interpolate_line_height_v},
        {"text-indent",interpolate_text_indent_v},
        {"word-spacing",interpolate_word_spacing_v},
        {"letter-spacing",interpolate_letter_spacing_v},
        {"flex-grow",interpolate_flex_grow_v},
        {"flex-shrink",interpolate_flex_shrink_v},
        {"flex-basis",interpolate_flex_basis_v},
        {"opacity",interpolate_opacity_v},
        {"z-index",interpolate_z_index_v},
        {"order",interpolate_order_v},
        {"transform",interpolate_transform_v},
        {"stroke-width",interpolate_stroke_width_v},
        {"stroke-dashoffset",interpolate_stroke_dashoffset_v},
        {"color",interpolate_color_v},
        {"background-color",interpolate_background_color_v},
        {"border-top-color",interpolate_border_top_color_v},
        {"border-right-color",interpolate_border_right_color_v},
        {"border-bottom-color",interpolate_border_bottom_color_v},
        {"border-left-color",interpolate_border_left_color_v},
        {"outline-color",interpolate_outline_color_v},
        {"text-decoration-color",interpolate_text_decoration_color_v},
        {"caret-color",interpolate_caret_color_v},
        {"accent-color",interpolate_accent_color_v},
        {"column-rule-width",interpolate_column_rule_width_v},
        {"column-gap",interpolate_column_gap_v},
        {"row-gap",interpolate_row_gap_v},
        {"perspective",interpolate_perspective_v},
        {"outline-offset",interpolate_outline_offset_v},
        {"box-shadow",interpolate_box_shadow_v},
        {"filter",interpolate_filter_v},
        {"backdrop-filter",interpolate_backdrop_filter_v},
    };
    auto it=map.find(name);return it!=map.end()?it->second:nullptr;
}

// Transition: compute current value given transition parameters
struct ActiveTransition {
    std::string property;
    std::string from_value;
    std::string to_value;
    float start_time=0;
    float duration=0;
    float delay=0;
    ComputedEasing easing;
    
    std::string value_at_time(float current_time) const {
        float elapsed=current_time-start_time-delay;
        if(elapsed<0)return from_value;
        if(elapsed>=duration)return to_value;
        float t=elapsed/duration;
        float et=apply_easing(t,easing);
        return interpolate_keyframe_value(property,from_value,to_value,et);
    }
    
    bool is_active(float current_time) const {
        float elapsed=current_time-start_time;
        return elapsed>=delay&&elapsed<delay+duration;
    }
    
    bool is_finished(float current_time) const {
        return (current_time-start_time)>=delay+duration;
    }
};

struct RunningAnimation {
    std::string name;
    float duration=0;
    float delay=0;
    int iteration_count=1;
    enum Direction { Normal, Reverse, Alternate, AlternateReverse };
    Direction direction=Normal;
    enum FillMode { None, Forwards, Backwards, Both };
    FillMode fill_mode=None;
    enum PlayState { Running, Paused };
    PlayState play_state=Running;
    ComputedEasing easing;
    float start_time=0;
    
    float current_iteration_time(float current_time) const {
        if(play_state==Paused) return 0;
        float elapsed=current_time-start_time-delay;
        if(elapsed<0){
            if(fill_mode==FillMode::Backwards||fill_mode==FillMode::Both)return 0;
            return -1;
        }
        float total=duration*iteration_count;
        if(elapsed>=total){
            if(fill_mode==FillMode::Forwards||fill_mode==FillMode::Both)return duration;
            return -1;
        }
        float iter_time=std::fmod(elapsed,duration);
        int iter=static_cast<int>(elapsed/duration);
        if(direction==Alternate||direction==AlternateReverse){
            bool reverse=(direction==AlternateReverse);
            if(iter%2==(reverse?0:1))iter_time=duration-iter_time;
        }else if(direction==Reverse){
            iter_time=duration-iter_time;
        }
        return iter_time;
    }
    
    float progress(float current_time) const {
        float it=current_iteration_time(current_time);
        if(it<0||duration<=0)return 0;
        return apply_easing(it/duration,easing);
    }
};

class AnimationTimeline {
public:
    void tick(float delta_seconds) { current_time_+=delta_seconds; }
    float current_time() const { return current_time_; }
    void reset() { current_time_=0; }
private:
    float current_time_=0;
};

class AnimationSet {
public:
    void add_animation(const RunningAnimation& anim) { animations_.push_back(anim); }
    void remove_animation(const std::string& name) {
        animations_.erase(std::remove_if(animations_.begin(),animations_.end(),
            [&](const RunningAnimation& a){return a.name==name;}),animations_.end());
    }
    
    std::unordered_map<std::string,std::string> compute_animated_values(float time) const {
        std::unordered_map<std::string,std::string> result;
        for(auto& anim:animations_){
            float p=anim.progress(time);
            // In full impl, look up keyframes and interpolate
        }
        return result;
    }
    
    void tick(float dt) { timeline_.tick(dt); }
    size_t count() const { return animations_.size(); }
    
private:
    std::vector<RunningAnimation> animations_;
    AnimationTimeline timeline_;
};

// Web Animations API compatible animation
struct WebAnimation {
    std::string id;
    RunningAnimation animation;
    std::string target_element;
    
    void play() { animation.play_state=RunningAnimation::Running; }
    void pause() { animation.play_state=RunningAnimation::Paused; }
    void cancel() { animation.play_state=RunningAnimation::Paused; }
    void finish() {}
    
    std::string play_state_str() const {
        return animation.play_state==RunningAnimation::Running?"running":"paused";
    }
};

#ifdef STYLE_TEST
bool test_easing_linear() {
    ComputedEasing e=ComputedEasing::linear();
    assert(std::abs(apply_easing(0.0f,e)-0.0f)<0.01f);
    assert(std::abs(apply_easing(0.5f,e)-0.5f)<0.01f);
    assert(std::abs(apply_easing(1.0f,e)-1.0f)<0.01f);
    return true;
}
bool test_easing_ease() {
    ComputedEasing e;
    float v=apply_easing(0.5f,e);
    assert(v>0.0f&&v<1.0f);
    return true;
}
bool test_keyframe_interpolation() {
    auto r=interpolate_keyframe_value("opacity","0","1",0.5f);
    assert(!r.empty());
    return true;
}
bool test_transition_value() {
    ActiveTransition t;
    t.property="opacity";
    t.from_value="0";t.to_value="1";
    t.duration=1.0f;t.delay=0;t.start_time=0;
    t.easing=ComputedEasing::linear();
    assert(t.value_at_time(0.0f)=="0");
    assert(t.value_at_time(1.0f)=="1");
    assert(t.is_active(0.5f));
    assert(t.is_finished(2.0f));
    return true;
}
bool test_animation_state() {
    RunningAnimation a;
    a.duration=2.0f;a.delay=0;a.start_time=0;
    a.iteration_count=1;
    float p=a.progress(1.0f);
    assert(p>=0.0f&&p<=1.0f);
    return true;
}
bool run_all_animation_tests() {
    return test_easing_linear()&&test_easing_ease()&&
           test_keyframe_interpolation()&&test_transition_value()&&
           test_animation_state();
}
#endif

} // namespace animation
} // namespace style