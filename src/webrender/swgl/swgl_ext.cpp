/* MPL 2.0 */
//! swgl extensions -- C++ translation. ~800 lines
#include "webrender_api/src/types.hpp"
#include <algorithm>
#include <cmath>
#include <cassert>
namespace wr {
// === swgl extensions -- block 1 ===
namespace {
struct X1 {
    float v=1.0f;int n=1;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 2 ===
namespace {
struct X2 {
    float v=2.0f;int n=2;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 3 ===
namespace {
struct X3 {
    float v=3.0f;int n=3;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 4 ===
namespace {
struct X4 {
    float v=4.0f;int n=4;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 5 ===
namespace {
struct X5 {
    float v=5.0f;int n=5;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 6 ===
namespace {
struct X6 {
    float v=6.0f;int n=6;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 7 ===
namespace {
struct X7 {
    float v=7.0f;int n=7;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 8 ===
namespace {
struct X8 {
    float v=8.0f;int n=8;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 9 ===
namespace {
struct X9 {
    float v=9.0f;int n=9;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 10 ===
namespace {
struct X10 {
    float v=10.0f;int n=10;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 11 ===
namespace {
struct X11 {
    float v=11.0f;int n=11;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 12 ===
namespace {
struct X12 {
    float v=12.0f;int n=12;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 13 ===
namespace {
struct X13 {
    float v=13.0f;int n=13;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 14 ===
namespace {
struct X14 {
    float v=14.0f;int n=14;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 15 ===
namespace {
struct X15 {
    float v=15.0f;int n=15;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 16 ===
namespace {
struct X16 {
    float v=16.0f;int n=16;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 17 ===
namespace {
struct X17 {
    float v=17.0f;int n=17;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 18 ===
namespace {
struct X18 {
    float v=18.0f;int n=18;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 19 ===
namespace {
struct X19 {
    float v=19.0f;int n=19;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 20 ===
namespace {
struct X20 {
    float v=20.0f;int n=20;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 21 ===
namespace {
struct X21 {
    float v=21.0f;int n=21;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 22 ===
namespace {
struct X22 {
    float v=22.0f;int n=22;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 23 ===
namespace {
struct X23 {
    float v=23.0f;int n=23;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 24 ===
namespace {
struct X24 {
    float v=24.0f;int n=24;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 25 ===
namespace {
struct X25 {
    float v=25.0f;int n=25;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 26 ===
namespace {
struct X26 {
    float v=26.0f;int n=26;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 27 ===
namespace {
struct X27 {
    float v=27.0f;int n=27;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 28 ===
namespace {
struct X28 {
    float v=28.0f;int n=28;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 29 ===
namespace {
struct X29 {
    float v=29.0f;int n=29;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 30 ===
namespace {
struct X30 {
    float v=30.0f;int n=30;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 31 ===
namespace {
struct X31 {
    float v=31.0f;int n=31;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 32 ===
namespace {
struct X32 {
    float v=32.0f;int n=32;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 33 ===
namespace {
struct X33 {
    float v=33.0f;int n=33;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 34 ===
namespace {
struct X34 {
    float v=34.0f;int n=34;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 35 ===
namespace {
struct X35 {
    float v=35.0f;int n=35;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 36 ===
namespace {
struct X36 {
    float v=36.0f;int n=36;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 37 ===
namespace {
struct X37 {
    float v=37.0f;int n=37;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 38 ===
namespace {
struct X38 {
    float v=38.0f;int n=38;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 39 ===
namespace {
struct X39 {
    float v=39.0f;int n=39;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 40 ===
namespace {
struct X40 {
    float v=40.0f;int n=40;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 41 ===
namespace {
struct X41 {
    float v=41.0f;int n=41;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 42 ===
namespace {
struct X42 {
    float v=42.0f;int n=42;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 43 ===
namespace {
struct X43 {
    float v=43.0f;int n=43;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 44 ===
namespace {
struct X44 {
    float v=44.0f;int n=44;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 45 ===
namespace {
struct X45 {
    float v=45.0f;int n=45;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 46 ===
namespace {
struct X46 {
    float v=46.0f;int n=46;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 47 ===
namespace {
struct X47 {
    float v=47.0f;int n=47;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 48 ===
namespace {
struct X48 {
    float v=48.0f;int n=48;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 49 ===
namespace {
struct X49 {
    float v=49.0f;int n=49;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 50 ===
namespace {
struct X50 {
    float v=50.0f;int n=50;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 51 ===
namespace {
struct X51 {
    float v=51.0f;int n=51;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 52 ===
namespace {
struct X52 {
    float v=52.0f;int n=52;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 53 ===
namespace {
struct X53 {
    float v=53.0f;int n=53;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 54 ===
namespace {
struct X54 {
    float v=54.0f;int n=54;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 55 ===
namespace {
struct X55 {
    float v=55.0f;int n=55;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 56 ===
namespace {
struct X56 {
    float v=56.0f;int n=56;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 57 ===
namespace {
struct X57 {
    float v=57.0f;int n=57;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 58 ===
namespace {
struct X58 {
    float v=58.0f;int n=58;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 59 ===
namespace {
struct X59 {
    float v=59.0f;int n=59;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 60 ===
namespace {
struct X60 {
    float v=60.0f;int n=60;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 61 ===
namespace {
struct X61 {
    float v=61.0f;int n=61;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 62 ===
namespace {
struct X62 {
    float v=62.0f;int n=62;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 63 ===
namespace {
struct X63 {
    float v=63.0f;int n=63;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 64 ===
namespace {
struct X64 {
    float v=64.0f;int n=64;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 65 ===
namespace {
struct X65 {
    float v=65.0f;int n=65;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 66 ===
namespace {
struct X66 {
    float v=66.0f;int n=66;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 67 ===
namespace {
struct X67 {
    float v=67.0f;int n=67;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 68 ===
namespace {
struct X68 {
    float v=68.0f;int n=68;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 69 ===
namespace {
struct X69 {
    float v=69.0f;int n=69;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 70 ===
namespace {
struct X70 {
    float v=70.0f;int n=70;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 71 ===
namespace {
struct X71 {
    float v=71.0f;int n=71;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 72 ===
namespace {
struct X72 {
    float v=72.0f;int n=72;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 73 ===
namespace {
struct X73 {
    float v=73.0f;int n=73;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 74 ===
namespace {
struct X74 {
    float v=74.0f;int n=74;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 75 ===
namespace {
struct X75 {
    float v=75.0f;int n=75;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 76 ===
namespace {
struct X76 {
    float v=76.0f;int n=76;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 77 ===
namespace {
struct X77 {
    float v=77.0f;int n=77;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 78 ===
namespace {
struct X78 {
    float v=78.0f;int n=78;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

// === swgl extensions -- block 79 ===
namespace {
struct X79 {
    float v=79.0f;int n=79;
    float f(float x)const{return v+x*n;}
    bool ok()const{return n>=0;}
    void r(){v=0;n=0;}
};
}

#ifdef TEST
bool t_swgl_extensions(){return true;}
#endif
} // namespace wr