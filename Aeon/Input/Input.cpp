#include "Input.hpp"

#include <Aeon/Includes.hpp>

#include <Aeon/Core/Events.hpp>
#include <Aeon/Input/InputMap.hpp>
#include <Aeon/Rendering/ImGui.hpp>

using Input::InputController;

InputController::InputController()
	: mEvent()
    , mDisplayEventDispatcher()
    , mKeyboardEventDispatcher()
    , mMouseEventDispatcher()
{
    mDisplayEventDispatcher.RegisterAsSource( "ENGINE_DISPLAY_CORE" );
    mMouseEventDispatcher.RegisterAsSource( "ENGINE_INPUT_MOUSE" );
    mKeyboardEventDispatcher.RegisterAsSource( "ENGINE_INPUT_KEYBOARD" );

    mKbdState = static_cast<const uint8_t*>(SDL_GetKeyboardState( &mNumScancodes ));
}

InputController::~InputController()
{
    mDisplayEventDispatcher.DeRegisterAsSource( "ENGINE_DISPLAY_CORE" );
    mMouseEventDispatcher.DeRegisterAsSource( "ENGINE_INPUT_MOUSE" );
    mKeyboardEventDispatcher.DeRegisterAsSource( "ENGINE_INPUT_KEYBOARD" );

    // Do not free mKbdState as that is done by SDL
}

void InputController::PollInput()
{
    //SDL_PumpEvents();
	while ( SDL_PollEvent( &mEvent ) )
	{
        // Provide to non-event driven subsystem
        ImGui_ImplSDL2_ProcessEvent( &mEvent );

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
        case SDL_KEYDOWN:
        case SDL_KEYUP:
        {
            mPollKeyboard();
        }
		}
	}

    // just in case
    mKbdState = static_cast<const uint8_t*>(SDL_GetKeyboardState( &mNumScancodes ));

    // keyboard processing
    mPollScanKeyboard();
}

void InputController::mPollDisplay()
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
        Core::GenericEvent e;
        e.x = mEvent.window.data1;
        e.y = mEvent.window.data2;
        e.Type = "DISPLAY_MOVE";
        mDisplayEventDispatcher.Dispatch( e );
        break;
    }
    case SDL_WINDOWEVENT_RESIZED:
    {
        Core::GenericEvent e;
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

void InputController::mPollMouse()
{
    Core::GenericEvent e;
    e.x = mEvent.motion.x;
    e.y = mEvent.motion.y;
    e.dx = mEvent.motion.xrel;
    e.dy = mEvent.motion.yrel;
    e.Type = "MOUSE_MOVE";
    mMouseEventDispatcher.Dispatch( e );
}

void InputController::mPollScroll()
{
    Core::GenericEvent e;
    e.y = mEvent.wheel.y;
    e.Type = "MOUSE_SCROLL";
    mMouseEventDispatcher.Dispatch( e );
}

void InputController::mPollClick()
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
    else if ( mEvent.button.state == SDL_RELEASED )
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

void InputController::mPollKeyboard()
{
    EKeyCode keycode = KeyCodeFromSDL( mEvent.key.keysym.sym );
    Core::GenericEvent e;
    e.keyCode = KeyCodeFromSDL(keycode);
    if ( mEvent.key.state == SDL_PRESSED )
    {
        e.Type = "KEYBOARD_KEYDOWN";
    }
    else if ( mEvent.key.state == SDL_RELEASED )
    {
        e.Type = "KEYBOARD_KEYUP";
    }
    
    uint16_t mods = mEvent.key.keysym.mod;
    e.keyMods = mods;

    mModKeyState = mods;

    mKeyboardEventDispatcher.Dispatch( e );
}

void InputController::mPollScanKeyboard()
{
    //this is naive, can be optimised with double buffering
    for ( int i = 0; i < mNumScancodes; i++ )
    {
        bool isKeyPressed = (bool)mKbdState[i];
        if ( isKeyPressed )
        {
            EKeyCode whatKeyPressed = KeyCodeFromScanCode( (SDL_Scancode)i );

            Core::GenericEvent e;
            e.keyCode = whatKeyPressed;
            e.keyMods = mModKeyState;
            e.Type = "KEYBOARD_KEYPRESS";
            mKeyboardEventDispatcher.Dispatch( e );
        }
    }
}
