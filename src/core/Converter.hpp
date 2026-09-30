#pragma once

#include <filesystem>

#include "ConversionOptions.hpp"

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
};

}