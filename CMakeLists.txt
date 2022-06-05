cmake_minimum_required(VERSION 3.20)
project(product_base)

set(CMAKE_CXX_STANDARD 17)

add_executable(product_base main.cpp Product.h Position.h Order.h Order.hpp)
