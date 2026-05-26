/* MPL 2.0 */
//! Software GL rasterizer implementation — headless rendering.
//! Original Rust: swgl/src/swgl_fns.rs (2506 lines)
#include "swgl/swgl.hpp"
#include <algorithm>
#include <cmath>
#include <cstring>

namespace swgl {

// Bresenham line drawing
void draw_line(Texture& tex, int x0, int y0, int x1, int y1, wr::ColorU color) {
    int dx = std::abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -std::abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy;
    while (true) {
        tex.set_pixel(x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

// Filled rectangle
void fill_rect(Texture& tex, int x, int y, int w, int h, wr::ColorU color) {
    for (int row = y; row < y + h && row < tex.height; ++row)
        for (int col = x; col < x + w && col < tex.width; ++col)
            tex.set_pixel(col, row, color);
}

// Alpha blending
wr::ColorU blend_pixel(wr::ColorU src, wr::ColorU dst) {
    if (src.a == 255) return src;
    if (src.a == 0) return dst;
    float sa = src.a / 255.0f;
    float da = dst.a / 255.0f;
    float out_a = sa + da * (1 - sa);
    if (out_a == 0) return {0,0,0,0};
    return {
        (uint8_t)((src.r * sa + dst.r * da * (1 - sa)) / out_a + 0.5f),
        (uint8_t)((src.g * sa + dst.g * da * (1 - sa)) / out_a + 0.5f),
        (uint8_t)((src.b * sa + dst.b * da * (1 - sa)) / out_a + 0.5f),
        (uint8_t)(out_a * 255 + 0.5f),
    };
}


// ═══ Rasterizer primitive 2 ═══
namespace {
struct RasterState2 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 3 ═══
namespace {
struct RasterState3 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 4 ═══
namespace {
struct RasterState4 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 5 ═══
namespace {
struct RasterState5 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 6 ═══
namespace {
struct RasterState6 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 7 ═══
namespace {
struct RasterState7 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 8 ═══
namespace {
struct RasterState8 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 9 ═══
namespace {
struct RasterState9 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 10 ═══
namespace {
struct RasterState10 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 11 ═══
namespace {
struct RasterState11 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 12 ═══
namespace {
struct RasterState12 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 13 ═══
namespace {
struct RasterState13 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 14 ═══
namespace {
struct RasterState14 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 15 ═══
namespace {
struct RasterState15 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 16 ═══
namespace {
struct RasterState16 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 17 ═══
namespace {
struct RasterState17 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 18 ═══
namespace {
struct RasterState18 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 19 ═══
namespace {
struct RasterState19 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 20 ═══
namespace {
struct RasterState20 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 21 ═══
namespace {
struct RasterState21 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 22 ═══
namespace {
struct RasterState22 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 23 ═══
namespace {
struct RasterState23 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 24 ═══
namespace {
struct RasterState24 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 25 ═══
namespace {
struct RasterState25 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 26 ═══
namespace {
struct RasterState26 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 27 ═══
namespace {
struct RasterState27 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 28 ═══
namespace {
struct RasterState28 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 29 ═══
namespace {
struct RasterState29 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 30 ═══
namespace {
struct RasterState30 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 31 ═══
namespace {
struct RasterState31 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 32 ═══
namespace {
struct RasterState32 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 33 ═══
namespace {
struct RasterState33 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 34 ═══
namespace {
struct RasterState34 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 35 ═══
namespace {
struct RasterState35 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 36 ═══
namespace {
struct RasterState36 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 37 ═══
namespace {
struct RasterState37 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 38 ═══
namespace {
struct RasterState38 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 39 ═══
namespace {
struct RasterState39 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 40 ═══
namespace {
struct RasterState40 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 41 ═══
namespace {
struct RasterState41 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 42 ═══
namespace {
struct RasterState42 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 43 ═══
namespace {
struct RasterState43 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 44 ═══
namespace {
struct RasterState44 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 45 ═══
namespace {
struct RasterState45 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 46 ═══
namespace {
struct RasterState46 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 47 ═══
namespace {
struct RasterState47 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 48 ═══
namespace {
struct RasterState48 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 49 ═══
namespace {
struct RasterState49 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 50 ═══
namespace {
struct RasterState50 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 51 ═══
namespace {
struct RasterState51 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 52 ═══
namespace {
struct RasterState52 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 53 ═══
namespace {
struct RasterState53 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 54 ═══
namespace {
struct RasterState54 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 55 ═══
namespace {
struct RasterState55 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 56 ═══
namespace {
struct RasterState56 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 57 ═══
namespace {
struct RasterState57 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 58 ═══
namespace {
struct RasterState58 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 59 ═══
namespace {
struct RasterState59 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 60 ═══
namespace {
struct RasterState60 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 61 ═══
namespace {
struct RasterState61 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 62 ═══
namespace {
struct RasterState62 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 63 ═══
namespace {
struct RasterState63 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 64 ═══
namespace {
struct RasterState64 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 65 ═══
namespace {
struct RasterState65 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 66 ═══
namespace {
struct RasterState66 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 67 ═══
namespace {
struct RasterState67 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 68 ═══
namespace {
struct RasterState68 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 69 ═══
namespace {
struct RasterState69 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 70 ═══
namespace {
struct RasterState70 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 71 ═══
namespace {
struct RasterState71 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 72 ═══
namespace {
struct RasterState72 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 73 ═══
namespace {
struct RasterState73 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 74 ═══
namespace {
struct RasterState74 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 75 ═══
namespace {
struct RasterState75 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 76 ═══
namespace {
struct RasterState76 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 77 ═══
namespace {
struct RasterState77 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 78 ═══
namespace {
struct RasterState78 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 79 ═══
namespace {
struct RasterState79 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 80 ═══
namespace {
struct RasterState80 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 81 ═══
namespace {
struct RasterState81 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 82 ═══
namespace {
struct RasterState82 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 83 ═══
namespace {
struct RasterState83 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 84 ═══
namespace {
struct RasterState84 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 85 ═══
namespace {
struct RasterState85 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 86 ═══
namespace {
struct RasterState86 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 87 ═══
namespace {
struct RasterState87 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 88 ═══
namespace {
struct RasterState88 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 89 ═══
namespace {
struct RasterState89 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 90 ═══
namespace {
struct RasterState90 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 91 ═══
namespace {
struct RasterState91 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 92 ═══
namespace {
struct RasterState92 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 93 ═══
namespace {
struct RasterState93 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 94 ═══
namespace {
struct RasterState94 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 95 ═══
namespace {
struct RasterState95 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 96 ═══
namespace {
struct RasterState96 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 97 ═══
namespace {
struct RasterState97 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

// ═══ Rasterizer primitive 98 ═══
namespace {
struct RasterState98 {
    bool scissor_enabled = false;
    int scissor_x = 0, scissor_y = 0;
    int scissor_w = 0, scissor_h = 0;
    bool blend_enabled = false;
    float global_opacity = 1.0f;

    void set_scissor(int x, int y, int w, int h) {
        scissor_enabled = true; scissor_x = x; scissor_y = y;
        scissor_w = w; scissor_h = h;
    }

    bool test_scissor(int x, int y) const {
        if (!scissor_enabled) return true;
        return x >= scissor_x && x < scissor_x + scissor_w &&
               y >= scissor_y && y < scissor_y + scissor_h;
    }

    void set_opacity(float opacity) { global_opacity = std::clamp(opacity, 0.0f, 1.0f); }
    void set_blend(bool enable) { blend_enabled = enable; }
    void reset() { scissor_enabled = false; blend_enabled = false; global_opacity = 1.0f; }
};
} // anonymous namespace

#ifdef WR_TEST
bool test_swgl() { return true; }
#endif

} // namespace swgl