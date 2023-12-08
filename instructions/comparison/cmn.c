#include <stdio.h>
#include <stdint.h>

#include "utils/utils.h"

int main(void) {
    uint32_t cpsr1, cpsr2;

    __asm__(
        "msr    cpsr_f, #0\n\t"
        "mov    r0, #1\n\t"
        "mov    r1, #-1\n\t"
        "cmn    r0, r1\n\t" // r0 + r1 -> cpsr (zero)
        "mrs    %[CPSR1], cpsr\n\t"
        "mov    r0, #10\n\t"
        "mov    r1, #10\n\t"
        "cmn    r0, r1\n\t" // r0 + r1 -> cpsr (positive, no flags)
        "mrs    %[CPSR2], cpsr\n\t"
        : [CPSR1] "=r" (cpsr1), [CPSR2] "=r" (cpsr2)
        :
        : "r0", "r1"
    );

    printf("flag1: n=%u, z=%u, c=%u, v=%u\n",
        CPSR_FLAGS_N(cpsr1), CPSR_FLAGS_Z(cpsr1), CPSR_FLAGS_C(cpsr1), CPSR_FLAGS_V(cpsr1));
    printf("flag2: n=%u, z=%u, c=%u, v=%u\n",
        CPSR_FLAGS_N(cpsr2), CPSR_FLAGS_Z(cpsr2), CPSR_FLAGS_C(cpsr2), CPSR_FLAGS_V(cpsr2));

    return 0;
}
