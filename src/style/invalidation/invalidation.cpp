/* MPL 2.0 */
#include "style/invalidation/invalidation.hpp"
namespace style { namespace invalidation {
TreeStyleInvalidator::TreeStyleInvalidator()=default;
void InvalidationMap::add_dependency(const std::string& k,const std::string& s){if(k.empty())return;if(k[0]=='.')class_map_[k.substr(1)].push_back(s);else if(k[0]=='#')id_map_[k.substr(1)].push_back(s);}
void InvalidationMap::add_state_dependency(uint64_t st,const std::string& s){state_map_[st].push_back(s);}
std::vector<std::string> InvalidationMap::selectors_for_key(const std::string& k)const{std::vector<std::string> r;auto add=[&](auto&m){auto it=m.find(k);if(it!=m.end())r.insert(r.end(),it->second.begin(),it->second.end());};add(class_map_);add(id_map_);return r;}
std::vector<std::string> InvalidationMap::selectors_for_state(uint64_t st)const{std::vector<std::string> r;for(auto&[s,v]:state_map_)if(s&st)r.insert(r.end(),v.begin(),v.end());return r;}
void InvalidationMap::clear(){class_map_.clear();id_map_.clear();attr_map_.clear();state_map_.clear();}
size_t InvalidationMap::size()const{return class_map_.size()+id_map_.size()+state_map_.size();}
void StylesheetInvalidator::stylesheet_changed(uint64_t id){changed_sheets_.insert(id);}
bool StylesheetInvalidator::needs_restyle(const GeckoElement*)const{return !changed_sheets_.empty();}
void StylesheetInvalidator::flush(){changed_sheets_.clear();}
void ViewportUnitInvalidator::viewport_changed(){viewport_changed_=true;}
void TreeStyleInvalidator::invalidate_element(const GeckoElement* el,const InvalidationSet&){pending_[el]=gen_;}
void TreeStyleInvalidator::invalidate_state(const GeckoElement* el,uint64_t){pending_[el]=gen_;}
void TreeStyleInvalidator::invalidate_stylesheets(){}
void TreeStyleInvalidator::invalidate_viewport(){}
std::vector<const GeckoElement*> TreeStyleInvalidator::collect_pending_restyles(){std::vector<const GeckoElement*> r;for(auto&[el,g]:pending_)r.push_back(el);return r;}
bool TreeStyleInvalidator::has_pending()const{return !pending_.empty();}
void TreeStyleInvalidator::clear(){pending_.clear();gen_++;}
}} // namespace
