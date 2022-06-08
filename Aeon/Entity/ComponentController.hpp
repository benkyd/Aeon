#ifndef AEON_ENTITY_COMPONENTCONTROLLER_H_
#define AEON_ENTITY_COMPONENTCONTROLLER_H_

#include <Aeon/Includes.hpp>


namespace EC
{

struct IComponentArr
{

};

template <typename TComponent>
struct ComponentArr : public IComponentArr
{

    void Destroy();
};

class ComponentController
{
public:
    ComponentController()
    {

    }
    ~ComponentController()
    {

    }

    template <typename TComponent>
    void Register()
    {
        const char* name = typeid(TComponent).name();
        std::cout << name << std::endl;
    }


private:
    std::map<std::string, IComponentArr>


};

}


#endif
