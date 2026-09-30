#pragma once

#include <filesystem>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <cctype>

#include "ImageFormat.hpp"

namespace n1ka
{

    ImageFormat getImageFormat(const std::filesystem::path& path)
    {
        std::string extension = path.extension().string();

        std::transform(
            extension.begin(),
            extension.end(),
            extension.begin(),
            [](unsigned char c)
        {
            return static_cast<char>(std::tolower(c));
        }
        );

        if (extension == ".jpg" || extension == ".jpeg")
        {
            return ImageFormat::JPEG;
        }
        else if (extension == ".png")
        {
            return ImageFormat::PNG;
        }
        
        throw std::invalid_argument("Unsupported image format: " + extension);
    }

}