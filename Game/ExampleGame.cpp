// simple raycast shooter
// shotgun fun fun yanno

#include <iostream>

#include <Aeon/Aeon.hpp>
#include <Aeon/Core/Events.hpp>

class BottomestLevel : public Aeon::Core::GameLayer
{
public:
	BottomestLevel()
	{
		UnshiftThisAsSink("GAME_LOL");
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

	bool EventRecieved(Aeon::Core::GenericEvent& e) override
	{
		std::cout << "FROM BOTTOMESTLEVEL " << e.System << " " << e.Type << " " << e.Data << std::endl;
		return false;
	}

	void Detach() override
	{

	}
};


class BottomLevel : public Aeon::Core::GameLayer
{
public:
	BottomLevel()
	{
		PushThisAsSink("GAME_LOL");
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

	bool EventRecieved(Aeon::Core::GenericEvent& e) override
	{
		std::cout << "FROM BOTTOMLEVEL " << e.System << " " << e.Type << " " << e.Data << std::endl;
		return false;
	}

	void Detach() override
	{

	}
};

class Level : public Aeon::Core::GameLayer
{
public:
	Level() 
	{ 
		mEventDispatcher.RegisterAsSource("GAME_LOL");
		PushThisAsSink("GAME_LOL");
		Aeon::Core::EventManager::GetInstance().DebugPrint();
	}

	void Attach() override
	{

	}

	void FrameTick() override
	{
		mEventDispatcher.Dispatch("Lmao gottem");

	}

	void TimeTick() override
	{

	}

	bool EventRecieved( Aeon::Core::GenericEvent& e ) override
	{
		std::cout << "FROM LEVEL " << e.System << " " << e.Type << " " << e.Data << std::endl;
		return false;
	}

	void Detach() override
	{

	}

	Aeon::Core::EventDispatcher mEventDispatcher;

};

class TopLevel : public Aeon::Core::GameLayer
{
public:
	TopLevel() 
	{ 
		PushAndStickThisAsSink("GAME_LOL");
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
		std::cout << "FROM TOPLEVEL " << e.System << " " << e.Type << " " << e.Data << std::endl;
		return false;
	}

	void Detach() override
	{

	}
};

class ToperLevel : public Aeon::Core::GameLayer
{
public:
	ToperLevel() 
	{
		PushAndStickThisAsSink("GAME_LOL");
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

	bool EventRecieved(Aeon::Core::GenericEvent& e) override
	{
		std::cout << "FROM TOPERLEVEL " << e.System << " " << e.Type << " " << e.Data << std::endl;
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
		BottomestLevel* bottomestLevel = new BottomestLevel;
		BottomLevel* bottomLevel = new BottomLevel;
		Level* level = new Level;
		TopLevel* topLevel = new TopLevel;
		ToperLevel* toperLevel = new ToperLevel;
		PushLayer( (Aeon::Core::GameLayer*)bottomestLevel );
		PushLayer( (Aeon::Core::GameLayer*)bottomLevel );
		PushLayer( (Aeon::Core::GameLayer*)level );
		PushLayer( (Aeon::Core::GameLayer*)topLevel );
		PushLayer( (Aeon::Core::GameLayer*)toperLevel);
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
