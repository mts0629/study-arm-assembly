#include <stdint.h>
#include <stdio.h>

void ldr_pre_index(void) {
    uint32_t s[] = { 1, 2, 3 };
    uint32_t d1, d2;

    (void)s;

    __asm__(
        "ldr    r0, =.LC0\n\t"          // r0 = (address of s, ".LC0" is a label of it)
        "ldr    r1, [r0, #0x4]!\n\t"    // r1 = *(r0 + 4[B]) = *&s[1], r0 += 4[B] (pre-index with write-back)
        "ldr    r2, [r0, #0x4]\n\t"     // r2 = *(r0 + 4[B]) = *&s[2] (pre-index)
        "mov    %[Rd1], r1\n\t"
        "mov    %[Rd2], r2\n\t"
        : [Rd1] "=r" (d1), [Rd2] "=r" (d2)
        :
        : "r0", "r1", "r2"
    );

    printf("d1 = %u\n", d1);
    printf("d2 = %u\n", d2);
}

int main(void) {
    ldr_pre_index();

    return 0;
}
