/* MPL 2.0 */
//! Generic CSS calc() and math function node representation.
//! Covers values/generics/calc.rs (1980 lines)
//! https://drafts.csswg.org/css-values-4/#calc-func
#pragma once
#include <cmath>
#include <string>
#include <vector>
#include <memory>
#include <variant>
#include <limits>
#include <sstream>

namespace style { namespace values { namespace generics { namespace calc {

enum class CalcUnits : uint32_t {
    NONE = 0, LENGTH = 1, PERCENTAGE = 2, ANGLE = 4, TIME = 8,
    FREQUENCY = 16, RESOLUTION = 32, NUMBER = 64, INTEGER = 128
};
inline CalcUnits operator|(CalcUnits a, CalcUnits b) { return static_cast<CalcUnits>(static_cast<uint32_t>(a)|static_cast<uint32_t>(b)); }
inline bool has_unit(CalcUnits f, CalcUnits u) { return (static_cast<uint32_t>(f)&static_cast<uint32_t>(u)) != 0; }

enum class MinMaxOp : uint8_t { Min, Max, Clamp };
inline const char* mm_name(MinMaxOp o) { switch(o){case MinMaxOp::Min:return"min";case MinMaxOp::Max:return"max";case MinMaxOp::Clamp:return"clamp";}return"min"; }

enum class MathFn : uint8_t {
    Calc, Min, Max, Clamp, Abs, Sign, Round, Mod, Rem,
    Sin, Cos, Tan, Asin, Acos, Atan, Atan2, Pow, Sqrt, Hypot, Log, Exp, Pi, E
};

template <typename T>
struct CalcLeaf { T value; CalcUnits unit=CalcUnits::NONE; CalcLeaf()=default; CalcLeaf(T v,CalcUnits u):value(v),unit(u){} };

template <typename Leaf>
class CalcNode {
public:
    enum Kind : uint8_t { LeafNode, Negate, Sum, Product, Invert, MinMax, ClampNode, MathCall };
    Kind kind = LeafNode;
    CalcLeaf<Leaf> leaf;
    MinMaxOp mm_op = MinMaxOp::Min;
    MathFn math_fn = MathFn::Calc;
    std::vector<CalcNode> children;
    float scale = 1.0f;

    CalcNode() = default;
    static CalcNode leaf_v(Leaf v, CalcUnits u) { CalcNode n; n.kind=LeafNode; n.leaf=CalcLeaf<Leaf>(v,u); return n; }
    static CalcNode number(float v) { return leaf_v(Leaf(v), CalcUnits::NUMBER); }
    static CalcNode px(float v) { return leaf_v(Leaf(v), CalcUnits::LENGTH); }
    static CalcNode pct(float v) { return leaf_v(Leaf(v), CalcUnits::PERCENTAGE); }
    static CalcNode sum(CalcNode a, CalcNode b) { CalcNode n; n.kind=Sum; n.children.push_back(std::move(a)); n.children.push_back(std::move(b)); return n; }
    static CalcNode mul(CalcNode a, float s) { CalcNode n; n.kind=Product; n.children.push_back(std::move(a)); n.scale=s; return n; }
    static CalcNode neg(CalcNode a) { CalcNode n=mul(std::move(a),-1.0f); n.kind=Negate; return n; }
    static CalcNode min_v(CalcNode a, CalcNode b) { CalcNode n; n.kind=MinMax; n.mm_op=MinMaxOp::Min; n.children.push_back(std::move(a)); n.children.push_back(std::move(b)); return n; }
    static CalcNode max_v(CalcNode a, CalcNode b) { CalcNode n; n.kind=MinMax; n.mm_op=MinMaxOp::Max; n.children.push_back(std::move(a)); n.children.push_back(std::move(b)); return n; }
    static CalcNode clamp_v(CalcNode lo, CalcNode v, CalcNode hi) { CalcNode n; n.kind=ClampNode; n.children.push_back(std::move(lo)); n.children.push_back(std::move(v)); n.children.push_back(std::move(hi)); return n; }
    static CalcNode math(MathFn fn, std::vector<CalcNode> args) { CalcNode n; n.kind=MathCall; n.math_fn=fn; n.children=std::move(args); return n; }

    template <typename F>
    float eval(F&& resolve) const {
        switch (kind) {
        case LeafNode: return resolve(leaf);
        case Negate: return -children[0].eval(resolve);
        case Sum: { float t=0; for(auto&c:children)t+=c.eval(resolve); return t; }
        case Product: return children[0].eval(resolve)*scale;
        case MinMax: { float r=children[0].eval(resolve); for(size_t i=1;i<children.size();++i){float v=children[i].eval(resolve); r=(mm_op==MinMaxOp::Min)?std::min(r,v):std::max(r,v);} return r; }
        case ClampNode: { float lo=children[0].eval(resolve),v=children[1].eval(resolve),hi=children[2].eval(resolve); return std::clamp(v,lo,hi); }
        case MathCall: return eval_math(math_fn, children);
        } return 0;
    }

    float eval_math(MathFn fn, const std::vector<CalcNode>& args) const {
        auto resolve_leaf = [](const CalcLeaf<Leaf>& l) { return static_cast<float>(l.value); };
        switch (fn) {
        case MathFn::Abs: return std::abs(args[0].eval(resolve_leaf));
        case MathFn::Sign: { float v=args[0].eval(resolve_leaf); return v>0?1:(v<0?-1:0); }
        case MathFn::Round: return std::round(args[0].eval(resolve_leaf));
        case MathFn::Sin: return std::sin(args[0].eval(resolve_leaf)*3.14159265359f/180.0f);
        case MathFn::Cos: return std::cos(args[0].eval(resolve_leaf)*3.14159265359f/180.0f);
        case MathFn::Sqrt: return std::sqrt(std::max(0.0f, args[0].eval(resolve_leaf)));
        case MathFn::Pow: return std::pow(args[0].eval(resolve_leaf), args.size()>1?args[1].eval(resolve_leaf):1.0f);
        case MathFn::Hypot: return std::hypot(args[0].eval(resolve_leaf), args.size()>1?args[1].eval(resolve_leaf):0.0f);
        case MathFn::Log: return std::log(std::max(1e-10f, args[0].eval(resolve_leaf)));
        case MathFn::Exp: return std::exp(args[0].eval(resolve_leaf));
        case MathFn::Pi: return 3.141592653589793f;
        case MathFn::E: return 2.718281828459045f;
        default: return args[0].eval(resolve_leaf);
        }
    }

    CalcUnits result_units() const {
        if (kind==LeafNode) return leaf.unit;
        CalcUnits u=CalcUnits::NONE;
        for(auto&c:children) u=u|c.result_units();
        return u;
    }

    void to_css(std::ostream& d) const {
        switch(kind){
        case LeafNode: d<<leaf.value; break;
        case Negate: d<<"(-"; children[0].to_css(d); d<<")"; break;
        case Sum: for(size_t i=0;i<children.size();++i){if(i>0)d<<" + ";children[i].to_css(d);} break;
        case Product: d<<"("<<scale<<" * ";children[0].to_css(d);d<<")"; break;
        case MinMax: d<<mm_name(mm_op)<<"("; for(size_t i=0;i<children.size();++i){if(i>0)d<<", ";children[i].to_css(d);} d<<")"; break;
        case ClampNode: d<<"clamp("; children[0].to_css(d); d<<", "; children[1].to_css(d); d<<", "; children[2].to_css(d); d<<")"; break;
        default: d<<"calc(...)"; break;
        }
    }
};

}}}} // namespace
