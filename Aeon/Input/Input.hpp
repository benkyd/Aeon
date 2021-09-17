#ifndef AEON_INPUT_INPUT_H_
#define AEON_INPUT_INPUT_H_

#include <vector>

#include <SDL.h>

#include "Aeon/Singleton.hpp"
#include "Aeon/Core/Events.hpp"

namespace Aeon::Input {

class Input
{
public:
	Input();
	~Input();

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

	Aeon::Core::EventDispatcher mDisplayEventDispatcher;
	Aeon::Core::EventDispatcher mKeyboardEventDispatcher;
	Aeon::Core::EventDispatcher mMouseEventDispatcher;
};

}

#endif
