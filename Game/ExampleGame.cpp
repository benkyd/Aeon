// simple raycast shooter
// shotgun fun fun yanno

#include <iostream>

#include <Aeon/Aeon.hpp>
#include <Aeon/Core/Events.hpp>

class BackgroundLevel : public Aeon::Core::GameLayer {

};

class Level : public Aeon::Core::GameLayer
{
public:
	Level() 
	{ 
		PushThisAsSink("ENGINE_INPUT_KEYBOARD");
		Aeon::Core::EventManager::GetInstance().DebugPrint();
	}

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
		std::cout << "FROM LEVEL " << e.System << " " << (char)e.keyCode << std::endl;
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
		PushLayer( (Aeon::Core::GameLayer*)level );
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
