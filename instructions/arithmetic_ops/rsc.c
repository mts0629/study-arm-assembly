#include <stdio.h>
#include <stdint.h>

#include "utils/utils.h"

void subtract_double_word(void) {
    int32_t rd1, rd2;
    uint32_t cpsr;

    __asm__(
        "ldr    r0, =0x10\n\t"      // 64 bit value #1: 0x0000002000000010
        "ldr    r1, =0x20\n\t"
                                    // 0 - (value #1)
        "rsbs   r2, r0, #0\n\t"     // r2 = 0 - r0
        "rsc    r3, r1, #0\n\t"     // r3 = 0 - r1 - NOT(carry flag)
        "mov    %[Rd1], r2\n\t"
        "mov    %[Rd2], r3\n\t"
        "mrs    %[CPSR], cpsr\n\t"
        : [Rd1] "=r" (rd1), [Rd2] "=r" (rd2), [CPSR] "=r" (cpsr)
        :
        : "r0", "r1", "r2", "r3"
    );

    printf("r2 = 0x%08x\n", rd1);
    printf("r3 = 0x%08x\n", rd2);
    printf("flag: n=%u, z=%u, c=%u, v=%u\n", CPSR_FLAGS_N(cpsr), CPSR_FLAGS_Z(cpsr), CPSR_FLAGS_C(cpsr), CPSR_FLAGS_V(cpsr));
}

int main(void) {
    subtract_double_word();

    return 0;
}
