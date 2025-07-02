#include <Aeon/Aeon.hpp>
#include <Aeon/Core/Events.hpp>
#include <Aeon/Entity/CoreComponents/MaterialComponent.hpp>
#include <Aeon/Entity/CoreComponents/MeshComponent.hpp>
#include <Aeon/Entity/CoreComponents/Transform.hpp>
#include <Aeon/Entity/Entity.hpp>
#include <Aeon/Rendering/ImGui.hpp>
#include <iostream>
#include <thread>

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
        EC::Entity entity = GetEntityRegistry().create();
        GetEntityRegistry().emplace<EC::Transform>(entity, EC::Transform({0.0f, 0.0f, 0.0f}));
        GetEntityRegistry().emplace<EC::MeshComponent>(entity, EC::MeshComponent {});
        GetEntityRegistry().emplace<EC::MaterialComponent>(entity, EC::MaterialComponent {});

        Level* level = new Level;
        PushLayer((Core::GameLayer*)level);

        DebugLayer debug;
        PushDebugLayer(&debug);

        Run();
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
