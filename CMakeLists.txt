# Cmake OwO

cmake_minimum_required(VERSION 3.7)
project(2D_GLOBAL_ILLUMINATION)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} CMakeModules/)
cmake_policy(SET CMP0037 OLD) # alow for spaces in file names

set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_CXX_FLAGS "-Ofast")

set(exe output)
set(src ./src)
set(include ./include)

# Adds RESOURCES constant in C++
add_definitions(-DRESOURCES="${CMAKE_SOURCE_DIR}/resources/")
message(${CMAKE_SOURCE_DIR}/resources)

if (UNIX)
	find_package(SDL2 REQUIRED)
endif(UNIX)

if (WIN32)
	include_directories(${exe}
		"C:/dev/SDL2/include/"
	)
endif (WIN32)


set(THREADS_PREFER_PTHREAD_FLAD ON)
find_package(Threads REQUIRED)
find_package(OpenGL REQUIRED)

if (UNIX)
	include_directories(${exe}
		${SDL2_INCLUDE_DIR}
	)
endif (UNIX)

include_directories(${exe}
	${include}
)

file(GLOB src 
	${src}/*
	${src}/util/*
	${src}/thirdparty/*
)

add_executable(${exe} ${src})

set_target_properties(${exe} PROPERTIES
	CXX_STANDARD 17
	CXX_EXTENSIONS OFF
)

if (UNIX)
	target_link_libraries(${exe}
		SDL2
		OpenGL::OpenGL
		OpenGL::GL
		Threads::Threads
	)
endif (UNIX)

if (WIN32)
	target_link_libraries(${exe}
		${WinSDK}
		"C:/dev/SDL2/lib/x64/SDL2.lib"
		"C:/dev/SDL2/lib/x64/SDL2main.lib"
		"C:/dev/SDL2/lib/x64/SDL2test.lib"
	)
endif (WIN32)

target_link_libraries(${exe}
	${CMAKE_DL_LIBS}
)
