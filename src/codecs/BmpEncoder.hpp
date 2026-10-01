#pragma once

#include <filesystem>

#include "ImageEncoder.hpp"
#include "../core/Image.hpp"
#include "../core/ConversionOptions.hpp"

namespace n1ka
{

class BmpEncoder : public ImageEncoder
{
public:
    void encode(
        const Image& image,
        const std::filesystem::path& path,
        const ConversionOptions& options
    ) const override;
};

}