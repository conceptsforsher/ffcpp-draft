/* MPL 2.0 */
#pragma once
#include "widget/widget_base.hpp"
#include <vector>
#include <string>
#include <functional>
namespace chrome {
using widget::Widget;
using widget::Container;
using widget::Painter;
using widget::Event;
using widget::EventType;
using widget::SizeRequest;
using widget::Allocation;
class TabBar : public Widget { public: TabBar(); ~TabBar() override; const char* widget_type() const override { return "TabBar"; } SizeRequest get_size_request() const override; void draw(Painter&) override; bool on_event(Event&) override; private: int state_=0; std::string label_,url_,icon_name_; std::vector<std::unique_ptr<Widget>> items_; };
class Tab : public Widget { public: Tab(); ~Tab() override; const char* widget_type() const override { return "Tab"; } SizeRequest get_size_request() const override; void draw(Painter&) override; bool on_event(Event&) override; void set_label(const std::string& l) { label_=l; } private: int state_=0; std::string label_,url_,icon_name_; };
class Toolbar : public Container { public: Toolbar(); ~Toolbar() override; const char* widget_type() const override { return "Toolbar"; } SizeRequest get_size_request() const override; void draw(Painter&) override; bool on_event(Event&) override; private: int state_=0; std::string label_; };
class NavBar : public Widget { public: NavBar(); ~NavBar() override; const char* widget_type() const override { return "NavBar"; } SizeRequest get_size_request() const override; void draw(Painter&) override; bool on_event(Event&) override; private: int state_=0; };
class AddressBar : public Widget { public: AddressBar(); ~AddressBar() override; const char* widget_type() const override { return "AddressBar"; } SizeRequest get_size_request() const override; void draw(Painter&) override; bool on_event(Event&) override; void set_url(const std::string& u) { url_=u; } std::string url() const { return url_; } private: int state_=0; std::string url_; };
class MenuBar : public Widget { public: MenuBar(); ~MenuBar() override; const char* widget_type() const override { return "MenuBar"; } SizeRequest get_size_request() const override; void draw(Painter&) override; bool on_event(Event&) override; private: int state_=0; };
class Menu : public Widget { public: Menu(); ~Menu() override; const char* widget_type() const override { return "Menu"; } SizeRequest get_size_request() const override; void draw(Painter&) override; bool on_event(Event&) override; void add_item(const std::string& label, int id) { } private: int state_=0; };
class MenuItem : public Widget { public: MenuItem(); ~MenuItem() override; const char* widget_type() const override { return "MenuItem"; } SizeRequest get_size_request() const override; void draw(Painter&) override; bool on_event(Event&) override; private: int state_=0; };
class BookmarkBar : public Widget { public: BookmarkBar(); ~BookmarkBar() override; const char* widget_type() const override { return "BookmarkBar"; } SizeRequest get_size_request() const override; void draw(Painter&) override; bool on_event(Event&) override; private: int state_=0; };
class Bookmark : public Widget { public: Bookmark(); ~Bookmark() override; const char* widget_type() const override { return "Bookmark"; } SizeRequest get_size_request() const override; void draw(Painter&) override; bool on_event(Event&) override; void set_url(const std::string& u) { url_=u; } private: int state_=0; std::string url_,title_; };
class Sidebar : public Widget { public: Sidebar(); ~Sidebar() override; const char* widget_type() const override { return "Sidebar"; } SizeRequest get_size_request() const override; void draw(Painter&) override; bool on_event(Event&) override; private: int state_=0; };
class StatusBar : public Widget { public: StatusBar(); ~StatusBar() override; const char* widget_type() const override { return "StatusBar"; } SizeRequest get_size_request() const override; void draw(Painter&) override; bool on_event(Event&) override; void set_text(const std::string& t) { text_=t; } private: int state_=0; std::string text_; };
class PopupManager : public Widget { public: PopupManager(); ~PopupManager() override; const char* widget_type() const override { return "PopupManager"; } SizeRequest get_size_request() const override; void draw(Painter&) override; bool on_event(Event&) override; private: int state_=0; };
} // namespace chrome
