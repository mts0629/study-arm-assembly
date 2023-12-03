#include <stdint.h>
#include <stdio.h>

#include "utils/utils.h"

void sbc(void) {
    int32_t d;
    uint32_t cpsr;

    __asm__(
        "msr    cpsr_f, #0\n\t"             // Clear CPSR flags
        "mrs    %[CPSR], cpsr\n\t"
        "ldr    r0, =1\n\t"                 // r0 = 1
        "ldr    r1, =4\n\t"                 // r1 = 4
        "sbc    r2, r0, r1\n\t"             // r2 = r0 - r1 - NOT(carry flag)
        "mov    %[Rd], r2\n\t"              // %[Rd] = r2
        : [Rd] "=r" (d), [CPSR] "=r" (cpsr)
        :
        : "r0", "r1", "r2"
    );

    printf("r2 = %d\n", d);
    printf("flag: n=%u, z=%u, c=%u, v=%u\n", CPSR_FLAGS_N(cpsr), CPSR_FLAGS_Z(cpsr), CPSR_FLAGS_C(cpsr), CPSR_FLAGS_V(cpsr));
}

void subtract_double_word(void) {
    int32_t rd1, rd2;
    uint32_t cpsr;

    __asm__(
                                    // 64bit value #1: 0x0000002000000010
        "ldr    r0, =0x10\n\t"      // r0: lower bits
        "ldr    r1, =0x20\n\t"      // r1: upper bits
                                    // 64bit value #2: 0x0000001000000020
        "ldr    r2, =0x20\n\t"      // r2: lower bits
        "ldr    r3, =0x10\n\t"      // r3: upper bits
        "subs   r4, r0, r2\n\t"     // r4 = r0 - r2
        "sbc    r5, r1, r3\n\t"     // r5 = r1 - r3 - NOT(carry flag)
        "mov    %[Rd1], r4\n\t"
        "mov    %[Rd2], r5\n\t"
        "mrs    %[CPSR], cpsr\n\t"
        : [Rd1] "=r" (rd1), [Rd2] "=r" (rd2), [CPSR] "=r" (cpsr)
        : 
        : "r0", "r1", "r2", "r3", "r4", "r5"
    );

    printf("r4 = 0x%08x\n", rd1);   // Lower 32 bits
    printf("r5 = 0x%08x\n", rd2);   // Upper 32 bits
    printf("flag: n=%u, z=%u, c=%u, v=%u\n", CPSR_FLAGS_N(cpsr), CPSR_FLAGS_Z(cpsr), CPSR_FLAGS_C(cpsr), CPSR_FLAGS_V(cpsr));
}

int main(void) {
    sbc();
    subtract_double_word();

    return 0;
}
