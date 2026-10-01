#include <memory>
#include <stdexcept>

#include "ImageDecoderFactory.hpp"
#include "StbImageDecoder.hpp"

namespace n1ka
{
    std::unique_ptr<ImageDecoder> ImageDecoderFactory::create(FileFormat format)
    {
        switch (format)
        {
        case FileFormat::JPEG:
        case FileFormat::PNG:
            return std::make_unique<StbImageDecoder>();

        default:
            throw std::invalid_argument("Unsupported image format");
        }
    }
}