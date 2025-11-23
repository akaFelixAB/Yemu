#include "MinCPU.h"
#include <iostream>

bits test_mem[MEM_SIZE] = {
    0b11101110, // LOAD [14]
    0b00000100, // MOV R1 R0
    0b11101111, // LOAD [15]
    0b00001000, // MOV R2 R0
    0b00010110, // ADD R1, R2
    0b00000001, // MOV R0 R1
    0b11110000, // STORE [0]
    0b01000000, // HALT
    0b00000000, // Data at address 8
    0b00000000, // Data at address 9
    0b00000000, // Data at address 10
    0b00000000, // Data at address 11
    0b00000000, // Data at address 12
    0b00000000, // Data at address 13
    0b00001000, // Data at address 14 (8)
    0b00000101  // Data at address 15 (5)
}; // After execution, memory[0] should contain 13 (8 + 5)

int main()
{
    MinCPU cpu(test_mem);
    std::cout << "MinCPU starts!" << std::endl;
    cpu.run();
    std::cout << "MinCPU halted!" << std::endl;
    return 0;
}
