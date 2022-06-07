#include "Aeon/Core/Events.hpp"

#include "Aeon/Assert.hpp"

using Core::GenericEvent;
using Core::EventListener;
using Core::EventDispatcher;
using Core::EventManager;

// TODO: Events should use pre-allocated memory ALWAYS!
// TODO: Look into Bump Allocation

EventListener::EventListener()
{

}

EventListener::~EventListener()
{

}

void EventListener::PushThisAsSink( std::string system )
{
	mListenerID = EventManager::GetInstance().RegisterSinkPush( this, system );
	AEON_ASSERT( mListenerID != -1, "Cannot register event sink" );
}

void EventListener::PushAndStickThisAsSink( std::string system )
{
	mListenerID = EventManager::GetInstance().RegisterSinkPushStick( this, system );
	AEON_ASSERT( mListenerID != -1, "Cannot register event sink" );
}

void EventListener::UnshiftThisAsSink( std::string system )
{
	mListenerID = EventManager::GetInstance().RegisterSinkUnshift( this, system );
	AEON_ASSERT( mListenerID != -1, "Cannot register event sink" );
}

void EventListener::ShiftSinkLeft( std::string forSystem )
{
	EventManager::GetInstance().MoveSinkLeft( this, forSystem );
}

void EventListener::ShiftSinkRight( std::string forSystem )
{
	EventManager::GetInstance().MoveSinkRight( this, forSystem );
}

void EventListener::DeRegisterAsSink( std::string system )
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

int EventManager::RegisterSinkPush( EventListener* sink, std::string system )
{
	int id = mNextHeighest;
	mListeners[id] = sink;

	auto& sinkVector = mSinks[system];
	sinkVector.push_back( { sink, id } );

	mNextHeighest++;
	return id;
}

int EventManager::RegisterSinkPushStick( EventListener* sink, std::string system )
{
	int id = mNextHeighest;
	mListeners[id] = sink;

	auto& sinkVector = mStickySinks[system];
	sinkVector.push_back( { sink, id } );

	mNextHeighest++;
	return id;
}

int EventManager::RegisterSinkUnshift( EventListener* sink, std::string system )
{
	int id = mNextHeighest;
	mListeners[id] = sink;

	if ( !mSinks.count( system ) )
	{
		return RegisterSinkPush( sink, system );
	}

	auto& sinkVector = mSinks[system];
	sinkVector.insert( sinkVector.begin(), { sink, id } );

	mNextHeighest++;
	return id;
}

void EventManager::MoveSinkLeft( EventListener* sink, std::string system )
{

}

void EventManager::MoveSinkRight( EventListener* sink, std::string system )
{

}

void EventManager::RemoveSource( int dispatcherID, std::string system )
{

}

void EventManager::RemoveSink( int listenerID, std::string system )
{

}


// it is important to reverse the lists so that the dispatching is done correctly
// this is more efficiently done at insert... lol
template <typename C>
struct reverse_wrapper {

	C& c_;
	reverse_wrapper(C& c) : c_(c) {}

	typename C::reverse_iterator begin() { return c_.rbegin(); }
	typename C::reverse_iterator end() { return c_.rend(); }
};

template <typename C, size_t N>
struct reverse_wrapper< C[N] > {

	C(&c_)[N];
	reverse_wrapper(C(&c)[N]) : c_(c) {}

	typename std::reverse_iterator<const C*> begin() { return std::rbegin(c_); }
	typename std::reverse_iterator<const C*> end() { return std::rend(c_); }
};


template <typename C>
reverse_wrapper<C> r_wrap(C& c) {
	return reverse_wrapper<C>(c);
}

void EventManager::Dispatch( int dispatcherID, GenericEvent e )
{
	std::string targetSink = mSources[dispatcherID];
	auto stickySinks = mStickySinks[targetSink];
	auto sinks = mSinks[targetSink];

	if ( !stickySinks.empty() )
	{
		for ( auto& listenerPair : r_wrap(stickySinks))
		{
			EventListener* listener = std::get<0>( listenerPair );
			bool handled = listener->EventRecieved( e );
			if ( handled ) e.Handled = handled;

			if ( e.Handled )
			{
				// destroy event
				return;
			}
		}
	}

	if (!sinks.empty())
	{
		for (auto& listenerPair : r_wrap(sinks))
		{
			EventListener* listener = std::get<0>(listenerPair);
			bool handled = listener->EventRecieved(e);
			if (handled) e.Handled = handled;

			if (e.Handled)
			{
				// destroy event
				return;
			}
		}
	}
	
}

void EventManager::DebugPrint()
{
	std::cout << "----- BEGIN EVENTS DEBUG -----" << std::endl;
	for (auto const& [dispatcher, targetSink] : mSources)
	{
		auto stickySinks = mStickySinks[targetSink];
		auto sinks = mSinks[targetSink];

		int sourceCount = 0;
		for (auto const& [id, source] : mSources)
			if (source == targetSink) sourceCount++;

		std::cout << targetSink << " has " << stickySinks.size() << " sticky and " << sinks.size() << " sink(s) and is being dispatched from " << sourceCount << " different source(s)" << std::endl;
	}
	std::cout << "----- END EVENTS DEBUG -----" << std::endl;
}
