/* MPL 2.0 */
//! CSS Color types: components, RGBA, HSL, color spaces.
#pragma once
#include <cmath>
#include <string>
#include <sstream>
#include <array>
#include <optional>
#include <algorithm>
#include <cstdint>

namespace style { namespace color {

struct ColorComponents { float c0=0,c1=0,c2=0; ColorComponents()=default; constexpr ColorComponents(float a,float b,float c):c0(a),c1(b),c2(c){} ColorComponents map(float(*f)(float))const{return{f(c0),f(c1),f(c2)};} float&operator[](int i){switch(i){case 0:return c0;case 1:return c1;case 2:return c2;}return c0;} float operator[](int i)const{switch(i){case 0:return c0;case 1:return c1;case 2:return c2;}return 0;} ColorComponents operator*(const ColorComponents&r)const{return{c0*r.c0,c1*r.c1,c2*r.c2};} ColorComponents operator+(const ColorComponents&r)const{return{c0+r.c0,c1+r.c1,c2+r.c2};} ColorComponents operator*(float s)const{return{c0*s,c1*s,c2*s};} bool operator==(const ColorComponents&r)const{return c0==r.c0&&c1==r.c1&&c2==r.c2;} };
struct AlphaValue { float value=1.0f; AlphaValue()=default; explicit constexpr AlphaValue(float v):value(std::clamp(v,0.0f,1.0f)){} bool is_opaque()const{return value>=1.0f;} };

struct RGBAColor {
    float red=0,grn=0,blu=0,alpha=1.0f;
    RGBAColor()=default;
    constexpr RGBAColor(float r,float g,float b,float a=1.0f):red(std::clamp(r,0.0f,1.0f)),grn(std::clamp(g,0.0f,1.0f)),blu(std::clamp(b,0.0f,1.0f)),alpha(std::clamp(a,0.0f,1.0f)){}
    static RGBAColor from_u8(uint8_t r,uint8_t g,uint8_t b,uint8_t a=255){return RGBAColor(r/255.0f,g/255.0f,b/255.0f,a/255.0f);}
    static RGBAColor transparent(){return{0,0,0,0};}
    static RGBAColor black(){return{0,0,0,1};}
    static RGBAColor white(){return{1,1,1,1};}
    static RGBAColor color_red(){return{1,0,0,1};}
    static RGBAColor color_green(){return{0,1,0,1};}
    static RGBAColor color_blue(){return{0,0,1,1};}
    std::string to_hex()const{auto h=[](float c)->int{return std::clamp(static_cast<int>(c*255.0f+0.5f),0,255);};char buf[10];snprintf(buf,sizeof(buf),"#%02x%02x%02x",h(red),h(grn),h(blu));return buf;}
    bool operator==(const RGBAColor&o)const{return red==o.red&&grn==o.grn&&blu==o.blu&&alpha==o.alpha;}
};

struct HSLColor { float hue=0,saturation=0,lightness=0,alpha=1.0f; HSLColor()=default; HSLColor(float h,float s,float l,float a=1.0f):hue(h),saturation(std::clamp(s,0.0f,1.0f)),lightness(std::clamp(l,0.0f,1.0f)),alpha(std::clamp(a,0.0f,1.0f)){} };

enum class ColorSpace : uint8_t { Srgb=0,Hsl,Hwb,Lab,Lch,Oklab,Oklch,DisplayP3,A98Rgb,ProphotoRgb,Rec2020,XyzD50,XyzD65 };
inline const char* color_space_name(ColorSpace cs){switch(cs){case ColorSpace::Srgb:return"srgb";case ColorSpace::Hsl:return"hsl";case ColorSpace::Hwb:return"hwb";case ColorSpace::Lab:return"lab";case ColorSpace::Lch:return"lch";case ColorSpace::Oklab:return"oklab";case ColorSpace::Oklch:return"oklch";case ColorSpace::DisplayP3:return"display-p3";default:return"srgb";}}

struct AbsoluteColor { ColorComponents components; float alpha=1.0f; ColorSpace color_space=ColorSpace::Srgb; AbsoluteColor()=default; AbsoluteColor(ColorComponents comps,float a,ColorSpace cs):components(comps),alpha(std::clamp(a,0.0f,1.0f)),color_space(cs){} static AbsoluteColor srgb(float r,float g,float b,float a=1.0f){return{{r,g,b},a,ColorSpace::Srgb};} static AbsoluteColor transparent(){return srgb(0,0,0,0);} bool operator==(const AbsoluteColor&o)const{return components==o.components&&alpha==o.alpha&&color_space==o.color_space;} };

std::optional<RGBAColor> lookup_named_color(const std::string& name);

}} // namespace
