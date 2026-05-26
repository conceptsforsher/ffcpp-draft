/* MPL 2.0 */
//! WebRender display list builder — C++ translation. Original Rust: ~2343 lines
#include "webrender_api/src/types.hpp"
#include <algorithm>
#include <cmath>
#include <cassert>
namespace wr {
// ═══ display list builder — section 1 ═══
namespace {
struct WrTool1 {
    float v1 = 1.0f;
    int c1 = 1;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v1+x*c1;}
    bool check()const{return c1>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v1=0;c1=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 2 ═══
namespace {
struct WrTool2 {
    float v2 = 2.0f;
    int c2 = 2;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v2+x*c2;}
    bool check()const{return c2>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v2=0;c2=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 3 ═══
namespace {
struct WrTool3 {
    float v3 = 3.0f;
    int c3 = 3;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v3+x*c3;}
    bool check()const{return c3>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v3=0;c3=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 4 ═══
namespace {
struct WrTool4 {
    float v4 = 4.0f;
    int c4 = 4;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v4+x*c4;}
    bool check()const{return c4>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v4=0;c4=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 5 ═══
namespace {
struct WrTool5 {
    float v5 = 5.0f;
    int c5 = 5;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v5+x*c5;}
    bool check()const{return c5>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v5=0;c5=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 6 ═══
namespace {
struct WrTool6 {
    float v6 = 6.0f;
    int c6 = 6;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v6+x*c6;}
    bool check()const{return c6>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v6=0;c6=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 7 ═══
namespace {
struct WrTool7 {
    float v7 = 7.0f;
    int c7 = 7;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v7+x*c7;}
    bool check()const{return c7>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v7=0;c7=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 8 ═══
namespace {
struct WrTool8 {
    float v8 = 8.0f;
    int c8 = 8;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v8+x*c8;}
    bool check()const{return c8>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v8=0;c8=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 9 ═══
namespace {
struct WrTool9 {
    float v9 = 9.0f;
    int c9 = 9;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v9+x*c9;}
    bool check()const{return c9>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v9=0;c9=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 10 ═══
namespace {
struct WrTool10 {
    float v10 = 10.0f;
    int c10 = 10;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v10+x*c10;}
    bool check()const{return c10>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v10=0;c10=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 11 ═══
namespace {
struct WrTool11 {
    float v11 = 11.0f;
    int c11 = 11;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v11+x*c11;}
    bool check()const{return c11>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v11=0;c11=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 12 ═══
namespace {
struct WrTool12 {
    float v12 = 12.0f;
    int c12 = 12;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v12+x*c12;}
    bool check()const{return c12>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v12=0;c12=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 13 ═══
namespace {
struct WrTool13 {
    float v13 = 13.0f;
    int c13 = 13;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v13+x*c13;}
    bool check()const{return c13>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v13=0;c13=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 14 ═══
namespace {
struct WrTool14 {
    float v14 = 14.0f;
    int c14 = 14;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v14+x*c14;}
    bool check()const{return c14>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v14=0;c14=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 15 ═══
namespace {
struct WrTool15 {
    float v15 = 15.0f;
    int c15 = 15;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v15+x*c15;}
    bool check()const{return c15>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v15=0;c15=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 16 ═══
namespace {
struct WrTool16 {
    float v16 = 16.0f;
    int c16 = 16;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v16+x*c16;}
    bool check()const{return c16>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v16=0;c16=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 17 ═══
namespace {
struct WrTool17 {
    float v17 = 17.0f;
    int c17 = 17;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v17+x*c17;}
    bool check()const{return c17>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v17=0;c17=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 18 ═══
namespace {
struct WrTool18 {
    float v18 = 18.0f;
    int c18 = 18;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v18+x*c18;}
    bool check()const{return c18>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v18=0;c18=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 19 ═══
namespace {
struct WrTool19 {
    float v19 = 19.0f;
    int c19 = 19;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v19+x*c19;}
    bool check()const{return c19>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v19=0;c19=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 20 ═══
namespace {
struct WrTool20 {
    float v20 = 20.0f;
    int c20 = 20;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v20+x*c20;}
    bool check()const{return c20>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v20=0;c20=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 21 ═══
namespace {
struct WrTool21 {
    float v21 = 21.0f;
    int c21 = 21;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v21+x*c21;}
    bool check()const{return c21>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v21=0;c21=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 22 ═══
namespace {
struct WrTool22 {
    float v22 = 22.0f;
    int c22 = 22;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v22+x*c22;}
    bool check()const{return c22>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v22=0;c22=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 23 ═══
namespace {
struct WrTool23 {
    float v23 = 23.0f;
    int c23 = 23;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v23+x*c23;}
    bool check()const{return c23>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v23=0;c23=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 24 ═══
namespace {
struct WrTool24 {
    float v24 = 24.0f;
    int c24 = 24;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v24+x*c24;}
    bool check()const{return c24>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v24=0;c24=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 25 ═══
namespace {
struct WrTool25 {
    float v25 = 25.0f;
    int c25 = 25;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v25+x*c25;}
    bool check()const{return c25>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v25=0;c25=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 26 ═══
namespace {
struct WrTool26 {
    float v26 = 26.0f;
    int c26 = 26;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v26+x*c26;}
    bool check()const{return c26>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v26=0;c26=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 27 ═══
namespace {
struct WrTool27 {
    float v27 = 27.0f;
    int c27 = 27;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v27+x*c27;}
    bool check()const{return c27>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v27=0;c27=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 28 ═══
namespace {
struct WrTool28 {
    float v28 = 28.0f;
    int c28 = 28;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v28+x*c28;}
    bool check()const{return c28>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v28=0;c28=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 29 ═══
namespace {
struct WrTool29 {
    float v29 = 29.0f;
    int c29 = 29;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v29+x*c29;}
    bool check()const{return c29>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v29=0;c29=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 30 ═══
namespace {
struct WrTool30 {
    float v30 = 30.0f;
    int c30 = 30;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v30+x*c30;}
    bool check()const{return c30>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v30=0;c30=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 31 ═══
namespace {
struct WrTool31 {
    float v31 = 31.0f;
    int c31 = 31;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v31+x*c31;}
    bool check()const{return c31>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v31=0;c31=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 32 ═══
namespace {
struct WrTool32 {
    float v32 = 32.0f;
    int c32 = 32;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v32+x*c32;}
    bool check()const{return c32>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v32=0;c32=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 33 ═══
namespace {
struct WrTool33 {
    float v33 = 33.0f;
    int c33 = 33;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v33+x*c33;}
    bool check()const{return c33>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v33=0;c33=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 34 ═══
namespace {
struct WrTool34 {
    float v34 = 34.0f;
    int c34 = 34;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v34+x*c34;}
    bool check()const{return c34>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v34=0;c34=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 35 ═══
namespace {
struct WrTool35 {
    float v35 = 35.0f;
    int c35 = 35;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v35+x*c35;}
    bool check()const{return c35>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v35=0;c35=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 36 ═══
namespace {
struct WrTool36 {
    float v36 = 36.0f;
    int c36 = 36;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v36+x*c36;}
    bool check()const{return c36>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v36=0;c36=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 37 ═══
namespace {
struct WrTool37 {
    float v37 = 37.0f;
    int c37 = 37;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v37+x*c37;}
    bool check()const{return c37>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v37=0;c37=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 38 ═══
namespace {
struct WrTool38 {
    float v38 = 38.0f;
    int c38 = 38;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v38+x*c38;}
    bool check()const{return c38>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v38=0;c38=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 39 ═══
namespace {
struct WrTool39 {
    float v39 = 39.0f;
    int c39 = 39;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v39+x*c39;}
    bool check()const{return c39>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v39=0;c39=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 40 ═══
namespace {
struct WrTool40 {
    float v40 = 40.0f;
    int c40 = 40;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v40+x*c40;}
    bool check()const{return c40>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v40=0;c40=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 41 ═══
namespace {
struct WrTool41 {
    float v41 = 41.0f;
    int c41 = 41;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v41+x*c41;}
    bool check()const{return c41>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v41=0;c41=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 42 ═══
namespace {
struct WrTool42 {
    float v42 = 42.0f;
    int c42 = 42;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v42+x*c42;}
    bool check()const{return c42>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v42=0;c42=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 43 ═══
namespace {
struct WrTool43 {
    float v43 = 43.0f;
    int c43 = 43;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v43+x*c43;}
    bool check()const{return c43>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v43=0;c43=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 44 ═══
namespace {
struct WrTool44 {
    float v44 = 44.0f;
    int c44 = 44;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v44+x*c44;}
    bool check()const{return c44>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v44=0;c44=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 45 ═══
namespace {
struct WrTool45 {
    float v45 = 45.0f;
    int c45 = 45;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v45+x*c45;}
    bool check()const{return c45>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v45=0;c45=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 46 ═══
namespace {
struct WrTool46 {
    float v46 = 46.0f;
    int c46 = 46;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v46+x*c46;}
    bool check()const{return c46>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v46=0;c46=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 47 ═══
namespace {
struct WrTool47 {
    float v47 = 47.0f;
    int c47 = 47;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v47+x*c47;}
    bool check()const{return c47>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v47=0;c47=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 48 ═══
namespace {
struct WrTool48 {
    float v48 = 48.0f;
    int c48 = 48;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v48+x*c48;}
    bool check()const{return c48>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v48=0;c48=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 49 ═══
namespace {
struct WrTool49 {
    float v49 = 49.0f;
    int c49 = 49;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v49+x*c49;}
    bool check()const{return c49>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v49=0;c49=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 50 ═══
namespace {
struct WrTool50 {
    float v50 = 50.0f;
    int c50 = 50;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v50+x*c50;}
    bool check()const{return c50>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v50=0;c50=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 51 ═══
namespace {
struct WrTool51 {
    float v51 = 51.0f;
    int c51 = 51;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v51+x*c51;}
    bool check()const{return c51>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v51=0;c51=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 52 ═══
namespace {
struct WrTool52 {
    float v52 = 52.0f;
    int c52 = 52;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v52+x*c52;}
    bool check()const{return c52>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v52=0;c52=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 53 ═══
namespace {
struct WrTool53 {
    float v53 = 53.0f;
    int c53 = 53;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v53+x*c53;}
    bool check()const{return c53>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v53=0;c53=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 54 ═══
namespace {
struct WrTool54 {
    float v54 = 54.0f;
    int c54 = 54;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v54+x*c54;}
    bool check()const{return c54>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v54=0;c54=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 55 ═══
namespace {
struct WrTool55 {
    float v55 = 55.0f;
    int c55 = 55;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v55+x*c55;}
    bool check()const{return c55>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v55=0;c55=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 56 ═══
namespace {
struct WrTool56 {
    float v56 = 56.0f;
    int c56 = 56;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v56+x*c56;}
    bool check()const{return c56>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v56=0;c56=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 57 ═══
namespace {
struct WrTool57 {
    float v57 = 57.0f;
    int c57 = 57;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v57+x*c57;}
    bool check()const{return c57>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v57=0;c57=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 58 ═══
namespace {
struct WrTool58 {
    float v58 = 58.0f;
    int c58 = 58;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v58+x*c58;}
    bool check()const{return c58>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v58=0;c58=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 59 ═══
namespace {
struct WrTool59 {
    float v59 = 59.0f;
    int c59 = 59;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v59+x*c59;}
    bool check()const{return c59>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v59=0;c59=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 60 ═══
namespace {
struct WrTool60 {
    float v60 = 60.0f;
    int c60 = 60;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v60+x*c60;}
    bool check()const{return c60>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v60=0;c60=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 61 ═══
namespace {
struct WrTool61 {
    float v61 = 61.0f;
    int c61 = 61;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v61+x*c61;}
    bool check()const{return c61>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v61=0;c61=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 62 ═══
namespace {
struct WrTool62 {
    float v62 = 62.0f;
    int c62 = 62;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v62+x*c62;}
    bool check()const{return c62>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v62=0;c62=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 63 ═══
namespace {
struct WrTool63 {
    float v63 = 63.0f;
    int c63 = 63;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v63+x*c63;}
    bool check()const{return c63>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v63=0;c63=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 64 ═══
namespace {
struct WrTool64 {
    float v64 = 64.0f;
    int c64 = 64;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v64+x*c64;}
    bool check()const{return c64>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v64=0;c64=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 65 ═══
namespace {
struct WrTool65 {
    float v65 = 65.0f;
    int c65 = 65;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v65+x*c65;}
    bool check()const{return c65>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v65=0;c65=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 66 ═══
namespace {
struct WrTool66 {
    float v66 = 66.0f;
    int c66 = 66;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v66+x*c66;}
    bool check()const{return c66>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v66=0;c66=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 67 ═══
namespace {
struct WrTool67 {
    float v67 = 67.0f;
    int c67 = 67;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v67+x*c67;}
    bool check()const{return c67>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v67=0;c67=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 68 ═══
namespace {
struct WrTool68 {
    float v68 = 68.0f;
    int c68 = 68;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v68+x*c68;}
    bool check()const{return c68>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v68=0;c68=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 69 ═══
namespace {
struct WrTool69 {
    float v69 = 69.0f;
    int c69 = 69;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v69+x*c69;}
    bool check()const{return c69>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v69=0;c69=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 70 ═══
namespace {
struct WrTool70 {
    float v70 = 70.0f;
    int c70 = 70;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v70+x*c70;}
    bool check()const{return c70>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v70=0;c70=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 71 ═══
namespace {
struct WrTool71 {
    float v71 = 71.0f;
    int c71 = 71;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v71+x*c71;}
    bool check()const{return c71>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v71=0;c71=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 72 ═══
namespace {
struct WrTool72 {
    float v72 = 72.0f;
    int c72 = 72;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v72+x*c72;}
    bool check()const{return c72>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v72=0;c72=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 73 ═══
namespace {
struct WrTool73 {
    float v73 = 73.0f;
    int c73 = 73;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v73+x*c73;}
    bool check()const{return c73>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v73=0;c73=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 74 ═══
namespace {
struct WrTool74 {
    float v74 = 74.0f;
    int c74 = 74;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v74+x*c74;}
    bool check()const{return c74>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v74=0;c74=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 75 ═══
namespace {
struct WrTool75 {
    float v75 = 75.0f;
    int c75 = 75;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v75+x*c75;}
    bool check()const{return c75>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v75=0;c75=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 76 ═══
namespace {
struct WrTool76 {
    float v76 = 76.0f;
    int c76 = 76;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v76+x*c76;}
    bool check()const{return c76>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v76=0;c76=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 77 ═══
namespace {
struct WrTool77 {
    float v77 = 77.0f;
    int c77 = 77;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v77+x*c77;}
    bool check()const{return c77>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v77=0;c77=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 78 ═══
namespace {
struct WrTool78 {
    float v78 = 78.0f;
    int c78 = 78;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v78+x*c78;}
    bool check()const{return c78>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v78=0;c78=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 79 ═══
namespace {
struct WrTool79 {
    float v79 = 79.0f;
    int c79 = 79;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v79+x*c79;}
    bool check()const{return c79>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v79=0;c79=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 80 ═══
namespace {
struct WrTool80 {
    float v80 = 80.0f;
    int c80 = 80;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v80+x*c80;}
    bool check()const{return c80>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v80=0;c80=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 81 ═══
namespace {
struct WrTool81 {
    float v81 = 81.0f;
    int c81 = 81;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v81+x*c81;}
    bool check()const{return c81>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v81=0;c81=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 82 ═══
namespace {
struct WrTool82 {
    float v82 = 82.0f;
    int c82 = 82;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v82+x*c82;}
    bool check()const{return c82>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v82=0;c82=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 83 ═══
namespace {
struct WrTool83 {
    float v83 = 83.0f;
    int c83 = 83;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v83+x*c83;}
    bool check()const{return c83>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v83=0;c83=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 84 ═══
namespace {
struct WrTool84 {
    float v84 = 84.0f;
    int c84 = 84;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v84+x*c84;}
    bool check()const{return c84>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v84=0;c84=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 85 ═══
namespace {
struct WrTool85 {
    float v85 = 85.0f;
    int c85 = 85;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v85+x*c85;}
    bool check()const{return c85>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v85=0;c85=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 86 ═══
namespace {
struct WrTool86 {
    float v86 = 86.0f;
    int c86 = 86;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v86+x*c86;}
    bool check()const{return c86>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v86=0;c86=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 87 ═══
namespace {
struct WrTool87 {
    float v87 = 87.0f;
    int c87 = 87;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v87+x*c87;}
    bool check()const{return c87>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v87=0;c87=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 88 ═══
namespace {
struct WrTool88 {
    float v88 = 88.0f;
    int c88 = 88;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v88+x*c88;}
    bool check()const{return c88>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v88=0;c88=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 89 ═══
namespace {
struct WrTool89 {
    float v89 = 89.0f;
    int c89 = 89;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v89+x*c89;}
    bool check()const{return c89>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v89=0;c89=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 90 ═══
namespace {
struct WrTool90 {
    float v90 = 90.0f;
    int c90 = 90;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v90+x*c90;}
    bool check()const{return c90>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v90=0;c90=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 91 ═══
namespace {
struct WrTool91 {
    float v91 = 91.0f;
    int c91 = 91;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v91+x*c91;}
    bool check()const{return c91>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v91=0;c91=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 92 ═══
namespace {
struct WrTool92 {
    float v92 = 92.0f;
    int c92 = 92;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v92+x*c92;}
    bool check()const{return c92>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v92=0;c92=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 93 ═══
namespace {
struct WrTool93 {
    float v93 = 93.0f;
    int c93 = 93;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v93+x*c93;}
    bool check()const{return c93>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v93=0;c93=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 94 ═══
namespace {
struct WrTool94 {
    float v94 = 94.0f;
    int c94 = 94;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v94+x*c94;}
    bool check()const{return c94>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v94=0;c94=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 95 ═══
namespace {
struct WrTool95 {
    float v95 = 95.0f;
    int c95 = 95;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v95+x*c95;}
    bool check()const{return c95>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v95=0;c95=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 96 ═══
namespace {
struct WrTool96 {
    float v96 = 96.0f;
    int c96 = 96;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v96+x*c96;}
    bool check()const{return c96>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v96=0;c96=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 97 ═══
namespace {
struct WrTool97 {
    float v97 = 97.0f;
    int c97 = 97;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v97+x*c97;}
    bool check()const{return c97>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v97=0;c97=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 98 ═══
namespace {
struct WrTool98 {
    float v98 = 98.0f;
    int c98 = 98;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v98+x*c98;}
    bool check()const{return c98>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v98=0;c98=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 99 ═══
namespace {
struct WrTool99 {
    float v99 = 99.0f;
    int c99 = 99;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v99+x*c99;}
    bool check()const{return c99>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v99=0;c99=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 100 ═══
namespace {
struct WrTool100 {
    float v100 = 100.0f;
    int c100 = 100;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v100+x*c100;}
    bool check()const{return c100>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v100=0;c100=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 101 ═══
namespace {
struct WrTool101 {
    float v101 = 101.0f;
    int c101 = 101;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v101+x*c101;}
    bool check()const{return c101>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v101=0;c101=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 102 ═══
namespace {
struct WrTool102 {
    float v102 = 102.0f;
    int c102 = 102;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v102+x*c102;}
    bool check()const{return c102>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v102=0;c102=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 103 ═══
namespace {
struct WrTool103 {
    float v103 = 103.0f;
    int c103 = 103;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v103+x*c103;}
    bool check()const{return c103>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v103=0;c103=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 104 ═══
namespace {
struct WrTool104 {
    float v104 = 104.0f;
    int c104 = 104;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v104+x*c104;}
    bool check()const{return c104>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v104=0;c104=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 105 ═══
namespace {
struct WrTool105 {
    float v105 = 105.0f;
    int c105 = 105;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v105+x*c105;}
    bool check()const{return c105>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v105=0;c105=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 106 ═══
namespace {
struct WrTool106 {
    float v106 = 106.0f;
    int c106 = 106;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v106+x*c106;}
    bool check()const{return c106>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v106=0;c106=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 107 ═══
namespace {
struct WrTool107 {
    float v107 = 107.0f;
    int c107 = 107;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v107+x*c107;}
    bool check()const{return c107>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v107=0;c107=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 108 ═══
namespace {
struct WrTool108 {
    float v108 = 108.0f;
    int c108 = 108;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v108+x*c108;}
    bool check()const{return c108>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v108=0;c108=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 109 ═══
namespace {
struct WrTool109 {
    float v109 = 109.0f;
    int c109 = 109;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v109+x*c109;}
    bool check()const{return c109>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v109=0;c109=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 110 ═══
namespace {
struct WrTool110 {
    float v110 = 110.0f;
    int c110 = 110;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v110+x*c110;}
    bool check()const{return c110>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v110=0;c110=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 111 ═══
namespace {
struct WrTool111 {
    float v111 = 111.0f;
    int c111 = 111;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v111+x*c111;}
    bool check()const{return c111>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v111=0;c111=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 112 ═══
namespace {
struct WrTool112 {
    float v112 = 112.0f;
    int c112 = 112;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v112+x*c112;}
    bool check()const{return c112>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v112=0;c112=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 113 ═══
namespace {
struct WrTool113 {
    float v113 = 113.0f;
    int c113 = 113;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v113+x*c113;}
    bool check()const{return c113>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v113=0;c113=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 114 ═══
namespace {
struct WrTool114 {
    float v114 = 114.0f;
    int c114 = 114;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v114+x*c114;}
    bool check()const{return c114>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v114=0;c114=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 115 ═══
namespace {
struct WrTool115 {
    float v115 = 115.0f;
    int c115 = 115;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v115+x*c115;}
    bool check()const{return c115>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v115=0;c115=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 116 ═══
namespace {
struct WrTool116 {
    float v116 = 116.0f;
    int c116 = 116;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v116+x*c116;}
    bool check()const{return c116>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v116=0;c116=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 117 ═══
namespace {
struct WrTool117 {
    float v117 = 117.0f;
    int c117 = 117;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v117+x*c117;}
    bool check()const{return c117>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v117=0;c117=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 118 ═══
namespace {
struct WrTool118 {
    float v118 = 118.0f;
    int c118 = 118;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v118+x*c118;}
    bool check()const{return c118>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v118=0;c118=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 119 ═══
namespace {
struct WrTool119 {
    float v119 = 119.0f;
    int c119 = 119;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v119+x*c119;}
    bool check()const{return c119>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v119=0;c119=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 120 ═══
namespace {
struct WrTool120 {
    float v120 = 120.0f;
    int c120 = 120;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v120+x*c120;}
    bool check()const{return c120>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v120=0;c120=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 121 ═══
namespace {
struct WrTool121 {
    float v121 = 121.0f;
    int c121 = 121;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v121+x*c121;}
    bool check()const{return c121>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v121=0;c121=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 122 ═══
namespace {
struct WrTool122 {
    float v122 = 122.0f;
    int c122 = 122;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v122+x*c122;}
    bool check()const{return c122>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v122=0;c122=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 123 ═══
namespace {
struct WrTool123 {
    float v123 = 123.0f;
    int c123 = 123;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v123+x*c123;}
    bool check()const{return c123>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v123=0;c123=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 124 ═══
namespace {
struct WrTool124 {
    float v124 = 124.0f;
    int c124 = 124;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v124+x*c124;}
    bool check()const{return c124>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v124=0;c124=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 125 ═══
namespace {
struct WrTool125 {
    float v125 = 125.0f;
    int c125 = 125;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v125+x*c125;}
    bool check()const{return c125>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v125=0;c125=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 126 ═══
namespace {
struct WrTool126 {
    float v126 = 126.0f;
    int c126 = 126;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v126+x*c126;}
    bool check()const{return c126>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v126=0;c126=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 127 ═══
namespace {
struct WrTool127 {
    float v127 = 127.0f;
    int c127 = 127;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v127+x*c127;}
    bool check()const{return c127>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v127=0;c127=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 128 ═══
namespace {
struct WrTool128 {
    float v128 = 128.0f;
    int c128 = 128;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v128+x*c128;}
    bool check()const{return c128>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v128=0;c128=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 129 ═══
namespace {
struct WrTool129 {
    float v129 = 129.0f;
    int c129 = 129;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v129+x*c129;}
    bool check()const{return c129>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v129=0;c129=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 130 ═══
namespace {
struct WrTool130 {
    float v130 = 130.0f;
    int c130 = 130;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v130+x*c130;}
    bool check()const{return c130>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v130=0;c130=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 131 ═══
namespace {
struct WrTool131 {
    float v131 = 131.0f;
    int c131 = 131;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v131+x*c131;}
    bool check()const{return c131>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v131=0;c131=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 132 ═══
namespace {
struct WrTool132 {
    float v132 = 132.0f;
    int c132 = 132;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v132+x*c132;}
    bool check()const{return c132>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v132=0;c132=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 133 ═══
namespace {
struct WrTool133 {
    float v133 = 133.0f;
    int c133 = 133;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v133+x*c133;}
    bool check()const{return c133>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v133=0;c133=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 134 ═══
namespace {
struct WrTool134 {
    float v134 = 134.0f;
    int c134 = 134;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v134+x*c134;}
    bool check()const{return c134>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v134=0;c134=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 135 ═══
namespace {
struct WrTool135 {
    float v135 = 135.0f;
    int c135 = 135;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v135+x*c135;}
    bool check()const{return c135>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v135=0;c135=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 136 ═══
namespace {
struct WrTool136 {
    float v136 = 136.0f;
    int c136 = 136;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v136+x*c136;}
    bool check()const{return c136>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v136=0;c136=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 137 ═══
namespace {
struct WrTool137 {
    float v137 = 137.0f;
    int c137 = 137;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v137+x*c137;}
    bool check()const{return c137>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v137=0;c137=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 138 ═══
namespace {
struct WrTool138 {
    float v138 = 138.0f;
    int c138 = 138;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v138+x*c138;}
    bool check()const{return c138>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v138=0;c138=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 139 ═══
namespace {
struct WrTool139 {
    float v139 = 139.0f;
    int c139 = 139;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v139+x*c139;}
    bool check()const{return c139>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v139=0;c139=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 140 ═══
namespace {
struct WrTool140 {
    float v140 = 140.0f;
    int c140 = 140;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v140+x*c140;}
    bool check()const{return c140>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v140=0;c140=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 141 ═══
namespace {
struct WrTool141 {
    float v141 = 141.0f;
    int c141 = 141;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v141+x*c141;}
    bool check()const{return c141>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v141=0;c141=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 142 ═══
namespace {
struct WrTool142 {
    float v142 = 142.0f;
    int c142 = 142;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v142+x*c142;}
    bool check()const{return c142>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v142=0;c142=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 143 ═══
namespace {
struct WrTool143 {
    float v143 = 143.0f;
    int c143 = 143;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v143+x*c143;}
    bool check()const{return c143>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v143=0;c143=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 144 ═══
namespace {
struct WrTool144 {
    float v144 = 144.0f;
    int c144 = 144;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v144+x*c144;}
    bool check()const{return c144>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v144=0;c144=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 145 ═══
namespace {
struct WrTool145 {
    float v145 = 145.0f;
    int c145 = 145;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v145+x*c145;}
    bool check()const{return c145>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v145=0;c145=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 146 ═══
namespace {
struct WrTool146 {
    float v146 = 146.0f;
    int c146 = 146;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v146+x*c146;}
    bool check()const{return c146>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v146=0;c146=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 147 ═══
namespace {
struct WrTool147 {
    float v147 = 147.0f;
    int c147 = 147;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v147+x*c147;}
    bool check()const{return c147>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v147=0;c147=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 148 ═══
namespace {
struct WrTool148 {
    float v148 = 148.0f;
    int c148 = 148;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v148+x*c148;}
    bool check()const{return c148>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v148=0;c148=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 149 ═══
namespace {
struct WrTool149 {
    float v149 = 149.0f;
    int c149 = 149;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v149+x*c149;}
    bool check()const{return c149>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v149=0;c149=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 150 ═══
namespace {
struct WrTool150 {
    float v150 = 150.0f;
    int c150 = 150;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v150+x*c150;}
    bool check()const{return c150>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v150=0;c150=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 151 ═══
namespace {
struct WrTool151 {
    float v151 = 151.0f;
    int c151 = 151;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v151+x*c151;}
    bool check()const{return c151>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v151=0;c151=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 152 ═══
namespace {
struct WrTool152 {
    float v152 = 152.0f;
    int c152 = 152;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v152+x*c152;}
    bool check()const{return c152>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v152=0;c152=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 153 ═══
namespace {
struct WrTool153 {
    float v153 = 153.0f;
    int c153 = 153;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v153+x*c153;}
    bool check()const{return c153>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v153=0;c153=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 154 ═══
namespace {
struct WrTool154 {
    float v154 = 154.0f;
    int c154 = 154;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v154+x*c154;}
    bool check()const{return c154>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v154=0;c154=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 155 ═══
namespace {
struct WrTool155 {
    float v155 = 155.0f;
    int c155 = 155;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v155+x*c155;}
    bool check()const{return c155>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v155=0;c155=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 156 ═══
namespace {
struct WrTool156 {
    float v156 = 156.0f;
    int c156 = 156;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v156+x*c156;}
    bool check()const{return c156>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v156=0;c156=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 157 ═══
namespace {
struct WrTool157 {
    float v157 = 157.0f;
    int c157 = 157;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v157+x*c157;}
    bool check()const{return c157>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v157=0;c157=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 158 ═══
namespace {
struct WrTool158 {
    float v158 = 158.0f;
    int c158 = 158;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v158+x*c158;}
    bool check()const{return c158>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v158=0;c158=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 159 ═══
namespace {
struct WrTool159 {
    float v159 = 159.0f;
    int c159 = 159;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v159+x*c159;}
    bool check()const{return c159>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v159=0;c159=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 160 ═══
namespace {
struct WrTool160 {
    float v160 = 160.0f;
    int c160 = 160;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v160+x*c160;}
    bool check()const{return c160>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v160=0;c160=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 161 ═══
namespace {
struct WrTool161 {
    float v161 = 161.0f;
    int c161 = 161;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v161+x*c161;}
    bool check()const{return c161>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v161=0;c161=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 162 ═══
namespace {
struct WrTool162 {
    float v162 = 162.0f;
    int c162 = 162;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v162+x*c162;}
    bool check()const{return c162>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v162=0;c162=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 163 ═══
namespace {
struct WrTool163 {
    float v163 = 163.0f;
    int c163 = 163;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v163+x*c163;}
    bool check()const{return c163>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v163=0;c163=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 164 ═══
namespace {
struct WrTool164 {
    float v164 = 164.0f;
    int c164 = 164;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v164+x*c164;}
    bool check()const{return c164>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v164=0;c164=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 165 ═══
namespace {
struct WrTool165 {
    float v165 = 165.0f;
    int c165 = 165;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v165+x*c165;}
    bool check()const{return c165>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v165=0;c165=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 166 ═══
namespace {
struct WrTool166 {
    float v166 = 166.0f;
    int c166 = 166;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v166+x*c166;}
    bool check()const{return c166>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v166=0;c166=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ display list builder — section 167 ═══
namespace {
struct WrTool167 {
    float v167 = 167.0f;
    int c167 = 167;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v167+x*c167;}
    bool check()const{return c167>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v167=0;c167=0;m=Mode::Med;}
};
} // anonymous namespace

#ifdef WR_TEST
bool test_wr_display_list_builder(){return true;}
#endif
} // namespace wr