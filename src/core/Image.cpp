#include "Image.hpp"

namespace n1ka
{
    Image::Image(std::uint32_t width, std::uint32_t height, std::uint8_t channels)
        : width_(width),
          height_(height),
          channels_(channels),
          data_(width * height * channels)
    {

    }

    Image::~Image()
    {

    }

    std::uint32_t Image::width() const
    {
        return width_;
    }

    std::uint32_t Image::height() const
    {
        return height_;
    }

    std::uint8_t Image::channels() const
    {
        return channels_;
    }

    const std::vector<std::uint8_t>& Image::data() const
    {
        return data_;
    }

    std::vector<std::uint8_t>& Image::data()
    {
        return data_; 
    }
}