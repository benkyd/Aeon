#define OLC_PGE_APPLICATION
#include <olcPixelGameEngine.hpp>

class Application : public olc::PixelGameEngine
{
public:
	Application()
	{
		sAppName = "2D Global Illumination";
	}

	bool OnUserCreate() override
	{
		return true;
	}

	bool OnUserUpdate( float fElapsedTime ) override
	{
		for ( int x = 0; x < ScreenWidth(); x++ )
			for ( int y = 0; y < ScreenHeight(); y++ )
				Draw( x, y, olc::Pixel( x % 255, y % 255, rand() % 255 ) );

		return true;
	}

};

int main( int argc, char** argv )
{
	Application app;
	if ( app.Construct( 700, 700, 1, 1, false, true ) )
		app.Start();
}
