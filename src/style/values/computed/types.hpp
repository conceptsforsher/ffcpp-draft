/* MPL 2.0 */
//! Computed CSS value types — fully resolved.
#pragma once
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <cstdint>
#include <cmath>
#include "style/color/types.hpp"

namespace style { namespace values { namespace computed {

using color::AbsoluteColor;

struct ComputedLength { float pixels=0; bool is_auto=false; ComputedLength()=default; explicit ComputedLength(float px):pixels(px){} static ComputedLength auto_val(){ComputedLength l;l.is_auto=true;return l;} static ComputedLength zero(){return ComputedLength(0);} float px()const{return pixels;} };
struct ComputedLengthPercentage { float pixels=0,percentage=0; bool has_pct=false,is_auto=false; ComputedLengthPercentage()=default; static ComputedLengthPercentage px(float v){ComputedLengthPercentage l;l.pixels=v;return l;} static ComputedLengthPercentage pct(float v){ComputedLengthPercentage l;l.percentage=v;l.has_pct=true;return l;} static ComputedLengthPercentage zero(){return px(0);} float resolve(float ref)const{return pixels+(has_pct?percentage*ref:0);} };
using ComputedColor = AbsoluteColor;
struct ComputedNumber { float value=0; ComputedNumber()=default; explicit ComputedNumber(float v):value(v){} };
struct ComputedInteger { int32_t value=0; ComputedInteger()=default; explicit ComputedInteger(int32_t v):value(v){} };
struct ComputedAngle { float degrees=0; ComputedAngle()=default; explicit ComputedAngle(float d):degrees(d){} };
struct ComputedTime { float seconds=0; ComputedTime()=default; explicit ComputedTime(float s):seconds(s){} };

enum class DisplayOutside : uint8_t { Block, Inline, None };
enum class DisplayInside : uint8_t { Flow, Flex, Grid, Table };
struct ComputedDisplay { DisplayOutside outside=DisplayOutside::Inline; DisplayInside inside=DisplayInside::Flow; bool is_list_item=false; bool is_none()const{return outside==DisplayOutside::None;} bool is_flex()const{return inside==DisplayInside::Flex;} bool is_grid()const{return inside==DisplayInside::Grid;} };

enum class ComputedPosition : uint8_t { StaticPos, RelativePos, AbsolutePos, FixedPos, StickyPos };
enum class OverflowType : uint8_t { VisibleVal, HiddenVal, ClipVal, ScrollVal, AutoVal };
enum class VisibilityType : uint8_t { VisibleVal, HiddenVal, CollapseVal };
enum class TextAlignType : uint8_t { StartVal, EndVal, LeftVal, RightVal, CenterVal, JustifyVal };
enum class FloatType : uint8_t { NoneVal, LeftVal, RightVal };

struct ComputedFontWeight { int value=400; ComputedFontWeight()=default; explicit ComputedFontWeight(int v):value(std::clamp(v,1,1000)){} };
struct ComputedFontSize { float pixels=16; ComputedFontSize()=default; explicit ComputedFontSize(float px):pixels(px){} };

struct ComputedBox {
    ComputedLengthPercentage margin_top,margin_right,margin_bottom,margin_left;
    ComputedLengthPercentage padding_top,padding_right,padding_bottom,padding_left;
    ComputedLength border_top_width{0},border_right_width{0},border_bottom_width{0},border_left_width{0};
    ComputedLength width{0},height{0};
};

struct ComputedTransformOp {
    enum OpType { MatrixOp, TranslateOp, ScaleOp, RotateOp, InterpolatedOp };
    OpType type=MatrixOp;
    std::array<float,16> m={1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
    ComputedTransformOp()=default;
    static ComputedTransformOp identity(){return{};}
    static ComputedTransformOp translate(float tx,float ty){ComputedTransformOp op;op.type=TranslateOp;op.m[3]=tx;op.m[7]=ty;return op;}
    static ComputedTransformOp scale(float sx,float sy){ComputedTransformOp op;op.type=ScaleOp;op.m[0]=sx;op.m[5]=sy;return op;}
    static ComputedTransformOp rotate(float deg){ComputedTransformOp op;op.type=RotateOp;float r=deg*3.14159265359f/180.0f;op.m[0]=cos(r);op.m[1]=sin(r);op.m[4]=-sin(r);op.m[5]=cos(r);return op;}
};
using ComputedTransform = std::vector<ComputedTransformOp>;

struct ComputedBorderSide { ComputedLength width{0}; enum StyleType { NoneVal,HiddenVal,DottedVal,DashedVal,SolidVal,DoubleVal,GrooveVal,RidgeVal,InsetVal,OutsetVal }; StyleType style=NoneVal; ComputedColor color=AbsoluteColor::transparent(); };

struct ComputedText {
    ComputedColor color=AbsoluteColor::srgb(0,0,0);
    ComputedFontSize font_size{16};
    ComputedFontWeight font_weight{400};
    std::string font_family="serif";
    ComputedLengthPercentage line_height;
    TextAlignType text_align=TextAlignType::StartVal;
    float letter_spacing=0,word_spacing=0;
    std::string text_transform="none",text_decoration="none",white_space="normal";
    ComputedLengthPercentage text_indent;
};

struct ComputedFlex {
    float flex_grow=0,flex_shrink=1;
    ComputedLengthPercentage flex_basis;
    int order=0;
    enum DirType { RowVal,RowReverseVal,ColVal,ColReverseVal };
    DirType direction=RowVal;
    enum WrapType { NoWrapVal,WrapVal,WrapReverseVal };
    WrapType wrap=NoWrapVal;
    enum JustifyType { JustifyStartVal,JustifyEndVal,CenterVal,SpaceBetweenVal,SpaceAroundVal,SpaceEvenlyVal };
    JustifyType justify_content=JustifyStartVal;
    enum AlignType { AlignStretchVal,AlignStartVal,AlignEndVal,AlignCenterVal,BaselineVal };
    AlignType align_items=AlignStretchVal;
    AlignType align_self=AlignType::AlignStretchVal;
};

struct ComputedEasing {
    enum EaseType { LinearEase,EaseVal,EaseInVal,EaseOutVal,EaseInOutVal,CubicBezierVal,StepsVal };
    EaseType type=EaseVal;
    float x1=0.25f,y1=0.1f,x2=0.25f,y2=1.0f;
    int steps=1;
};

struct ComputedValues {
    ComputedDisplay display;
    ComputedPosition position=ComputedPosition::StaticPos;
    FloatType float_val=FloatType::NoneVal;
    ComputedBox box;
    ComputedText text;
    ComputedFlex flex;
    OverflowType overflow_x=OverflowType::VisibleVal,overflow_y=OverflowType::VisibleVal;
    VisibilityType visibility=VisibilityType::VisibleVal;
    float opacity=1.0f;
    int32_t z_index=0;
    ComputedTransform transform;
    ComputedColor background_color=AbsoluteColor::transparent();
    ComputedBorderSide border_top,border_right,border_bottom,border_left;
    ComputedEasing transition_timing;
    ComputedTime transition_duration{0},transition_delay{0};
    std::unordered_map<std::string,std::string> custom_properties;
};

}}} // namespace
