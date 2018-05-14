# cmake_minimum_required(VERSION <specify CMake version here>)
project(boardHW_master)

set(CMAKE_CXX_STANDARD 11)

add_executable(boardHW_master
        .idea/codeStyles/Project.xml
        .idea/misc.xml
        .idea/vcs.xml
        .gitignore
        Board.cpp
        Board.h
        Coordinate.cpp
        exeptions.cpp
        LICENSE
        main.cpp
        README.md
        square.cpp)
