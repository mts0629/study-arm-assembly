#include <stdint.h>
#include <stdio.h>

void lsl_lsr(void) {
    int32_t rd0, rd1, rd2;

    __asm__(
        "ldr    r0, =10\n\t"
        "lsl    r1, r0, #1\n\t" // Logical left shift
        "lsr    r2, r0, #1\n\t" // Logical right shift
        "mov    %[Rd0], r0\n\t"
        "mov    %[Rd1], r1\n\t"
        "mov    %[Rd2], r2\n\t"
        : [Rd0] "=r" (rd0), [Rd1] "=r" (rd1), [Rd2] "=r" (rd2)
        :
        : "r0", "r1", "r2"
    );

    printf("r0 = %d (0x%08x)\n", rd0, rd0);
    printf("r1 = %d (0x%08x)\n", rd1, rd1);
    printf("r2 = %d (0x%08x)\n", rd2, rd2);
}

void mul_by_16(void) {
    uint32_t rd0, rd1;

    __asm__(
        "ldr    r0, =5\n\t"
        "lsl    r1, r0, #4\n\t" // r1 = r0 << 4 -> r0 * 16
        "mov    %[Rd0], r0\n\t"
        "mov    %[Rd1], r1\n\t"
        : [Rd0] "=r" (rd0), [Rd1] "=r" (rd1)
        :
        : "r0", "r1"
    );

    printf("r0 = %d (0x%08x)\n", rd0, rd0);
    printf("r1 = %d (0x%08x)\n", rd1, rd1);
}

void mul_by_7(void) {
    uint32_t rd0, rd1;

    __asm__(
        "ldr    r0, =5\n\t"
        "lsl    r1, r0, #1\n\t" // r1 = r0 * 2
        "lsl    r2, r0, #2\n\t" // r2 = r0 * 4
        "add    r3, r1, r2\n\t" // r3 = r1 + r2
        "add    r3, r3, r0\n\t" // r3 = r0 + r1 + r2 -> r0 + 2 * r0 + 4 * r0 = 7 * r0
        "mov    %[Rd0], r0\n\t"
        "mov    %[Rd1], r3\n\t"
        : [Rd0] "=r" (rd0), [Rd1] "=r" (rd1)
        :
        : "r0", "r1", "r2", "r3"
    );

    printf("r0 = %d (0x%08x)\n", rd0, rd0);
    printf("r3 = %d (0x%08x)\n", rd1, rd1);
}

void mul_by_7_2(void) {
    uint32_t rd0, rd1;

    __asm__(
        "ldr    r0, =5\n\t"
        "lsl    r1, r0, #3\n\t" // r1 = r0 * 8
        "sub    r2, r1, r0\n\t" // r2 = r1 - r0 -> 8 * r0 - r0 = 7 * r0
        "mov    %[Rd0], r0\n\t"
        "mov    %[Rd1], r2\n\t"
        : [Rd0] "=r" (rd0), [Rd1] "=r" (rd1)
        :
        : "r0", "r1", "r2"
    );

    printf("r0 = %d (0x%08x)\n", rd0, rd0);
    printf("r2 = %d (0x%08x)\n", rd1, rd1);
}

int main(void) {
    lsl_lsr();

    mul_by_16();
    mul_by_7();
    mul_by_7_2();

    return 0;
}
