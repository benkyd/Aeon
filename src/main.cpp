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


		return true;
	}

};

int main( int argc, char** argv )
{
	Application app;
	if ( app.Construct( 700, 700, 1, 1, false ) )
		app.Start();
}
