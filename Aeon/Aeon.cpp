#include "Aeon/Aeon.hpp"

#include <iostream>

#include "Aeon/Rendering/ImGui.hpp"

using Aeon::Core::App;
using Aeon::Core::Display;
using Aeon::Core::DisplayProperties;

using Aeon::Input::Input;

App::App( const DisplayProperties& props )
	: mDisplay()
	, mInput()
{
	RegisterAsSink( "ENGINE_DISPLAY_CORE", 0 );

	mDisplay.Create( props );
}

void App::Run()
{
	while ( !mSIGTERM )
	{
		mInput.PollInput();

		static float f = 0.0f;
		static int counter = 0;
		static ImVec4 clearColour = ImVec4( 0.45f, 0.55f, 0.60f, 1.00f );

		ImGui::Begin( "Hello, world!" );                          // Create a window called "Hello, world!" and append into it.

		ImGui::Text( "This is some useful text." );               // Display some text (you can use a format strings too)
		ImGui::SliderFloat( "float", &f, 0.0f, 1.0f );            // Edit 1 float using a slider from 0.0f to 1.0f
		ImGui::ColorEdit3( "clear color", (float*)&clearColour ); // Edit 3 floats representing a color

		ImGui::End();

		mDisplay.SetClearColour( clearColour.x, clearColour.y, clearColour.z, clearColour.w );

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
