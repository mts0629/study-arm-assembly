#include <stdint.h>
#include <stdio.h>

void asr_positive(void) {
    int32_t rd0, rd1;

    __asm__(
        "ldr    r0, =10\n\t"
        "asr    r1, r0, #1\n\t" // Arithmetic right shift
        "mov    %[Rd0], r0\n\t"
        "mov    %[Rd1], r1\n\t"
        : [Rd0] "=r" (rd0), [Rd1] "=r" (rd1)
        :
        : "r0", "r1"
    );

    printf("r0 = %d (0x%08x)\n", rd0, rd0);
    printf("r1 = %d (0x%08x)\n", rd1, rd1);
}

void asr_negative(void) {
    int32_t rd0, rd1;

    __asm__(
        "ldr    r0, =-10\n\t"
        "asr    r1, r0, #1\n\t" // Arithmetic right shift
        "mov    %[Rd0], r0\n\t"
        "mov    %[Rd1], r1\n\t"
        : [Rd0] "=r" (rd0), [Rd1] "=r" (rd1)
        :
        : "r0", "r1"
    );

    printf("r0 = %d (0x%08x)\n", rd0, rd0);
    printf("r1 = %d (0x%08x)\n", rd1, rd1);
}

void div_by_2(void) {
    int32_t rd0, rd1, rd2;

    __asm__(
        "ldr    r0, =-10\n\t"
        "asr    r1, r0, #1\n\t" // r1 = r0 >> 1 -> r0 / 2
        "lsr    r2, r0, #1\n\t" // Logical shift, wrong operation
        "mov    %[Rd0], r0\n\t"
        "mov    %[Rd1], r1\n\t"
        "mov    %[Rd2], r2\n\t"
        : [Rd0] "=r" (rd0), [Rd1] "=r" (rd1), [Rd2] "=r" (rd2)
        :
        : "r0", "r1", "r2"
    );

    printf("r0 = %d (0x%08x)\n", rd0, rd0);
    printf("r1 = %d (0x%08x)\n", rd1, rd1);
    printf("r2 = %d (0x%08x)\n", rd2, rd2); // Wrong answer
}

int main(void) {
    asr_positive();
    asr_negative();

    div_by_2();

    return 0;
}
