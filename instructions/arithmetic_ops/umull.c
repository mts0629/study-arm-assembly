#include <stdint.h>
#include <stdio.h>

int main(void) {
    uint32_t rd1, rd2;

    __asm__(
        "ldr    r0, =0x80000000\n\t"    // r0 = 0x80000000
        "ldr    r1, =0x00000003\n\t"    // r1 = 0x00000003
        "umull  r2, r3, r0, r1\n\t"     // (r3, r2) = (unsigned)(r0 * r1)
        "mov    %[Rd1], r3\n\t"         // %[Rd1] = r3 (upper bits)
        "mov    %[Rd2], r2\n\t"         // %[Rd2] = r2 (lower bits)
        : [Rd1] "=r" (rd1), [Rd2] "=r" (rd2)
        :
        : "r0", "r1", "r2", "r3"
    );

    printf("r3 = 0x%08x\n", rd1);
    printf("r2 = 0x%08x\n", rd2);
    printf("(0x%016llx)\n", (((uint64_t)rd1 << 32) | rd2));

    return 0;
}
