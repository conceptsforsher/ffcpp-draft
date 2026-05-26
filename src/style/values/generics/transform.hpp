/* MPL 2.0 */
//! Generic CSS transform operations.
//! Corresponds to values/generics/transform.rs (895 lines)
#pragma once
#include <array>
#include <vector>
#include <string>
#include "style/values/specified/length.hpp"

namespace style { namespace values { namespace generics { namespace transform {

using specified::LengthPercentage;
using specified::Length;

enum class TransformOp : uint8_t {
    Translate, TranslateX, TranslateY, TranslateZ, Translate3D,
    Scale, ScaleX, ScaleY, ScaleZ, Scale3D,
    Rotate, RotateX, RotateY, RotateZ, Rotate3D,
    Skew, SkewX, SkewY,
    Perspective, Matrix, Matrix3D, Interpolated,
};

struct GenericTransformOperation {
    TransformOp op = TransformOp::Matrix;
    float matrix[16] = {1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1};
    float x = 0, y = 0, z = 0, angle = 0;

    static GenericTransformOperation translate(float tx, float ty) {
        GenericTransformOperation t; t.op=TransformOp::Translate; t.x=tx; t.y=ty; return t;
    }
    static GenericTransformOperation scale(float sx, float sy) {
        GenericTransformOperation t; t.op=TransformOp::Scale; t.x=sx; t.y=sy; return t;
    }
    static GenericTransformOperation rotate(float deg) {
        GenericTransformOperation t; t.op=TransformOp::Rotate; t.angle=deg; return t;
    }
    static GenericTransformOperation skew(float ax, float ay) {
        GenericTransformOperation t; t.op=TransformOp::Skew; t.x=ax; t.y=ay; return t;
    }
};

struct GenericTransform {
    std::vector<GenericTransformOperation> operations;
    bool is_none() const { return operations.empty(); }
};

}}}} // namespace
