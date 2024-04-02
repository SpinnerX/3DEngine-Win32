#include <3DEngine/Core/Application.h>
#include <3DEngine/Core/EngineLogger.h>
#include <3DEngine/Core/EntryPoint.h>
#include <stdio.h>
#include <3DEngine/Events/KeyEvent.h>

// #include "Engine3D/Image.h"

class ExampleLayer : public Engine3D::Layer{
public:
	void onAttach() override {

	}

	void onDetach() override{

	}
	
	void onUpdate(float ts){

	}

	virtual void onUIRender() override{
		// printf("Running onUIRender()!\n");
		// ImGui::Begin("Hello");
		// ImGui::Button("Button");
		// ImGui::End();

		// ImGui::ShowDemoWindow();
	}
};

Engine3D::Application* Engine3D::CreateApplication(int argc, char** argv){
	Engine3D::ApplicationSpecification spec;
	spec.name = "Engine3D Example";
	spec.width = 1900;
	spec.height = 900;

	Engine3D::Application* app = new Engine3D::Application(spec);
	// app->pushLayer<ExampleLayer>();
	// app->setMenuCallback([app](){
	// 	if (ImGui::BeginMenu("File")){
	// 		if (ImGui::MenuItem("Exit")){
	// 			app->close();
	// 		}
			
	// 		ImGui::EndMenu();
	// 	}
	// });
	return app;
}