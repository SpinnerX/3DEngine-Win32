#pragma once
#include <3DEngine/Core/core.h>
#include <3DEngine/Events/Event.h>
#include <3DEngine/Events/KeyCodes.h>
#include <spdlog/spdlog.h>

namespace Engine3D{

    class ENGINE_API KeyEvent : public Event{
    public:

        inline virtual KeyCode GetKeyCode() const { return keycode; }
        inline int GetCategoryFlags() const override { return EventCategoryKeyboard | EventCategoryInput; }

    protected:

        KeyEvent(KeyCode code) : keycode(code) {}

        KeyCode keycode;
    };

    class ENGINE_API KeyPressedEvent : public KeyEvent {
    public:
        KeyPressedEvent(KeyCode code, int repeatCount) : KeyEvent(code), isRepeatedCount(repeatCount) {}

        inline int GetRepeatedCount() const { return isRepeatedCount; }

        std::string toString() const {
            std::stringstream ss;
            ss << fmt::format("KeyPressedEvent: {} ({} repeats)", static_cast<int32_t>(keycode), isRepeatedCount);
            return ss.str();
        }

        static EventType GetStaticType() { return EventType::KeyPressed; }

        EventType GetEventType() const override { return GetStaticType(); }
        const char* GetName() const override { return GetNameImpl(); }

    private:
        const char* GetNameImpl() const { return "EventType::KeyPressed"; }

    private:
        int isRepeatedCount; //! @note variable for handling repeated key pressed events
    };

    class ENGINE_API KeyReleasedEvent : public KeyEvent {
    public:
        KeyReleasedEvent(KeyCode code) : KeyEvent(code){}

        // In runtime we want to see what event type this is.
        static EventType GetStaticType() { return EventType::KeyReleased; }

        // We need another instance of it, so we know what the actual event type it is.
        EventType GetEventType() const override { return GetStaticType(); }
        const char* GetName() const override { return "EventType::Released"; }

        std::string toString() const {
            std::stringstream ss;
            ss << fmt::format("KeyTypedEvent: {}", static_cast<int32_t>(keycode));
            return ss.str();
        }
    };

    class ENGINE_API KeyTypedEvent : public KeyEvent {
    public:
        KeyTypedEvent(KeyCode keycode) : KeyEvent(keycode){}

        static EventType GetStaticType() { return EventType::KeyTyped; }

        EventType GetEventType() const override { return GetStaticType(); }

        const char* GetName() const override { return "EventType::KeyTyped"; }

        std::string toString() const {
            std::stringstream ss;
            ss << fmt::format("KeyTypedEvent: {}", static_cast<int32_t>(keycode));
            return ss.str();
        }
    };
};