cmake_minimum_required(VERSION 3.28)
project(lib_book)

set(CMAKE_CXX_STANDARD 17)

add_executable(lib_book main.cpp
        model/Param.cpp
        model/Param.h
        model/Request.cpp
        model/Request.h)

find_package(jsoncpp CONFIG REQUIRED)
target_link_libraries(lib_book PRIVATE jsoncpp_static)
