#pragma once
#include <3DEngine/Core/core.h>
#include <3DEngine/Core/Layer.h>
#include <vector>
#include <memory>
#include <imgui/imgui.h>
#include <vulkan/vulkan.h>
#include <functional>
#include <3DEngine/interfaces/Window.h>
#include <3DEngine/Events/Event.h>
#include <3DEngine/Events/AppEvent.h>

void check_vk_result(VkResult err);
struct GLFWwindow;
namespace Engine3D{

    struct ApplicationSpecification{
        std::string name = "MiniEngine";
        uint32_t width = 1600;
        uint32_t height = 900;
    };

    class ENGINE_API Application{
    public:
        Application(const ApplicationSpecification& specification = ApplicationSpecification());
        ~Application();

        static Application& Get();

        void Run();

        void setMenuCallback(const std::function<void()>& menuBarCallback){
            _menuBarCallback = menuBarCallback;
        }

        void pushLayer(Ref<Layer>& layer){
            _layerStack.emplace_back(layer);
            layer->onAttach();
        }

        template<typename T>
        void pushLayer(){
            static_assert(std::is_base_of<Layer, T>::value, "Pushed type was not a layer");
            _layerStack.emplace_back(Ref<T>())->onAttach();
        }
        
        void close();

        float getTime();

        GLFWwindow* getNativeWindow() const { return (GLFWwindow *)window->getNativeWindow(); }

        // static VkInstance GetInstance();
		// static VkPhysicalDevice GetPhysicalDevice();
		// static VkDevice GetDevice();

		// static VkCommandBuffer GetCommandBuffer(bool begin);
		// static void FlushCommandBuffer(VkCommandBuffer commandBuffer);

        static void submitResourceFree(std::function<void()>&& func);

        void onEvent(Event& event);

    private:
        void init();

        void shutdown();

    private:
        bool onWindowClose(WindowClosedEvent& e);

    private:
        static Application* instance;
        ApplicationSpecification _specifications;
        Ref<Window> window;
        bool isRunning = false;
        float m_TimeStep = 0.0f;
		float m_FrameTime = 0.0f;
		float m_LastFrameTime = 0.0f;

        std::vector<std::shared_ptr<Layer>> _layerStack;
        std::function<void()> _menuBarCallback;
    };

    Application* CreateApplication(int argc, char** argv);
};