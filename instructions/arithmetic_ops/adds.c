#include <stdint.h>
#include <stdio.h>

#include "utils/utils.h"

int main(void) {
    uint32_t rd1, rd2, cpsr1, cpsr2;

    __asm__(
        "msr    cpsr_f, #0\n\t"     // Clear CPSR flag field
        "ldr    r0,=1\n\t"          // r0 = 1
        "ldr    r1,=-1\n\t"         // r1 = -1
        "adds   r2, r0, r1\n\t"     // r2 = r0 + r1
        "mov    %[Rd1], r2\n\t"     // %[Rd1] = r2
        "mrs    %[CPSR1], cpsr\n\t" // %[CPSR1] = cpsr
        "ldr    r0, =1\n\t"         // r0 = 1
        "ldr    r1, =2\n\t"         // r1 = 2
        "adds   r3, r0, r1\n\t"     // r3 = r0 + r1
        "mov    %[Rd2], r3\n\t"     // %[Rd2] = r3
        "mrs    %[CPSR2], cpsr\n\t" // %[CPSR2] = cpsr
        : [Rd1] "=r" (rd1), [Rd2] "=r" (rd2), [CPSR1] "=r" (cpsr1), [CPSR2] "=r" (cpsr2)
        :
        : "r0", "r1", "r2", "r3"
    );

    printf("rd1 = %u\n", rd1);
    printf("rd2 = %u\n", rd2);
    printf("flag1: n=%u, z=%u, c=%u, v=%u\n", CPSR_FLAGS_N(cpsr1), CPSR_FLAGS_Z(cpsr1), CPSR_FLAGS_C(cpsr1), CPSR_FLAGS_V(cpsr1));
    printf("flag2: n=%u, z=%u, c=%u, v=%u\n", CPSR_FLAGS_N(cpsr2), CPSR_FLAGS_Z(cpsr2), CPSR_FLAGS_C(cpsr2), CPSR_FLAGS_V(cpsr2));

    return 0;
}
