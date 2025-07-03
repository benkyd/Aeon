#ifndef AEON_SCENE_H_
#define AEON_SCENE_H_

#include <Aeon/Entity/Entity.hpp>
#include <Aeon/Entity/CoreComponents/MaterialComponent.hpp>
#include <Aeon/Entity/CoreComponents/MeshComponent.hpp>
#include <Aeon/Entity/CoreComponents/Transform.hpp>

#include <Aeon/Includes.hpp>

class Scene
{
public:
    Scene();
    ~Scene();

    EC::Registry& GetEntityRegistry();
    inline std::vector<EC::Entity> GatherRenderables()
    {
        return mEntityRegistry.view<Transform, MeshComponent, MaterialComponent>();
    }

private:
    EC::Registry mEntityRegistry;
};

#endif
