#include <memory>
#include <stdexcept>

#include "DecoderFactory.hpp"
#include "JpegDecoder.hpp"
#include "PngDecoder.hpp"

namespace n1ka
{
    std::unique_ptr<ImageDecoder> DecoderFactory::create(ImageFormat format)
    {
        switch (format)
        {
        case ImageFormat::JPEG:
            return std::make_unique<JpegDecoder>();

        case ImageFormat::PNG:
            return std::make_unique<PngDecoder>();

        default:
            throw std::invalid_argument("Unsupported image format");
        }
    }
}