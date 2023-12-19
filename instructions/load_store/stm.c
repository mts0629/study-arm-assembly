#include <stdint.h>
#include <stdio.h>

#define SIZE 7

uint32_t s[SIZE] = { 0, 1, 2, 3, 4, 5, 6 };

void init_s(void) {
    for (size_t i = 0; i < SIZE; i++) {
        s[i] = (uint32_t)i;
    }
}

void print_s(void) {
    for (size_t i = 0; i < SIZE; i++) {
        printf("s[%u]=%u", i, s[i]);

        if (i < (SIZE - 1)) {
            printf(", ");
        }
    }
    printf("\n");
}

void stmia(void) {
    init_s();

    __asm__(
        "ldr    r0, =s\n\t"         // r0 = (address of s)
        "add    r0, r0, #12\n\t"    // r0 = (address of s[3])
        "mov    r1, #7\n\t"         // r1 = 7
        "mov    r2, #8\n\t"         // r2 = 8
        "mov    r3, #9\n\t"         // r3 = 9
        "stmia  r0!, {r1-r3}\n\t"   // *(r0) = s[3] = r1, r0++ (post-increment, write-back)
                                    // *(r0) = s[4] = r2, r0++
                                    // *(r0) = s[5] = r3, r0++
        :
        :
        : "r0", "r1", "r2", "r3"
    );

    print_s();
}

void stmib(void) {
    init_s();

    __asm__(
        "ldr    r0, =s\n\t"         // r0 = (address of s)
        "add    r0, r0, #12\n\t"    // r0 = (address of s[3])
        "mov    r1, #7\n\t"         // r1 = 7
        "mov    r2, #8\n\t"         // r2 = 8
        "mov    r3, #9\n\t"         // r3 = 9
        "stmib  r0!, {r1-r3}\n\t"   // *(++r0) = s[4] = r1 (pre-increment, write-back)
                                    // *(++r0) = s[5] = r2
                                    // *(++r0) = s[6] = r3
        :
        :
        : "r0", "r1", "r2", "r3"
    );

    print_s();
}

void stmda(void) {
    init_s();

    __asm__(
        "ldr    r0, =s\n\t"         // r0 = (address of s)
        "add    r0, r0, #12\n\t"    // r0 = (address of s[3])
        "mov    r1, #7\n\t"         // r1 = 7
        "mov    r2, #8\n\t"         // r2 = 8
        "mov    r3, #9\n\t"         // r3 = 9
        "stmda  r0!, {r1-r3}\n\t"   // *(r0) = s[3] = r3, r0-- (post-decrement, write-back)
                                    // *(r0) = s[2] = r2, r0--
                                    // *(r0) = s[1] = r1, r0--
        :
        :
        : "r0", "r1", "r2", "r3"
    );

    print_s();
}

void stmdb(void) {
    init_s();

    __asm__(
        "ldr    r0, =s\n\t"         // r0 = (address of s)
        "add    r0, r0, #12\n\t"    // r0 = (address of s[3])
        "mov    r1, #7\n\t"         // r1 = 7
        "mov    r2, #8\n\t"         // r2 = 8
        "mov    r3, #9\n\t"         // r3 = 9
        "stmdb  r0!, {r1-r3}\n\t"   // *(--r0) = s[2] = r3 (pre-decrement, write-back)
                                    // *(--r0) = s[1] = r2
                                    // *(--r0) = s[0] = r1
        :
        :
        : "r0", "r1", "r2", "r3"
    );

    print_s();
}

int main(void) {
    stmia();
    stmib();
    stmda();
    stmdb();

    return 0;
}