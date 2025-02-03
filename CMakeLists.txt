cmake_minimum_required(VERSION 3.5.2)

project(ATM_Software_Simulator)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source and test directories
add_subdirectory(src)
add_subdirectory(tests)
