# 3DEngine-Win32
Engine3D port to Windows

# Prereq Installation
* If you already have this installed, then continue to building the project.
* Make sure you have git, and C++ installed first.

## Windows Installation
* Make sure to install CMake, and have C++ installed on your machine before building the project.
* If C++ is not installed already then go to this link, `https://www.msys2.org/`

### Vulkan Installation (Windows)
* To install Vulkan in Windows go to this link and follow the instructions shown, `https://www.lunarg.com/vulkan-sdk/`

## Linux Installation
* Note, was tested on Ubuntu necessarily.
* To install the dependencies on a Linux machine just run the `setup.sh` script.
* This setup script will install all of the dependencies that are required.
* The linux script will also install vulkan.

# Cloning the Repository
* To git clone simply do the following \
1.) `git clone https://github.com/SpinnerX/3DEngine-Win32` \
2.) `git submodule update --init --recursive`


# How to Build the Project
* If you try to recompile with simply `cmake ..` (note this is if you create build dir and your inside it).
* Or if you are outside it then you do `cmake --build build`.
* If these do not work and you get some error, run the second command below. (If it doesn't compile)

1.) Create Build dir by doing `cmake -S . -B build`.
2.) Do `cmake --build build` and if you get an error then do the following in part 3.
3.) Then compile by doing `cmake -DCMAKE_CXX_COMPILER=g++ -DCMAKE_CC_COMPILER=gcc -DCMAKE_MAKE_PROGRAM=make --build build`.

* To specify the build type do, `cmake -DCMAKE_BUILD_TYPE=Release ..` (if your in build dir, if not in build dir just do '.').