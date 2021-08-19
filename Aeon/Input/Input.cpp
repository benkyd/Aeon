#include "Aeon/Input/Input.hpp"

#include <iostream>

#include "Aeon/Core/Events.hpp"

using Aeon::Input::Input;

Input::Input()
	: mEvent()
    , mDisplayEventDispatcher()
    , mKeyboardEventDispatcher()
    , mMouseEventDispatcher()
{
    mDisplayEventDispatcher.RegisterAsSource( "ENGINE_DISPLAY_CORE" );
}

Input::~Input()
{

}

void Input::PollInput()
{
	while ( SDL_PollEvent( &mEvent ) )
	{
		switch ( mEvent.type )
		{
        case SDL_WINDOWEVENT:
        {
            switch ( mEvent.window.event )
            {
            case SDL_WINDOWEVENT_SHOWN:
            {
                mDisplayEventDispatcher.Dispatch( "DISPLAY_SHOW" );
                break;
            }
            case SDL_WINDOWEVENT_HIDDEN:
            {
                mDisplayEventDispatcher.Dispatch( "DISPLAY_HIDE" );
                break;
            }
            case SDL_WINDOWEVENT_MOVED:
            {
                Aeon::Core::GenericEvent e;
                e.x = mEvent.window.data1;
                e.y = mEvent.window.data2;
                e.Type = "DISPLAY_MOVE";
                mDisplayEventDispatcher.Dispatch( e );
                break;
            }
            case SDL_WINDOWEVENT_RESIZED:
            {
                Aeon::Core::GenericEvent e;
                e.x = mEvent.window.data1;
                e.y = mEvent.window.data2;
                e.Type = "DISPLAY_RESIZE";
                mDisplayEventDispatcher.Dispatch( e );
                break;
            }
            case SDL_WINDOWEVENT_MINIMIZED:
            {
                mDisplayEventDispatcher.Dispatch( "DISPLAY_MINIMISED" );
                break;
            }
            case SDL_WINDOWEVENT_MAXIMIZED:
            {
                mDisplayEventDispatcher.Dispatch( "DISPLAY_MAXIMISED" );
                break;
            }
            case SDL_WINDOWEVENT_ENTER:
            {
                mDisplayEventDispatcher.Dispatch( "DISPLAY_MOUSE_ENTER" );
                break;
            }
            case SDL_WINDOWEVENT_LEAVE:
            {
                mDisplayEventDispatcher.Dispatch( "DISPLAY_MOUSE_LEAVE" );
                break;
            }
            case SDL_WINDOWEVENT_FOCUS_GAINED:
            {
                mDisplayEventDispatcher.Dispatch( "DISPLAY_FOCUS" );
                break;
            }
            case SDL_WINDOWEVENT_FOCUS_LOST:
            {
                mDisplayEventDispatcher.Dispatch( "DISPLAY_OUT_OF_FOCUS" );
                break;
            }
            case SDL_WINDOWEVENT_CLOSE:
            {
                mDisplayEventDispatcher.Dispatch( "DISPLAY_CLOSED" );
                break;
            }
            }
        }
		}
	}

	//Uint8* state = (Uint8*)SDL_GetKeyboardState( NULL );
	//std::cout << state << std::endl;
	//std::cout << std::endl;
}

