#include "Aeon/Aeon.hpp"

#include <iostream>

using Aeon::Core::App;
using Aeon::Core::Display;
using Aeon::Core::DisplayProperties;

using Aeon::Input::Input;

App::App( const DisplayProperties& props )
	: mDisplay()
	, mInput()
{
	RegisterAsSink( "ENGINE_DISPLAY_CORE", 0 );
	RegisterAsSink( "ENGINE_INPUT_MOUSE", 0 );
	RegisterAsSink( "ENGINE_INPUT_KEYBOARD", 0 );

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
	//std::cout << e.Type << std::endl;
	if ( e.Type == "DISPLAY_CLOSED" )
	{
		mSIGTERM = true;
	}

	return false;
}
