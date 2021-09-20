#include "Aeon/Aeon.hpp"

#include <iostream>
#include <thread>

#include "Aeon/Rendering/ImGui.hpp"

using Aeon::Core::App;
using Aeon::Core::Display;
using Aeon::Core::DisplayProperties;

using Aeon::Input::Input;

App::App( const AppProperties& props, const DisplayProperties& dispProps )
	: mDisplay()
	, mInput()
{
	RegisterAsSink( "ENGINE_DISPLAY_CORE", 0 );

	mDisplay.Create( dispProps );
}

void App::Run()
{
	while ( !mSIGTERM )
	{
		mInput.PollInput();

		std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );

		mDisplay.EndFrame();
	}
}

const Display& App::GetDisplay()
{
	return mDisplay;
}

bool App::EventRecieved( GenericEvent& e )
{
	if ( e.Type == "DISPLAY_CLOSED" )
	{
		mSIGTERM = true;
	}

	return false;
}
