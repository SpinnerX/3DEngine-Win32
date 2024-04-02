#pragma once
#include <3DEngine/Events/Event.h>

namespace Engine3D{
    class ENGINE_API WindowResizedEvent : public Event {
    public:
        WindowResizedEvent(uint32_t w, uint32_t h) : width(w), height(h) { }

        uint32_t getWidth() const { return width; }

        uint32_t getHeight() const { return height; }

        EventType GetEventType() const override { return GetStaticType(); }

        const char* GetName() const override {
            return "EventType::WindowResize";
        }

        std::string toString() const {
            std::stringstream ss;
            ss << "WindowResizedEvent: " << width << ", " << height;
            return ss.str();
        }

        static EventType GetStaticType() { return EventType::WindowResize; }

        int GetCategoryFlags() const override{
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

        EventType GetEventType() const override {
            return GetStaticType();
        }

        const char* GetName() const override {
            return "EventType::WindowClose";
        }

        int GetCategoryFlags() const override {
            return EventCategoryApp;
        }
    };
};