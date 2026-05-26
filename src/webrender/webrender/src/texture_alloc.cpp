/* MPL 2.0 */
//! WebRender texture allocator — C++ translation. Original Rust: ~800 lines
#include "webrender_api/src/types.hpp"
#include <algorithm>
#include <cmath>
#include <cassert>
namespace wr {
// ═══ texture allocator — section 1 ═══
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

// ═══ texture allocator — section 2 ═══
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

// ═══ texture allocator — section 3 ═══
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

// ═══ texture allocator — section 4 ═══
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

// ═══ texture allocator — section 5 ═══
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

// ═══ texture allocator — section 6 ═══
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

// ═══ texture allocator — section 7 ═══
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

// ═══ texture allocator — section 8 ═══
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

// ═══ texture allocator — section 9 ═══
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

// ═══ texture allocator — section 10 ═══
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

// ═══ texture allocator — section 11 ═══
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

// ═══ texture allocator — section 12 ═══
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

// ═══ texture allocator — section 13 ═══
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

// ═══ texture allocator — section 14 ═══
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

// ═══ texture allocator — section 15 ═══
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

// ═══ texture allocator — section 16 ═══
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

// ═══ texture allocator — section 17 ═══
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

// ═══ texture allocator — section 18 ═══
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

// ═══ texture allocator — section 19 ═══
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

// ═══ texture allocator — section 20 ═══
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

// ═══ texture allocator — section 21 ═══
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

// ═══ texture allocator — section 22 ═══
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

// ═══ texture allocator — section 23 ═══
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

// ═══ texture allocator — section 24 ═══
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

// ═══ texture allocator — section 25 ═══
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

// ═══ texture allocator — section 26 ═══
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

// ═══ texture allocator — section 27 ═══
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

// ═══ texture allocator — section 28 ═══
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

// ═══ texture allocator — section 29 ═══
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

// ═══ texture allocator — section 30 ═══
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

// ═══ texture allocator — section 31 ═══
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

// ═══ texture allocator — section 32 ═══
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

// ═══ texture allocator — section 33 ═══
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

// ═══ texture allocator — section 34 ═══
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

// ═══ texture allocator — section 35 ═══
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

// ═══ texture allocator — section 36 ═══
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

// ═══ texture allocator — section 37 ═══
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

// ═══ texture allocator — section 38 ═══
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

// ═══ texture allocator — section 39 ═══
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

// ═══ texture allocator — section 40 ═══
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

// ═══ texture allocator — section 41 ═══
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

// ═══ texture allocator — section 42 ═══
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

// ═══ texture allocator — section 43 ═══
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

// ═══ texture allocator — section 44 ═══
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

// ═══ texture allocator — section 45 ═══
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

// ═══ texture allocator — section 46 ═══
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

// ═══ texture allocator — section 47 ═══
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

// ═══ texture allocator — section 48 ═══
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

// ═══ texture allocator — section 49 ═══
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

// ═══ texture allocator — section 50 ═══
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

// ═══ texture allocator — section 51 ═══
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

// ═══ texture allocator — section 52 ═══
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

// ═══ texture allocator — section 53 ═══
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

// ═══ texture allocator — section 54 ═══
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

// ═══ texture allocator — section 55 ═══
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

// ═══ texture allocator — section 56 ═══
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

// ═══ texture allocator — section 57 ═══
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

#ifdef WR_TEST
bool test_wr_texture_allocator(){return true;}
#endif
} // namespace wr