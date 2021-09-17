#include "Aeon/Core/Events.hpp"

#include "Aeon/Assert.hpp"

using Aeon::Core::GenericEvent;
using Aeon::Core::EventListener;
using Aeon::Core::EventDispatcher;
using Aeon::Core::EventManager;

EventListener::EventListener()
{

}

EventListener::~EventListener()
{

}

void EventListener::RegisterAsSink( std::string system, int layer )
{
	mListenerID = EventManager::GetInstance().RegisterSink( this, system );
	AEON_ASSERT( mListenerID != -1, "Cannot register event sink" );
}

void EventListener::DeRegisterAsSink( std::string system )
{

}

void EventListener::UpdateLayer( int layer )
{

}


EventDispatcher::EventDispatcher()
{

}

EventDispatcher::EventDispatcher( std::string system )
{
	RegisterAsSource( system );
}

EventDispatcher::~EventDispatcher()
{

}

void EventDispatcher::RegisterAsSource( std::string system )
{
	mDispatcherID = EventManager::GetInstance().RegisterSource( this, system );
	AEON_ASSERT( mDispatcherID != -1, "Cannot register event source" );
	mSystem = system;
}

void EventDispatcher::DeRegisterAsSource( std::string system )
{

}

void EventDispatcher::Dispatch( GenericEvent e )
{
	e.System = mSystem;
	EventManager::GetInstance().Dispatch( mDispatcherID, e );
}

void EventDispatcher::Dispatch( std::string type )
{
	GenericEvent e;
	e.Type = type;
	e.System = mSystem;
	EventManager::GetInstance().Dispatch( mDispatcherID, e );
}


EventManager::EventManager()
{

}

EventManager::~EventManager()
{

}

int EventManager::RegisterSource( EventDispatcher* source, std::string system )
{
	int id = mNextHeighest;
	mSources[id] = system;
	mNextHeighest++;
	return id;
}

int EventManager::RegisterSink( EventListener* sink, std::string system )
{
	int id = mNextHeighest;
	mListeners[id] = sink;

	// if there is no sinks for the system, make sure there is one
	if ( !mSinks.count( system ) )
	{
		std::vector<std::tuple<EventListener*, int>> v;
		mSinks.insert( { system, v } );
	}

	auto& sinkVector = mSinks[system];
	sinkVector.push_back( { sink, id } );

	mNextHeighest++;
	return id;
}

void EventManager::RemoveSource( int dispatcherID, std::string system )
{

}

void EventManager::RemoveSink( int listenerID, std::string system )
{

}

void EventManager::Dispatch( int dispatcherID, GenericEvent e )
{
	std::string targetSink = mSources[dispatcherID];
	auto sinks = mSinks[targetSink];

	if ( sinks.empty() )
	{
		return;
	}
	
	for ( auto& listenerPair : sinks )
	{
		EventListener* listener = std::get<0>( listenerPair );
		bool handled = listener->EventRecieved(e);
		if ( handled ) e.Handled = handled;

		if ( e.Handled )
		{
			// destroy event
			break;
		}
	}
}
