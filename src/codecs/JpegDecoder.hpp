#pragma once

#include <filesystem>

#include "ImageDecoder.hpp"
#include "../core/Image.hpp"

namespace n1ka
{

class JpegDecoder : public ImageDecoder
{
public:
    Image decode(const std::filesystem::path& path) const override;
};

}