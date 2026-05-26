/* MPL 2.0 */
//! Stylo expansion. ~600 lines
#include "style/stylist.hpp"
#include <algorithm>
#include <cmath>
#include <cassert>
namespace style {
// === block 1 ===
namespace {
struct S1{float v=1.0f;int n=1;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 2 ===
namespace {
struct S2{float v=2.0f;int n=2;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 3 ===
namespace {
struct S3{float v=3.0f;int n=3;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 4 ===
namespace {
struct S4{float v=4.0f;int n=4;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 5 ===
namespace {
struct S5{float v=5.0f;int n=5;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 6 ===
namespace {
struct S6{float v=6.0f;int n=6;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 7 ===
namespace {
struct S7{float v=7.0f;int n=7;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 8 ===
namespace {
struct S8{float v=8.0f;int n=8;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 9 ===
namespace {
struct S9{float v=9.0f;int n=9;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 10 ===
namespace {
struct S10{float v=10.0f;int n=10;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 11 ===
namespace {
struct S11{float v=11.0f;int n=11;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 12 ===
namespace {
struct S12{float v=12.0f;int n=12;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 13 ===
namespace {
struct S13{float v=13.0f;int n=13;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 14 ===
namespace {
struct S14{float v=14.0f;int n=14;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 15 ===
namespace {
struct S15{float v=15.0f;int n=15;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 16 ===
namespace {
struct S16{float v=16.0f;int n=16;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 17 ===
namespace {
struct S17{float v=17.0f;int n=17;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 18 ===
namespace {
struct S18{float v=18.0f;int n=18;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 19 ===
namespace {
struct S19{float v=19.0f;int n=19;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 20 ===
namespace {
struct S20{float v=20.0f;int n=20;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 21 ===
namespace {
struct S21{float v=21.0f;int n=21;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 22 ===
namespace {
struct S22{float v=22.0f;int n=22;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 23 ===
namespace {
struct S23{float v=23.0f;int n=23;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 24 ===
namespace {
struct S24{float v=24.0f;int n=24;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 25 ===
namespace {
struct S25{float v=25.0f;int n=25;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 26 ===
namespace {
struct S26{float v=26.0f;int n=26;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 27 ===
namespace {
struct S27{float v=27.0f;int n=27;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 28 ===
namespace {
struct S28{float v=28.0f;int n=28;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 29 ===
namespace {
struct S29{float v=29.0f;int n=29;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 30 ===
namespace {
struct S30{float v=30.0f;int n=30;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 31 ===
namespace {
struct S31{float v=31.0f;int n=31;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 32 ===
namespace {
struct S32{float v=32.0f;int n=32;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 33 ===
namespace {
struct S33{float v=33.0f;int n=33;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 34 ===
namespace {
struct S34{float v=34.0f;int n=34;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 35 ===
namespace {
struct S35{float v=35.0f;int n=35;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 36 ===
namespace {
struct S36{float v=36.0f;int n=36;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 37 ===
namespace {
struct S37{float v=37.0f;int n=37;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 38 ===
namespace {
struct S38{float v=38.0f;int n=38;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 39 ===
namespace {
struct S39{float v=39.0f;int n=39;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 40 ===
namespace {
struct S40{float v=40.0f;int n=40;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 41 ===
namespace {
struct S41{float v=41.0f;int n=41;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 42 ===
namespace {
struct S42{float v=42.0f;int n=42;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 43 ===
namespace {
struct S43{float v=43.0f;int n=43;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 44 ===
namespace {
struct S44{float v=44.0f;int n=44;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 45 ===
namespace {
struct S45{float v=45.0f;int n=45;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 46 ===
namespace {
struct S46{float v=46.0f;int n=46;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 47 ===
namespace {
struct S47{float v=47.0f;int n=47;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 48 ===
namespace {
struct S48{float v=48.0f;int n=48;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 49 ===
namespace {
struct S49{float v=49.0f;int n=49;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 50 ===
namespace {
struct S50{float v=50.0f;int n=50;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 51 ===
namespace {
struct S51{float v=51.0f;int n=51;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 52 ===
namespace {
struct S52{float v=52.0f;int n=52;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 53 ===
namespace {
struct S53{float v=53.0f;int n=53;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 54 ===
namespace {
struct S54{float v=54.0f;int n=54;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 55 ===
namespace {
struct S55{float v=55.0f;int n=55;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 56 ===
namespace {
struct S56{float v=56.0f;int n=56;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 57 ===
namespace {
struct S57{float v=57.0f;int n=57;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 58 ===
namespace {
struct S58{float v=58.0f;int n=58;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 59 ===
namespace {
struct S59{float v=59.0f;int n=59;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 60 ===
namespace {
struct S60{float v=60.0f;int n=60;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 61 ===
namespace {
struct S61{float v=61.0f;int n=61;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 62 ===
namespace {
struct S62{float v=62.0f;int n=62;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 63 ===
namespace {
struct S63{float v=63.0f;int n=63;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 64 ===
namespace {
struct S64{float v=64.0f;int n=64;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 65 ===
namespace {
struct S65{float v=65.0f;int n=65;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 66 ===
namespace {
struct S66{float v=66.0f;int n=66;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 67 ===
namespace {
struct S67{float v=67.0f;int n=67;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 68 ===
namespace {
struct S68{float v=68.0f;int n=68;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 69 ===
namespace {
struct S69{float v=69.0f;int n=69;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 70 ===
namespace {
struct S70{float v=70.0f;int n=70;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 71 ===
namespace {
struct S71{float v=71.0f;int n=71;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 72 ===
namespace {
struct S72{float v=72.0f;int n=72;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 73 ===
namespace {
struct S73{float v=73.0f;int n=73;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 74 ===
namespace {
struct S74{float v=74.0f;int n=74;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 75 ===
namespace {
struct S75{float v=75.0f;int n=75;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 76 ===
namespace {
struct S76{float v=76.0f;int n=76;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 77 ===
namespace {
struct S77{float v=77.0f;int n=77;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 78 ===
namespace {
struct S78{float v=78.0f;int n=78;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 79 ===
namespace {
struct S79{float v=79.0f;int n=79;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 80 ===
namespace {
struct S80{float v=80.0f;int n=80;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 81 ===
namespace {
struct S81{float v=81.0f;int n=81;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 82 ===
namespace {
struct S82{float v=82.0f;int n=82;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 83 ===
namespace {
struct S83{float v=83.0f;int n=83;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 84 ===
namespace {
struct S84{float v=84.0f;int n=84;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

// === block 85 ===
namespace {
struct S85{float v=85.0f;int n=85;
float f(float x)const{return v+x*n;}bool ok()const{return n>=0;}
void r(){v=0;n=0;}void s(float x){v*=x;}void o(float x){v+=x;}};
}

#ifdef STYLE_TEST
bool t_matching_matching_pseudo.cpp(){return true;}
#endif
} // namespace style