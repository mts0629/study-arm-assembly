#include <stdint.h>
#include <stdio.h>

int main(void) {
    uint32_t d;

    __asm__(
        "ldr    r0, =5\n\t"         // r0 = 5
        "ldr    r1, =2\n\t"         // r1 = 2
        "ldr    r2, =2\n\t"         // r2 = 2
        "mla    r3, r0, r1, r2\n\t" // r3 = r0 * r1 + r2
        "mov    %[Rd], r3\n\t"      // %[Rd] = r3
        : [Rd] "=r" (d)
        :
        : "r0", "r1", "r2", "r3"
    );

    printf("r3 = %u\n", d);

    return 0;
}
