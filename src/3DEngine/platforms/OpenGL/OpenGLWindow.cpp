#include <3DEngine/Core/Window.h>
#include <3DEngine/Core/EngineLogger.h>
#include <GLFW/glfw3.h>

namespace Engine3D{
    Window* Window::instance = nullptr;

    static bool setVSync(bool enabled){
        if(enabled){
            glfwSwapInterval(1);
        }
        else{
            glfwSwapInterval(0);
        }
        return enabled;
    }

    static void glfw_error_callback(int error, const char* description){
        coreLogFatal("GLFWError callback is saying error number \"{}\" description being \"{}\"", error, description);
    }

    Window::Window(const WindowProperties& properties){
        instance = this;
        initializeCore();
    }

    Window::~Window(){
        shutdown();
    }

    void Window::onUpdate(){
        glfwPollEvents();
    }

    void Window::onEvent(Event& event){}

    Window* Window::create(const WindowProperties& properties){
        return new Window(properties);
    }

    bool Window::isWindowClosing() { return glfwWindowShouldClose(windowHandler); }

    void Window::initializeCore(){
        coreLogInfo("Initializng OpenGL Window!");
        if(!glfwInit()){
            coreLogFatal("Could not initialize GLFW!");
            assert(false);
        }
        int w = properties.width, h = properties.height;
        windowHandler = glfwCreateWindow(w, h, properties.title.c_str(), nullptr, nullptr);

        if(!windowHandler){
            coreLogFatal("windowHandler is nullptr!");
            return;
        }

        glfwSetWindowUserPointer(windowHandler, &properties);

        properties.isVSyncEnabled = setVSync(true);
    }

    void Window::shutdown(){
        glfwDestroyWindow(windowHandler);
        glfwTerminate();
    }


};