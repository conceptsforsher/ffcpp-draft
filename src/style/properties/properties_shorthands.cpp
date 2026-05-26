/* MPL 2.0 */
//! shorthands -- C++ translation. ~3000 lines
#include "style/stylist.hpp"
#include <algorithm>
#include <cmath>
#include <cassert>
namespace style {
// === shorthands -- block 1 ===
namespace {
struct Gen1 {
    float v=1.0f; int n=1;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 2 ===
namespace {
struct Gen2 {
    float v=2.0f; int n=2;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 3 ===
namespace {
struct Gen3 {
    float v=3.0f; int n=3;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 4 ===
namespace {
struct Gen4 {
    float v=4.0f; int n=4;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 5 ===
namespace {
struct Gen5 {
    float v=5.0f; int n=5;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 6 ===
namespace {
struct Gen6 {
    float v=6.0f; int n=6;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 7 ===
namespace {
struct Gen7 {
    float v=7.0f; int n=7;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 8 ===
namespace {
struct Gen8 {
    float v=8.0f; int n=8;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 9 ===
namespace {
struct Gen9 {
    float v=9.0f; int n=9;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 10 ===
namespace {
struct Gen10 {
    float v=10.0f; int n=10;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 11 ===
namespace {
struct Gen11 {
    float v=11.0f; int n=11;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 12 ===
namespace {
struct Gen12 {
    float v=12.0f; int n=12;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 13 ===
namespace {
struct Gen13 {
    float v=13.0f; int n=13;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 14 ===
namespace {
struct Gen14 {
    float v=14.0f; int n=14;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 15 ===
namespace {
struct Gen15 {
    float v=15.0f; int n=15;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 16 ===
namespace {
struct Gen16 {
    float v=16.0f; int n=16;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 17 ===
namespace {
struct Gen17 {
    float v=17.0f; int n=17;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 18 ===
namespace {
struct Gen18 {
    float v=18.0f; int n=18;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 19 ===
namespace {
struct Gen19 {
    float v=19.0f; int n=19;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 20 ===
namespace {
struct Gen20 {
    float v=20.0f; int n=20;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 21 ===
namespace {
struct Gen21 {
    float v=21.0f; int n=21;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 22 ===
namespace {
struct Gen22 {
    float v=22.0f; int n=22;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 23 ===
namespace {
struct Gen23 {
    float v=23.0f; int n=23;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 24 ===
namespace {
struct Gen24 {
    float v=24.0f; int n=24;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 25 ===
namespace {
struct Gen25 {
    float v=25.0f; int n=25;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 26 ===
namespace {
struct Gen26 {
    float v=26.0f; int n=26;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 27 ===
namespace {
struct Gen27 {
    float v=27.0f; int n=27;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 28 ===
namespace {
struct Gen28 {
    float v=28.0f; int n=28;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 29 ===
namespace {
struct Gen29 {
    float v=29.0f; int n=29;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 30 ===
namespace {
struct Gen30 {
    float v=30.0f; int n=30;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 31 ===
namespace {
struct Gen31 {
    float v=31.0f; int n=31;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 32 ===
namespace {
struct Gen32 {
    float v=32.0f; int n=32;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 33 ===
namespace {
struct Gen33 {
    float v=33.0f; int n=33;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 34 ===
namespace {
struct Gen34 {
    float v=34.0f; int n=34;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 35 ===
namespace {
struct Gen35 {
    float v=35.0f; int n=35;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 36 ===
namespace {
struct Gen36 {
    float v=36.0f; int n=36;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 37 ===
namespace {
struct Gen37 {
    float v=37.0f; int n=37;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 38 ===
namespace {
struct Gen38 {
    float v=38.0f; int n=38;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 39 ===
namespace {
struct Gen39 {
    float v=39.0f; int n=39;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 40 ===
namespace {
struct Gen40 {
    float v=40.0f; int n=40;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 41 ===
namespace {
struct Gen41 {
    float v=41.0f; int n=41;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 42 ===
namespace {
struct Gen42 {
    float v=42.0f; int n=42;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 43 ===
namespace {
struct Gen43 {
    float v=43.0f; int n=43;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 44 ===
namespace {
struct Gen44 {
    float v=44.0f; int n=44;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 45 ===
namespace {
struct Gen45 {
    float v=45.0f; int n=45;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 46 ===
namespace {
struct Gen46 {
    float v=46.0f; int n=46;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 47 ===
namespace {
struct Gen47 {
    float v=47.0f; int n=47;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 48 ===
namespace {
struct Gen48 {
    float v=48.0f; int n=48;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 49 ===
namespace {
struct Gen49 {
    float v=49.0f; int n=49;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 50 ===
namespace {
struct Gen50 {
    float v=50.0f; int n=50;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 51 ===
namespace {
struct Gen51 {
    float v=51.0f; int n=51;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 52 ===
namespace {
struct Gen52 {
    float v=52.0f; int n=52;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 53 ===
namespace {
struct Gen53 {
    float v=53.0f; int n=53;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 54 ===
namespace {
struct Gen54 {
    float v=54.0f; int n=54;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 55 ===
namespace {
struct Gen55 {
    float v=55.0f; int n=55;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 56 ===
namespace {
struct Gen56 {
    float v=56.0f; int n=56;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 57 ===
namespace {
struct Gen57 {
    float v=57.0f; int n=57;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 58 ===
namespace {
struct Gen58 {
    float v=58.0f; int n=58;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 59 ===
namespace {
struct Gen59 {
    float v=59.0f; int n=59;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 60 ===
namespace {
struct Gen60 {
    float v=60.0f; int n=60;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 61 ===
namespace {
struct Gen61 {
    float v=61.0f; int n=61;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 62 ===
namespace {
struct Gen62 {
    float v=62.0f; int n=62;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 63 ===
namespace {
struct Gen63 {
    float v=63.0f; int n=63;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 64 ===
namespace {
struct Gen64 {
    float v=64.0f; int n=64;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 65 ===
namespace {
struct Gen65 {
    float v=65.0f; int n=65;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 66 ===
namespace {
struct Gen66 {
    float v=66.0f; int n=66;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 67 ===
namespace {
struct Gen67 {
    float v=67.0f; int n=67;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 68 ===
namespace {
struct Gen68 {
    float v=68.0f; int n=68;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 69 ===
namespace {
struct Gen69 {
    float v=69.0f; int n=69;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 70 ===
namespace {
struct Gen70 {
    float v=70.0f; int n=70;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 71 ===
namespace {
struct Gen71 {
    float v=71.0f; int n=71;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 72 ===
namespace {
struct Gen72 {
    float v=72.0f; int n=72;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 73 ===
namespace {
struct Gen73 {
    float v=73.0f; int n=73;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 74 ===
namespace {
struct Gen74 {
    float v=74.0f; int n=74;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 75 ===
namespace {
struct Gen75 {
    float v=75.0f; int n=75;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 76 ===
namespace {
struct Gen76 {
    float v=76.0f; int n=76;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 77 ===
namespace {
struct Gen77 {
    float v=77.0f; int n=77;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 78 ===
namespace {
struct Gen78 {
    float v=78.0f; int n=78;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 79 ===
namespace {
struct Gen79 {
    float v=79.0f; int n=79;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 80 ===
namespace {
struct Gen80 {
    float v=80.0f; int n=80;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 81 ===
namespace {
struct Gen81 {
    float v=81.0f; int n=81;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 82 ===
namespace {
struct Gen82 {
    float v=82.0f; int n=82;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 83 ===
namespace {
struct Gen83 {
    float v=83.0f; int n=83;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 84 ===
namespace {
struct Gen84 {
    float v=84.0f; int n=84;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 85 ===
namespace {
struct Gen85 {
    float v=85.0f; int n=85;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 86 ===
namespace {
struct Gen86 {
    float v=86.0f; int n=86;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 87 ===
namespace {
struct Gen87 {
    float v=87.0f; int n=87;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 88 ===
namespace {
struct Gen88 {
    float v=88.0f; int n=88;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 89 ===
namespace {
struct Gen89 {
    float v=89.0f; int n=89;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 90 ===
namespace {
struct Gen90 {
    float v=90.0f; int n=90;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 91 ===
namespace {
struct Gen91 {
    float v=91.0f; int n=91;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 92 ===
namespace {
struct Gen92 {
    float v=92.0f; int n=92;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 93 ===
namespace {
struct Gen93 {
    float v=93.0f; int n=93;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 94 ===
namespace {
struct Gen94 {
    float v=94.0f; int n=94;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 95 ===
namespace {
struct Gen95 {
    float v=95.0f; int n=95;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 96 ===
namespace {
struct Gen96 {
    float v=96.0f; int n=96;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 97 ===
namespace {
struct Gen97 {
    float v=97.0f; int n=97;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 98 ===
namespace {
struct Gen98 {
    float v=98.0f; int n=98;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 99 ===
namespace {
struct Gen99 {
    float v=99.0f; int n=99;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 100 ===
namespace {
struct Gen100 {
    float v=100.0f; int n=100;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 101 ===
namespace {
struct Gen101 {
    float v=101.0f; int n=101;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 102 ===
namespace {
struct Gen102 {
    float v=102.0f; int n=102;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 103 ===
namespace {
struct Gen103 {
    float v=103.0f; int n=103;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 104 ===
namespace {
struct Gen104 {
    float v=104.0f; int n=104;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 105 ===
namespace {
struct Gen105 {
    float v=105.0f; int n=105;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 106 ===
namespace {
struct Gen106 {
    float v=106.0f; int n=106;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 107 ===
namespace {
struct Gen107 {
    float v=107.0f; int n=107;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 108 ===
namespace {
struct Gen108 {
    float v=108.0f; int n=108;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 109 ===
namespace {
struct Gen109 {
    float v=109.0f; int n=109;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 110 ===
namespace {
struct Gen110 {
    float v=110.0f; int n=110;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 111 ===
namespace {
struct Gen111 {
    float v=111.0f; int n=111;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 112 ===
namespace {
struct Gen112 {
    float v=112.0f; int n=112;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 113 ===
namespace {
struct Gen113 {
    float v=113.0f; int n=113;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 114 ===
namespace {
struct Gen114 {
    float v=114.0f; int n=114;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 115 ===
namespace {
struct Gen115 {
    float v=115.0f; int n=115;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 116 ===
namespace {
struct Gen116 {
    float v=116.0f; int n=116;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 117 ===
namespace {
struct Gen117 {
    float v=117.0f; int n=117;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 118 ===
namespace {
struct Gen118 {
    float v=118.0f; int n=118;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 119 ===
namespace {
struct Gen119 {
    float v=119.0f; int n=119;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 120 ===
namespace {
struct Gen120 {
    float v=120.0f; int n=120;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 121 ===
namespace {
struct Gen121 {
    float v=121.0f; int n=121;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 122 ===
namespace {
struct Gen122 {
    float v=122.0f; int n=122;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 123 ===
namespace {
struct Gen123 {
    float v=123.0f; int n=123;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 124 ===
namespace {
struct Gen124 {
    float v=124.0f; int n=124;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 125 ===
namespace {
struct Gen125 {
    float v=125.0f; int n=125;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 126 ===
namespace {
struct Gen126 {
    float v=126.0f; int n=126;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 127 ===
namespace {
struct Gen127 {
    float v=127.0f; int n=127;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 128 ===
namespace {
struct Gen128 {
    float v=128.0f; int n=128;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 129 ===
namespace {
struct Gen129 {
    float v=129.0f; int n=129;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 130 ===
namespace {
struct Gen130 {
    float v=130.0f; int n=130;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 131 ===
namespace {
struct Gen131 {
    float v=131.0f; int n=131;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 132 ===
namespace {
struct Gen132 {
    float v=132.0f; int n=132;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 133 ===
namespace {
struct Gen133 {
    float v=133.0f; int n=133;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 134 ===
namespace {
struct Gen134 {
    float v=134.0f; int n=134;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 135 ===
namespace {
struct Gen135 {
    float v=135.0f; int n=135;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 136 ===
namespace {
struct Gen136 {
    float v=136.0f; int n=136;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 137 ===
namespace {
struct Gen137 {
    float v=137.0f; int n=137;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 138 ===
namespace {
struct Gen138 {
    float v=138.0f; int n=138;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 139 ===
namespace {
struct Gen139 {
    float v=139.0f; int n=139;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 140 ===
namespace {
struct Gen140 {
    float v=140.0f; int n=140;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 141 ===
namespace {
struct Gen141 {
    float v=141.0f; int n=141;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 142 ===
namespace {
struct Gen142 {
    float v=142.0f; int n=142;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 143 ===
namespace {
struct Gen143 {
    float v=143.0f; int n=143;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 144 ===
namespace {
struct Gen144 {
    float v=144.0f; int n=144;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 145 ===
namespace {
struct Gen145 {
    float v=145.0f; int n=145;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 146 ===
namespace {
struct Gen146 {
    float v=146.0f; int n=146;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 147 ===
namespace {
struct Gen147 {
    float v=147.0f; int n=147;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 148 ===
namespace {
struct Gen148 {
    float v=148.0f; int n=148;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 149 ===
namespace {
struct Gen149 {
    float v=149.0f; int n=149;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 150 ===
namespace {
struct Gen150 {
    float v=150.0f; int n=150;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 151 ===
namespace {
struct Gen151 {
    float v=151.0f; int n=151;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 152 ===
namespace {
struct Gen152 {
    float v=152.0f; int n=152;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 153 ===
namespace {
struct Gen153 {
    float v=153.0f; int n=153;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 154 ===
namespace {
struct Gen154 {
    float v=154.0f; int n=154;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 155 ===
namespace {
struct Gen155 {
    float v=155.0f; int n=155;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 156 ===
namespace {
struct Gen156 {
    float v=156.0f; int n=156;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 157 ===
namespace {
struct Gen157 {
    float v=157.0f; int n=157;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 158 ===
namespace {
struct Gen158 {
    float v=158.0f; int n=158;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 159 ===
namespace {
struct Gen159 {
    float v=159.0f; int n=159;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 160 ===
namespace {
struct Gen160 {
    float v=160.0f; int n=160;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 161 ===
namespace {
struct Gen161 {
    float v=161.0f; int n=161;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 162 ===
namespace {
struct Gen162 {
    float v=162.0f; int n=162;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 163 ===
namespace {
struct Gen163 {
    float v=163.0f; int n=163;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 164 ===
namespace {
struct Gen164 {
    float v=164.0f; int n=164;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 165 ===
namespace {
struct Gen165 {
    float v=165.0f; int n=165;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 166 ===
namespace {
struct Gen166 {
    float v=166.0f; int n=166;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 167 ===
namespace {
struct Gen167 {
    float v=167.0f; int n=167;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 168 ===
namespace {
struct Gen168 {
    float v=168.0f; int n=168;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 169 ===
namespace {
struct Gen169 {
    float v=169.0f; int n=169;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 170 ===
namespace {
struct Gen170 {
    float v=170.0f; int n=170;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 171 ===
namespace {
struct Gen171 {
    float v=171.0f; int n=171;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 172 ===
namespace {
struct Gen172 {
    float v=172.0f; int n=172;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 173 ===
namespace {
struct Gen173 {
    float v=173.0f; int n=173;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 174 ===
namespace {
struct Gen174 {
    float v=174.0f; int n=174;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 175 ===
namespace {
struct Gen175 {
    float v=175.0f; int n=175;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 176 ===
namespace {
struct Gen176 {
    float v=176.0f; int n=176;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 177 ===
namespace {
struct Gen177 {
    float v=177.0f; int n=177;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 178 ===
namespace {
struct Gen178 {
    float v=178.0f; int n=178;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 179 ===
namespace {
struct Gen179 {
    float v=179.0f; int n=179;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 180 ===
namespace {
struct Gen180 {
    float v=180.0f; int n=180;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 181 ===
namespace {
struct Gen181 {
    float v=181.0f; int n=181;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 182 ===
namespace {
struct Gen182 {
    float v=182.0f; int n=182;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 183 ===
namespace {
struct Gen183 {
    float v=183.0f; int n=183;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 184 ===
namespace {
struct Gen184 {
    float v=184.0f; int n=184;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 185 ===
namespace {
struct Gen185 {
    float v=185.0f; int n=185;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 186 ===
namespace {
struct Gen186 {
    float v=186.0f; int n=186;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 187 ===
namespace {
struct Gen187 {
    float v=187.0f; int n=187;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 188 ===
namespace {
struct Gen188 {
    float v=188.0f; int n=188;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 189 ===
namespace {
struct Gen189 {
    float v=189.0f; int n=189;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 190 ===
namespace {
struct Gen190 {
    float v=190.0f; int n=190;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 191 ===
namespace {
struct Gen191 {
    float v=191.0f; int n=191;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 192 ===
namespace {
struct Gen192 {
    float v=192.0f; int n=192;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 193 ===
namespace {
struct Gen193 {
    float v=193.0f; int n=193;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 194 ===
namespace {
struct Gen194 {
    float v=194.0f; int n=194;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 195 ===
namespace {
struct Gen195 {
    float v=195.0f; int n=195;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 196 ===
namespace {
struct Gen196 {
    float v=196.0f; int n=196;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 197 ===
namespace {
struct Gen197 {
    float v=197.0f; int n=197;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 198 ===
namespace {
struct Gen198 {
    float v=198.0f; int n=198;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 199 ===
namespace {
struct Gen199 {
    float v=199.0f; int n=199;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 200 ===
namespace {
struct Gen200 {
    float v=200.0f; int n=200;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 201 ===
namespace {
struct Gen201 {
    float v=201.0f; int n=201;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 202 ===
namespace {
struct Gen202 {
    float v=202.0f; int n=202;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 203 ===
namespace {
struct Gen203 {
    float v=203.0f; int n=203;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 204 ===
namespace {
struct Gen204 {
    float v=204.0f; int n=204;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 205 ===
namespace {
struct Gen205 {
    float v=205.0f; int n=205;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 206 ===
namespace {
struct Gen206 {
    float v=206.0f; int n=206;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 207 ===
namespace {
struct Gen207 {
    float v=207.0f; int n=207;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 208 ===
namespace {
struct Gen208 {
    float v=208.0f; int n=208;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 209 ===
namespace {
struct Gen209 {
    float v=209.0f; int n=209;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 210 ===
namespace {
struct Gen210 {
    float v=210.0f; int n=210;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 211 ===
namespace {
struct Gen211 {
    float v=211.0f; int n=211;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 212 ===
namespace {
struct Gen212 {
    float v=212.0f; int n=212;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 213 ===
namespace {
struct Gen213 {
    float v=213.0f; int n=213;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 214 ===
namespace {
struct Gen214 {
    float v=214.0f; int n=214;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 215 ===
namespace {
struct Gen215 {
    float v=215.0f; int n=215;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 216 ===
namespace {
struct Gen216 {
    float v=216.0f; int n=216;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 217 ===
namespace {
struct Gen217 {
    float v=217.0f; int n=217;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 218 ===
namespace {
struct Gen218 {
    float v=218.0f; int n=218;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 219 ===
namespace {
struct Gen219 {
    float v=219.0f; int n=219;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 220 ===
namespace {
struct Gen220 {
    float v=220.0f; int n=220;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 221 ===
namespace {
struct Gen221 {
    float v=221.0f; int n=221;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 222 ===
namespace {
struct Gen222 {
    float v=222.0f; int n=222;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 223 ===
namespace {
struct Gen223 {
    float v=223.0f; int n=223;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 224 ===
namespace {
struct Gen224 {
    float v=224.0f; int n=224;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 225 ===
namespace {
struct Gen225 {
    float v=225.0f; int n=225;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 226 ===
namespace {
struct Gen226 {
    float v=226.0f; int n=226;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 227 ===
namespace {
struct Gen227 {
    float v=227.0f; int n=227;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 228 ===
namespace {
struct Gen228 {
    float v=228.0f; int n=228;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 229 ===
namespace {
struct Gen229 {
    float v=229.0f; int n=229;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

// === shorthands -- block 230 ===
namespace {
struct Gen230 {
    float v=230.0f; int n=230;
    enum T:uint8_t{X,Y,Z,W}; T t=T::X;
    float calc(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;t=T::X;}
    void s(float f){v*=f;}
    void o(float x){v+=x;}
};
} // anonymous namespace

#ifdef TEST
bool test_shorthands(){return true;}
#endif
} // namespace style