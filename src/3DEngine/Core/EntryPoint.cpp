#include <3DEngine/Core/EntryPoint.h>
#include <3DEngine/Core/Application.h>
#include <3DEngine/Core/EngineLogger.h>
#include <3DEngine/Events/InputPoll.h>
using namespace Engine3D;

extern Engine3D::Application* Engine3D::CreateApplication(int argc, char** argv);
bool _applicationRunning = true;

namespace Engine3D{
    int Main(int argc, char** argv){
        Engine3D::Application* app = Engine3D::CreateApplication(argc, argv);
        app->Run();
        delete app;
        return 0;
    }
};
#ifdef WL_DIST

#include <Windows.h>

int APIENTRY main(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
	return Engine3D::Main(__argc, __argv);
}
#else
int main(int argc, char** argv){
    Engine3D::EngineLogger::Init();

    Engine3D::Application* app = Engine3D::CreateApplication(argc, argv);
    app->Run();
    delete app;
}
#endif