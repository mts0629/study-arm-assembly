#include <stdint.h>
#include <stdio.h>

void push_pop(void) {
    uint32_t d3, d4, d5;

    __asm__(
        "mov    r0, #1\n\t" // r0 = 1
        "mov    r1, #2\n\t" // r1 = 2
        "mov    r2, #3\n\t" // r2 = 3
        "push   {r0}\n\t"   // *(SP) = r0, SP++
        "push   {r1}\n\t"   // *(SP) = r1, SP++
        "push   {r2}\n\t"   // *(SP) = r2, SP++
        "pop    {r3}\n\t"   // SP--, r3 = *(SP) (= r2)
        "pop    {r4}\n\t"   // SP--, r4 = *(SP) (= r1)
        "pop    {r5}\n\t"   // SP--, r5 = *(SP) (= r0)
        "mov    %0, r3\n\t"
        "mov    %1, r4\n\t"
        "mov    %2, r5\n\t"
        : "=r" (d3), "=r" (d4), "=r" (d5)
        :
        : "r1", "r2", "r3", "r4", "r5"
    );

    printf("r3=%u, r4=%u, r5=%u\n", d3, d4, d5);
}

void push_pop_multi(void) {
    uint32_t d3, d4, d5;

    __asm__(
        "mov    r0, #1\n\t"     // r0 = 1
        "mov    r1, #2\n\t"     // r1 = 2
        "mov    r2, #3\n\t"     // r2 = 3
        "push   {r0-r2}\n\t"    // *(SP) = r2, SP++
                                // *(SP) = r1, SP++
                                // *(SP) = r0, SP++
        "pop    {r3-r5}\n\t"    // SP--, r3 = *(SP) (= r0)
                                // SP--, r4 = *(SP) (= r1)
                                // SP--, r5 = *(SP) (= r2)
        "mov    %0, r3\n\t"
        "mov    %1, r4\n\t"
        "mov    %2, r5\n\t"
        : "=r" (d3), "=r" (d4), "=r" (d5)
        :
        : "r1", "r2", "r3", "r4", "r5"
    );

    printf("r3=%u, r4=%u, r5=%u\n", d3, d4, d5);
}

int main(void) {
    push_pop();
    push_pop_multi();

    return 0;
}
