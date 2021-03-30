cmake_minimum_required(VERSION 3.17)
project(container_git)

set(CMAKE_CXX_STANDARD 98)

add_executable(container_git main.cpp list.hpp vector.hpp listIterator.hpp vectorIterator.hpp memVector.hpp stack.hpp queue.hpp map.hpp mapIterator.hpp)