#pragma once
#include <3DEngine/Core/core.h>
#include <3DEngine/Core/EngineLogger.h>
#include <cstdint>
#include <string>
#include <cassert>

namespace Engine3D{
    /**
     * @name Buffer
     * @note Represent a variation of a buffer
     * 
    */

   enum class ShaderDataType : uint8_t {
        None = 0,
        Float, Float2, Float3, Float4,
        Mat3, Mat4,
        Int, Int2, Int3, Int4,
        Bool
    };

    static uint32_t ShaderDataTypeSize(ShaderDataType type){
        switch (type){
            case ShaderDataType::None:
                return 0;
            case ShaderDataType::Float: // A float is 4 bytes.
                return 4;
            case ShaderDataType::Float2: // A float2 is 4*2 bytes.
                return 4 * 2;
            case ShaderDataType::Float3: // A float3 is 4*3 bytes.
                return 4 * 3;
            case ShaderDataType::Float4: // A float4 is 4*4 bytes.
                return 4 * 4;
            case ShaderDataType::Mat3: // A Mat3 is 4*3*3 bytes.
                return 4 * 3 * 3;
            case ShaderDataType::Mat4: // A float4 is 4*4*4 bytes.
                return 4 * 4 * 4;
            case ShaderDataType::Int: // A Int is 4 bytes.
                return 4;
            case ShaderDataType::Int2: // A Int2 is 4*2 bytes.
                return 4 * 2;
            case ShaderDataType::Int3: // A Int3 is 4*3 bytes.
                return 4 * 3;
            case ShaderDataType::Int4: // A Int4 is 4 bytes.
                return 4;
            case ShaderDataType::Bool: // A Bool is 1 byte.
                return 1;
        }
        
        coreLogFatal("Unknown ShaderDataType!");
        assert(false);
        return 0;
    }

    // Simply just for debugging purpose.
    static std::string ShaderDataTypeToString(ShaderDataType type){
        switch (type){
            case ShaderDataType::None: return "ShaderDataType::None";
            case ShaderDataType::Float:  return "ShaderDataType::Float";
            case ShaderDataType::Float2: return "ShaderDataType::Float2";
            case ShaderDataType::Float3: return "ShaderDataType::Float3";
            case ShaderDataType::Float4: return "ShaderDataType::Float4";
            case ShaderDataType::Mat3:   return "ShaderDataType::Mat3";
            case ShaderDataType::Mat4:   return "ShaderDataType::Mat4";
            case ShaderDataType::Int:    return "ShaderDataType::Int";
            case ShaderDataType::Int2:   return "ShaderDataType::Int2";
            case ShaderDataType::Int3:   return "ShaderDataType::Int3";
            case ShaderDataType::Int4:   return "ShaderDataType::Int4";
            case ShaderDataType::Bool:   return "ShaderDataType::Bool";
        }

        return "Default: meaning no type was given!";
    }

    /**
     * @name BufferElement
     * @note Contains how we format data to correspond with our shader programs
     * @note This way we have an API for specifying shader-related tasks.
     * 
     * @param name
     * @param type our shader type that will be used to compute in our glsl file
     * @param offset going to give us the offset of our element in the buffer layout
     * @param size is how big our buffer elements are
     * @param isNormalized checks our buffer element are normalized
     * @param getComponent() is returning our data type size based on specified size.
    */
    class BufferElement{
    public:
        BufferElement() = default;
        BufferElement(ShaderDataType t, const std::string& n, bool normalized = false) : name(n), size(ShaderDataTypeSize(t)), offset(0), isNormalized(normalized) {}

        uint32_t getComponentCount() const {
            switch (type){
                case ShaderDataType::None: return 0;
                case ShaderDataType::Float:  return 1;
                case ShaderDataType::Float2: return 2;
                case ShaderDataType::Float3: return 3;
                case ShaderDataType::Float4: return 4;
                case ShaderDataType::Mat3:   return 3 * 3;
                case ShaderDataType::Mat4:   return 4 * 4;
                case ShaderDataType::Int:    return 1;
                case ShaderDataType::Int2:   return 2;
                case ShaderDataType::Int3:   return 3;
                case ShaderDataType::Int4:   return 4;
                case ShaderDataType::Bool:   return 1;
            }

            // static_assert(false, "Unknown ShaderDataType!");
            coreLogFatal("Unknown ShaderDataType!");
            assert(false);
            return 0;
        }

        std::string name; //! @note Name of our variable that corresponds with our shaders
        ShaderDataType type; //! @note Our type that we specifiy for the shaders
        uint32_t offset; //! @note offset rfom the element contained in our buffer layout
        uint32_t size; //! @note size of the buffer
        bool isNormalized;
    };

    /**
     * @name BufferLayout
     * @note Layout of how we may want to handles our buffers for our shader abstraction
     * @note BufferLayout is going to be used specifically to correspond to our shader program.
     * 
     * @example
     * layout.setLayout({
     *  {ShaderDataType::Float2, "a_Position"},
     *  {ShaderDataType::Float4, "a_Color" }
     * });
     * 
     * 
    */
    class BufferLayout{
        using iterator = std::vector<BufferElement>::iterator;
        using const_iterator = std::vector<BufferElement>::const_iterator;
    public:
        BufferLayout() = default;
        BufferLayout(const std::initializer_list<BufferElement>& list) : elements(list) {}

        iterator begin() { return elements.begin(); }
        iterator end() { return elements.end(); }

        const_iterator begin() const { return elements.begin(); }
        const_iterator end() const { return elements.end(); }

        inline const std::vector<BufferElement>& getElements() const { return elements; }

    private:
        //! @note Computing the offset and fetching the element's strides.
        void calculateOffsetAndStride(){
            uint32_t offset=0, stride = 0;
            for(auto& element : elements){
                element.offset = offset;
                offset += element.size;
                stride += element.size;
            }
        }

    private:
        std::vector<BufferElement> elements;
        uint32_t stride = 0;
    };


    class VertexBuffer{
    public:
        ~VertexBuffer();

        virtual void bind() const = 0;

        virtual void unbind() const = 0;

        virtual void setLayout(const BufferLayout& layout) const = 0;

        //! @note Are Platform-agnostic create functions
        static Ref<VertexBuffer> create(const void* data, uint32_t size);

        static Ref<VertexBuffer> create(uint32_t size);
    };


    class IndexBuffer{
    public:
        virtual ~IndexBuffer(){}

        virtual void bind() const = 0;
        virtual void unbind() const = 0;

        static Ref<IndexBuffer> create(uint32_t* indices, uint32_t size);
    };


};