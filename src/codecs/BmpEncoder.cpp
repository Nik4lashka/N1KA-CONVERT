#include <stdexcept>
#include <string>

#include "stb_image_write.h"

#include "BmpEncoder.hpp"

namespace n1ka
{
    void BmpEncoder::encode(
        const Image& image,
        const std::filesystem::path& path,
        const ConversionOptions& options
    ) const
    {
        const std::string pathString = path.string();

        const int stride = static_cast<int>(image.width() * image.channels());

        const int result  =stbi_write_bmp(
            pathString.c_str(),
            static_cast<int>(image.width()),
            static_cast<int>(image.height()),
            static_cast<int>(image.channels()),
            image.data().data()
        );

        if (result == 0)
        {
            throw std::runtime_error("Failed to write image: " + path.string());
        }
    }
}