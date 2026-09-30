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

target_include_directories(N1KA_CONVERTER
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/third_party/stb
)