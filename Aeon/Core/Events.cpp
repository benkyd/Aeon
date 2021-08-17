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

}

EventDispatcher::~EventDispatcher()
{

}

void EventDispatcher::RegisterAsSource( std::string system )
{
	mDispatcherID = EventManager::GetInstance().RegisterSource(*this, system);
	AEON_ASSERT( mDispatcherID != -1, "Cannot register event source" );
}

void EventDispatcher::DeRegisterAsSource( std::string system )
{

}

void EventDispatcher::Dispatch( GenericEvent e )
{

}

void EventDispatcher::Dispatch( std::string data )
{

}


EventManager::EventManager()
{

}

EventManager::~EventManager()
{

}

int EventManager::RegisterSource( EventDispatcher& source, std::string system )
{
	int id = mNextHeighest;
	mSources[id] = system;

	mNextHeighest++;
	return id;
}

int EventManager::RegisterSink( EventListener& source, std::string system )
{
	return -1;
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
	
	for ( auto& listenerPair : sinks )
	{
		int handled = std::get<0>(listenerPair).EventRecieved(e);
		if ( handled ) e.Handled = handled;

		if ( e.Handled )
		{
			// destroy event
			break;
		}
	}
}
