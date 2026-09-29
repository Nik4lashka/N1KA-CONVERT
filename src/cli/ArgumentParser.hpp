#pragma once

#include <filesystem>
#include <optional>
#include <string>

struct Arguments
{
    std::filesystem::path inputPath;
    std::filesystem::path outputPath;

    std::optional<int> quality;

    bool showHelp = false;
};

class ArgumentParser
{
public:
    ArgumentParser(int argc, char* argv[]);
    ~ArgumentParser();
    std::optional<Arguments> parse() const;

private:
    int argc_;
    char** argv_;
};