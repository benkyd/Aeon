#include "Aeon/Aeon.hpp"

using Aeon::Core::App;
using Aeon::Core::Display;
using Aeon::Core::DisplayProperties;

App::App( const DisplayProperties& props )
	: mDisplay()
{
	mDisplay.Create( props );

}

void App::Run()
{
	// while ( !mSIGTERM )
	{

	}
}

const Display& App::GetDisplay()
{
	return mDisplay;
}
