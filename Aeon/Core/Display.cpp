#include "Display.hpp"

#include <Aeon/Assert.hpp>
#include <Aeon/Includes.hpp>
#include <Aeon/Rendering/ImGui.hpp>
#include <yolo/yolo.hpp>

using Core::Display;

Display::Display()
    : mWindow(nullptr), mContext(NULL), mClearColour {1.0f, 1.0f, 1.0f, 1.0f}
{
    mYoloModule = yolo::registerModule("DISPLAY", "\e[0;33m");
    PushThisAsSink("ENGINE_DISPLAY_CORE");
}

Display::~Display()
{
}

bool Display::Create(const DisplayProperties& properties)
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);

    mWindow = SDL_CreateWindow(properties.Name.c_str(),
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               properties.Width,
                               properties.Height,
                               SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    AEON_ASSERT(mWindow, "Can't initialise window");

    mContext = SDL_GL_CreateContext(mWindow);

    AEON_ASSERT(mContext, "Can't initialise context");

    SDL_GL_SetSwapInterval(static_cast<int>(!properties.VSync));

    gladLoadGLLoader(SDL_GL_GetProcAddress);
    glEnable(GL_MULTISAMPLE);
    glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);

    mWidth = properties.Width;
    mHeight = properties.Height;

    Rendering::SetupImGui(mWindow, mContext);

    // Make sure ImGUI is ready to be used on the first frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    return true;
}

const unsigned int Display::GetWidth()
{
    return mWidth;
}

const unsigned int Display::GetHeight()
{
    return mHeight;
}

const SDL_Window* Display::GetWindow()
{
    return mWindow;
}

const SDL_GLContext& Display::GetContext()
{
    return mContext;
}

void Display::SetClearColour(float r, float g, float b, float a)
{
    mClearColour[0] = r * a;
    mClearColour[1] = g * a;
    mClearColour[2] = b * a;
    mClearColour[3] = a;
}

void Display::EndFrame()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    SDL_GL_SwapWindow(mWindow);

    glClearColor(mClearColour[0], mClearColour[1], mClearColour[2], mClearColour[3]);
    glClear(GL_COLOR_BUFFER_BIT);

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();
}

void Display::Destroy()
{
    Rendering::CleanupImGui();
    SDL_DestroyWindow(mWindow);
    // dangly balls
    mWindow = nullptr;
    mWidth = 0;
    mHeight = 0;
}

bool Display::EventRecieved(GenericEvent& e)
{
    yolo::info(mYoloModule, "Recieved Event {}", e.Type.c_str());

    if (e.Type == "DISPLAY_RESIZE")
    {
        mWidth = e.x;
        mHeight = e.y;
        return true;
    }

    if (e.Type == "DISPLAY_MOVE")
    {
        mX = e.x;
        mY = e.y;
        return true;
    }

    return false;
}
