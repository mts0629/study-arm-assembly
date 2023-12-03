#include <stdint.h>

// CPSR (Current Program Status Register) flags
#define CPSR_FLAGS_N(cpsr) (uint8_t)(((cpsr) >> 31U) & 0x1U)    // Negative
#define CPSR_FLAGS_Z(cpsr) (uint8_t)(((cpsr) >> 30U) & 0x1U)    // Zero
#define CPSR_FLAGS_C(cpsr) (uint8_t)(((cpsr) >> 29U) & 0x1U)    // Carry
#define CPSR_FLAGS_V(cpsr) (uint8_t)(((cpsr) >> 28U) & 0x1U)    // Overflow
