/* MPL 2.0 - Iceweasel C++ */
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cmath>

class Canvas {
    int w_,h_; uint32_t* px_;
    Display*dpy_=nullptr; Window win_; GC gc_; XImage*img_=nullptr; bool x11_=false;
    XFontStruct*font_=nullptr;
public:
    Canvas(int w,int h):w_(w),h_(h){px_=new uint32_t[w*h];memset(px_,0x2B,w*h*4);
        dpy_=XOpenDisplay(nullptr);
        if(dpy_){
            x11_=true; int s=DefaultScreen(dpy_);
            win_=XCreateSimpleWindow(dpy_,RootWindow(dpy_,s),0,0,w,h,1,0x1C1B22,0x1C1B22);
            XStoreName(dpy_,win_,"Iceweasel C++");
            XSelectInput(dpy_,win_,ExposureMask|KeyPressMask|KeyReleaseMask|ButtonPressMask|ButtonReleaseMask|PointerMotionMask|StructureNotifyMask);
            XMapWindow(dpy_,win_); gc_=XCreateGC(dpy_,win_,0,nullptr);
            img_=XCreateImage(dpy_,DefaultVisual(dpy_,s),24,ZPixmap,0,(char*)px_,w,h,32,w*4);
            const char* fonts[]={"-*-fixed-medium-r-*-*-14-*-*-*-*-*-*-*","fixed","-*-helvetica-*-r-*-*-12-*-*-*-*-*-*-*","6x13",nullptr};
            for(int i=0;fonts[i];i++){font_=XLoadQueryFont(dpy_,fonts[i]);if(font_){XSetFont(dpy_,gc_,font_->fid);break;}}
            if(!font_)fprintf(stderr,"WARNING: no X11 font found, text won't render\n");
        }
    }
    ~Canvas(){if(img_)XDestroyImage(img_);if(font_)XFreeFont(dpy_,font_);if(gc_)XFreeGC(dpy_,gc_);if(dpy_)XCloseDisplay(dpy_);delete[]px_;}
    int W()const{return w_;} int H()const{return h_;} bool x11()const{return x11_;}
    Display*dpy(){return dpy_;} Window win(){return win_;} bool has_font()const{return font_!=nullptr;}
    void pset(int x,int y,uint8_t r,uint8_t g,uint8_t b){if(x<0||x>=w_||y<0||y>=h_)return;px_[y*w_+x]=0xFF000000|(r<<16)|(g<<8)|b;}
    void fill(int x,int y,int rw,int rh,uint8_t r,uint8_t g,uint8_t b){
        if(x<0){rw+=x;x=0;}if(y<0){rh+=y;y=0;}if(x+rw>w_)rw=w_-x;if(y+rh>h_)rh=h_-y;if(rw<=0||rh<=0)return;
        uint32_t c=0xFF000000|(r<<16)|(g<<8)|b;
        for(int dy=0;dy<rh;dy++){auto*row=px_+(y+dy)*w_+x;for(int dx=0;dx<rw;dx++)row[dx]=c;}}
    void rect(int x,int y,int rw,int rh,uint8_t r,uint8_t g,uint8_t b){fill(x,y,rw,1,r,g,b);fill(x,y+rh-1,rw,1,r,g,b);fill(x,y,1,rh,r,g,b);fill(x+rw-1,y,1,rh,r,g,b);}
    void rrect(int x,int y,int rw,int rh,int rad,uint8_t r,uint8_t g,uint8_t b){
        fill(x+rad,y,rw-2*rad,rh,r,g,b);fill(x,y+rad,rw,rh-2*rad,r,g,b);
        for(int dy=-rad;dy<=rad;dy++){int dx=(int)sqrt(std::max(0,rad*rad-dy*dy));
            for(int px=-dx;px<=dx;px++){pset(x+rad+px,y+rad+dy,r,g,b);pset(x+rw-1-rad+px,y+rad+dy,r,g,b);
                pset(x+rad+px,y+rh-1-rad+dy,r,g,b);pset(x+rw-1-rad+px,y+rh-1-rad+dy,r,g,b);}}}
    void rtop(int x,int y,int rw,int rh,int rad,uint8_t r,uint8_t g,uint8_t b){
        fill(x,y+rad,rw,rh-rad,r,g,b);
        for(int dy=-rad;dy<=0;dy++){int dx=(int)sqrt(std::max(0,rad*rad-dy*dy));
            for(int px=-dx;px<=dx;px++){pset(x+rad+px,y+rad+dy,r,g,b);pset(x+rw-1-rad+px,y+rad+dy,r,g,b);}}}
    void xtext(int x,int y,const std::string&s,uint8_t r=255,uint8_t g=255,uint8_t b=255){
        if(!x11_||!font_){draw_text(x,y,s,r,g,b);return;}
        XSetForeground(dpy_,gc_,(r<<16)|(g<<8)|b);
        XDrawString(dpy_,win_,gc_,x,y+font_->ascent,s.c_str(),s.size());}
    void draw_text(int x,int y,const std::string&s,uint8_t r=255,uint8_t g=255,uint8_t b=255){
        for(size_t i=0;i<s.size();i++){char c=s[i];if(c<32||c>126)c='?';dchar(x+i*7,y,c,r,g,b);}}
    void dchar(int cx,int cy,char c,uint8_t r,uint8_t g,uint8_t b){
        static const uint8_t F[95][7]={
            {0},{0x20,0x20,0x20,0x20,0x20,0,0x20},{0x50,0x50,0x50},{0x50,0x50,0xf8,0x50,0xf8,0x50,0x50},
            {0x20,0x78,0xa0,0x70,0x28,0xf0,0x20},{0xc0,0xc8,0x10,0x20,0x40,0x98,0x18},{0x40,0xa0,0xa0,0x40,0xa8,0x90,0x68},
            {0x30,0x30,0x20,0x40},{0x10,0x20,0x40,0x40,0x40,0x20,0x10},{0x40,0x20,0x10,0x10,0x10,0x20,0x40},
            {0x20,0xa8,0x70,0xf8,0x70,0xa8,0x20},{0,0x20,0x20,0xf8,0x20,0x20},{0,0,0,0,0x30,0x30,0x20},
            {0,0,0xf8},{0,0,0,0,0,0x30,0x30},{0,0x08,0x10,0x20,0x40,0x80},
            {0x70,0x88,0x98,0xa8,0xc8,0x88,0x70},{0x20,0x60,0x20,0x20,0x20,0x20,0x70},{0x70,0x88,0x08,0x10,0x20,0x40,0xf8},
            {0xf8,0x08,0x10,0x30,0x08,0x88,0x70},{0x10,0x30,0x50,0x90,0xf8,0x10,0x10},{0xf8,0x80,0xf0,0x08,0x08,0x88,0x70},
            {0x30,0x40,0x80,0xf0,0x88,0x88,0x70},{0xf8,0x08,0x10,0x20,0x40,0x40,0x40},{0x70,0x88,0x88,0x70,0x88,0x88,0x70},
            {0x70,0x88,0x88,0x78,0x08,0x10,0x60},{0,0x30,0x30,0,0x30,0x30},{0,0x30,0x30,0,0x30,0x30,0x20},
            {0x08,0x10,0x20,0x40,0x20,0x10,0x08},{0,0,0xf8,0,0xf8},{0x40,0x20,0x10,0x08,0x10,0x20,0x40},
            {0x70,0x88,0x08,0x10,0x20,0,0x20},{0x70,0x88,0xb8,0xa8,0xb8,0x80,0x70},
            {0x20,0x50,0x88,0x88,0xf8,0x88,0x88},{0xf0,0x88,0x88,0xf0,0x88,0x88,0xf0},{0x70,0x88,0x80,0x80,0x80,0x88,0x70},
            {0xe0,0x90,0x88,0x88,0x88,0x90,0xe0},{0xf8,0x80,0x80,0xf0,0x80,0x80,0xf8},{0xf8,0x80,0x80,0xf0,0x80,0x80,0x80},
            {0x70,0x88,0x80,0xb8,0x88,0x88,0x78},{0x88,0x88,0x88,0xf8,0x88,0x88,0x88},{0x70,0x20,0x20,0x20,0x20,0x20,0x70},
            {0x38,0x10,0x10,0x10,0x10,0x90,0x60},{0x88,0x90,0xa0,0xc0,0xa0,0x90,0x88},{0x80,0x80,0x80,0x80,0x80,0x80,0xf8},
            {0x88,0xd8,0xa8,0xa8,0x88,0x88,0x88},{0x88,0xc8,0xa8,0x98,0x88,0x88,0x88},{0x70,0x88,0x88,0x88,0x88,0x88,0x70},
            {0xf0,0x88,0x88,0xf0,0x80,0x80,0x80},{0x70,0x88,0x88,0x88,0xa8,0x90,0x68},{0xf0,0x88,0x88,0xf0,0xa0,0x90,0x88},
            {0x78,0x80,0x80,0x70,0x08,0x08,0xf0},{0xf8,0x20,0x20,0x20,0x20,0x20,0x20},{0x88,0x88,0x88,0x88,0x88,0x88,0x70},
            {0x88,0x88,0x88,0x88,0x50,0x50,0x20},{0x88,0x88,0x88,0xa8,0xa8,0xa8,0x50},{0x88,0x88,0x50,0x20,0x50,0x88,0x88},
            {0x88,0x88,0x50,0x20,0x20,0x20,0x20},{0xf8,0x08,0x10,0x20,0x40,0x80,0xf8},
            {0x78,0x40,0x40,0x40,0x40,0x40,0x78},{0,0x80,0x40,0x20,0x10,0x08},{0x78,0x08,0x08,0x08,0x08,0x08,0x78},
            {0x20,0x50,0x88},{0,0,0,0,0,0,0xf8},
        };
        int idx=c-32;if(idx<0)idx=0;if(idx>=95)idx=94;
        for(int row=0;row<7;row++){uint8_t b=F[idx][row];for(int col=0;col<5;col++)if(b&(0x80>>col))pset(cx+col,cy+row,r,g,b);}
    }
    void flush(){if(x11_){XPutImage(dpy_,win_,gc_,img_,0,0,0,0,w_,h_);if(font_){/*force text to render on top*/}XFlush(dpy_);}}
    void save_bmp(const std::string&fn){
        std::ofstream f(fn,std::ios::binary);if(!f)return;
        int rs=((w_*3+3)/4)*4,is=rs*h_;
        auto w16=[&](uint16_t v){f.put(v&0xFF);f.put(v>>8);};
        auto w32=[&](uint32_t v){w16(v&0xFFFF);w16(v>>16);};
        f.put('B');f.put('M');w32(54+is);w32(0);w32(54);w32(40);w32(w_);w32(h_);
        w16(1);w16(24);w32(0);w32(is);w32(2835);w32(2835);w32(0);w32(0);
        for(int y=h_-1;y>=0;y--){for(int x=0;x<w_;x++){uint32_t p=px_[y*w_+x];f.put(p&0xFF);f.put((p>>8)&0xFF);f.put((p>>16)&0xFF);}for(int p=w_*3;p<rs;p++)f.put(0);}
    }
};

