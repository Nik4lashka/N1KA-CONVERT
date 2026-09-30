#include <stdexcept>
#include <string>

#include "stb_image.h"

#include "JpegDecoder.hpp"

namespace n1ka
{
    Image JpegDecoder::decode(const std::filesystem::path& path) const
    {
        const std::string pathString = path.string();
        int width = 0;
        int height = 0;
        int channels = 0;

        unsigned char* data = stbi_load(
            pathString.c_str(),
            &width,
            &height,
            &channels,
            0
        );

        if (!data)
        {
            throw std::runtime_error("Failed to load image: " + path.string());
        }

        Image image(
            width,
            height,
            static_cast<std::uint8_t>(channels)
        );

        std::copy(
            data,
            data + width * height * channels,
            image.data().begin()
        );

        stbi_image_free(data);

        return image;
    }
}