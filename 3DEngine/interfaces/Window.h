#pragma once
#include <3DEngine/Core/core.h>
#include <string>
#include <functional>
#include <3DEngine/Events/Event.h>
#include <optional>

class GLFWwindow;

namespace Engine3D{
    //! @note Setting the window properties to their default state
    struct WindowProperties{
        using EventCallbackFunc = std::function<void(Event& event)>;
        std::string title = "Engine3D";
        uint32_t width=1900, height=900;
        bool isVSyncEnabled = false;
        EventCallbackFunc callback;
    };

    /*!
        @class Window
        @note Used to interface with different rendering API's such as Vulkan or DirectX.
        @note Utilizing OpenGL's windowing system.

        @function Window::get()
        @note Extracts our windows instance
        @note We should only have one window instance
        @note Then how we handle games will vary on various layers.

        @function Window::getNativeWindow()
        @note Used for getting whatever native window that we specify.
    */
    class Window{
        using EventCallbackFn = WindowProperties::EventCallbackFunc;
    public:
        Window(const WindowProperties& properties = WindowProperties());
        virtual ~Window();

        static Window* create(std::string title="Engine3D", uint32_t w=1900, uint32_t h=900);

        virtual void* getNativeWindow();

        void onUpdate();

        static Window& get();

        bool getVSync() const;
        void setVSync(bool enabled);

        virtual uint32_t getWidth() const { return properties.width; };
        virtual uint32_t getHeight() const { return properties.height; };

        void setEventCallback(EventCallbackFn callback){ properties.callback = callback; }


    private:
        /**
         * @function initializeCore()
         * @note Used for cleanly initializing our windowing system
         * 
         * @functoin shutdownCleanup()
         * @note Handling cleanly ending out application (window cleanup, essentially)
        */
        void initializeWindowCore();

        void shutdownCleanup();

    private:
        GLFWwindow* windowHandler = nullptr;
        WindowProperties properties;
        static Window* instance;
        // std::function<void(Event& event)> callback;
    };
};