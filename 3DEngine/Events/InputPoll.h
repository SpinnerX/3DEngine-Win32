#pragma once
#include <3DEngine/Core/core.h>
#include <glm/glm.hpp>
#include <3DEngine/Events/KeyEvent.h>
#include <3DEngine/Events/MouseEvent.h>

namespace Engine3D{
    class ENGINE_API InputPoll{
	public:

        inline static bool isKeyPressed(KeyCode keycode){
			return instance->isKeyPressedImpl(keycode);
		}
		
		inline static bool isMouseButtonPressed(Mouse button){
			return instance->isMouseButtonPressedImpl(button);
		}

		inline static glm::vec2 getMousePosition(){
			return instance->getMousePositionImpl();
		}
		
		inline static float getMouseX(){
			return instance->getMouseXImpl();
		}

		inline static float getMouseY(){
			return instance->getMouseYImpl();
		}

	protected:
		bool isKeyPressedImpl(Key keycode);
		bool isMouseButtonPressedImpl(Mouse button);
		glm::vec2 getMousePositionImpl();
		
		float getMouseXImpl();
		float getMouseYImpl();

    private:
        static InputPoll* instance;
    };
};