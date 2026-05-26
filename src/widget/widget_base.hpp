/* MPL 2.0 - C++ Widget Toolkit */
#pragma once
#include <string>
#include <vector>
#include <memory>
#include <functional>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cassert>

namespace widget {

// Forward declarations
class Widget;
class Container;
class Window;
class Application;
class Painter;
class Event;
class SizeRequest;

// ============================================================
// Geometry types
// ============================================================
struct Point { int x = 0, y = 0; };
struct Size { int width = 0, height = 0; };
struct Rect { int x = 0, y = 0, width = 0, height = 0;
    bool contains(Point p) const { return p.x>=x && p.x<x+width && p.y>=y && p.y<y+height; }
    Rect intersect(const Rect& o) const {
        int nx=std::max(x,o.x), ny=std::max(y,o.y);
        return {nx,ny,std::max(0,std::min(x+width,o.x+o.width)-nx),std::max(0,std::min(y+height,o.y+o.height)-ny)};
    }
    bool empty() const { return width<=0 || height<=0; }
    int right() const { return x+width; }
    int bottom() const { return y+height; }
};

struct Color { uint8_t r=0,g=0,b=0,a=255;
    static Color rgb(uint8_t r,uint8_t g,uint8_t b) { return {r,g,b,255}; }
    static Color rgba(uint8_t r,uint8_t g,uint8_t b,uint8_t a) { return {r,g,b,a}; }
    uint32_t to_rgba32() const { return ((uint32_t)r) | ((uint32_t)g<<8) | ((uint32_t)b<<16) | ((uint32_t)a<<24); }
    Color blend(const Color& o, float t) const {
        return {uint8_t(r+(o.r-r)*t),uint8_t(g+(o.g-g)*t),uint8_t(b+(o.b-b)*t),uint8_t(a+(o.a-a)*t)};
    }
};

// ============================================================
// Event types
// ============================================================
enum class EventType : uint32_t {
    NONE=0, KEY_PRESS, KEY_RELEASE, MOUSE_MOVE, MOUSE_DOWN, MOUSE_UP,
    MOUSE_WHEEL, MOUSE_ENTER, MOUSE_LEAVE, FOCUS_IN, FOCUS_OUT,
    RESIZE, EXPOSE, DELETE_EVENT, DESTROY, SCROLL,
    DRAG_ENTER, DRAG_LEAVE, DRAG_MOTION, DROP,
    CLIPBOARD_PASTE, CLIPBOARD_COPY,
    COUNT
};

enum class Modifier : uint32_t { NONE=0, SHIFT=1, CTRL=2, ALT=4, META=8 };

class Event {
public:
    EventType type = EventType::NONE;
    uint32_t modifiers = 0;
    Point mouse_pos;
    int mouse_button = 0;
    int key_code = 0;
    uint32_t key_char = 0;
    int scroll_dx = 0, scroll_dy = 0;
    int width = 0, height = 0;
    void* user_data = nullptr;
    bool accepted = false;

    bool shift() const { return modifiers & (uint32_t)Modifier::SHIFT; }
    bool ctrl() const { return modifiers & (uint32_t)Modifier::CTRL; }
    bool alt() const { return modifiers & (uint32_t)Modifier::ALT; }
    bool meta() const { return modifiers & (uint32_t)Modifier::META; }
};

// ============================================================
// Size request / allocation
// ============================================================
struct SizeRequest {
    int min_width=0, min_height=0;
    int natural_width=0, natural_height=0;
    bool expand_h=false, expand_v=false;
    bool fill_h=true, fill_v=true;
};

struct Allocation {
    int x=0, y=0, width=0, height=0;
    Rect to_rect() const { return {x,y,width,height}; }
};

// ============================================================
// Base Widget
// ============================================================
class Widget {
public:
    Widget();
    virtual ~Widget();

    // Hierarchy
    Widget* parent() const { return parent_; }
    Container* to_container();
    Window* to_window();

    virtual void set_parent(Widget* p);
    virtual void add_child(std::unique_ptr<Widget> child);
    virtual void remove_child(Widget* child);
    size_t child_count() const { return 0; } // overridden in Container
    Widget* nth_child(size_t n) const { return nullptr; }

    // Properties
    virtual const char* widget_type() const { return "Widget"; }
    void set_name(const std::string& n) { name_ = n; }
    const std::string& name() const { return name_; }
    void set_visible(bool v);
    bool visible() const { return visible_; }
    void set_sensitive(bool s) { sensitive_ = s; }
    bool sensitive() const { return sensitive_; }
    void set_tooltip(const std::string& t) { tooltip_ = t; }
    const std::string& tooltip() const { return tooltip_; }

    // Sizing
    virtual SizeRequest get_size_request() const;
    void set_size_request(int w, int h) { req_w_=w; req_h_=h; }
    int width() const { return alloc_.width; }
    int height() const { return alloc_.height; }
    const Allocation& allocation() const { return alloc_; }
    Rect bounds() const { return alloc_.to_rect(); }

    // Layout
    virtual void size_allocate(const Allocation& a);
    virtual void realize();
    virtual void map();
    virtual void unmap();

    // Drawing
    virtual void draw(Painter& p);
    virtual void queue_draw();
    bool needs_redraw() const { return needs_redraw_; }
    void set_needs_redraw(bool v) { needs_redraw_=v; }

    // Events
    virtual bool on_event(Event& e);
    void add_events(int mask) { event_mask_|=mask; }
    void set_events(int mask) { event_mask_=mask; }
    int event_mask() const { return event_mask_; }

