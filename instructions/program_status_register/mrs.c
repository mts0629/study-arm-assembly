#include <stdint.h>
#include <stdio.h>

int main(void) {
    uint32_t cpsr1;

    __asm__(
        "mrs    r0, cpsr\n\t"       // r0 = cpsr
        "mov    %[CPSR1], r0\n\t"
        : [CPSR1] "=r" (cpsr1)
        :
        : "r0"
    );

    printf("cpsr = 0x%08x\n", cpsr1);

    return 0;
}
