#ifndef AEON_ENTITY_COMPONENTCONTROLLER_H_
#define AEON_ENTITY_COMPONENTCONTROLLER_H_

#include <Aeon/Includes.hpp>

struct Entity;

namespace EC
{

// I wish i diddn't have to do it like this
// someone fix this ahaha
struct IComponentContainer
{
    virtual ~IComponentContainer() = default;
    virtual void Create(const Entity) = 0;
    virtual void Destroy(const Entity) = 0;
};

template <typename TComponent>
struct ComponentContainer : public IComponentContainer
{
    ComponentContainer()
    {

    }


    void Destroy(const Entity) override
    {

    }

private:


};

class ComponentController
{
public:
    inline ComponentController()
    {

    }
    inline ~ComponentController()
    {

    }

    template <typename TComponent>
    inline void Register()
    {
        std::string componentTypeName = static_cast<std::string>(typeid(TComponent).name());
        std::cout << componentTypeName << std::endl;
    }


private:
    std::map<std::string, IComponentContainer> mComponentContainers;

};

}


#endif
