/* MPL 2.0 */
//! Generic CSS basic shapes: circle(), ellipse(), inset(), polygon(), path().
//! Corresponds to values/generics/basic_shape.rs (1081 lines)
#pragma once
#include <string>
#include <vector>
#include <variant>
#include <optional>
#include "style/values/specified/length.hpp"

namespace style { namespace values { namespace generics { namespace basic_shape {

using specified::LengthPercentage;
using specified::NonNegativeLengthPercentage;

enum class ShapeType : uint8_t { Circle, Ellipse, Inset, Polygon, Path, PathFill };

// Circle
struct Circle {
    NonNegativeLengthPercentage radius;
    float center_x = 0.5f;
    float center_y = 0.5f;
    Circle() : radius(NonNegativeLengthPercentage::px(0)) {}
};

// Ellipse
struct Ellipse {
    NonNegativeLengthPercentage radius_x;
    NonNegativeLengthPercentage radius_y;
    float center_x = 0.5f;
    float center_y = 0.5f;
    Ellipse() : radius_x(NonNegativeLengthPercentage::px(0)), radius_y(NonNegativeLengthPercentage::px(0)) {}
};

// Inset
struct InsetRect {
    LengthPercentage top, right, bottom, left;
    NonNegativeLengthPercentage border_radius_top_left;
    NonNegativeLengthPercentage border_radius_top_right;
    NonNegativeLengthPercentage border_radius_bottom_right;
    NonNegativeLengthPercentage border_radius_bottom_left;
};

// Polygon
struct Polygon {
    enum FillRule : uint8_t { Nonzero, Evenodd };
    FillRule fill_rule = Nonzero;
    std::vector<std::pair<float,float>> vertices;  // percentage or length pairs
};

// Path
struct PathCommand {
    enum Type : uint8_t { MoveTo, LineTo, CurveTo, QuadTo, Arc, Close };
    Type type = MoveTo;
    std::vector<float> coords;
};
struct Path {
    std::string fill_rule = "nonzero";
    std::vector<PathCommand> commands;
};

// Generic basic shape (template over reference box)
template <typename RefBox>
struct GenericBasicShape {
    ShapeType type = ShapeType::Circle;
    Circle circle;
    Ellipse ellipse;
    InsetRect inset;
    Polygon polygon;
    Path path;
    std::optional<RefBox> reference_box;

    GenericBasicShape() = default;
    static GenericBasicShape circle_shape(const Circle& c) {
        GenericBasicShape s; s.type=ShapeType::Circle; s.circle=c; return s;
    }
    static GenericBasicShape ellipse_shape(const Ellipse& e) {
        GenericBasicShape s; s.type=ShapeType::Ellipse; s.ellipse=e; return s;
    }
    static GenericBasicShape inset_shape(const InsetRect& r) {
        GenericBasicShape s; s.type=ShapeType::Inset; s.inset=r; return s;
    }
    static GenericBasicShape polygon_shape(const Polygon& p) {
        GenericBasicShape s; s.type=ShapeType::Polygon; s.polygon=p; return s;
    }
};

// ─── Shape radius (for shape-outside) ───
struct ShapeRadius {
    enum Type : uint8_t { ClosestSide, FarthestSide, Length };
    Type type = ClosestSide;
    NonNegativeLengthPercentage length;
};

}}}} // namespace
