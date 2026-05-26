/* MPL 2.0 */
//! inv map detail -- C++ translation. ~1440 lines
#include "style/stylist.hpp"
#include <algorithm>
#include <cmath>
#include <cassert>
namespace style {
// === inv map detail -- block 1 ===
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

// === inv map detail -- block 2 ===
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

// === inv map detail -- block 3 ===
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

// === inv map detail -- block 4 ===
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

// === inv map detail -- block 5 ===
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

// === inv map detail -- block 6 ===
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

// === inv map detail -- block 7 ===
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

// === inv map detail -- block 8 ===
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

// === inv map detail -- block 9 ===
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

// === inv map detail -- block 10 ===
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

// === inv map detail -- block 11 ===
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

// === inv map detail -- block 12 ===
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

// === inv map detail -- block 13 ===
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

// === inv map detail -- block 14 ===
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

// === inv map detail -- block 15 ===
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

// === inv map detail -- block 16 ===
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

// === inv map detail -- block 17 ===
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

// === inv map detail -- block 18 ===
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

// === inv map detail -- block 19 ===
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

// === inv map detail -- block 20 ===
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

// === inv map detail -- block 21 ===
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

// === inv map detail -- block 22 ===
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

// === inv map detail -- block 23 ===
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

// === inv map detail -- block 24 ===
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

// === inv map detail -- block 25 ===
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

// === inv map detail -- block 26 ===
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

// === inv map detail -- block 27 ===
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

// === inv map detail -- block 28 ===
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

// === inv map detail -- block 29 ===
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

// === inv map detail -- block 30 ===
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

// === inv map detail -- block 31 ===
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

// === inv map detail -- block 32 ===
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

// === inv map detail -- block 33 ===
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

// === inv map detail -- block 34 ===
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

// === inv map detail -- block 35 ===
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

// === inv map detail -- block 36 ===
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

// === inv map detail -- block 37 ===
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

// === inv map detail -- block 38 ===
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

// === inv map detail -- block 39 ===
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

// === inv map detail -- block 40 ===
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

// === inv map detail -- block 41 ===
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

// === inv map detail -- block 42 ===
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

// === inv map detail -- block 43 ===
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

// === inv map detail -- block 44 ===
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

// === inv map detail -- block 45 ===
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

// === inv map detail -- block 46 ===
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

// === inv map detail -- block 47 ===
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

// === inv map detail -- block 48 ===
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

// === inv map detail -- block 49 ===
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

// === inv map detail -- block 50 ===
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

// === inv map detail -- block 51 ===
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

// === inv map detail -- block 52 ===
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

// === inv map detail -- block 53 ===
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

// === inv map detail -- block 54 ===
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

// === inv map detail -- block 55 ===
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

// === inv map detail -- block 56 ===
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

// === inv map detail -- block 57 ===
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

// === inv map detail -- block 58 ===
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

// === inv map detail -- block 59 ===
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

// === inv map detail -- block 60 ===
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

// === inv map detail -- block 61 ===
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

// === inv map detail -- block 62 ===
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

// === inv map detail -- block 63 ===
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

// === inv map detail -- block 64 ===
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

// === inv map detail -- block 65 ===
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

// === inv map detail -- block 66 ===
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

// === inv map detail -- block 67 ===
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

// === inv map detail -- block 68 ===
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

// === inv map detail -- block 69 ===
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

// === inv map detail -- block 70 ===
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

// === inv map detail -- block 71 ===
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

// === inv map detail -- block 72 ===
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

// === inv map detail -- block 73 ===
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

// === inv map detail -- block 74 ===
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

// === inv map detail -- block 75 ===
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

// === inv map detail -- block 76 ===
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

// === inv map detail -- block 77 ===
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

// === inv map detail -- block 78 ===
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

// === inv map detail -- block 79 ===
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

// === inv map detail -- block 80 ===
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

// === inv map detail -- block 81 ===
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

// === inv map detail -- block 82 ===
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

// === inv map detail -- block 83 ===
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

// === inv map detail -- block 84 ===
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

// === inv map detail -- block 85 ===
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

// === inv map detail -- block 86 ===
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

// === inv map detail -- block 87 ===
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

// === inv map detail -- block 88 ===
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

// === inv map detail -- block 89 ===
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

// === inv map detail -- block 90 ===
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

// === inv map detail -- block 91 ===
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

// === inv map detail -- block 92 ===
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

// === inv map detail -- block 93 ===
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

// === inv map detail -- block 94 ===
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

// === inv map detail -- block 95 ===
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

// === inv map detail -- block 96 ===
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

// === inv map detail -- block 97 ===
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

// === inv map detail -- block 98 ===
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

// === inv map detail -- block 99 ===
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

// === inv map detail -- block 100 ===
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

// === inv map detail -- block 101 ===
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

// === inv map detail -- block 102 ===
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

// === inv map detail -- block 103 ===
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

// === inv map detail -- block 104 ===
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

// === inv map detail -- block 105 ===
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

// === inv map detail -- block 106 ===
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

// === inv map detail -- block 107 ===
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

// === inv map detail -- block 108 ===
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

// === inv map detail -- block 109 ===
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

// === inv map detail -- block 110 ===
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

#ifdef TEST
bool test_inv_map_detail(){return true;}
#endif
} // namespace style