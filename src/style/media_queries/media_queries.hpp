/* MPL 2.0 */
//! Media query parsing and evaluation.
//! Covers media_queries/mod.rs, media_list.rs, media_query.rs
#pragma once
#include <string>
#include <vector>
#include "style/queries/queries.hpp"

namespace style { namespace media_queries {

using queries::QueryContext;

enum class MediaType : uint8_t { All, Screen, Print, Speech };
enum class MediaFeatureOperator : uint8_t { Min, Max, Eq };

struct MediaExpression {
    std::string feature;
    MediaFeatureOperator op = MediaFeatureOperator::Eq;
    std::string value;
    bool negated = false;

    bool evaluate(const QueryContext& ctx) const;
};

struct MediaQuery {
    MediaType media_type = MediaType::All;
    bool negated = false;
    std::vector<MediaExpression> expressions;
    bool only_keyword = false;

    bool evaluate(const QueryContext& ctx) const;
    bool is_all() const { return media_type==MediaType::All && expressions.empty(); }
    void to_css(std::ostream& dest) const;
};

struct MediaList {
    std::vector<MediaQuery> queries;
    bool evaluate(const QueryContext& ctx) const {
        if (queries.empty()) return true;
        for (const auto& q : queries) if (q.evaluate(ctx)) return true;
        return false;
    }
    bool is_all() const { return queries.empty() || (queries.size()==1&&queries[0].is_all()); }
};

}}} // namespace
