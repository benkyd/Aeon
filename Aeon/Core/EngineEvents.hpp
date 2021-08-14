#ifndef AEON_CORE_ENGINEEVENTS_H_
#define AEON_CORE_ENGINEEVENTS_H_

/*
	- events are typed and system'd
	- systems can request to only receive events from a certain "system" category
	- systems that dispatch events can create the event and register it as a type
	- events are queued and non - blocking
	- events propagate through game layers top - to - bottom
		- once an event is flagged as handled by a receiving system,
		  it is discarded this is to prevent, say a "mouse click" 
		  from propagating from the UI layer to the game layer
*/

namespace Aeon::Core {

class GenericEvent
{

};

class EventDispatcher
{

};

}

#endif
