// simple raycast shooter
// shotgun fun fun yanno

#include <iostream>

#include <Aeon/Aeon.hpp>
#include <Aeon/Core/Events.hpp>

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

class SomeSystem : public Aeon::Core::EventListener
{
public:
	SomeSystem()
	{
		RegisterAsSink( "System1", 0 );
	}

	~SomeSystem() override
	{
		DeRegisterAsSink( "System1" );
	}

	bool EventRecieved( Aeon::Core::GenericEvent& e ) override
	{
		std::cout << e.Source << ":" << e.Type << ":" << e.Sink << ":" << e.Data << std::endl;
		return false;
	}

};

class SomeOtherSystem : public Aeon::Core::EventListener
{
public:
	SomeOtherSystem()
	{
		RegisterAsSink( "System1", 0 );
	}

	~SomeOtherSystem() override
	{
		DeRegisterAsSink( "System1" );
	}

	bool EventRecieved( Aeon::Core::GenericEvent& e ) override
	{
		std::cout << e.Source << ":" << e.Type << ":" << e.Sink << ":" << e.Data << std::endl;
		return false;
	}

};

int main( int argc, char** argv )
{
    ExampleGame game;

	SomeSystem system1;
	SomeOtherSystem system2;

	Aeon::Core::EventDispatcher eventDispatcher;
	eventDispatcher.RegisterAsSource( "System1" );
	eventDispatcher.Dispatch( "bro" );

    return 0;
}
