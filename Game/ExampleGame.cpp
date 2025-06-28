#include <Aeon/Aeon.hpp>
#include <Aeon/Core/Events.hpp>
#include <Aeon/Entity/Entity.hpp>
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
        const auto entity = this->mEntityRegistry.create();
        entity.emplace<EC::Transform>();

        Level* level = new Level;

        PushLayer((Core::GameLayer*)level);
        PushDebugLayer(&debug);
        DebugLayer debug;
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
