#include "MinCPU.h"
#include <iostream>
#include <format>

MinCPU::MinCPU()
{
    // Zero-initialize all registers to 0
    for (size_t i = 0; i < REG_NUMBER; ++i)
        registers.regs[i] = (bits)0;

    // Initialize program counter
    pc = init_pc;
}

// Constructor that initializes memory from an external buffer
MinCPU::MinCPU(bits memory_init[MEM_SIZE]) : MinCPU()
{
    for (std::size_t i = 0; i < MEM_SIZE; ++i)
        memory[i] = memory_init[i];
}

void MinCPU::print_state(int cycle_count) const
{
    std::cout << '\n' << "Cycle: " << cycle_count << "\n"
              << "PC: " << std::format("{:08b}", pc) << "\n"
              << "RA: " << std::format("{:08b}", registers.RA) << "\n"
              << "R1: " << std::format("{:08b}", registers.R1) << "\n"
              << "R2: " << std::format("{:08b}", registers.R2) << "\n"
              << "R3: " << std::format("{:08b}", registers.R3) << "\n"
              << "Memory State:\n";
    for (size_t i = 0; i < MEM_SIZE; ++i)
    {
        std::cout << std::format("{:08b}", memory[i]) << "\n";
    }
}

void MinCPU::run()
{
    int cycle_count = 0;
    while (!is_halt(memory[pc])) 
    {
        bits instruction = memory[pc];
        bits opcode = (instruction >> (CPU_BIT_WIDTH - 4)) & 0b1111; // Extract the top 4 bits as opcode
        std::cout << "Executing instruction: " << std::format("{:08b}", instruction) << "\n"; // DEBUG
        print_state(cycle_count++);
        switch (opcode)
        {
            case MOV:
                mov_instruction((instruction >> 2) & 0b11, instruction & 0b11);
                break;
            case ADD:
                add_instruction((instruction >> 2) & 0b11, instruction & 0b11);
                break;
            case LOAD:
                load_instruction(instruction & 0b1111);
                break;
            case STORE:
                store_instruction(instruction & 0b1111);
                break;
            default:
                // Handle unknown opcode (could raise an error or ignore)
                break;
        }
        pc++; // Move to the next instruction
    }
}

bool MinCPU::is_halt(bits instruction) const
{
    // 0b01000000 is the HALT instruction
    return (instruction == HALT) || pc >= MEM_SIZE; 
}

void MinCPU::mov_instruction(bits rt, bits rs)
{
    registers.regs[rt] = registers.regs[rs];
}

void MinCPU::add_instruction(bits rt, bits rs)
{
    registers.regs[rt] += registers.regs[rs];
}

void MinCPU::load_instruction(bits addr)
{
    registers.RA = memory[addr];
}

void MinCPU::store_instruction(bits addr)
{
    memory[addr] = registers.RA;
}