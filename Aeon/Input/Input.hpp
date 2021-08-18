#ifndef AEON_INPUT_INPUT_H_
#define AEON_INPUT_INPUT_H_

#include <SDL.h>

#include "Aeon/Singleton.hpp"

namespace Aeon::Input {



class Input
{
public:
	Input();
	~Input();

	void PollInput();
private:
	SDL_Event mEvent;
};

}

#endif
