// simple raycast shooter
// shotgun fun fun yanno

#include "Aeon/Aeon.hpp"

class ExampleGame : public Aeon::Core::App 
{
public:

	// take command line args better (parse them first!)
	ExampleGame()
		: App( { "Game with AEON!" } )
	{
		Run();

	}

	~ExampleGame()
	{

	}

};

int main( int argc, char** argv )
{
    ExampleGame game;

    return 0;
}
