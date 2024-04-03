#pragma once
#include <3DEngine/Core/core.h>
#include <string>
#include <functional>
#include <3DEngine/Events/Event.h>
#include <3DEngine/Core/LayerStack.h>

class GLFWwindow;
namespace Engine3D{
    struct WindowProperties{
        using EventCallbackFunc = std::function<void(Event& event)>;
        WindowProperties(const std::string& name = "Engine3D", uint32_t w = 1600, uint32_t h = 900) : title(name), width(w), height(h) {}

        std::string title;
        uint32_t width, height;
        bool isVSyncEnabled = false; //! @note vsync is default to disabled.
        EventCallbackFunc callback;
    };

    /**
     * @name Window
     * @note Will have different implementations
     * @note 
     * 
     * 
     * 
    */
    class ENGINE_API Window{
        Window(const WindowProperties& properties);
    public:
        using EventCallbackFn = WindowProperties::EventCallbackFunc;

        ~Window();

        //! @note Updating our window instance.
        void onUpdate();

        //! @note updating out events being handled.
        void onEvent(Event& event);

        uint32_t getWidth() const { return properties.width; }

        uint32_t getHeight() const { return properties.height; }

        void* getNativeWindow() const { return windowHandler; }

        static Window* create(const WindowProperties& properties = WindowProperties());
        bool isWindowClosing();
        void setEventCallback(EventCallbackFn fn) { properties.callback = fn;}

        template<typename T>
        void pushLayer(){
            static_assert(std::is_base_of<Layer, T>::value, "Is not a layer type!");

            T* layer = new T();
            layer->onAttach();
            layerStack.pushLayer(layer);
        }
    private:
        //! @note Initializing our core API's
        void initializeCore();

        //! @note Helper function to make sure we close our application cleanly.
        void shutdown();

    private:
        void setup();

    private:
        GLFWwindow* windowHandler;
        WindowProperties properties;
        static Window* instance;
        LayerStack layerStack;
    };
};