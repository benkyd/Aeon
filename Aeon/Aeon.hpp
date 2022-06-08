#ifndef AEON_AEON_H_
#define AEON_AEON_H_

#include <Aeon/Includes.hpp>

#include <Aeon/Core/Display.hpp>
#include <Aeon/Core/Events.hpp>
#include <Aeon/Core/GameLayer.hpp>
#include <Aeon/Input/Input.hpp>
#include <Aeon/Entity/EntityController.hpp>

namespace Core 
{

// NOTE: Derivations / children of "App" cannot attatch
// event listeners to themselves, the programmer must
// first add a gamelayer to handle events

// App stores the GLOBAL gamestate
// It is OK to store this globally 
// every component needs to use state
class App : public EventListener
{
public:
	App( const AppProperties& props, const DisplayProperties& dispProps );

	void Run();

	const Display& GetDisplay();

	// Layers, once assigned, until poped are assumed to 
	// never change their spot in the layer hierarchy 
	void PushLayer( GameLayer* layer );
	void PushTopLayer( GameLayer* layer );
	void PushDebugLayer( GameLayer* layer );

	bool EventRecieved( GenericEvent& e ) override;

public:
	void PopLayer();
	void PopTopLayer();
	void PopDebugLayer();

private:
	Display mDisplay;

	EC::EntityRegistry mEntityController;
	Input::InputController& mInput;

	// Game layers from z order
	std::vector<GameLayer*> mGameLayers;
	std::vector<GameLayer*> mTopLayers;
	std::vector<GameLayer*> mDebugLayers;

private:
	bool mSIGTERM = false;

};

}

#endif
