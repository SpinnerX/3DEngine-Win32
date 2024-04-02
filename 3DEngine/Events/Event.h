#pragma once
#include <3DEngine/Core/core.h>
#include <string>
#include <functional>
// #include <fmt/format.h>
#include <sstream>
#include <type_traits>

namespace Engine3D{
    //! @note Enums of the different application states
    enum class EventType{
        None=0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased, KeyTyped,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    //! @note Categories of certain events that can occur within our application
    enum EventCategory{
        None = 0,
        EventCategoryApp =              bit(0),
        EventCategoryInput =            bit(1),
        EventCategoryKeyboard =         bit(2),
        EventCategoryMouse =            bit(3),
        EventCategoryMouseButton =      bit(4)
    };

    class ENGINE_API Event{
        friend class EventDispatcher;
    public:
        bool isEventCurrentlyHandled() const;
        EventType GetEventType() const;
        const char* GetName() const;
        int GetCategoryFlags() const;

        inline bool isInCategory(EventCategory category);

        std::string toString() const;

        friend std::ostream& operator<<(std::ostream& outs, const Event& e){
            return outs << e.toString();
        }

        //! @note Reason for this is that if the event we pass in does not occur
        //! @note Will help us for signal to the dispatcher if that event has happened or not.
        template<typename T>
        bool operator=(std::function<bool(T&)> func){
            int handled = func();
            return handled;
        }

    private:
        virtual EventType GetEventTypeImpl() const {};
        virtual const char* GetNameImpl() const {};
        virtual std::string toStringImpl() const {};
        virtual int GetCategoryFlagsImpl() const {};

        //! @note Checking if an event has been handled or not.
        //! @note Specifially for when we are handling events in the dispatcher.
        bool isHandled = false;
    };

    class EventDispatcher{
        template<typename T>
        using EventFunction = std::function<bool(T&)>;
    public:

        EventDispatcher(Event& event) : _event(event){}

        /*!
            @name Dispatch<T>
            @note When we dispatch events, we check if that event being handled are cleanly working
            @note When handling events within our dispatcher

            @example
            ** If we have a button on our screen, and mouse clicked has fallen within the bounds of the button (already clicked)
            ** Preventing so that if we were to have other layers inside worldview does not receive those events anymore.
            ** If event happened, then do not receive that event anymore. (Essentially...)
            @note Essentially a way to check if events that has been actioned or occurred through our dispatch and makes sure that event is not longer valid.
        */
        template<typename T>
        bool Dispatch(EventFunction<T> func){
            //! @note Must be a valid event passed into this function
            if(std::is_base_of<Event, T>()){
                static_assert(false, "In Dispatch<T> is not given an event type!");
            }

            //! @note Checking if current event specified is a valid event type returned 
            //! @note An example is we could be passing in an event that may not even be valid.
            if(_event.GetEventType() == T::GetStaticType()){
                _event = func(*(T *)&_event);
                return true;
            }

            return false;
        }

    private:
        Event& _event;
    };
};

// namespace fmt{
// template<>
// struct fmt::formatter<Engine3D::Event> {
//     template<typename ParseContext>
//     constexpr auto parse(ParseContext& ctx) { return ctx.begin(); }

//     auto format(const Engine3D::Event& p, fmt::format_context& ctx) const -> fmt::format_context::iterator {
//         // ctx.out() is an output iterator to write to.
//         std::stringstream stream;
//         stream << p.toString();
//         return fmt::format_to(ctx.out(), "{}", stream.str());
//     }
// };
// };