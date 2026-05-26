/* MPL 2.0 */
#pragma once
#include <cstdint>
#include "style/values/computed/types.hpp"

namespace style {
namespace gecko { class GeckoElement; }
class Stylist;
namespace matching {

enum class StyleChange : uint8_t { Unchanged=0, Changed=1, ResetOnly=2 };
struct StyleDifference { StyleChange change=StyleChange::Unchanged;uint32_t damage=0;bool is_changed()const{return change!=StyleChange::Unchanged;}static StyleDifference unchanged(){return{};} };

StyleDifference compute_style(gecko::GeckoElement& el,const values::computed::ComputedValues* parent,Stylist& s);

}} // namespace
