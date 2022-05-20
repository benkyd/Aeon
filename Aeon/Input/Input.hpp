#ifndef AEON_INPUT_INPUT_H_
#define AEON_INPUT_INPUT_H_

#include <vector>

#include <SDL.h>

#include "Aeon/Singleton.hpp"
#include "Aeon/Core/Events.hpp"

namespace Input {

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

}

#endif
