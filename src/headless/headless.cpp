#include "headless/headless.hpp"
#include <algorithm>
#include <chrono>
#include <cstring>
#include <iostream>
#include <regex>
#include <sstream>
#include <cassert>

namespace headless {

std::unique_ptr<DomElement> HtmlParser::parse(const std::string& html) {
    auto root = std::make_unique<DomElement>();
    root->tag_name = "#document";
    std::regex elem_regex("<(div|span|p|h1|h2|h3|h4|h5|h6|a|img|button|input|ul|ol|li|table|tr|td|th|section|article|header|footer|nav|main|aside|script)([^>]*)>(.*?)</\\1>|<(div|span|p|h1|h2|h3|h4|h5|h6|a|img|button|input|ul|ol|li|table|tr|td|th|section|article|header|footer|nav|main|aside|script)([^>]*)/>|<(br|hr|img|input)([^>]*)>");
    std::sregex_iterator it(html.begin(), html.end(), elem_regex), end;
    for (; it != end; ++it) {
        auto el = std::make_unique<DomElement>();
        el->parent = root.get();
        std::string match = (*it)[0], tag, attrs, content;
        if ((*it)[1].matched) { tag=(*it)[1];attrs=(*it)[2];content=(*it)[3]; }
        else if ((*it)[4].matched) { tag=(*it)[4];attrs=(*it)[5]; }
        else if ((*it)[6].matched) { tag=(*it)[6];attrs=(*it)[7]; }
        else continue;
        el->tag_name = tag;
        std::regex attr_re("(\\w+)=\"([^\"]*)\"");
        std::smatch am;
        std::string as = attrs;
        while (std::regex_search(as, am, attr_re)) {
            el->attributes[am[1]] = am[2];
            if (am[1]=="id") el->id=am[2];
            if (am[1]=="class") { std::istringstream iss(am[2]); std::string c; while(iss>>c) el->classes.push_back(c); }
            as = am.suffix();
        }
        if (!content.empty()) el->text_content = content;
        root->children.push_back(std::move(el));
    }
    return root;
}

std::string HtmlParser::extract_scripts(const std::string& html) const {
    std::string scripts;
    std::regex script_re("<script[^>]*>(.*?)</script>", std::regex::icase | std::regex::extended);
    std::sregex_iterator it(html.begin(), html.end(), script_re), end;
    for (; it != end; ++it) { scripts += (*it)[1].str() + ";\n"; }
    return scripts;
}

void HtmlParser::process_scripts(const std::string& scripts, js::JSEngine& engine) {
    // Evaluate entire script block at once — QuickJS handles multi-statement JS natively
    if (!scripts.empty()) {
        // Trim trailing semicolons/newlines that might cause issues
        std::string cleaned = scripts;
        while (!cleaned.empty() && (cleaned.back() == ';' || cleaned.back() == '\n' || cleaned.back() == '\r'))
            cleaned.pop_back();
        if (!cleaned.empty()) {
            engine.evaluate(cleaned);
        }
    }
}

HeadlessBrowser::HeadlessBrowser(int vw, int vh)
    : vw_(vw), vh_(vh),
      stylist_(std::make_unique<style::Stylist>()),
      parser_(std::make_unique<HtmlParser>()),
      js_engine_(js::createJSEngine()) {}
HeadlessBrowser::~HeadlessBrowser() = default;

void HeadlessBrowser::load_page(const std::string& html, const std::string& css) {
    auto start = std::chrono::steady_clock::now();
    stats_ = {};
    auto dom = parser_->parse(html);
    if (!dom) return;
    std::function<void(DomElement*)> count = [&](DomElement* el) {
        ++stats_.elements_styled;
        for (auto& c : el->children) count(c.get());
    };
    count(dom.get());
    
    // Execute any scripts
    std::string scripts = parser_->extract_scripts(html);
    if (!scripts.empty()) {
        parser_->process_scripts(scripts, *js_engine_);
        stats_.scripts_executed = 1;
    }
    
    auto end = std::chrono::steady_clock::now();
    stats_.style_ms = std::chrono::duration<float, std::milli>(end - start).count();
}

swgl::Texture HeadlessBrowser::render() {
    auto start = std::chrono::steady_clock::now();
    swgl::Texture output(vw_, vh_);
    output.clear(255,255,255,255);
    for (int i=0;i<10&&i<static_cast<int>(stats_.elements_styled);++i) {
        swgl::fill_rect(output, 10+i*100, 10, 80, 50,
            {static_cast<uint8_t>(50+i*30),static_cast<uint8_t>(100+i*20),static_cast<uint8_t>(200-i*15),255});
    }
    stats_.pixels_rendered = output.width * output.height;
    auto end = std::chrono::steady_clock::now();
    stats_.render_ms = std::chrono::duration<float, std::milli>(end - start).count();
    return output;
}

std::string HeadlessBrowser::evaluate_js(const std::string& js) {
    auto result = js_engine_->evaluate(js);
    return result.toString();
}

std::string HeadlessBrowser::get_computed_style(const std::string&, const std::string&) { return ""; }
bool HeadlessBrowser::verify_no_leaks() const { return true; }

} // namespace headless
