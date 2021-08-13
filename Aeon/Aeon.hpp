#ifndef AEON_AEON_H_
#define AEON_AEON_H_

#include <string>

#include "Aeon/Core/Display.hpp"

namespace Aeon::Core {

class AppProperties {
public:
	std::string Name;
	int Width, Height;
	bool VSync;

	AppProperties(std::string name, int width = 1200, int height = 900, bool vSync = true)
		: Name(name),
		  Width(width),
		  Height(height),
		  VSync(vSync) { }
};

class App {
public:
	App(const AppProperties& props);
	virtual ~App();



	const Display& GetDisplay();


};

}

#endif
 