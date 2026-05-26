/* MPL 2.0 */
//! Stylesheet set — manages the collection of stylesheets for a document.
//! Corresponds to stylesheet_set.rs (707 lines)
#pragma once
#include <memory>
#include <vector>
#include <string>
#include <unordered_set>

namespace style {

class Stylesheet;
struct DocumentCascadeData;

/// Origin of a stylesheet in the cascade.
enum class SheetOrigin : uint8_t { UserAgent, User, Author };

/// A collection of stylesheets organized by origin.
class StylesheetSet {
public:
    StylesheetSet();
    ~StylesheetSet();

    /// Append a new stylesheet.
    void append_stylesheet(std::shared_ptr<Stylesheet> sheet, SheetOrigin origin);

    /// Remove a stylesheet.
    void remove_stylesheet(std::shared_ptr<Stylesheet> sheet);

    /// Insert a stylesheet before another.
    void insert_stylesheet_before(std::shared_ptr<Stylesheet> sheet,
                                  std::shared_ptr<Stylesheet> reference);

    /// Get all author stylesheets.
    const std::vector<std::shared_ptr<Stylesheet>>& author_sheets() const;

    /// Get all user-agent stylesheets.
    const std::vector<std::shared_ptr<Stylesheet>>& ua_sheets() const;

    /// Get all user stylesheets.
    const std::vector<std::shared_ptr<Stylesheet>>& user_sheets() const;

    /// Flatten all stylesheets into a single cascade data structure.
    void collect_cascade_data(DocumentCascadeData& data) const;

    /// Number of stylesheets total.
    size_t total_count() const;

    /// Force recomputation of cascade data.
    void mark_dirty() { dirty_ = true; }
    bool is_dirty() const { return dirty_; }

private:
    std::vector<std::shared_ptr<Stylesheet>> author_sheets_;
    std::vector<std::shared_ptr<Stylesheet>> ua_sheets_;
    std::vector<std::shared_ptr<Stylesheet>> user_sheets_;
    std::unordered_set<const Stylesheet*> known_sheets_;
    bool dirty_ = false;
};

} // namespace style
