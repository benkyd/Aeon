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
    mEntityCeiling++;
    uint32_t entityId = mEntityCeiling;
 
    Entity entity( { entityId } );
    mEntities.push( entity );
    return entity;
}

Entity EntityRegistry::Copy( const Entity entity )
{
    // look up everything, create a new entity and populate
    // with the components in the og entity

    return Entity( { 0 } );
}

Entity EntityRegistry::Destroy( Entity entity )
{
    auto id = entity.id;
    mEntities = std::move(n.back());          // move last element to removal location
    mEntities.pop_back();
}
