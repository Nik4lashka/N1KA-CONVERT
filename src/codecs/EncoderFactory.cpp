#include <memory>
#include <stdexcept>

#include "EncoderFactory.hpp"
#include "JpegEncoder.hpp"
#include "PngEncoder.hpp"

namespace n1ka
{
    std::unique_ptr<ImageEncoder> EncoderFactory::create(ImageFormat format)
    {
        switch (format)
        {
        case ImageFormat::JPEG:
            return std::make_unique<JpegEncoder>();

        case ImageFormat::PNG:
            return std::make_unique<PngEncoder>();

        default:
            throw std::invalid_argument("Unsupported image format");
        }
    }
}