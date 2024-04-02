#include <3DEngine/Events/Event.h>


namespace Engine3D{
    bool Event::isEventCurrentlyHandled() const {
        return isHandled;
    }

    const char* Event::GetName() const {
        return GetNameImpl();
    }

    int Event::GetCategoryFlags() const{
        return GetCategoryFlagsImpl();
    }

    bool Event::isInCategory(EventCategory category){

        return GetCategoryFlags() & category;
    }

    std::string Event::toString() const {
        return toStringImpl();
    }
};