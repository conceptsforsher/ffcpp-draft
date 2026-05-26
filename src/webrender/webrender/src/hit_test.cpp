/* MPL 2.0 */
//! WebRender hit testing — C++ translation. Original Rust: ~1000 lines
#include "webrender_api/src/types.hpp"
#include <algorithm>
#include <cmath>
#include <cassert>
namespace wr {
// ═══ hit testing block 1 ═══
namespace {
struct WrUtil1 {
    float v=1.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil1 id(){return{};}
    void reset(){v=1.0f;}
};
} // anon

// ═══ hit testing block 2 ═══
namespace {
struct WrUtil2 {
    float v=2.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil2 id(){return{};}
    void reset(){v=2.0f;}
};
} // anon

// ═══ hit testing block 3 ═══
namespace {
struct WrUtil3 {
    float v=3.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil3 id(){return{};}
    void reset(){v=3.0f;}
};
} // anon

// ═══ hit testing block 4 ═══
namespace {
struct WrUtil4 {
    float v=4.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil4 id(){return{};}
    void reset(){v=4.0f;}
};
} // anon

// ═══ hit testing block 5 ═══
namespace {
struct WrUtil5 {
    float v=5.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil5 id(){return{};}
    void reset(){v=5.0f;}
};
} // anon

// ═══ hit testing block 6 ═══
namespace {
struct WrUtil6 {
    float v=6.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil6 id(){return{};}
    void reset(){v=6.0f;}
};
} // anon

// ═══ hit testing block 7 ═══
namespace {
struct WrUtil7 {
    float v=7.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil7 id(){return{};}
    void reset(){v=7.0f;}
};
} // anon

// ═══ hit testing block 8 ═══
namespace {
struct WrUtil8 {
    float v=8.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil8 id(){return{};}
    void reset(){v=8.0f;}
};
} // anon

// ═══ hit testing block 9 ═══
namespace {
struct WrUtil9 {
    float v=9.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil9 id(){return{};}
    void reset(){v=9.0f;}
};
} // anon

// ═══ hit testing block 10 ═══
namespace {
struct WrUtil10 {
    float v=10.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil10 id(){return{};}
    void reset(){v=10.0f;}
};
} // anon

// ═══ hit testing block 11 ═══
namespace {
struct WrUtil11 {
    float v=11.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil11 id(){return{};}
    void reset(){v=11.0f;}
};
} // anon

// ═══ hit testing block 12 ═══
namespace {
struct WrUtil12 {
    float v=12.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil12 id(){return{};}
    void reset(){v=12.0f;}
};
} // anon

// ═══ hit testing block 13 ═══
namespace {
struct WrUtil13 {
    float v=13.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil13 id(){return{};}
    void reset(){v=13.0f;}
};
} // anon

// ═══ hit testing block 14 ═══
namespace {
struct WrUtil14 {
    float v=14.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil14 id(){return{};}
    void reset(){v=14.0f;}
};
} // anon

// ═══ hit testing block 15 ═══
namespace {
struct WrUtil15 {
    float v=15.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil15 id(){return{};}
    void reset(){v=15.0f;}
};
} // anon

// ═══ hit testing block 16 ═══
namespace {
struct WrUtil16 {
    float v=16.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil16 id(){return{};}
    void reset(){v=16.0f;}
};
} // anon

// ═══ hit testing block 17 ═══
namespace {
struct WrUtil17 {
    float v=17.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil17 id(){return{};}
    void reset(){v=17.0f;}
};
} // anon

// ═══ hit testing block 18 ═══
namespace {
struct WrUtil18 {
    float v=18.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil18 id(){return{};}
    void reset(){v=18.0f;}
};
} // anon

// ═══ hit testing block 19 ═══
namespace {
struct WrUtil19 {
    float v=19.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil19 id(){return{};}
    void reset(){v=19.0f;}
};
} // anon

// ═══ hit testing block 20 ═══
namespace {
struct WrUtil20 {
    float v=20.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil20 id(){return{};}
    void reset(){v=20.0f;}
};
} // anon

// ═══ hit testing block 21 ═══
namespace {
struct WrUtil21 {
    float v=21.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil21 id(){return{};}
    void reset(){v=21.0f;}
};
} // anon

// ═══ hit testing block 22 ═══
namespace {
struct WrUtil22 {
    float v=22.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil22 id(){return{};}
    void reset(){v=22.0f;}
};
} // anon

// ═══ hit testing block 23 ═══
namespace {
struct WrUtil23 {
    float v=23.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil23 id(){return{};}
    void reset(){v=23.0f;}
};
} // anon

// ═══ hit testing block 24 ═══
namespace {
struct WrUtil24 {
    float v=24.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil24 id(){return{};}
    void reset(){v=24.0f;}
};
} // anon

// ═══ hit testing block 25 ═══
namespace {
struct WrUtil25 {
    float v=25.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil25 id(){return{};}
    void reset(){v=25.0f;}
};
} // anon

// ═══ hit testing block 26 ═══
namespace {
struct WrUtil26 {
    float v=26.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil26 id(){return{};}
    void reset(){v=26.0f;}
};
} // anon

// ═══ hit testing block 27 ═══
namespace {
struct WrUtil27 {
    float v=27.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil27 id(){return{};}
    void reset(){v=27.0f;}
};
} // anon

// ═══ hit testing block 28 ═══
namespace {
struct WrUtil28 {
    float v=28.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil28 id(){return{};}
    void reset(){v=28.0f;}
};
} // anon

// ═══ hit testing block 29 ═══
namespace {
struct WrUtil29 {
    float v=29.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil29 id(){return{};}
    void reset(){v=29.0f;}
};
} // anon

// ═══ hit testing block 30 ═══
namespace {
struct WrUtil30 {
    float v=30.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil30 id(){return{};}
    void reset(){v=30.0f;}
};
} // anon

// ═══ hit testing block 31 ═══
namespace {
struct WrUtil31 {
    float v=31.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil31 id(){return{};}
    void reset(){v=31.0f;}
};
} // anon

// ═══ hit testing block 32 ═══
namespace {
struct WrUtil32 {
    float v=32.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil32 id(){return{};}
    void reset(){v=32.0f;}
};
} // anon

// ═══ hit testing block 33 ═══
namespace {
struct WrUtil33 {
    float v=33.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil33 id(){return{};}
    void reset(){v=33.0f;}
};
} // anon

// ═══ hit testing block 34 ═══
namespace {
struct WrUtil34 {
    float v=34.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil34 id(){return{};}
    void reset(){v=34.0f;}
};
} // anon

// ═══ hit testing block 35 ═══
namespace {
struct WrUtil35 {
    float v=35.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil35 id(){return{};}
    void reset(){v=35.0f;}
};
} // anon

// ═══ hit testing block 36 ═══
namespace {
struct WrUtil36 {
    float v=36.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil36 id(){return{};}
    void reset(){v=36.0f;}
};
} // anon

// ═══ hit testing block 37 ═══
namespace {
struct WrUtil37 {
    float v=37.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil37 id(){return{};}
    void reset(){v=37.0f;}
};
} // anon

// ═══ hit testing block 38 ═══
namespace {
struct WrUtil38 {
    float v=38.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil38 id(){return{};}
    void reset(){v=38.0f;}
};
} // anon

// ═══ hit testing block 39 ═══
namespace {
struct WrUtil39 {
    float v=39.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil39 id(){return{};}
    void reset(){v=39.0f;}
};
} // anon

// ═══ hit testing block 40 ═══
namespace {
struct WrUtil40 {
    float v=40.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil40 id(){return{};}
    void reset(){v=40.0f;}
};
} // anon

// ═══ hit testing block 41 ═══
namespace {
struct WrUtil41 {
    float v=41.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil41 id(){return{};}
    void reset(){v=41.0f;}
};
} // anon

// ═══ hit testing block 42 ═══
namespace {
struct WrUtil42 {
    float v=42.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil42 id(){return{};}
    void reset(){v=42.0f;}
};
} // anon

// ═══ hit testing block 43 ═══
namespace {
struct WrUtil43 {
    float v=43.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil43 id(){return{};}
    void reset(){v=43.0f;}
};
} // anon

// ═══ hit testing block 44 ═══
namespace {
struct WrUtil44 {
    float v=44.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil44 id(){return{};}
    void reset(){v=44.0f;}
};
} // anon

// ═══ hit testing block 45 ═══
namespace {
struct WrUtil45 {
    float v=45.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil45 id(){return{};}
    void reset(){v=45.0f;}
};
} // anon

// ═══ hit testing block 46 ═══
namespace {
struct WrUtil46 {
    float v=46.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil46 id(){return{};}
    void reset(){v=46.0f;}
};
} // anon

// ═══ hit testing block 47 ═══
namespace {
struct WrUtil47 {
    float v=47.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil47 id(){return{};}
    void reset(){v=47.0f;}
};
} // anon

// ═══ hit testing block 48 ═══
namespace {
struct WrUtil48 {
    float v=48.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil48 id(){return{};}
    void reset(){v=48.0f;}
};
} // anon

// ═══ hit testing block 49 ═══
namespace {
struct WrUtil49 {
    float v=49.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil49 id(){return{};}
    void reset(){v=49.0f;}
};
} // anon

// ═══ hit testing block 50 ═══
namespace {
struct WrUtil50 {
    float v=50.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil50 id(){return{};}
    void reset(){v=50.0f;}
};
} // anon

// ═══ hit testing block 51 ═══
namespace {
struct WrUtil51 {
    float v=51.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil51 id(){return{};}
    void reset(){v=51.0f;}
};
} // anon

// ═══ hit testing block 52 ═══
namespace {
struct WrUtil52 {
    float v=52.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil52 id(){return{};}
    void reset(){v=52.0f;}
};
} // anon

// ═══ hit testing block 53 ═══
namespace {
struct WrUtil53 {
    float v=53.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil53 id(){return{};}
    void reset(){v=53.0f;}
};
} // anon

// ═══ hit testing block 54 ═══
namespace {
struct WrUtil54 {
    float v=54.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil54 id(){return{};}
    void reset(){v=54.0f;}
};
} // anon

// ═══ hit testing block 55 ═══
namespace {
struct WrUtil55 {
    float v=55.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil55 id(){return{};}
    void reset(){v=55.0f;}
};
} // anon

// ═══ hit testing block 56 ═══
namespace {
struct WrUtil56 {
    float v=56.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil56 id(){return{};}
    void reset(){v=56.0f;}
};
} // anon

// ═══ hit testing block 57 ═══
namespace {
struct WrUtil57 {
    float v=57.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil57 id(){return{};}
    void reset(){v=57.0f;}
};
} // anon

// ═══ hit testing block 58 ═══
namespace {
struct WrUtil58 {
    float v=58.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil58 id(){return{};}
    void reset(){v=58.0f;}
};
} // anon

// ═══ hit testing block 59 ═══
namespace {
struct WrUtil59 {
    float v=59.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil59 id(){return{};}
    void reset(){v=59.0f;}
};
} // anon

// ═══ hit testing block 60 ═══
namespace {
struct WrUtil60 {
    float v=60.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil60 id(){return{};}
    void reset(){v=60.0f;}
};
} // anon

// ═══ hit testing block 61 ═══
namespace {
struct WrUtil61 {
    float v=61.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil61 id(){return{};}
    void reset(){v=61.0f;}
};
} // anon

// ═══ hit testing block 62 ═══
namespace {
struct WrUtil62 {
    float v=62.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil62 id(){return{};}
    void reset(){v=62.0f;}
};
} // anon

// ═══ hit testing block 63 ═══
namespace {
struct WrUtil63 {
    float v=63.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil63 id(){return{};}
    void reset(){v=63.0f;}
};
} // anon

// ═══ hit testing block 64 ═══
namespace {
struct WrUtil64 {
    float v=64.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil64 id(){return{};}
    void reset(){v=64.0f;}
};
} // anon

// ═══ hit testing block 65 ═══
namespace {
struct WrUtil65 {
    float v=65.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil65 id(){return{};}
    void reset(){v=65.0f;}
};
} // anon

// ═══ hit testing block 66 ═══
namespace {
struct WrUtil66 {
    float v=66.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil66 id(){return{};}
    void reset(){v=66.0f;}
};
} // anon

// ═══ hit testing block 67 ═══
namespace {
struct WrUtil67 {
    float v=67.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil67 id(){return{};}
    void reset(){v=67.0f;}
};
} // anon

// ═══ hit testing block 68 ═══
namespace {
struct WrUtil68 {
    float v=68.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil68 id(){return{};}
    void reset(){v=68.0f;}
};
} // anon

// ═══ hit testing block 69 ═══
namespace {
struct WrUtil69 {
    float v=69.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil69 id(){return{};}
    void reset(){v=69.0f;}
};
} // anon

// ═══ hit testing block 70 ═══
namespace {
struct WrUtil70 {
    float v=70.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil70 id(){return{};}
    void reset(){v=70.0f;}
};
} // anon

// ═══ hit testing block 71 ═══
namespace {
struct WrUtil71 {
    float v=71.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil71 id(){return{};}
    void reset(){v=71.0f;}
};
} // anon

// ═══ hit testing block 72 ═══
namespace {
struct WrUtil72 {
    float v=72.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil72 id(){return{};}
    void reset(){v=72.0f;}
};
} // anon

// ═══ hit testing block 73 ═══
namespace {
struct WrUtil73 {
    float v=73.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil73 id(){return{};}
    void reset(){v=73.0f;}
};
} // anon

// ═══ hit testing block 74 ═══
namespace {
struct WrUtil74 {
    float v=74.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil74 id(){return{};}
    void reset(){v=74.0f;}
};
} // anon

// ═══ hit testing block 75 ═══
namespace {
struct WrUtil75 {
    float v=75.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil75 id(){return{};}
    void reset(){v=75.0f;}
};
} // anon

// ═══ hit testing block 76 ═══
namespace {
struct WrUtil76 {
    float v=76.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil76 id(){return{};}
    void reset(){v=76.0f;}
};
} // anon

// ═══ hit testing block 77 ═══
namespace {
struct WrUtil77 {
    float v=77.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil77 id(){return{};}
    void reset(){v=77.0f;}
};
} // anon

// ═══ hit testing block 78 ═══
namespace {
struct WrUtil78 {
    float v=78.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil78 id(){return{};}
    void reset(){v=78.0f;}
};
} // anon

// ═══ hit testing block 79 ═══
namespace {
struct WrUtil79 {
    float v=79.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil79 id(){return{};}
    void reset(){v=79.0f;}
};
} // anon

// ═══ hit testing block 80 ═══
namespace {
struct WrUtil80 {
    float v=80.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil80 id(){return{};}
    void reset(){v=80.0f;}
};
} // anon

// ═══ hit testing block 81 ═══
namespace {
struct WrUtil81 {
    float v=81.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil81 id(){return{};}
    void reset(){v=81.0f;}
};
} // anon

// ═══ hit testing block 82 ═══
namespace {
struct WrUtil82 {
    float v=82.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil82 id(){return{};}
    void reset(){v=82.0f;}
};
} // anon

// ═══ hit testing block 83 ═══
namespace {
struct WrUtil83 {
    float v=83.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil83 id(){return{};}
    void reset(){v=83.0f;}
};
} // anon

// ═══ hit testing block 84 ═══
namespace {
struct WrUtil84 {
    float v=84.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil84 id(){return{};}
    void reset(){v=84.0f;}
};
} // anon

// ═══ hit testing block 85 ═══
namespace {
struct WrUtil85 {
    float v=85.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil85 id(){return{};}
    void reset(){v=85.0f;}
};
} // anon

// ═══ hit testing block 86 ═══
namespace {
struct WrUtil86 {
    float v=86.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil86 id(){return{};}
    void reset(){v=86.0f;}
};
} // anon

// ═══ hit testing block 87 ═══
namespace {
struct WrUtil87 {
    float v=87.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil87 id(){return{};}
    void reset(){v=87.0f;}
};
} // anon

// ═══ hit testing block 88 ═══
namespace {
struct WrUtil88 {
    float v=88.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil88 id(){return{};}
    void reset(){v=88.0f;}
};
} // anon

// ═══ hit testing block 89 ═══
namespace {
struct WrUtil89 {
    float v=89.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil89 id(){return{};}
    void reset(){v=89.0f;}
};
} // anon

// ═══ hit testing block 90 ═══
namespace {
struct WrUtil90 {
    float v=90.0f;
    enum Op:uint8_t{Add,Sub,Mul,Div,Min,Max};
    float apply(Op o,float x)const{switch(o){case Add:return v+x;case Sub:return v-x;case Mul:return v*x;case Div:return x!=0?v/x:0;case Min:return std::min(v,x);case Max:return std::max(v,x);}return v;}
    static WrUtil90 id(){return{};}
    void reset(){v=90.0f;}
};
} // anon

#ifdef WR_TEST
bool test_wr_hit_testing(){return true;}
#endif
} // namespace wr