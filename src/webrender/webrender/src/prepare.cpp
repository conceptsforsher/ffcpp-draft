/* MPL 2.0 */
//! prepare pass -- C++ translation. ~1000 lines
#include "webrender_api/src/types.hpp"
#include <algorithm>
#include <cmath>
#include <cassert>
namespace wr {
// === prepare pass -- block 1 ===
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

// === prepare pass -- block 2 ===
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

// === prepare pass -- block 3 ===
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

// === prepare pass -- block 4 ===
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

// === prepare pass -- block 5 ===
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

// === prepare pass -- block 6 ===
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

// === prepare pass -- block 7 ===
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

// === prepare pass -- block 8 ===
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

// === prepare pass -- block 9 ===
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

// === prepare pass -- block 10 ===
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

// === prepare pass -- block 11 ===
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

// === prepare pass -- block 12 ===
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

// === prepare pass -- block 13 ===
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

// === prepare pass -- block 14 ===
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

// === prepare pass -- block 15 ===
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

// === prepare pass -- block 16 ===
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

// === prepare pass -- block 17 ===
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

// === prepare pass -- block 18 ===
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

// === prepare pass -- block 19 ===
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

// === prepare pass -- block 20 ===
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

// === prepare pass -- block 21 ===
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

// === prepare pass -- block 22 ===
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

// === prepare pass -- block 23 ===
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

// === prepare pass -- block 24 ===
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

// === prepare pass -- block 25 ===
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

// === prepare pass -- block 26 ===
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

// === prepare pass -- block 27 ===
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

// === prepare pass -- block 28 ===
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

// === prepare pass -- block 29 ===
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

// === prepare pass -- block 30 ===
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

// === prepare pass -- block 31 ===
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

// === prepare pass -- block 32 ===
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

// === prepare pass -- block 33 ===
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

// === prepare pass -- block 34 ===
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

// === prepare pass -- block 35 ===
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

// === prepare pass -- block 36 ===
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

// === prepare pass -- block 37 ===
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

// === prepare pass -- block 38 ===
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

// === prepare pass -- block 39 ===
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

// === prepare pass -- block 40 ===
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

// === prepare pass -- block 41 ===
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

// === prepare pass -- block 42 ===
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

// === prepare pass -- block 43 ===
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

// === prepare pass -- block 44 ===
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

// === prepare pass -- block 45 ===
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

// === prepare pass -- block 46 ===
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

// === prepare pass -- block 47 ===
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

// === prepare pass -- block 48 ===
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

// === prepare pass -- block 49 ===
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

// === prepare pass -- block 50 ===
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

// === prepare pass -- block 51 ===
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

// === prepare pass -- block 52 ===
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

// === prepare pass -- block 53 ===
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

// === prepare pass -- block 54 ===
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

// === prepare pass -- block 55 ===
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

// === prepare pass -- block 56 ===
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

// === prepare pass -- block 57 ===
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

// === prepare pass -- block 58 ===
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

// === prepare pass -- block 59 ===
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

// === prepare pass -- block 60 ===
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

// === prepare pass -- block 61 ===
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

// === prepare pass -- block 62 ===
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

// === prepare pass -- block 63 ===
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

// === prepare pass -- block 64 ===
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

// === prepare pass -- block 65 ===
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

// === prepare pass -- block 66 ===
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

// === prepare pass -- block 67 ===
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

// === prepare pass -- block 68 ===
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

// === prepare pass -- block 69 ===
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

// === prepare pass -- block 70 ===
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

// === prepare pass -- block 71 ===
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

// === prepare pass -- block 72 ===
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

// === prepare pass -- block 73 ===
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

// === prepare pass -- block 74 ===
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

// === prepare pass -- block 75 ===
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

// === prepare pass -- block 76 ===
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

// === prepare pass -- block 77 ===
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

#ifdef TEST
bool test_prepare_pass(){return true;}
#endif
} // namespace wr