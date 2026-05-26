/* MPL 2.0 */
//! Specified CSS image values: url(), gradient(), image(), etc.
//! Corresponds to values/specified/image.rs (1336 lines)
#pragma once
#include <string>
#include <vector>
#include <variant>
#include <optional>
#include "style/color/types.hpp"
#include "style/values/specified/length.hpp"
#include "style/values/specified/position.hpp"

namespace style { namespace values { namespace specified {

using color::RGBAColor;

// ─── Image types ───
enum class ImageTag : uint8_t {
    None, Url, LinearGradient, RadialGradient, ConicGradient,
    RepeatingLinearGradient, RepeatingRadialGradient, RepeatingConicGradient,
    ImageSet, Element, CrossFade, Paint,
};

// ─── Gradient stop ───
struct GradientStop {
    std::optional<float> position;  // percentage 0.0-1.0 or length
    RGBAColor color = RGBAColor::transparent();
    std::optional<float> transition_hint;  // for color interpolation
};

// ─── Gradient direction ───
struct GradientDirection {
    enum Type : uint8_t { Angle, ToTop, ToBottom, ToLeft, ToRight,
        ToTopLeft, ToTopRight, ToBottomLeft, ToBottomRight };
    Type type = ToBottom;
    float angle_degrees = 180.0f;
};

// ─── Gradient size/position ───
enum class GradientShape : uint8_t { Ellipse, Circle };
enum class GradientSize : uint8_t { ClosestSide, FarthestSide, ClosestCorner, FarthestCorner, Explicit };

// ─── Image value ───
struct SpecifiedImage {
    ImageTag tag = ImageTag::None;
    std::string url;
    GradientDirection direction;
    GradientShape shape = GradientShape::Ellipse;
    GradientSize size = GradientSize::FarthestCorner;
    std::vector<GradientStop> stops;
    std::optional<LengthPercentage> gradient_size_x;
    std::optional<LengthPercentage> gradient_size_y;
    std::optional<float> gradient_angle;
    // Position for radial gradients
    float position_x = 0.5f;
    float position_y = 0.5f;
    bool position_is_percent_x = true;
    bool position_is_percent_y = true;
    // ImageSet
    std::vector<std::pair<std::string, float>> image_set_options; // url, resolution
    // Repeating
    bool repeating = false;
    // Paint worklet
    std::string paint_name;

    SpecifiedImage() = default;
    static SpecifiedImage none() { return {}; }
    static SpecifiedImage url_v(const std::string& u) { SpecifiedImage img; img.tag=ImageTag::Url; img.url=u; return img; }

    void to_css(std::ostream& dest) const;
    bool is_none() const { return tag == ImageTag::None; }
};

// ─── Background size ───
struct BackgroundSize {
    enum Type : uint8_t { Auto, Cover, Contain, Explicit };
    Type type = Auto;
    LengthPercentage width;
    LengthPercentage height;
};

}}} // namespace
