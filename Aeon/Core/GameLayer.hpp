#ifndef AEON_CORE_GAMELAYER_H_
#define AEON_CORE_GAMELAYER_H_

#include <Aeon/Core/Events.hpp>
#include <Aeon/Entity/Entity.hpp>

namespace Core
{

class GameLayer : public EventListener
{
public:
    virtual void Attach() = 0;
    virtual void FrameTick() = 0;
    virtual void TimeTick() = 0;
    virtual void Detach() = 0;
};

} // namespace Core

#endif
