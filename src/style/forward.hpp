/* MPL 2.0 */
//! Consolidated forward declarations for the style system.
#pragma once
#include "style/values/computed/types.hpp"

namespace style {

// Gecko DOM types — full definition in gecko/wrapper.hpp
// (forward-declare here so other headers don't need to include the full wrapper)
namespace gecko { class GeckoElement; class GeckoNode; }
using gecko::GeckoElement;
using gecko::GeckoNode;

using values::computed::ComputedValues;

class Stylist;
class Stylesheet;
class RuleTree;
class StyleSharingCache;
struct DocumentCascadeData;
struct CascadeData;
struct StyleContext;
struct TraversalFlags;

namespace invalidation { class TreeStyleInvalidator; }
namespace matching { struct StyleDifference; }

} // namespace style
