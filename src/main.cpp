#include <iostream>

#include "cli/ArgumentParser.hpp"
#include "core/ConversionOptions.hpp"
#include "core/Converter.hpp"

int main(int argc, char* argv[])
{
    n1ka::ArgumentParser parser(argc, argv);

    const auto arguments = parser.parse();

    if (!arguments)
    {
        return 1;
    }

    if (arguments->showHelp)
    {
        std::cout
            << "Usage: N1KA_CONVERTER <input> <output> [options]\n"
            << "\n"
            << "Options:\n"
            << "  -h, --help          Show this help\n"
            << "  --quality <value>  JPEG quality (0-100)\n";

        return 0;
    }

    n1ka::ConversionOptions options;
    options.quality = arguments->quality;

    n1ka::Converter converter;

    try
    {
        converter.convert(
            arguments->inputPath,
            arguments->outputPath,
            options
        );
    }
    catch (const std::exception& exception)
    {
        std::cerr << "Error: " << exception.what() << '\n';
        return 1;
    }

    std::cout
        << "Successfully converted "
        << arguments->inputPath
        << " -> "
        << arguments->outputPath
        << '\n';

    return 0;
}