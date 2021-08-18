#include "Aeon/Input/Input.hpp"

#include <iostream>

#include "Aeon/Core/Events.hpp"

using Aeon::Input::Input;

Input::Input()
	: mEvent()
{

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
            switch ( mEvent.window.event )
            {
            case SDL_WINDOWEVENT_SHOWN:
                SDL_Log( "Window %d shown", mEvent.window.windowID );
                break;
            case SDL_WINDOWEVENT_HIDDEN:
                SDL_Log( "Window %d hidden", mEvent.window.windowID );
                break;
            case SDL_WINDOWEVENT_MOVED:
                SDL_Log( "Window %d moved to %d,%d",
                    mEvent.window.windowID, mEvent.window.data1,
                    mEvent.window.data2 );
                break;
            case SDL_WINDOWEVENT_RESIZED:
                SDL_Log( "Window %d resized to %dx%d",
                    mEvent.window.windowID, mEvent.window.data1,
                    mEvent.window.data2 );
                break;
            case SDL_WINDOWEVENT_SIZE_CHANGED:
                SDL_Log( "Window %d size changed to %dx%d",
                    mEvent.window.windowID, mEvent.window.data1,
                    mEvent.window.data2 );
                break;
            case SDL_WINDOWEVENT_MINIMIZED:
                SDL_Log( "Window %d minimized", mEvent.window.windowID );
                break;
            case SDL_WINDOWEVENT_MAXIMIZED:
                SDL_Log( "Window %d maximized", mEvent.window.windowID );
                break;
            case SDL_WINDOWEVENT_RESTORED:
                SDL_Log( "Window %d restored", mEvent.window.windowID );
                break;
            case SDL_WINDOWEVENT_ENTER:
                SDL_Log( "Mouse entered window %d",
                    mEvent.window.windowID );
                break;
            case SDL_WINDOWEVENT_LEAVE:
                SDL_Log( "Mouse left window %d", mEvent.window.windowID );
                break;
            case SDL_WINDOWEVENT_FOCUS_GAINED:
                SDL_Log( "Window %d gained keyboard focus",
                    mEvent.window.windowID );
                break;
            case SDL_WINDOWEVENT_FOCUS_LOST:
                SDL_Log( "Window %d lost keyboard focus",
                    mEvent.window.windowID );
                break;
            case SDL_WINDOWEVENT_CLOSE:
                SDL_Log( "Window %d closed", mEvent.window.windowID );
                break;
            }
		}
	}

	//Uint8* state = (Uint8*)SDL_GetKeyboardState( NULL );
	//std::cout << state << std::endl;
	//std::cout << std::endl;
}

