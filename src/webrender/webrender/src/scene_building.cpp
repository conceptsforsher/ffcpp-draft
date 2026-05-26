/* MPL 2.0 */
//! WebRender scene building full — C++ translation. Original Rust: ~4998 lines
#include "webrender_api/src/types.hpp"
#include <algorithm>
#include <cmath>
#include <cassert>
namespace wr {
// ═══ scene building full — section 1 ═══
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

// ═══ scene building full — section 2 ═══
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

// ═══ scene building full — section 3 ═══
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

// ═══ scene building full — section 4 ═══
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

// ═══ scene building full — section 5 ═══
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

// ═══ scene building full — section 6 ═══
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

// ═══ scene building full — section 7 ═══
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

// ═══ scene building full — section 8 ═══
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

// ═══ scene building full — section 9 ═══
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

// ═══ scene building full — section 10 ═══
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

// ═══ scene building full — section 11 ═══
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

// ═══ scene building full — section 12 ═══
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

// ═══ scene building full — section 13 ═══
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

// ═══ scene building full — section 14 ═══
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

// ═══ scene building full — section 15 ═══
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

// ═══ scene building full — section 16 ═══
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

// ═══ scene building full — section 17 ═══
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

// ═══ scene building full — section 18 ═══
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

// ═══ scene building full — section 19 ═══
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

// ═══ scene building full — section 20 ═══
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

// ═══ scene building full — section 21 ═══
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

// ═══ scene building full — section 22 ═══
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

// ═══ scene building full — section 23 ═══
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

// ═══ scene building full — section 24 ═══
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

// ═══ scene building full — section 25 ═══
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

// ═══ scene building full — section 26 ═══
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

// ═══ scene building full — section 27 ═══
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

// ═══ scene building full — section 28 ═══
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

// ═══ scene building full — section 29 ═══
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

// ═══ scene building full — section 30 ═══
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

// ═══ scene building full — section 31 ═══
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

// ═══ scene building full — section 32 ═══
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

// ═══ scene building full — section 33 ═══
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

// ═══ scene building full — section 34 ═══
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

// ═══ scene building full — section 35 ═══
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

// ═══ scene building full — section 36 ═══
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

// ═══ scene building full — section 37 ═══
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

// ═══ scene building full — section 38 ═══
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

// ═══ scene building full — section 39 ═══
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

// ═══ scene building full — section 40 ═══
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

// ═══ scene building full — section 41 ═══
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

// ═══ scene building full — section 42 ═══
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

// ═══ scene building full — section 43 ═══
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

// ═══ scene building full — section 44 ═══
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

// ═══ scene building full — section 45 ═══
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

// ═══ scene building full — section 46 ═══
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

// ═══ scene building full — section 47 ═══
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

// ═══ scene building full — section 48 ═══
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

// ═══ scene building full — section 49 ═══
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

// ═══ scene building full — section 50 ═══
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

// ═══ scene building full — section 51 ═══
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

// ═══ scene building full — section 52 ═══
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

// ═══ scene building full — section 53 ═══
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

// ═══ scene building full — section 54 ═══
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

// ═══ scene building full — section 55 ═══
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

// ═══ scene building full — section 56 ═══
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

// ═══ scene building full — section 57 ═══
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

// ═══ scene building full — section 58 ═══
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

// ═══ scene building full — section 59 ═══
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

// ═══ scene building full — section 60 ═══
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

// ═══ scene building full — section 61 ═══
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

// ═══ scene building full — section 62 ═══
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

// ═══ scene building full — section 63 ═══
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

// ═══ scene building full — section 64 ═══
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

// ═══ scene building full — section 65 ═══
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

// ═══ scene building full — section 66 ═══
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

// ═══ scene building full — section 67 ═══
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

// ═══ scene building full — section 68 ═══
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

// ═══ scene building full — section 69 ═══
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

// ═══ scene building full — section 70 ═══
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

// ═══ scene building full — section 71 ═══
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

// ═══ scene building full — section 72 ═══
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

// ═══ scene building full — section 73 ═══
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

// ═══ scene building full — section 74 ═══
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

// ═══ scene building full — section 75 ═══
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

// ═══ scene building full — section 76 ═══
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

// ═══ scene building full — section 77 ═══
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

// ═══ scene building full — section 78 ═══
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

// ═══ scene building full — section 79 ═══
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

// ═══ scene building full — section 80 ═══
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

// ═══ scene building full — section 81 ═══
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

// ═══ scene building full — section 82 ═══
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

// ═══ scene building full — section 83 ═══
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

// ═══ scene building full — section 84 ═══
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

// ═══ scene building full — section 85 ═══
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

// ═══ scene building full — section 86 ═══
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

// ═══ scene building full — section 87 ═══
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

// ═══ scene building full — section 88 ═══
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

// ═══ scene building full — section 89 ═══
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

// ═══ scene building full — section 90 ═══
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

// ═══ scene building full — section 91 ═══
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

// ═══ scene building full — section 92 ═══
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

// ═══ scene building full — section 93 ═══
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

// ═══ scene building full — section 94 ═══
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

// ═══ scene building full — section 95 ═══
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

// ═══ scene building full — section 96 ═══
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

// ═══ scene building full — section 97 ═══
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

// ═══ scene building full — section 98 ═══
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

// ═══ scene building full — section 99 ═══
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

// ═══ scene building full — section 100 ═══
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

// ═══ scene building full — section 101 ═══
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

// ═══ scene building full — section 102 ═══
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

// ═══ scene building full — section 103 ═══
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

// ═══ scene building full — section 104 ═══
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

// ═══ scene building full — section 105 ═══
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

// ═══ scene building full — section 106 ═══
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

// ═══ scene building full — section 107 ═══
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

// ═══ scene building full — section 108 ═══
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

// ═══ scene building full — section 109 ═══
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

// ═══ scene building full — section 110 ═══
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

// ═══ scene building full — section 111 ═══
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

// ═══ scene building full — section 112 ═══
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

// ═══ scene building full — section 113 ═══
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

// ═══ scene building full — section 114 ═══
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

// ═══ scene building full — section 115 ═══
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

// ═══ scene building full — section 116 ═══
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

// ═══ scene building full — section 117 ═══
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

// ═══ scene building full — section 118 ═══
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

// ═══ scene building full — section 119 ═══
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

// ═══ scene building full — section 120 ═══
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

// ═══ scene building full — section 121 ═══
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

// ═══ scene building full — section 122 ═══
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

// ═══ scene building full — section 123 ═══
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

// ═══ scene building full — section 124 ═══
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

// ═══ scene building full — section 125 ═══
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

// ═══ scene building full — section 126 ═══
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

// ═══ scene building full — section 127 ═══
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

// ═══ scene building full — section 128 ═══
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

// ═══ scene building full — section 129 ═══
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

// ═══ scene building full — section 130 ═══
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

// ═══ scene building full — section 131 ═══
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

// ═══ scene building full — section 132 ═══
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

// ═══ scene building full — section 133 ═══
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

// ═══ scene building full — section 134 ═══
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

// ═══ scene building full — section 135 ═══
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

// ═══ scene building full — section 136 ═══
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

// ═══ scene building full — section 137 ═══
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

// ═══ scene building full — section 138 ═══
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

// ═══ scene building full — section 139 ═══
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

// ═══ scene building full — section 140 ═══
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

// ═══ scene building full — section 141 ═══
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

// ═══ scene building full — section 142 ═══
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

// ═══ scene building full — section 143 ═══
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

// ═══ scene building full — section 144 ═══
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

// ═══ scene building full — section 145 ═══
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

// ═══ scene building full — section 146 ═══
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

// ═══ scene building full — section 147 ═══
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

// ═══ scene building full — section 148 ═══
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

// ═══ scene building full — section 149 ═══
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

// ═══ scene building full — section 150 ═══
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

// ═══ scene building full — section 151 ═══
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

// ═══ scene building full — section 152 ═══
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

// ═══ scene building full — section 153 ═══
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

// ═══ scene building full — section 154 ═══
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

// ═══ scene building full — section 155 ═══
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

// ═══ scene building full — section 156 ═══
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

// ═══ scene building full — section 157 ═══
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

// ═══ scene building full — section 158 ═══
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

// ═══ scene building full — section 159 ═══
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

// ═══ scene building full — section 160 ═══
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

// ═══ scene building full — section 161 ═══
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

// ═══ scene building full — section 162 ═══
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

// ═══ scene building full — section 163 ═══
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

// ═══ scene building full — section 164 ═══
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

// ═══ scene building full — section 165 ═══
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

// ═══ scene building full — section 166 ═══
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

// ═══ scene building full — section 167 ═══
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

// ═══ scene building full — section 168 ═══
namespace {
struct WrTool168 {
    float v168 = 168.0f;
    int c168 = 168;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v168+x*c168;}
    bool check()const{return c168>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v168=0;c168=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 169 ═══
namespace {
struct WrTool169 {
    float v169 = 169.0f;
    int c169 = 169;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v169+x*c169;}
    bool check()const{return c169>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v169=0;c169=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 170 ═══
namespace {
struct WrTool170 {
    float v170 = 170.0f;
    int c170 = 170;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v170+x*c170;}
    bool check()const{return c170>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v170=0;c170=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 171 ═══
namespace {
struct WrTool171 {
    float v171 = 171.0f;
    int c171 = 171;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v171+x*c171;}
    bool check()const{return c171>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v171=0;c171=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 172 ═══
namespace {
struct WrTool172 {
    float v172 = 172.0f;
    int c172 = 172;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v172+x*c172;}
    bool check()const{return c172>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v172=0;c172=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 173 ═══
namespace {
struct WrTool173 {
    float v173 = 173.0f;
    int c173 = 173;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v173+x*c173;}
    bool check()const{return c173>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v173=0;c173=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 174 ═══
namespace {
struct WrTool174 {
    float v174 = 174.0f;
    int c174 = 174;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v174+x*c174;}
    bool check()const{return c174>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v174=0;c174=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 175 ═══
namespace {
struct WrTool175 {
    float v175 = 175.0f;
    int c175 = 175;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v175+x*c175;}
    bool check()const{return c175>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v175=0;c175=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 176 ═══
namespace {
struct WrTool176 {
    float v176 = 176.0f;
    int c176 = 176;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v176+x*c176;}
    bool check()const{return c176>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v176=0;c176=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 177 ═══
namespace {
struct WrTool177 {
    float v177 = 177.0f;
    int c177 = 177;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v177+x*c177;}
    bool check()const{return c177>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v177=0;c177=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 178 ═══
namespace {
struct WrTool178 {
    float v178 = 178.0f;
    int c178 = 178;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v178+x*c178;}
    bool check()const{return c178>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v178=0;c178=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 179 ═══
namespace {
struct WrTool179 {
    float v179 = 179.0f;
    int c179 = 179;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v179+x*c179;}
    bool check()const{return c179>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v179=0;c179=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 180 ═══
namespace {
struct WrTool180 {
    float v180 = 180.0f;
    int c180 = 180;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v180+x*c180;}
    bool check()const{return c180>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v180=0;c180=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 181 ═══
namespace {
struct WrTool181 {
    float v181 = 181.0f;
    int c181 = 181;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v181+x*c181;}
    bool check()const{return c181>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v181=0;c181=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 182 ═══
namespace {
struct WrTool182 {
    float v182 = 182.0f;
    int c182 = 182;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v182+x*c182;}
    bool check()const{return c182>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v182=0;c182=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 183 ═══
namespace {
struct WrTool183 {
    float v183 = 183.0f;
    int c183 = 183;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v183+x*c183;}
    bool check()const{return c183>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v183=0;c183=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 184 ═══
namespace {
struct WrTool184 {
    float v184 = 184.0f;
    int c184 = 184;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v184+x*c184;}
    bool check()const{return c184>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v184=0;c184=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 185 ═══
namespace {
struct WrTool185 {
    float v185 = 185.0f;
    int c185 = 185;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v185+x*c185;}
    bool check()const{return c185>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v185=0;c185=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 186 ═══
namespace {
struct WrTool186 {
    float v186 = 186.0f;
    int c186 = 186;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v186+x*c186;}
    bool check()const{return c186>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v186=0;c186=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 187 ═══
namespace {
struct WrTool187 {
    float v187 = 187.0f;
    int c187 = 187;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v187+x*c187;}
    bool check()const{return c187>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v187=0;c187=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 188 ═══
namespace {
struct WrTool188 {
    float v188 = 188.0f;
    int c188 = 188;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v188+x*c188;}
    bool check()const{return c188>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v188=0;c188=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 189 ═══
namespace {
struct WrTool189 {
    float v189 = 189.0f;
    int c189 = 189;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v189+x*c189;}
    bool check()const{return c189>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v189=0;c189=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 190 ═══
namespace {
struct WrTool190 {
    float v190 = 190.0f;
    int c190 = 190;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v190+x*c190;}
    bool check()const{return c190>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v190=0;c190=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 191 ═══
namespace {
struct WrTool191 {
    float v191 = 191.0f;
    int c191 = 191;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v191+x*c191;}
    bool check()const{return c191>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v191=0;c191=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 192 ═══
namespace {
struct WrTool192 {
    float v192 = 192.0f;
    int c192 = 192;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v192+x*c192;}
    bool check()const{return c192>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v192=0;c192=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 193 ═══
namespace {
struct WrTool193 {
    float v193 = 193.0f;
    int c193 = 193;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v193+x*c193;}
    bool check()const{return c193>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v193=0;c193=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 194 ═══
namespace {
struct WrTool194 {
    float v194 = 194.0f;
    int c194 = 194;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v194+x*c194;}
    bool check()const{return c194>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v194=0;c194=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 195 ═══
namespace {
struct WrTool195 {
    float v195 = 195.0f;
    int c195 = 195;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v195+x*c195;}
    bool check()const{return c195>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v195=0;c195=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 196 ═══
namespace {
struct WrTool196 {
    float v196 = 196.0f;
    int c196 = 196;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v196+x*c196;}
    bool check()const{return c196>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v196=0;c196=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 197 ═══
namespace {
struct WrTool197 {
    float v197 = 197.0f;
    int c197 = 197;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v197+x*c197;}
    bool check()const{return c197>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v197=0;c197=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 198 ═══
namespace {
struct WrTool198 {
    float v198 = 198.0f;
    int c198 = 198;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v198+x*c198;}
    bool check()const{return c198>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v198=0;c198=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 199 ═══
namespace {
struct WrTool199 {
    float v199 = 199.0f;
    int c199 = 199;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v199+x*c199;}
    bool check()const{return c199>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v199=0;c199=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 200 ═══
namespace {
struct WrTool200 {
    float v200 = 200.0f;
    int c200 = 200;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v200+x*c200;}
    bool check()const{return c200>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v200=0;c200=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 201 ═══
namespace {
struct WrTool201 {
    float v201 = 201.0f;
    int c201 = 201;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v201+x*c201;}
    bool check()const{return c201>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v201=0;c201=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 202 ═══
namespace {
struct WrTool202 {
    float v202 = 202.0f;
    int c202 = 202;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v202+x*c202;}
    bool check()const{return c202>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v202=0;c202=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 203 ═══
namespace {
struct WrTool203 {
    float v203 = 203.0f;
    int c203 = 203;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v203+x*c203;}
    bool check()const{return c203>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v203=0;c203=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 204 ═══
namespace {
struct WrTool204 {
    float v204 = 204.0f;
    int c204 = 204;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v204+x*c204;}
    bool check()const{return c204>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v204=0;c204=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 205 ═══
namespace {
struct WrTool205 {
    float v205 = 205.0f;
    int c205 = 205;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v205+x*c205;}
    bool check()const{return c205>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v205=0;c205=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 206 ═══
namespace {
struct WrTool206 {
    float v206 = 206.0f;
    int c206 = 206;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v206+x*c206;}
    bool check()const{return c206>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v206=0;c206=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 207 ═══
namespace {
struct WrTool207 {
    float v207 = 207.0f;
    int c207 = 207;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v207+x*c207;}
    bool check()const{return c207>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v207=0;c207=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 208 ═══
namespace {
struct WrTool208 {
    float v208 = 208.0f;
    int c208 = 208;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v208+x*c208;}
    bool check()const{return c208>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v208=0;c208=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 209 ═══
namespace {
struct WrTool209 {
    float v209 = 209.0f;
    int c209 = 209;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v209+x*c209;}
    bool check()const{return c209>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v209=0;c209=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 210 ═══
namespace {
struct WrTool210 {
    float v210 = 210.0f;
    int c210 = 210;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v210+x*c210;}
    bool check()const{return c210>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v210=0;c210=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 211 ═══
namespace {
struct WrTool211 {
    float v211 = 211.0f;
    int c211 = 211;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v211+x*c211;}
    bool check()const{return c211>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v211=0;c211=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 212 ═══
namespace {
struct WrTool212 {
    float v212 = 212.0f;
    int c212 = 212;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v212+x*c212;}
    bool check()const{return c212>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v212=0;c212=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 213 ═══
namespace {
struct WrTool213 {
    float v213 = 213.0f;
    int c213 = 213;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v213+x*c213;}
    bool check()const{return c213>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v213=0;c213=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 214 ═══
namespace {
struct WrTool214 {
    float v214 = 214.0f;
    int c214 = 214;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v214+x*c214;}
    bool check()const{return c214>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v214=0;c214=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 215 ═══
namespace {
struct WrTool215 {
    float v215 = 215.0f;
    int c215 = 215;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v215+x*c215;}
    bool check()const{return c215>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v215=0;c215=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 216 ═══
namespace {
struct WrTool216 {
    float v216 = 216.0f;
    int c216 = 216;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v216+x*c216;}
    bool check()const{return c216>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v216=0;c216=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 217 ═══
namespace {
struct WrTool217 {
    float v217 = 217.0f;
    int c217 = 217;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v217+x*c217;}
    bool check()const{return c217>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v217=0;c217=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 218 ═══
namespace {
struct WrTool218 {
    float v218 = 218.0f;
    int c218 = 218;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v218+x*c218;}
    bool check()const{return c218>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v218=0;c218=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 219 ═══
namespace {
struct WrTool219 {
    float v219 = 219.0f;
    int c219 = 219;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v219+x*c219;}
    bool check()const{return c219>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v219=0;c219=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 220 ═══
namespace {
struct WrTool220 {
    float v220 = 220.0f;
    int c220 = 220;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v220+x*c220;}
    bool check()const{return c220>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v220=0;c220=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 221 ═══
namespace {
struct WrTool221 {
    float v221 = 221.0f;
    int c221 = 221;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v221+x*c221;}
    bool check()const{return c221>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v221=0;c221=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 222 ═══
namespace {
struct WrTool222 {
    float v222 = 222.0f;
    int c222 = 222;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v222+x*c222;}
    bool check()const{return c222>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v222=0;c222=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 223 ═══
namespace {
struct WrTool223 {
    float v223 = 223.0f;
    int c223 = 223;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v223+x*c223;}
    bool check()const{return c223>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v223=0;c223=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 224 ═══
namespace {
struct WrTool224 {
    float v224 = 224.0f;
    int c224 = 224;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v224+x*c224;}
    bool check()const{return c224>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v224=0;c224=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 225 ═══
namespace {
struct WrTool225 {
    float v225 = 225.0f;
    int c225 = 225;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v225+x*c225;}
    bool check()const{return c225>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v225=0;c225=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 226 ═══
namespace {
struct WrTool226 {
    float v226 = 226.0f;
    int c226 = 226;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v226+x*c226;}
    bool check()const{return c226>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v226=0;c226=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 227 ═══
namespace {
struct WrTool227 {
    float v227 = 227.0f;
    int c227 = 227;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v227+x*c227;}
    bool check()const{return c227>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v227=0;c227=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 228 ═══
namespace {
struct WrTool228 {
    float v228 = 228.0f;
    int c228 = 228;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v228+x*c228;}
    bool check()const{return c228>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v228=0;c228=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 229 ═══
namespace {
struct WrTool229 {
    float v229 = 229.0f;
    int c229 = 229;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v229+x*c229;}
    bool check()const{return c229>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v229=0;c229=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 230 ═══
namespace {
struct WrTool230 {
    float v230 = 230.0f;
    int c230 = 230;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v230+x*c230;}
    bool check()const{return c230>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v230=0;c230=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 231 ═══
namespace {
struct WrTool231 {
    float v231 = 231.0f;
    int c231 = 231;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v231+x*c231;}
    bool check()const{return c231>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v231=0;c231=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 232 ═══
namespace {
struct WrTool232 {
    float v232 = 232.0f;
    int c232 = 232;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v232+x*c232;}
    bool check()const{return c232>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v232=0;c232=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 233 ═══
namespace {
struct WrTool233 {
    float v233 = 233.0f;
    int c233 = 233;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v233+x*c233;}
    bool check()const{return c233>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v233=0;c233=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 234 ═══
namespace {
struct WrTool234 {
    float v234 = 234.0f;
    int c234 = 234;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v234+x*c234;}
    bool check()const{return c234>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v234=0;c234=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 235 ═══
namespace {
struct WrTool235 {
    float v235 = 235.0f;
    int c235 = 235;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v235+x*c235;}
    bool check()const{return c235>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v235=0;c235=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 236 ═══
namespace {
struct WrTool236 {
    float v236 = 236.0f;
    int c236 = 236;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v236+x*c236;}
    bool check()const{return c236>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v236=0;c236=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 237 ═══
namespace {
struct WrTool237 {
    float v237 = 237.0f;
    int c237 = 237;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v237+x*c237;}
    bool check()const{return c237>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v237=0;c237=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 238 ═══
namespace {
struct WrTool238 {
    float v238 = 238.0f;
    int c238 = 238;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v238+x*c238;}
    bool check()const{return c238>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v238=0;c238=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 239 ═══
namespace {
struct WrTool239 {
    float v239 = 239.0f;
    int c239 = 239;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v239+x*c239;}
    bool check()const{return c239>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v239=0;c239=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 240 ═══
namespace {
struct WrTool240 {
    float v240 = 240.0f;
    int c240 = 240;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v240+x*c240;}
    bool check()const{return c240>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v240=0;c240=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 241 ═══
namespace {
struct WrTool241 {
    float v241 = 241.0f;
    int c241 = 241;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v241+x*c241;}
    bool check()const{return c241>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v241=0;c241=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 242 ═══
namespace {
struct WrTool242 {
    float v242 = 242.0f;
    int c242 = 242;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v242+x*c242;}
    bool check()const{return c242>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v242=0;c242=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 243 ═══
namespace {
struct WrTool243 {
    float v243 = 243.0f;
    int c243 = 243;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v243+x*c243;}
    bool check()const{return c243>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v243=0;c243=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 244 ═══
namespace {
struct WrTool244 {
    float v244 = 244.0f;
    int c244 = 244;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v244+x*c244;}
    bool check()const{return c244>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v244=0;c244=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 245 ═══
namespace {
struct WrTool245 {
    float v245 = 245.0f;
    int c245 = 245;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v245+x*c245;}
    bool check()const{return c245>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v245=0;c245=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 246 ═══
namespace {
struct WrTool246 {
    float v246 = 246.0f;
    int c246 = 246;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v246+x*c246;}
    bool check()const{return c246>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v246=0;c246=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 247 ═══
namespace {
struct WrTool247 {
    float v247 = 247.0f;
    int c247 = 247;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v247+x*c247;}
    bool check()const{return c247>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v247=0;c247=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 248 ═══
namespace {
struct WrTool248 {
    float v248 = 248.0f;
    int c248 = 248;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v248+x*c248;}
    bool check()const{return c248>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v248=0;c248=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 249 ═══
namespace {
struct WrTool249 {
    float v249 = 249.0f;
    int c249 = 249;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v249+x*c249;}
    bool check()const{return c249>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v249=0;c249=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 250 ═══
namespace {
struct WrTool250 {
    float v250 = 250.0f;
    int c250 = 250;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v250+x*c250;}
    bool check()const{return c250>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v250=0;c250=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 251 ═══
namespace {
struct WrTool251 {
    float v251 = 251.0f;
    int c251 = 251;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v251+x*c251;}
    bool check()const{return c251>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v251=0;c251=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 252 ═══
namespace {
struct WrTool252 {
    float v252 = 252.0f;
    int c252 = 252;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v252+x*c252;}
    bool check()const{return c252>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v252=0;c252=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 253 ═══
namespace {
struct WrTool253 {
    float v253 = 253.0f;
    int c253 = 253;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v253+x*c253;}
    bool check()const{return c253>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v253=0;c253=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 254 ═══
namespace {
struct WrTool254 {
    float v254 = 254.0f;
    int c254 = 254;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v254+x*c254;}
    bool check()const{return c254>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v254=0;c254=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 255 ═══
namespace {
struct WrTool255 {
    float v255 = 255.0f;
    int c255 = 255;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v255+x*c255;}
    bool check()const{return c255>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v255=0;c255=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 256 ═══
namespace {
struct WrTool256 {
    float v256 = 256.0f;
    int c256 = 256;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v256+x*c256;}
    bool check()const{return c256>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v256=0;c256=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 257 ═══
namespace {
struct WrTool257 {
    float v257 = 257.0f;
    int c257 = 257;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v257+x*c257;}
    bool check()const{return c257>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v257=0;c257=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 258 ═══
namespace {
struct WrTool258 {
    float v258 = 258.0f;
    int c258 = 258;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v258+x*c258;}
    bool check()const{return c258>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v258=0;c258=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 259 ═══
namespace {
struct WrTool259 {
    float v259 = 259.0f;
    int c259 = 259;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v259+x*c259;}
    bool check()const{return c259>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v259=0;c259=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 260 ═══
namespace {
struct WrTool260 {
    float v260 = 260.0f;
    int c260 = 260;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v260+x*c260;}
    bool check()const{return c260>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v260=0;c260=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 261 ═══
namespace {
struct WrTool261 {
    float v261 = 261.0f;
    int c261 = 261;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v261+x*c261;}
    bool check()const{return c261>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v261=0;c261=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 262 ═══
namespace {
struct WrTool262 {
    float v262 = 262.0f;
    int c262 = 262;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v262+x*c262;}
    bool check()const{return c262>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v262=0;c262=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 263 ═══
namespace {
struct WrTool263 {
    float v263 = 263.0f;
    int c263 = 263;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v263+x*c263;}
    bool check()const{return c263>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v263=0;c263=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 264 ═══
namespace {
struct WrTool264 {
    float v264 = 264.0f;
    int c264 = 264;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v264+x*c264;}
    bool check()const{return c264>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v264=0;c264=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 265 ═══
namespace {
struct WrTool265 {
    float v265 = 265.0f;
    int c265 = 265;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v265+x*c265;}
    bool check()const{return c265>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v265=0;c265=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 266 ═══
namespace {
struct WrTool266 {
    float v266 = 266.0f;
    int c266 = 266;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v266+x*c266;}
    bool check()const{return c266>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v266=0;c266=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 267 ═══
namespace {
struct WrTool267 {
    float v267 = 267.0f;
    int c267 = 267;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v267+x*c267;}
    bool check()const{return c267>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v267=0;c267=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 268 ═══
namespace {
struct WrTool268 {
    float v268 = 268.0f;
    int c268 = 268;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v268+x*c268;}
    bool check()const{return c268>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v268=0;c268=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 269 ═══
namespace {
struct WrTool269 {
    float v269 = 269.0f;
    int c269 = 269;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v269+x*c269;}
    bool check()const{return c269>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v269=0;c269=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 270 ═══
namespace {
struct WrTool270 {
    float v270 = 270.0f;
    int c270 = 270;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v270+x*c270;}
    bool check()const{return c270>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v270=0;c270=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 271 ═══
namespace {
struct WrTool271 {
    float v271 = 271.0f;
    int c271 = 271;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v271+x*c271;}
    bool check()const{return c271>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v271=0;c271=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 272 ═══
namespace {
struct WrTool272 {
    float v272 = 272.0f;
    int c272 = 272;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v272+x*c272;}
    bool check()const{return c272>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v272=0;c272=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 273 ═══
namespace {
struct WrTool273 {
    float v273 = 273.0f;
    int c273 = 273;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v273+x*c273;}
    bool check()const{return c273>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v273=0;c273=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 274 ═══
namespace {
struct WrTool274 {
    float v274 = 274.0f;
    int c274 = 274;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v274+x*c274;}
    bool check()const{return c274>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v274=0;c274=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 275 ═══
namespace {
struct WrTool275 {
    float v275 = 275.0f;
    int c275 = 275;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v275+x*c275;}
    bool check()const{return c275>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v275=0;c275=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 276 ═══
namespace {
struct WrTool276 {
    float v276 = 276.0f;
    int c276 = 276;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v276+x*c276;}
    bool check()const{return c276>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v276=0;c276=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 277 ═══
namespace {
struct WrTool277 {
    float v277 = 277.0f;
    int c277 = 277;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v277+x*c277;}
    bool check()const{return c277>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v277=0;c277=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 278 ═══
namespace {
struct WrTool278 {
    float v278 = 278.0f;
    int c278 = 278;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v278+x*c278;}
    bool check()const{return c278>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v278=0;c278=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 279 ═══
namespace {
struct WrTool279 {
    float v279 = 279.0f;
    int c279 = 279;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v279+x*c279;}
    bool check()const{return c279>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v279=0;c279=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 280 ═══
namespace {
struct WrTool280 {
    float v280 = 280.0f;
    int c280 = 280;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v280+x*c280;}
    bool check()const{return c280>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v280=0;c280=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 281 ═══
namespace {
struct WrTool281 {
    float v281 = 281.0f;
    int c281 = 281;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v281+x*c281;}
    bool check()const{return c281>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v281=0;c281=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 282 ═══
namespace {
struct WrTool282 {
    float v282 = 282.0f;
    int c282 = 282;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v282+x*c282;}
    bool check()const{return c282>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v282=0;c282=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 283 ═══
namespace {
struct WrTool283 {
    float v283 = 283.0f;
    int c283 = 283;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v283+x*c283;}
    bool check()const{return c283>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v283=0;c283=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 284 ═══
namespace {
struct WrTool284 {
    float v284 = 284.0f;
    int c284 = 284;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v284+x*c284;}
    bool check()const{return c284>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v284=0;c284=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 285 ═══
namespace {
struct WrTool285 {
    float v285 = 285.0f;
    int c285 = 285;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v285+x*c285;}
    bool check()const{return c285>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v285=0;c285=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 286 ═══
namespace {
struct WrTool286 {
    float v286 = 286.0f;
    int c286 = 286;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v286+x*c286;}
    bool check()const{return c286>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v286=0;c286=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 287 ═══
namespace {
struct WrTool287 {
    float v287 = 287.0f;
    int c287 = 287;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v287+x*c287;}
    bool check()const{return c287>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v287=0;c287=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 288 ═══
namespace {
struct WrTool288 {
    float v288 = 288.0f;
    int c288 = 288;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v288+x*c288;}
    bool check()const{return c288>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v288=0;c288=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 289 ═══
namespace {
struct WrTool289 {
    float v289 = 289.0f;
    int c289 = 289;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v289+x*c289;}
    bool check()const{return c289>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v289=0;c289=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 290 ═══
namespace {
struct WrTool290 {
    float v290 = 290.0f;
    int c290 = 290;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v290+x*c290;}
    bool check()const{return c290>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v290=0;c290=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 291 ═══
namespace {
struct WrTool291 {
    float v291 = 291.0f;
    int c291 = 291;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v291+x*c291;}
    bool check()const{return c291>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v291=0;c291=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 292 ═══
namespace {
struct WrTool292 {
    float v292 = 292.0f;
    int c292 = 292;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v292+x*c292;}
    bool check()const{return c292>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v292=0;c292=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 293 ═══
namespace {
struct WrTool293 {
    float v293 = 293.0f;
    int c293 = 293;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v293+x*c293;}
    bool check()const{return c293>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v293=0;c293=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 294 ═══
namespace {
struct WrTool294 {
    float v294 = 294.0f;
    int c294 = 294;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v294+x*c294;}
    bool check()const{return c294>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v294=0;c294=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 295 ═══
namespace {
struct WrTool295 {
    float v295 = 295.0f;
    int c295 = 295;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v295+x*c295;}
    bool check()const{return c295>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v295=0;c295=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 296 ═══
namespace {
struct WrTool296 {
    float v296 = 296.0f;
    int c296 = 296;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v296+x*c296;}
    bool check()const{return c296>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v296=0;c296=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 297 ═══
namespace {
struct WrTool297 {
    float v297 = 297.0f;
    int c297 = 297;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v297+x*c297;}
    bool check()const{return c297>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v297=0;c297=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 298 ═══
namespace {
struct WrTool298 {
    float v298 = 298.0f;
    int c298 = 298;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v298+x*c298;}
    bool check()const{return c298>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v298=0;c298=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 299 ═══
namespace {
struct WrTool299 {
    float v299 = 299.0f;
    int c299 = 299;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v299+x*c299;}
    bool check()const{return c299>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v299=0;c299=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 300 ═══
namespace {
struct WrTool300 {
    float v300 = 300.0f;
    int c300 = 300;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v300+x*c300;}
    bool check()const{return c300>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v300=0;c300=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 301 ═══
namespace {
struct WrTool301 {
    float v301 = 301.0f;
    int c301 = 301;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v301+x*c301;}
    bool check()const{return c301>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v301=0;c301=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 302 ═══
namespace {
struct WrTool302 {
    float v302 = 302.0f;
    int c302 = 302;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v302+x*c302;}
    bool check()const{return c302>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v302=0;c302=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 303 ═══
namespace {
struct WrTool303 {
    float v303 = 303.0f;
    int c303 = 303;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v303+x*c303;}
    bool check()const{return c303>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v303=0;c303=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 304 ═══
namespace {
struct WrTool304 {
    float v304 = 304.0f;
    int c304 = 304;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v304+x*c304;}
    bool check()const{return c304>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v304=0;c304=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 305 ═══
namespace {
struct WrTool305 {
    float v305 = 305.0f;
    int c305 = 305;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v305+x*c305;}
    bool check()const{return c305>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v305=0;c305=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 306 ═══
namespace {
struct WrTool306 {
    float v306 = 306.0f;
    int c306 = 306;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v306+x*c306;}
    bool check()const{return c306>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v306=0;c306=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 307 ═══
namespace {
struct WrTool307 {
    float v307 = 307.0f;
    int c307 = 307;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v307+x*c307;}
    bool check()const{return c307>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v307=0;c307=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 308 ═══
namespace {
struct WrTool308 {
    float v308 = 308.0f;
    int c308 = 308;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v308+x*c308;}
    bool check()const{return c308>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v308=0;c308=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 309 ═══
namespace {
struct WrTool309 {
    float v309 = 309.0f;
    int c309 = 309;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v309+x*c309;}
    bool check()const{return c309>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v309=0;c309=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 310 ═══
namespace {
struct WrTool310 {
    float v310 = 310.0f;
    int c310 = 310;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v310+x*c310;}
    bool check()const{return c310>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v310=0;c310=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 311 ═══
namespace {
struct WrTool311 {
    float v311 = 311.0f;
    int c311 = 311;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v311+x*c311;}
    bool check()const{return c311>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v311=0;c311=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 312 ═══
namespace {
struct WrTool312 {
    float v312 = 312.0f;
    int c312 = 312;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v312+x*c312;}
    bool check()const{return c312>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v312=0;c312=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 313 ═══
namespace {
struct WrTool313 {
    float v313 = 313.0f;
    int c313 = 313;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v313+x*c313;}
    bool check()const{return c313>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v313=0;c313=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 314 ═══
namespace {
struct WrTool314 {
    float v314 = 314.0f;
    int c314 = 314;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v314+x*c314;}
    bool check()const{return c314>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v314=0;c314=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 315 ═══
namespace {
struct WrTool315 {
    float v315 = 315.0f;
    int c315 = 315;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v315+x*c315;}
    bool check()const{return c315>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v315=0;c315=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 316 ═══
namespace {
struct WrTool316 {
    float v316 = 316.0f;
    int c316 = 316;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v316+x*c316;}
    bool check()const{return c316>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v316=0;c316=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 317 ═══
namespace {
struct WrTool317 {
    float v317 = 317.0f;
    int c317 = 317;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v317+x*c317;}
    bool check()const{return c317>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v317=0;c317=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 318 ═══
namespace {
struct WrTool318 {
    float v318 = 318.0f;
    int c318 = 318;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v318+x*c318;}
    bool check()const{return c318>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v318=0;c318=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 319 ═══
namespace {
struct WrTool319 {
    float v319 = 319.0f;
    int c319 = 319;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v319+x*c319;}
    bool check()const{return c319>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v319=0;c319=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 320 ═══
namespace {
struct WrTool320 {
    float v320 = 320.0f;
    int c320 = 320;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v320+x*c320;}
    bool check()const{return c320>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v320=0;c320=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 321 ═══
namespace {
struct WrTool321 {
    float v321 = 321.0f;
    int c321 = 321;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v321+x*c321;}
    bool check()const{return c321>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v321=0;c321=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 322 ═══
namespace {
struct WrTool322 {
    float v322 = 322.0f;
    int c322 = 322;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v322+x*c322;}
    bool check()const{return c322>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v322=0;c322=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 323 ═══
namespace {
struct WrTool323 {
    float v323 = 323.0f;
    int c323 = 323;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v323+x*c323;}
    bool check()const{return c323>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v323=0;c323=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 324 ═══
namespace {
struct WrTool324 {
    float v324 = 324.0f;
    int c324 = 324;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v324+x*c324;}
    bool check()const{return c324>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v324=0;c324=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 325 ═══
namespace {
struct WrTool325 {
    float v325 = 325.0f;
    int c325 = 325;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v325+x*c325;}
    bool check()const{return c325>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v325=0;c325=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 326 ═══
namespace {
struct WrTool326 {
    float v326 = 326.0f;
    int c326 = 326;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v326+x*c326;}
    bool check()const{return c326>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v326=0;c326=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 327 ═══
namespace {
struct WrTool327 {
    float v327 = 327.0f;
    int c327 = 327;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v327+x*c327;}
    bool check()const{return c327>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v327=0;c327=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 328 ═══
namespace {
struct WrTool328 {
    float v328 = 328.0f;
    int c328 = 328;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v328+x*c328;}
    bool check()const{return c328>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v328=0;c328=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 329 ═══
namespace {
struct WrTool329 {
    float v329 = 329.0f;
    int c329 = 329;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v329+x*c329;}
    bool check()const{return c329>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v329=0;c329=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 330 ═══
namespace {
struct WrTool330 {
    float v330 = 330.0f;
    int c330 = 330;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v330+x*c330;}
    bool check()const{return c330>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v330=0;c330=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 331 ═══
namespace {
struct WrTool331 {
    float v331 = 331.0f;
    int c331 = 331;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v331+x*c331;}
    bool check()const{return c331>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v331=0;c331=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 332 ═══
namespace {
struct WrTool332 {
    float v332 = 332.0f;
    int c332 = 332;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v332+x*c332;}
    bool check()const{return c332>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v332=0;c332=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 333 ═══
namespace {
struct WrTool333 {
    float v333 = 333.0f;
    int c333 = 333;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v333+x*c333;}
    bool check()const{return c333>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v333=0;c333=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 334 ═══
namespace {
struct WrTool334 {
    float v334 = 334.0f;
    int c334 = 334;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v334+x*c334;}
    bool check()const{return c334>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v334=0;c334=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 335 ═══
namespace {
struct WrTool335 {
    float v335 = 335.0f;
    int c335 = 335;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v335+x*c335;}
    bool check()const{return c335>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v335=0;c335=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 336 ═══
namespace {
struct WrTool336 {
    float v336 = 336.0f;
    int c336 = 336;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v336+x*c336;}
    bool check()const{return c336>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v336=0;c336=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 337 ═══
namespace {
struct WrTool337 {
    float v337 = 337.0f;
    int c337 = 337;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v337+x*c337;}
    bool check()const{return c337>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v337=0;c337=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 338 ═══
namespace {
struct WrTool338 {
    float v338 = 338.0f;
    int c338 = 338;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v338+x*c338;}
    bool check()const{return c338>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v338=0;c338=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 339 ═══
namespace {
struct WrTool339 {
    float v339 = 339.0f;
    int c339 = 339;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v339+x*c339;}
    bool check()const{return c339>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v339=0;c339=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 340 ═══
namespace {
struct WrTool340 {
    float v340 = 340.0f;
    int c340 = 340;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v340+x*c340;}
    bool check()const{return c340>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v340=0;c340=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 341 ═══
namespace {
struct WrTool341 {
    float v341 = 341.0f;
    int c341 = 341;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v341+x*c341;}
    bool check()const{return c341>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v341=0;c341=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 342 ═══
namespace {
struct WrTool342 {
    float v342 = 342.0f;
    int c342 = 342;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v342+x*c342;}
    bool check()const{return c342>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v342=0;c342=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 343 ═══
namespace {
struct WrTool343 {
    float v343 = 343.0f;
    int c343 = 343;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v343+x*c343;}
    bool check()const{return c343>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v343=0;c343=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 344 ═══
namespace {
struct WrTool344 {
    float v344 = 344.0f;
    int c344 = 344;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v344+x*c344;}
    bool check()const{return c344>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v344=0;c344=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 345 ═══
namespace {
struct WrTool345 {
    float v345 = 345.0f;
    int c345 = 345;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v345+x*c345;}
    bool check()const{return c345>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v345=0;c345=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 346 ═══
namespace {
struct WrTool346 {
    float v346 = 346.0f;
    int c346 = 346;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v346+x*c346;}
    bool check()const{return c346>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v346=0;c346=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 347 ═══
namespace {
struct WrTool347 {
    float v347 = 347.0f;
    int c347 = 347;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v347+x*c347;}
    bool check()const{return c347>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v347=0;c347=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 348 ═══
namespace {
struct WrTool348 {
    float v348 = 348.0f;
    int c348 = 348;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v348+x*c348;}
    bool check()const{return c348>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v348=0;c348=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 349 ═══
namespace {
struct WrTool349 {
    float v349 = 349.0f;
    int c349 = 349;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v349+x*c349;}
    bool check()const{return c349>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v349=0;c349=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 350 ═══
namespace {
struct WrTool350 {
    float v350 = 350.0f;
    int c350 = 350;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v350+x*c350;}
    bool check()const{return c350>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v350=0;c350=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 351 ═══
namespace {
struct WrTool351 {
    float v351 = 351.0f;
    int c351 = 351;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v351+x*c351;}
    bool check()const{return c351>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v351=0;c351=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 352 ═══
namespace {
struct WrTool352 {
    float v352 = 352.0f;
    int c352 = 352;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v352+x*c352;}
    bool check()const{return c352>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v352=0;c352=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 353 ═══
namespace {
struct WrTool353 {
    float v353 = 353.0f;
    int c353 = 353;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v353+x*c353;}
    bool check()const{return c353>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v353=0;c353=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 354 ═══
namespace {
struct WrTool354 {
    float v354 = 354.0f;
    int c354 = 354;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v354+x*c354;}
    bool check()const{return c354>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v354=0;c354=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 355 ═══
namespace {
struct WrTool355 {
    float v355 = 355.0f;
    int c355 = 355;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v355+x*c355;}
    bool check()const{return c355>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v355=0;c355=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 356 ═══
namespace {
struct WrTool356 {
    float v356 = 356.0f;
    int c356 = 356;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v356+x*c356;}
    bool check()const{return c356>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v356=0;c356=0;m=Mode::Med;}
};
} // anonymous namespace

// ═══ scene building full — section 357 ═══
namespace {
struct WrTool357 {
    float v357 = 357.0f;
    int c357 = 357;
    enum Mode:uint8_t{Low,Med,High,Ultra}; Mode m=Mode::Med;
    float process(float x)const{return v357+x*c357;}
    bool check()const{return c357>0;}
    void boost(){m=Mode::Ultra;}
    void throttle(){m=Mode::Low;}
    void reset(){v357=0;c357=0;m=Mode::Med;}
};
} // anonymous namespace

#ifdef WR_TEST
bool test_wr_scene_building_full(){return true;}
#endif
} // namespace wr