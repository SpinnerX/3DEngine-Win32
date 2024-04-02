#pragma once
#include <random>
#include <glm/glm.hpp>

namespace Engine3D{
    class Random{
    public:
        static void init(){
            _randEngine.seed(std::random_device()());
        }

        static uint32_t uInt(){
            return _distribution(_randEngine);
        }

        static uint32_t uInt(uint32_t min, uint32_t max){
            return min + (_distribution(_randEngine) % (max - min + 1));
        }

        static float Float(){
            return (float)_distribution(_randEngine) / (float)std::numeric_limits<uint32_t>::max();
        }

        static glm::vec3 vec3(){
            return glm::vec3(Float(), Float(), Float());
        }

        static glm::vec3 vec3(float min, float max){
            return glm::vec3(Float() * (max - min) + min, Float() * (max - min) + min, Float() * (max - min) + min);
        }

        static glm::vec3 isUnitSphere(){
            return glm::normalize(vec3(-1.0f, 1.0f));
        }

    private:
        static std::mt19937 _randEngine;
        static std::uniform_int_distribution<std::mt19937::result_type> _distribution;
    };
};