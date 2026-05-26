/* MPL 2.0 */
#include "widget/widget_base.hpp"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>

namespace widget {

// --- Widget ---
Widget::Widget() = default;
Widget::~Widget() = default;

Container* Widget::to_container() { return dynamic_cast<Container*>(this); }
Window* Widget::to_window() { return dynamic_cast<Window*>(this); }

void Widget::set_parent(Widget* p) { parent_ = p; }

void Widget::add_child(std::unique_ptr<Widget>) {
    std::cerr << "Widget::add_child not supported on " << widget_type() << std::endl;
}

void Widget::remove_child(Widget*) {
    std::cerr << "Widget::remove_child not supported on " << widget_type() << std::endl;
}

void Widget::set_visible(bool v) {
    visible_ = v;
    if (parent_) parent_->queue_draw();
}

SizeRequest Widget::get_size_request() const {
    return {req_w_>0?req_w_:0, req_h_>0?req_h_:0, req_w_>0?req_w_:200, req_h_>0?req_h_:50};
}

void Widget::size_allocate(const Allocation& a) {
    alloc_ = a;
    needs_redraw_ = true;
}

void Widget::realize() {
    realized_ = true;
    for (int i=0; i<(int)child_count(); i++) nth_child(i)->realize();
}

void Widget::map() {
    mapped_ = true;
    visible_ = true;
}

void Widget::unmap() {
    mapped_ = false;
    visible_ = false;
}

void Widget::draw(Painter& p) {
    if (!visible_) return;
    p.set_color(bg_);
    p.fill_rect(alloc_.x, alloc_.y, alloc_.width, alloc_.height);
    needs_redraw_ = false;
}

void Widget::queue_draw() { 
    needs_redraw_ = true;
    if (parent_) parent_->queue_draw();
}

bool Widget::on_event(Event& e) {
    switch (e.type) {
        case EventType::EXPOSE: { queue_draw(); return true; }
        case EventType::FOCUS_IN: has_focus_=true; return true;
        case EventType::FOCUS_OUT: has_focus_=false; return true;
        default: return false;
    }
}

int Widget::connect(const std::string& signal, SignalFunc cb) {
    int id = next_signal_id_++;
    signals_[signal].push_back({id, std::move(cb)});
    return id;
}

void Widget::emit(const std::string& signal) {
    auto it = signals_.find(signal);
    if (it != signals_.end()) {
        for (auto& [id, cb] : it->second) cb(this);
    }
}

void Widget::disconnect(int id) {
    for (auto& [sig, vec] : signals_) {
        vec.erase(std::remove_if(vec.begin(), vec.end(),
            [id](const auto& p){ return p.first==id; }), vec.end());
    }
}

void Widget::set_style(const std::string& key, const std::string& val) { style_[key]=val; }
std::string Widget::get_style(const std::string& key) const {
    auto it=style_.find(key); return it!=style_.end()?it->second:"";
}

void Widget::grab_focus() {
    if (parent_ && parent_->to_window()) {
        has_focus_ = true;
        Event e; e.type = EventType::FOCUS_IN;
        on_event(e);
    }
}

// --- Container ---
Container::Container() = default;
Container::~Container() { children_.clear(); }

void Container::add_child(std::unique_ptr<Widget> child) {
    child->set_parent(this);
    children_.push_back(std::move(child));
    queue_draw();
}

void Container::remove_child(Widget* child) {
    auto it = std::find_if(children_.begin(), children_.end(),
        [child](const auto& p){ return p.get()==child; });
    if (it != children_.end()) {
        (*it)->set_parent(nullptr);
        children_.erase(it);
        queue_draw();
    }
}

void Container::for_each_child(std::function<void(Widget*)> fn) {
    for (auto& c : children_) fn(c.get());
}

Widget* Container::find_child(const std::string& name) {
    for (auto& c : children_) {
        if (c->name()==name) return c.get();
        if (auto* cont = c->to_container()) {
            if (auto* found = cont->find_child(name)) return found;
        }
    }
    return nullptr;
}

// --- Window ---
Window::Window() { set_name("window"); }
Window::~Window() = default;

void Window::present() {
    map();
    Application::instance().add_window(this);
    Application::instance().set_active_window(this);
    realize();
    queue_draw();
}

void Window::close() {
    emit("delete-event");
    Application::instance().remove_window(this);
}

void Window::maximize() { maximized_ = true; queue_draw(); }
void Window::unmaximize() { maximized_ = false; queue_draw(); }
void Window::minimize() { visible_ = false; }
void Window::fullscreen() { fullscreen_ = true; queue_draw(); }
void Window::unfullscreen() { fullscreen_ = false; queue_draw(); }

// --- Application ---
Application& Application::instance() {
    static Application app;
    return app;
}

int Application::run(int argc, char** argv) {
    running_ = true;
    if (!windows_.empty()) {
        active_window_ = windows_[0];
        active_window_->present();
    }
    process_events();
    return 0;
}

void Application::quit() { running_ = false; }

void Application::add_window(Window* w) {
    if (std::find(windows_.begin(),windows_.end(),w)==windows_.end())
        windows_.push_back(w);
}

void Application::remove_window(Window* w) {
    windows_.erase(std::remove(windows_.begin(),windows_.end(),w),windows_.end());
    if (active_window_==w) active_window_=windows_.empty()?nullptr:windows_[0];
    if (windows_.empty()) quit();
}

void Application::process_events() {}
bool Application::events_pending() const { return false; }

} // namespace widget
