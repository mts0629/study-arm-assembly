#include <stdint.h>
#include <stdio.h>

uint32_t s[] = { 0, 1, 2, 3, 4, 5, 6 };

void ldmia(void) {
    uint32_t r0, r1, r2, r3;

    __asm__(
        "ldr    r0, =s\n\t"         // r0 = (address of s)
        "add    r0, r0, #12\n\t"    // r0 = (address of s[3])
        "ldmia  r0!, {r1-r3}\n\t"   // r1 = *(r0) = s[3], r0++ (post-increment, write-back)
                                    // r2 = *(r0) = s[4], r0++
                                    // r2 = *(r0) = s[5], r0++
        "mov    %[Rd0], r0\n\t"
        "mov    %[Rd1], r1\n\t"
        "mov    %[Rd2], r2\n\t"
        "mov    %[Rd3], r3\n\t"
        : [Rd0] "=r" (r0), [Rd1] "=r" (r1), [Rd2] "=r" (r2), [Rd3] "=r" (r3)
        :
        : "r0", "r1", "r2", "r3"
    );

    printf("r0=0x%08x, r1=%u, r2=%u, r3=%u\n", r0, r1, r2, r3);
}

void ldmib(void) {
    uint32_t r0, r1, r2, r3;

    __asm__(
        "ldr    r0, =s\n\t"         // r0 = (address of s)
        "add    r0, r0, #12\n\t"    // r0 = (address of s[3])
        "ldmib  r0!, {r1-r3}\n\t"   // r1 = *(++r0) = s[4] (pre-increment, write-back)
                                    // r2 = *(++r0) = s[5]
                                    // r2 = *(++r0) = s[6]
        "mov    %[Rd0], r0\n\t"
        "mov    %[Rd1], r1\n\t"
        "mov    %[Rd2], r2\n\t"
        "mov    %[Rd3], r3\n\t"
        : [Rd0] "=r" (r0), [Rd1] "=r" (r1), [Rd2] "=r" (r2), [Rd3] "=r" (r3)
        :
        : "r0", "r1", "r2", "r3"
    );

    printf("r0=0x%08x, r1=%u, r2=%u, r3=%u\n", r0, r1, r2, r3);
}

void ldmda(void) {
    uint32_t r0, r1, r2, r3;

    __asm__(
        "ldr    r0, =s\n\t"         // r0 = (address of s)
        "add    r0, r0, #12\n\t"    // r0 = (address of s[3])
        "ldmda  r0!, {r1-r3}\n\t"   // r3 = *(r0) = s[3], r0-- (post-decrement, write-back)
                                    // r2 = *(r0) = s[2], r0--
                                    // r1 = *(r0) = s[1], r0--
        "mov    %[Rd0], r0\n\t"
        "mov    %[Rd1], r1\n\t"
        "mov    %[Rd2], r2\n\t"
        "mov    %[Rd3], r3\n\t"
        : [Rd0] "=r" (r0), [Rd1] "=r" (r1), [Rd2] "=r" (r2), [Rd3] "=r" (r3)
        :
        : "r0", "r1", "r2", "r3"
    );

    printf("r0=0x%08x, r1=%u, r2=%u, r3=%u\n", r0, r1, r2, r3);
}

void ldmdb(void) {
    uint32_t r0, r1, r2, r3;

    __asm__(
        "ldr    r0, =s\n\t"         // r0 = (address of s)
        "add    r0, r0, #12\n\t"    // r0 = (address of s[3])
        "ldmdb  r0!, {r1-r3}\n\t"   // r3 = *(--r0) = s[2] (pre-decrement, write-back)
                                    // r2 = *(--r0) = s[1]
                                    // r1 = *(--r0) = s[0]
        "mov    %[Rd0], r0\n\t"
        "mov    %[Rd1], r1\n\t"
        "mov    %[Rd2], r2\n\t"
        "mov    %[Rd3], r3\n\t"
        : [Rd0] "=r" (r0), [Rd1] "=r" (r1), [Rd2] "=r" (r2), [Rd3] "=r" (r3)
        :
        : "r0", "r1", "r2", "r3"
    );

    printf("r0=0x%08x, r1=%u, r2=%u, r3=%u\n", r0, r1, r2, r3);
}

int main(void) {
    ldmia();
    ldmib();
    ldmda();
    ldmdb();

    return 0;
}