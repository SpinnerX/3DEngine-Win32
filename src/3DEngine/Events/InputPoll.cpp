#include <3DEngine/Events/InputPoll.h>
#include <3DEngine/Core/Application.h>
#include <GLFW/glfw3.h>

namespace Engine3D{
	InputPoll* InputPoll::instance = new InputPoll();

	bool InputPoll::isKeyPressedImpl(Key keycode){
		auto window = static_cast<GLFWwindow *>(Application::Get().getNativeWindow());

		auto state = glfwGetKey(window, static_cast<int32_t>(keycode));

		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool InputPoll::isMouseButtonPressedImpl(Mouse button){
		auto window = static_cast<GLFWwindow *>(Application::Get().getNativeWindow());

		auto state = glfwGetMouseButton(window, static_cast<int32_t>(button));

		return state == GLFW_PRESS;
	}

	float InputPoll::getMouseXImpl(){
		// auto[x, y] = getMousePositionImpl();
		return getMousePositionImpl().x;
	}

	float InputPoll::getMouseYImpl(){
		// auto[x, y] = getMousePositionImpl();
		return getMousePositionImpl().y;
	}

	glm::vec2 InputPoll::getMousePositionImpl(){
		auto window = static_cast<GLFWwindow *>(Application::Get().getNativeWindow());

		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		glm::vec2 position = {(float)xpos, (float)ypos};
		return position;
	}
};