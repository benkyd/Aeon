#ifndef AEON_ENTITY_ENTITYCONTROLLER_H_
#define AEON_ENTITY_ENTITYCONTROLLER_H_

#include <Aeon/Includes.hpp>

#include <Aeon/Entity/Entity.hpp>

namespace EC
{

// TODO: Entities space in memory should be pre-allocated
// using the engine's lifecycle bump allocator
class EntityRegistry
{
public:
    EntityRegistry();
    ~EntityRegistry();

    Entity Create()
    Entity Copy( const Entity entity );
    void Destroy( Entity entity );
    bool Valid(const Entity entity);

    // add, replace components
    template <typename TComponent>
    TComponent& Add(const Entity entity);

    template <typename TComponent>
    TComponent& Replace(const Entity entity);
    
    // replace in-place
    template <typename TComponent>
    TComponent& Patch(const Entity entity);

    // Get component from entity based on T
    template <typename TComponent>
    TComponent& Get(const Entity entity);
    
    // Get std::optional from entity based on T
    template <typename TComponent>
    std::optional<TComponent&> Opt(const Entity entity);

    // TODO: Sort by component properties, for example list of
    // entities with the renderable components, sorted by Y pos
    // of position component
    // template <typename T> 
    // std::vector<T&> Sort(std::function<;

private:
    uint32_t mEntityCeiling = 0;

    // On destroy, the last entity is moved to the position
    // of the old entity for cache coherency
    std::map<Entity, std::vector<std::string>> mEntities

};
    
}

#endif
