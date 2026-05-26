/* MPL 2.0 */
//! DOM Bindings — C++ translations of WebIDL DOM interfaces.
//! Original JS: ~16,786 lines across dom/ JS files
//! These provide the JavaScript-accessible DOM API surface.
#pragma once
#include <string>
#include <vector>
#include <memory>
#include <functional>
#include <unordered_map>
#include <variant>
#include <optional>
#include <cstdint>

namespace dom {

// ═══ DOM Exception ═══
class DOMException : public std::runtime_error {
public:
    DOMException(const std::string& msg, const std::string& name = "Error")
        : std::runtime_error(msg), name_(name) {}
    const std::string& name() const { return name_; }
private:
    std::string name_;
};

// ═══ Event ═══
class Event {
public:
    explicit Event(const std::string& type, bool bubbles = false, bool cancelable = false)
        : type_(type), bubbles_(bubbles), cancelable_(cancelable) {}
    virtual ~Event() = default;
    const std::string& type() const { return type_; }
    bool bubbles() const { return bubbles_; }
    bool cancelable() const { return cancelable_; }
    void preventDefault() { default_prevented_ = true; }
    void stopPropagation() { propagation_stopped_ = true; }
    bool defaultPrevented() const { return default_prevented_; }
private:
    std::string type_;
    bool bubbles_, cancelable_, default_prevented_ = false, propagation_stopped_ = false;
};

class CustomEvent : public Event {
public:
    CustomEvent(const std::string& type, const std::string& detail = "")
        : Event(type), detail_(detail) {}
    const std::string& detail() const { return detail_; }
private:
    std::string detail_;
};

class UIEvent : public Event {
public:
    UIEvent(const std::string& type) : Event(type) {}
};

class MouseEvent : public UIEvent {
public:
    MouseEvent(const std::string& type, int x = 0, int y = 0)
        : UIEvent(type), client_x_(x), client_y_(y) {}
    int clientX() const { return client_x_; }
    int clientY() const { return client_y_; }
private:
    int client_x_, client_y_;
};

class KeyboardEvent : public UIEvent {
public:
    KeyboardEvent(const std::string& type, const std::string& key = "")
        : UIEvent(type), key_(key) {}
    const std::string& key() const { return key_; }
private:
    std::string key_;
};

// ═══ EventTarget ═══
using EventListener = std::function<void(Event&)>;

class EventTarget {
public:
    virtual ~EventTarget() = default;
    void addEventListener(const std::string& type, EventListener listener);
    void removeEventListener(const std::string& type);
    bool dispatchEvent(Event& event);
public:
    std::unordered_map<std::string, std::vector<EventListener>> listeners_;
};

// ═══ Node ═══
class Node : public EventTarget {
public:
    enum NodeType : uint16_t {
        ELEMENT_NODE = 1, ATTRIBUTE_NODE = 2, TEXT_NODE = 3,
        CDATA_SECTION_NODE = 4, PROCESSING_INSTRUCTION_NODE = 7,
        COMMENT_NODE = 8, DOCUMENT_NODE = 9, DOCUMENT_TYPE_NODE = 10,
        DOCUMENT_FRAGMENT_NODE = 11
    };
    
    Node(NodeType type = ELEMENT_NODE) : node_type_(type) {}
    virtual ~Node() = default;
    
    NodeType nodeType() const { return node_type_; }
    virtual const std::string& nodeName() const = 0;
    virtual std::string nodeValue() const { return ""; }
    
    Node* parentNode() const { return parent_; }
    Node* firstChild() const { return children_.empty() ? nullptr : children_[0].get(); }
    Node* lastChild() const { return children_.empty() ? nullptr : children_.back().get(); }
    Node* nextSibling() const;
    Node* previousSibling() const;
    
    bool hasChildNodes() const { return !children_.empty(); }
    size_t childElementCount() const;
    
    Node* appendChild(std::unique_ptr<Node> child);
    Node* insertBefore(std::unique_ptr<Node> child, Node* reference);
    Node* removeChild(Node& child);
    Node* replaceChild(std::unique_ptr<Node> new_child, Node& old_child);
    
    Node* cloneNode(bool deep = false) const;
    bool contains(Node* other) const;
    
