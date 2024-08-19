#pragma once
#include <glm/glm.hpp>

namespace Engine3D{

    class RendererAPI{
        enum class API{
            None = 0,
            OpenGL = 1,
            Vulkan = 2
        };
    public:

        virtual ~RendererAPI() = default;

        virtual void init() = 0;
        
        virtual void setViewport(uint32_t x, uint32_t y, uint32_t w, uint32_t h) = 0;


        virtual void setClearColor(const glm::vec4& color) = 0;

        virtual void clear() = 0;

        //! @note This is going to be returning what our currently rendering API we are going to be using.
        static RendererAPI::API CurrentAPI() { return api; }
        
        // virtual void drawIndexed(const Ref<VA>)

    private:
        inline static RendererAPI::API api = RendererAPI::API::OpenGL;

    };
};