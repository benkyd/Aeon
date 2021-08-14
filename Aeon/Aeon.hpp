#ifndef AEON_AEON_H_
#define AEON_AEON_H_

#include <string>

#include "Aeon/Core/Display.hpp"

namespace Aeon::Core {

class App {
public:
	App( const DisplayProperties& props );

	void Run();

	void PushLayer();
	void PopLayer();

	const Display& GetDisplay();
private:

	Display mDisplay;

	bool mSIGTERM = false;

};

}

#endif
