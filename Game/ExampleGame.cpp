#include <iostream>

#include <Aeon/Aeon.hpp>
#include <Aeon/Core/Events.hpp>

class BackgroundLevel : public Core::GameLayer {

};

class Level : public Core::GameLayer
{
public:
	Level() 
	{
		Core::EventManager::GetInstance().DebugPrint();
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

	bool EventRecieved( Core::GenericEvent& e ) override
	{

		return false;
	}

	void Detach() override
	{

	}
};

class ExampleGame : public Core::App
{
public:
	ExampleGame()
		: App( { "Example" },  { "Game with AEON!" } )
	{
		Level* level = new Level;
		PushLayer( (Core::GameLayer*)level );
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
