#include <stdint.h>
#include <stdio.h>

int main(void) {
    int32_t rd1;

    __asm__(
        "msr    cpsr_f, #0\n\t"
        "ldr    r0, =7\n\t"   // Num of bits
        "ldr    r1, =32\n\t"  // Counter
        "ldr    r2, =0\n\t"
        "loop:\n\t"
        "rrxs   r0, r0\n\t"     // Rorate right and store the carry flag
        "addcs  r2, r2, #1\n\t"
        "subs   r1, r1, #1\n\t" // Counter -1 when the carry flag is 1
        "bne    loop\n\t"
        "mov    %[Rd1], r2\n\t"
        : [Rd1] "=r" (rd1)
        :
        : "r0", "r1", "r2"
    );

    printf("r1 = %d (0x%08x)\n", rd1, rd1);

    return 0;
}
