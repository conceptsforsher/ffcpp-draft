/* MPL 2.0 */
#pragma once
#include <string>
namespace compositor {
class LayerTree { public: LayerTree(); ~LayerTree(); void render_frame(); private: int state_=0; };
class Layer { public: Layer(); ~Layer(); private: int state_=0; };
class Compositor { public: Compositor(); ~Compositor(); void render_frame(); void schedule_frame(); void set_vsync(bool); bool vsync_enabled() const; private: int state_=0; bool vsync_on_=true; };
class ShaderProgram { public: ShaderProgram(); ~ShaderProgram(); private: int state_=0; };
class VSyncSource { public: VSyncSource(); ~VSyncSource(); bool enabled() const { return true; } void set_enabled(bool e) {} private: int state_=0; };
class RenderScheduler { public: RenderScheduler(); ~RenderScheduler(); void request_frame() {} private: int state_=0; };
class GPUBackend { public: GPUBackend(); ~GPUBackend(); private: int state_=0; };
class TextureAtlas { public: TextureAtlas(); ~TextureAtlas(); private: int state_=0; };
class EffectChain { public: EffectChain(); ~EffectChain(); private: int state_=0; };
class FrameBuffer { public: FrameBuffer(); ~FrameBuffer(); void clear() {} private: int state_=0; };
class RenderPass { public: RenderPass(); ~RenderPass(); private: int state_=0; };
class BlurFilter { public: BlurFilter(); ~BlurFilter(); private: int state_=0; };
class ShadowFilter { public: ShadowFilter(); ~ShadowFilter(); private: int state_=0; };
class ColorMatrix { public: ColorMatrix(); ~ColorMatrix(); private: int state_=0; };
class OpacityEffect { public: OpacityEffect(); ~OpacityEffect(); private: int state_=0; };
class TransformEffect { public: TransformEffect(); ~TransformEffect(); private: int state_=0; };
class ClipStack { public: ClipStack(); ~ClipStack(); private: int state_=0; };
class BatchRenderer { public: BatchRenderer(); ~BatchRenderer(); private: int state_=0; };
class TileManager { public: TileManager(); ~TileManager(); private: int state_=0; };
class SurfacePool { public: SurfacePool(); ~SurfacePool(); private: int state_=0; };
} // namespace compositor
