/* MPL 2.0 - Widget Containers */
#pragma once
#include "widget/widget_base.hpp"
#include <vector>
#include <memory>
#include <string>

namespace widget {

class Box : public Container {
public:
    Box();
    ~Box() override;
    const char* widget_type() const override { return "Box"; }
    SizeRequest get_size_request() const override;
    void size_allocate(const Allocation& a) override;
    void draw(Painter& p) override;
    bool on_event(Event& e) override;
    void set_orientation(int o) { orientation_ = o; }
    void set_spacing(int s) { spacing_ = s; }
    void set_homogeneous(bool h) { homogeneous_ = h; }
private:
    int orientation_ = 0;
    bool homogeneous_ = false;
};

class Grid : public Container {
public:
    Grid(); ~Grid() override;
    const char* widget_type() const override { return "Grid"; }
    SizeRequest get_size_request() const override;
    void size_allocate(const Allocation& a) override;
    void draw(Painter& p) override;
    bool on_event(Event& e) override;
    void set_rows(int r) { rows_ = r; }
    void set_columns(int c) { cols_ = c; }
private:
    int rows_ = 1, cols_ = 1;
};

class Notebook : public Container {
public:
    Notebook(); ~Notebook() override;
    const char* widget_type() const override { return "Notebook"; }
    SizeRequest get_size_request() const override;
    void size_allocate(const Allocation& a) override;
    void draw(Painter& p) override;
    bool on_event(Event& e) override;
    void set_current_page(int p) { current_page_ = p; }
    int current_page() const { return current_page_; }
private:
    int current_page_ = 0;
};

class Paned : public Container {
public:
    Paned(); ~Paned() override;
    const char* widget_type() const override { return "Paned"; }
    SizeRequest get_size_request() const override;
    void size_allocate(const Allocation& a) override;
    void draw(Painter& p) override;
    bool on_event(Event& e) override;
private:
    int position_ = 200;
};

class Frame : public Container {
public:
    Frame(); ~Frame() override;
    const char* widget_type() const override { return "Frame"; }
    SizeRequest get_size_request() const override;
    void size_allocate(const Allocation& a) override;
    void draw(Painter& p) override;
    bool on_event(Event& e) override;
    void set_label(const std::string& l) { label_ = l; }
private:
    std::string label_;
};

class ScrolledWindow : public Container {
public:
    ScrolledWindow(); ~ScrolledWindow() override;
    const char* widget_type() const override { return "ScrolledWindow"; }
    SizeRequest get_size_request() const override;
    void size_allocate(const Allocation& a) override;
    void draw(Painter& p) override;
    bool on_event(Event& e) override;
private:
    int policy_h_ = 0, policy_v_ = 0;
};

class Expander : public Container {
public:
    Expander(); ~Expander() override;
    const char* widget_type() const override { return "Expander"; }
    SizeRequest get_size_request() const override;
    void size_allocate(const Allocation& a) override;
    void draw(Painter& p) override;
    bool on_event(Event& e) override;
private:
    bool expanded_ = false;
};

class Viewport : public Container {
public:
    Viewport(); ~Viewport() override;
    const char* widget_type() const override { return "Viewport"; }
    SizeRequest get_size_request() const override;
    void size_allocate(const Allocation& a) override;
    void draw(Painter& p) override;
    bool on_event(Event& e) override;
};

class Fixed : public Container {
public:
    Fixed(); ~Fixed() override;
    const char* widget_type() const override { return "Fixed"; }
    SizeRequest get_size_request() const override;
    void size_allocate(const Allocation& a) override;
    void draw(Painter& p) override;
    bool on_event(Event& e) override;
};

class Overlay : public Container {
public:
    Overlay(); ~Overlay() override;
    const char* widget_type() const override { return "Overlay"; }
    SizeRequest get_size_request() const override;
    void size_allocate(const Allocation& a) override;
    void draw(Painter& p) override;
    bool on_event(Event& e) override;
};

class Stack : public Container {
public:
    Stack(); ~Stack() override;
    const char* widget_type() const override { return "Stack"; }
    SizeRequest get_size_request() const override;
    void size_allocate(const Allocation& a) override;
    void draw(Painter& p) override;
    bool on_event(Event& e) override;
    void set_visible_child(int n) { visible_child_ = n; }
private:
    int visible_child_ = 0;
};

class ListBox : public Container {
public:
    ListBox(); ~ListBox() override;
    const char* widget_type() const override { return "ListBox"; }
    SizeRequest get_size_request() const override;
    void size_allocate(const Allocation& a) override;
    void draw(Painter& p) override;
    bool on_event(Event& e) override;
};

class FlowBox : public Container {
public:
    FlowBox(); ~FlowBox() override;
    const char* widget_type() const override { return "FlowBox"; }
    SizeRequest get_size_request() const override;
    void size_allocate(const Allocation& a) override;
    void draw(Painter& p) override;
    bool on_event(Event& e) override;
};

class HeaderBar : public Container {
public:
    HeaderBar(); ~HeaderBar() override;
    const char* widget_type() const override { return "HeaderBar"; }
    SizeRequest get_size_request() const override;
    void size_allocate(const Allocation& a) override;
    void draw(Painter& p) override;
    bool on_event(Event& e) override;
    void set_title(const std::string& t) { title_ = t; }
    void set_subtitle(const std::string& s) { subtitle_ = s; }
private:
    std::string title_, subtitle_;
};

class ActionBar : public Container {
public:
    ActionBar(); ~ActionBar() override;
    const char* widget_type() const override { return "ActionBar"; }
    SizeRequest get_size_request() const override;
    void size_allocate(const Allocation& a) override;
    void draw(Painter& p) override;
    bool on_event(Event& e) override;
};

} // namespace widget
