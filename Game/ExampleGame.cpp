// simple raycast shooter
// shotgun fun fun yanno

#include <iostream>

#include <Aeon/Aeon.hpp>
#include <Aeon/Core/Events.hpp>

class Level : public Aeon::Core::GameLayer
{
public:
	Level() { }

	void Attach() override
	{

	}

	void FrameTick() override
	{

	}

	void TimeTick() override
	{

	}

	bool EventRecieved( Aeon::Core::GenericEvent& e ) override
	{

		return false;
	}

	void Detach() override
	{

	}
};

class TopLevel : public Aeon::Core::GameLayer
{
public:
	TopLevel() { }

	void Attach() override
	{

	}

	void FrameTick() override
	{

	}

	void TimeTick() override
	{

	}

	bool EventRecieved( Aeon::Core::GenericEvent& e ) override
	{

		return false;
	}

	void Detach() override
	{

	}
};

class ExampleGame : public Aeon::Core::App
{
public:

	// take command line args better (parse them first!)
	ExampleGame()
		: App( { "Example" },  { "Game with AEON!" } )
	{
		Level* level = new Level;
		TopLevel* topLevel = new TopLevel;
		PushLayer( (Aeon::Core::GameLayer*)level );
		PushLayer( (Aeon::Core::GameLayer*)topLevel );
		Run();
		delete level;
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
