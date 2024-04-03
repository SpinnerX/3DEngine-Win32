#include <3DEngine/interfaces/Window.h>
#include <3DEngine/Core/EngineLogger.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>
#include <vulkan/vulkan.h>
#include <3DEngine/Events/KeyEvent.h>
#include <3DEngine/Events/MouseEvent.h>
#include <3DEngine/Events/AppEvent.h>

namespace Engine3D{
    Window* Window::instance = nullptr;

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

    void Window::onEvent(Event& event) {
        glfwPollEvents();
    }

    Window* Window::create(const WindowProperties& properties){
        return new Window(properties);
    }

    bool Window::isWindowClosing(){ return glfwWindowShouldClose(windowHandler); }

    void Window::initializeCore(){
        if(!glfwInit()){
            coreLogFatal("Did not initialize!");
            assert(false);
        }

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        int w=properties.width, h=properties.height;
        windowHandler = glfwCreateWindow(w, h, "Vulkan", nullptr, nullptr);

    }

    void Window::shutdown(){
        glfwDestroyWindow(windowHandler);
    }

    void setup(){}
};