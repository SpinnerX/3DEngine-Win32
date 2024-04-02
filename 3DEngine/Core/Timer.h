#pragma once
#include <iostream>
#include <string>
#include <chrono>

namespace Engine3D{
    class Timer{
    public:
        Timer(){}

        void reset(){
            _start = std::chrono::high_resolution_clock::now();
        }

        float elapsed(){
            return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - _start).count() * 0.001f * 0.001f * 0.001f;
        }

        float elapsedMillis(){
            return elapsed() * 1000.f;
        }

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> _start;
    };

    class ScopedTimer{
    public:
        ScopedTimer(const std::string& name) : _name(name) {}
        
        ~ScopedTimer(){
            float time = _timer.elapsedMillis();
            std::cout << "[TIEMR]" << _name << time << "ms\n";
        }
    private:
        std::string _name;
        Timer _timer;
    };
};