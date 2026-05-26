/* MPL 2.0 */
#pragma once
#include <string>
#include <vector>
#include <cstdint>
namespace style { namespace queries {
enum class SupportsConditionType:uint8_t{Not,And,Or,Declaration,Selector};
struct SupportsCondition{SupportsConditionType type=SupportsConditionType::Declaration;std::string property,value;std::vector<SupportsCondition> children;bool evaluate()const;};
}} // namespace
