#ifndef AEON_RENDERING_RENDERMASTER_H_
#define AEON_RENDERING_RENDERMASTER_H_

#include "Aeon/Singleton.hpp"

namespace Rendering
{

class Renderable;

class RenderMaster : public Helpers::Singleton<RenderMaster>
{
	RenderMaster();

	void QueueRenderable( Renderable* renderable );
};

}

#endif
