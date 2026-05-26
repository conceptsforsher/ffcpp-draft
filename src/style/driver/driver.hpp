/* MPL 2.0 */
#pragma once
#include <memory>
#include "style/forward.hpp"

namespace style {
class StyleDriver {
public:
    StyleDriver();~StyleDriver();
    void set_stylist(Stylist* s);
    void traverse(GeckoElement& root);
    void process_restyles();
    void tick_animations();
    void handle_viewport_change(int w,int h);
    void handle_stylesheet_change();
    struct Stats {size_t traversals=0,elements_styled=0;};
    Stats stats() const;
private:
    Stylist* stylist_=nullptr;
    Stats stats_;
};
} // namespace
