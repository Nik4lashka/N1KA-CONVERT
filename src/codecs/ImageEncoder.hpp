#pragma once

#include <filesystem>

#include "../core/Image.hpp"
#include "../core/ConversionOptions.hpp"

namespace n1ka
{

class ImageEncoder
{
public:
    virtual ~ImageEncoder() = default;

    virtual void encode(
        const Image& image,
        const std::filesystem::path& path,
        const ConversionOptions& options
    ) const = 0;
};

}