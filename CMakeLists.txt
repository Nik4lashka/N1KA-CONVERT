cmake_minimum_required(VERSION 3.25)

project(N1KA_CONVERTER
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(N1KA_CONVERTER
    src/main.cpp

    src/cli/ArgumentParser.cpp
)

target_include_directories(N1KA_CONVERTER
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)