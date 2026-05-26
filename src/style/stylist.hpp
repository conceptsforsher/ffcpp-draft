/* MPL 2.0 */
//! Stylist — central style system coordinator.
#pragma once
#include <cstdint>
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include "style/values/types.hpp"
#include "style/color/types.hpp"
#include "style/queries/queries.hpp"
#include "style/values/computed/types.hpp"
#include "style/forward.hpp"

namespace style {

// Additional non-forward-declared types
class Stylesheet;
struct DocumentCascadeData;
struct CascadeData;
struct Rule;
class RuleTree;
class StyleSharingCache;

enum class Origin : uint8_t { UserAgent=0, User=1, Author=2 };
enum class RuleInclusion : uint8_t { All=0, DefaultOnly=1 };
struct MediaQuery { bool is_all() const { return true; } void to_css(std::ostream&) const {} };

enum class PseudoElement : uint16_t {
    None=0,Before,After,Marker,Backdrop,Selection,FirstLine,FirstLetter,
    Placeholder,Cue,FileSelectorButton,Highlight,TargetText
};

class Stylist {
public:
    Stylist();~Stylist();
    void add_stylesheet(std::shared_ptr<Stylesheet> s);
    void remove_stylesheet(std::shared_ptr<Stylesheet> s);
    void force_stylesheet_rebuild();
    bool has_stylesheet(const Stylesheet& s) const;
    size_t stylesheet_count() const;
    const DocumentCascadeData& document_cascade_data() const;
    bool author_styles_enabled() const;
    void set_author_styles_enabled(bool e);
    bool evaluate_media_query(const MediaQuery& q) const;
    void media_features_changed();
    bool has_author_feature(const std::string& f) const;
    void collect_features(std::vector<std::string>& features) const;
    size_t memory_usage() const;
    struct Stats { size_t num_stylesheets=0,num_rules=0,num_rebuilds=0,cascade_data_size=0; };
    Stats stats() const;
private:
    struct Impl;std::unique_ptr<Impl> impl_;
};

struct DocumentCascadeData {bool is_empty()const{return true;}size_t total_rule_count()const{return 0;}void clear(){}};
struct StyleContext {int vw=1920,vh=1080;float dpr=1.0f;bool is_print=false,skip_animations=false;RuleInclusion ri=RuleInclusion::All;float fs=16,rfs=16;const ComputedValues* parent_style=nullptr;};

} // namespace style
