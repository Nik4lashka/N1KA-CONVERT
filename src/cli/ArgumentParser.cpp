#include "ArgumentParser.hpp"

#include <iostream>

namespace n1ka
{

    ArgumentParser::ArgumentParser(int argc, char* argv[])
        : argc_(argc), argv_(argv) {
    }

    ArgumentParser::~ArgumentParser() {
    }

    std::optional<Arguments> ArgumentParser::parse() const {
        Arguments arguments;

        if (argc_ < 2) {
            return std::nullopt;
        }

        for (int i = 1; i < argc_; i++) {
            std::string_view argument = argv_[i];

            if (argument == "--help" || argument == "-h") {
                arguments.showHelp = true;
                continue;
            }

            if (argument == "--quality") {
                if (i + 1 >= argc_) {
                    std::cerr << "--quality requires a value.\n";
                    return std::nullopt;
                }

                try {
                    arguments.quality = std::stoi(argv_[++i]);
                }
                catch (...) {
                    std::cerr << "Invalid quality value.\n";
                    return std::nullopt;
                }

                continue;
            }

            if (arguments.inputPath.empty()) {
                arguments.inputPath = argument;
            }
            else if (arguments.outputPath.empty()) {
                arguments.outputPath = argument;
            }
            else {
                std::cerr << "Unknown argument: " << argument << '\n';
                return std::nullopt;
            }
        }

        if (!arguments.showHelp &&
                arguments.inputPath.empty() || arguments.outputPath.empty()) {
                    std::cerr << "Input and output files are required.\n";
                    return std::nullopt;
        }
            
        return arguments;
    }

}