#include <stdint.h>
#include <stdio.h>

int main(void) {
    uint32_t d;

    __asm__(
        "mov    r0, #2\n\t"
        "b      finish1\n\t"    // Branch to an address of "finish1"
        "mov    r0, #10\n\t"    // Skipped
        "finish1:\n\t"
        "mov    %[Rd], r0\n\t"
        : [Rd] "=r" (d)
        :
        : "r0"
    );

    printf("r0 = 0x%08x\n", d);

    return 0;
}