namespace C {
    const uint8_t TITLE[3]={28,27,34}, TOOLBAR[3]={43,42,51}, TAB_ACTIVE[3]={66,65,77};
    const uint8_t TAB_BG[3]={43,42,51}, ADDR_BG[3]={57,56,63}, ADDR_FOCUS[3]={0,221,255};
    const uint8_t BTN[3]={43,42,51}, BTN_HOVER[3]={82,82,94}, ORANGE[3]={255,149,0};
    const uint8_t ACCENT[3]={0,96,223}, ICON[3]={191,191,201}, TEXT[3]={251,251,254};
    const uint8_t TEXT2[3]={191,191,201}, CARD[3]={66,66,77}, GREEN[3]={46,198,109};
}

struct Tab { std::string title,url,content; bool loading=false; };

class Iceweasel {
    Canvas c;
    bool quit=false;
    std::vector<Tab> tabs;
    int active=0;
    std::string addr="";
    bool addr_focused=false;
    int mx=0,my=0;

public:
    Iceweasel():c(1280,800){
        tabs.push_back({"Getting Started","about:home",""});
        tabs.push_back({"GitHub","https://github.com",""});
        tabs.push_back({"Wikipedia","https://wikipedia.org",""});
    }

    struct Hit { int tab_idx; bool close_btn; bool is_quit; bool is_addr; bool is_newtab; bool is_reload; bool is_home; bool is_search; };
    Hit hit(int x,int y){
        Hit h={-1,false,false,false,false,false,false,false};
        if(x>=c.W()-46&&x<c.W()-22&&y>=8&&y<22)h.is_quit=true;
        if(x>=74&&x<104&&y>=36&&y<66)h.is_reload=true;
        if(x>=108&&x<138&&y>=36&&y<66)h.is_home=true;
        if(x>=152&&x<c.W()-152&&y>=35&&y<67)h.is_addr=true;
        if(x>=c.W()/2-280&&x<c.W()/2+280&&y>=280&&y<324)h.is_search=true;
        int ntx=(int)tabs.size()*200+8;
        if(x>=ntx&&x<ntx+22&&y>=78&&y<100)h.is_newtab=true;
        for(int i=0;i<(int)tabs.size();i++){
            int tx=i*200;
            if(x>=tx&&x<tx+200&&y>=72&&y<106){
                h.tab_idx=i;
                if(x>=tx+174&&x<tx+190&&y>=80&&y<96)h.close_btn=true;
            }
        }
        return h;
    }

