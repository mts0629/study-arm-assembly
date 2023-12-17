#include <stdint.h>
#include <stdio.h>

uint32_t s[] = { 1, 2, 3 };

void ldr_pre_index(void) {
    uint32_t d1, d2;

    __asm__(
        "ldr    r0, =s\n\t"             // r0 = (address of s, "s" is a label of it)
        "ldr    r1, [r0, #0x4]!\n\t"    // r1 = *(r0 + 4[B]) = *&s[1], r0 += 4[B] (pre-index with write-back)
        "ldr    r2, [r0, #0x4]\n\t"     // r2 = *(r0 + 4[B]) = *&s[2] (pre-index)
        "mov    %[Rd1], r1\n\t"
        "mov    %[Rd2], r2\n\t"
        : [Rd1] "=r" (d1), [Rd2] "=r" (d2)
        :
        : "r0", "r1", "r2"
    );

    printf("d1 = %u\n", d1);
    printf("d2 = %u\n", d2);
}

void ldr_post_index(void) {
    uint32_t d1, d2;

    __asm__(
        "ldr    r0, =s\n\t"         // r0 = (address of s)
        "ldr    r1, [r0], #0x4\n\t" // r1 = *(r0) = *&s[0], r0 += 4[B] (post-index)
        "ldr    r2, [r0]\n\t"       // r2 = *(r0) = *&s[1]
        "mov    %[Rd1], r1\n\t"
        "mov    %[Rd2], r2\n\t"
        : [Rd1] "=r" (d1), [Rd2] "=r" (d2)
        :
        : "r0", "r1", "r2"
    );

    printf("d1 = %u\n", d1);
    printf("d2 = %u\n", d2);
}

void ldr_barrel_shifter(void) {
    uint32_t d;

    __asm__(
        "ldr    r0, =s\n\t"                 // r0 = (address of s)
        "mov    r1, #1\n\t"                 // r1 = 1
        "ldr    r2, [r0, r1, lsl #0x2]\n\t" // r2 = *(r0 + (r1 << 2)) = *&s[1] (pre-index)
        "mov    %[Rd], r2\n\t"
        : [Rd] "=r" (d)
        :
        : "r0", "r1", "r2"
    );

    printf("d = %u\n", d);
}

void ldr_immediate(void) {
    uint32_t d;

    __asm__(
        "ldr    r0, =100\n\t"   // r0 = 100
        "mov    %[Rd], r0\n\t"
        : [Rd] "=r" (d)
        :
        : "r0"
    );

    printf("d = %u\n", d);
}

int main(void) {
    ldr_pre_index();

    ldr_post_index();

    ldr_barrel_shifter();

    ldr_immediate();

    return 0;
}
