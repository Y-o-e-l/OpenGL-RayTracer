cmake_minimum_required(VERSION 4.1.1)
# Set the project name.
project(PPM_Format VERSION 1.1 LANGUAGES C CXX)
# include Testing options
include(CTest)
enable_testing()
# Create an executable file.
add_executable(PPM_Format PPMimgFormat.cpp)
# Set the property of my target to be the C++ language standard so this info is passed to the 
# C++ extension
set_property(TARGET PPM_Format PROPERTY CXX_STANDARD 17)