    void run(){
        if(!c.x11()){render();c.save_bmp("/tmp/iceweasel_cpp.bmp");std::cout<<"No X11. BMP saved.\n";return;}
        render(); overlay(); c.flush();
        while(!quit){
            while(XPending(c.dpy())){
                XEvent ev; XNextEvent(c.dpy(),&ev);
                if(ev.type==Expose){render();overlay();c.flush();continue;}
                if(ev.type==KeyPress){
                    char buf[32]={}; KeySym ks=0;
                    XLookupString(&ev.xkey,buf,sizeof(buf),&ks,nullptr);
                    int mod=ev.xkey.state;
                    if(ks==XK_Escape) quit=true;
                    else if(ks==XK_Return){if(addr_focused&&!addr.empty()){navigate(addr);addr="";addr_focused=false;}}
                    else if(ks==XK_BackSpace){if(addr_focused&&!addr.empty())addr.pop_back();}
                    else if((ks==XK_T||ks==XK_t)&&(mod&ControlMask)){tabs.push_back({"New Tab","about:home",""});active=tabs.size()-1;addr_focused=false;}
                    else if((ks==XK_W||ks==XK_w)&&(mod&ControlMask)) close_current_tab();
                    else if((ks==XK_L||ks==XK_l)&&(mod&ControlMask)){addr_focused=true;addr="";}
                    else if((ks==XK_R||ks==XK_r)&&(mod&ControlMask)) reload();
                    else if(ks==XK_Tab){active=(active+1)%tabs.size();addr_focused=false;}
                    else if(addr_focused&&buf[0]>=32&&buf[0]<127) addr+=buf[0];
                    render(); overlay(); c.flush();
                }
                if(ev.type==ButtonPress){
                    mx=ev.xbutton.x; my=ev.xbutton.y;
                    auto h=hit(mx,my);
                    if(h.is_quit) quit=true;
                    else if(h.is_reload) reload();
                    else if(h.is_home){active=0;addr_focused=false;}
                    else if(h.is_addr){addr_focused=true;addr="";}
                    else if(h.is_newtab||h.is_search){tabs.push_back({"New Tab","about:home",""});active=tabs.size()-1;addr_focused=true;addr="";}
                    else if(h.tab_idx>=0){
                        if(h.close_btn){
                            // Close specific tab
                            if(tabs.size()<=1) quit=true;
                            else {
                                tabs.erase(tabs.begin()+h.tab_idx);
                                if(active>=(int)tabs.size()) active=tabs.size()-1;
                            }
                        } else {
                            active=h.tab_idx;
                            addr_focused=false;
                        }
                    }
                    render(); overlay(); c.flush();
                }
                if(ev.type==MotionNotify){mx=ev.xmotion.x;my=ev.xmotion.y;}
            }
            usleep(16000);
        }
    }

