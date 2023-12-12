#include <stdint.h>
#include <stdio.h>

int main(void) {
    uint32_t d;

    __asm__(
        "mov    r0, #2\n\t"
        "bl     subr1\n\t"      // Subroutine call of "subr1"
        "beq    finish2\n"      // Branch to "finish2"
        "subr1:\n\t"
        "mov    r0, #10\n\t"
        "bx     lr\n\t"         // Return to the next address of subroutine call
        "finish2:\n\t"
        "mov    %[Rd], r0\n\t"
        : [Rd] "=r" (d)
        :
        : "r0", "r14"           // r14: link register (lr), return address of BL is stored
    );

    printf("r0 = %d\n", d);

    return 0;
}
