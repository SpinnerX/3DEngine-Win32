#pragma once

namespace Engine3D{
    class Layer{
    public:
        virtual ~Layer() = default;

        virtual void onAttach(){}

        virtual void onDetach(){}

        virtual void onUpdate(float ts){}

        virtual void onUIRender(){}
    };
};