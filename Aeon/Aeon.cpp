#include <Aeon/Aeon.hpp>

Aeon::Core::Engine::Engine()
{

}

const Aeon::Core::Display& Aeon::Core::Engine::getDisplay()
{
	return Aeon::Core::Display::getInstance();
}
