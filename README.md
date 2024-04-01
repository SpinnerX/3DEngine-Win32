# 3DEngine-Win32
Engine3D port to Windows


## Windows Installation
* Make sure to install CMake, and have C++ installed on your machine before building the project. \
* If C++ is not installed already then go to this link, `https://www.msys2.org/`

### Vulkan Installation (Windows)
* To install Vulkan in Windows go to this link and follow the instructions shown, `https://www.lunarg.com/vulkan-sdk/`

## Linux Installation
* Note, was tested on Ubuntu necessarily. \
* To install the dependencies on a Linux machine just run the `setup.sh` script. \
* This setup script will install all of the dependencies that are required.
* The linux script will also install vulkan.

## Running CMake
* If you try to recompile with simply `cmake ..` (note this is if you create build dir and your inside it) \
* Or if you are outside it then you do `cmake --build build` \
* If these do not work and you get some error, run the second command below. (If it doesn't compile)

* To set the build type, simply do: `cmake -DCMAKE_BUILD_TYPE=Release ..` (if your in build dir, if not in build dir just do '.')

* Or do this if that does not work, `cmake -DCMAKE_CXX_COMPILER=g++ -DCMAKE_CC_COMPILER=gcc -DCMAKE_MAKE_PROGRAM=make ..`
