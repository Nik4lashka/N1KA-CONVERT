#pragma once

#include <memory>

#include "ImageEncoder.hpp"
#include "../core/FileFormat.hpp"

namespace n1ka
{

class ImageEncoderFactory
{
public:
    static std::unique_ptr<ImageEncoder> create(FileFormat format);
};

}