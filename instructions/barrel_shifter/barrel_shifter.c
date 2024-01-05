#include <stdint.h>
#include <stdio.h>

int main(void) {
    uint32_t rd1;

    __asm__(
        "mov    r0, #1\n\t"                 // r0 = 1
        "mov    r1, #2\n\t"                 // r1 = 2
        "add    r2, r0, r1, lsl #1\n\t"     // r2 = r0 + (r1 << 1) = 1 + 4 = 5
                                            // with barrel shifter
        "mov    %[Rd1], r2\n\t"
        : [Rd1] "=r" (rd1)
        :
        : "r0", "r1", "r2"
    );

    printf("rd1 = %u\n", rd1);

    return 0;
}
