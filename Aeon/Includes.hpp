#ifndef AEON_INCLUDES_H_
#define AEON_INCLUDES_H_

// shut up

#ifdef __WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

extern "C" {
#include <glad.h>
}

#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <iomanip>
#include <tuple>
#include <map>
#include <optional>
#include <functional>
#include <queue>
#include <array>

#endif
