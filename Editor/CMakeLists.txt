cmake_minimum_required (VERSION 3.27)
project(Editor)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_PREFIX_PATH "C:\\Program Files (x86)\\3DEngine\\lib\\cmake")

set(imgui_DIR "C:\\Program Files (x86)\\3DEngine\\lib\\cmake\\imgui")
set(fmt_DIR "C:\\Program Files (x86)\\3DEngine\\libcmake\\fmt")
set(spdlog_DIR "C:\\Program Files (x86)\\3DEngine\\libcmake\\spdlog")
find_package(spdlog REQUIRED)
find_package(fmt REQUIRED)
find_package(imgui REQUIRED)
find_package(ImGuizmo REQUIRED)
find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)
find_package(imgui REQUIRED)
find_package(ImGuizmo REQUIRED)
find_package(3DEngine REQUIRED)
# Create the executable
add_executable(Editor Application.cpp)

# @note This is to move the assets into our binary directory
# file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Link the static library from subproject1 using its alias sub::lib1
# Link the header only library from subproject2 using its alias sub::lib2
# This will cause the include directories for that target to be added to this project

# Log::Log1 is the alias we made when we created an alias in the Logger CMakeLists.txt file
target_link_libraries(
    ${PROJECT_NAME}
	3DEngine::3DEngine
    glfw
    ${Vulkan_LIBRARIES}
    fmt::fmt
    spdlog::spdlog
    glm::glm
    tobanteGaming::Box2D
    yaml-cpp
    imgui
    ImGuizmo
)