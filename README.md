[Yemu]
# Yemu

A mininalistic cpu emulator written in C++20.

## Project Structure
```
Yemu/
├── src/            # Main program source
│   ├── MinCPU.h    # Minimal CPU header
│   ├── MinCPU.cpp  # Minimal CPU implementation
│   └── main.cpp    # Entry point
├── tests/          # Unit tests
│   ├── test_main.cpp
│   └── CMakeLists.txt
├── CMakeLists.txt  # Top-level CMake configuration
├── README.md       # Project documentation
└── LICENSE         # License
```

## Build Requirements
- A C++20-capable compiler (g++ 10+ recommended)
- CMake >= 3.16
- Ninja build backend (optional, recommended)

## Build Steps

1. Install dependencies (example for Debian/Ubuntu):

```bash
sudo apt install g++
sudo apt install cmake
# Optional, recommended:
sudo apt install ninja-build
```

2. Create the build directory and compile:

```bash
mkdir build
cd build
cmake -G Ninja ..   # Use Ninja
# or
cmake ..            # Use default generator
cmake --build .
```

3. Run the program:

```bash
./Yemu
```

## Unit Tests

- The project uses Catch2 by default; CMake will download and integrate it automatically if enabled.
- To run tests after building:

```fish
cd build
ctest
```

## Configuration Notes

- `CMakeLists.txt` configures the project to use C++20 and is tested with g++. It also supports Ninja as an optional generator.
- Enable or disable tests with the `YEMU_ENABLE_TESTS` CMake option.
- Catch2 is the default test framework; you can swap or add other frameworks (for example, Google Test) if desired.

If you'd like, I can also add a short example showing how to assemble a simple program binary or provide CI instructions.
# Yemu
