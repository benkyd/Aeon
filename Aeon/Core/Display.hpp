#ifndef AEON_CORE_DISPLAY_H_
#define AEON_CORE_DISPLAY_H_

#include <string>

#include <SDL.h>
#include <ThirdParty/glad.h>

namespace Aeon::Core {

class DisplayProperties
{
public:
	std::string Name;
	int Width, Height;
	bool VSync;

    DisplayProperties( std::string name, int width = 1200, int height = 900, bool vSync = true )
		: Name( name ),
		  Width( width ),
		  Height( height ),
		  VSync( vSync ) { }
};

class Display
{
public:
    Display();
    ~Display();

    bool Create( const DisplayProperties& properties );

    unsigned int GetWidth();
    unsigned int GetHeight();

    void Destroy();

private:
    SDL_Window* mWindow;
    SDL_GLContext mContext;

    unsigned int mWidth, mHeight;

private:
    Display( Display const& ) = delete;
    void operator=( Display const& ) = delete;
};

}

#endif
