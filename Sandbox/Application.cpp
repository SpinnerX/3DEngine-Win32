#include <3DEngine/Core/Application.h>
#include <3DEngine/Core/EngineLogger.h>
#include <3DEngine/Core/EntryPoint.h>
#include <stdio.h>
#include <3DEngine/Events/KeyEvent.h>
#include <3DEngine/Events/InputPoll.h>
// #include "Engine3D/Image.h"
#include <imgui/imgui.h>

class ExampleLayer : public Engine3D::Layer{
public:
	ExampleLayer() : Engine3D::Layer("Layer #1"){}
	
	void onAttach() override {

	}

	void onDetach() override{

	}
	
	void onUpdate(float ts){
		if(Engine3D::InputPoll::isKeyPressed(ENGINE_KEY_ESCAPE)){
			coreLogInfo("Escape key called!\n");
			Engine3D::Application::Get().close();
		}
	}

	virtual void onUIRender() override {
	// 	ImGui::Begin("Settings");

	// 	ImGui::End();
	}
};

Engine3D::Application* Engine3D::CreateApplication(int argc, char** argv){
	// Engine3D::ApplicationSpecification spec;
	// spec.name = "Engine3D Example";
	// spec.width = 1900;
	// spec.height = 900;

	Engine3D::Application* app = new Engine3D::Application();
	app->pushLayer<ExampleLayer>();
	app->setMenuCallback([app](){
		if (ImGui::BeginMenu("File")){
			if (ImGui::MenuItem("Exit")){
				app->close();
			}
			
			ImGui::EndMenu();
		}
	});
	return app;
}