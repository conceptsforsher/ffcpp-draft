/* MPL 2.0 */
#pragma once
#include "style/forward.hpp"

namespace style {
class StyleAdjuster {
public:
    explicit StyleAdjuster(ComputedValues& s):style_(&s){}
    void adjust();
private:
    ComputedValues* style_;
    void adjust_for_position();void adjust_for_float();
    void blockify();void inlinify();
};
} // namespace
