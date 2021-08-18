#include "Aeon/Core/Display.hpp"

#include <iostream>

#include "Aeon/Assert.hpp"

using Aeon::Core::Display;

Display::Display()
	: mWindow( nullptr )
	, mContext( NULL )
{
	RegisterAsSink( "ENGINE_DISPLAY_CORE", 0 );
}

Display::~Display()
{

}

bool Display::Create( const DisplayProperties& properties )
{
	SDL_Init( SDL_INIT_VIDEO );

	SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );
	SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8 );
	SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 );
	SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 8 );
	SDL_GL_SetAttribute( SDL_GL_BUFFER_SIZE, 32 );
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

	SDL_GL_SetAttribute( SDL_GL_MULTISAMPLEBUFFERS, 1 );
	SDL_GL_SetAttribute( SDL_GL_MULTISAMPLESAMPLES, 4 );

	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 4 );
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 5 );

	mWindow = SDL_CreateWindow( properties.Name.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, properties.Width, properties.Height,
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE );

	AEON_ASSERT( mWindow, "Can't initialise window" );

	mContext = SDL_GL_CreateContext( mWindow );

	AEON_ASSERT( mContext, "Can't initialise context" );

	SDL_GL_SetSwapInterval( static_cast<int>(!properties.VSync) );

	gladLoadGLLoader( SDL_GL_GetProcAddress );
	glEnable( GL_MULTISAMPLE );
	glCullFace( GL_BACK );
	glEnable( GL_DEPTH_TEST );

	mWidth = properties.Width;
	mHeight = properties.Height;

	return true;
}

unsigned int Display::GetWidth()
{
	return mWidth;
}

unsigned int Display::GetHeight()
{
	return mHeight;
}

void Display::Destroy()
{
	SDL_DestroyWindow( mWindow );
	// dangly balls
	mWindow = nullptr;
	mWidth = 0;
	mHeight = 0;
}

bool Display::EventRecieved( GenericEvent& e )
{
	return false;
}
