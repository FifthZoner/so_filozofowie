cmake_minimum_required(VERSION 3.26)
project(so_filozofowie)

set(CMAKE_CXX_STANDARD 23)

add_executable(so_filozofowie main.cpp
        filozof.cpp
        filozof.hpp
        widelec.hpp
        wyswietlanie.hpp
        widelec.cpp
        wyswietlanie.cpp)
