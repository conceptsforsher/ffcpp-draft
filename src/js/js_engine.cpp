/* MPL 2.0 */
//! JS engine factory — QuickJS (ES2020+).
#include "js/js_engine_quickjs.hpp"

namespace js {

std::unique_ptr<JSEngine> createJSEngine() {
    auto engine = std::make_unique<QuickJSEngine>();
    if (engine->init()) {
        return engine;
    }
    // Ultimate fallback: stub engine
    return std::make_unique<StubJSEngine>();
}

} // namespace js
