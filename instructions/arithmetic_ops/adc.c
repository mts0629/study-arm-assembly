#include <stdint.h>
#include <stdio.h>

#include "utils/utils.h"

void adc(void) {
    uint32_t d, cpsr;

    __asm__(
        "mrs    r0, cpsr\n\t"               // r0 = cpsr
        "orr    r0, r0, #0x20000000\n\t"    // r0 = (r0 | 0x20000000)
        "msr    cpsr_f, r0\n\t"             // (CPSR flag field) = r0
                                            // (carry flag) = 1
        "mrs    %[CPSR], cpsr\n\t"          // %[CPSR] = cpsr
        "ldr    r0, =1\n\t"                 // r0 = 1
        "ldr    r1, =2\n\t"                 // r1 = 2
        "adc    r2, r0, r1\n\t"             // r2 = r0 + r1 + (carry flag)
        "mov    %[Rd], r2\n\t"              // %[Rd] = r2
        : [Rd] "=r" (d), [CPSR] "=r" (cpsr)
        :
        : "r0", "r1", "r2", "r3"
    );

    printf("rd2 = %u\n", d);
    printf("flag: n=%u, z=%u, c=%u, v=%u\n", CPSR_FLAGS_N(cpsr), CPSR_FLAGS_Z(cpsr), CPSR_FLAGS_C(cpsr), CPSR_FLAGS_V(cpsr));
}

void add_double_word(void) {
    uint32_t rd1, rd2, cpsr;

    __asm__(
                                        // 64 bit value #1: 0x0000000080000002
        "ldr    r0, =0x80000002\n\t"    // r0 = 0x80000002: lower bits
        "ldr    r1, =0x00000000\n\t"    // r1 = 0x00000000: upper bits
                                        // 64 bit value #2: 0x0000000080000001
        "ldr    r2, =0x80000001\n\t"    // r2 = 0x80000001: lower bits
        "ldr    r3, =0x00000000\n\t"    // r3 = 0x00000000: upper bits
        "adds   r4, r2, r0\n\t"         // r4 = r2 + r0: lower bits
        "adc    r5, r1, r3\n\t"         // rt = r1 + r3 + (carry flag): upper bits
        "mov    %[Rd1], r4\n\t"         // %[Rd1] = r4
        "mov    %[Rd2], r5\n\t"         // %[Rd2] = r5
        "mrs    %[CPSR], cpsr\n\t"      // %[CPSR] = cpsr
        : [Rd1] "=r" (rd1), [Rd2] "=r" (rd2), [CPSR] "=r" (cpsr)
        :
        : "r0", "r1", "r2", "r3", "r4", "r5"
    );

    printf("r4 = 0x%08x\n", rd1);   // Lower 32 bits
    printf("r5 = 0x%08x\n", rd2);   // Upper 32 bits
    printf("flag: n=%u, z=%u, c=%u, v=%u\n", CPSR_FLAGS_N(cpsr), CPSR_FLAGS_Z(cpsr), CPSR_FLAGS_C(cpsr), CPSR_FLAGS_V(cpsr));
}

int main(void) {
    adc();
    add_double_word();

    return 0;
}
