#pragma once
#include <3DEngine/Core/core.h>
#include <string>

namespace Engine3D{
    class ENGINE_API Layer{
    public:
        Layer(const std::string& name);
        virtual ~Layer();

        virtual void onAttach(){}

        virtual void onDetach(){}

        virtual void onUpdate(float ts){}

        virtual void onUIRender(){}

    private:
        std::string _debugName;
    };
};