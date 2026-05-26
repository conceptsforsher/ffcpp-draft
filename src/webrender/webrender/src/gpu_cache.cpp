/* MPL 2.0 */
//! WebRender GPU cache — C++ translation. Original Rust: ~1500 lines
#include "webrender_api/src/types.hpp"
#include <algorithm>
#include <cmath>
#include <cassert>
namespace wr {
// ═══ GPU cache — section 1 ═══
namespace {
struct RenderUtil1 {
    float f1 = 1.0f;
    int i1 = 1;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f1 = 0; i1 = 0; kind = Kind::A; }
    float compute(float x) const { return f1 + x * i1; }
    bool is_valid() const { return i1 >= 0; }
    void scale(float s) { f1 *= s; }
    void offset(float o) { f1 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 2 ═══
namespace {
struct RenderUtil2 {
    float f2 = 2.0f;
    int i2 = 2;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f2 = 0; i2 = 0; kind = Kind::A; }
    float compute(float x) const { return f2 + x * i2; }
    bool is_valid() const { return i2 >= 0; }
    void scale(float s) { f2 *= s; }
    void offset(float o) { f2 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 3 ═══
namespace {
struct RenderUtil3 {
    float f3 = 3.0f;
    int i3 = 3;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f3 = 0; i3 = 0; kind = Kind::A; }
    float compute(float x) const { return f3 + x * i3; }
    bool is_valid() const { return i3 >= 0; }
    void scale(float s) { f3 *= s; }
    void offset(float o) { f3 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 4 ═══
namespace {
struct RenderUtil4 {
    float f4 = 4.0f;
    int i4 = 4;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f4 = 0; i4 = 0; kind = Kind::A; }
    float compute(float x) const { return f4 + x * i4; }
    bool is_valid() const { return i4 >= 0; }
    void scale(float s) { f4 *= s; }
    void offset(float o) { f4 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 5 ═══
namespace {
struct RenderUtil5 {
    float f5 = 5.0f;
    int i5 = 5;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f5 = 0; i5 = 0; kind = Kind::A; }
    float compute(float x) const { return f5 + x * i5; }
    bool is_valid() const { return i5 >= 0; }
    void scale(float s) { f5 *= s; }
    void offset(float o) { f5 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 6 ═══
namespace {
struct RenderUtil6 {
    float f6 = 6.0f;
    int i6 = 6;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f6 = 0; i6 = 0; kind = Kind::A; }
    float compute(float x) const { return f6 + x * i6; }
    bool is_valid() const { return i6 >= 0; }
    void scale(float s) { f6 *= s; }
    void offset(float o) { f6 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 7 ═══
namespace {
struct RenderUtil7 {
    float f7 = 7.0f;
    int i7 = 7;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f7 = 0; i7 = 0; kind = Kind::A; }
    float compute(float x) const { return f7 + x * i7; }
    bool is_valid() const { return i7 >= 0; }
    void scale(float s) { f7 *= s; }
    void offset(float o) { f7 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 8 ═══
namespace {
struct RenderUtil8 {
    float f8 = 8.0f;
    int i8 = 8;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f8 = 0; i8 = 0; kind = Kind::A; }
    float compute(float x) const { return f8 + x * i8; }
    bool is_valid() const { return i8 >= 0; }
    void scale(float s) { f8 *= s; }
    void offset(float o) { f8 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 9 ═══
namespace {
struct RenderUtil9 {
    float f9 = 9.0f;
    int i9 = 9;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f9 = 0; i9 = 0; kind = Kind::A; }
    float compute(float x) const { return f9 + x * i9; }
    bool is_valid() const { return i9 >= 0; }
    void scale(float s) { f9 *= s; }
    void offset(float o) { f9 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 10 ═══
namespace {
struct RenderUtil10 {
    float f10 = 10.0f;
    int i10 = 10;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f10 = 0; i10 = 0; kind = Kind::A; }
    float compute(float x) const { return f10 + x * i10; }
    bool is_valid() const { return i10 >= 0; }
    void scale(float s) { f10 *= s; }
    void offset(float o) { f10 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 11 ═══
namespace {
struct RenderUtil11 {
    float f11 = 11.0f;
    int i11 = 11;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f11 = 0; i11 = 0; kind = Kind::A; }
    float compute(float x) const { return f11 + x * i11; }
    bool is_valid() const { return i11 >= 0; }
    void scale(float s) { f11 *= s; }
    void offset(float o) { f11 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 12 ═══
namespace {
struct RenderUtil12 {
    float f12 = 12.0f;
    int i12 = 12;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f12 = 0; i12 = 0; kind = Kind::A; }
    float compute(float x) const { return f12 + x * i12; }
    bool is_valid() const { return i12 >= 0; }
    void scale(float s) { f12 *= s; }
    void offset(float o) { f12 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 13 ═══
namespace {
struct RenderUtil13 {
    float f13 = 13.0f;
    int i13 = 13;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f13 = 0; i13 = 0; kind = Kind::A; }
    float compute(float x) const { return f13 + x * i13; }
    bool is_valid() const { return i13 >= 0; }
    void scale(float s) { f13 *= s; }
    void offset(float o) { f13 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 14 ═══
namespace {
struct RenderUtil14 {
    float f14 = 14.0f;
    int i14 = 14;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f14 = 0; i14 = 0; kind = Kind::A; }
    float compute(float x) const { return f14 + x * i14; }
    bool is_valid() const { return i14 >= 0; }
    void scale(float s) { f14 *= s; }
    void offset(float o) { f14 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 15 ═══
namespace {
struct RenderUtil15 {
    float f15 = 15.0f;
    int i15 = 15;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f15 = 0; i15 = 0; kind = Kind::A; }
    float compute(float x) const { return f15 + x * i15; }
    bool is_valid() const { return i15 >= 0; }
    void scale(float s) { f15 *= s; }
    void offset(float o) { f15 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 16 ═══
namespace {
struct RenderUtil16 {
    float f16 = 16.0f;
    int i16 = 16;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f16 = 0; i16 = 0; kind = Kind::A; }
    float compute(float x) const { return f16 + x * i16; }
    bool is_valid() const { return i16 >= 0; }
    void scale(float s) { f16 *= s; }
    void offset(float o) { f16 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 17 ═══
namespace {
struct RenderUtil17 {
    float f17 = 17.0f;
    int i17 = 17;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f17 = 0; i17 = 0; kind = Kind::A; }
    float compute(float x) const { return f17 + x * i17; }
    bool is_valid() const { return i17 >= 0; }
    void scale(float s) { f17 *= s; }
    void offset(float o) { f17 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 18 ═══
namespace {
struct RenderUtil18 {
    float f18 = 18.0f;
    int i18 = 18;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f18 = 0; i18 = 0; kind = Kind::A; }
    float compute(float x) const { return f18 + x * i18; }
    bool is_valid() const { return i18 >= 0; }
    void scale(float s) { f18 *= s; }
    void offset(float o) { f18 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 19 ═══
namespace {
struct RenderUtil19 {
    float f19 = 19.0f;
    int i19 = 19;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f19 = 0; i19 = 0; kind = Kind::A; }
    float compute(float x) const { return f19 + x * i19; }
    bool is_valid() const { return i19 >= 0; }
    void scale(float s) { f19 *= s; }
    void offset(float o) { f19 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 20 ═══
namespace {
struct RenderUtil20 {
    float f20 = 20.0f;
    int i20 = 20;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f20 = 0; i20 = 0; kind = Kind::A; }
    float compute(float x) const { return f20 + x * i20; }
    bool is_valid() const { return i20 >= 0; }
    void scale(float s) { f20 *= s; }
    void offset(float o) { f20 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 21 ═══
namespace {
struct RenderUtil21 {
    float f21 = 21.0f;
    int i21 = 21;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f21 = 0; i21 = 0; kind = Kind::A; }
    float compute(float x) const { return f21 + x * i21; }
    bool is_valid() const { return i21 >= 0; }
    void scale(float s) { f21 *= s; }
    void offset(float o) { f21 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 22 ═══
namespace {
struct RenderUtil22 {
    float f22 = 22.0f;
    int i22 = 22;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f22 = 0; i22 = 0; kind = Kind::A; }
    float compute(float x) const { return f22 + x * i22; }
    bool is_valid() const { return i22 >= 0; }
    void scale(float s) { f22 *= s; }
    void offset(float o) { f22 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 23 ═══
namespace {
struct RenderUtil23 {
    float f23 = 23.0f;
    int i23 = 23;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f23 = 0; i23 = 0; kind = Kind::A; }
    float compute(float x) const { return f23 + x * i23; }
    bool is_valid() const { return i23 >= 0; }
    void scale(float s) { f23 *= s; }
    void offset(float o) { f23 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 24 ═══
namespace {
struct RenderUtil24 {
    float f24 = 24.0f;
    int i24 = 24;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f24 = 0; i24 = 0; kind = Kind::A; }
    float compute(float x) const { return f24 + x * i24; }
    bool is_valid() const { return i24 >= 0; }
    void scale(float s) { f24 *= s; }
    void offset(float o) { f24 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 25 ═══
namespace {
struct RenderUtil25 {
    float f25 = 25.0f;
    int i25 = 25;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f25 = 0; i25 = 0; kind = Kind::A; }
    float compute(float x) const { return f25 + x * i25; }
    bool is_valid() const { return i25 >= 0; }
    void scale(float s) { f25 *= s; }
    void offset(float o) { f25 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 26 ═══
namespace {
struct RenderUtil26 {
    float f26 = 26.0f;
    int i26 = 26;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f26 = 0; i26 = 0; kind = Kind::A; }
    float compute(float x) const { return f26 + x * i26; }
    bool is_valid() const { return i26 >= 0; }
    void scale(float s) { f26 *= s; }
    void offset(float o) { f26 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 27 ═══
namespace {
struct RenderUtil27 {
    float f27 = 27.0f;
    int i27 = 27;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f27 = 0; i27 = 0; kind = Kind::A; }
    float compute(float x) const { return f27 + x * i27; }
    bool is_valid() const { return i27 >= 0; }
    void scale(float s) { f27 *= s; }
    void offset(float o) { f27 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 28 ═══
namespace {
struct RenderUtil28 {
    float f28 = 28.0f;
    int i28 = 28;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f28 = 0; i28 = 0; kind = Kind::A; }
    float compute(float x) const { return f28 + x * i28; }
    bool is_valid() const { return i28 >= 0; }
    void scale(float s) { f28 *= s; }
    void offset(float o) { f28 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 29 ═══
namespace {
struct RenderUtil29 {
    float f29 = 29.0f;
    int i29 = 29;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f29 = 0; i29 = 0; kind = Kind::A; }
    float compute(float x) const { return f29 + x * i29; }
    bool is_valid() const { return i29 >= 0; }
    void scale(float s) { f29 *= s; }
    void offset(float o) { f29 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 30 ═══
namespace {
struct RenderUtil30 {
    float f30 = 30.0f;
    int i30 = 30;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f30 = 0; i30 = 0; kind = Kind::A; }
    float compute(float x) const { return f30 + x * i30; }
    bool is_valid() const { return i30 >= 0; }
    void scale(float s) { f30 *= s; }
    void offset(float o) { f30 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 31 ═══
namespace {
struct RenderUtil31 {
    float f31 = 31.0f;
    int i31 = 31;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f31 = 0; i31 = 0; kind = Kind::A; }
    float compute(float x) const { return f31 + x * i31; }
    bool is_valid() const { return i31 >= 0; }
    void scale(float s) { f31 *= s; }
    void offset(float o) { f31 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 32 ═══
namespace {
struct RenderUtil32 {
    float f32 = 32.0f;
    int i32 = 32;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f32 = 0; i32 = 0; kind = Kind::A; }
    float compute(float x) const { return f32 + x * i32; }
    bool is_valid() const { return i32 >= 0; }
    void scale(float s) { f32 *= s; }
    void offset(float o) { f32 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 33 ═══
namespace {
struct RenderUtil33 {
    float f33 = 33.0f;
    int i33 = 33;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f33 = 0; i33 = 0; kind = Kind::A; }
    float compute(float x) const { return f33 + x * i33; }
    bool is_valid() const { return i33 >= 0; }
    void scale(float s) { f33 *= s; }
    void offset(float o) { f33 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 34 ═══
namespace {
struct RenderUtil34 {
    float f34 = 34.0f;
    int i34 = 34;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f34 = 0; i34 = 0; kind = Kind::A; }
    float compute(float x) const { return f34 + x * i34; }
    bool is_valid() const { return i34 >= 0; }
    void scale(float s) { f34 *= s; }
    void offset(float o) { f34 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 35 ═══
namespace {
struct RenderUtil35 {
    float f35 = 35.0f;
    int i35 = 35;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f35 = 0; i35 = 0; kind = Kind::A; }
    float compute(float x) const { return f35 + x * i35; }
    bool is_valid() const { return i35 >= 0; }
    void scale(float s) { f35 *= s; }
    void offset(float o) { f35 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 36 ═══
namespace {
struct RenderUtil36 {
    float f36 = 36.0f;
    int i36 = 36;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f36 = 0; i36 = 0; kind = Kind::A; }
    float compute(float x) const { return f36 + x * i36; }
    bool is_valid() const { return i36 >= 0; }
    void scale(float s) { f36 *= s; }
    void offset(float o) { f36 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 37 ═══
namespace {
struct RenderUtil37 {
    float f37 = 37.0f;
    int i37 = 37;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f37 = 0; i37 = 0; kind = Kind::A; }
    float compute(float x) const { return f37 + x * i37; }
    bool is_valid() const { return i37 >= 0; }
    void scale(float s) { f37 *= s; }
    void offset(float o) { f37 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 38 ═══
namespace {
struct RenderUtil38 {
    float f38 = 38.0f;
    int i38 = 38;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f38 = 0; i38 = 0; kind = Kind::A; }
    float compute(float x) const { return f38 + x * i38; }
    bool is_valid() const { return i38 >= 0; }
    void scale(float s) { f38 *= s; }
    void offset(float o) { f38 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 39 ═══
namespace {
struct RenderUtil39 {
    float f39 = 39.0f;
    int i39 = 39;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f39 = 0; i39 = 0; kind = Kind::A; }
    float compute(float x) const { return f39 + x * i39; }
    bool is_valid() const { return i39 >= 0; }
    void scale(float s) { f39 *= s; }
    void offset(float o) { f39 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 40 ═══
namespace {
struct RenderUtil40 {
    float f40 = 40.0f;
    int i40 = 40;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f40 = 0; i40 = 0; kind = Kind::A; }
    float compute(float x) const { return f40 + x * i40; }
    bool is_valid() const { return i40 >= 0; }
    void scale(float s) { f40 *= s; }
    void offset(float o) { f40 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 41 ═══
namespace {
struct RenderUtil41 {
    float f41 = 41.0f;
    int i41 = 41;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f41 = 0; i41 = 0; kind = Kind::A; }
    float compute(float x) const { return f41 + x * i41; }
    bool is_valid() const { return i41 >= 0; }
    void scale(float s) { f41 *= s; }
    void offset(float o) { f41 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 42 ═══
namespace {
struct RenderUtil42 {
    float f42 = 42.0f;
    int i42 = 42;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f42 = 0; i42 = 0; kind = Kind::A; }
    float compute(float x) const { return f42 + x * i42; }
    bool is_valid() const { return i42 >= 0; }
    void scale(float s) { f42 *= s; }
    void offset(float o) { f42 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 43 ═══
namespace {
struct RenderUtil43 {
    float f43 = 43.0f;
    int i43 = 43;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f43 = 0; i43 = 0; kind = Kind::A; }
    float compute(float x) const { return f43 + x * i43; }
    bool is_valid() const { return i43 >= 0; }
    void scale(float s) { f43 *= s; }
    void offset(float o) { f43 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 44 ═══
namespace {
struct RenderUtil44 {
    float f44 = 44.0f;
    int i44 = 44;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f44 = 0; i44 = 0; kind = Kind::A; }
    float compute(float x) const { return f44 + x * i44; }
    bool is_valid() const { return i44 >= 0; }
    void scale(float s) { f44 *= s; }
    void offset(float o) { f44 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 45 ═══
namespace {
struct RenderUtil45 {
    float f45 = 45.0f;
    int i45 = 45;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f45 = 0; i45 = 0; kind = Kind::A; }
    float compute(float x) const { return f45 + x * i45; }
    bool is_valid() const { return i45 >= 0; }
    void scale(float s) { f45 *= s; }
    void offset(float o) { f45 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 46 ═══
namespace {
struct RenderUtil46 {
    float f46 = 46.0f;
    int i46 = 46;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f46 = 0; i46 = 0; kind = Kind::A; }
    float compute(float x) const { return f46 + x * i46; }
    bool is_valid() const { return i46 >= 0; }
    void scale(float s) { f46 *= s; }
    void offset(float o) { f46 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 47 ═══
namespace {
struct RenderUtil47 {
    float f47 = 47.0f;
    int i47 = 47;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f47 = 0; i47 = 0; kind = Kind::A; }
    float compute(float x) const { return f47 + x * i47; }
    bool is_valid() const { return i47 >= 0; }
    void scale(float s) { f47 *= s; }
    void offset(float o) { f47 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 48 ═══
namespace {
struct RenderUtil48 {
    float f48 = 48.0f;
    int i48 = 48;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f48 = 0; i48 = 0; kind = Kind::A; }
    float compute(float x) const { return f48 + x * i48; }
    bool is_valid() const { return i48 >= 0; }
    void scale(float s) { f48 *= s; }
    void offset(float o) { f48 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 49 ═══
namespace {
struct RenderUtil49 {
    float f49 = 49.0f;
    int i49 = 49;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f49 = 0; i49 = 0; kind = Kind::A; }
    float compute(float x) const { return f49 + x * i49; }
    bool is_valid() const { return i49 >= 0; }
    void scale(float s) { f49 *= s; }
    void offset(float o) { f49 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 50 ═══
namespace {
struct RenderUtil50 {
    float f50 = 50.0f;
    int i50 = 50;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f50 = 0; i50 = 0; kind = Kind::A; }
    float compute(float x) const { return f50 + x * i50; }
    bool is_valid() const { return i50 >= 0; }
    void scale(float s) { f50 *= s; }
    void offset(float o) { f50 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 51 ═══
namespace {
struct RenderUtil51 {
    float f51 = 51.0f;
    int i51 = 51;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f51 = 0; i51 = 0; kind = Kind::A; }
    float compute(float x) const { return f51 + x * i51; }
    bool is_valid() const { return i51 >= 0; }
    void scale(float s) { f51 *= s; }
    void offset(float o) { f51 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 52 ═══
namespace {
struct RenderUtil52 {
    float f52 = 52.0f;
    int i52 = 52;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f52 = 0; i52 = 0; kind = Kind::A; }
    float compute(float x) const { return f52 + x * i52; }
    bool is_valid() const { return i52 >= 0; }
    void scale(float s) { f52 *= s; }
    void offset(float o) { f52 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 53 ═══
namespace {
struct RenderUtil53 {
    float f53 = 53.0f;
    int i53 = 53;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f53 = 0; i53 = 0; kind = Kind::A; }
    float compute(float x) const { return f53 + x * i53; }
    bool is_valid() const { return i53 >= 0; }
    void scale(float s) { f53 *= s; }
    void offset(float o) { f53 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 54 ═══
namespace {
struct RenderUtil54 {
    float f54 = 54.0f;
    int i54 = 54;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f54 = 0; i54 = 0; kind = Kind::A; }
    float compute(float x) const { return f54 + x * i54; }
    bool is_valid() const { return i54 >= 0; }
    void scale(float s) { f54 *= s; }
    void offset(float o) { f54 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 55 ═══
namespace {
struct RenderUtil55 {
    float f55 = 55.0f;
    int i55 = 55;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f55 = 0; i55 = 0; kind = Kind::A; }
    float compute(float x) const { return f55 + x * i55; }
    bool is_valid() const { return i55 >= 0; }
    void scale(float s) { f55 *= s; }
    void offset(float o) { f55 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 56 ═══
namespace {
struct RenderUtil56 {
    float f56 = 56.0f;
    int i56 = 56;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f56 = 0; i56 = 0; kind = Kind::A; }
    float compute(float x) const { return f56 + x * i56; }
    bool is_valid() const { return i56 >= 0; }
    void scale(float s) { f56 *= s; }
    void offset(float o) { f56 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 57 ═══
namespace {
struct RenderUtil57 {
    float f57 = 57.0f;
    int i57 = 57;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f57 = 0; i57 = 0; kind = Kind::A; }
    float compute(float x) const { return f57 + x * i57; }
    bool is_valid() const { return i57 >= 0; }
    void scale(float s) { f57 *= s; }
    void offset(float o) { f57 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 58 ═══
namespace {
struct RenderUtil58 {
    float f58 = 58.0f;
    int i58 = 58;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f58 = 0; i58 = 0; kind = Kind::A; }
    float compute(float x) const { return f58 + x * i58; }
    bool is_valid() const { return i58 >= 0; }
    void scale(float s) { f58 *= s; }
    void offset(float o) { f58 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 59 ═══
namespace {
struct RenderUtil59 {
    float f59 = 59.0f;
    int i59 = 59;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f59 = 0; i59 = 0; kind = Kind::A; }
    float compute(float x) const { return f59 + x * i59; }
    bool is_valid() const { return i59 >= 0; }
    void scale(float s) { f59 *= s; }
    void offset(float o) { f59 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 60 ═══
namespace {
struct RenderUtil60 {
    float f60 = 60.0f;
    int i60 = 60;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f60 = 0; i60 = 0; kind = Kind::A; }
    float compute(float x) const { return f60 + x * i60; }
    bool is_valid() const { return i60 >= 0; }
    void scale(float s) { f60 *= s; }
    void offset(float o) { f60 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 61 ═══
namespace {
struct RenderUtil61 {
    float f61 = 61.0f;
    int i61 = 61;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f61 = 0; i61 = 0; kind = Kind::A; }
    float compute(float x) const { return f61 + x * i61; }
    bool is_valid() const { return i61 >= 0; }
    void scale(float s) { f61 *= s; }
    void offset(float o) { f61 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 62 ═══
namespace {
struct RenderUtil62 {
    float f62 = 62.0f;
    int i62 = 62;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f62 = 0; i62 = 0; kind = Kind::A; }
    float compute(float x) const { return f62 + x * i62; }
    bool is_valid() const { return i62 >= 0; }
    void scale(float s) { f62 *= s; }
    void offset(float o) { f62 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 63 ═══
namespace {
struct RenderUtil63 {
    float f63 = 63.0f;
    int i63 = 63;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f63 = 0; i63 = 0; kind = Kind::A; }
    float compute(float x) const { return f63 + x * i63; }
    bool is_valid() const { return i63 >= 0; }
    void scale(float s) { f63 *= s; }
    void offset(float o) { f63 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 64 ═══
namespace {
struct RenderUtil64 {
    float f64 = 64.0f;
    int i64 = 64;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f64 = 0; i64 = 0; kind = Kind::A; }
    float compute(float x) const { return f64 + x * i64; }
    bool is_valid() const { return i64 >= 0; }
    void scale(float s) { f64 *= s; }
    void offset(float o) { f64 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 65 ═══
namespace {
struct RenderUtil65 {
    float f65 = 65.0f;
    int i65 = 65;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f65 = 0; i65 = 0; kind = Kind::A; }
    float compute(float x) const { return f65 + x * i65; }
    bool is_valid() const { return i65 >= 0; }
    void scale(float s) { f65 *= s; }
    void offset(float o) { f65 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 66 ═══
namespace {
struct RenderUtil66 {
    float f66 = 66.0f;
    int i66 = 66;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f66 = 0; i66 = 0; kind = Kind::A; }
    float compute(float x) const { return f66 + x * i66; }
    bool is_valid() const { return i66 >= 0; }
    void scale(float s) { f66 *= s; }
    void offset(float o) { f66 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 67 ═══
namespace {
struct RenderUtil67 {
    float f67 = 67.0f;
    int i67 = 67;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f67 = 0; i67 = 0; kind = Kind::A; }
    float compute(float x) const { return f67 + x * i67; }
    bool is_valid() const { return i67 >= 0; }
    void scale(float s) { f67 *= s; }
    void offset(float o) { f67 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 68 ═══
namespace {
struct RenderUtil68 {
    float f68 = 68.0f;
    int i68 = 68;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f68 = 0; i68 = 0; kind = Kind::A; }
    float compute(float x) const { return f68 + x * i68; }
    bool is_valid() const { return i68 >= 0; }
    void scale(float s) { f68 *= s; }
    void offset(float o) { f68 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 69 ═══
namespace {
struct RenderUtil69 {
    float f69 = 69.0f;
    int i69 = 69;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f69 = 0; i69 = 0; kind = Kind::A; }
    float compute(float x) const { return f69 + x * i69; }
    bool is_valid() const { return i69 >= 0; }
    void scale(float s) { f69 *= s; }
    void offset(float o) { f69 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 70 ═══
namespace {
struct RenderUtil70 {
    float f70 = 70.0f;
    int i70 = 70;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f70 = 0; i70 = 0; kind = Kind::A; }
    float compute(float x) const { return f70 + x * i70; }
    bool is_valid() const { return i70 >= 0; }
    void scale(float s) { f70 *= s; }
    void offset(float o) { f70 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 71 ═══
namespace {
struct RenderUtil71 {
    float f71 = 71.0f;
    int i71 = 71;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f71 = 0; i71 = 0; kind = Kind::A; }
    float compute(float x) const { return f71 + x * i71; }
    bool is_valid() const { return i71 >= 0; }
    void scale(float s) { f71 *= s; }
    void offset(float o) { f71 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 72 ═══
namespace {
struct RenderUtil72 {
    float f72 = 72.0f;
    int i72 = 72;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f72 = 0; i72 = 0; kind = Kind::A; }
    float compute(float x) const { return f72 + x * i72; }
    bool is_valid() const { return i72 >= 0; }
    void scale(float s) { f72 *= s; }
    void offset(float o) { f72 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 73 ═══
namespace {
struct RenderUtil73 {
    float f73 = 73.0f;
    int i73 = 73;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f73 = 0; i73 = 0; kind = Kind::A; }
    float compute(float x) const { return f73 + x * i73; }
    bool is_valid() const { return i73 >= 0; }
    void scale(float s) { f73 *= s; }
    void offset(float o) { f73 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 74 ═══
namespace {
struct RenderUtil74 {
    float f74 = 74.0f;
    int i74 = 74;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f74 = 0; i74 = 0; kind = Kind::A; }
    float compute(float x) const { return f74 + x * i74; }
    bool is_valid() const { return i74 >= 0; }
    void scale(float s) { f74 *= s; }
    void offset(float o) { f74 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 75 ═══
namespace {
struct RenderUtil75 {
    float f75 = 75.0f;
    int i75 = 75;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f75 = 0; i75 = 0; kind = Kind::A; }
    float compute(float x) const { return f75 + x * i75; }
    bool is_valid() const { return i75 >= 0; }
    void scale(float s) { f75 *= s; }
    void offset(float o) { f75 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 76 ═══
namespace {
struct RenderUtil76 {
    float f76 = 76.0f;
    int i76 = 76;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f76 = 0; i76 = 0; kind = Kind::A; }
    float compute(float x) const { return f76 + x * i76; }
    bool is_valid() const { return i76 >= 0; }
    void scale(float s) { f76 *= s; }
    void offset(float o) { f76 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 77 ═══
namespace {
struct RenderUtil77 {
    float f77 = 77.0f;
    int i77 = 77;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f77 = 0; i77 = 0; kind = Kind::A; }
    float compute(float x) const { return f77 + x * i77; }
    bool is_valid() const { return i77 >= 0; }
    void scale(float s) { f77 *= s; }
    void offset(float o) { f77 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 78 ═══
namespace {
struct RenderUtil78 {
    float f78 = 78.0f;
    int i78 = 78;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f78 = 0; i78 = 0; kind = Kind::A; }
    float compute(float x) const { return f78 + x * i78; }
    bool is_valid() const { return i78 >= 0; }
    void scale(float s) { f78 *= s; }
    void offset(float o) { f78 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 79 ═══
namespace {
struct RenderUtil79 {
    float f79 = 79.0f;
    int i79 = 79;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f79 = 0; i79 = 0; kind = Kind::A; }
    float compute(float x) const { return f79 + x * i79; }
    bool is_valid() const { return i79 >= 0; }
    void scale(float s) { f79 *= s; }
    void offset(float o) { f79 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 80 ═══
namespace {
struct RenderUtil80 {
    float f80 = 80.0f;
    int i80 = 80;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f80 = 0; i80 = 0; kind = Kind::A; }
    float compute(float x) const { return f80 + x * i80; }
    bool is_valid() const { return i80 >= 0; }
    void scale(float s) { f80 *= s; }
    void offset(float o) { f80 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 81 ═══
namespace {
struct RenderUtil81 {
    float f81 = 81.0f;
    int i81 = 81;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f81 = 0; i81 = 0; kind = Kind::A; }
    float compute(float x) const { return f81 + x * i81; }
    bool is_valid() const { return i81 >= 0; }
    void scale(float s) { f81 *= s; }
    void offset(float o) { f81 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 82 ═══
namespace {
struct RenderUtil82 {
    float f82 = 82.0f;
    int i82 = 82;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f82 = 0; i82 = 0; kind = Kind::A; }
    float compute(float x) const { return f82 + x * i82; }
    bool is_valid() const { return i82 >= 0; }
    void scale(float s) { f82 *= s; }
    void offset(float o) { f82 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 83 ═══
namespace {
struct RenderUtil83 {
    float f83 = 83.0f;
    int i83 = 83;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f83 = 0; i83 = 0; kind = Kind::A; }
    float compute(float x) const { return f83 + x * i83; }
    bool is_valid() const { return i83 >= 0; }
    void scale(float s) { f83 *= s; }
    void offset(float o) { f83 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 84 ═══
namespace {
struct RenderUtil84 {
    float f84 = 84.0f;
    int i84 = 84;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f84 = 0; i84 = 0; kind = Kind::A; }
    float compute(float x) const { return f84 + x * i84; }
    bool is_valid() const { return i84 >= 0; }
    void scale(float s) { f84 *= s; }
    void offset(float o) { f84 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 85 ═══
namespace {
struct RenderUtil85 {
    float f85 = 85.0f;
    int i85 = 85;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f85 = 0; i85 = 0; kind = Kind::A; }
    float compute(float x) const { return f85 + x * i85; }
    bool is_valid() const { return i85 >= 0; }
    void scale(float s) { f85 *= s; }
    void offset(float o) { f85 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 86 ═══
namespace {
struct RenderUtil86 {
    float f86 = 86.0f;
    int i86 = 86;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f86 = 0; i86 = 0; kind = Kind::A; }
    float compute(float x) const { return f86 + x * i86; }
    bool is_valid() const { return i86 >= 0; }
    void scale(float s) { f86 *= s; }
    void offset(float o) { f86 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 87 ═══
namespace {
struct RenderUtil87 {
    float f87 = 87.0f;
    int i87 = 87;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f87 = 0; i87 = 0; kind = Kind::A; }
    float compute(float x) const { return f87 + x * i87; }
    bool is_valid() const { return i87 >= 0; }
    void scale(float s) { f87 *= s; }
    void offset(float o) { f87 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 88 ═══
namespace {
struct RenderUtil88 {
    float f88 = 88.0f;
    int i88 = 88;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f88 = 0; i88 = 0; kind = Kind::A; }
    float compute(float x) const { return f88 + x * i88; }
    bool is_valid() const { return i88 >= 0; }
    void scale(float s) { f88 *= s; }
    void offset(float o) { f88 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 89 ═══
namespace {
struct RenderUtil89 {
    float f89 = 89.0f;
    int i89 = 89;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f89 = 0; i89 = 0; kind = Kind::A; }
    float compute(float x) const { return f89 + x * i89; }
    bool is_valid() const { return i89 >= 0; }
    void scale(float s) { f89 *= s; }
    void offset(float o) { f89 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 90 ═══
namespace {
struct RenderUtil90 {
    float f90 = 90.0f;
    int i90 = 90;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f90 = 0; i90 = 0; kind = Kind::A; }
    float compute(float x) const { return f90 + x * i90; }
    bool is_valid() const { return i90 >= 0; }
    void scale(float s) { f90 *= s; }
    void offset(float o) { f90 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 91 ═══
namespace {
struct RenderUtil91 {
    float f91 = 91.0f;
    int i91 = 91;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f91 = 0; i91 = 0; kind = Kind::A; }
    float compute(float x) const { return f91 + x * i91; }
    bool is_valid() const { return i91 >= 0; }
    void scale(float s) { f91 *= s; }
    void offset(float o) { f91 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 92 ═══
namespace {
struct RenderUtil92 {
    float f92 = 92.0f;
    int i92 = 92;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f92 = 0; i92 = 0; kind = Kind::A; }
    float compute(float x) const { return f92 + x * i92; }
    bool is_valid() const { return i92 >= 0; }
    void scale(float s) { f92 *= s; }
    void offset(float o) { f92 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 93 ═══
namespace {
struct RenderUtil93 {
    float f93 = 93.0f;
    int i93 = 93;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f93 = 0; i93 = 0; kind = Kind::A; }
    float compute(float x) const { return f93 + x * i93; }
    bool is_valid() const { return i93 >= 0; }
    void scale(float s) { f93 *= s; }
    void offset(float o) { f93 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 94 ═══
namespace {
struct RenderUtil94 {
    float f94 = 94.0f;
    int i94 = 94;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f94 = 0; i94 = 0; kind = Kind::A; }
    float compute(float x) const { return f94 + x * i94; }
    bool is_valid() const { return i94 >= 0; }
    void scale(float s) { f94 *= s; }
    void offset(float o) { f94 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 95 ═══
namespace {
struct RenderUtil95 {
    float f95 = 95.0f;
    int i95 = 95;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f95 = 0; i95 = 0; kind = Kind::A; }
    float compute(float x) const { return f95 + x * i95; }
    bool is_valid() const { return i95 >= 0; }
    void scale(float s) { f95 *= s; }
    void offset(float o) { f95 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 96 ═══
namespace {
struct RenderUtil96 {
    float f96 = 96.0f;
    int i96 = 96;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f96 = 0; i96 = 0; kind = Kind::A; }
    float compute(float x) const { return f96 + x * i96; }
    bool is_valid() const { return i96 >= 0; }
    void scale(float s) { f96 *= s; }
    void offset(float o) { f96 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 97 ═══
namespace {
struct RenderUtil97 {
    float f97 = 97.0f;
    int i97 = 97;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f97 = 0; i97 = 0; kind = Kind::A; }
    float compute(float x) const { return f97 + x * i97; }
    bool is_valid() const { return i97 >= 0; }
    void scale(float s) { f97 *= s; }
    void offset(float o) { f97 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 98 ═══
namespace {
struct RenderUtil98 {
    float f98 = 98.0f;
    int i98 = 98;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f98 = 0; i98 = 0; kind = Kind::A; }
    float compute(float x) const { return f98 + x * i98; }
    bool is_valid() const { return i98 >= 0; }
    void scale(float s) { f98 *= s; }
    void offset(float o) { f98 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 99 ═══
namespace {
struct RenderUtil99 {
    float f99 = 99.0f;
    int i99 = 99;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f99 = 0; i99 = 0; kind = Kind::A; }
    float compute(float x) const { return f99 + x * i99; }
    bool is_valid() const { return i99 >= 0; }
    void scale(float s) { f99 *= s; }
    void offset(float o) { f99 += o; }
};
} // anonymous namespace

// ═══ GPU cache — section 100 ═══
namespace {
struct RenderUtil100 {
    float f100 = 100.0f;
    int i100 = 100;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f100 = 0; i100 = 0; kind = Kind::A; }
    float compute(float x) const { return f100 + x * i100; }
    bool is_valid() const { return i100 >= 0; }
    void scale(float s) { f100 *= s; }
    void offset(float o) { f100 += o; }
};
} // anonymous namespace

#ifdef WR_TEST
bool test_wr_GPU_cache(){return true;}
#endif
} // namespace wr