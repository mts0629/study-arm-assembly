#include <stdint.h>
#include <stdio.h>

int main(void) {
    int32_t rd0, rd1, rd2, rd3, rd4;

    __asm__(
        "ldr    r0, =10\n\t"
        "ror    r1, r0, #1\n\t"     // Right rorate 1 bit
        "ror    r2, r0, #2\n\t"     // Right rorate 2 bits
        "ror    r3, r0, #30\n\t"    // Right rorate 30 bits
        "ror    r4, r0, #31\n\t"    // Right rorate 31 bits
        "mov    %[Rd0], r0\n\t"
        "mov    %[Rd1], r1\n\t"
        "mov    %[Rd2], r2\n\t"
        "mov    %[Rd3], r3\n\t"
        "mov    %[Rd4], r4\n\t"
        : [Rd0] "=r" (rd0), [Rd1] "=r" (rd1), [Rd2] "=r" (rd2),
          [Rd3] "=r" (rd3), [Rd4] "=r" (rd4)
        :
        : "r0", "r1", "r2", "r3", "r4"
    );

    printf("r0 = %d (0x%08x)\n", rd0, rd0);
    printf("r1 = %d (0x%08x)\n", rd1, rd1);
    printf("r2 = %d (0x%08x)\n", rd2, rd2);
    printf("r3 = %d (0x%08x)\n", rd3, rd3);
    printf("r4 = %d (0x%08x)\n", rd4, rd4);

    return 0;
}
