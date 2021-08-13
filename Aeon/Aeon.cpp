#include "Aeon/Aeon.hpp"

Aeon::Core::App::App(const AppProperties& props)
{

	Aeon::Core::Display::GetInstance();

}

const Aeon::Core::Display& Aeon::Core::App::GetDisplay()
{
	return Aeon::Core::Display::GetInstance();
}
