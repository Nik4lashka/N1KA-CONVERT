#include "Converter.hpp"
#include "FileFormat.hpp"

#include "../codecs/ImageDecoderFactory.hpp"
#include "../codecs/ImageEncoderFactory.hpp"

namespace n1ka
{
    void Converter::convert(
        const std::filesystem::path& inputPath,
        const std::filesystem::path& outputPath,
        const ConversionOptions& options
    )
    {
        const FileFormat inputFormat  = getFileFormat(inputPath);
        const FileFormat outputFormat = getFileFormat(outputPath);

        if (getFormatCategory(inputFormat) != getFormatCategory(outputFormat))
        {
            throw std::invalid_argument("Input and output formats are not compatible");    
        }

        switch (getFormatCategory(inputFormat))
        {
        case FormatCategory::Image:
            convertImage(inputPath, inputFormat, outputPath, outputFormat, options);
            break;
        }
    }

    void Converter::convertImage(
        const std::filesystem::path& inputPath, FileFormat inputFormat,
        const std::filesystem::path& outputPath, FileFormat outputFormat,
        const ConversionOptions& options
    )
    {
        auto decoder = ImageDecoderFactory::create(inputFormat);
        Image image = decoder->decode(inputPath);

        auto encoder = ImageEncoderFactory::create(outputFormat);
        encoder->encode(image, outputPath, options);
    }
}