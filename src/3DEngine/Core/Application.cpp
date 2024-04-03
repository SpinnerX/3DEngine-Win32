#include <3DEngine/Core/Application.h>
#include <3DEngine/Core/Timestep.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_vulkan.h>
/* #define GLFW_INCLUDE_NONE */
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <imgui/imgui.h>

namespace Engine3D{
    Application* Application::instance = nullptr;
    Application::Application(const std::string& name, ApplicationCommandLineArgs args){
        instance = this;
        isAppRunning = true;
        windowHandler = std::unique_ptr<Window>(Window::create());
        // windowHandler->setEventCallback(bind_function(this, &Application::onEvent));

        //! @note Setting up ImGui
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
		//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
        
        ImGui::StyleColorsDark();

		ImGuiStyle& style = ImGui::GetStyle();
		if(io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable){
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}

    }

    void Application::onUpdate(){
        // for(auto& layer : layerStack){
        //     layt
        // }
    }

    void Application::onEvent(Event& event){

    }

    void Application::Run(){

        while(!windowHandler->isWindowClosing() && isAppRunning){
            float time = (float)glfwGetTime(); // Should be in platform::getTime() (containing impl for Mac, Windows, etc.)
            Timestep timestep = time - lastFrameTime;
            lastFrameTime = time;

            for(auto& layer : layerStack){
                layer->onUpdate(timestep);
            }

            for(auto& layer : layerStack){
                layer->onUIRender();
            }

            windowHandler->onUpdate();
        }
    }

    Application& Application::Get() { return *instance; }

    void* Application::getNativeWindow() { return windowHandler->getNativeWindow(); }

    void Application::close(){
        isAppRunning = false;
    }
};