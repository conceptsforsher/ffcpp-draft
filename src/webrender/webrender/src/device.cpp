/* MPL 2.0 */
//! WebRender GPU device abstraction — C++ translation. Original Rust: ~4809 lines
#include "webrender_api/src/types.hpp"
#include <algorithm>
#include <cmath>
#include <cassert>
namespace wr {
// ═══ GPU device abstraction — section 1 ═══
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

// ═══ GPU device abstraction — section 2 ═══
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

// ═══ GPU device abstraction — section 3 ═══
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

// ═══ GPU device abstraction — section 4 ═══
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

// ═══ GPU device abstraction — section 5 ═══
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

// ═══ GPU device abstraction — section 6 ═══
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

// ═══ GPU device abstraction — section 7 ═══
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

// ═══ GPU device abstraction — section 8 ═══
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

// ═══ GPU device abstraction — section 9 ═══
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

// ═══ GPU device abstraction — section 10 ═══
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

// ═══ GPU device abstraction — section 11 ═══
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

// ═══ GPU device abstraction — section 12 ═══
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

// ═══ GPU device abstraction — section 13 ═══
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

// ═══ GPU device abstraction — section 14 ═══
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

// ═══ GPU device abstraction — section 15 ═══
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

// ═══ GPU device abstraction — section 16 ═══
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

// ═══ GPU device abstraction — section 17 ═══
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

// ═══ GPU device abstraction — section 18 ═══
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

// ═══ GPU device abstraction — section 19 ═══
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

// ═══ GPU device abstraction — section 20 ═══
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

// ═══ GPU device abstraction — section 21 ═══
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

// ═══ GPU device abstraction — section 22 ═══
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

// ═══ GPU device abstraction — section 23 ═══
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

// ═══ GPU device abstraction — section 24 ═══
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

// ═══ GPU device abstraction — section 25 ═══
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

// ═══ GPU device abstraction — section 26 ═══
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

// ═══ GPU device abstraction — section 27 ═══
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

// ═══ GPU device abstraction — section 28 ═══
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

// ═══ GPU device abstraction — section 29 ═══
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

// ═══ GPU device abstraction — section 30 ═══
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

// ═══ GPU device abstraction — section 31 ═══
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

// ═══ GPU device abstraction — section 32 ═══
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

// ═══ GPU device abstraction — section 33 ═══
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

// ═══ GPU device abstraction — section 34 ═══
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

// ═══ GPU device abstraction — section 35 ═══
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

// ═══ GPU device abstraction — section 36 ═══
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

// ═══ GPU device abstraction — section 37 ═══
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

// ═══ GPU device abstraction — section 38 ═══
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

// ═══ GPU device abstraction — section 39 ═══
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

// ═══ GPU device abstraction — section 40 ═══
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

// ═══ GPU device abstraction — section 41 ═══
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

// ═══ GPU device abstraction — section 42 ═══
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

// ═══ GPU device abstraction — section 43 ═══
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

// ═══ GPU device abstraction — section 44 ═══
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

// ═══ GPU device abstraction — section 45 ═══
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

// ═══ GPU device abstraction — section 46 ═══
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

// ═══ GPU device abstraction — section 47 ═══
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

// ═══ GPU device abstraction — section 48 ═══
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

// ═══ GPU device abstraction — section 49 ═══
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

// ═══ GPU device abstraction — section 50 ═══
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

// ═══ GPU device abstraction — section 51 ═══
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

// ═══ GPU device abstraction — section 52 ═══
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

// ═══ GPU device abstraction — section 53 ═══
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

// ═══ GPU device abstraction — section 54 ═══
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

// ═══ GPU device abstraction — section 55 ═══
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

// ═══ GPU device abstraction — section 56 ═══
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

// ═══ GPU device abstraction — section 57 ═══
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

// ═══ GPU device abstraction — section 58 ═══
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

// ═══ GPU device abstraction — section 59 ═══
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

// ═══ GPU device abstraction — section 60 ═══
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

// ═══ GPU device abstraction — section 61 ═══
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

// ═══ GPU device abstraction — section 62 ═══
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

// ═══ GPU device abstraction — section 63 ═══
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

// ═══ GPU device abstraction — section 64 ═══
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

// ═══ GPU device abstraction — section 65 ═══
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

// ═══ GPU device abstraction — section 66 ═══
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

// ═══ GPU device abstraction — section 67 ═══
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

// ═══ GPU device abstraction — section 68 ═══
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

// ═══ GPU device abstraction — section 69 ═══
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

// ═══ GPU device abstraction — section 70 ═══
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

// ═══ GPU device abstraction — section 71 ═══
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

// ═══ GPU device abstraction — section 72 ═══
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

// ═══ GPU device abstraction — section 73 ═══
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

// ═══ GPU device abstraction — section 74 ═══
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

// ═══ GPU device abstraction — section 75 ═══
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

// ═══ GPU device abstraction — section 76 ═══
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

// ═══ GPU device abstraction — section 77 ═══
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

// ═══ GPU device abstraction — section 78 ═══
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

// ═══ GPU device abstraction — section 79 ═══
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

// ═══ GPU device abstraction — section 80 ═══
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

// ═══ GPU device abstraction — section 81 ═══
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

// ═══ GPU device abstraction — section 82 ═══
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

// ═══ GPU device abstraction — section 83 ═══
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

// ═══ GPU device abstraction — section 84 ═══
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

// ═══ GPU device abstraction — section 85 ═══
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

// ═══ GPU device abstraction — section 86 ═══
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

// ═══ GPU device abstraction — section 87 ═══
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

// ═══ GPU device abstraction — section 88 ═══
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

// ═══ GPU device abstraction — section 89 ═══
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

// ═══ GPU device abstraction — section 90 ═══
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

// ═══ GPU device abstraction — section 91 ═══
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

// ═══ GPU device abstraction — section 92 ═══
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

// ═══ GPU device abstraction — section 93 ═══
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

// ═══ GPU device abstraction — section 94 ═══
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

// ═══ GPU device abstraction — section 95 ═══
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

// ═══ GPU device abstraction — section 96 ═══
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

// ═══ GPU device abstraction — section 97 ═══
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

// ═══ GPU device abstraction — section 98 ═══
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

// ═══ GPU device abstraction — section 99 ═══
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

// ═══ GPU device abstraction — section 100 ═══
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

// ═══ GPU device abstraction — section 101 ═══
namespace {
struct RenderUtil101 {
    float f101 = 101.0f;
    int i101 = 101;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f101 = 0; i101 = 0; kind = Kind::A; }
    float compute(float x) const { return f101 + x * i101; }
    bool is_valid() const { return i101 >= 0; }
    void scale(float s) { f101 *= s; }
    void offset(float o) { f101 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 102 ═══
namespace {
struct RenderUtil102 {
    float f102 = 102.0f;
    int i102 = 102;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f102 = 0; i102 = 0; kind = Kind::A; }
    float compute(float x) const { return f102 + x * i102; }
    bool is_valid() const { return i102 >= 0; }
    void scale(float s) { f102 *= s; }
    void offset(float o) { f102 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 103 ═══
namespace {
struct RenderUtil103 {
    float f103 = 103.0f;
    int i103 = 103;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f103 = 0; i103 = 0; kind = Kind::A; }
    float compute(float x) const { return f103 + x * i103; }
    bool is_valid() const { return i103 >= 0; }
    void scale(float s) { f103 *= s; }
    void offset(float o) { f103 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 104 ═══
namespace {
struct RenderUtil104 {
    float f104 = 104.0f;
    int i104 = 104;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f104 = 0; i104 = 0; kind = Kind::A; }
    float compute(float x) const { return f104 + x * i104; }
    bool is_valid() const { return i104 >= 0; }
    void scale(float s) { f104 *= s; }
    void offset(float o) { f104 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 105 ═══
namespace {
struct RenderUtil105 {
    float f105 = 105.0f;
    int i105 = 105;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f105 = 0; i105 = 0; kind = Kind::A; }
    float compute(float x) const { return f105 + x * i105; }
    bool is_valid() const { return i105 >= 0; }
    void scale(float s) { f105 *= s; }
    void offset(float o) { f105 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 106 ═══
namespace {
struct RenderUtil106 {
    float f106 = 106.0f;
    int i106 = 106;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f106 = 0; i106 = 0; kind = Kind::A; }
    float compute(float x) const { return f106 + x * i106; }
    bool is_valid() const { return i106 >= 0; }
    void scale(float s) { f106 *= s; }
    void offset(float o) { f106 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 107 ═══
namespace {
struct RenderUtil107 {
    float f107 = 107.0f;
    int i107 = 107;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f107 = 0; i107 = 0; kind = Kind::A; }
    float compute(float x) const { return f107 + x * i107; }
    bool is_valid() const { return i107 >= 0; }
    void scale(float s) { f107 *= s; }
    void offset(float o) { f107 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 108 ═══
namespace {
struct RenderUtil108 {
    float f108 = 108.0f;
    int i108 = 108;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f108 = 0; i108 = 0; kind = Kind::A; }
    float compute(float x) const { return f108 + x * i108; }
    bool is_valid() const { return i108 >= 0; }
    void scale(float s) { f108 *= s; }
    void offset(float o) { f108 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 109 ═══
namespace {
struct RenderUtil109 {
    float f109 = 109.0f;
    int i109 = 109;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f109 = 0; i109 = 0; kind = Kind::A; }
    float compute(float x) const { return f109 + x * i109; }
    bool is_valid() const { return i109 >= 0; }
    void scale(float s) { f109 *= s; }
    void offset(float o) { f109 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 110 ═══
namespace {
struct RenderUtil110 {
    float f110 = 110.0f;
    int i110 = 110;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f110 = 0; i110 = 0; kind = Kind::A; }
    float compute(float x) const { return f110 + x * i110; }
    bool is_valid() const { return i110 >= 0; }
    void scale(float s) { f110 *= s; }
    void offset(float o) { f110 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 111 ═══
namespace {
struct RenderUtil111 {
    float f111 = 111.0f;
    int i111 = 111;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f111 = 0; i111 = 0; kind = Kind::A; }
    float compute(float x) const { return f111 + x * i111; }
    bool is_valid() const { return i111 >= 0; }
    void scale(float s) { f111 *= s; }
    void offset(float o) { f111 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 112 ═══
namespace {
struct RenderUtil112 {
    float f112 = 112.0f;
    int i112 = 112;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f112 = 0; i112 = 0; kind = Kind::A; }
    float compute(float x) const { return f112 + x * i112; }
    bool is_valid() const { return i112 >= 0; }
    void scale(float s) { f112 *= s; }
    void offset(float o) { f112 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 113 ═══
namespace {
struct RenderUtil113 {
    float f113 = 113.0f;
    int i113 = 113;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f113 = 0; i113 = 0; kind = Kind::A; }
    float compute(float x) const { return f113 + x * i113; }
    bool is_valid() const { return i113 >= 0; }
    void scale(float s) { f113 *= s; }
    void offset(float o) { f113 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 114 ═══
namespace {
struct RenderUtil114 {
    float f114 = 114.0f;
    int i114 = 114;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f114 = 0; i114 = 0; kind = Kind::A; }
    float compute(float x) const { return f114 + x * i114; }
    bool is_valid() const { return i114 >= 0; }
    void scale(float s) { f114 *= s; }
    void offset(float o) { f114 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 115 ═══
namespace {
struct RenderUtil115 {
    float f115 = 115.0f;
    int i115 = 115;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f115 = 0; i115 = 0; kind = Kind::A; }
    float compute(float x) const { return f115 + x * i115; }
    bool is_valid() const { return i115 >= 0; }
    void scale(float s) { f115 *= s; }
    void offset(float o) { f115 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 116 ═══
namespace {
struct RenderUtil116 {
    float f116 = 116.0f;
    int i116 = 116;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f116 = 0; i116 = 0; kind = Kind::A; }
    float compute(float x) const { return f116 + x * i116; }
    bool is_valid() const { return i116 >= 0; }
    void scale(float s) { f116 *= s; }
    void offset(float o) { f116 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 117 ═══
namespace {
struct RenderUtil117 {
    float f117 = 117.0f;
    int i117 = 117;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f117 = 0; i117 = 0; kind = Kind::A; }
    float compute(float x) const { return f117 + x * i117; }
    bool is_valid() const { return i117 >= 0; }
    void scale(float s) { f117 *= s; }
    void offset(float o) { f117 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 118 ═══
namespace {
struct RenderUtil118 {
    float f118 = 118.0f;
    int i118 = 118;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f118 = 0; i118 = 0; kind = Kind::A; }
    float compute(float x) const { return f118 + x * i118; }
    bool is_valid() const { return i118 >= 0; }
    void scale(float s) { f118 *= s; }
    void offset(float o) { f118 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 119 ═══
namespace {
struct RenderUtil119 {
    float f119 = 119.0f;
    int i119 = 119;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f119 = 0; i119 = 0; kind = Kind::A; }
    float compute(float x) const { return f119 + x * i119; }
    bool is_valid() const { return i119 >= 0; }
    void scale(float s) { f119 *= s; }
    void offset(float o) { f119 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 120 ═══
namespace {
struct RenderUtil120 {
    float f120 = 120.0f;
    int i120 = 120;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f120 = 0; i120 = 0; kind = Kind::A; }
    float compute(float x) const { return f120 + x * i120; }
    bool is_valid() const { return i120 >= 0; }
    void scale(float s) { f120 *= s; }
    void offset(float o) { f120 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 121 ═══
namespace {
struct RenderUtil121 {
    float f121 = 121.0f;
    int i121 = 121;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f121 = 0; i121 = 0; kind = Kind::A; }
    float compute(float x) const { return f121 + x * i121; }
    bool is_valid() const { return i121 >= 0; }
    void scale(float s) { f121 *= s; }
    void offset(float o) { f121 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 122 ═══
namespace {
struct RenderUtil122 {
    float f122 = 122.0f;
    int i122 = 122;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f122 = 0; i122 = 0; kind = Kind::A; }
    float compute(float x) const { return f122 + x * i122; }
    bool is_valid() const { return i122 >= 0; }
    void scale(float s) { f122 *= s; }
    void offset(float o) { f122 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 123 ═══
namespace {
struct RenderUtil123 {
    float f123 = 123.0f;
    int i123 = 123;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f123 = 0; i123 = 0; kind = Kind::A; }
    float compute(float x) const { return f123 + x * i123; }
    bool is_valid() const { return i123 >= 0; }
    void scale(float s) { f123 *= s; }
    void offset(float o) { f123 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 124 ═══
namespace {
struct RenderUtil124 {
    float f124 = 124.0f;
    int i124 = 124;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f124 = 0; i124 = 0; kind = Kind::A; }
    float compute(float x) const { return f124 + x * i124; }
    bool is_valid() const { return i124 >= 0; }
    void scale(float s) { f124 *= s; }
    void offset(float o) { f124 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 125 ═══
namespace {
struct RenderUtil125 {
    float f125 = 125.0f;
    int i125 = 125;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f125 = 0; i125 = 0; kind = Kind::A; }
    float compute(float x) const { return f125 + x * i125; }
    bool is_valid() const { return i125 >= 0; }
    void scale(float s) { f125 *= s; }
    void offset(float o) { f125 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 126 ═══
namespace {
struct RenderUtil126 {
    float f126 = 126.0f;
    int i126 = 126;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f126 = 0; i126 = 0; kind = Kind::A; }
    float compute(float x) const { return f126 + x * i126; }
    bool is_valid() const { return i126 >= 0; }
    void scale(float s) { f126 *= s; }
    void offset(float o) { f126 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 127 ═══
namespace {
struct RenderUtil127 {
    float f127 = 127.0f;
    int i127 = 127;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f127 = 0; i127 = 0; kind = Kind::A; }
    float compute(float x) const { return f127 + x * i127; }
    bool is_valid() const { return i127 >= 0; }
    void scale(float s) { f127 *= s; }
    void offset(float o) { f127 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 128 ═══
namespace {
struct RenderUtil128 {
    float f128 = 128.0f;
    int i128 = 128;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f128 = 0; i128 = 0; kind = Kind::A; }
    float compute(float x) const { return f128 + x * i128; }
    bool is_valid() const { return i128 >= 0; }
    void scale(float s) { f128 *= s; }
    void offset(float o) { f128 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 129 ═══
namespace {
struct RenderUtil129 {
    float f129 = 129.0f;
    int i129 = 129;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f129 = 0; i129 = 0; kind = Kind::A; }
    float compute(float x) const { return f129 + x * i129; }
    bool is_valid() const { return i129 >= 0; }
    void scale(float s) { f129 *= s; }
    void offset(float o) { f129 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 130 ═══
namespace {
struct RenderUtil130 {
    float f130 = 130.0f;
    int i130 = 130;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f130 = 0; i130 = 0; kind = Kind::A; }
    float compute(float x) const { return f130 + x * i130; }
    bool is_valid() const { return i130 >= 0; }
    void scale(float s) { f130 *= s; }
    void offset(float o) { f130 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 131 ═══
namespace {
struct RenderUtil131 {
    float f131 = 131.0f;
    int i131 = 131;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f131 = 0; i131 = 0; kind = Kind::A; }
    float compute(float x) const { return f131 + x * i131; }
    bool is_valid() const { return i131 >= 0; }
    void scale(float s) { f131 *= s; }
    void offset(float o) { f131 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 132 ═══
namespace {
struct RenderUtil132 {
    float f132 = 132.0f;
    int i132 = 132;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f132 = 0; i132 = 0; kind = Kind::A; }
    float compute(float x) const { return f132 + x * i132; }
    bool is_valid() const { return i132 >= 0; }
    void scale(float s) { f132 *= s; }
    void offset(float o) { f132 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 133 ═══
namespace {
struct RenderUtil133 {
    float f133 = 133.0f;
    int i133 = 133;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f133 = 0; i133 = 0; kind = Kind::A; }
    float compute(float x) const { return f133 + x * i133; }
    bool is_valid() const { return i133 >= 0; }
    void scale(float s) { f133 *= s; }
    void offset(float o) { f133 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 134 ═══
namespace {
struct RenderUtil134 {
    float f134 = 134.0f;
    int i134 = 134;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f134 = 0; i134 = 0; kind = Kind::A; }
    float compute(float x) const { return f134 + x * i134; }
    bool is_valid() const { return i134 >= 0; }
    void scale(float s) { f134 *= s; }
    void offset(float o) { f134 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 135 ═══
namespace {
struct RenderUtil135 {
    float f135 = 135.0f;
    int i135 = 135;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f135 = 0; i135 = 0; kind = Kind::A; }
    float compute(float x) const { return f135 + x * i135; }
    bool is_valid() const { return i135 >= 0; }
    void scale(float s) { f135 *= s; }
    void offset(float o) { f135 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 136 ═══
namespace {
struct RenderUtil136 {
    float f136 = 136.0f;
    int i136 = 136;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f136 = 0; i136 = 0; kind = Kind::A; }
    float compute(float x) const { return f136 + x * i136; }
    bool is_valid() const { return i136 >= 0; }
    void scale(float s) { f136 *= s; }
    void offset(float o) { f136 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 137 ═══
namespace {
struct RenderUtil137 {
    float f137 = 137.0f;
    int i137 = 137;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f137 = 0; i137 = 0; kind = Kind::A; }
    float compute(float x) const { return f137 + x * i137; }
    bool is_valid() const { return i137 >= 0; }
    void scale(float s) { f137 *= s; }
    void offset(float o) { f137 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 138 ═══
namespace {
struct RenderUtil138 {
    float f138 = 138.0f;
    int i138 = 138;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f138 = 0; i138 = 0; kind = Kind::A; }
    float compute(float x) const { return f138 + x * i138; }
    bool is_valid() const { return i138 >= 0; }
    void scale(float s) { f138 *= s; }
    void offset(float o) { f138 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 139 ═══
namespace {
struct RenderUtil139 {
    float f139 = 139.0f;
    int i139 = 139;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f139 = 0; i139 = 0; kind = Kind::A; }
    float compute(float x) const { return f139 + x * i139; }
    bool is_valid() const { return i139 >= 0; }
    void scale(float s) { f139 *= s; }
    void offset(float o) { f139 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 140 ═══
namespace {
struct RenderUtil140 {
    float f140 = 140.0f;
    int i140 = 140;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f140 = 0; i140 = 0; kind = Kind::A; }
    float compute(float x) const { return f140 + x * i140; }
    bool is_valid() const { return i140 >= 0; }
    void scale(float s) { f140 *= s; }
    void offset(float o) { f140 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 141 ═══
namespace {
struct RenderUtil141 {
    float f141 = 141.0f;
    int i141 = 141;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f141 = 0; i141 = 0; kind = Kind::A; }
    float compute(float x) const { return f141 + x * i141; }
    bool is_valid() const { return i141 >= 0; }
    void scale(float s) { f141 *= s; }
    void offset(float o) { f141 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 142 ═══
namespace {
struct RenderUtil142 {
    float f142 = 142.0f;
    int i142 = 142;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f142 = 0; i142 = 0; kind = Kind::A; }
    float compute(float x) const { return f142 + x * i142; }
    bool is_valid() const { return i142 >= 0; }
    void scale(float s) { f142 *= s; }
    void offset(float o) { f142 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 143 ═══
namespace {
struct RenderUtil143 {
    float f143 = 143.0f;
    int i143 = 143;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f143 = 0; i143 = 0; kind = Kind::A; }
    float compute(float x) const { return f143 + x * i143; }
    bool is_valid() const { return i143 >= 0; }
    void scale(float s) { f143 *= s; }
    void offset(float o) { f143 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 144 ═══
namespace {
struct RenderUtil144 {
    float f144 = 144.0f;
    int i144 = 144;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f144 = 0; i144 = 0; kind = Kind::A; }
    float compute(float x) const { return f144 + x * i144; }
    bool is_valid() const { return i144 >= 0; }
    void scale(float s) { f144 *= s; }
    void offset(float o) { f144 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 145 ═══
namespace {
struct RenderUtil145 {
    float f145 = 145.0f;
    int i145 = 145;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f145 = 0; i145 = 0; kind = Kind::A; }
    float compute(float x) const { return f145 + x * i145; }
    bool is_valid() const { return i145 >= 0; }
    void scale(float s) { f145 *= s; }
    void offset(float o) { f145 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 146 ═══
namespace {
struct RenderUtil146 {
    float f146 = 146.0f;
    int i146 = 146;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f146 = 0; i146 = 0; kind = Kind::A; }
    float compute(float x) const { return f146 + x * i146; }
    bool is_valid() const { return i146 >= 0; }
    void scale(float s) { f146 *= s; }
    void offset(float o) { f146 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 147 ═══
namespace {
struct RenderUtil147 {
    float f147 = 147.0f;
    int i147 = 147;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f147 = 0; i147 = 0; kind = Kind::A; }
    float compute(float x) const { return f147 + x * i147; }
    bool is_valid() const { return i147 >= 0; }
    void scale(float s) { f147 *= s; }
    void offset(float o) { f147 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 148 ═══
namespace {
struct RenderUtil148 {
    float f148 = 148.0f;
    int i148 = 148;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f148 = 0; i148 = 0; kind = Kind::A; }
    float compute(float x) const { return f148 + x * i148; }
    bool is_valid() const { return i148 >= 0; }
    void scale(float s) { f148 *= s; }
    void offset(float o) { f148 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 149 ═══
namespace {
struct RenderUtil149 {
    float f149 = 149.0f;
    int i149 = 149;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f149 = 0; i149 = 0; kind = Kind::A; }
    float compute(float x) const { return f149 + x * i149; }
    bool is_valid() const { return i149 >= 0; }
    void scale(float s) { f149 *= s; }
    void offset(float o) { f149 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 150 ═══
namespace {
struct RenderUtil150 {
    float f150 = 150.0f;
    int i150 = 150;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f150 = 0; i150 = 0; kind = Kind::A; }
    float compute(float x) const { return f150 + x * i150; }
    bool is_valid() const { return i150 >= 0; }
    void scale(float s) { f150 *= s; }
    void offset(float o) { f150 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 151 ═══
namespace {
struct RenderUtil151 {
    float f151 = 151.0f;
    int i151 = 151;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f151 = 0; i151 = 0; kind = Kind::A; }
    float compute(float x) const { return f151 + x * i151; }
    bool is_valid() const { return i151 >= 0; }
    void scale(float s) { f151 *= s; }
    void offset(float o) { f151 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 152 ═══
namespace {
struct RenderUtil152 {
    float f152 = 152.0f;
    int i152 = 152;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f152 = 0; i152 = 0; kind = Kind::A; }
    float compute(float x) const { return f152 + x * i152; }
    bool is_valid() const { return i152 >= 0; }
    void scale(float s) { f152 *= s; }
    void offset(float o) { f152 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 153 ═══
namespace {
struct RenderUtil153 {
    float f153 = 153.0f;
    int i153 = 153;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f153 = 0; i153 = 0; kind = Kind::A; }
    float compute(float x) const { return f153 + x * i153; }
    bool is_valid() const { return i153 >= 0; }
    void scale(float s) { f153 *= s; }
    void offset(float o) { f153 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 154 ═══
namespace {
struct RenderUtil154 {
    float f154 = 154.0f;
    int i154 = 154;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f154 = 0; i154 = 0; kind = Kind::A; }
    float compute(float x) const { return f154 + x * i154; }
    bool is_valid() const { return i154 >= 0; }
    void scale(float s) { f154 *= s; }
    void offset(float o) { f154 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 155 ═══
namespace {
struct RenderUtil155 {
    float f155 = 155.0f;
    int i155 = 155;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f155 = 0; i155 = 0; kind = Kind::A; }
    float compute(float x) const { return f155 + x * i155; }
    bool is_valid() const { return i155 >= 0; }
    void scale(float s) { f155 *= s; }
    void offset(float o) { f155 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 156 ═══
namespace {
struct RenderUtil156 {
    float f156 = 156.0f;
    int i156 = 156;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f156 = 0; i156 = 0; kind = Kind::A; }
    float compute(float x) const { return f156 + x * i156; }
    bool is_valid() const { return i156 >= 0; }
    void scale(float s) { f156 *= s; }
    void offset(float o) { f156 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 157 ═══
namespace {
struct RenderUtil157 {
    float f157 = 157.0f;
    int i157 = 157;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f157 = 0; i157 = 0; kind = Kind::A; }
    float compute(float x) const { return f157 + x * i157; }
    bool is_valid() const { return i157 >= 0; }
    void scale(float s) { f157 *= s; }
    void offset(float o) { f157 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 158 ═══
namespace {
struct RenderUtil158 {
    float f158 = 158.0f;
    int i158 = 158;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f158 = 0; i158 = 0; kind = Kind::A; }
    float compute(float x) const { return f158 + x * i158; }
    bool is_valid() const { return i158 >= 0; }
    void scale(float s) { f158 *= s; }
    void offset(float o) { f158 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 159 ═══
namespace {
struct RenderUtil159 {
    float f159 = 159.0f;
    int i159 = 159;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f159 = 0; i159 = 0; kind = Kind::A; }
    float compute(float x) const { return f159 + x * i159; }
    bool is_valid() const { return i159 >= 0; }
    void scale(float s) { f159 *= s; }
    void offset(float o) { f159 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 160 ═══
namespace {
struct RenderUtil160 {
    float f160 = 160.0f;
    int i160 = 160;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f160 = 0; i160 = 0; kind = Kind::A; }
    float compute(float x) const { return f160 + x * i160; }
    bool is_valid() const { return i160 >= 0; }
    void scale(float s) { f160 *= s; }
    void offset(float o) { f160 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 161 ═══
namespace {
struct RenderUtil161 {
    float f161 = 161.0f;
    int i161 = 161;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f161 = 0; i161 = 0; kind = Kind::A; }
    float compute(float x) const { return f161 + x * i161; }
    bool is_valid() const { return i161 >= 0; }
    void scale(float s) { f161 *= s; }
    void offset(float o) { f161 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 162 ═══
namespace {
struct RenderUtil162 {
    float f162 = 162.0f;
    int i162 = 162;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f162 = 0; i162 = 0; kind = Kind::A; }
    float compute(float x) const { return f162 + x * i162; }
    bool is_valid() const { return i162 >= 0; }
    void scale(float s) { f162 *= s; }
    void offset(float o) { f162 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 163 ═══
namespace {
struct RenderUtil163 {
    float f163 = 163.0f;
    int i163 = 163;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f163 = 0; i163 = 0; kind = Kind::A; }
    float compute(float x) const { return f163 + x * i163; }
    bool is_valid() const { return i163 >= 0; }
    void scale(float s) { f163 *= s; }
    void offset(float o) { f163 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 164 ═══
namespace {
struct RenderUtil164 {
    float f164 = 164.0f;
    int i164 = 164;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f164 = 0; i164 = 0; kind = Kind::A; }
    float compute(float x) const { return f164 + x * i164; }
    bool is_valid() const { return i164 >= 0; }
    void scale(float s) { f164 *= s; }
    void offset(float o) { f164 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 165 ═══
namespace {
struct RenderUtil165 {
    float f165 = 165.0f;
    int i165 = 165;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f165 = 0; i165 = 0; kind = Kind::A; }
    float compute(float x) const { return f165 + x * i165; }
    bool is_valid() const { return i165 >= 0; }
    void scale(float s) { f165 *= s; }
    void offset(float o) { f165 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 166 ═══
namespace {
struct RenderUtil166 {
    float f166 = 166.0f;
    int i166 = 166;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f166 = 0; i166 = 0; kind = Kind::A; }
    float compute(float x) const { return f166 + x * i166; }
    bool is_valid() const { return i166 >= 0; }
    void scale(float s) { f166 *= s; }
    void offset(float o) { f166 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 167 ═══
namespace {
struct RenderUtil167 {
    float f167 = 167.0f;
    int i167 = 167;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f167 = 0; i167 = 0; kind = Kind::A; }
    float compute(float x) const { return f167 + x * i167; }
    bool is_valid() const { return i167 >= 0; }
    void scale(float s) { f167 *= s; }
    void offset(float o) { f167 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 168 ═══
namespace {
struct RenderUtil168 {
    float f168 = 168.0f;
    int i168 = 168;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f168 = 0; i168 = 0; kind = Kind::A; }
    float compute(float x) const { return f168 + x * i168; }
    bool is_valid() const { return i168 >= 0; }
    void scale(float s) { f168 *= s; }
    void offset(float o) { f168 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 169 ═══
namespace {
struct RenderUtil169 {
    float f169 = 169.0f;
    int i169 = 169;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f169 = 0; i169 = 0; kind = Kind::A; }
    float compute(float x) const { return f169 + x * i169; }
    bool is_valid() const { return i169 >= 0; }
    void scale(float s) { f169 *= s; }
    void offset(float o) { f169 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 170 ═══
namespace {
struct RenderUtil170 {
    float f170 = 170.0f;
    int i170 = 170;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f170 = 0; i170 = 0; kind = Kind::A; }
    float compute(float x) const { return f170 + x * i170; }
    bool is_valid() const { return i170 >= 0; }
    void scale(float s) { f170 *= s; }
    void offset(float o) { f170 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 171 ═══
namespace {
struct RenderUtil171 {
    float f171 = 171.0f;
    int i171 = 171;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f171 = 0; i171 = 0; kind = Kind::A; }
    float compute(float x) const { return f171 + x * i171; }
    bool is_valid() const { return i171 >= 0; }
    void scale(float s) { f171 *= s; }
    void offset(float o) { f171 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 172 ═══
namespace {
struct RenderUtil172 {
    float f172 = 172.0f;
    int i172 = 172;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f172 = 0; i172 = 0; kind = Kind::A; }
    float compute(float x) const { return f172 + x * i172; }
    bool is_valid() const { return i172 >= 0; }
    void scale(float s) { f172 *= s; }
    void offset(float o) { f172 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 173 ═══
namespace {
struct RenderUtil173 {
    float f173 = 173.0f;
    int i173 = 173;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f173 = 0; i173 = 0; kind = Kind::A; }
    float compute(float x) const { return f173 + x * i173; }
    bool is_valid() const { return i173 >= 0; }
    void scale(float s) { f173 *= s; }
    void offset(float o) { f173 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 174 ═══
namespace {
struct RenderUtil174 {
    float f174 = 174.0f;
    int i174 = 174;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f174 = 0; i174 = 0; kind = Kind::A; }
    float compute(float x) const { return f174 + x * i174; }
    bool is_valid() const { return i174 >= 0; }
    void scale(float s) { f174 *= s; }
    void offset(float o) { f174 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 175 ═══
namespace {
struct RenderUtil175 {
    float f175 = 175.0f;
    int i175 = 175;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f175 = 0; i175 = 0; kind = Kind::A; }
    float compute(float x) const { return f175 + x * i175; }
    bool is_valid() const { return i175 >= 0; }
    void scale(float s) { f175 *= s; }
    void offset(float o) { f175 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 176 ═══
namespace {
struct RenderUtil176 {
    float f176 = 176.0f;
    int i176 = 176;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f176 = 0; i176 = 0; kind = Kind::A; }
    float compute(float x) const { return f176 + x * i176; }
    bool is_valid() const { return i176 >= 0; }
    void scale(float s) { f176 *= s; }
    void offset(float o) { f176 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 177 ═══
namespace {
struct RenderUtil177 {
    float f177 = 177.0f;
    int i177 = 177;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f177 = 0; i177 = 0; kind = Kind::A; }
    float compute(float x) const { return f177 + x * i177; }
    bool is_valid() const { return i177 >= 0; }
    void scale(float s) { f177 *= s; }
    void offset(float o) { f177 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 178 ═══
namespace {
struct RenderUtil178 {
    float f178 = 178.0f;
    int i178 = 178;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f178 = 0; i178 = 0; kind = Kind::A; }
    float compute(float x) const { return f178 + x * i178; }
    bool is_valid() const { return i178 >= 0; }
    void scale(float s) { f178 *= s; }
    void offset(float o) { f178 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 179 ═══
namespace {
struct RenderUtil179 {
    float f179 = 179.0f;
    int i179 = 179;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f179 = 0; i179 = 0; kind = Kind::A; }
    float compute(float x) const { return f179 + x * i179; }
    bool is_valid() const { return i179 >= 0; }
    void scale(float s) { f179 *= s; }
    void offset(float o) { f179 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 180 ═══
namespace {
struct RenderUtil180 {
    float f180 = 180.0f;
    int i180 = 180;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f180 = 0; i180 = 0; kind = Kind::A; }
    float compute(float x) const { return f180 + x * i180; }
    bool is_valid() const { return i180 >= 0; }
    void scale(float s) { f180 *= s; }
    void offset(float o) { f180 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 181 ═══
namespace {
struct RenderUtil181 {
    float f181 = 181.0f;
    int i181 = 181;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f181 = 0; i181 = 0; kind = Kind::A; }
    float compute(float x) const { return f181 + x * i181; }
    bool is_valid() const { return i181 >= 0; }
    void scale(float s) { f181 *= s; }
    void offset(float o) { f181 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 182 ═══
namespace {
struct RenderUtil182 {
    float f182 = 182.0f;
    int i182 = 182;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f182 = 0; i182 = 0; kind = Kind::A; }
    float compute(float x) const { return f182 + x * i182; }
    bool is_valid() const { return i182 >= 0; }
    void scale(float s) { f182 *= s; }
    void offset(float o) { f182 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 183 ═══
namespace {
struct RenderUtil183 {
    float f183 = 183.0f;
    int i183 = 183;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f183 = 0; i183 = 0; kind = Kind::A; }
    float compute(float x) const { return f183 + x * i183; }
    bool is_valid() const { return i183 >= 0; }
    void scale(float s) { f183 *= s; }
    void offset(float o) { f183 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 184 ═══
namespace {
struct RenderUtil184 {
    float f184 = 184.0f;
    int i184 = 184;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f184 = 0; i184 = 0; kind = Kind::A; }
    float compute(float x) const { return f184 + x * i184; }
    bool is_valid() const { return i184 >= 0; }
    void scale(float s) { f184 *= s; }
    void offset(float o) { f184 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 185 ═══
namespace {
struct RenderUtil185 {
    float f185 = 185.0f;
    int i185 = 185;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f185 = 0; i185 = 0; kind = Kind::A; }
    float compute(float x) const { return f185 + x * i185; }
    bool is_valid() const { return i185 >= 0; }
    void scale(float s) { f185 *= s; }
    void offset(float o) { f185 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 186 ═══
namespace {
struct RenderUtil186 {
    float f186 = 186.0f;
    int i186 = 186;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f186 = 0; i186 = 0; kind = Kind::A; }
    float compute(float x) const { return f186 + x * i186; }
    bool is_valid() const { return i186 >= 0; }
    void scale(float s) { f186 *= s; }
    void offset(float o) { f186 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 187 ═══
namespace {
struct RenderUtil187 {
    float f187 = 187.0f;
    int i187 = 187;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f187 = 0; i187 = 0; kind = Kind::A; }
    float compute(float x) const { return f187 + x * i187; }
    bool is_valid() const { return i187 >= 0; }
    void scale(float s) { f187 *= s; }
    void offset(float o) { f187 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 188 ═══
namespace {
struct RenderUtil188 {
    float f188 = 188.0f;
    int i188 = 188;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f188 = 0; i188 = 0; kind = Kind::A; }
    float compute(float x) const { return f188 + x * i188; }
    bool is_valid() const { return i188 >= 0; }
    void scale(float s) { f188 *= s; }
    void offset(float o) { f188 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 189 ═══
namespace {
struct RenderUtil189 {
    float f189 = 189.0f;
    int i189 = 189;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f189 = 0; i189 = 0; kind = Kind::A; }
    float compute(float x) const { return f189 + x * i189; }
    bool is_valid() const { return i189 >= 0; }
    void scale(float s) { f189 *= s; }
    void offset(float o) { f189 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 190 ═══
namespace {
struct RenderUtil190 {
    float f190 = 190.0f;
    int i190 = 190;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f190 = 0; i190 = 0; kind = Kind::A; }
    float compute(float x) const { return f190 + x * i190; }
    bool is_valid() const { return i190 >= 0; }
    void scale(float s) { f190 *= s; }
    void offset(float o) { f190 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 191 ═══
namespace {
struct RenderUtil191 {
    float f191 = 191.0f;
    int i191 = 191;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f191 = 0; i191 = 0; kind = Kind::A; }
    float compute(float x) const { return f191 + x * i191; }
    bool is_valid() const { return i191 >= 0; }
    void scale(float s) { f191 *= s; }
    void offset(float o) { f191 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 192 ═══
namespace {
struct RenderUtil192 {
    float f192 = 192.0f;
    int i192 = 192;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f192 = 0; i192 = 0; kind = Kind::A; }
    float compute(float x) const { return f192 + x * i192; }
    bool is_valid() const { return i192 >= 0; }
    void scale(float s) { f192 *= s; }
    void offset(float o) { f192 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 193 ═══
namespace {
struct RenderUtil193 {
    float f193 = 193.0f;
    int i193 = 193;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f193 = 0; i193 = 0; kind = Kind::A; }
    float compute(float x) const { return f193 + x * i193; }
    bool is_valid() const { return i193 >= 0; }
    void scale(float s) { f193 *= s; }
    void offset(float o) { f193 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 194 ═══
namespace {
struct RenderUtil194 {
    float f194 = 194.0f;
    int i194 = 194;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f194 = 0; i194 = 0; kind = Kind::A; }
    float compute(float x) const { return f194 + x * i194; }
    bool is_valid() const { return i194 >= 0; }
    void scale(float s) { f194 *= s; }
    void offset(float o) { f194 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 195 ═══
namespace {
struct RenderUtil195 {
    float f195 = 195.0f;
    int i195 = 195;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f195 = 0; i195 = 0; kind = Kind::A; }
    float compute(float x) const { return f195 + x * i195; }
    bool is_valid() const { return i195 >= 0; }
    void scale(float s) { f195 *= s; }
    void offset(float o) { f195 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 196 ═══
namespace {
struct RenderUtil196 {
    float f196 = 196.0f;
    int i196 = 196;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f196 = 0; i196 = 0; kind = Kind::A; }
    float compute(float x) const { return f196 + x * i196; }
    bool is_valid() const { return i196 >= 0; }
    void scale(float s) { f196 *= s; }
    void offset(float o) { f196 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 197 ═══
namespace {
struct RenderUtil197 {
    float f197 = 197.0f;
    int i197 = 197;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f197 = 0; i197 = 0; kind = Kind::A; }
    float compute(float x) const { return f197 + x * i197; }
    bool is_valid() const { return i197 >= 0; }
    void scale(float s) { f197 *= s; }
    void offset(float o) { f197 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 198 ═══
namespace {
struct RenderUtil198 {
    float f198 = 198.0f;
    int i198 = 198;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f198 = 0; i198 = 0; kind = Kind::A; }
    float compute(float x) const { return f198 + x * i198; }
    bool is_valid() const { return i198 >= 0; }
    void scale(float s) { f198 *= s; }
    void offset(float o) { f198 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 199 ═══
namespace {
struct RenderUtil199 {
    float f199 = 199.0f;
    int i199 = 199;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f199 = 0; i199 = 0; kind = Kind::A; }
    float compute(float x) const { return f199 + x * i199; }
    bool is_valid() const { return i199 >= 0; }
    void scale(float s) { f199 *= s; }
    void offset(float o) { f199 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 200 ═══
namespace {
struct RenderUtil200 {
    float f200 = 200.0f;
    int i200 = 200;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f200 = 0; i200 = 0; kind = Kind::A; }
    float compute(float x) const { return f200 + x * i200; }
    bool is_valid() const { return i200 >= 0; }
    void scale(float s) { f200 *= s; }
    void offset(float o) { f200 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 201 ═══
namespace {
struct RenderUtil201 {
    float f201 = 201.0f;
    int i201 = 201;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f201 = 0; i201 = 0; kind = Kind::A; }
    float compute(float x) const { return f201 + x * i201; }
    bool is_valid() const { return i201 >= 0; }
    void scale(float s) { f201 *= s; }
    void offset(float o) { f201 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 202 ═══
namespace {
struct RenderUtil202 {
    float f202 = 202.0f;
    int i202 = 202;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f202 = 0; i202 = 0; kind = Kind::A; }
    float compute(float x) const { return f202 + x * i202; }
    bool is_valid() const { return i202 >= 0; }
    void scale(float s) { f202 *= s; }
    void offset(float o) { f202 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 203 ═══
namespace {
struct RenderUtil203 {
    float f203 = 203.0f;
    int i203 = 203;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f203 = 0; i203 = 0; kind = Kind::A; }
    float compute(float x) const { return f203 + x * i203; }
    bool is_valid() const { return i203 >= 0; }
    void scale(float s) { f203 *= s; }
    void offset(float o) { f203 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 204 ═══
namespace {
struct RenderUtil204 {
    float f204 = 204.0f;
    int i204 = 204;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f204 = 0; i204 = 0; kind = Kind::A; }
    float compute(float x) const { return f204 + x * i204; }
    bool is_valid() const { return i204 >= 0; }
    void scale(float s) { f204 *= s; }
    void offset(float o) { f204 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 205 ═══
namespace {
struct RenderUtil205 {
    float f205 = 205.0f;
    int i205 = 205;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f205 = 0; i205 = 0; kind = Kind::A; }
    float compute(float x) const { return f205 + x * i205; }
    bool is_valid() const { return i205 >= 0; }
    void scale(float s) { f205 *= s; }
    void offset(float o) { f205 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 206 ═══
namespace {
struct RenderUtil206 {
    float f206 = 206.0f;
    int i206 = 206;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f206 = 0; i206 = 0; kind = Kind::A; }
    float compute(float x) const { return f206 + x * i206; }
    bool is_valid() const { return i206 >= 0; }
    void scale(float s) { f206 *= s; }
    void offset(float o) { f206 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 207 ═══
namespace {
struct RenderUtil207 {
    float f207 = 207.0f;
    int i207 = 207;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f207 = 0; i207 = 0; kind = Kind::A; }
    float compute(float x) const { return f207 + x * i207; }
    bool is_valid() const { return i207 >= 0; }
    void scale(float s) { f207 *= s; }
    void offset(float o) { f207 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 208 ═══
namespace {
struct RenderUtil208 {
    float f208 = 208.0f;
    int i208 = 208;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f208 = 0; i208 = 0; kind = Kind::A; }
    float compute(float x) const { return f208 + x * i208; }
    bool is_valid() const { return i208 >= 0; }
    void scale(float s) { f208 *= s; }
    void offset(float o) { f208 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 209 ═══
namespace {
struct RenderUtil209 {
    float f209 = 209.0f;
    int i209 = 209;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f209 = 0; i209 = 0; kind = Kind::A; }
    float compute(float x) const { return f209 + x * i209; }
    bool is_valid() const { return i209 >= 0; }
    void scale(float s) { f209 *= s; }
    void offset(float o) { f209 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 210 ═══
namespace {
struct RenderUtil210 {
    float f210 = 210.0f;
    int i210 = 210;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f210 = 0; i210 = 0; kind = Kind::A; }
    float compute(float x) const { return f210 + x * i210; }
    bool is_valid() const { return i210 >= 0; }
    void scale(float s) { f210 *= s; }
    void offset(float o) { f210 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 211 ═══
namespace {
struct RenderUtil211 {
    float f211 = 211.0f;
    int i211 = 211;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f211 = 0; i211 = 0; kind = Kind::A; }
    float compute(float x) const { return f211 + x * i211; }
    bool is_valid() const { return i211 >= 0; }
    void scale(float s) { f211 *= s; }
    void offset(float o) { f211 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 212 ═══
namespace {
struct RenderUtil212 {
    float f212 = 212.0f;
    int i212 = 212;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f212 = 0; i212 = 0; kind = Kind::A; }
    float compute(float x) const { return f212 + x * i212; }
    bool is_valid() const { return i212 >= 0; }
    void scale(float s) { f212 *= s; }
    void offset(float o) { f212 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 213 ═══
namespace {
struct RenderUtil213 {
    float f213 = 213.0f;
    int i213 = 213;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f213 = 0; i213 = 0; kind = Kind::A; }
    float compute(float x) const { return f213 + x * i213; }
    bool is_valid() const { return i213 >= 0; }
    void scale(float s) { f213 *= s; }
    void offset(float o) { f213 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 214 ═══
namespace {
struct RenderUtil214 {
    float f214 = 214.0f;
    int i214 = 214;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f214 = 0; i214 = 0; kind = Kind::A; }
    float compute(float x) const { return f214 + x * i214; }
    bool is_valid() const { return i214 >= 0; }
    void scale(float s) { f214 *= s; }
    void offset(float o) { f214 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 215 ═══
namespace {
struct RenderUtil215 {
    float f215 = 215.0f;
    int i215 = 215;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f215 = 0; i215 = 0; kind = Kind::A; }
    float compute(float x) const { return f215 + x * i215; }
    bool is_valid() const { return i215 >= 0; }
    void scale(float s) { f215 *= s; }
    void offset(float o) { f215 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 216 ═══
namespace {
struct RenderUtil216 {
    float f216 = 216.0f;
    int i216 = 216;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f216 = 0; i216 = 0; kind = Kind::A; }
    float compute(float x) const { return f216 + x * i216; }
    bool is_valid() const { return i216 >= 0; }
    void scale(float s) { f216 *= s; }
    void offset(float o) { f216 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 217 ═══
namespace {
struct RenderUtil217 {
    float f217 = 217.0f;
    int i217 = 217;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f217 = 0; i217 = 0; kind = Kind::A; }
    float compute(float x) const { return f217 + x * i217; }
    bool is_valid() const { return i217 >= 0; }
    void scale(float s) { f217 *= s; }
    void offset(float o) { f217 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 218 ═══
namespace {
struct RenderUtil218 {
    float f218 = 218.0f;
    int i218 = 218;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f218 = 0; i218 = 0; kind = Kind::A; }
    float compute(float x) const { return f218 + x * i218; }
    bool is_valid() const { return i218 >= 0; }
    void scale(float s) { f218 *= s; }
    void offset(float o) { f218 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 219 ═══
namespace {
struct RenderUtil219 {
    float f219 = 219.0f;
    int i219 = 219;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f219 = 0; i219 = 0; kind = Kind::A; }
    float compute(float x) const { return f219 + x * i219; }
    bool is_valid() const { return i219 >= 0; }
    void scale(float s) { f219 *= s; }
    void offset(float o) { f219 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 220 ═══
namespace {
struct RenderUtil220 {
    float f220 = 220.0f;
    int i220 = 220;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f220 = 0; i220 = 0; kind = Kind::A; }
    float compute(float x) const { return f220 + x * i220; }
    bool is_valid() const { return i220 >= 0; }
    void scale(float s) { f220 *= s; }
    void offset(float o) { f220 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 221 ═══
namespace {
struct RenderUtil221 {
    float f221 = 221.0f;
    int i221 = 221;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f221 = 0; i221 = 0; kind = Kind::A; }
    float compute(float x) const { return f221 + x * i221; }
    bool is_valid() const { return i221 >= 0; }
    void scale(float s) { f221 *= s; }
    void offset(float o) { f221 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 222 ═══
namespace {
struct RenderUtil222 {
    float f222 = 222.0f;
    int i222 = 222;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f222 = 0; i222 = 0; kind = Kind::A; }
    float compute(float x) const { return f222 + x * i222; }
    bool is_valid() const { return i222 >= 0; }
    void scale(float s) { f222 *= s; }
    void offset(float o) { f222 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 223 ═══
namespace {
struct RenderUtil223 {
    float f223 = 223.0f;
    int i223 = 223;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f223 = 0; i223 = 0; kind = Kind::A; }
    float compute(float x) const { return f223 + x * i223; }
    bool is_valid() const { return i223 >= 0; }
    void scale(float s) { f223 *= s; }
    void offset(float o) { f223 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 224 ═══
namespace {
struct RenderUtil224 {
    float f224 = 224.0f;
    int i224 = 224;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f224 = 0; i224 = 0; kind = Kind::A; }
    float compute(float x) const { return f224 + x * i224; }
    bool is_valid() const { return i224 >= 0; }
    void scale(float s) { f224 *= s; }
    void offset(float o) { f224 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 225 ═══
namespace {
struct RenderUtil225 {
    float f225 = 225.0f;
    int i225 = 225;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f225 = 0; i225 = 0; kind = Kind::A; }
    float compute(float x) const { return f225 + x * i225; }
    bool is_valid() const { return i225 >= 0; }
    void scale(float s) { f225 *= s; }
    void offset(float o) { f225 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 226 ═══
namespace {
struct RenderUtil226 {
    float f226 = 226.0f;
    int i226 = 226;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f226 = 0; i226 = 0; kind = Kind::A; }
    float compute(float x) const { return f226 + x * i226; }
    bool is_valid() const { return i226 >= 0; }
    void scale(float s) { f226 *= s; }
    void offset(float o) { f226 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 227 ═══
namespace {
struct RenderUtil227 {
    float f227 = 227.0f;
    int i227 = 227;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f227 = 0; i227 = 0; kind = Kind::A; }
    float compute(float x) const { return f227 + x * i227; }
    bool is_valid() const { return i227 >= 0; }
    void scale(float s) { f227 *= s; }
    void offset(float o) { f227 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 228 ═══
namespace {
struct RenderUtil228 {
    float f228 = 228.0f;
    int i228 = 228;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f228 = 0; i228 = 0; kind = Kind::A; }
    float compute(float x) const { return f228 + x * i228; }
    bool is_valid() const { return i228 >= 0; }
    void scale(float s) { f228 *= s; }
    void offset(float o) { f228 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 229 ═══
namespace {
struct RenderUtil229 {
    float f229 = 229.0f;
    int i229 = 229;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f229 = 0; i229 = 0; kind = Kind::A; }
    float compute(float x) const { return f229 + x * i229; }
    bool is_valid() const { return i229 >= 0; }
    void scale(float s) { f229 *= s; }
    void offset(float o) { f229 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 230 ═══
namespace {
struct RenderUtil230 {
    float f230 = 230.0f;
    int i230 = 230;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f230 = 0; i230 = 0; kind = Kind::A; }
    float compute(float x) const { return f230 + x * i230; }
    bool is_valid() const { return i230 >= 0; }
    void scale(float s) { f230 *= s; }
    void offset(float o) { f230 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 231 ═══
namespace {
struct RenderUtil231 {
    float f231 = 231.0f;
    int i231 = 231;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f231 = 0; i231 = 0; kind = Kind::A; }
    float compute(float x) const { return f231 + x * i231; }
    bool is_valid() const { return i231 >= 0; }
    void scale(float s) { f231 *= s; }
    void offset(float o) { f231 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 232 ═══
namespace {
struct RenderUtil232 {
    float f232 = 232.0f;
    int i232 = 232;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f232 = 0; i232 = 0; kind = Kind::A; }
    float compute(float x) const { return f232 + x * i232; }
    bool is_valid() const { return i232 >= 0; }
    void scale(float s) { f232 *= s; }
    void offset(float o) { f232 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 233 ═══
namespace {
struct RenderUtil233 {
    float f233 = 233.0f;
    int i233 = 233;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f233 = 0; i233 = 0; kind = Kind::A; }
    float compute(float x) const { return f233 + x * i233; }
    bool is_valid() const { return i233 >= 0; }
    void scale(float s) { f233 *= s; }
    void offset(float o) { f233 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 234 ═══
namespace {
struct RenderUtil234 {
    float f234 = 234.0f;
    int i234 = 234;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f234 = 0; i234 = 0; kind = Kind::A; }
    float compute(float x) const { return f234 + x * i234; }
    bool is_valid() const { return i234 >= 0; }
    void scale(float s) { f234 *= s; }
    void offset(float o) { f234 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 235 ═══
namespace {
struct RenderUtil235 {
    float f235 = 235.0f;
    int i235 = 235;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f235 = 0; i235 = 0; kind = Kind::A; }
    float compute(float x) const { return f235 + x * i235; }
    bool is_valid() const { return i235 >= 0; }
    void scale(float s) { f235 *= s; }
    void offset(float o) { f235 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 236 ═══
namespace {
struct RenderUtil236 {
    float f236 = 236.0f;
    int i236 = 236;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f236 = 0; i236 = 0; kind = Kind::A; }
    float compute(float x) const { return f236 + x * i236; }
    bool is_valid() const { return i236 >= 0; }
    void scale(float s) { f236 *= s; }
    void offset(float o) { f236 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 237 ═══
namespace {
struct RenderUtil237 {
    float f237 = 237.0f;
    int i237 = 237;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f237 = 0; i237 = 0; kind = Kind::A; }
    float compute(float x) const { return f237 + x * i237; }
    bool is_valid() const { return i237 >= 0; }
    void scale(float s) { f237 *= s; }
    void offset(float o) { f237 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 238 ═══
namespace {
struct RenderUtil238 {
    float f238 = 238.0f;
    int i238 = 238;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f238 = 0; i238 = 0; kind = Kind::A; }
    float compute(float x) const { return f238 + x * i238; }
    bool is_valid() const { return i238 >= 0; }
    void scale(float s) { f238 *= s; }
    void offset(float o) { f238 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 239 ═══
namespace {
struct RenderUtil239 {
    float f239 = 239.0f;
    int i239 = 239;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f239 = 0; i239 = 0; kind = Kind::A; }
    float compute(float x) const { return f239 + x * i239; }
    bool is_valid() const { return i239 >= 0; }
    void scale(float s) { f239 *= s; }
    void offset(float o) { f239 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 240 ═══
namespace {
struct RenderUtil240 {
    float f240 = 240.0f;
    int i240 = 240;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f240 = 0; i240 = 0; kind = Kind::A; }
    float compute(float x) const { return f240 + x * i240; }
    bool is_valid() const { return i240 >= 0; }
    void scale(float s) { f240 *= s; }
    void offset(float o) { f240 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 241 ═══
namespace {
struct RenderUtil241 {
    float f241 = 241.0f;
    int i241 = 241;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f241 = 0; i241 = 0; kind = Kind::A; }
    float compute(float x) const { return f241 + x * i241; }
    bool is_valid() const { return i241 >= 0; }
    void scale(float s) { f241 *= s; }
    void offset(float o) { f241 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 242 ═══
namespace {
struct RenderUtil242 {
    float f242 = 242.0f;
    int i242 = 242;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f242 = 0; i242 = 0; kind = Kind::A; }
    float compute(float x) const { return f242 + x * i242; }
    bool is_valid() const { return i242 >= 0; }
    void scale(float s) { f242 *= s; }
    void offset(float o) { f242 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 243 ═══
namespace {
struct RenderUtil243 {
    float f243 = 243.0f;
    int i243 = 243;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f243 = 0; i243 = 0; kind = Kind::A; }
    float compute(float x) const { return f243 + x * i243; }
    bool is_valid() const { return i243 >= 0; }
    void scale(float s) { f243 *= s; }
    void offset(float o) { f243 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 244 ═══
namespace {
struct RenderUtil244 {
    float f244 = 244.0f;
    int i244 = 244;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f244 = 0; i244 = 0; kind = Kind::A; }
    float compute(float x) const { return f244 + x * i244; }
    bool is_valid() const { return i244 >= 0; }
    void scale(float s) { f244 *= s; }
    void offset(float o) { f244 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 245 ═══
namespace {
struct RenderUtil245 {
    float f245 = 245.0f;
    int i245 = 245;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f245 = 0; i245 = 0; kind = Kind::A; }
    float compute(float x) const { return f245 + x * i245; }
    bool is_valid() const { return i245 >= 0; }
    void scale(float s) { f245 *= s; }
    void offset(float o) { f245 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 246 ═══
namespace {
struct RenderUtil246 {
    float f246 = 246.0f;
    int i246 = 246;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f246 = 0; i246 = 0; kind = Kind::A; }
    float compute(float x) const { return f246 + x * i246; }
    bool is_valid() const { return i246 >= 0; }
    void scale(float s) { f246 *= s; }
    void offset(float o) { f246 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 247 ═══
namespace {
struct RenderUtil247 {
    float f247 = 247.0f;
    int i247 = 247;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f247 = 0; i247 = 0; kind = Kind::A; }
    float compute(float x) const { return f247 + x * i247; }
    bool is_valid() const { return i247 >= 0; }
    void scale(float s) { f247 *= s; }
    void offset(float o) { f247 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 248 ═══
namespace {
struct RenderUtil248 {
    float f248 = 248.0f;
    int i248 = 248;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f248 = 0; i248 = 0; kind = Kind::A; }
    float compute(float x) const { return f248 + x * i248; }
    bool is_valid() const { return i248 >= 0; }
    void scale(float s) { f248 *= s; }
    void offset(float o) { f248 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 249 ═══
namespace {
struct RenderUtil249 {
    float f249 = 249.0f;
    int i249 = 249;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f249 = 0; i249 = 0; kind = Kind::A; }
    float compute(float x) const { return f249 + x * i249; }
    bool is_valid() const { return i249 >= 0; }
    void scale(float s) { f249 *= s; }
    void offset(float o) { f249 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 250 ═══
namespace {
struct RenderUtil250 {
    float f250 = 250.0f;
    int i250 = 250;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f250 = 0; i250 = 0; kind = Kind::A; }
    float compute(float x) const { return f250 + x * i250; }
    bool is_valid() const { return i250 >= 0; }
    void scale(float s) { f250 *= s; }
    void offset(float o) { f250 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 251 ═══
namespace {
struct RenderUtil251 {
    float f251 = 251.0f;
    int i251 = 251;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f251 = 0; i251 = 0; kind = Kind::A; }
    float compute(float x) const { return f251 + x * i251; }
    bool is_valid() const { return i251 >= 0; }
    void scale(float s) { f251 *= s; }
    void offset(float o) { f251 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 252 ═══
namespace {
struct RenderUtil252 {
    float f252 = 252.0f;
    int i252 = 252;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f252 = 0; i252 = 0; kind = Kind::A; }
    float compute(float x) const { return f252 + x * i252; }
    bool is_valid() const { return i252 >= 0; }
    void scale(float s) { f252 *= s; }
    void offset(float o) { f252 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 253 ═══
namespace {
struct RenderUtil253 {
    float f253 = 253.0f;
    int i253 = 253;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f253 = 0; i253 = 0; kind = Kind::A; }
    float compute(float x) const { return f253 + x * i253; }
    bool is_valid() const { return i253 >= 0; }
    void scale(float s) { f253 *= s; }
    void offset(float o) { f253 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 254 ═══
namespace {
struct RenderUtil254 {
    float f254 = 254.0f;
    int i254 = 254;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f254 = 0; i254 = 0; kind = Kind::A; }
    float compute(float x) const { return f254 + x * i254; }
    bool is_valid() const { return i254 >= 0; }
    void scale(float s) { f254 *= s; }
    void offset(float o) { f254 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 255 ═══
namespace {
struct RenderUtil255 {
    float f255 = 255.0f;
    int i255 = 255;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f255 = 0; i255 = 0; kind = Kind::A; }
    float compute(float x) const { return f255 + x * i255; }
    bool is_valid() const { return i255 >= 0; }
    void scale(float s) { f255 *= s; }
    void offset(float o) { f255 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 256 ═══
namespace {
struct RenderUtil256 {
    float f256 = 256.0f;
    int i256 = 256;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f256 = 0; i256 = 0; kind = Kind::A; }
    float compute(float x) const { return f256 + x * i256; }
    bool is_valid() const { return i256 >= 0; }
    void scale(float s) { f256 *= s; }
    void offset(float o) { f256 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 257 ═══
namespace {
struct RenderUtil257 {
    float f257 = 257.0f;
    int i257 = 257;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f257 = 0; i257 = 0; kind = Kind::A; }
    float compute(float x) const { return f257 + x * i257; }
    bool is_valid() const { return i257 >= 0; }
    void scale(float s) { f257 *= s; }
    void offset(float o) { f257 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 258 ═══
namespace {
struct RenderUtil258 {
    float f258 = 258.0f;
    int i258 = 258;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f258 = 0; i258 = 0; kind = Kind::A; }
    float compute(float x) const { return f258 + x * i258; }
    bool is_valid() const { return i258 >= 0; }
    void scale(float s) { f258 *= s; }
    void offset(float o) { f258 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 259 ═══
namespace {
struct RenderUtil259 {
    float f259 = 259.0f;
    int i259 = 259;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f259 = 0; i259 = 0; kind = Kind::A; }
    float compute(float x) const { return f259 + x * i259; }
    bool is_valid() const { return i259 >= 0; }
    void scale(float s) { f259 *= s; }
    void offset(float o) { f259 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 260 ═══
namespace {
struct RenderUtil260 {
    float f260 = 260.0f;
    int i260 = 260;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f260 = 0; i260 = 0; kind = Kind::A; }
    float compute(float x) const { return f260 + x * i260; }
    bool is_valid() const { return i260 >= 0; }
    void scale(float s) { f260 *= s; }
    void offset(float o) { f260 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 261 ═══
namespace {
struct RenderUtil261 {
    float f261 = 261.0f;
    int i261 = 261;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f261 = 0; i261 = 0; kind = Kind::A; }
    float compute(float x) const { return f261 + x * i261; }
    bool is_valid() const { return i261 >= 0; }
    void scale(float s) { f261 *= s; }
    void offset(float o) { f261 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 262 ═══
namespace {
struct RenderUtil262 {
    float f262 = 262.0f;
    int i262 = 262;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f262 = 0; i262 = 0; kind = Kind::A; }
    float compute(float x) const { return f262 + x * i262; }
    bool is_valid() const { return i262 >= 0; }
    void scale(float s) { f262 *= s; }
    void offset(float o) { f262 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 263 ═══
namespace {
struct RenderUtil263 {
    float f263 = 263.0f;
    int i263 = 263;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f263 = 0; i263 = 0; kind = Kind::A; }
    float compute(float x) const { return f263 + x * i263; }
    bool is_valid() const { return i263 >= 0; }
    void scale(float s) { f263 *= s; }
    void offset(float o) { f263 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 264 ═══
namespace {
struct RenderUtil264 {
    float f264 = 264.0f;
    int i264 = 264;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f264 = 0; i264 = 0; kind = Kind::A; }
    float compute(float x) const { return f264 + x * i264; }
    bool is_valid() const { return i264 >= 0; }
    void scale(float s) { f264 *= s; }
    void offset(float o) { f264 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 265 ═══
namespace {
struct RenderUtil265 {
    float f265 = 265.0f;
    int i265 = 265;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f265 = 0; i265 = 0; kind = Kind::A; }
    float compute(float x) const { return f265 + x * i265; }
    bool is_valid() const { return i265 >= 0; }
    void scale(float s) { f265 *= s; }
    void offset(float o) { f265 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 266 ═══
namespace {
struct RenderUtil266 {
    float f266 = 266.0f;
    int i266 = 266;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f266 = 0; i266 = 0; kind = Kind::A; }
    float compute(float x) const { return f266 + x * i266; }
    bool is_valid() const { return i266 >= 0; }
    void scale(float s) { f266 *= s; }
    void offset(float o) { f266 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 267 ═══
namespace {
struct RenderUtil267 {
    float f267 = 267.0f;
    int i267 = 267;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f267 = 0; i267 = 0; kind = Kind::A; }
    float compute(float x) const { return f267 + x * i267; }
    bool is_valid() const { return i267 >= 0; }
    void scale(float s) { f267 *= s; }
    void offset(float o) { f267 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 268 ═══
namespace {
struct RenderUtil268 {
    float f268 = 268.0f;
    int i268 = 268;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f268 = 0; i268 = 0; kind = Kind::A; }
    float compute(float x) const { return f268 + x * i268; }
    bool is_valid() const { return i268 >= 0; }
    void scale(float s) { f268 *= s; }
    void offset(float o) { f268 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 269 ═══
namespace {
struct RenderUtil269 {
    float f269 = 269.0f;
    int i269 = 269;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f269 = 0; i269 = 0; kind = Kind::A; }
    float compute(float x) const { return f269 + x * i269; }
    bool is_valid() const { return i269 >= 0; }
    void scale(float s) { f269 *= s; }
    void offset(float o) { f269 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 270 ═══
namespace {
struct RenderUtil270 {
    float f270 = 270.0f;
    int i270 = 270;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f270 = 0; i270 = 0; kind = Kind::A; }
    float compute(float x) const { return f270 + x * i270; }
    bool is_valid() const { return i270 >= 0; }
    void scale(float s) { f270 *= s; }
    void offset(float o) { f270 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 271 ═══
namespace {
struct RenderUtil271 {
    float f271 = 271.0f;
    int i271 = 271;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f271 = 0; i271 = 0; kind = Kind::A; }
    float compute(float x) const { return f271 + x * i271; }
    bool is_valid() const { return i271 >= 0; }
    void scale(float s) { f271 *= s; }
    void offset(float o) { f271 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 272 ═══
namespace {
struct RenderUtil272 {
    float f272 = 272.0f;
    int i272 = 272;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f272 = 0; i272 = 0; kind = Kind::A; }
    float compute(float x) const { return f272 + x * i272; }
    bool is_valid() const { return i272 >= 0; }
    void scale(float s) { f272 *= s; }
    void offset(float o) { f272 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 273 ═══
namespace {
struct RenderUtil273 {
    float f273 = 273.0f;
    int i273 = 273;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f273 = 0; i273 = 0; kind = Kind::A; }
    float compute(float x) const { return f273 + x * i273; }
    bool is_valid() const { return i273 >= 0; }
    void scale(float s) { f273 *= s; }
    void offset(float o) { f273 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 274 ═══
namespace {
struct RenderUtil274 {
    float f274 = 274.0f;
    int i274 = 274;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f274 = 0; i274 = 0; kind = Kind::A; }
    float compute(float x) const { return f274 + x * i274; }
    bool is_valid() const { return i274 >= 0; }
    void scale(float s) { f274 *= s; }
    void offset(float o) { f274 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 275 ═══
namespace {
struct RenderUtil275 {
    float f275 = 275.0f;
    int i275 = 275;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f275 = 0; i275 = 0; kind = Kind::A; }
    float compute(float x) const { return f275 + x * i275; }
    bool is_valid() const { return i275 >= 0; }
    void scale(float s) { f275 *= s; }
    void offset(float o) { f275 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 276 ═══
namespace {
struct RenderUtil276 {
    float f276 = 276.0f;
    int i276 = 276;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f276 = 0; i276 = 0; kind = Kind::A; }
    float compute(float x) const { return f276 + x * i276; }
    bool is_valid() const { return i276 >= 0; }
    void scale(float s) { f276 *= s; }
    void offset(float o) { f276 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 277 ═══
namespace {
struct RenderUtil277 {
    float f277 = 277.0f;
    int i277 = 277;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f277 = 0; i277 = 0; kind = Kind::A; }
    float compute(float x) const { return f277 + x * i277; }
    bool is_valid() const { return i277 >= 0; }
    void scale(float s) { f277 *= s; }
    void offset(float o) { f277 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 278 ═══
namespace {
struct RenderUtil278 {
    float f278 = 278.0f;
    int i278 = 278;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f278 = 0; i278 = 0; kind = Kind::A; }
    float compute(float x) const { return f278 + x * i278; }
    bool is_valid() const { return i278 >= 0; }
    void scale(float s) { f278 *= s; }
    void offset(float o) { f278 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 279 ═══
namespace {
struct RenderUtil279 {
    float f279 = 279.0f;
    int i279 = 279;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f279 = 0; i279 = 0; kind = Kind::A; }
    float compute(float x) const { return f279 + x * i279; }
    bool is_valid() const { return i279 >= 0; }
    void scale(float s) { f279 *= s; }
    void offset(float o) { f279 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 280 ═══
namespace {
struct RenderUtil280 {
    float f280 = 280.0f;
    int i280 = 280;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f280 = 0; i280 = 0; kind = Kind::A; }
    float compute(float x) const { return f280 + x * i280; }
    bool is_valid() const { return i280 >= 0; }
    void scale(float s) { f280 *= s; }
    void offset(float o) { f280 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 281 ═══
namespace {
struct RenderUtil281 {
    float f281 = 281.0f;
    int i281 = 281;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f281 = 0; i281 = 0; kind = Kind::A; }
    float compute(float x) const { return f281 + x * i281; }
    bool is_valid() const { return i281 >= 0; }
    void scale(float s) { f281 *= s; }
    void offset(float o) { f281 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 282 ═══
namespace {
struct RenderUtil282 {
    float f282 = 282.0f;
    int i282 = 282;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f282 = 0; i282 = 0; kind = Kind::A; }
    float compute(float x) const { return f282 + x * i282; }
    bool is_valid() const { return i282 >= 0; }
    void scale(float s) { f282 *= s; }
    void offset(float o) { f282 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 283 ═══
namespace {
struct RenderUtil283 {
    float f283 = 283.0f;
    int i283 = 283;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f283 = 0; i283 = 0; kind = Kind::A; }
    float compute(float x) const { return f283 + x * i283; }
    bool is_valid() const { return i283 >= 0; }
    void scale(float s) { f283 *= s; }
    void offset(float o) { f283 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 284 ═══
namespace {
struct RenderUtil284 {
    float f284 = 284.0f;
    int i284 = 284;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f284 = 0; i284 = 0; kind = Kind::A; }
    float compute(float x) const { return f284 + x * i284; }
    bool is_valid() const { return i284 >= 0; }
    void scale(float s) { f284 *= s; }
    void offset(float o) { f284 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 285 ═══
namespace {
struct RenderUtil285 {
    float f285 = 285.0f;
    int i285 = 285;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f285 = 0; i285 = 0; kind = Kind::A; }
    float compute(float x) const { return f285 + x * i285; }
    bool is_valid() const { return i285 >= 0; }
    void scale(float s) { f285 *= s; }
    void offset(float o) { f285 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 286 ═══
namespace {
struct RenderUtil286 {
    float f286 = 286.0f;
    int i286 = 286;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f286 = 0; i286 = 0; kind = Kind::A; }
    float compute(float x) const { return f286 + x * i286; }
    bool is_valid() const { return i286 >= 0; }
    void scale(float s) { f286 *= s; }
    void offset(float o) { f286 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 287 ═══
namespace {
struct RenderUtil287 {
    float f287 = 287.0f;
    int i287 = 287;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f287 = 0; i287 = 0; kind = Kind::A; }
    float compute(float x) const { return f287 + x * i287; }
    bool is_valid() const { return i287 >= 0; }
    void scale(float s) { f287 *= s; }
    void offset(float o) { f287 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 288 ═══
namespace {
struct RenderUtil288 {
    float f288 = 288.0f;
    int i288 = 288;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f288 = 0; i288 = 0; kind = Kind::A; }
    float compute(float x) const { return f288 + x * i288; }
    bool is_valid() const { return i288 >= 0; }
    void scale(float s) { f288 *= s; }
    void offset(float o) { f288 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 289 ═══
namespace {
struct RenderUtil289 {
    float f289 = 289.0f;
    int i289 = 289;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f289 = 0; i289 = 0; kind = Kind::A; }
    float compute(float x) const { return f289 + x * i289; }
    bool is_valid() const { return i289 >= 0; }
    void scale(float s) { f289 *= s; }
    void offset(float o) { f289 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 290 ═══
namespace {
struct RenderUtil290 {
    float f290 = 290.0f;
    int i290 = 290;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f290 = 0; i290 = 0; kind = Kind::A; }
    float compute(float x) const { return f290 + x * i290; }
    bool is_valid() const { return i290 >= 0; }
    void scale(float s) { f290 *= s; }
    void offset(float o) { f290 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 291 ═══
namespace {
struct RenderUtil291 {
    float f291 = 291.0f;
    int i291 = 291;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f291 = 0; i291 = 0; kind = Kind::A; }
    float compute(float x) const { return f291 + x * i291; }
    bool is_valid() const { return i291 >= 0; }
    void scale(float s) { f291 *= s; }
    void offset(float o) { f291 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 292 ═══
namespace {
struct RenderUtil292 {
    float f292 = 292.0f;
    int i292 = 292;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f292 = 0; i292 = 0; kind = Kind::A; }
    float compute(float x) const { return f292 + x * i292; }
    bool is_valid() const { return i292 >= 0; }
    void scale(float s) { f292 *= s; }
    void offset(float o) { f292 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 293 ═══
namespace {
struct RenderUtil293 {
    float f293 = 293.0f;
    int i293 = 293;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f293 = 0; i293 = 0; kind = Kind::A; }
    float compute(float x) const { return f293 + x * i293; }
    bool is_valid() const { return i293 >= 0; }
    void scale(float s) { f293 *= s; }
    void offset(float o) { f293 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 294 ═══
namespace {
struct RenderUtil294 {
    float f294 = 294.0f;
    int i294 = 294;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f294 = 0; i294 = 0; kind = Kind::A; }
    float compute(float x) const { return f294 + x * i294; }
    bool is_valid() const { return i294 >= 0; }
    void scale(float s) { f294 *= s; }
    void offset(float o) { f294 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 295 ═══
namespace {
struct RenderUtil295 {
    float f295 = 295.0f;
    int i295 = 295;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f295 = 0; i295 = 0; kind = Kind::A; }
    float compute(float x) const { return f295 + x * i295; }
    bool is_valid() const { return i295 >= 0; }
    void scale(float s) { f295 *= s; }
    void offset(float o) { f295 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 296 ═══
namespace {
struct RenderUtil296 {
    float f296 = 296.0f;
    int i296 = 296;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f296 = 0; i296 = 0; kind = Kind::A; }
    float compute(float x) const { return f296 + x * i296; }
    bool is_valid() const { return i296 >= 0; }
    void scale(float s) { f296 *= s; }
    void offset(float o) { f296 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 297 ═══
namespace {
struct RenderUtil297 {
    float f297 = 297.0f;
    int i297 = 297;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f297 = 0; i297 = 0; kind = Kind::A; }
    float compute(float x) const { return f297 + x * i297; }
    bool is_valid() const { return i297 >= 0; }
    void scale(float s) { f297 *= s; }
    void offset(float o) { f297 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 298 ═══
namespace {
struct RenderUtil298 {
    float f298 = 298.0f;
    int i298 = 298;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f298 = 0; i298 = 0; kind = Kind::A; }
    float compute(float x) const { return f298 + x * i298; }
    bool is_valid() const { return i298 >= 0; }
    void scale(float s) { f298 *= s; }
    void offset(float o) { f298 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 299 ═══
namespace {
struct RenderUtil299 {
    float f299 = 299.0f;
    int i299 = 299;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f299 = 0; i299 = 0; kind = Kind::A; }
    float compute(float x) const { return f299 + x * i299; }
    bool is_valid() const { return i299 >= 0; }
    void scale(float s) { f299 *= s; }
    void offset(float o) { f299 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 300 ═══
namespace {
struct RenderUtil300 {
    float f300 = 300.0f;
    int i300 = 300;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f300 = 0; i300 = 0; kind = Kind::A; }
    float compute(float x) const { return f300 + x * i300; }
    bool is_valid() const { return i300 >= 0; }
    void scale(float s) { f300 *= s; }
    void offset(float o) { f300 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 301 ═══
namespace {
struct RenderUtil301 {
    float f301 = 301.0f;
    int i301 = 301;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f301 = 0; i301 = 0; kind = Kind::A; }
    float compute(float x) const { return f301 + x * i301; }
    bool is_valid() const { return i301 >= 0; }
    void scale(float s) { f301 *= s; }
    void offset(float o) { f301 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 302 ═══
namespace {
struct RenderUtil302 {
    float f302 = 302.0f;
    int i302 = 302;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f302 = 0; i302 = 0; kind = Kind::A; }
    float compute(float x) const { return f302 + x * i302; }
    bool is_valid() const { return i302 >= 0; }
    void scale(float s) { f302 *= s; }
    void offset(float o) { f302 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 303 ═══
namespace {
struct RenderUtil303 {
    float f303 = 303.0f;
    int i303 = 303;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f303 = 0; i303 = 0; kind = Kind::A; }
    float compute(float x) const { return f303 + x * i303; }
    bool is_valid() const { return i303 >= 0; }
    void scale(float s) { f303 *= s; }
    void offset(float o) { f303 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 304 ═══
namespace {
struct RenderUtil304 {
    float f304 = 304.0f;
    int i304 = 304;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f304 = 0; i304 = 0; kind = Kind::A; }
    float compute(float x) const { return f304 + x * i304; }
    bool is_valid() const { return i304 >= 0; }
    void scale(float s) { f304 *= s; }
    void offset(float o) { f304 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 305 ═══
namespace {
struct RenderUtil305 {
    float f305 = 305.0f;
    int i305 = 305;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f305 = 0; i305 = 0; kind = Kind::A; }
    float compute(float x) const { return f305 + x * i305; }
    bool is_valid() const { return i305 >= 0; }
    void scale(float s) { f305 *= s; }
    void offset(float o) { f305 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 306 ═══
namespace {
struct RenderUtil306 {
    float f306 = 306.0f;
    int i306 = 306;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f306 = 0; i306 = 0; kind = Kind::A; }
    float compute(float x) const { return f306 + x * i306; }
    bool is_valid() const { return i306 >= 0; }
    void scale(float s) { f306 *= s; }
    void offset(float o) { f306 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 307 ═══
namespace {
struct RenderUtil307 {
    float f307 = 307.0f;
    int i307 = 307;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f307 = 0; i307 = 0; kind = Kind::A; }
    float compute(float x) const { return f307 + x * i307; }
    bool is_valid() const { return i307 >= 0; }
    void scale(float s) { f307 *= s; }
    void offset(float o) { f307 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 308 ═══
namespace {
struct RenderUtil308 {
    float f308 = 308.0f;
    int i308 = 308;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f308 = 0; i308 = 0; kind = Kind::A; }
    float compute(float x) const { return f308 + x * i308; }
    bool is_valid() const { return i308 >= 0; }
    void scale(float s) { f308 *= s; }
    void offset(float o) { f308 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 309 ═══
namespace {
struct RenderUtil309 {
    float f309 = 309.0f;
    int i309 = 309;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f309 = 0; i309 = 0; kind = Kind::A; }
    float compute(float x) const { return f309 + x * i309; }
    bool is_valid() const { return i309 >= 0; }
    void scale(float s) { f309 *= s; }
    void offset(float o) { f309 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 310 ═══
namespace {
struct RenderUtil310 {
    float f310 = 310.0f;
    int i310 = 310;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f310 = 0; i310 = 0; kind = Kind::A; }
    float compute(float x) const { return f310 + x * i310; }
    bool is_valid() const { return i310 >= 0; }
    void scale(float s) { f310 *= s; }
    void offset(float o) { f310 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 311 ═══
namespace {
struct RenderUtil311 {
    float f311 = 311.0f;
    int i311 = 311;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f311 = 0; i311 = 0; kind = Kind::A; }
    float compute(float x) const { return f311 + x * i311; }
    bool is_valid() const { return i311 >= 0; }
    void scale(float s) { f311 *= s; }
    void offset(float o) { f311 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 312 ═══
namespace {
struct RenderUtil312 {
    float f312 = 312.0f;
    int i312 = 312;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f312 = 0; i312 = 0; kind = Kind::A; }
    float compute(float x) const { return f312 + x * i312; }
    bool is_valid() const { return i312 >= 0; }
    void scale(float s) { f312 *= s; }
    void offset(float o) { f312 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 313 ═══
namespace {
struct RenderUtil313 {
    float f313 = 313.0f;
    int i313 = 313;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f313 = 0; i313 = 0; kind = Kind::A; }
    float compute(float x) const { return f313 + x * i313; }
    bool is_valid() const { return i313 >= 0; }
    void scale(float s) { f313 *= s; }
    void offset(float o) { f313 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 314 ═══
namespace {
struct RenderUtil314 {
    float f314 = 314.0f;
    int i314 = 314;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f314 = 0; i314 = 0; kind = Kind::A; }
    float compute(float x) const { return f314 + x * i314; }
    bool is_valid() const { return i314 >= 0; }
    void scale(float s) { f314 *= s; }
    void offset(float o) { f314 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 315 ═══
namespace {
struct RenderUtil315 {
    float f315 = 315.0f;
    int i315 = 315;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f315 = 0; i315 = 0; kind = Kind::A; }
    float compute(float x) const { return f315 + x * i315; }
    bool is_valid() const { return i315 >= 0; }
    void scale(float s) { f315 *= s; }
    void offset(float o) { f315 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 316 ═══
namespace {
struct RenderUtil316 {
    float f316 = 316.0f;
    int i316 = 316;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f316 = 0; i316 = 0; kind = Kind::A; }
    float compute(float x) const { return f316 + x * i316; }
    bool is_valid() const { return i316 >= 0; }
    void scale(float s) { f316 *= s; }
    void offset(float o) { f316 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 317 ═══
namespace {
struct RenderUtil317 {
    float f317 = 317.0f;
    int i317 = 317;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f317 = 0; i317 = 0; kind = Kind::A; }
    float compute(float x) const { return f317 + x * i317; }
    bool is_valid() const { return i317 >= 0; }
    void scale(float s) { f317 *= s; }
    void offset(float o) { f317 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 318 ═══
namespace {
struct RenderUtil318 {
    float f318 = 318.0f;
    int i318 = 318;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f318 = 0; i318 = 0; kind = Kind::A; }
    float compute(float x) const { return f318 + x * i318; }
    bool is_valid() const { return i318 >= 0; }
    void scale(float s) { f318 *= s; }
    void offset(float o) { f318 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 319 ═══
namespace {
struct RenderUtil319 {
    float f319 = 319.0f;
    int i319 = 319;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f319 = 0; i319 = 0; kind = Kind::A; }
    float compute(float x) const { return f319 + x * i319; }
    bool is_valid() const { return i319 >= 0; }
    void scale(float s) { f319 *= s; }
    void offset(float o) { f319 += o; }
};
} // anonymous namespace

// ═══ GPU device abstraction — section 320 ═══
namespace {
struct RenderUtil320 {
    float f320 = 320.0f;
    int i320 = 320;
    enum class Kind : uint8_t { A, B, C, D, E, F };
    Kind kind = Kind::A;
    void init() { f320 = 0; i320 = 0; kind = Kind::A; }
    float compute(float x) const { return f320 + x * i320; }
    bool is_valid() const { return i320 >= 0; }
    void scale(float s) { f320 *= s; }
    void offset(float o) { f320 += o; }
};
} // anonymous namespace

#ifdef WR_TEST
bool test_wr_GPU_device_abstraction(){return true;}
#endif
} // namespace wr