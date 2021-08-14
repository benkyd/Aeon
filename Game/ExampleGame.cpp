// simple raycast shooter
// shotgun fun fun yanno

#include "Aeon/Aeon.hpp"

class ExampleGame : public Aeon::Core::App 
{
public:

	// take command line args better (parse them first!)
	ExampleGame( int argc, char** argv )
		: App( { "Game with AEON!" } )
	{

	}

	~ExampleGame() override
	{

	}

};

int main( int argc, char** argv )
{
	ExampleGame game(argc, argv);
}
