#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint32_t d;

    __asm__(
        "mov    r0, #5\n\t"
        "mov    r1, #3\n\t"
        "eor    r0, r0, r1\n\t" // r0 = r0 (0b'0101) ^ r1 (0b'0011) = 6 (0b'0110)
        "mov    %[Rd], r0\n\t"
        : [Rd] "=r" (d)
        :
        : "r0", "r1"
    );

    printf("r0 = 0x%08x\n", d);

    return 0;
}
