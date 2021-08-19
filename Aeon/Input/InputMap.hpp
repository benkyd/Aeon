#ifndef AEON_INPUT_INPUTMAP_H_
#define AEON_INPUT_INPUTMAP_H_

#include <SDL.h>

namespace Aeon::Input
{

enum EKeyCode
{
    Unknown = 0,
    Return = '\r',
    Escape = '\x1B',
    Backspace = '\b',
    Tab = '\t',
    Space = ' ',
    ExclimationMark = '!',
    DoubleQuote = '"',
    Hashtag = '#',
    Percent = '%',
    Dollar = '$',
    Ampersand = '&',
    SingleQuote = '\'',
    LeftBracket = '(',
    RightBracket = ')',
    Asterisk = '*',
    Plus = '+',
    Comma = ',',
    Minus = '-',
    Peroid = '.',
    Slash = '/',
    Key_0 = '0',
    Key_1 = '1',
    Key_2 = '2',
    Key_3 = '3',
    Key_4 = '4',
    Key_5 = '5',
    Key_6 = '6',
    Key_7 = '7',
    Key_8 = '8',
    Key_9 = '9',
    Colon = ':',
    Semicolon = ';',
    Less = '<',
    Equal = '=',
    Greater = '>',
    Question = '?',
    At = '@',
    LeftSquareBracket = '[',
    RightSquareBracket = ']',
    Backslash = '\\',
    Caret = '^',
    Underscore = '_',
    Backtick = '`',
    Key_a = 'a',
    Key_b = 'b',
    Key_c = 'c',
    Key_d = 'd',
    Key_e = 'e',
    Key_f = 'f',
    Key_g = 'g',
    Key_h = 'h',
    Key_i = 'i',
    Key_j = 'j',
    Key_k = 'k',
    Key_l = 'l',
    Key_m = 'm',
    Key_n = 'n',
    Key_o = 'o',
    Key_p = 'p',
    Key_q = 'q',
    Key_r = 'r',
    Key_s = 's',
    Key_t = 't',
    Key_u = 'u',
    Key_v = 'v',
    Key_w = 'w',
    Key_x = 'x',
    Key_y = 'y',
    Key_z = 'z',
    Capslock = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_CAPSLOCK ),
    F1 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_F1 ),
    F2 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_F2 ),
    F3 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_F3 ),
    F4 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_F4 ),
    F5 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_F5 ),
    F6 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_F6 ),
    F7 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_F7 ),
    F8 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_F8 ),
    F9 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_F9 ),
    F10 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_F10 ),
    F11 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_F11 ),
    F12 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_F12 ),
    F13 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_F13 ),
    F14 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_F14 ),
    F15 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_F15 ),
    F16 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_F16 ),
    F17 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_F17 ),
    F18 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_F18 ),
    F19 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_F19 ),
    F20 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_F20 ),
    F21 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_F21 ),
    F22 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_F22 ),
    F23 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_F23 ),
    F24 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_F24 ),

    PrintSc = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_PRINTSCREEN ),
    ScrollLk = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_SCROLLLOCK ),
    Pause = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_PAUSE ),
    Insert = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_INSERT ),
    Home = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_HOME ),
    PageUp = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_PAGEUP ),
    PageDown = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_PAGEDOWN ),
    Delete = '\x7F',
    End = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_END ),
    RightArrow = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_RIGHT ),
    UpArrow = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_UP ),
    DownArrow = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_DOWN ),
    LeftArrow = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_LEFT ),

    KeyPad_Divide = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_DIVIDE ),
    KeyPad_Multiply = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_MULTIPLY ),
    KeyPad_Minus = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_MINUS ),
    KeyPad_Plus = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_PLUS ),
    KeyPad_Enter = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_ENTER ),
    KeyPad_1 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_1 ),
    KeyPad_2 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_2 ),
    KeyPad_3 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_3 ),
    KeyPad_4 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_4 ),
    KeyPad_5 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_5 ),
    KeyPad_6 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_6 ),
    KeyPad_7 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_7 ),
    KeyPad_8 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_8 ),
    KeyPad_9 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_9 ),
    KeyPad_0 = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_0 ),
    KeyPad_Peroid = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_PERIOD ),
    KeyPad_Equals = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_EQUALS ),
    KeyPad_LeftBracket = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_LEFTPAREN ),
    KeyPad_RightBracket = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_RIGHTPAREN ),
    KeyPad_LeftBrace = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_LEFTBRACE ),
    KeyPad_RightBrace = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_RIGHTBRACE ),
    KeyPad_Tab = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_TAB ),
    KeyPad_Backspace = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_BACKSPACE ),
    KeyPad_XOR = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_XOR ),
    KeyPad_Power = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_POWER ),
    KeyPad_Percent = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_PERCENT ),
    KeyPad_Less = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_LESS ),
    KeyPad_Greater = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_GREATER ),
    KeyPad_Ampersand = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_AMPERSAND ),
    KeyPad_VerticalBar = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_VERTICALBAR ),
    KeyPad_Colon = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_COLON ),
    KeyPad_Hashtag = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_HASH ),
    KeyPad_Space = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_SPACE ),
    KeyPad_At = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_KP_AT ),

    LCTRL = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_LCTRL ),
    RCTRL = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_RCTRL ),
    LSHIFT = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_LSHIFT ),
    RSHIFT = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_RSHIFT ),
    LALT = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_LALT ),
    RALT = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_RALT ),
    LGUI = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_LGUI ),
    RGUI = SDL_SCANCODE_TO_KEYCODE( SDL_SCANCODE_RGUI ),

    CTRL = LCTRL | RCTRL,
    SHIFT = LSHIFT | RSHIFT,
    ALT = LALT | RALT,
    GUI = LGUI | RGUI
};

inline EKeyCode KeyCodeFromSDL( SDL_Keycode key )
{
    return (EKeyCode)key;
}

inline EKeyCode KeyCodeFromKeymod( SDL_Keymod key )
{
    switch ( key )
    {
    case KMOD_NONE:
        return EKeyCode::Unknown;
        break;
    case KMOD_LSHIFT:
        return EKeyCode::LSHIFT;
        break;
    case KMOD_RSHIFT:
        return EKeyCode::RSHIFT;
        break;
    case KMOD_LCTRL:
        return EKeyCode::LCTRL;
        break;
    case KMOD_RCTRL:
        return EKeyCode::RCTRL;
        break;
    case KMOD_LALT:
        return EKeyCode::LALT;
        break;
    case KMOD_RALT:
        return EKeyCode::RALT;
        break;
    case KMOD_LGUI:
        return EKeyCode::LGUI;
        break;
    case KMOD_RGUI:
        return EKeyCode::RGUI;
        break;
    case KMOD_CTRL:
        return EKeyCode::CTRL;
        break;
    case KMOD_SHIFT:
        return EKeyCode::SHIFT;
        break;
    case KMOD_ALT:
        return EKeyCode::ALT;
        break;
    case KMOD_GUI:
        return EKeyCode::GUI;
        break;
    default:
        return EKeyCode::Unknown;
    }
}

inline EKeyCode KeyCodeFromSDL( SDL_Scancode key )
{
    return KeyCodeFromSDL( SDL_SCANCODE_TO_KEYCODE( key ) );
}

}

#endif
