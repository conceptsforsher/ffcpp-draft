/* MPL 2.0 */
#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "style/forward.hpp"

namespace style { namespace invalidation {
class InvalidationMap {
public:
    void add_dependency(const std::string& key,const std::string& sel);
    void add_state_dependency(uint64_t state,const std::string& sel);
    std::vector<std::string> selectors_for_key(const std::string& key)const;
    std::vector<std::string> selectors_for_state(uint64_t state)const;
    void clear();size_t size()const;
private:
    std::unordered_map<std::string,std::vector<std::string>> class_map_,id_map_,attr_map_;
    std::unordered_map<uint64_t,std::vector<std::string>> state_map_;
};
struct InvalidationSet {uint8_t kind=0;std::string value;bool invalidates_descendants=false;};
struct InvalidationElement {const GeckoElement* element=nullptr;};
class StylesheetInvalidator {
public:
    void stylesheet_changed(uint64_t id);bool needs_restyle(const GeckoElement*)const;void flush();
    std::unordered_set<uint64_t> changed_sheets_;
};
class ViewportUnitInvalidator {public:void viewport_changed();bool viewport_changed_=false;};
class TreeStyleInvalidator {
public:
    TreeStyleInvalidator();
    void invalidate_element(const GeckoElement* el,const InvalidationSet& set);
    void invalidate_state(const GeckoElement* el,uint64_t state);
    void invalidate_stylesheets();void invalidate_viewport();
    std::vector<const GeckoElement*> collect_pending_restyles();
    bool has_pending()const;void clear();
private:
    std::unordered_map<const GeckoElement*,uint32_t> pending_;uint32_t gen_=0;
};
}} // namespace