    void close_current_tab(){
        if(tabs.size()<=1) quit=true;
        else {tabs.erase(tabs.begin()+active); if(active>=(int)tabs.size()) active=tabs.size()-1;}
    }

    void reload(){if(!tabs[active].url.empty()&&tabs[active].url!="about:home")navigate(tabs[active].url);}

    void navigate(const std::string& url){
        std::string u=url; if(u.empty())return;
        if(u.find("://")==std::string::npos&&u!="about:home") u="https://"+u;
        tabs[active].url=u; tabs[active].loading=true;
        tabs[active].title=u.substr(u.find("://")+3,30);
        render(); overlay(); c.flush();
        std::string body=http_get(u);
        tabs[active].content=body;
        size_t ts=body.find("<title>");if(ts!=std::string::npos){ts+=7;size_t te=body.find("</title>",ts);if(te!=std::string::npos)tabs[active].title=body.substr(ts,te-ts);}
        tabs[active].loading=false;
    }

    std::string http_get(const std::string&url){
        std::string host,path="/";
        size_t ps=url.find("://");std::string rest=(ps!=std::string::npos)?url.substr(ps+3):url;
        size_t sl=rest.find('/');if(sl!=std::string::npos){host=rest.substr(0,sl);path=rest.substr(sl);}else host=rest;
        int port=80;size_t cl=host.find(':');if(cl!=std::string::npos){try{port=std::stoi(host.substr(cl+1));}catch(...){port=80;}host=host.substr(0,cl);}
        int sock=socket(AF_INET,SOCK_STREAM,0);if(sock<0)return"";
        struct timeval tv={3,0};setsockopt(sock,SOL_SOCKET,SO_RCVTIMEO,&tv,sizeof(tv));
        struct hostent*he=gethostbyname(host.c_str());if(!he){close(sock);return"";}
        struct sockaddr_in a={};a.sin_family=AF_INET;a.sin_port=htons(port);memcpy(&a.sin_addr,he->h_addr_list[0],he->h_length);
        if(connect(sock,(struct sockaddr*)&a,sizeof(a))<0){close(sock);return"";}
        std::string req="GET "+path+" HTTP/1.1\r\nHost: "+host+"\r\nUser-Agent: Iceweasel/130.0\r\nAccept: text/html\r\nConnection: close\r\n\r\n";
        send(sock,req.c_str(),req.size(),0);
        std::string r;char b[8192];int n;while((n=recv(sock,b,sizeof(b)-1,0))>0){b[n]=0;r+=b;}close(sock);
        size_t heof=r.find("\r\n\r\n");return(heof!=std::string::npos)?r.substr(heof+4):r;
    }

