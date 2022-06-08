#include <iostream>

#include <Aeon/Aeon.hpp>
#include <Aeon/Core/Events.hpp>
#include <Aeon/Rendering/ImGui.hpp>

#include <Aeon/Entity/ComponentController.hpp>

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

class DebugLayer : public Core::GameLayer 
{
public:
	DebugLayer() 
	{
	
	}

	void Attach() override
	{

	}

	void FrameTick() override
	{

		ImGui::Begin( "Debug" );

		ImGui::End();

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
		DebugLayer* debug = new DebugLayer;
		PushDebugLayer( debug );
		Run();
		delete level;
	}

	~ExampleGame()
	{

	}

};


struct GenericComponent
{
	int x,y;
};

int main( int argc, char** argv )
{
	EC::ComponentController cController;

	cController.Register<GenericComponent>();
    ExampleGame game;

    return 0;
}
