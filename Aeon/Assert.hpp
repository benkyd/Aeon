#ifndef AEON_ASSERT_H_
#define AEON_ASSERT_H_

#include <Aeon/Includes.hpp>

#define AEON_ASSERT(x, m) \
    if (! (x)) { \
        std::cerr << "Assertion `" #x "` failed in " << __FILE__ \
            << " line " << __LINE__ << ": " << m << std::endl; \
        std::terminate(); \
    }
#define AEON_ASSERT_NO_BRK(x) \
    if (! (x)) { \
        std::cerr << "Assertion `" #x "` failed in " << __FILE__ \
            << " line " << __LINE__ << ": " << m << std::endl; \
    }

#endif
