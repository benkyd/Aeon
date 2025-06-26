#ifndef AEON_RENDERING_RENDERMASTER_H_
#define AEON_RENDERING_RENDERMASTER_H_

#include <Aeon/Singleton.hpp>

class Renderable;

namespace Rendering
{

class RenderMaster : public Helpers::Singleton<Rendering::RenderMaster>
{
public:
    RenderMaster();

    void QueueRenderable(Renderable* renderable);


};

} // namespace Rendering

#endif
