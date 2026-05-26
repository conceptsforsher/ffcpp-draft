/* MPL 2.0 */
#include "style/sharing/sharing.hpp"
#include "style/gecko/wrapper.hpp"
#include <unordered_map>

namespace style {
struct StyleSharingCache::Impl {
    struct Key {std::string tag,id;std::vector<std::string> classes;
        bool operator==(const Key&o)const{return tag==o.tag&&id==o.id&&classes==o.classes;}
    };
    struct Hash {size_t operator()(const Key&k)const{return std::hash<std::string>{}(k.tag)^std::hash<std::string>{}(k.id)<<1;}};
    std::unordered_map<Key,const ComputedValues*,Hash> cache;
};
StyleSharingCache::StyleSharingCache():impl_(std::make_unique<Impl>()){}
StyleSharingCache::~StyleSharingCache()=default;
const ComputedValues* StyleSharingCache::find_shareable_style(const GeckoElement& el){++stats_.misses;return nullptr;}
void StyleSharingCache::cache_style(const GeckoElement& el,const ComputedValues& s){++stats_.insertions;}
void StyleSharingCache::clear(){impl_->cache.clear();}
size_t StyleSharingCache::size()const{return impl_->cache.size();}
} // namespace style
