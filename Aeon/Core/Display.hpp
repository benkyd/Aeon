#ifndef AEON_CORE_DISPLAY_H_
#define AEON_CORE_DISPLAY_H_

#include <string>

#include <SDL.h>
extern "C" {
#include <ThirdParty/glad.h>
}

#include "Aeon/Core/EngineConfig.hpp"
#include "Aeon/Core/Events.hpp"

class Rendering::Rendermaster;

namespace Core {

class Display : public EventListener
{
public:
    Display();
    ~Display();

    bool Create( const DisplayProperties& properties );

    const unsigned int GetWidth();
    const unsigned int GetHeight();

    const SDL_Window* GetWindow();
    const SDL_GLContext& GetContext();

    void SetClearColour( float r, float g, float b, float a = 1.0f );

    void EndFrame();

    void Destroy();

    bool EventRecieved( GenericEvent& e ) override;

private:
    SDL_Window* mWindow;
    SDL_GLContext mContext;



    unsigned int mWidth, mHeight;
    unsigned int mX, mY;
    float mClearColour[4];

private:
    Display( Display const& ) = delete;
    void operator=( Display const& ) = delete;
};

}

#endif
