#include "EntityController.hpp"

using namespace EC;


EntityRegistry::EntityRegistry()
{

}

EntityRegistry::~EntityRegistry()
{

}

Entity EntityRegistry::Create()
{
    uint32_t entityId;
    if ( mFreedEntities.empty() )
    {
        mEntityCeiling++;
        entityId = mEntityCeiling;
    } 
    else 
    {
        mFreedEntities.pop();
    }

    mEntities[entityId] = std::vector<std::string>();
    return entityId;
}

Entity Copy( const Entity& entity )
{
    // look up everything, create a new entity and populate
    // with the components in the og entity

    return static_cast<uint32_t>( 0 );
}

void EntityRegistry::Destroy( Entity entity )
{
    if ( !this->Valid( entity ) ) return;
    mFreedEntities.push(entity);
    mEntities.erase(entity);
}

bool EntityRegistry::Valid( const Entity entity )
{
    return mEntities.find(entity) != mEntities.end();
}
