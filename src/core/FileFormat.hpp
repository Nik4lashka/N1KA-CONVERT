#pragma once

#include <filesystem>

namespace n1ka
{

enum class FileFormat
{
    JPEG,
    PNG
};

enum class FormatCategory
{
    Image
};

FileFormat getFileFormat(const std::filesystem::path& path);

FormatCategory getFormatCategory(FileFormat format);

}