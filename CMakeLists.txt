cmake_minimum_required(VERSION 3.7)
project(AEON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeModules/")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

set(THREADS_PREFER_PTHREAD_FLAD ON)
find_package(Threads REQUIRED)

# Find GL and GLX package
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)

# Adds RESOURCES constant in C++
add_definitions(-DRESOURCES="${CMAKE_SOURCE_DIR}/resources/")
message(${CMAKE_SOURCE_DIR}/resources)

set(Aeon Aeon)

file(GLOB EngineSource
	Aeon/*.cpp
    Aeon/Core/*.cpp
	Aeon/Debug/*.cpp
	Aeon/Entity/*.cpp
	Aeon/Entity/CoreComponents/*.cpp
    Aeon/Input/*.cpp
	Aeon/Maths/*.cpp
	Aeon/Rendering/*.cpp
    ThirdParty/*.cpp
    ThirdParty/*.c
    ThirdParty/ImGui/*.cpp
)

#temp
file(GLOB GameSource
    Game/*.cpp
)

include_directories(${Aeon}
    "."
    "ThirdParty/"
    "ThirdParty/glm/"
    "ThirdParty/entt/src/"
    "ThirdParty/assimp/"
    "ThirdParty/Yolo/include"
    ${WinSDK}
    ${SDL2_INCLUDE_DIRS}
)

add_executable(${Aeon}
    ${EngineSource}
    ${GameSource}
)

add_subdirectory("ThirdParty/assimp")

target_link_libraries(${Aeon}
    ${WinSDK}
    ${SDL2_LIBRARIES}
    Threads::Threads
    OpenGL::GL
    assimp
)
