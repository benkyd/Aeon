#include "Aeon.hpp"

#include <Aeon/Includes.hpp>

#include <Aeon/Rendering/ImGui.hpp>

using Core::App;
using Core::Display;
using Core::DisplayProperties;

using Input::InputController;

App::App( const AppProperties& props, const DisplayProperties& dispProps )
	: mDisplay()
	, mInput(InputController::GetInstance())
{
	PushThisAsSink( "ENGINE_DISPLAY_CORE" );

	mDisplay.Create( dispProps );
}

void App::Run()
{
	while ( !mSIGTERM )
	{
		// Should do this ONLY on update (but needs to be on main thread)
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
		// TODO: Timed event thread (won't allow rendering)
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

	mDisplay.Destroy();
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
