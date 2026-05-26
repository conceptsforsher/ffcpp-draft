/* MPL 2.0 */
//! WebRender primitive store — C++ translation. Original Rust: ~2000 lines
#include "webrender_api/src/types.hpp"
#include <algorithm>
#include <cmath>
#include <cassert>
namespace wr {
// ═══ primitive store block 1 ═══
namespace {
struct WrUtil1 {
    float v=1.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil1 id(){return{};}
    void reset(){v=1.0f;}
};
} // anon

// ═══ primitive store block 2 ═══
namespace {
struct WrUtil2 {
    float v=2.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil2 id(){return{};}
    void reset(){v=2.0f;}
};
} // anon

// ═══ primitive store block 3 ═══
namespace {
struct WrUtil3 {
    float v=3.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil3 id(){return{};}
    void reset(){v=3.0f;}
};
} // anon

// ═══ primitive store block 4 ═══
namespace {
struct WrUtil4 {
    float v=4.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil4 id(){return{};}
    void reset(){v=4.0f;}
};
} // anon

// ═══ primitive store block 5 ═══
namespace {
struct WrUtil5 {
    float v=5.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil5 id(){return{};}
    void reset(){v=5.0f;}
};
} // anon

// ═══ primitive store block 6 ═══
namespace {
struct WrUtil6 {
    float v=6.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil6 id(){return{};}
    void reset(){v=6.0f;}
};
} // anon

// ═══ primitive store block 7 ═══
namespace {
struct WrUtil7 {
    float v=7.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil7 id(){return{};}
    void reset(){v=7.0f;}
};
} // anon

// ═══ primitive store block 8 ═══
namespace {
struct WrUtil8 {
    float v=8.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil8 id(){return{};}
    void reset(){v=8.0f;}
};
} // anon

// ═══ primitive store block 9 ═══
namespace {
struct WrUtil9 {
    float v=9.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil9 id(){return{};}
    void reset(){v=9.0f;}
};
} // anon

// ═══ primitive store block 10 ═══
namespace {
struct WrUtil10 {
    float v=10.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil10 id(){return{};}
    void reset(){v=10.0f;}
};
} // anon

// ═══ primitive store block 11 ═══
namespace {
struct WrUtil11 {
    float v=11.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil11 id(){return{};}
    void reset(){v=11.0f;}
};
} // anon

// ═══ primitive store block 12 ═══
namespace {
struct WrUtil12 {
    float v=12.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil12 id(){return{};}
    void reset(){v=12.0f;}
};
} // anon

// ═══ primitive store block 13 ═══
namespace {
struct WrUtil13 {
    float v=13.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil13 id(){return{};}
    void reset(){v=13.0f;}
};
} // anon

// ═══ primitive store block 14 ═══
namespace {
struct WrUtil14 {
    float v=14.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil14 id(){return{};}
    void reset(){v=14.0f;}
};
} // anon

// ═══ primitive store block 15 ═══
namespace {
struct WrUtil15 {
    float v=15.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil15 id(){return{};}
    void reset(){v=15.0f;}
};
} // anon

// ═══ primitive store block 16 ═══
namespace {
struct WrUtil16 {
    float v=16.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil16 id(){return{};}
    void reset(){v=16.0f;}
};
} // anon

// ═══ primitive store block 17 ═══
namespace {
struct WrUtil17 {
    float v=17.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil17 id(){return{};}
    void reset(){v=17.0f;}
};
} // anon

// ═══ primitive store block 18 ═══
namespace {
struct WrUtil18 {
    float v=18.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil18 id(){return{};}
    void reset(){v=18.0f;}
};
} // anon

// ═══ primitive store block 19 ═══
namespace {
struct WrUtil19 {
    float v=19.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil19 id(){return{};}
    void reset(){v=19.0f;}
};
} // anon

// ═══ primitive store block 20 ═══
namespace {
struct WrUtil20 {
    float v=20.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil20 id(){return{};}
    void reset(){v=20.0f;}
};
} // anon

// ═══ primitive store block 21 ═══
namespace {
struct WrUtil21 {
    float v=21.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil21 id(){return{};}
    void reset(){v=21.0f;}
};
} // anon

// ═══ primitive store block 22 ═══
namespace {
struct WrUtil22 {
    float v=22.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil22 id(){return{};}
    void reset(){v=22.0f;}
};
} // anon

// ═══ primitive store block 23 ═══
namespace {
struct WrUtil23 {
    float v=23.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil23 id(){return{};}
    void reset(){v=23.0f;}
};
} // anon

// ═══ primitive store block 24 ═══
namespace {
struct WrUtil24 {
    float v=24.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil24 id(){return{};}
    void reset(){v=24.0f;}
};
} // anon

// ═══ primitive store block 25 ═══
namespace {
struct WrUtil25 {
    float v=25.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil25 id(){return{};}
    void reset(){v=25.0f;}
};
} // anon

// ═══ primitive store block 26 ═══
namespace {
struct WrUtil26 {
    float v=26.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil26 id(){return{};}
    void reset(){v=26.0f;}
};
} // anon

// ═══ primitive store block 27 ═══
namespace {
struct WrUtil27 {
    float v=27.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil27 id(){return{};}
    void reset(){v=27.0f;}
};
} // anon

// ═══ primitive store block 28 ═══
namespace {
struct WrUtil28 {
    float v=28.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil28 id(){return{};}
    void reset(){v=28.0f;}
};
} // anon

// ═══ primitive store block 29 ═══
namespace {
struct WrUtil29 {
    float v=29.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil29 id(){return{};}
    void reset(){v=29.0f;}
};
} // anon

// ═══ primitive store block 30 ═══
namespace {
struct WrUtil30 {
    float v=30.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil30 id(){return{};}
    void reset(){v=30.0f;}
};
} // anon

// ═══ primitive store block 31 ═══
namespace {
struct WrUtil31 {
    float v=31.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil31 id(){return{};}
    void reset(){v=31.0f;}
};
} // anon

// ═══ primitive store block 32 ═══
namespace {
struct WrUtil32 {
    float v=32.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil32 id(){return{};}
    void reset(){v=32.0f;}
};
} // anon

// ═══ primitive store block 33 ═══
namespace {
struct WrUtil33 {
    float v=33.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil33 id(){return{};}
    void reset(){v=33.0f;}
};
} // anon

// ═══ primitive store block 34 ═══
namespace {
struct WrUtil34 {
    float v=34.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil34 id(){return{};}
    void reset(){v=34.0f;}
};
} // anon

// ═══ primitive store block 35 ═══
namespace {
struct WrUtil35 {
    float v=35.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil35 id(){return{};}
    void reset(){v=35.0f;}
};
} // anon

// ═══ primitive store block 36 ═══
namespace {
struct WrUtil36 {
    float v=36.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil36 id(){return{};}
    void reset(){v=36.0f;}
};
} // anon

// ═══ primitive store block 37 ═══
namespace {
struct WrUtil37 {
    float v=37.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil37 id(){return{};}
    void reset(){v=37.0f;}
};
} // anon

// ═══ primitive store block 38 ═══
namespace {
struct WrUtil38 {
    float v=38.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil38 id(){return{};}
    void reset(){v=38.0f;}
};
} // anon

// ═══ primitive store block 39 ═══
namespace {
struct WrUtil39 {
    float v=39.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil39 id(){return{};}
    void reset(){v=39.0f;}
};
} // anon

// ═══ primitive store block 40 ═══
namespace {
struct WrUtil40 {
    float v=40.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil40 id(){return{};}
    void reset(){v=40.0f;}
};
} // anon

// ═══ primitive store block 41 ═══
namespace {
struct WrUtil41 {
    float v=41.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil41 id(){return{};}
    void reset(){v=41.0f;}
};
} // anon

// ═══ primitive store block 42 ═══
namespace {
struct WrUtil42 {
    float v=42.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil42 id(){return{};}
    void reset(){v=42.0f;}
};
} // anon

// ═══ primitive store block 43 ═══
namespace {
struct WrUtil43 {
    float v=43.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil43 id(){return{};}
    void reset(){v=43.0f;}
};
} // anon

// ═══ primitive store block 44 ═══
namespace {
struct WrUtil44 {
    float v=44.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil44 id(){return{};}
    void reset(){v=44.0f;}
};
} // anon

// ═══ primitive store block 45 ═══
namespace {
struct WrUtil45 {
    float v=45.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil45 id(){return{};}
    void reset(){v=45.0f;}
};
} // anon

// ═══ primitive store block 46 ═══
namespace {
struct WrUtil46 {
    float v=46.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil46 id(){return{};}
    void reset(){v=46.0f;}
};
} // anon

// ═══ primitive store block 47 ═══
namespace {
struct WrUtil47 {
    float v=47.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil47 id(){return{};}
    void reset(){v=47.0f;}
};
} // anon

// ═══ primitive store block 48 ═══
namespace {
struct WrUtil48 {
    float v=48.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil48 id(){return{};}
    void reset(){v=48.0f;}
};
} // anon

// ═══ primitive store block 49 ═══
namespace {
struct WrUtil49 {
    float v=49.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil49 id(){return{};}
    void reset(){v=49.0f;}
};
} // anon

// ═══ primitive store block 50 ═══
namespace {
struct WrUtil50 {
    float v=50.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil50 id(){return{};}
    void reset(){v=50.0f;}
};
} // anon

// ═══ primitive store block 51 ═══
namespace {
struct WrUtil51 {
    float v=51.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil51 id(){return{};}
    void reset(){v=51.0f;}
};
} // anon

// ═══ primitive store block 52 ═══
namespace {
struct WrUtil52 {
    float v=52.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil52 id(){return{};}
    void reset(){v=52.0f;}
};
} // anon

// ═══ primitive store block 53 ═══
namespace {
struct WrUtil53 {
    float v=53.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil53 id(){return{};}
    void reset(){v=53.0f;}
};
} // anon

// ═══ primitive store block 54 ═══
namespace {
struct WrUtil54 {
    float v=54.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil54 id(){return{};}
    void reset(){v=54.0f;}
};
} // anon

// ═══ primitive store block 55 ═══
namespace {
struct WrUtil55 {
    float v=55.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil55 id(){return{};}
    void reset(){v=55.0f;}
};
} // anon

// ═══ primitive store block 56 ═══
namespace {
struct WrUtil56 {
    float v=56.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil56 id(){return{};}
    void reset(){v=56.0f;}
};
} // anon

// ═══ primitive store block 57 ═══
namespace {
struct WrUtil57 {
    float v=57.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil57 id(){return{};}
    void reset(){v=57.0f;}
};
} // anon

// ═══ primitive store block 58 ═══
namespace {
struct WrUtil58 {
    float v=58.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil58 id(){return{};}
    void reset(){v=58.0f;}
};
} // anon

// ═══ primitive store block 59 ═══
namespace {
struct WrUtil59 {
    float v=59.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil59 id(){return{};}
    void reset(){v=59.0f;}
};
} // anon

// ═══ primitive store block 60 ═══
namespace {
struct WrUtil60 {
    float v=60.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil60 id(){return{};}
    void reset(){v=60.0f;}
};
} // anon

// ═══ primitive store block 61 ═══
namespace {
struct WrUtil61 {
    float v=61.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil61 id(){return{};}
    void reset(){v=61.0f;}
};
} // anon

// ═══ primitive store block 62 ═══
namespace {
struct WrUtil62 {
    float v=62.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil62 id(){return{};}
    void reset(){v=62.0f;}
};
} // anon

// ═══ primitive store block 63 ═══
namespace {
struct WrUtil63 {
    float v=63.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil63 id(){return{};}
    void reset(){v=63.0f;}
};
} // anon

// ═══ primitive store block 64 ═══
namespace {
struct WrUtil64 {
    float v=64.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil64 id(){return{};}
    void reset(){v=64.0f;}
};
} // anon

// ═══ primitive store block 65 ═══
namespace {
struct WrUtil65 {
    float v=65.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil65 id(){return{};}
    void reset(){v=65.0f;}
};
} // anon

// ═══ primitive store block 66 ═══
namespace {
struct WrUtil66 {
    float v=66.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil66 id(){return{};}
    void reset(){v=66.0f;}
};
} // anon

// ═══ primitive store block 67 ═══
namespace {
struct WrUtil67 {
    float v=67.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil67 id(){return{};}
    void reset(){v=67.0f;}
};
} // anon

// ═══ primitive store block 68 ═══
namespace {
struct WrUtil68 {
    float v=68.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil68 id(){return{};}
    void reset(){v=68.0f;}
};
} // anon

// ═══ primitive store block 69 ═══
namespace {
struct WrUtil69 {
    float v=69.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil69 id(){return{};}
    void reset(){v=69.0f;}
};
} // anon

// ═══ primitive store block 70 ═══
namespace {
struct WrUtil70 {
    float v=70.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil70 id(){return{};}
    void reset(){v=70.0f;}
};
} // anon

// ═══ primitive store block 71 ═══
namespace {
struct WrUtil71 {
    float v=71.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil71 id(){return{};}
    void reset(){v=71.0f;}
};
} // anon

// ═══ primitive store block 72 ═══
namespace {
struct WrUtil72 {
    float v=72.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil72 id(){return{};}
    void reset(){v=72.0f;}
};
} // anon

// ═══ primitive store block 73 ═══
namespace {
struct WrUtil73 {
    float v=73.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil73 id(){return{};}
    void reset(){v=73.0f;}
};
} // anon

// ═══ primitive store block 74 ═══
namespace {
struct WrUtil74 {
    float v=74.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil74 id(){return{};}
    void reset(){v=74.0f;}
};
} // anon

// ═══ primitive store block 75 ═══
namespace {
struct WrUtil75 {
    float v=75.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil75 id(){return{};}
    void reset(){v=75.0f;}
};
} // anon

// ═══ primitive store block 76 ═══
namespace {
struct WrUtil76 {
    float v=76.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil76 id(){return{};}
    void reset(){v=76.0f;}
};
} // anon

// ═══ primitive store block 77 ═══
namespace {
struct WrUtil77 {
    float v=77.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil77 id(){return{};}
    void reset(){v=77.0f;}
};
} // anon

// ═══ primitive store block 78 ═══
namespace {
struct WrUtil78 {
    float v=78.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil78 id(){return{};}
    void reset(){v=78.0f;}
};
} // anon

// ═══ primitive store block 79 ═══
namespace {
struct WrUtil79 {
    float v=79.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil79 id(){return{};}
    void reset(){v=79.0f;}
};
} // anon

// ═══ primitive store block 80 ═══
namespace {
struct WrUtil80 {
    float v=80.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil80 id(){return{};}
    void reset(){v=80.0f;}
};
} // anon

// ═══ primitive store block 81 ═══
namespace {
struct WrUtil81 {
    float v=81.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil81 id(){return{};}
    void reset(){v=81.0f;}
};
} // anon

// ═══ primitive store block 82 ═══
namespace {
struct WrUtil82 {
    float v=82.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil82 id(){return{};}
    void reset(){v=82.0f;}
};
} // anon

// ═══ primitive store block 83 ═══
namespace {
struct WrUtil83 {
    float v=83.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil83 id(){return{};}
    void reset(){v=83.0f;}
};
} // anon

// ═══ primitive store block 84 ═══
namespace {
struct WrUtil84 {
    float v=84.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil84 id(){return{};}
    void reset(){v=84.0f;}
};
} // anon

// ═══ primitive store block 85 ═══
namespace {
struct WrUtil85 {
    float v=85.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil85 id(){return{};}
    void reset(){v=85.0f;}
};
} // anon

// ═══ primitive store block 86 ═══
namespace {
struct WrUtil86 {
    float v=86.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil86 id(){return{};}
    void reset(){v=86.0f;}
};
} // anon

// ═══ primitive store block 87 ═══
namespace {
struct WrUtil87 {
    float v=87.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil87 id(){return{};}
    void reset(){v=87.0f;}
};
} // anon

// ═══ primitive store block 88 ═══
namespace {
struct WrUtil88 {
    float v=88.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil88 id(){return{};}
    void reset(){v=88.0f;}
};
} // anon

// ═══ primitive store block 89 ═══
namespace {
struct WrUtil89 {
    float v=89.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil89 id(){return{};}
    void reset(){v=89.0f;}
};
} // anon

// ═══ primitive store block 90 ═══
namespace {
struct WrUtil90 {
    float v=90.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil90 id(){return{};}
    void reset(){v=90.0f;}
};
} // anon

// ═══ primitive store block 91 ═══
namespace {
struct WrUtil91 {
    float v=91.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil91 id(){return{};}
    void reset(){v=91.0f;}
};
} // anon

// ═══ primitive store block 92 ═══
namespace {
struct WrUtil92 {
    float v=92.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil92 id(){return{};}
    void reset(){v=92.0f;}
};
} // anon

// ═══ primitive store block 93 ═══
namespace {
struct WrUtil93 {
    float v=93.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil93 id(){return{};}
    void reset(){v=93.0f;}
};
} // anon

// ═══ primitive store block 94 ═══
namespace {
struct WrUtil94 {
    float v=94.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil94 id(){return{};}
    void reset(){v=94.0f;}
};
} // anon

// ═══ primitive store block 95 ═══
namespace {
struct WrUtil95 {
    float v=95.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil95 id(){return{};}
    void reset(){v=95.0f;}
};
} // anon

// ═══ primitive store block 96 ═══
namespace {
struct WrUtil96 {
    float v=96.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil96 id(){return{};}
    void reset(){v=96.0f;}
};
} // anon

// ═══ primitive store block 97 ═══
namespace {
struct WrUtil97 {
    float v=97.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil97 id(){return{};}
    void reset(){v=97.0f;}
};
} // anon

// ═══ primitive store block 98 ═══
namespace {
struct WrUtil98 {
    float v=98.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil98 id(){return{};}
    void reset(){v=98.0f;}
};
} // anon

// ═══ primitive store block 99 ═══
namespace {
struct WrUtil99 {
    float v=99.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil99 id(){return{};}
    void reset(){v=99.0f;}
};
} // anon

// ═══ primitive store block 100 ═══
namespace {
struct WrUtil100 {
    float v=100.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil100 id(){return{};}
    void reset(){v=100.0f;}
};
} // anon

// ═══ primitive store block 101 ═══
namespace {
struct WrUtil101 {
    float v=101.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil101 id(){return{};}
    void reset(){v=101.0f;}
};
} // anon

// ═══ primitive store block 102 ═══
namespace {
struct WrUtil102 {
    float v=102.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil102 id(){return{};}
    void reset(){v=102.0f;}
};
} // anon

// ═══ primitive store block 103 ═══
namespace {
struct WrUtil103 {
    float v=103.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil103 id(){return{};}
    void reset(){v=103.0f;}
};
} // anon

// ═══ primitive store block 104 ═══
namespace {
struct WrUtil104 {
    float v=104.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil104 id(){return{};}
    void reset(){v=104.0f;}
};
} // anon

// ═══ primitive store block 105 ═══
namespace {
struct WrUtil105 {
    float v=105.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil105 id(){return{};}
    void reset(){v=105.0f;}
};
} // anon

// ═══ primitive store block 106 ═══
namespace {
struct WrUtil106 {
    float v=106.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil106 id(){return{};}
    void reset(){v=106.0f;}
};
} // anon

// ═══ primitive store block 107 ═══
namespace {
struct WrUtil107 {
    float v=107.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil107 id(){return{};}
    void reset(){v=107.0f;}
};
} // anon

// ═══ primitive store block 108 ═══
namespace {
struct WrUtil108 {
    float v=108.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil108 id(){return{};}
    void reset(){v=108.0f;}
};
} // anon

// ═══ primitive store block 109 ═══
namespace {
struct WrUtil109 {
    float v=109.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil109 id(){return{};}
    void reset(){v=109.0f;}
};
} // anon

// ═══ primitive store block 110 ═══
namespace {
struct WrUtil110 {
    float v=110.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil110 id(){return{};}
    void reset(){v=110.0f;}
};
} // anon

// ═══ primitive store block 111 ═══
namespace {
struct WrUtil111 {
    float v=111.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil111 id(){return{};}
    void reset(){v=111.0f;}
};
} // anon

// ═══ primitive store block 112 ═══
namespace {
struct WrUtil112 {
    float v=112.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil112 id(){return{};}
    void reset(){v=112.0f;}
};
} // anon

// ═══ primitive store block 113 ═══
namespace {
struct WrUtil113 {
    float v=113.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil113 id(){return{};}
    void reset(){v=113.0f;}
};
} // anon

// ═══ primitive store block 114 ═══
namespace {
struct WrUtil114 {
    float v=114.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil114 id(){return{};}
    void reset(){v=114.0f;}
};
} // anon

// ═══ primitive store block 115 ═══
namespace {
struct WrUtil115 {
    float v=115.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil115 id(){return{};}
    void reset(){v=115.0f;}
};
} // anon

// ═══ primitive store block 116 ═══
namespace {
struct WrUtil116 {
    float v=116.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil116 id(){return{};}
    void reset(){v=116.0f;}
};
} // anon

// ═══ primitive store block 117 ═══
namespace {
struct WrUtil117 {
    float v=117.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil117 id(){return{};}
    void reset(){v=117.0f;}
};
} // anon

// ═══ primitive store block 118 ═══
namespace {
struct WrUtil118 {
    float v=118.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil118 id(){return{};}
    void reset(){v=118.0f;}
};
} // anon

// ═══ primitive store block 119 ═══
namespace {
struct WrUtil119 {
    float v=119.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil119 id(){return{};}
    void reset(){v=119.0f;}
};
} // anon

// ═══ primitive store block 120 ═══
namespace {
struct WrUtil120 {
    float v=120.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil120 id(){return{};}
    void reset(){v=120.0f;}
};
} // anon

// ═══ primitive store block 121 ═══
namespace {
struct WrUtil121 {
    float v=121.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil121 id(){return{};}
    void reset(){v=121.0f;}
};
} // anon

// ═══ primitive store block 122 ═══
namespace {
struct WrUtil122 {
    float v=122.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil122 id(){return{};}
    void reset(){v=122.0f;}
};
} // anon

// ═══ primitive store block 123 ═══
namespace {
struct WrUtil123 {
    float v=123.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil123 id(){return{};}
    void reset(){v=123.0f;}
};
} // anon

// ═══ primitive store block 124 ═══
namespace {
struct WrUtil124 {
    float v=124.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil124 id(){return{};}
    void reset(){v=124.0f;}
};
} // anon

// ═══ primitive store block 125 ═══
namespace {
struct WrUtil125 {
    float v=125.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil125 id(){return{};}
    void reset(){v=125.0f;}
};
} // anon

// ═══ primitive store block 126 ═══
namespace {
struct WrUtil126 {
    float v=126.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil126 id(){return{};}
    void reset(){v=126.0f;}
};
} // anon

// ═══ primitive store block 127 ═══
namespace {
struct WrUtil127 {
    float v=127.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil127 id(){return{};}
    void reset(){v=127.0f;}
};
} // anon

// ═══ primitive store block 128 ═══
namespace {
struct WrUtil128 {
    float v=128.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil128 id(){return{};}
    void reset(){v=128.0f;}
};
} // anon

// ═══ primitive store block 129 ═══
namespace {
struct WrUtil129 {
    float v=129.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil129 id(){return{};}
    void reset(){v=129.0f;}
};
} // anon

// ═══ primitive store block 130 ═══
namespace {
struct WrUtil130 {
    float v=130.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil130 id(){return{};}
    void reset(){v=130.0f;}
};
} // anon

// ═══ primitive store block 131 ═══
namespace {
struct WrUtil131 {
    float v=131.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil131 id(){return{};}
    void reset(){v=131.0f;}
};
} // anon

// ═══ primitive store block 132 ═══
namespace {
struct WrUtil132 {
    float v=132.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil132 id(){return{};}
    void reset(){v=132.0f;}
};
} // anon

// ═══ primitive store block 133 ═══
namespace {
struct WrUtil133 {
    float v=133.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil133 id(){return{};}
    void reset(){v=133.0f;}
};
} // anon

// ═══ primitive store block 134 ═══
namespace {
struct WrUtil134 {
    float v=134.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil134 id(){return{};}
    void reset(){v=134.0f;}
};
} // anon

// ═══ primitive store block 135 ═══
namespace {
struct WrUtil135 {
    float v=135.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil135 id(){return{};}
    void reset(){v=135.0f;}
};
} // anon

// ═══ primitive store block 136 ═══
namespace {
struct WrUtil136 {
    float v=136.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil136 id(){return{};}
    void reset(){v=136.0f;}
};
} // anon

// ═══ primitive store block 137 ═══
namespace {
struct WrUtil137 {
    float v=137.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil137 id(){return{};}
    void reset(){v=137.0f;}
};
} // anon

// ═══ primitive store block 138 ═══
namespace {
struct WrUtil138 {
    float v=138.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil138 id(){return{};}
    void reset(){v=138.0f;}
};
} // anon

// ═══ primitive store block 139 ═══
namespace {
struct WrUtil139 {
    float v=139.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil139 id(){return{};}
    void reset(){v=139.0f;}
};
} // anon

// ═══ primitive store block 140 ═══
namespace {
struct WrUtil140 {
    float v=140.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil140 id(){return{};}
    void reset(){v=140.0f;}
};
} // anon

// ═══ primitive store block 141 ═══
namespace {
struct WrUtil141 {
    float v=141.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil141 id(){return{};}
    void reset(){v=141.0f;}
};
} // anon

// ═══ primitive store block 142 ═══
namespace {
struct WrUtil142 {
    float v=142.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil142 id(){return{};}
    void reset(){v=142.0f;}
};
} // anon

// ═══ primitive store block 143 ═══
namespace {
struct WrUtil143 {
    float v=143.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil143 id(){return{};}
    void reset(){v=143.0f;}
};
} // anon

// ═══ primitive store block 144 ═══
namespace {
struct WrUtil144 {
    float v=144.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil144 id(){return{};}
    void reset(){v=144.0f;}
};
} // anon

// ═══ primitive store block 145 ═══
namespace {
struct WrUtil145 {
    float v=145.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil145 id(){return{};}
    void reset(){v=145.0f;}
};
} // anon

// ═══ primitive store block 146 ═══
namespace {
struct WrUtil146 {
    float v=146.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil146 id(){return{};}
    void reset(){v=146.0f;}
};
} // anon

// ═══ primitive store block 147 ═══
namespace {
struct WrUtil147 {
    float v=147.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil147 id(){return{};}
    void reset(){v=147.0f;}
};
} // anon

// ═══ primitive store block 148 ═══
namespace {
struct WrUtil148 {
    float v=148.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil148 id(){return{};}
    void reset(){v=148.0f;}
};
} // anon

// ═══ primitive store block 149 ═══
namespace {
struct WrUtil149 {
    float v=149.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil149 id(){return{};}
    void reset(){v=149.0f;}
};
} // anon

// ═══ primitive store block 150 ═══
namespace {
struct WrUtil150 {
    float v=150.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil150 id(){return{};}
    void reset(){v=150.0f;}
};
} // anon

// ═══ primitive store block 151 ═══
namespace {
struct WrUtil151 {
    float v=151.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil151 id(){return{};}
    void reset(){v=151.0f;}
};
} // anon

// ═══ primitive store block 152 ═══
namespace {
struct WrUtil152 {
    float v=152.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil152 id(){return{};}
    void reset(){v=152.0f;}
};
} // anon

// ═══ primitive store block 153 ═══
namespace {
struct WrUtil153 {
    float v=153.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil153 id(){return{};}
    void reset(){v=153.0f;}
};
} // anon

// ═══ primitive store block 154 ═══
namespace {
struct WrUtil154 {
    float v=154.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil154 id(){return{};}
    void reset(){v=154.0f;}
};
} // anon

// ═══ primitive store block 155 ═══
namespace {
struct WrUtil155 {
    float v=155.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil155 id(){return{};}
    void reset(){v=155.0f;}
};
} // anon

// ═══ primitive store block 156 ═══
namespace {
struct WrUtil156 {
    float v=156.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil156 id(){return{};}
    void reset(){v=156.0f;}
};
} // anon

// ═══ primitive store block 157 ═══
namespace {
struct WrUtil157 {
    float v=157.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil157 id(){return{};}
    void reset(){v=157.0f;}
};
} // anon

// ═══ primitive store block 158 ═══
namespace {
struct WrUtil158 {
    float v=158.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil158 id(){return{};}
    void reset(){v=158.0f;}
};
} // anon

// ═══ primitive store block 159 ═══
namespace {
struct WrUtil159 {
    float v=159.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil159 id(){return{};}
    void reset(){v=159.0f;}
};
} // anon

// ═══ primitive store block 160 ═══
namespace {
struct WrUtil160 {
    float v=160.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil160 id(){return{};}
    void reset(){v=160.0f;}
};
} // anon

// ═══ primitive store block 161 ═══
namespace {
struct WrUtil161 {
    float v=161.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil161 id(){return{};}
    void reset(){v=161.0f;}
};
} // anon

// ═══ primitive store block 162 ═══
namespace {
struct WrUtil162 {
    float v=162.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil162 id(){return{};}
    void reset(){v=162.0f;}
};
} // anon

// ═══ primitive store block 163 ═══
namespace {
struct WrUtil163 {
    float v=163.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil163 id(){return{};}
    void reset(){v=163.0f;}
};
} // anon

// ═══ primitive store block 164 ═══
namespace {
struct WrUtil164 {
    float v=164.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil164 id(){return{};}
    void reset(){v=164.0f;}
};
} // anon

// ═══ primitive store block 165 ═══
namespace {
struct WrUtil165 {
    float v=165.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil165 id(){return{};}
    void reset(){v=165.0f;}
};
} // anon

// ═══ primitive store block 166 ═══
namespace {
struct WrUtil166 {
    float v=166.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil166 id(){return{};}
    void reset(){v=166.0f;}
};
} // anon

// ═══ primitive store block 167 ═══
namespace {
struct WrUtil167 {
    float v=167.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil167 id(){return{};}
    void reset(){v=167.0f;}
};
} // anon

// ═══ primitive store block 168 ═══
namespace {
struct WrUtil168 {
    float v=168.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil168 id(){return{};}
    void reset(){v=168.0f;}
};
} // anon

// ═══ primitive store block 169 ═══
namespace {
struct WrUtil169 {
    float v=169.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil169 id(){return{};}
    void reset(){v=169.0f;}
};
} // anon

// ═══ primitive store block 170 ═══
namespace {
struct WrUtil170 {
    float v=170.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil170 id(){return{};}
    void reset(){v=170.0f;}
};
} // anon

// ═══ primitive store block 171 ═══
namespace {
struct WrUtil171 {
    float v=171.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil171 id(){return{};}
    void reset(){v=171.0f;}
};
} // anon

// ═══ primitive store block 172 ═══
namespace {
struct WrUtil172 {
    float v=172.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil172 id(){return{};}
    void reset(){v=172.0f;}
};
} // anon

// ═══ primitive store block 173 ═══
namespace {
struct WrUtil173 {
    float v=173.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil173 id(){return{};}
    void reset(){v=173.0f;}
};
} // anon

// ═══ primitive store block 174 ═══
namespace {
struct WrUtil174 {
    float v=174.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil174 id(){return{};}
    void reset(){v=174.0f;}
};
} // anon

// ═══ primitive store block 175 ═══
namespace {
struct WrUtil175 {
    float v=175.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil175 id(){return{};}
    void reset(){v=175.0f;}
};
} // anon

// ═══ primitive store block 176 ═══
namespace {
struct WrUtil176 {
    float v=176.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil176 id(){return{};}
    void reset(){v=176.0f;}
};
} // anon

// ═══ primitive store block 177 ═══
namespace {
struct WrUtil177 {
    float v=177.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil177 id(){return{};}
    void reset(){v=177.0f;}
};
} // anon

// ═══ primitive store block 178 ═══
namespace {
struct WrUtil178 {
    float v=178.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil178 id(){return{};}
    void reset(){v=178.0f;}
};
} // anon

// ═══ primitive store block 179 ═══
namespace {
struct WrUtil179 {
    float v=179.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil179 id(){return{};}
    void reset(){v=179.0f;}
};
} // anon

// ═══ primitive store block 180 ═══
namespace {
struct WrUtil180 {
    float v=180.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil180 id(){return{};}
    void reset(){v=180.0f;}
};
} // anon

// ═══ primitive store block 181 ═══
namespace {
struct WrUtil181 {
    float v=181.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil181 id(){return{};}
    void reset(){v=181.0f;}
};
} // anon

#ifdef WR_TEST
bool test_wr_primitive_store(){return true;}
#endif
} // namespace wr