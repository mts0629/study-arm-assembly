#include <stdio.h>
#include <stdint.h>

int main(void) {
    int32_t d;

    __asm__(
        "ldr    r0, =5\n\t"     // r0 = 5
        "rsb    r2, r0, #0\n\t" // r2 = 0 - r0
        "mov    %[Rd], r2\n\t"  // %[Rd] = r2
        : [Rd] "=r" (d)
        :
        : "r0", "r1", "r2"
    );

    printf("r2 = %d\n", d);

    return 0;
}