    // Signals
    using SignalFunc = std::function<void(Widget*)>;
    int connect(const std::string& signal, SignalFunc cb);
    void emit(const std::string& signal);
    void disconnect(int id);

    // Style
    void set_style(const std::string& key, const std::string& val);
    std::string get_style(const std::string& key) const;
    void set_fg_color(const Color& c) { fg_=c; }
    void set_bg_color(const Color& c) { bg_=c; }
    Color fg_color() const { return fg_; }
    Color bg_color() const { return bg_; }
    void set_font_desc(const std::string& fd) { font_desc_=fd; }
    const std::string& font_desc() const { return font_desc_; }

    // State
    bool has_focus() const { return has_focus_; }
    void grab_focus();
    bool is_mapped() const { return mapped_; }
    bool is_realized() const { return realized_; }

protected:
    Widget* parent_ = nullptr;
    std::string name_;
    bool visible_ = true;
    bool sensitive_ = true;
    bool has_focus_ = false;
    bool mapped_ = false;
    bool realized_ = false;
    bool needs_redraw_ = true;
    int req_w_ = -1, req_h_ = -1;
    int event_mask_ = 0;
    Allocation alloc_;
    std::string tooltip_;
    Color fg_{0,0,0,255}, bg_{255,255,255,255};
    std::string font_desc_;
    std::unordered_map<std::string, std::string> style_;
    std::unordered_map<std::string, std::vector<std::pair<int,SignalFunc>>> signals_;
    int next_signal_id_ = 1;
};

// ============================================================
// Container
// ============================================================
class Container : public Widget {
public:
    Container();
    ~Container() override;

    const char* widget_type() const override { return "Container"; }
    void add_child(std::unique_ptr<Widget> child) override;
    void remove_child(Widget* child) override;
    size_t child_count() const { return children_.size(); }
    Widget* nth_child(size_t n) const { return n<children_.size()?children_[n].get():nullptr; }

    using Iterator = std::vector<std::unique_ptr<Widget>>::iterator;
    Iterator begin() { return children_.begin(); }
    Iterator end() { return children_.end(); }
    void for_each_child(std::function<void(Widget*)> fn);
    Widget* find_child(const std::string& name);

    void set_border_width(int w) { border_w_=w; }
    int border_width() const { return border_w_; }
    void set_spacing(int s) { spacing_=s; }
    int spacing() const { return spacing_; }

protected:
    std::vector<std::unique_ptr<Widget>> children_;
    int border_w_ = 0;
    int spacing_ = 0;
};

// ============================================================
// Painter (abstract drawing context)
// ============================================================
class Painter {
public:
    virtual ~Painter() = default;
    virtual void set_color(const Color& c) = 0;
    virtual void set_line_width(double w) = 0;
    virtual void fill_rect(int x,int y,int w,int h) = 0;
    virtual void draw_rect(int x,int y,int w,int h) = 0;
    virtual void fill_rounded_rect(int x,int y,int w,int h,double r) = 0;
    virtual void draw_text(int x,int y,const std::string& text) = 0;
    virtual void draw_line(int x1,int y1,int x2,int y2) = 0;
    virtual void draw_arc(int cx,int cy,double r,double start,double end) = 0;
    virtual void draw_polygon(const Point* pts, int n) = 0;
    virtual void set_clip(const Rect& r) = 0;
    virtual void reset_clip() = 0;
    virtual void translate(double dx, double dy) = 0;
    virtual void save() = 0;
    virtual void restore() = 0;
    virtual Size text_extent(const std::string& text) = 0;
    virtual void draw_pixbuf(int x,int y,int w,int h,const uint8_t* data) = 0;
    // Advanced
    virtual void fill_gradient(int x,int y,int w,int h,const Color& c1,const Color& c2,bool vert=true) = 0;
    virtual void set_antialias(bool on) = 0;
    virtual void set_opacity(double o) = 0;
};

// ============================================================
// Application
// ============================================================
class Application {
public:
    static Application& instance();
    int run(int argc, char** argv);
    void quit();
    Window* active_window() const { return active_window_; }
    void set_active_window(Window* w) { active_window_=w; }
    void add_window(Window* w);
    void remove_window(Window* w);
    size_t window_count() const { return windows_.size(); }
    void process_events();
    bool events_pending() const;
    void set_app_name(const std::string& n) { app_name_=n; }
    const std::string& app_name() const { return app_name_; }

private:
    Application() = default;
    Window* active_window_ = nullptr;
    std::vector<Window*> windows_;
    std::string app_name_;
    bool running_ = false;
};

// ============================================================
// Window
// ============================================================
class Window : public Container {
public:
    Window();
    ~Window() override;

    const char* widget_type() const override { return "Window"; }
    void set_title(const std::string& t) { title_=t; }
    const std::string& title() const { return title_; }
    void set_default_size(int w,int h) { def_w_=w; def_h_=h; }
    void set_resizable(bool r) { resizable_=r; }
    void set_decorated(bool d) { decorated_=d; }
    void present();
    void close();
    void maximize();
    void unmaximize();
    void minimize();
    void fullscreen();
    void unfullscreen();
    bool is_maximized() const { return maximized_; }
    bool is_fullscreen() const { return fullscreen_; }
    void set_icon_name(const std::string& n) { icon_name_=n; }

protected:
    std::string title_;
    int def_w_=800, def_h_=600;
    bool resizable_=true, decorated_=true;
    bool maximized_=false, fullscreen_=false;
    std::string icon_name_;
};

} // namespace widget