    void render(){
        int W=c.W(),H=c.H();
        c.fill(0,0,W,H,C::TITLE[0],C::TITLE[1],C::TITLE[2]);
        c.fill(0,0,W,30,C::TITLE[0],C::TITLE[1],C::TITLE[2]);
        // Close btn
        c.fill(W-46,8,24,14,C::BTN[0],C::BTN[1],C::BTN[2]);
        c.fill(W-86,8,24,14,C::BTN[0],C::BTN[1],C::BTN[2]);
        c.fill(W-126,8,24,14,C::BTN[0],C::BTN[1],C::BTN[2]);
        // Toolbar
        int ty=30,th=42;
        c.fill(0,ty,W,th,C::TOOLBAR[0],C::TOOLBAR[1],C::TOOLBAR[2]);
        c.rrect(6,ty+6,30,30,15,C::BTN[0],C::BTN[1],C::BTN[2]);
        c.rrect(40,ty+6,30,30,15,C::BTN[0],C::BTN[1],C::BTN[2]);
        c.rrect(74,ty+6,30,30,15,C::BTN[0],C::BTN[1],C::BTN[2]);
        c.rrect(108,ty+6,30,30,15,C::BTN[0],C::BTN[1],C::BTN[2]);
        // Address bar
        int ax=152,ay=ty+5,aw=W-304,ah=32;
        if(addr_focused)c.rrect(ax-1,ay-1,aw+2,ah+2,21,C::ADDR_FOCUS[0],C::ADDR_FOCUS[1],C::ADDR_FOCUS[2]);
        c.rrect(ax,ay,aw,ah,20,C::ADDR_BG[0],C::ADDR_BG[1],C::ADDR_BG[2]);
        if(!tabs[active].url.empty()&&tabs[active].url.find("https")==0)c.fill(ax+10,ay+8,16,16,C::GREEN[0],C::GREEN[1],C::GREEN[2]);
        else c.fill(ax+10,ay+8,16,16,C::ICON[0],C::ICON[1],C::ICON[2]);
        // Right toolbar
        c.rrect(W-140,ty+6,30,30,15,C::BTN[0],C::BTN[1],C::BTN[2]);
        c.rrect(W-104,ty+6,30,30,15,C::BTN[0],C::BTN[1],C::BTN[2]);
        c.rrect(W-68,ty+6,30,30,15,C::BTN[0],C::BTN[1],C::BTN[2]);
        // Tab bar
        int tby=72,tabh=34;
        c.fill(0,tby,W,tabh,C::TAB_BG[0],C::TAB_BG[1],C::TAB_BG[2]);
        for(int i=0;i<(int)tabs.size();i++){
            int tx=i*200;
            const uint8_t*bg=(i==active)?C::TAB_ACTIVE:C::TAB_BG;
            if(i==active){c.rtop(tx,tby,200,tabh+2,8,bg[0],bg[1],bg[2]);c.fill(tx+4,tby+1,192,2,C::ACCENT[0],C::ACCENT[1],C::ACCENT[2]);}
            else{c.fill(tx,tby,200,tabh,bg[0],bg[1],bg[2]);if(i!=active+1)c.fill(tx,tby+8,1,tabh-16,C::ICON[0],C::ICON[1],C::ICON[2]);}
            c.rrect(tx+174,tby+8,16,16,8,C::BTN[0],C::BTN[1],C::BTN[2]);
        }
        int ntx=(int)tabs.size()*200+8;
        c.rrect(ntx,tby+6,22,22,11,C::BTN[0],C::BTN[1],C::BTN[2]);
        // Bookmark bar
        int bby=tby+tabh,bbh=28;
        c.fill(0,bby,W,bbh,C::TOOLBAR[0],C::TOOLBAR[1],C::TOOLBAR[2]);
        c.fill(0,bby,W,1,C::ICON[0],C::ICON[1],C::ICON[2]);
        // Content
        int cy=bby+bbh,ch=H-cy-24;
        c.fill(0,cy,W,ch,C::TOOLBAR[0],C::TOOLBAR[1],C::TOOLBAR[2]);
        if(tabs[active].url=="about:home"||tabs[active].url=="about:blank"){
            int cx=W/2;
            for(int dy=-40;dy<=40;dy++){int dx=(int)sqrt(1600-dy*dy);for(int px=-dx;px<=dx;px++)c.pset(cx+px,cy+100+dy,C::ORANGE[0],C::ORANGE[1],C::ORANGE[2]);}
            c.rrect(cx-280,cy+180,560,44,22,C::ADDR_BG[0],C::ADDR_BG[1],C::ADDR_BG[2]);
            std::vector<std::string> sites={"Google","YouTube","GitHub","Wikipedia","Reddit","Amazon","Stack Overflow","Twitter"};
            for(int i=0;i<(int)sites.size();i++){
                int sx=cx-380+(i%4)*200,scy=cy+250+(i/4)*90;
                c.rrect(sx,scy,180,72,8,C::CARD[0],C::CARD[1],C::CARD[2]);
                c.fill(sx+14,scy+14,28,28,C::ORANGE[0],C::ORANGE[1],C::ORANGE[2]);
            }
        }
        // Status bar
        int sby=H-24;
        c.fill(0,sby,W,24,C::TITLE[0],C::TITLE[1],C::TITLE[2]);
        c.fill(0,sby,W,1,C::ICON[0],C::ICON[1],C::ICON[2]);
    }

