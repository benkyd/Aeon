cmake_minimum_required(VERSION 3.7)
project(AEON CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} CMakeModules/)
cmake_policy(SET CMP0037 OLD) # alow for spaces in file names

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

# set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_CXX_FLAGS "-Ofast")

# Adds RESOURCES constant in C++
add_definitions(-DRESOURCES="${CMAKE_SOURCE_DIR}/resources/")
message(${CMAKE_SOURCE_DIR}/resources)

set(exe out)

file(GLOB EngineSource
	Aeon/*.cpp
	Aeon/ThirdParty/*.cpp
	Aeon/Maths/*.cpp
)

#temp
file (GLOB GameSource
    Game/*.cpp
)

set(THREADS_PREFER_PTHREAD_FLAD ON)
find_package(Threads REQUIRED)

# Find GL and GLX package
find_package(OpenGL REQUIRED)

include_directories(".")
include_directories(${WinSDK})

add_executable(Aeon
    ${EngineSource} ${GameSource}
)

link_libraries(${exe}
    Threads::Threads
    OpenGL::OpenGL
    OpenGL::GL
    OpenGL::GLX
    ${WinSDK}
)
