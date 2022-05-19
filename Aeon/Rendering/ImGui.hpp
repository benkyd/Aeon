#ifndef AEON_RENDERING_IMGUI_H_
#define AEON_RENDERING_IMGUI_H_

#include <type_traits>

#include <SDL.h>
extern "C" {
#include <ThirdParty/glad.h>
}

#include <Aeon/ThirdParty/ImGui/imgui.h>
#include <Aeon/ThirdParty/ImGui/imgui_impl_sdl.h>
#include <Aeon/ThirdParty/ImGui/imgui_impl_opengl3.h>

namespace Rendering
{

inline void SetupImGui( const SDL_Window* window, const SDL_GLContext& context )
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	static ImGuiIO& io = ImGui::GetIO();

	ImGui::StyleColorsDark();
	ImGui_ImplSDL2_InitForOpenGL( const_cast<SDL_Window*>(window), context );
	ImGui_ImplOpenGL3_Init( "#version 450" );
}

inline void CleanupImGui()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();
}

}

#endif
