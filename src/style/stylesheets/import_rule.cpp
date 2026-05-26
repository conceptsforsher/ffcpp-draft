/* MPL 2.0 */
//! @import rule: loading external stylesheets.
//! https://drafts.csswg.org/css-cascade-5/#at-import
#include "style/stylesheets/import_rule.hpp"
#include <regex>

namespace style { namespace stylesheets {

ImportRule::ImportRule() = default;
ImportRule::~ImportRule() = default;

void ImportRule::set_url(const std::string& url) {
    // Strip url() wrapper if present
    url_ = url;
    if (url_.starts_with("url(") && url_.ends_with(")")) {
        url_ = url_.substr(4, url_.size() - 5);
    }
    // Strip quotes
    if ((url_.starts_with("\"") && url_.ends_with("\"")) ||
        (url_.starts_with("'") && url_.ends_with("'"))) {
        url_ = url_.substr(1, url_.size() - 2);
    }
}

void ImportRule::set_media_condition(const std::string& condition) {
    media_condition_ = condition;
    if (!condition.empty() && condition != "all") {
        has_media_query_ = true;
    }
}

void ImportRule::set_layer_name(const std::string& layer) {
    layer_name_ = layer;
    has_layer_ = !layer.empty();
}

void ImportRule::set_supports_condition(const std::string& condition) {
    supports_condition_ = condition;
    has_supports_ = !condition.empty();
}

const std::string& ImportRule::url() const { return url_; }
const std::string& ImportRule::media_condition() const { return media_condition_; }
const std::string& ImportRule::layer_name() const { return layer_name_; }
const std::string& ImportRule::supports_condition() const { return supports_condition_; }
bool ImportRule::has_media_query() const { return has_media_query_; }

void ImportRule::set_loaded_stylesheet(std::shared_ptr<Stylesheet> sheet) {
    loaded_sheet_ = std::move(sheet);
}

std::shared_ptr<Stylesheet> ImportRule::loaded_stylesheet() const {
    return loaded_sheet_;
}

bool ImportRule::is_loaded() const { return loaded_sheet_ != nullptr; }

void ImportRule::to_css(std::ostream& dest) const {
    dest << "@import \"" << url_ << "\"";
    if (has_layer_) dest << " layer(" << layer_name_ << ")";
    if (has_supports_) dest << " supports(" << supports_condition_ << ")";
    if (has_media_query_) dest << " " << media_condition_;
    dest << ";";
}

// URL resolution
std::string ImportRule::resolve_url(const std::string& base_url) const {
    if (url_.find("://") != std::string::npos) {
        return url_;  // Already absolute
    }
    if (url_.starts_with("/")) {
        // Absolute path: prepend origin from base_url
        size_t scheme_end = base_url.find("://");
        if (scheme_end != std::string::npos) {
            size_t path_start = base_url.find('/', scheme_end + 3);
            if (path_start != std::string::npos) {
                return base_url.substr(0, path_start) + url_;
            }
        }
        return url_;
    }
    // Relative: resolve against base directory
    size_t last_slash = base_url.rfind('/');
    if (last_slash != std::string::npos && last_slash > 7) {
        return base_url.substr(0, last_slash + 1) + url_;
    }
    return url_;
}

#ifdef STYLE_TEST
bool test_import_rule() {
    ImportRule rule;
    rule.set_url("url(\"theme.css\")");
    assert(rule.url() == "theme.css");
    
    rule.set_media_condition("screen");
    assert(rule.has_media_query());
    
    assert(rule.resolve_url("https://example.com/css/main.css") == "https://example.com/css/theme.css");
    
    return true;
}
#endif

}} // namespace
