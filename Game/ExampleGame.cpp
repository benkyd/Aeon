// simple raycast shooter

#include "Aeon/Aeon.hpp"

class ExampleGame : public Aeon::Core::App {
public:

	ExampleGame()
		: App( { "Game with AEON!" } )
	{

	}

	~ExampleGame() override
	{

	}

};

int main( int argc, char** argv )
{
	ExampleGame game;
}
