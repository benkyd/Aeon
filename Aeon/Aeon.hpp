#ifndef AEON_AEON_H_
#define AEON_AEON_H_

#include <string>

#include "Aeon/Core/Display.hpp"
#include "Aeon/Core/Events.hpp"
#include "Aeon/Input/Input.hpp"

namespace Aeon::Core {

class App : public EventListener
{
public:
	App( const DisplayProperties& props );

	void Run();

	void PushLayer();
	void PopLayer();

	const Display& GetDisplay();

	bool EventRecieved( GenericEvent& e ) override;

private:

	Display mDisplay;

	Aeon::Input::Input mInput;

private:
	
	bool mSIGTERM = false;

};

}

#endif
