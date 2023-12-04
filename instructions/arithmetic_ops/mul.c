#include <stdint.h>
#include <stdio.h>

int main(void) {
    uint32_t d;

    __asm__(
        "ldr    r0, =5\n\t"     // r0 = 5
        "ldr    r1, =2\n\t"     // r1 = 2
        "mul    r2, r0, r1\n\t" // r2 = r0 * r1
        "mov    %[Rd], r2\n\t"  // %[Rd] = r2
        : [Rd] "=r" (d)
        :
        : "r0", "r1", "r2"
    );

    printf("r2 = %u\n", d);

    return 0;
}
