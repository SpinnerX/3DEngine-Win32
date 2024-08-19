#pragma once
#include <3DEngine/interfaces/RendererAPI.h>
#include <type_traits>
#include <glm/glm.hpp>

namespace Engine3D{
    class OpenGLRendererAPI : public RendererAPI{
    public:

        void Init();

        template<typename T, typename = std::enable_if_t<std::is_base_of<glm::vec4, T>::value || std::is_base_of<float, T>::value>, typename ...>
        void setClearColor(const T&& args){
            if(std::is_same<glm::vec3, T>::value){
                setClearColor(color);
            }
            else{
                setClearColor({std::forward<T>(args)...});
            }
        }

    private:

        virtual void init() override;
		
		virtual void setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;

        virtual void setClearColor(const glm::vec4& color) override;
        virtual void clear() override;

        // virtual void drawIndexed(const Ref<VertexArray>& vertexArr, uint32_t indexCount = 0) override;
    };
};