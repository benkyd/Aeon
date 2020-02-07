# Cmake OwO

cmake_minimum_required(VERSION 3.7)
project(AEON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} CMakeModules/)
cmake_policy(SET CMP0037 OLD) # alow for spaces in file names

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_CXX_FLAGS "-Ofast")

set(exe output)
set(src ./src)
set(include ./include)

# Adds RESOURCES constant in C++
add_definitions(-DRESOURCES="${CMAKE_SOURCE_DIR}/resources/")
message(${CMAKE_SOURCE_DIR}/resources)

file(GLOB src 
	${src}/*
)

set(THREADS_PREFER_PTHREAD_FLAD ON)
find_package(Threads REQUIRED)

# Find GL and GLX package
find_package(OpenGL REQUIRED)

include_directories(${include})


if (UNIX)
    find_package(X11 REQUIRED)
    find_package(PNG REQUIRED)
    include_directories(${PNG_INCLUDE_DIR})
endif (UNIX)

if (WIN32)
    include_directories(${WinSDK})
endif (WIN32)

add_executable(${exe} 
    ${src}
)

link_libraries(${exe}
    Threads::Threads
    OpenGL::OpenGL
    OpenGL::GL
    OpenGL::GLX
)

if (UNIX) 
    link_libraries(${exe} 
        ${X11_LIBRARIES}
        PNG::PNG
    )
endif (UNIX)

if (WIN32)
    link_libraries(${exe} 
        ${WinSDK}
    )
endif (WIN32)
