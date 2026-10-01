# N1KA-CONVERT

A lightweight command-line image converter written in modern C++23.

N1KA-CONVERT converts images between **PNG** and **JPEG**. It is built around a small, extensible codec architecture, so new image formats can be added with minimal changes.

## Features

- Convert PNG ↔ JPEG, or re-encode an image within the same format
- Adjustable JPEG quality
- Automatic format detection from the file extension (case-insensitive)
- Keeps the channel layout of the source image (grayscale, RGB, RGBA)
- Clear error messages and exit codes, suitable for scripts and batch jobs
- No external libraries to install – image I/O is provided by the bundled [stb](https://github.com/nothings/stb) headers

## Supported Formats

| Format | Extensions      | Read | Write | Notes                                          |
|--------|-----------------|:----:|:-----:|------------------------------------------------|
| PNG    | `.png`          |  ✓   |   ✓   | Lossless, supports transparency                |
| JPEG   | `.jpg`, `.jpeg` |  ✓   |   ✓   | Lossy; the alpha channel is discarded on write |

## Requirements

- Windows 10/11 (x64)
- [CMake](https://cmake.org/) 3.25 or newer
- [Clang](https://releases.llvm.org/) with C++23 support (tested with Clang 23.1.1)
- [Ninja](https://ninja-build.org/)
- Visual Studio 2022 or the Build Tools for Visual Studio – Clang uses their C++ standard library, Windows SDK and linker

## Building

```bash
git clone https://github.com/Nik4lashka/N1KA-CONVERT.git
cd N1KA-CONVERT
cmake --preset windows-clang-release
cmake --build --preset windows-clang-release
```

The executable `N1KA_CONVERT.exe` is written to `build/windows-clang-release/`.

For a debug build, use the `windows-clang-debug` preset for both commands instead.

### Presets

Each preset is available as a configure preset and as a build preset with the same name.

| Preset                  | Build type                               | Output directory               |
|-------------------------|------------------------------------------|--------------------------------|
| `windows-clang-debug`   | Debug – no optimization, debug symbols   | `build/windows-clang-debug/`   |
| `windows-clang-release` | Release – optimized                      | `build/windows-clang-release/` |

Run `cmake --list-presets` to list all available presets.

### Presets

| Preset                  | Type      | Description                    |
|-------------------------|-----------|--------------------------------|
| `windows-clang`         | Configure | Windows x64, Clang, Ninja      |
| `windows-clang-debug`   | Build     | Debug build with debug symbols |
| `windows-clang-release` | Build     | Optimized release build        |

## Usage

```
N1KA_CONVERT <input> <output> [options]
```

The input and output formats are determined by the file extensions.

### Options

| Option              | Description                                                   |
|---------------------|---------------------------------------------------------------|
| `-h`, `--help`      | Show the help text                                            |
| `--quality <1-100>` | JPEG quality, higher means better quality and larger files. Default: `90`. Ignored for PNG output. |

### Examples

```bash
# PNG to JPEG with the default quality
N1KA_CONVERT photo.png photo.jpg

# PNG to JPEG with a smaller file size
N1KA_CONVERT photo.png photo.jpg --quality 75

# JPEG to PNG
N1KA_CONVERT scan.jpeg scan.png
```

### Exit Codes

| Code | Meaning                                                        |
|------|----------------------------------------------------------------|
| `0`  | Conversion succeeded                                           |
| `1`  | Invalid arguments, unsupported format, or read/write error     |

Error messages are written to `stderr`.

## How It Works

1. `getImageFormat()` determines the input and output format from the file extensions.
2. `DecoderFactory` creates the matching `ImageDecoder`, which loads the file into an `Image` (width, height, channels and raw 8-bit pixel data).
3. `EncoderFactory` creates the matching `ImageEncoder`, which writes the `Image` in the target format using the given `ConversionOptions`.

## Project Structure

```
N1KA-CONVERT/
├── src/
│   ├── main.cpp           Entry point
│   ├── cli/               Command-line argument parsing
│   ├── core/              Image model, format detection, conversion pipeline
│   ├── codecs/            Decoder/encoder interfaces, factories, PNG and JPEG codecs
│   ├── Version.hpp.in     Version header template (filled in by CMake)
│   └── Version.rc.in      Windows version resource template (filled in by CMake)
├── third_party/stb/       stb_image and stb_image_write
├── CMakeLists.txt
└── CMakePresets.json
```

## Adding a New Format

1. Add a value to `ImageFormat` in `src/core/ImageFormat.hpp` and map its file extensions in `getImageFormat()` in `src/core/ImageFormat.cpp`.
2. Implement a decoder derived from `ImageDecoder` and/or an encoder derived from `ImageEncoder` in `src/codecs/`.
3. Register them in `DecoderFactory::create()` and `EncoderFactory::create()`.
4. Add the new source files to `add_executable` in `CMakeLists.txt`.

## Versioning

This project follows [Semantic Versioning](https://semver.org/). The version is defined once in `CMakeLists.txt` (`project(... VERSION x.y.z)`) and embedded into the Windows file properties of the executable at build time. Release tags use the format `vX.Y.Z`.

## Third-Party Libraries

| Library                                                 | Version | Purpose        | License              |
|---------------------------------------------------------|---------|----------------|----------------------|
| [stb_image](https://github.com/nothings/stb)            | 2.30    | Image decoding | Public domain or MIT |
| [stb_image_write](https://github.com/nothings/stb)      | 1.16    | Image encoding | Public domain or MIT |
