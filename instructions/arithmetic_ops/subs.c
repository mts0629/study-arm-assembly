#include <stdint.h>
#include <stdio.h>

#include "utils/utils.h"

int main(void) {
    int32_t d;
    uint32_t cpsr;

    __asm__(
        "msr    cpsr_f, #0\n\t"
        "ldr    r0, =1\n\t"         // r0 = 1
        "ldr    r1, =4\n\t"         // r1 = 4
        "subs   r2, r0, r1\n\t"     // r2 = r0 - r1
        "mov    %[Rd], r2\n\t"      // %[Rd] = r2
        "mrs    %[CPSR], cpsr\n\t"
        : [Rd] "=r" (d), [CPSR] "=r" (cpsr)
        :
        : "r0", "r1", "r2"
    );

    printf("r2 = %d\n", d);
    printf("flag: n=%u, z=%u, c=%u, v=%u\n", CPSR_FLAGS_N(cpsr), CPSR_FLAGS_Z(cpsr), CPSR_FLAGS_C(cpsr), CPSR_FLAGS_V(cpsr));

    return 0;
}
