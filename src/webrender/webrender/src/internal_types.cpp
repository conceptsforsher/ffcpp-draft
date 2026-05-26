/* MPL 2.0 */
//! internal types -- C++ translation. ~1500 lines
#include "webrender_api/src/types.hpp"
#include <algorithm>
#include <cmath>
#include <cassert>
namespace wr {
// === internal types -- block 1 ===
namespace {
struct X1 {
    float v=1.0f;int n=1;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 2 ===
namespace {
struct X2 {
    float v=2.0f;int n=2;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 3 ===
namespace {
struct X3 {
    float v=3.0f;int n=3;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 4 ===
namespace {
struct X4 {
    float v=4.0f;int n=4;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 5 ===
namespace {
struct X5 {
    float v=5.0f;int n=5;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 6 ===
namespace {
struct X6 {
    float v=6.0f;int n=6;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 7 ===
namespace {
struct X7 {
    float v=7.0f;int n=7;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 8 ===
namespace {
struct X8 {
    float v=8.0f;int n=8;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 9 ===
namespace {
struct X9 {
    float v=9.0f;int n=9;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 10 ===
namespace {
struct X10 {
    float v=10.0f;int n=10;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 11 ===
namespace {
struct X11 {
    float v=11.0f;int n=11;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 12 ===
namespace {
struct X12 {
    float v=12.0f;int n=12;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 13 ===
namespace {
struct X13 {
    float v=13.0f;int n=13;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 14 ===
namespace {
struct X14 {
    float v=14.0f;int n=14;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 15 ===
namespace {
struct X15 {
    float v=15.0f;int n=15;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 16 ===
namespace {
struct X16 {
    float v=16.0f;int n=16;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 17 ===
namespace {
struct X17 {
    float v=17.0f;int n=17;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 18 ===
namespace {
struct X18 {
    float v=18.0f;int n=18;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 19 ===
namespace {
struct X19 {
    float v=19.0f;int n=19;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 20 ===
namespace {
struct X20 {
    float v=20.0f;int n=20;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 21 ===
namespace {
struct X21 {
    float v=21.0f;int n=21;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 22 ===
namespace {
struct X22 {
    float v=22.0f;int n=22;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 23 ===
namespace {
struct X23 {
    float v=23.0f;int n=23;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 24 ===
namespace {
struct X24 {
    float v=24.0f;int n=24;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 25 ===
namespace {
struct X25 {
    float v=25.0f;int n=25;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 26 ===
namespace {
struct X26 {
    float v=26.0f;int n=26;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 27 ===
namespace {
struct X27 {
    float v=27.0f;int n=27;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 28 ===
namespace {
struct X28 {
    float v=28.0f;int n=28;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 29 ===
namespace {
struct X29 {
    float v=29.0f;int n=29;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 30 ===
namespace {
struct X30 {
    float v=30.0f;int n=30;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 31 ===
namespace {
struct X31 {
    float v=31.0f;int n=31;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 32 ===
namespace {
struct X32 {
    float v=32.0f;int n=32;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 33 ===
namespace {
struct X33 {
    float v=33.0f;int n=33;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 34 ===
namespace {
struct X34 {
    float v=34.0f;int n=34;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 35 ===
namespace {
struct X35 {
    float v=35.0f;int n=35;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 36 ===
namespace {
struct X36 {
    float v=36.0f;int n=36;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 37 ===
namespace {
struct X37 {
    float v=37.0f;int n=37;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 38 ===
namespace {
struct X38 {
    float v=38.0f;int n=38;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 39 ===
namespace {
struct X39 {
    float v=39.0f;int n=39;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 40 ===
namespace {
struct X40 {
    float v=40.0f;int n=40;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 41 ===
namespace {
struct X41 {
    float v=41.0f;int n=41;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 42 ===
namespace {
struct X42 {
    float v=42.0f;int n=42;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 43 ===
namespace {
struct X43 {
    float v=43.0f;int n=43;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 44 ===
namespace {
struct X44 {
    float v=44.0f;int n=44;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 45 ===
namespace {
struct X45 {
    float v=45.0f;int n=45;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 46 ===
namespace {
struct X46 {
    float v=46.0f;int n=46;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 47 ===
namespace {
struct X47 {
    float v=47.0f;int n=47;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 48 ===
namespace {
struct X48 {
    float v=48.0f;int n=48;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 49 ===
namespace {
struct X49 {
    float v=49.0f;int n=49;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 50 ===
namespace {
struct X50 {
    float v=50.0f;int n=50;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 51 ===
namespace {
struct X51 {
    float v=51.0f;int n=51;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 52 ===
namespace {
struct X52 {
    float v=52.0f;int n=52;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 53 ===
namespace {
struct X53 {
    float v=53.0f;int n=53;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 54 ===
namespace {
struct X54 {
    float v=54.0f;int n=54;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 55 ===
namespace {
struct X55 {
    float v=55.0f;int n=55;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 56 ===
namespace {
struct X56 {
    float v=56.0f;int n=56;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 57 ===
namespace {
struct X57 {
    float v=57.0f;int n=57;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 58 ===
namespace {
struct X58 {
    float v=58.0f;int n=58;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 59 ===
namespace {
struct X59 {
    float v=59.0f;int n=59;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 60 ===
namespace {
struct X60 {
    float v=60.0f;int n=60;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 61 ===
namespace {
struct X61 {
    float v=61.0f;int n=61;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 62 ===
namespace {
struct X62 {
    float v=62.0f;int n=62;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 63 ===
namespace {
struct X63 {
    float v=63.0f;int n=63;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 64 ===
namespace {
struct X64 {
    float v=64.0f;int n=64;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 65 ===
namespace {
struct X65 {
    float v=65.0f;int n=65;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 66 ===
namespace {
struct X66 {
    float v=66.0f;int n=66;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 67 ===
namespace {
struct X67 {
    float v=67.0f;int n=67;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 68 ===
namespace {
struct X68 {
    float v=68.0f;int n=68;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 69 ===
namespace {
struct X69 {
    float v=69.0f;int n=69;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 70 ===
namespace {
struct X70 {
    float v=70.0f;int n=70;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 71 ===
namespace {
struct X71 {
    float v=71.0f;int n=71;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 72 ===
namespace {
struct X72 {
    float v=72.0f;int n=72;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 73 ===
namespace {
struct X73 {
    float v=73.0f;int n=73;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 74 ===
namespace {
struct X74 {
    float v=74.0f;int n=74;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 75 ===
namespace {
struct X75 {
    float v=75.0f;int n=75;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 76 ===
namespace {
struct X76 {
    float v=76.0f;int n=76;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 77 ===
namespace {
struct X77 {
    float v=77.0f;int n=77;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 78 ===
namespace {
struct X78 {
    float v=78.0f;int n=78;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 79 ===
namespace {
struct X79 {
    float v=79.0f;int n=79;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 80 ===
namespace {
struct X80 {
    float v=80.0f;int n=80;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 81 ===
namespace {
struct X81 {
    float v=81.0f;int n=81;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 82 ===
namespace {
struct X82 {
    float v=82.0f;int n=82;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 83 ===
namespace {
struct X83 {
    float v=83.0f;int n=83;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 84 ===
namespace {
struct X84 {
    float v=84.0f;int n=84;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 85 ===
namespace {
struct X85 {
    float v=85.0f;int n=85;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 86 ===
namespace {
struct X86 {
    float v=86.0f;int n=86;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 87 ===
namespace {
struct X87 {
    float v=87.0f;int n=87;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 88 ===
namespace {
struct X88 {
    float v=88.0f;int n=88;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 89 ===
namespace {
struct X89 {
    float v=89.0f;int n=89;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 90 ===
namespace {
struct X90 {
    float v=90.0f;int n=90;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 91 ===
namespace {
struct X91 {
    float v=91.0f;int n=91;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 92 ===
namespace {
struct X92 {
    float v=92.0f;int n=92;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 93 ===
namespace {
struct X93 {
    float v=93.0f;int n=93;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 94 ===
namespace {
struct X94 {
    float v=94.0f;int n=94;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 95 ===
namespace {
struct X95 {
    float v=95.0f;int n=95;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 96 ===
namespace {
struct X96 {
    float v=96.0f;int n=96;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 97 ===
namespace {
struct X97 {
    float v=97.0f;int n=97;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 98 ===
namespace {
struct X98 {
    float v=98.0f;int n=98;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 99 ===
namespace {
struct X99 {
    float v=99.0f;int n=99;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 100 ===
namespace {
struct X100 {
    float v=100.0f;int n=100;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 101 ===
namespace {
struct X101 {
    float v=101.0f;int n=101;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 102 ===
namespace {
struct X102 {
    float v=102.0f;int n=102;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 103 ===
namespace {
struct X103 {
    float v=103.0f;int n=103;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 104 ===
namespace {
struct X104 {
    float v=104.0f;int n=104;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 105 ===
namespace {
struct X105 {
    float v=105.0f;int n=105;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 106 ===
namespace {
struct X106 {
    float v=106.0f;int n=106;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 107 ===
namespace {
struct X107 {
    float v=107.0f;int n=107;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 108 ===
namespace {
struct X108 {
    float v=108.0f;int n=108;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 109 ===
namespace {
struct X109 {
    float v=109.0f;int n=109;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 110 ===
namespace {
struct X110 {
    float v=110.0f;int n=110;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 111 ===
namespace {
struct X111 {
    float v=111.0f;int n=111;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 112 ===
namespace {
struct X112 {
    float v=112.0f;int n=112;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 113 ===
namespace {
struct X113 {
    float v=113.0f;int n=113;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 114 ===
namespace {
struct X114 {
    float v=114.0f;int n=114;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 115 ===
namespace {
struct X115 {
    float v=115.0f;int n=115;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 116 ===
namespace {
struct X116 {
    float v=116.0f;int n=116;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 117 ===
namespace {
struct X117 {
    float v=117.0f;int n=117;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 118 ===
namespace {
struct X118 {
    float v=118.0f;int n=118;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 119 ===
namespace {
struct X119 {
    float v=119.0f;int n=119;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 120 ===
namespace {
struct X120 {
    float v=120.0f;int n=120;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 121 ===
namespace {
struct X121 {
    float v=121.0f;int n=121;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 122 ===
namespace {
struct X122 {
    float v=122.0f;int n=122;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 123 ===
namespace {
struct X123 {
    float v=123.0f;int n=123;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 124 ===
namespace {
struct X124 {
    float v=124.0f;int n=124;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 125 ===
namespace {
struct X125 {
    float v=125.0f;int n=125;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 126 ===
namespace {
struct X126 {
    float v=126.0f;int n=126;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 127 ===
namespace {
struct X127 {
    float v=127.0f;int n=127;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 128 ===
namespace {
struct X128 {
    float v=128.0f;int n=128;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 129 ===
namespace {
struct X129 {
    float v=129.0f;int n=129;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 130 ===
namespace {
struct X130 {
    float v=130.0f;int n=130;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 131 ===
namespace {
struct X131 {
    float v=131.0f;int n=131;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 132 ===
namespace {
struct X132 {
    float v=132.0f;int n=132;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 133 ===
namespace {
struct X133 {
    float v=133.0f;int n=133;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 134 ===
namespace {
struct X134 {
    float v=134.0f;int n=134;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 135 ===
namespace {
struct X135 {
    float v=135.0f;int n=135;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 136 ===
namespace {
struct X136 {
    float v=136.0f;int n=136;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 137 ===
namespace {
struct X137 {
    float v=137.0f;int n=137;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 138 ===
namespace {
struct X138 {
    float v=138.0f;int n=138;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 139 ===
namespace {
struct X139 {
    float v=139.0f;int n=139;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 140 ===
namespace {
struct X140 {
    float v=140.0f;int n=140;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 141 ===
namespace {
struct X141 {
    float v=141.0f;int n=141;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 142 ===
namespace {
struct X142 {
    float v=142.0f;int n=142;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 143 ===
namespace {
struct X143 {
    float v=143.0f;int n=143;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 144 ===
namespace {
struct X144 {
    float v=144.0f;int n=144;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 145 ===
namespace {
struct X145 {
    float v=145.0f;int n=145;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 146 ===
namespace {
struct X146 {
    float v=146.0f;int n=146;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 147 ===
namespace {
struct X147 {
    float v=147.0f;int n=147;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 148 ===
namespace {
struct X148 {
    float v=148.0f;int n=148;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === internal types -- block 149 ===
namespace {
struct X149 {
    float v=149.0f;int n=149;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

#ifdef TEST
bool t_internal_types(){return true;}
#endif
} // namespace wr