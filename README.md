# Yemu

A mininalistic cpu emulator written in C++20.

## Features

### CPU Specifications
- 4 General Purpose Registers: R0(RA), R1, R2, R3
- 16 Bytes of Memory
- 8-bit Data Width
- Each instruction is 4 bits long

### Operations Supported
- `LOAD [addr]`: Load data from memory to register `RA`
- `STORE [addr]`: Store data from register `RA` to memory
- `ADD [rt][rs]`: Add the value of register `rs` to `rt`
- `MOV [rt][rs]`: Move the value of register `rs` to `rt`
- `HALT`: Stop execution

### Instructions Format
| Instruction  | Format    |
|--------------|-----------|
| `LOAD`       | 1110 AAAA |
| `STORE`      | 1111 AAAA |
| `ADD`        | 0001 RTRS |
| `MOV`        | 0000 RTRS |
| `HALT`       | 0100 0000 |
Where `AAAA` is a 4-bit memory address and `RT` `RS` are 2-bit register specifiers.

### Examples

```binary
11100000    # LOAD from address 0
00000100    # MOV R0 to R1
11110001    # STORE to address 1
01000000    # HALT
```

## Project Structure
```
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

## License

This project is licensed under the MIT License - see the LICENSE file for details.