#pragma once

#include <filesystem>

namespace n1ka
{

enum class ImageFormat
{
    JPEG,
    PNG
};

ImageFormat getImageFormat(const std::filesystem::path& path);

}