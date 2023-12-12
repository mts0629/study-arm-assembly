#include <stdint.h>
#include <stdio.h>

int main(void) {
    uint32_t d;

    __asm__(
        "mov    r0, #2\n\t"
        "mov    r1, #1\n\t"
        "cmp    r0, r1\n\t"     // Compare r0, r1
        "beq    next\n\t"       // If r0 == r1, branch to "next"
        "mov    r2, #10\n\t"
        "b      finish\n\t"     // Branch to "finish"
        "next:\n\t"
        "mov    r2, #20\n\t"    // Skipped
        "finish:\n\t"
        "mov    %[Rd], r2\n\t"
        : [Rd] "=r" (d)
        :
        : "r0", "r1", "r2"
    );

    printf("r2 = %d\n", d);

    return 0;
}
