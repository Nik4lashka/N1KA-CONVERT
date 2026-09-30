#include "Converter.hpp"
#include "ImageFormat.hpp"

#include "../codecs/DecoderFactory.hpp"
#include "../codecs/EncoderFactory.hpp"

namespace n1ka
{
    void Converter::convert(
        const std::filesystem::path& inputPath,
        const std::filesystem::path& outputPath,
        const ConversionOptions& options
    )
    {
        const ImageFormat inputFormat  = getImageFormat(inputPath);
        const ImageFormat outputFormat = getImageFormat(outputPath);

        auto decoder = DecoderFactory::create(inputFormat);

        Image image = decoder->decode(inputPath);

        auto encoder = EncoderFactory::create(outputFormat);

        encoder->encode(image, outputPath, options);
    }
}