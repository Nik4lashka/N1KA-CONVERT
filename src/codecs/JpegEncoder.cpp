#include <stdexcept>
#include <string>

#include "stb_image_write.h"

#include "JpegEncoder.hpp"

namespace n1ka
{
    void JpegEncoder::encode(
        const Image& image,
        const std::filesystem::path& path,
        const ConversionOptions& options
    ) const
    {
        const std::string pathString = path.string();

        const int quality = options.quality.value_or(90);

        const int result  =stbi_write_jpg(
            pathString.c_str(),
            static_cast<int>(image.width()),
            static_cast<int>(image.height()),
            static_cast<int>(image.channels()),
            image.data().data(),
            quality
        );

        if (result == 0)
        {
            throw std::runtime_error("Failed to write image: " + path.string());
        }
    }
}