    void overlay(){
        int W=c.W(),H=c.H();
        // All text uses xtext which falls back to bitmap if no X11 font
        c.xtext(10,4,tabs[active].title.size()>50?tabs[active].title.substr(0,48)+"..":tabs[active].title,191,191,201);
        // Nav button labels
        c.xtext(16,38,"<",191,191,201); c.xtext(50,38,">",191,191,201);
        c.xtext(84,38,"R",191,191,201); c.xtext(118,38,"^",191,191,201);
        // Address bar
        std::string ad=addr_focused?(addr.empty()?"Search or enter address":addr):tabs[active].url;
        if(ad.size()>65)ad=ad.substr(0,63)+"..";
        c.xtext(184,38,ad,251,251,254);
        // Tab titles
        for(int i=0;i<(int)tabs.size();i++){
            std::string tl=tabs[i].title;if(tl.size()>16)tl=tl.substr(0,14)+"..";
            if(tabs[i].loading)tl="Loading...";
            c.xtext(i*200+12,76,tl,i==active?251:191,i==active?251:191,i==active?254:201);
            c.xtext(i*200+178,76,"x",191,191,201);
        }
        c.xtext((int)tabs.size()*200+14,76,"+",191,191,201);
        // Bookmarks
        c.xtext(8,108,"Getting Started",191,191,201);
        c.xtext(150,108,"GitHub",191,191,201);
        c.xtext(220,108,"Most Visited",191,191,201);
        c.xtext(350,108,"Firefox C++",191,191,201);
        // Newtab page text
        if(tabs[active].url=="about:home"||tabs[active].url=="about:blank"){
            c.xtext(W/2-30,H/2-160,"Firefox",251,251,254);
            c.xtext(W/2-260,H/2-30,"Search the Web",191,191,201);
            std::vector<std::string> sites={"Google","YouTube","GitHub","Wikipedia","Reddit","Amazon","Stack Overflow","Twitter"};
            for(int i=0;i<(int)sites.size();i++){
                c.xtext(W/2-368+(i%4)*200,H/2+50+(i/4)*90,sites[i],251,251,254);
                c.xtext(W/2-368+(i%4)*200,H/2+66+(i/4)*90,sites[i]+".com",191,191,201);
            }
        }
        // Status bar
        std::string st=tabs[active].loading?"Loading...":tabs[active].url.empty()?"Ready":tabs[active].url;
        if(st.size()>80)st=st.substr(0,78)+"..";
        c.xtext(8,H-15,st,191,191,201);
        if(!tabs[active].url.empty()&&tabs[active].url.find("https")==0)c.xtext(W-60,H-15,"Secure",46,198,109);
    }
};

int main(){Iceweasel w;w.run();return 0;}
