#include <iostream>

#include <glad/glad.h>

#ifdef _WIN32
#include <SDL.h>
#undef main
#elif UNIX
#include <SDL2/SDL.h>
#endif

#include "renderer.hpp"
#include "framebuffer.hpp"

void doInput( SDL_Event* e, bool& isWindowOpen );

struct Game
{
	int Width, Height;
	SDL_Window* Window = nullptr;
	SDL_GLContext GlContext = nullptr;
};

void GLAPIENTRY
MessageCallback( GLenum source,
	GLenum type,
	GLuint id,
	GLenum severity,
	GLsizei length,
	const GLchar* message,
	const void* userParam )
{
	std::cout << "GL CALLBACK: type = " << type
		<< ", severity = " << severity
		<< ", message = " << message << std::endl;

}

int main()
{

	SDL_Init( SDL_INIT_VIDEO );

	SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );
	SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8 );
	SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 );
	SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 8 );
	SDL_GL_SetAttribute( SDL_GL_BUFFER_SIZE, 32 );
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
	SDL_GL_SetAttribute( SDL_GL_MULTISAMPLEBUFFERS, 1 );

	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 4 );
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 4 );

	Game game;
	game.Width = 700; game.Height = 700;

	game.Window = SDL_CreateWindow( "2D Global Illumination",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		game.Width, game.Height,
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE );

	game.GlContext = SDL_GL_CreateContext( game.Window );

	if ( !game.GlContext )
	{
		std::cout << SDL_GetError() << std::endl;
		exit( 0 );
	}

	// Vsync
	SDL_GL_SetSwapInterval( 1 );

	// Time to actually load OpenGL
	gladLoadGLLoader( SDL_GL_GetProcAddress );

	glEnable( GL_DEBUG_OUTPUT );
	glDebugMessageCallback( MessageCallback, 0 );

	Renderer renderer;
	renderer.LoadShader();

	FrameBuffer framebuffer{ game.Width, game.Height };
	framebuffer.SetPixel( 1, 1, { 1.0, 0.0, 0.0 } );
	framebuffer.SetPixel( 2, 1, { 1.0, 0.0, 0.0 } );
	framebuffer.SetPixel( 3, 1, { 1.0, 0.0, 0.0 } );
	framebuffer.SetPixel( 4, 1, { 1.0, 0.0, 0.0 } );
	framebuffer.SetPixel( 5, 1, { 1.0, 0.0, 0.0 } );

	renderer.RegisterBuffer( &framebuffer, 0 );

	SDL_Event e;
	const float clearColour[] = { 186.0f / 255.0f, 214.0f / 255.0f, 254.0f / 255.0f };

	bool IsWindowOpen = true;
	while ( IsWindowOpen )
	{

		doInput( &e, IsWindowOpen );

		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
		glClearBufferfv( GL_COLOR, 0, clearColour );

		renderer.Render();

		SDL_GL_SwapWindow( game.Window );

	}

	return 0;

}

void doInput( SDL_Event* e, bool& isWindowOpen )
{
	Uint8* state = (Uint8*)SDL_GetKeyboardState( NULL );

	static bool IsMouseActive = false;

	while ( SDL_PollEvent( e ) ) {


		switch ( e->type ) {

			case SDL_KEYDOWN:
			{

				if ( e->key.keysym.sym == SDLK_ESCAPE ) {

					IsMouseActive = !IsMouseActive;

					if ( IsMouseActive )
						SDL_SetRelativeMouseMode( SDL_TRUE );
					else
						SDL_SetRelativeMouseMode( SDL_FALSE );

				}

				break;

			}

			case SDL_QUIT:
			{

				isWindowOpen = false;

				break;

			}

		}

	}

}
