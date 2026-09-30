#pragma once

#include <memory>

#include "ImageDecoder.hpp"
#include "../core/ImageFormat.hpp"

namespace n1ka
{

class DecoderFactory
{
public:
    static std::unique_ptr<ImageDecoder> create(ImageFormat format);
};

}