    std::string textContent() const;
    void setTextContent(const std::string& text);
    
public:
    NodeType node_type_;
    Node* parent_ = nullptr;
    std::vector<std::unique_ptr<Node>> children_;
};

// ═══ CharacterData ═══
class CharacterData : public Node {
public:
    CharacterData(const std::string& data)
        : Node(Node::TEXT_NODE), data_(data) {}
    const std::string& data() const { return data_; }
    void setData(const std::string& d) { data_ = d; }
    size_t length() const { return data_.size(); }
    std::string nodeValue() const override { return data_; }
private:
    std::string data_;
};

class Text : public CharacterData {
public:
    explicit Text(const std::string& data) : CharacterData(data) {}
    const std::string& nodeName() const override { static std::string n = "#text"; return n; }
    std::unique_ptr<Text> splitText(size_t offset);
    std::string wholeText() const;
};

class Comment : public CharacterData {
public:
    explicit Comment(const std::string& data) : CharacterData(data) {}
    const std::string& nodeName() const override { static std::string n = "#comment"; return n; }
};

// ═══ NamedNodeMap / Attr ═══
class Attr {
public:
    Attr(const std::string& name, const std::string& value)
        : name_(name), value_(value) {}
    const std::string& name() const { return name_; }
    const std::string& value() const { return value_; }
    void setValue(const std::string& v) { value_ = v; }
private:
    std::string name_, value_;
};

// ═══ Element ═══
class Element : public Node {
public:
    Element(const std::string& tag_name) : Node(Node::ELEMENT_NODE), tag_name_(tag_name) {}
    
    const std::string& nodeName() const override { return tag_name_; }
    const std::string& tagName() const { return tag_name_; }
    const std::string& localName() const { return tag_name_; }
    
    // Attributes
    std::string getAttribute(const std::string& name) const;
    void setAttribute(const std::string& name, const std::string& value);
    void removeAttribute(const std::string& name);
    bool hasAttribute(const std::string& name) const;
    
    // Class list
    const std::string& className() const { return class_name_; }
    void setClassName(const std::string& name) { class_name_ = name; }
    std::vector<std::string> classList() const;
    
    // ID
    const std::string& id() const { return id_; }
    void setId(const std::string& id) { id_ = id; setAttribute("id", id); }
    
    // Inner/outer HTML
    std::string innerHTML() const;
    void setInnerHTML(const std::string& html);
    std::string outerHTML() const;
    
    // Query
    Element* querySelector(const std::string& selector);
    std::vector<Element*> querySelectorAll(const std::string& selector);
    
    // Style
    std::string getComputedStyle(const std::string& property) const;
    void setStyleProperty(const std::string& name, const std::string& value);
    
    // Children
    Element* firstElementChild() const;
    Element* lastElementChild() const;
    Element* nextElementSibling() const;
    Element* previousElementSibling() const;
    
    // Bounding rect
    struct DOMRect { float x=0,y=0,width=0,height=0,top=0,right=0,bottom=0,left=0; };
    DOMRect getBoundingClientRect() const;
    DOMRect getClientRects() const;
    
    // Scroll
    int scrollTop() const { return scroll_top_; }
    void setScrollTop(int v) { scroll_top_ = v; }
    int scrollLeft() const { return scroll_left_; }
    void setScrollLeft(int v) { scroll_left_ = v; }
    int scrollWidth() const { return 0; }
    int scrollHeight() const { return 0; }
    
public:
    std::string tag_name_, id_, class_name_;
    std::unordered_map<std::string, std::string> attributes_;
    int scroll_top_ = 0, scroll_left_ = 0;
};

class HTMLElement : public Element {
public:
    HTMLElement(const std::string& tag) : Element(tag) {}
    std::string title() const { return getAttribute("title"); }
    void setTitle(const std::string& t) { setAttribute("title", t); }
    std::string lang() const { return getAttribute("lang"); }
    bool hidden() const { return hasAttribute("hidden"); }
    void click() {}
    void focus() {}
    void blur() {}
};

// ═══ HTML elements ═══
class HTMLDivElement : public HTMLElement { public: HTMLDivElement() : HTMLElement("div") {} };
class HTMLSpanElement : public HTMLElement { public: HTMLSpanElement() : HTMLElement("span") {} };
class HTMLParagraphElement : public HTMLElement { public: HTMLParagraphElement() : HTMLElement("p") {} };
class HTMLHeadingElement : public HTMLElement { public: HTMLHeadingElement(const std::string& t) : HTMLElement(t) {} };
class HTMLAnchorElement : public HTMLElement {
public:
    HTMLAnchorElement() : HTMLElement("a") {}
    std::string href() const { return getAttribute("href"); }
    void setHref(const std::string& h) { setAttribute("href", h); }
};
class HTMLImageElement : public HTMLElement {
public:
    HTMLImageElement() : HTMLElement("img") {}
    std::string src() const { return getAttribute("src"); }
    void setSrc(const std::string& s) { setAttribute("src", s); }
    int width() const { return 0; }
    int height() const { return 0; }
};
class HTMLInputElement : public HTMLElement {
public:
    HTMLInputElement() : HTMLElement("input") {}
    std::string type() const { return getAttribute("type"); }
    std::string value() const { return getAttribute("value"); }
    void setValue(const std::string& v) { setAttribute("value", v); }
    bool checked() const { return hasAttribute("checked"); }
};
class HTMLButtonElement : public HTMLElement { public: HTMLButtonElement() : HTMLElement("button") {} };
class HTMLFormElement : public HTMLElement { public: HTMLFormElement() : HTMLElement("form") {} };
class HTMLSelectElement : public HTMLElement { public: HTMLSelectElement() : HTMLElement("select") {} };
class HTMLTextAreaElement : public HTMLElement { public: HTMLTextAreaElement() : HTMLElement("textarea") {} };
class HTMLTableElement : public HTMLElement { public: HTMLTableElement() : HTMLElement("table") {} };
class HTMLUListElement : public HTMLElement { public: HTMLUListElement() : HTMLElement("ul") {} };
class HTMLOListElement : public HTMLElement { public: HTMLOListElement() : HTMLElement("ol") {} };
class HTMLLIElement : public HTMLElement { public: HTMLLIElement() : HTMLElement("li") {} };
class HTMLSectionElement : public HTMLElement { public: HTMLSectionElement() : HTMLElement("section") {} };
class HTMLArticleElement : public HTMLElement { public: HTMLArticleElement() : HTMLElement("article") {} };

// ═══ Document ═══
class Document : public Node {
class DocumentFragment;
public:
    Document() : Node(Node::DOCUMENT_NODE) {}
    const std::string& nodeName() const override { static std::string n = "#document"; return n; }
    
