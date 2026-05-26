/* MPL 2.0 */
//! Specified CSS length values.
#pragma once
#include <cmath>
#include <string>
#include <cstdint>

namespace style { namespace values { namespace specified {

enum class FontRelativeUnit : uint8_t { Em, Rem, Ex, Ch, Cap, Ic };
enum class ViewportUnit : uint8_t { Vw, Vh, Vmin, Vmax, Vb, Vi, Svw, Svh, Dvw, Dvh };
enum class AbsoluteUnit : uint8_t { Px, Cm, Mm, In, Pt, Pc };

struct FontRelativeLength { float value=0; FontRelativeUnit unit=FontRelativeUnit::Em; };
struct ViewportPercentageLength { float value=0; ViewportUnit unit=ViewportUnit::Vw; };

inline float to_pixels(float v, AbsoluteUnit u) {
    switch(u){case AbsoluteUnit::Px:return v;case AbsoluteUnit::Cm:return v*96.0f/2.54f;case AbsoluteUnit::Mm:return v*96.0f/25.4f;case AbsoluteUnit::In:return v*96.0f;case AbsoluteUnit::Pt:return v*96.0f/72.0f;case AbsoluteUnit::Pc:return v*96.0f/6.0f;}return v;
}

struct Length {
    enum Tag : uint8_t { Absolute, FontRelative, ViewportPercentage, Auto_, None_, Normal_ };
    Tag tag=Tag::Auto_;
    float abs_value=0; AbsoluteUnit abs_unit=AbsoluteUnit::Px;
    FontRelativeLength font_rel;
    ViewportPercentageLength viewport_pct;
    Length()=default;
    static Length px(float v){Length l;l.tag=Tag::Absolute;l.abs_value=v;return l;}
    static Length em(float v){Length l;l.tag=Tag::FontRelative;l.font_rel={v,FontRelativeUnit::Em};return l;}
    static Length rem(float v){Length l;l.tag=Tag::FontRelative;l.font_rel={v,FontRelativeUnit::Rem};return l;}
    static Length vw(float v){Length l;l.tag=Tag::ViewportPercentage;l.viewport_pct={v,ViewportUnit::Vw};return l;}
    static Length vh(float v){Length l;l.tag=Tag::ViewportPercentage;l.viewport_pct={v,ViewportUnit::Vh};return l;}
    static Length zero(){return px(0);}
    static Length auto_val(){Length l;l.tag=Tag::Auto_;return l;}
    static Length none_(){Length l;l.tag=Tag::None_;return l;}
    bool is_auto()const{return tag==Tag::Auto_;}
    bool is_none()const{return tag==Tag::None_;}
    bool is_zero()const{return tag==Tag::Absolute&&abs_value==0;}
    float to_px(float font_size,float root_font_size,float vw_vp,float vh_vp)const{
        switch(tag){
        case Tag::Absolute:return to_pixels(abs_value,abs_unit);
        case Tag::FontRelative:{
            float base=(font_rel.unit==FontRelativeUnit::Rem)?root_font_size:font_size;
            return font_rel.value*base;
        }
        case Tag::ViewportPercentage:{
            float vp=(viewport_pct.unit==ViewportUnit::Vh||viewport_pct.unit==ViewportUnit::Svh)?vh_vp:vw_vp;
            return viewport_pct.value/100.0f*vp;
        }
        default:return 0;
        }
    }
};

struct LengthPercentage {
    bool is_percentage=false;
    Length length;
    float percentage=0;
    LengthPercentage()=default;
    static LengthPercentage px(float v){LengthPercentage l;l.length=Length::px(v);return l;}
    static LengthPercentage percent(float v){LengthPercentage l;l.is_percentage=true;l.percentage=v/100.0f;return l;}
    static LengthPercentage zero(){return px(0);}
    static LengthPercentage auto_val(){LengthPercentage l;l.length=Length::auto_val();return l;}
    bool is_auto()const{return length.is_auto();}
    float to_px(float ref,float fs,float rfs,float vw_,float vh_)const{
        if(is_percentage)return percentage*ref;
        return length.to_px(fs,rfs,vw_,vh_);
    }
};

struct NonNegativeLength : Length { NonNegativeLength():Length(){} static NonNegativeLength px(float v){NonNegativeLength l;l.tag=Tag::Absolute;l.abs_value=std::max(0.0f,v);return l;} };
struct NonNegativeLengthPercentage : LengthPercentage { NonNegativeLengthPercentage():LengthPercentage(){} };
struct Ratio { float num=1,den=1; Ratio()=default; Ratio(float n,float d):num(n),den(d){} };

}}} // namespace
