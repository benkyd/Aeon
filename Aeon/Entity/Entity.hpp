#ifndef AEON_ENTITY_ENTITY_H_
#define AEON_ENTITY_ENTITY_H_

#include <Aeon/Includes.hpp>

namespace EC
{

template <typename T>
struct Entity
{
    T id;

    inline bool operator==( const Entity& rhs )
    {
        return rhs.id == id;    
    }

    inline bool operator!=( const Entity& rhs )
    {
        return rhs.id != id;
    }
};

}

#endif
