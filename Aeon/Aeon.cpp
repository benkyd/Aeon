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

		// tick through game layers
		for ( const auto& layer : mGameLayers )
		{
			layer->FrameTick();
		}
		for ( const auto& layer : mTopLayers )
		{
			layer->FrameTick();
		}
		for ( const auto& layer : mDebugLayers )
		{
			layer->FrameTick();
		}

		// tick through game layers *but timed*
		for ( const auto& layer : mGameLayers )
		{
			layer->TimeTick();
		}
		for ( const auto& layer : mTopLayers )
		{
			layer->TimeTick();
		}
		for ( const auto& layer : mDebugLayers )
		{
			layer->TimeTick();
		}

		mDisplay.EndFrame();
	}
}

const Display& App::GetDisplay()
{
	return mDisplay;
}

void App::PushLayer( GameLayer* layer )
{
	mGameLayers.push_back( layer );
}

void App::PushTopLayer( GameLayer* layer )
{
	mTopLayers.push_back( layer );
}

void App::PushDebugLayer( GameLayer* layer )
{
	mDebugLayers.push_back( layer );
}


bool App::EventRecieved( GenericEvent& e )
{
	if ( e.Type == "DISPLAY_CLOSED" )
	{
		mSIGTERM = true;
	}

	return false;
}
