#include "Aeon/Input/Input.hpp"

#include <iostream>
#include <algorithm>
#include <iterator>

#include "Aeon/Core/Events.hpp"

using Aeon::Input::Input;

Input::Input()
	: mEvent()
    , mDisplayEventDispatcher()
    , mKeyboardEventDispatcher()
    , mMouseEventDispatcher()
{
    mDisplayEventDispatcher.RegisterAsSource( "ENGINE_DISPLAY_CORE" );
    mMouseEventDispatcher.RegisterAsSource( "ENGINE_INPUT_MOUSE" );
    mKeyboardEventDispatcher.RegisterAsSource( "ENGINE_INPUT_KEYBOARD" );

    mKbdState = static_cast<const uint8_t*>(SDL_GetKeyboardState( &numScancodes ));
    mOldKbdState = static_cast<uint8_t*>(malloc( numScancodes / sizeof( uint8_t ) ));
    memcpy( mOldKbdState, mKbdState, 242 / sizeof( uint8_t ) );
}

Input::~Input()
{
    mDisplayEventDispatcher.DeRegisterAsSource( "ENGINE_DISPLAY_CORE" );
    mMouseEventDispatcher.DeRegisterAsSource( "ENGINE_INPUT_MOUSE" );
    mKeyboardEventDispatcher.DeRegisterAsSource( "ENGINE_INPUT_KEYBOARD" );

    free( mOldKbdState );
}

void Input::PollInput()
{
    SDL_PumpEvents();
	while ( SDL_PollEvent( &mEvent ) )
	{
		switch ( mEvent.type )
		{
		case SDL_WINDOWEVENT:
		{
            mPollDisplay();
            break;
		}
        case SDL_MOUSEWHEEL:
        {
            mPollScroll();
            break;
        }
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP:
        {
            mPollClick();
            break;
        }
        case SDL_MOUSEMOTION:
        {
            mPollMouse();
            break;
        }
		}
	}

    // just in case
    mKbdState = static_cast<const uint8_t*>(SDL_GetKeyboardState( &numScancodes ));

    // keyboard processing

    // first we want to check if any key has changed
    // if a key has changed, then we want to check if any keys are pressed
    // if a key is pressed we want to check the keys and dispatch events
    // according to the scancode
    // keydown and keyup will be done seperately
    if ( !std::equal( mKbdState, mKbdState + numScancodes, mOldKbdState ) )
    {
        std::cout << "keyboard ennit" << std::endl;
    }

    memcpy( mOldKbdState, mKbdState, numScancodes / sizeof( uint8_t ) );
}

void Input::mPollDisplay()
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

void Input::mPollMouse()
{
    Aeon::Core::GenericEvent e;
    e.x = mEvent.motion.x;
    e.y = mEvent.motion.y;
    e.dx = mEvent.motion.xrel;
    e.dy = mEvent.motion.yrel;
    e.Type = "MOUSE_MOVE";
    mMouseEventDispatcher.Dispatch( e );
}

void Input::mPollScroll()
{
    Aeon::Core::GenericEvent e;
    e.y = mEvent.wheel.y;
    e.Type = "MOUSE_SCROLL";
    mMouseEventDispatcher.Dispatch( e );
}

void Input::mPollClick()
{
    if ( mEvent.button.state == SDL_PRESSED )
    {
        switch ( mEvent.button.button )
        {
        case SDL_BUTTON_LEFT:
        {
            mDisplayEventDispatcher.Dispatch( "MOUSE_LEFT_DOWN" );
            break;
        }
        case SDL_BUTTON_RIGHT:
        {
            mDisplayEventDispatcher.Dispatch( "MOUSE_RIGHT_DOWN" );
            break;
        }
        case SDL_BUTTON_MIDDLE:
        {
            mDisplayEventDispatcher.Dispatch( "MOUSE_MIDDLE_DOWN" );
            break;
        }
        }
    }
    if ( mEvent.button.state == SDL_RELEASED )
    {
        switch ( mEvent.button.button )
        {
        case SDL_BUTTON_LEFT:
        {
            mDisplayEventDispatcher.Dispatch( "MOUSE_LEFT_UP" );
            break;
        }
        case SDL_BUTTON_RIGHT:
        {
            mDisplayEventDispatcher.Dispatch( "MOUSE_RIGHT_UP" );
            break;
        }
        case SDL_BUTTON_MIDDLE:
        {
            mDisplayEventDispatcher.Dispatch( "MOUSE_MIDDLE_UP" );
            break;
        }
        }
    }
}

void Input::mPollKeyboard()
{

}
