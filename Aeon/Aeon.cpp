#include "Aeon/Aeon.hpp"

using Aeon::Core::App;
using Aeon::Core::Display;
using Aeon::Core::DisplayProperties;

using Aeon::Input::Input;

App::App( const DisplayProperties& props )
	: mDisplay()
	, mInput()
{
	RegisterAsSink( "ENGINE_SYSTEM_CORE", 0 );

	mDisplay.Create( props );

}

void App::Run()
{
	while ( !mSIGTERM )
	{
		mInput.PollInput();
	}
}

const Display& App::GetDisplay()
{
	return mDisplay;
}

bool App::EventRecieved( GenericEvent& e )
{
	return false;
}
