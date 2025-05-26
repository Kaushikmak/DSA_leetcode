cmake_minimum_required(VERSION 3.25)
project(Leetcode)

set(CMAKE_CXX_STANDARD 17)

# Recursively collect all .cpp files in the project
file(GLOB_RECURSE ALL_SOURCE_FILES
        "Hard/*.cpp"
        "Medium/*.cpp"
        "Easy/*.cpp"
        "Algorithms/*.cpp"
)

add_executable(Leetcode ${ALL_SOURCE_FILES})