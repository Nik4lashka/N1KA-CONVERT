#pragma once

#include <memory>

#include "ImageEncoder.hpp"
#include "../core/ImageFormat.hpp"

namespace n1ka
{

class EncoderFactory
{
public:
    static std::unique_ptr<ImageEncoder> create(ImageFormat format);
};

}