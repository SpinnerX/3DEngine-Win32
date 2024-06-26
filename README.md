# 3DEngine-Win32
Engine3D port to Windows

# Prereq Installation
* If you already have this installed, then continue to building the project.
* Make sure you have git, and C++ installed first, and also MAKE SURE CMake is installed as well.
* Set the PATH environmental variables to the cmake path where you installed it.

## Installing and Compiling C++ and CMake (Windows Edition)
* Follow this link's instruction, `https://medium.com/@ahmetekiz/how-to-compile-c-in-vscode-on-windows-11-11518b471c68`
* This link is to install C++ and allow to install it's toolchain. (C++, Make, etc.)
* Next install CMake, by going to this link, `https://cmake.org/download/`


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
* To git clone simply do the following, `git clone --recurse-submodules -j8 https://github.com/SpinnerX/3DEngine-Win32`


# How to Build the Project
* If you try to recompile with simply `cmake ..` (note this is if you create build dir and your inside it).
* Or if you are outside it then you do `cmake --build build`.
* If these do not work and you get some error, run the second command below. (If it doesn't compile)

1.) Create Build dir by doing `cmake -S . -B build`. \
* Some note, is this step is compiling cmake to generate the Makefile \
* Once you do this step, then run the second command below. \
2.) Then to recompile the Makefile `cmake --build build` and if you get an error then do the following in part 3. \
3.) Then compile by doing `cmake -DCMAKE_CXX_COMPILER=g++ -DCMAKE_CC_COMPILER=gcc -DCMAKE_MAKE_PROGRAM=make --build build`.
4/) 3.) Then compile by doing `cmake -DCMAKE_CXX_COMPILER=g++ -DCMAKE_CC_COMPILER=gcc -DCMAKE_MAKE_PROGRAM=make ..`.

* To specify the build type do, `cmake -DCMAKE_BUILD_TYPE=Release ..` (if your in build dir, if not in build dir just do '.').