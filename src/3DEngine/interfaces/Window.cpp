#include <3DEngine/interfaces/Window.h>
#include <GLFW/glfw3.h>
#include <cassert>
#include <3DEngine/Core/EngineLogger.h>
#include <3DEngine/Events/AppEvent.h>
#include <3DEngine/Events/KeyEvent.h>

namespace Engine3D{
    Window* Window::instance = nullptr;
    Window::Window(const WindowProperties& props) : properties(props){
        initializeWindowCore();
        instance = this;
    }

    Window::~Window(){
        shutdownCleanup();
    }

    Window* Window::create(std::string title, uint32_t w, uint32_t h){
        const WindowProperties properties = {.title = title, .width=w, .height=h};
        return new Window(properties);
    }

    void Window::initializeWindowCore(){
        coreLogInfo("Window Created ({} x {}), named = {}", properties.width, properties.height, properties.title);
        if(!glfwInit()){
            // static_assert(false, "glfwInit() not working!\n");
            coreLogError("glfwInit Failed!");
            assert(false);
        }

        windowHandler = glfwCreateWindow(properties.width, properties.height, properties.title.c_str(), nullptr, nullptr);

        if(!windowHandler){
            coreLogError("GLFWwindow* Failed!");
            assert(false);
        }

        // This is creating a WindowResizeEvent callback
        glfwSetWindowSizeCallback(windowHandler, [](GLFWwindow* window, int w, int h){
            WindowProperties& data =  *(WindowProperties *)glfwGetWindowUserPointer(window);
            data.width = w;
            data.height = h;

            // This is how we are going to be setting the callback from Application to event
            WindowResizedEvent event(w, h);
            data.callback(event);
        });

        // This is how we are dispatching the WindowCloseEvent callbacks to that specific event.
        glfwSetWindowCloseCallback(windowHandler, [](GLFWwindow* window){
            WindowProperties& data =  *(WindowProperties *)glfwGetWindowUserPointer(window);
            WindowClosedEvent event;
            data.callback(event);
        });

        // - A thing to NOTE is that at some point because this key code is GLFW-specific.
        // We should definitely convert the key code into our engines specific key code because on other platforms
        // - where we don't use GLFW key codes, and do not want to be tied to only using those GLFW key codes.
        // - To basically have our own.
        glfwSetKeyCallback(windowHandler, [](GLFWwindow* window, int key, int scancode, int action, int modes){
            WindowProperties& data =  *(WindowProperties *)glfwGetWindowUserPointer(window);

            // So when are doing a key call back the function takes in GLFWwindow, int, int, int
            //  action specified what action is occuring when with our key events, like are we pressing, releasing or repeating key events.
            // Event Usage: event(key, count) and for release is event(key)
            switch(action){
                case GLFW_PRESS:
                {
                    KeyPressedEvent event(static_cast<KeyCode>(key), 0);
                    data.callback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleasedEvent event(static_cast<KeyCode>(key));
                    data.callback(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressedEvent event(static_cast<KeyCode>(key), 1);
                    data.callback(event);
                    break;
                }
            }
        });
    }

    void Window::shutdownCleanup(){
        glfwDestroyWindow(windowHandler);
    }

    void* Window::getNativeWindow() { return windowHandler; }

    Window& Window::get(){ return *instance; }

    bool Window::getVSync() const { return properties.isVSyncEnabled; }

    void Window::setVSync(bool enabled){
        if(enabled){
            glfwSwapInterval(1);
        }
        else{
            glfwSwapInterval(0);
        }

        properties.isVSyncEnabled = enabled;
    }

    void Window::onUpdate(){
        glfwPollEvents();
        glfwSwapBuffers(windowHandler);
    }
};