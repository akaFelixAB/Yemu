#pragma once

#include <cstdint>
#include <type_traits>
#include <cstddef>

// Configure the memory size here
#define MEM_SIZE 16

// Configure the number of registers here
#define REG_NUMBER 5

// Configure the CPU bit width here (allowed: 8, 16, 32, 64)
constexpr std::size_t CPU_BIT_WIDTH = 8; // <-- change this value to 8/16/32/64

using bits = std::conditional_t<CPU_BIT_WIDTH == 8, std::uint8_t,
             std::conditional_t<CPU_BIT_WIDTH == 16, std::uint16_t,
             std::conditional_t<CPU_BIT_WIDTH == 32, std::uint32_t,
             std::conditional_t<CPU_BIT_WIDTH == 64, std::uint64_t, void>>>>;

static_assert(!std::is_same_v<bits, void>, "CPU_BIT_WIDTH must be one of: 8, 16, 32, 64");


#define pc (registers.PC)
#define init_pc (bits)0x0

#define opcode_length 4

#define MOV 0b0000
#define ADD 0b0001
#define LOAD 0b1110
#define STORE 0b1111
#define HALT 0b01000000


class MinCPU
{
public:
    MinCPU();
    MinCPU(bits memory_init[MEM_SIZE]);
    ~MinCPU() = default;

    void run();

    void print_state(int cycle_count) const;

private:
    union
    {
        struct 
        {
            bits RA;
            bits R1;
            bits R2;
            bits R3;
            bits PC;
        };
        bits regs[REG_NUMBER]; // Access registers using registers.regs[idx]
    } registers;

    bits memory[MEM_SIZE] = {0}; // Memory initialized to zero


    bool is_halt(bits instruction) const;

    void mov_instruction(bits rt, bits rs);
    void add_instruction(bits rt, bits rs);
    void load_instruction(bits addr);
    void store_instruction(bits addr);
};