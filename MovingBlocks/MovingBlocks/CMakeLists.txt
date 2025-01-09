cmake_minimum_required(VERSION 3.8)
project(Voorbeeld-MoveSemanticsBlock)

set(CMAKE_CXX_STANDARD 11)

SET(CMAKE_CXX_FLAGS "-fno-elide-constructors")

set(SOURCE_FILES
        Block.cpp
        Block.h
        main.cpp
        )

add_executable(Voorbeeld-MoveSemanticsBlock ${SOURCE_FILES})
