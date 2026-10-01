cmake_minimum_required(VERSION 3.25)

project(N1KA_CONVERT
    VERSION 1.0.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(N1KA_CONVERT
    src/main.cpp
    src/stb_image.cpp
    src/stb_image_write.cpp

    src/cli/ArgumentParser.cpp

    src/core/Image.cpp
    src/core/ImageFormat.cpp
    src/core/Converter.cpp

    src/codecs/DecoderFactory.cpp
    src/codecs/EncoderFactory.cpp
    src/codecs/JpegDecoder.cpp
    src/codecs/PngDecoder.cpp
    src/codecs/JpegEncoder.cpp
    src/codecs/PngEncoder.cpp
)

target_include_directories(N1KA_CONVERT
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/third_party/stb
)

find_package(Git QUIET)
set(N1KA_GIT_HASH "unknown")
if(GIT_FOUND)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        OUTPUT_VARIABLE N1KA_GIT_HASH
        OUTPUT_STRIP_TRAILING_WHITESPACE
        ERROR_QUIET
    )
endif()

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Version.hpp.in
    ${CMAKE_CURRENT_BINARY_DIR}/generated/Version.hpp
    @ONLY
)

if(WIN32)
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Version.rc.in
        ${CMAKE_CURRENT_BINARY_DIR}/generated/Version.rc
        @ONLY
    )
    target_sources(N1KA_CONVERT PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/generated/Version.rc)
endif()