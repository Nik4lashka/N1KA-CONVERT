#pragma once

#include <filesystem>

#include "ConversionOptions.hpp"
#include "FileFormat.hpp"

namespace n1ka
{

class Converter
{
public:
    Converter() = default;

    void convert(
        const std::filesystem::path& inputPath,
        const std::filesystem::path& outputPath,
        const ConversionOptions& options
    );

    void convertImage(
        const std::filesystem::path& inputPath, FileFormat inputFormat,
        const std::filesystem::path& outputPath, FileFormat outputFormat,
        const ConversionOptions& options
    );
};

}