#pragma once

#include <memory>

#include "ImageDecoder.hpp"
#include "../core/FileFormat.hpp"

namespace n1ka
{

class ImageDecoderFactory
{
public:
    static std::unique_ptr<ImageDecoder> create(FileFormat format);
};

}