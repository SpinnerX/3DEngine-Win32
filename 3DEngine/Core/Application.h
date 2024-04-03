#pragma once
#include <3DEngine/Core/core.h>
#include <string>
#include <cassert>
#include <3DEngine/interfaces/Window.h>
#include <3DEngine/Core/LayerStack.h>

namespace Engine3D{
    struct ApplicationCommandLineArgs{
        int count = 0;
        char** args = nullptr;

        const char* operator[](int index) const {
            assert(index < count);
            return args[index];
        }
    };

    class Application{
    public:
        Application(const std::string& name = "Engine3D", ApplicationCommandLineArgs args = ApplicationCommandLineArgs());

        //! @note Client-functions that will be called to this specific instance.
        template<typename T>
        void pushLayer(){
            static_assert(std::is_base_of<Layer, T>::value, "Pushed type is not a layer which means it is invalid!");
            T* layer = new T();
            layer->onAttach();
            layerStack.pushLayer(layer);
        }

        void setMenuCallback(const std::function<void()>& callback){}

        static Application& Get();

        void onUpdate();
        void onEvent(Event& event);

        void Run();

        void* getNativeWindow();

        void close();

    private:
        static Application* instance;
        Ref<Window> windowHandler;

        bool isAppRunning = false;
        LayerStack layerStack;
        float lastFrameTime;
    };

    Application* CreateApplication(int argc, char** argv);
};