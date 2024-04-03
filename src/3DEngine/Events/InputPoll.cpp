#include <3DEngine/Events/InputPoll.h>
#include <3DEngine/Core/Application.h>
#include <GLFW/glfw3.h>

namespace Engine3D{
	bool InputPoll::isKeyPressed(KeyCode keycode){
		GLFWwindow* windowHandle = static_cast<GLFWwindow *>(Application::Get().getNativeWindow());
		int state = glfwGetKey(windowHandle, (int)keycode);

		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}
		
	bool InputPoll::isMouseButtonPressed(Engine3D::Mouse button){
		GLFWwindow* windowHandle = static_cast<GLFWwindow *>(Application::Get().getNativeWindow());
		int state = glfwGetMouseButton(windowHandle, (int)button);
		return state == GLFW_PRESS;
	}

	void InputPoll::setCursorMode(CursorMode mode){
		GLFWwindow* windowHandle = static_cast<GLFWwindow *>(Application::Get().getNativeWindow());
		glfwSetInputMode(windowHandle, GLFW_CURSOR, GLFW_CURSOR_NORMAL + (int)mode);
	}

	glm::vec2 InputPoll::getMousePosition(){
		GLFWwindow* windowHandle = static_cast<GLFWwindow *>(Application::Get().getNativeWindow());
		
		double x, y;
		glfwGetCursorPos(windowHandle, &x, &y);
		return {x, y};
	}
	
	float InputPoll::getMouseX(){
		return getMousePosition().x;
	}

	float InputPoll::getMouseY(){
		return getMousePosition().y;
	}
};