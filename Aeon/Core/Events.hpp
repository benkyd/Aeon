#ifndef AEON_CORE_EVENTS_H_
#define AEON_CORE_EVENTS_H_

/*
	- Events have a source and a sink, where from and where too
	- Event sinks are systems that events are dispatched to from 
		a source of the same system
	- Event listeners are layered, 0 is front, larger is back so 
		events propogate from the front to the back, not going 
		further once handled
	- Event sources can only dispatch events to a single system
	- Systems can request to only receive events from a certain 
		"system" category, or multiple
	- Events are blocking for now
*/

#include <string>
#include <tuple>
#include <vector>
#include <map>

#include "Aeon/Singleton.hpp"
#include "Aeon/Input/InputMap.hpp"

namespace Aeon::Core {

/*
* Engine event systems / type
* ENGINE_SYSTEM_CORE	- start, stop, pause, etc
*	ENGINE_START			- starts game loop execution
*	ENGINE_STOP
*	ENGINE_PAUSE
* ENGINE_DISPLAY_CORE	- window open, window close, etc
*	DISPLAY_RESIZE (x, y)	- rezise to x, y being new w, h
*	DISPLAY_MOVE (x, y)		- move to x, y
*	DISPLAY_SHOW			- no data
*	DISPLAY_HIDE			- no data
*	DISPLAY_MINIMISED		- no data
*	DISPLAY_MAXIMISED		- no data
*	DISPLAY_CLOSED			- no data
*	DISPLAY_MOUSE_ENTER		- no data
*	DISPLAY_MOUSE_LEAVE		- no data
*	DISPLAY_FOCUS			- no data
*	DISPLAY_OUT_OF_FOCUS	- no data
* ENGINE_INPUT_MOUSE
*	MOUSE_LEFT_DOWN			- no data
*	MOUSE_LEFT_UP			- no data
*	MOUSE_RIGHT_DOWN		- no data
*	MOUSE_RIGHT_UP			- no data
*	MOUSE_MIDDLE_DOWN		- no data
*	MOUSE_MIDDLE_UP			- no data
*	MOUSE_SCROLL			- y+-
*	MOUSE_MOVE				- move to x, y relative dx, dy
* ENGINE_INPUT_KEYBOARD
*	KEYBOARD_KEYDOWN		- keycode
*	KEYBOARD_KEYUP			- keycode
*	KEYBOARD_KEYPRESS		- keycode for continual pressing
*/


struct GenericEvent
{
	std::string System;
	std::string Type;
	
	// the rest can be empty
	// user defined
	std::string Data;
	// DISPLAY_RESIZE DISPLAY_MOVE MOUSE_MOVE
	int x, y;
	// MOUSE_MOVE
	int dx, dy;
	// KEYBOARD_KEYDOWN KEYBOARD_KEYUP KEYBOARD_PRESSED
	Aeon::Input::EKeyCode keyCode;

	bool Handled = false;
};

class EventListener
{
public:
	EventListener();
	virtual ~EventListener();

	void RegisterAsSink( std::string system, int layer = 0 );
	void DeRegisterAsSink( std::string system );

	void UpdateLayer( int layer );

	// return true = event handled
	virtual bool EventRecieved(GenericEvent& e) = 0;

private:
	int mListenerID = -1;

	friend class EventManager;
};

class EventDispatcher
{
public:
	EventDispatcher();
	EventDispatcher( std::string system );
	~EventDispatcher();

	void RegisterAsSource( std::string system );
	void DeRegisterAsSource( std::string system );

	void Dispatch( GenericEvent e );
	// no data needed
	void Dispatch( std::string type );

private:
	std::string mSystem;
	int mDispatcherID = -1;

	friend class EventManager;
};

class EventManager : public Aeon::Helpers::Singleton<EventManager>
{
public:
	EventManager();
	~EventManager();

	int RegisterSource( EventDispatcher* source, std::string system );
	int RegisterSink( EventListener* sink, std::string system );

	void RemoveSource( int dispatcherID, std::string system );
	void RemoveSink( int listenerID, std::string system );

	void Dispatch( int dispatcherID, GenericEvent e );
private:

	// indexed by listener ID
	std::map<int, const EventListener*> mListeners;
	// indexed by dispatcher ID
	std::map<int, std::string> mSources;
	// indexed by (sink) system ID
	// their position in the vector is their layer
	std::map<std::string, std::vector<std::tuple<EventListener*, int>>> mSinks;

	int mNextHeighest = 0;
};

}

#endif
