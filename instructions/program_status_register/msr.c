#include <stdint.h>
#include <stdio.h>

void msr(void) {
    uint32_t cpsr1;

    __asm__(
        "msr    cpsr_f, #00\n\t"    // cpsr f (flag) field = 0
        "mrs    %[CPSR1], cpsr\n\t"
        : [CPSR1] "=r" (cpsr1)
        :
        : "r0"
    );

    printf("cpsr = 0x%08x\n", cpsr1);
}

void msr_and_mrs(void) {
    uint32_t cpsr1, cpsr2;

    __asm__(
        "mrs    r0, cpsr\n\t"
        "bic    r0, r0, #0x20000000\n\t"    // Bit clear CPSR (bit 29)
        "msr    cpsr_f, r0\n\t"
        "mrs    %[CPSR1], cpsr\n\t"

        "mrs    r0, cpsr\n\t"
        "orr    r0, r0, #0x20000000\n\t"   // OR CPSR (bit 29)
        "msr    cpsr_f, r0\n\t"
        "mrs    %[CPSR2], cpsr\n\t"
        : [CPSR1] "=r" (cpsr1), [CPSR2] "=r" (cpsr2)
        :
        : "r0"
    );

    printf("cpsr1 = 0x%08x\n", cpsr1);
    printf("cpsr2 = 0x%08x\n", cpsr2);
}

int main(void) {
    msr();
    msr_and_mrs();

    return 0;
}
