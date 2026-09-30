#pragma once

#include <filesystem>

#include "../core/Image.hpp"

namespace n1ka
{

class ImageDecoder
{
public:
    virtual ~ImageDecoder() = default;

    virtual Image decode(
        const std::filesystem::path& path
    ) const = 0;
};

}