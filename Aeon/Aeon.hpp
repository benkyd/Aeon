#ifndef AEON_AEON_H_
#define AEON_AEON_H_

#include <Aeon/Display.hpp>

namespace Aeon::Core {

class Engine
{
public:
	Engine();

	const Aeon::Core::Display& getDisplay();
};

}

#endif
