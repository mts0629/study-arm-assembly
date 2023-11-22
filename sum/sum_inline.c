#include <stdio.h>

int sum(int limit) {
    int total;

    __asm__(
        "mov r0, #0\n\t"            // int total = 0;
        "mov r1, %[Rs1]\n\t"        // int i = limit;
        "loop:\n\t"                 // loop:
        "   add r0, r0, r1\n\t"     //     total = total + i;
        "   subs r1, r1, #1\n\t"    //     i = i - 1;
        "   bge loop\n\t"           //     if (i > 0) goto loop;
        "   mov %[Rd], r0\n\t"      // (total = r0)
        : [Rd] "=r"(total)
        : [Rs1] "r"(limit)
    );

    return total;
}

int main(void) {
    int val = 10;
    int retval = sum(val);

    printf("sum(%d) = %d\n", val, retval);

    return 0;
}
