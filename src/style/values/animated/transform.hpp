/* MPL 2.0 */
//! CSS transform animation interpolation.
//! Corresponds to values/animated/transform.rs (1667 lines)
#pragma once
#include <array>
#include <vector>
#include <cmath>
#include <optional>
#include "style/values/computed/types.hpp"

namespace style { namespace values { namespace animated {

using computed::ComputedTransformOp;

/// Interpolate two transform operation lists.
/// Each list may have different numbers/orders of operations.
/// We decompose to matrix, interpolate, and recompose.
std::vector<ComputedTransformOp> interpolate_transform(
    const std::vector<ComputedTransformOp>& from,
    const std::vector<ComputedTransformOp>& to,
    float progress);

/// Decompose a 4x4 matrix into translate, scale, skew, perspective, quaternion.
struct DecomposedMatrix {
    std::array<float, 3> translate = {0,0,0};
    std::array<float, 3> scale = {1,1,1};
    std::array<float, 3> skew = {0,0,0};
    std::array<float, 4> perspective = {0,0,0,1};
    std::array<float, 4> quaternion = {0,0,0,1};

    static DecomposedMatrix identity();
    DecomposedMatrix interpolate(const DecomposedMatrix& other, float t) const;
    std::array<float, 16> recompose() const;
};

DecomposedMatrix decompose_matrix(const std::array<float, 16>& m);
std::array<float, 16> multiply_matrices(const std::array<float, 16>& a, const std::array<float, 16>& b);

// ─── 2D Transform interpolation ───
ComputedTransformOp interpolate_translate(const ComputedTransformOp& from, const ComputedTransformOp& to, float t);
ComputedTransformOp interpolate_scale(const ComputedTransformOp& from, const ComputedTransformOp& to, float t);
ComputedTransformOp interpolate_rotate(const ComputedTransformOp& from, const ComputedTransformOp& to, float t);

} // namespace animated
} // namespace values
} // namespace style
