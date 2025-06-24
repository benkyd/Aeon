#include <Aeon/Aeon.hpp>
#include <Aeon/Core/Events.hpp>
#include <Aeon/Entity/ComponentController.hpp>
#include <Aeon/Rendering/ImGui.hpp>
#include <iostream>

class BackgroundLevel : public Core::GameLayer
{
};

class Level : public Core::GameLayer
{
public:
    Level()
    {
        Core::EventManager::GetInstance().DebugPrint();
    }

    void Attach() override
    {
    }

    void FrameTick() override
    {
    }

    void TimeTick() override
    {
    }

    bool EventRecieved(Core::GenericEvent& e) override
    {
        return false;
    }

    void Detach() override
    {
    }
};

class DebugLayer : public Core::GameLayer
{
public:
    DebugLayer()
    {
    }

    void Attach() override
    {
    }

    void FrameTick() override
    {

        ImGui::Begin("Debug");

        ImGui::End();
    }

    void TimeTick() override
    {
    }

    bool EventRecieved(Core::GenericEvent& e) override
    {
        return false;
    }

    void Detach() override
    {
    }
};

class ExampleGame : public Core::App
{
public:
    ExampleGame()
        : App({"Example"}, {"Game with AEON!"})
    {
        // EC::EntityRegistry registry;
        //
        // EC::Entity entity1 = registry.Create();
        //
        // std::cout << "1: " << entity1 << std::endl;
        //
        // std::vector<EC::Entity> entities;
        //
        // for (int i = 0; i < 100; i++)
        // {
        // 	entities.push_back(registry.Create());
        // }
        //
        // std::cout << entities[entities.size()] << std::endl;
        //
        // for (int i = 0; i < 100; i++)
        // {
        // 	std::cout << "ENtity in vector pos " << i << " " << entities[i] << std::endl;
        // 	registry.Destroy(entities[i]);
        // }
        //
        // EC::Entity entity2 = registry.Create();
        // std::cout << "2: " << entity2 << std::endl;

        Level* level = new Level;
        PushLayer((Core::GameLayer*)level);
        DebugLayer* debug = new DebugLayer;
        PushDebugLayer(debug);
        Run();
        delete level;
    }

    ~ExampleGame()
    {
    }
};

int main(int argc, char** argv)
{
    ExampleGame game;

    return 0;
}
