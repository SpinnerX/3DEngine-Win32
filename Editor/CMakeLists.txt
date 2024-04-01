# cmake_minimum_required (VERSION 3.27)

set(CMAKE_CXX_STANDARD 20)

# Create the executable
add_library(Editor Application.cpp)

# @note This is to move the assets into our binary directory
# file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Link the static library from subproject1 using its alias sub::lib1
# Link the header only library from subproject2 using its alias sub::lib2
# This will cause the include directories for that target to be added to this project

# Log::Log1 is the alias we made when we created an alias in the Logger CMakeLists.txt file
# target_link_libraries(
#     ${PROJECT_NAME}
# 	Engine3D::Engine3D
# )