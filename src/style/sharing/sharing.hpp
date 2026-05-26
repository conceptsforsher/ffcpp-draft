/* MPL 2.0 */
#pragma once
#include <cstdint>
#include <memory>
#include "style/forward.hpp"

namespace style {
class StyleSharingCache {
public:
    StyleSharingCache();~StyleSharingCache();
    const ComputedValues* find_shareable_style(const GeckoElement& el);
    void cache_style(const GeckoElement& el,const ComputedValues& style);
    void clear();size_t size() const;
    struct Stats {size_t hits=0,misses=0,insertions=0;};
    const Stats& stats() const {return stats_;}
private:
    struct Impl;std::unique_ptr<Impl> impl_;
    Stats stats_;
};
} // namespace
