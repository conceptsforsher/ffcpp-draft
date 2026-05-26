/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

//! Color conversion algorithms from CSS Color Level 4.
//! https://drafts.csswg.org/css-color-4/#color-conversion-code
//!
//! Corresponds to servo/components/style/color/convert.rs (914 lines)
//! Translation: Rust → C++

#pragma once

#include "style/color/types.hpp"
#include <cmath>

namespace style {
namespace color {

// ─────────────────────────────────────────────────────────────
// Hue normalization
// ─────────────────────────────────────────────────────────────

/// Normalize hue into [0, 360) range.
/// Returns `hue - 360.0 * floor(hue / 360.0)`
inline float normalize_hue(float hue) noexcept {
    return hue - 360.0f * std::floor(hue / 360.0f);
}

/// Normalize hue in degrees for a given range.
inline float normalize_hue_radians(float hue_rad) noexcept {
    constexpr float TWO_PI = 2.0f * 3.141592653589793f;
    return hue_rad - TWO_PI * std::floor(hue_rad / TWO_PI);
}

// ─────────────────────────────────────────────────────────────
// RGB ↔ HSL Conversion
// ─────────────────────────────────────────────────────────────

/// Calculate the hue from RGB components and return it along with
/// the min and max RGB values.
struct HueMinMax {
    float hue;
    float min_val;
    float max_val;
};

inline HueMinMax rgb_to_hue_min_max(float red, float green, float blue) noexcept {
    float max_val = std::max({red, green, blue});
    float min_val = std::min({red, green, blue});
    float delta = max_val - min_val;

    float hue = 0.0f;
    if (delta != 0.0f) {
        if (max_val == red) {
            hue = (green - blue) / delta + (green < blue ? 6.0f : 0.0f);
        } else if (max_val == green) {
            hue = (blue - red) / delta + 2.0f;
        } else {
            hue = (red - green) / delta + 4.0f;
        }
        hue *= 60.0f;
    }

    return {hue, min_val, max_val};
}

/// Convert sRGB (linear or gamma) to HSL.
inline HSLColor rgb_to_hsl(float red, float green, float blue, float alpha = 1.0f) noexcept {
    auto [hue, min_val, max_val] = rgb_to_hue_min_max(red, green, blue);
    float lightness = (min_val + max_val) / 2.0f;
    float saturation = 0.0f;

    if (min_val != max_val) {
        if (lightness <= 0.5f) {
            saturation = (max_val - min_val) / (max_val + min_val);
        } else {
            saturation = (max_val - min_val) / (2.0f - max_val - min_val);
        }
    }

    return {hue, saturation, lightness, alpha};
}

// ─────────────────────────────────────────────────────────────
// sRGB ↔ Display P3 Conversion
// ─────────────────────────────────────────────────────────────

/// Convert a color from sRGB-linear to Display P3-linear.
/// Matrix from CSS Color 4 spec.
inline ColorComponents srgb_linear_to_display_p3(ColorComponents srgb) noexcept {
    return {
        0.82246196871f * srgb.c0 + 0.17753803129f * srgb.c1 + 0.0f               * srgb.c2,
        0.03319419894f * srgb.c0 + 0.96680580106f * srgb.c1 + 0.0f               * srgb.c2,
        0.01708263023f * srgb.c0 + 0.07239744376f * srgb.c1 + 0.91051992601f     * srgb.c2,
    };
}

/// Convert a color from Display P3-linear to sRGB-linear.
inline ColorComponents display_p3_to_srgb_linear(ColorComponents p3) noexcept {
    return {
         1.22494017532f * p3.c0 - 0.22494017528f * p3.c1 + 0.0f              * p3.c2,
        -0.04205695459f * p3.c0 + 1.04205695460f * p3.c1 + 0.0f              * p3.c2,
        -0.01963755464f * p3.c0 - 0.07863604655f * p3.c1 + 1.09827360119f    * p3.c2,
    };
}

// ─────────────────────────────────────────────────────────────
// sRGB ↔ XYZ-D65 Conversion
// ─────────────────────────────────────────────────────────────

/// Convert linear sRGB to XYZ-D65.
inline ColorComponents srgb_linear_to_xyz_d65(ColorComponents srgb) noexcept {
    return {
        0.4123907992659595f  * srgb.c0 + 0.357584339383878f   * srgb.c1 + 0.1804807884018343f  * srgb.c2,
        0.21263900587151027f * srgb.c0 + 0.715168678767756f   * srgb.c1 + 0.07219231536073371f * srgb.c2,
        0.01933081871559182f * srgb.c0 + 0.11919477979462598f * srgb.c1 + 0.9505321522496607f  * srgb.c2,
    };
}

/// Convert XYZ-D65 to linear sRGB.
inline ColorComponents xyz_d65_to_srgb_linear(ColorComponents xyz) noexcept {
    return {
         3.2409699419045226f  * xyz.c0 - 1.5373831775700939f  * xyz.c1 - 0.4986107602930034f  * xyz.c2,
        -0.9692436362808796f  * xyz.c0 + 1.8759675015077202f  * xyz.c1 + 0.04155505740717559f * xyz.c2,
         0.05563007969699366f * xyz.c0 - 0.2039769609930969f  * xyz.c1 + 1.0569715142428784f  * xyz.c2,
    };
}

// ─────────────────────────────────────────────────────────────
// sRGB ↔ XYZ-D50 Conversion
// ─────────────────────────────────────────────────────────────

/// Bradford chromatic adaptation from D65 to D50.
inline ColorComponents d65_to_d50(ColorComponents xyz_d65) noexcept {
    return {
         1.0479297925449969f  * xyz_d65.c0 + 0.022946870601609652f * xyz_d65.c1 - 0.05019226628920524f * xyz_d65.c2,
         0.02962780877005599f * xyz_d65.c0 + 0.9904344267538799f   * xyz_d65.c1 - 0.017073799063418826f* xyz_d65.c2,
        -0.009243040646204504f* xyz_d65.c0 + 0.015055191490203152f * xyz_d65.c1 + 0.7518742814281371f   * xyz_d65.c2,
    };
}

/// Bradford chromatic adaptation from D50 to D65.
inline ColorComponents d50_to_d65(ColorComponents xyz_d50) noexcept {
    return {
         0.955473421488075f    * xyz_d50.c0 - 0.02309845494876471f * xyz_d50.c1 + 0.0632592438125706f  * xyz_d50.c2,
        -0.0283697093338637f   * xyz_d50.c0 + 1.0099951818181818f  * xyz_d50.c1 + 0.021041441191066258f* xyz_d50.c2,
         0.012314014459982029f * xyz_d50.c0 - 0.02050764929889896f * xyz_d50.c1 + 1.330365926242124f   * xyz_d50.c2,
    };
}

/// Convert linear sRGB to XYZ-D50.
inline ColorComponents srgb_linear_to_xyz_d50(ColorComponents srgb) noexcept {
    return d65_to_d50(srgb_linear_to_xyz_d65(srgb));
}

/// Convert XYZ-D50 to linear sRGB.
inline ColorComponents xyz_d50_to_srgb_linear(ColorComponents xyz) noexcept {
    return xyz_d65_to_srgb_linear(d50_to_d65(xyz));
}

// ─────────────────────────────────────────────────────────────
// Lab conversion
// ─────────────────────────────────────────────────────────────

/// Convert from XYZ-D50 to CIE Lab.
inline ColorComponents xyz_d50_to_lab(ColorComponents xyz) noexcept {
    // D50 white point
    constexpr float WHITE_X = 0.96422f;
    constexpr float WHITE_Y = 1.0f;
    constexpr float WHITE_Z = 0.82521f;
    constexpr float KAPPA = 24389.0f / 27.0f;  // 903.2963
    constexpr float EPSILON = 216.0f / 24389.0f; // 0.008856

    auto f = [](float t) -> float {
        if (t > EPSILON) {
            return std::cbrt(t);
        }
        return (KAPPA * t + 16.0f) / 116.0f;
    };

    float fx = f(xyz.c0 / WHITE_X);
    float fy = f(xyz.c1 / WHITE_Y);
    float fz = f(xyz.c2 / WHITE_Z);

    return {
        116.0f * fy - 16.0f,  // L
        500.0f * (fx - fy),    // a
        200.0f * (fy - fz),    // b
    };
}

/// Convert from CIE Lab to XYZ-D50.
inline ColorComponents lab_to_xyz_d50(ColorComponents lab) noexcept {
    constexpr float WHITE_X = 0.96422f;
    constexpr float WHITE_Y = 1.0f;
    constexpr float WHITE_Z = 0.82521f;
    constexpr float KAPPA = 24389.0f / 27.0f;
    constexpr float EPSILON = 216.0f / 24389.0f;

    float fy = (lab.c0 + 16.0f) / 116.0f;
    float fx = lab.c1 / 500.0f + fy;
    float fz = fy - lab.c2 / 200.0f;

    auto finv = [](float t) -> float {
        float t3 = t * t * t;
        if (t3 > EPSILON) return t3;
        return (116.0f * t - 16.0f) / KAPPA;
    };

    return {
        finv(fx) * WHITE_X,
        finv(fy) * WHITE_Y,
        finv(fz) * WHITE_Z,
    };
}

// ─────────────────────────────────────────────────────────────
// Oklab conversion
// ─────────────────────────────────────────────────────────────

/// Convert from linear sRGB to Oklab.
inline ColorComponents srgb_linear_to_oklab(ColorComponents srgb) noexcept {
    // First convert to LMS
    float l = 0.4122214708f * srgb.c0 + 0.5363325363f * srgb.c1 + 0.0514459929f * srgb.c2;
    float m = 0.2119034982f * srgb.c0 + 0.6806995451f * srgb.c1 + 0.1073969566f * srgb.c2;
    float s = 0.0883024619f * srgb.c0 + 0.2817188376f * srgb.c1 + 0.6299787005f * srgb.c2;

    // Nonlinear transform (cube root)
    float l_ = std::cbrt(l);
    float m_ = std::cbrt(m);
    float s_ = std::cbrt(s);

    return {
        0.2104542553f * l_ + 0.7936177850f * m_ - 0.0040720468f * s_,  // L
        1.9779984951f * l_ - 2.4285922050f * m_ + 0.4505937099f * s_,  // a
        0.0259040371f * l_ + 0.7827717662f * m_ - 0.8086757660f * s_,  // b
    };
}

/// Convert from Oklab to linear sRGB.
inline ColorComponents oklab_to_srgb_linear(ColorComponents oklab) noexcept {
    float l_ = oklab.c0 + 0.3963377774f * oklab.c1 + 0.2158037573f * oklab.c2;
    float m_ = oklab.c0 - 0.1055613458f * oklab.c1 - 0.0638541728f * oklab.c2;
    float s_ = oklab.c0 - 0.0894841775f * oklab.c1 - 1.2914855480f * oklab.c2;

    // Inverse nonlinear transform (cube)
    float l = l_ * l_ * l_;
    float m = m_ * m_ * m_;
    float s = s_ * s_ * s_;

    return {
         4.0767416621f * l - 3.3077115913f * m + 0.2309699292f * s,
        -1.2684380046f * l + 2.6097574011f * m - 0.3413193965f * s,
        -0.0041960863f * l - 0.7034186147f * m + 1.7076147010f * s,
    };
}

// ─────────────────────────────────────────────────────────────
// Generic Conversion Orchestrator
// ─────────────────────────────────────────────────────────────

/// Convert color components from one color space to another.
ColorComponents convert_color_components(
    ColorComponents src,
    ColorSpace src_space,
    ColorSpace dst_space
);

} // namespace color
} // namespace style
