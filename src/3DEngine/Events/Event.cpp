#include <3DEngine/Events/Event.h>


namespace Engine3D{
    bool Event::isEventCurrentlyHandled() const {
        return isHandled;
    }
};