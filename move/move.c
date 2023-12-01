#include <stdint.h>
#include <stdio.h>

void mov(void) {
    uint32_t d;

    __asm__(
        "mov r0, #1\n\t"    // r0 = 1
        "mov %[Rd], r0\n\t" // %Rd = r0
        : [Rd] "=r" (d)
        :
        : "r0"
    );

    printf("r0 = 0x%08x\n", d);
}

void mvn(void) {
    uint32_t d;

    __asm__(
        "mvn r0, #1\n\t"    // r0 = ^1
        "mov %[Rd], r0\n\t" // %Rd = r0
        : [Rd] "=r" (d)
        :
        : "r0"
    );

    printf("r0 = 0x%08x\n", d);
}

int main(void) {
    mov();
    mvn();

    return 0;
}
