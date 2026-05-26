#pragma once
#include <string>
#include <vector>
#include <memory>
#include <functional>
#include "style/stylist.hpp"
#include "swgl/swgl.hpp"
#include "js/js_engine.hpp"
#include "dom/dom_bindings.hpp"

namespace headless {

struct DomElement {
    std::string tag_name, id, text_content;
    std::vector<std::string> classes;
    std::unordered_map<std::string, std::string> attributes;
    DomElement* parent = nullptr;
    std::vector<std::unique_ptr<DomElement>> children;
    bool has_class(const std::string& cls) const {
        return std::find(classes.begin(), classes.end(), cls) != classes.end();
    }
};

class HtmlParser {
public:
    std::unique_ptr<DomElement> parse(const std::string& html);
    std::string extract_scripts(const std::string& html) const;
    void process_scripts(const std::string& scripts, js::JSEngine& engine);
};

class HeadlessBrowser {
public:
    HeadlessBrowser(int vw = 1920, int vh = 1080);
    ~HeadlessBrowser();
    void load_page(const std::string& html, const std::string& css = "");
    swgl::Texture render();
    std::string evaluate_js(const std::string& js);
    std::string get_computed_style(const std::string& selector, const std::string& property);
    struct RenderStats { size_t elements_styled=0, pixels_rendered=0; float style_ms=0, render_ms=0; size_t scripts_executed=0; };
    RenderStats stats() const { return stats_; }
    bool verify_no_leaks() const;
private:
    int vw_, vh_;
    std::unique_ptr<style::Stylist> stylist_;
    std::unique_ptr<HtmlParser> parser_;
    std::unique_ptr<js::JSEngine> js_engine_;
    RenderStats stats_;
};

} // namespace headless
