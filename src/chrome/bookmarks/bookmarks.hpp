/* MPL 2.0 */
#pragma once
#include "chrome/chrome.hpp"
#include <vector>
namespace chrome {
class BookmarkManager {
public:
    struct Bookmark { std::string url, title; int id; };
    BookmarkManager(); ~BookmarkManager();
    void add(const std::string& url, const std::string& title);
    void remove(const std::string& url);
    std::vector<Bookmark> search(const std::string& q) const;
private:
    std::vector<Bookmark> bookmarks_;
};
} // namespace chrome
