#pragma once
#include <3DEngine/Events/Event.h>

namespace Engine3D{
    class ENGINE_API WindowResizedEvent : public Event {
    public:
        WindowResizedEvent(uint32_t w, uint32_t h) : width(w), height(h) { }

        uint32_t getWidth() const { return width; }

        uint32_t getHeight() const { return height; }

        EventType GetEventTypeImpl() { return GetStaticType(); }

        const char* GetNameImpl(){
            return "EventType::WindowResize";
        }

        std::string toStringImpl() const override {
            std::stringstream ss;
            ss << "WindowResizedEvent: " << width << ", " << height;
            return ss.str();
        }

        static EventType GetStaticType() { return EventType::WindowResize; }

        int GetCategoryFlagsImpl() const override{
            return EventCategoryApp;
        }

        friend std::ostream& operator<<(std::ostream& outs, const WindowResizedEvent& event){
            return outs << event.toString();
        }

    private:
        uint32_t width, height;
    };

    class ENGINE_API WindowClosedEvent : public Event {
    public:
        WindowClosedEvent(){}

        static EventType GetStaticType() { return EventType::WindowClose; }

        EventType GetEventTypeImpl() const override {
            return GetStaticType();
        }

        const char* GetNameImpl() const override {
            return "EventType::WindowClose";
        }

        int GetCategoryFlagsImpl() const override {
            return EventCategoryApp;
        }
    };
};