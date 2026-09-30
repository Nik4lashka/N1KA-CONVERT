#pragma once

#include <cstdint>
#include <vector>

namespace n1ka
{
class Image
{
public:
    Image(std::uint32_t width, std::uint32_t height, std::uint8_t channels);
    ~Image();

    std::uint32_t width() const;
    std::uint32_t height() const;
    std::uint8_t channels() const;
    const std::vector<std::uint8_t>& data() const;

    std::vector<std::uint8_t>& data();

private:
    std::uint32_t width_;
    std::uint32_t height_;
    std::uint8_t channels_;
    std::vector<std::uint8_t> data_;
}; 
}