#pragma once
#include <3DEngine/Core/core.h>
#include <glm/glm.hpp>
#include <Events/KeyEvent.h>
#include <Events/MouseButtonCodes.h>
#include <Events/CursorCodes.h>

namespace Engine3D{
    class ENGINE_API InputPoll{
	public:

        static bool isKeyPressed(KeyCode keycode);
		
		static bool isMouseButtonPressed(Engine3D::Mouse button);

		static glm::vec2 getMousePosition();
		
		static float getMouseX();

		static float getMouseY();

		static void setCursorMode(CursorMode code);
    };
};