#include <filesystem>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <cctype>

#include "FileFormat.hpp"

namespace n1ka
{

    FileFormat getFileFormat(const std::filesystem::path& path)
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
            return FileFormat::JPEG;
        }
        else if (extension == ".png")
        {
            return FileFormat::PNG;
        }
        
        throw std::invalid_argument("Unsupported image format: " + extension);
    }

    FormatCategory getFormatCategory(FileFormat format)
    {
        switch (format)
        {
        case FileFormat::PNG:
        case FileFormat::JPEG:
            return FormatCategory::Image;
        
        default:
            throw std::invalid_argument("Unknown file format");
        }
    }

}