#include <memory>
#include <stdexcept>

#include "ImageEncoderFactory.hpp"
#include "JpegEncoder.hpp"
#include "PngEncoder.hpp"

namespace n1ka
{
    std::unique_ptr<ImageEncoder> ImageEncoderFactory::create(FileFormat format)
    {
        switch (format)
        {
        case FileFormat::JPEG:
            return std::make_unique<JpegEncoder>();

        case FileFormat::PNG:
            return std::make_unique<PngEncoder>();

        default:
            throw std::invalid_argument("Unsupported image format");
        }
    }
}