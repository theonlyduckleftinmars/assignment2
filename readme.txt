To run the provided C++ code,
Ensure you have CMake and a C++ compiler installed on your system.
Install CMake using Homebrew by typing in: brew install cmake
Add the necessary "CMakeLists.txt" file to your project directory.
CMakeLists.txt:
cmake_minimum_required(VERSION 3.29)
project(assignment2)

set(CMAKE_CXX_STANDARD 20)

add_executable(assignment2 main.cpp Chef.cpp SousChef.cpp Restaurant.cpp)

Then, build and run your project by typing in the following commands:
mkdir build
cd build
cmake..
make
./assignment2

This will compile and run the C++ code provided in the assignment.