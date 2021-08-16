#ifndef AEON_CORE_EVENTS_H_
#define AEON_CORE_EVENTS_H_

/*
	- events are typed and system'd using a subscriber/publisher-esque observer pattern
	- systems can request to only receive events from a certain "system" category
	- systems that dispatch events can create the event and register it as a type
	- events are queued and non - blocking
	- events propagate through game layers top - to - bottom
		- once an event is flagged as handled by a receiving system,
		  it is discarded this is to prevent, say a "mouse click" 
		  from propagating from the UI layer to the game layer
*/

#include "Aeon/Singleton.hpp"

namespace Aeon::Core {

struct GenericEvent
{

};

struct Dispatcher
{

};

class EventListener
{
public:
	EventListener();
	virtual ~EventListener();
};

class EventManager : public Aeon::Helpers::Singleton<EventManager>
{
public:


	void RegisterDispatcher();

	void Dispatch( GenericEvent& e );
};

}

#endif
