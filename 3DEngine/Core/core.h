#pragma once
#include <type_traits>
#include <memory>

// Essentially to support Windows/Mac/Linux systems

// if we are on the Windows OS (since windows uses dll files)
#ifdef ENGINE_PLATFORM_WINDOWS
    #ifdef ENGINE_BUILD_DLL
        #define ENGINE_API __declspec(dllexport)
    #else
        #define ENGINE_API __declspec(dllimport)
    #endif
#else // If we are on either Linux/Mac OS, since they use __attributes__
    #define ENGINE_API __attribute__((visibility("default")))
#endif

namespace Engine3D{

    template<typename T>
    using Ref = std::shared_ptr<T>;

    template<typename T>
    using Scope = std::unique_ptr<T>;


    template<typename T, typename... Args>
    Ref<T> CreateRef(Args&&... args){
        return std::unique_ptr<T>(std::move(args)...);
    }

    template<typename T, typename... Args>
    Scope<T> CreateScope(Args&&... args){
        return std::shared_ptr<T>(std::move(args)...);
    }
};