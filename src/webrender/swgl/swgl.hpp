/* MPL 2.0 */
//! Software OpenGL rasterizer for headless rendering.
#pragma once
#include <cstdint>
#include <vector>
#include "webrender_api/src/types.hpp"

namespace swgl {

struct Texture {
    int width=0, height=0, stride=0;
    std::vector<uint8_t> data;
    Texture()=default;
    Texture(int w,int h):width(w),height(h),stride(w*4),data(w*h*4){}
    void clear(uint8_t r,uint8_t g,uint8_t b,uint8_t a=255) {
        for(size_t i=0;i+3<data.size();i+=4){data[i]=r;data[i+1]=g;data[i+2]=b;data[i+3]=a;}
    }
    void set_pixel(int x,int y,wr::ColorU c) {
        if(x<0||x>=width||y<0||y>=height)return;
        size_t idx=(y*stride)+x*4;
        data[idx]=c.r;data[idx+1]=c.g;data[idx+2]=c.b;data[idx+3]=c.a;
    }
};

struct SWGLContext {
    Texture* framebuffer=nullptr;
    int fb_width=0,fb_height=0;
    void bind_framebuffer(Texture* tex){framebuffer=tex;fb_width=tex?tex->width:0;fb_height=tex?tex->height:0;}
    void clear_color(float r,float g,float b,float a){if(framebuffer)framebuffer->clear(r*255,g*255,b*255,a*255);}
};

void fill_rect(Texture& tex, int x, int y, int w, int h, wr::ColorU color);
void draw_line(Texture& tex, int x0, int y0, int x1, int y1, wr::ColorU color);
wr::ColorU blend_pixel(wr::ColorU src, wr::ColorU dst);

} // namespace swgl
