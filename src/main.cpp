#include "cli/ArgumentParser.hpp"
#include "core/ConversionOptions.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    ArgumentParser parser(argc, argv);

    auto arguments = parser.parse();

    if (!arguments)
    {
        return 1;
    }

    n1ka::ConversionOptions options;
    options.quality = arguments->quality;

    if (arguments->showHelp)
    {
        std::cout << "Usage: nika-converter <input> <output> [options]\n";
        return 0;
    }

    std::cout << "Input:  " << arguments->inputPath << '\n';
    std::cout << "Output: " << arguments->outputPath << '\n';

    if (arguments->quality)
    {
        std::cout << "Quality: " << *arguments->quality << '\n';
    }

    return 0;
}