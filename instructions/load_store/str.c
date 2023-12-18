#include <stdint.h>
#include <stdio.h>

uint32_t s[] = { 1, 2, 3 };

void str_pre_index(void) {
    s[0] = 1, s[1] = 2, s[2] = 3;

    __asm__(
        "ldr    r0, =s\n\t"             // r0 = (address of s, "s" is a label of it)
        "mov    r1, #4\n\t"             // r1 = 4
        "mov    r2, #5\n\t"             // r2 = 5
        "str    r1, [r0, #0x4]!\n\t"    // *(r0 + 4[B]) = *&s[1] = r1, r0 += 4[B] (pre-index with write-back)
        "str    r2, [r0, #0x4]\n\t"     // *(r0 + 4[B]) = *&s[2] = r2 (pre-index)
        :
        :
        : "r0", "r1", "r2"
    );

    printf("s[0]=%u, s[1]=%u, s[2]=%u\n", s[0], s[1], s[2]);
}

void str_post_index(void) {
    s[0] = 1, s[1] = 2, s[2] = 3;

    __asm__(
        "ldr    r0, =s\n\t"         // r0 = (address of s, "s" is a label of it)
        "mov    r1, #4\n\t"         // r1 = 4
        "mov    r2, #5\n\t"         // r2 = 5
        "str    r1, [r0], #0x4\n\t" // *(r0) = *&s[0] = r1, r0 += 4[B] (post-index)
        "str    r2, [r0], #0x4\n\t" // *(r0 + 4[B]) = *&s[1] = r2
        :
        :
        : "r0", "r1", "r2"
    );

    printf("s[0]=%u, s[1]=%u, s[2]=%u\n", s[0], s[1], s[2]);
}

void str_barrel_shifter(void) {
    s[0] = 1, s[1] = 2, s[2] = 3;

    __asm__(
        "ldr    r0, =s\n\t"                 // r0 = (address of s)
        "mov    r1, #1\n\t"                 // r1 = 1
        "mov    r2, #4\n\t"                 // r2 = 4
        "str    r2, [r0, r1, lsl #0x2]\n\t" // *(r0 + (r1 << 2)) = *&s[1] = r2 (pre-index)
        :
        :
        : "r0", "r1", "r2"
    );

    printf("s[0]=%u, s[1]=%u, s[2]=%u\n", s[0], s[1], s[2]);
}

int main(void) {
    str_pre_index();

    str_post_index();

    str_barrel_shifter();

    return 0;
}
