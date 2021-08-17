#ifndef AEON_CORE_EVENTS_H_
#define AEON_CORE_EVENTS_H_

/*
	- Events have a source and a sink, where from and where too
	- Event sinks are systems that events are dispatched to from 
		a source of the same system
	- Event listeners are layered, 0 is front, larger is back so 
		events propogate from the front to the back, not going 
		further once handled
	- Systems can request to only receive events from a certain 
		"system" category, or multiple
	- Events are blocking for now
*/

#include <string>
#include <tuple>
#include <vector>
#include <map>

#include "Aeon/Singleton.hpp"

namespace Aeon::Core {

struct GenericEvent
{
	std::string Source;
	std::string Sink;
	std::string Type;
	std::string Data;
	bool Handled = false;

	GenericEvent() { }
};

struct KeyboardEvent : public GenericEvent
{
	int KeyCode;
	int KeyStatus;

	KeyboardEvent( int keyCode, int keyStatus )
		: GenericEvent()
		, KeyCode(keyCode)
		, KeyStatus(keyStatus) { }
};

class EventListener
{
public:
	EventListener();
	virtual ~EventListener();

	void RegisterAsSink( std::string system, int layer );
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
	void Dispatch( std::string data );

private:
	int mDispatcherID = -1;

	friend class EventManager;
};

class EventManager : public Aeon::Helpers::Singleton<EventManager>
{
public:
	EventManager();
	~EventManager();

	int RegisterSource( EventDispatcher& source, std::string system );
	int RegisterSink( EventListener& sink, std::string system );

	void RemoveSource( int dispatcherID, std::string system );
	void RemoveSink( int listenerID, std::string system );

	void Dispatch( int dispatcherID, GenericEvent e );
private:

	// indexed by listener ID
	std::map<int, EventListener&> mListeners;
	// indexed by dispatcher ID
	std::map<int, std::string> mSources;
	// indexed by (sink) system ID
	// their position in the vector is their layer
	std::map<std::string, std::vector<std::tuple<EventListener&, int>>> mSinks;

	int mNextHeighest = 0;
};

}

#endif
