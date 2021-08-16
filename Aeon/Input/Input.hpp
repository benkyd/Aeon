#ifndef AEON_INPUT_INPUT_H_
#define AEON_INPUT_INPUT_H_

#include "Aeon/Singleton.hpp"

namespace Aeon::Input {

class Input : public Aeon::Helpers::Singleton<Input>
{
public:
	Input();
	~Input();

	void PollInput();
};

}

#endif
