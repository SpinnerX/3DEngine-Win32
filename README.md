# 3DEngine-Win32
Engine3D port to Windows


## Windows Installation
* Make sure to install CMake, and have C++ installed on your machine before building the project.

* If you try to recompile with simply `cmake ..` (note this is if you create build dir and your inside it)
* Or if you are outside it then you do `cmake --build build`
* If these do not work and you get some error, run the second command below. (If it doesn't compile)

* `cmake -DCMAKE_CXX_COMPILER=g++ -DCMAKE_CC_COMPILER=gcc -DCMAKE_MAKE_PROGRAM=mingw32-make -G ..`

* Or do this if that does not work, `cmake -DCMAKE_CXX_COMPILER=g++ -DCMAKE_CC_COMPILER=gcc -DCMAKE_MAKE_PROGRAM=make ..`

## Linux Installation
* To install the dependencies on a Linux machine just run the `setup.sh` script.