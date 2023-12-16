#include <stdint.h>
#include <stdio.h>

void ldr_pre_index(void) {
    uint32_t s[] = { 1, 2, 3 };
    uint32_t d0, d1;

    __asm__(
        "ldr    r0, %[Rs]\n\t"          // r0 = (address of s)
        "ldr    r1, [r0, #0x4]!\n\t"    // r1 = *(r0 + 4[B]) = *&d[1], r0 += 4[B] (pre-index with write-back)
        "ldr    r2, [r0, #0x4]\n\t"     // r2 = *(r0 + 4[B]) = *&d[2] (pre-index)
        "mov    %[Rd0], r1\n\t"
        "mov    %[Rd1], r2\n\t"
        : [Rd0] "=r" (d0), [Rd1] "=r" (d1)
        : [Rs] "m" (s)
        : "r0", "r1", "r2"
    );

    printf("d0 = %u\n", d0);
    printf("d1 = %u\n", d1);
}

int main(void) {
    ldr_pre_index();

    return 0;
}
