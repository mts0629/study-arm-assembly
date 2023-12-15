#include <stdint.h>
#include <stdio.h>

void ldr_pre_index(void) {
    uint32_t d[] = { 1, 2 };
    uint32_t d0, d1;

    __asm__(
        "ldr    r0, [%[Rs]]\n\t"        // r0 = *(&d) (pre-index)
        "ldr    r1, [%[Rs], #0x4]\n\t"  // r1 = *(&d + 4 B) (= *&d[1]) (pre-index)
        "mov    %[Rd0], r0\n\t"
        "mov    %[Rd1], r1\n\t"
        : [Rd0] "=r" (d0), [Rd1] "=r" (d1)
        : [Rs] "r" (d)
        : "r0", "r1"
    );

    printf("d0 = %u\n", d0);
    printf("d1 = %u\n", d1);
}

int main(void) {
    ldr_pre_index();

    return 0;
}