    Element* documentElement() const { return document_element_; }
    Element* head() const;
    Element* body() const;
    void setBody(Element* body);
    
    Element* createElement(const std::string& tag_name);
    Text* createTextNode(const std::string& data);
    Comment* createComment(const std::string& data);
    DocumentFragment* createDocumentFragment();
    Event* createEvent(const std::string& type);
    
    Element* getElementById(const std::string& id);
    std::vector<Element*> getElementsByClassName(const std::string& class_name);
    std::vector<Element*> getElementsByTagName(const std::string& tag_name);
    Element* querySelector(const std::string& selector);
    std::vector<Element*> querySelectorAll(const std::string& selector);
    
    std::string title() const;
    void setTitle(const std::string& title);
    std::string cookie() const { return ""; }
    
private:
    Element* document_element_ = nullptr;
    Element* head_ = nullptr;
    Element* body_ = nullptr;
    std::string title_;
};

class DocumentFragment : public Node {
public:
    DocumentFragment() : Node(Node::DOCUMENT_FRAGMENT_NODE) {}
    const std::string& nodeName() const override { static std::string n = "#document-fragment"; return n; }
};

// ═══ Window ═══
class Window : public EventTarget {
public:
    Window() = default;
    Document* document() const { return document_.get(); }
    void setDocument(std::unique_ptr<Document> doc) { document_ = std::move(doc); }
    
    int innerWidth() const { return 1920; }
    int innerHeight() const { return 1080; }
    int outerWidth() const { return 1920; }
    int outerHeight() const { return 1080; }
    int scrollX() const { return 0; }
    int scrollY() const { return 0; }
    
    void alert(const std::string& msg) const {}
    void close() {}
    
    void requestAnimationFrame(std::function<void(double)> callback);
    int setTimeout(std::function<void()> callback, int ms);
    void clearTimeout(int id);
    int setInterval(std::function<void()> callback, int ms);
    void clearInterval(int id);
    
private:
    std::unique_ptr<Document> document_;
};

// ═══ Console ═══
class Console {
public:
    void log(const std::string& msg) const {}
    void warn(const std::string& msg) const {}
    void error(const std::string& msg) const {}
    void info(const std::string& msg) const {}
    void debug(const std::string& msg) const {}
    void trace() const {}
};

// ═══ Navigator ═══
class Navigator {
public:
    std::string userAgent() const { return "Firefox-CPP/130.0"; }
    std::string platform() const { return "Linux"; }
    std::string language() const { return "en-US"; }
    bool onLine() const { return true; }
    bool cookieEnabled() const { return true; }
};

// ═══ Location ═══
class Location {
public:
    Location(const std::string& url) : href_(url) {}
    std::string href() const { return href_; }
    void setHref(const std::string& url) { href_ = url; }
    std::string protocol() const;
    std::string host() const;
    std::string hostname() const;
    std::string port() const;
    std::string pathname() const;
    std::string search() const;
    std::string hash() const;
    void reload() {}
    void replace(const std::string& url) { href_ = url; }
private:
    std::string href_;
};

// ═══ History ═══
class History {
public:
    int length() const { return 1; }
    void back() {}
    void forward() {}
    void go(int delta = 0) {}
    void pushState(const std::string& data, const std::string& title, const std::string& url) {}
    void replaceState(const std::string& data, const std::string& title, const std::string& url) {}
};

// ═══ Storage ═══
class Storage {
public:
    int length() const { return storage_.size(); }
    std::string key(int index) const;
    std::string getItem(const std::string& key) const;
    void setItem(const std::string& key, const std::string& value);
    void removeItem(const std::string& key);
    void clear() { storage_.clear(); }
private:
    std::unordered_map<std::string, std::string> storage_;
};

// ═══ Global scope helpers ═══
void dom_setTimeout(std::function<void()> callback, int ms);
void dom_setInterval(std::function<void()> callback, int ms);
void dom_requestAnimationFrame(std::function<void(double)> callback);

} // namespace dom
