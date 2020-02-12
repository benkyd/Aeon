#define OLC_PGE_APPLICATION

#include "display.hpp"

#include <thread>
#include <chrono>

void EngineThread( Aeon::Display* disp )
{
	Aeon::DisplayBuff buf( 500, 500 );
	while ( true )
	{

		for ( int x = 0; x < 500; x++ )
		for ( int y = 0; y < 500; y++ )
			buf.Set( x, y, { (float)( rand() % 255 ) / 255.0f,
						  (float)( rand() % 255 ) / 255.0f,
						  (float)( rand() % 255 ) / 255.0f } );

		disp->NewFrame( &buf );

		static std::chrono::milliseconds dura( 10 );
		std::this_thread::sleep_for( dura );
	}
}

int main( int argc, char** argv )
{
	Aeon::Display display;

	display.Init( 500, 500 );
	display.SetTitle( "BRuh" );

	std::thread thread( EngineThread, &display );

	display.Start();

	thread.detach();
}
