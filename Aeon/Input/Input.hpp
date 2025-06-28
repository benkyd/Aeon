#ifndef AEON_INPUT_INPUT_H_
#define AEON_INPUT_INPUT_H_

#include <Aeon/Core/Events.hpp>
#include <Aeon/Includes.hpp>
#include <Aeon/Singleton.hpp>

namespace Input
{

// confusing name, not part of the ecs
// could be tho
class InputController : public Helpers::Singleton<InputController>
{
public:
    InputController();
    ~InputController();

    void PollInput();

private:
    void mPollDisplay();
    void mPollMouse();
    void mPollScroll();
    void mPollClick();
    void mPollKeyboard();
    void mPollScanKeyboard();

private:
    SDL_Event mEvent;

    int mNumScancodes = 242;
    const uint8_t* mKbdState;
    uint16_t mModKeyState = 0x0;

    Core::EventDispatcher mDisplayEventDispatcher;
    Core::EventDispatcher mKeyboardEventDispatcher;
    Core::EventDispatcher mMouseEventDispatcher;
};

} // namespace Input

#endif
