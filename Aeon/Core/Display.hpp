#ifndef AEON_CORE_DISPLAY_H_
#define AEON_CORE_DISPLAY_H_

#include <string>

#include <SDL.h>
extern "C" {
#include <ThirdParty/glad.h>
}

#include "Aeon/Core/Events.hpp"

namespace Aeon::Core {

struct DisplayProperties
{
	std::string Name;
	int Width, Height;
	bool VSync;

    DisplayProperties( std::string name, int width = 1200, int height = 900, bool vSync = true )
		: Name( name ),
		  Width( width ),
		  Height( height ),
		  VSync( vSync ) { }
};

class Display : public EventListener
{
public:
    Display();
    ~Display();

    bool Create( const DisplayProperties& properties );

    unsigned int GetWidth();
    unsigned int GetHeight();

    void Destroy();

    bool EventRecieved( GenericEvent& e ) override;

private:
    SDL_Window* mWindow;
    SDL_GLContext mContext;

    unsigned int mWidth, mHeight;
    unsigned int mX, mY;

private:
    Display( Display const& ) = delete;
    void operator=( Display const& ) = delete;
};

}

#endif
