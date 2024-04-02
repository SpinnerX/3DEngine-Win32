#include <3DEngine/Core/Application.h>
#include <GLFW/glfw3.h>

namespace Engine3D{
	Application* Application::instance=  nullptr;

	Application::Application(const ApplicationSpecification& spcs){
		instance = this;
		isRunning = true;
		window = std::unique_ptr<Window>(Window::create());
		window->setEventCallback(bind_function(this, &Application::onEvent));
	}

	Application::~Application(){
	}

	void Application::Run(){
		while(isRunning){

			for(auto& layer : layerStack){
				layer->onUpdate(0.f);
			}

			for(auto& layer : layerStack){
				layer->onUIRender();
			}

			window->onUpdate();
		}
	}

	void Application::onEvent(Event& event){
		EventDispatcher dispatcher(event);

		dispatcher.Dispatch<WindowClosedEvent>(bind_function(this, &Application::onWindowClose));
	}

	void Application::close(){
		isRunning = false;
	}

	bool Application::onWindowClose(WindowClosedEvent& e){
		isRunning = false;
		return true;
	}

};