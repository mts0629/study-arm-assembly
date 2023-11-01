#include <stdio.h>

int addvalues(int val1, int val2) {
    int result;

    // GCC extended asm
    __asm__(
        "ADD %[Rd],%[Rs1],%[Rs2]"               // Rd = Rs1 + Rs2
        : [Rd] "=r" (result)                    // Output operand: register, read-only
        : [Rs1] "r" (val1), [Rs2] "r" (val2)    // Input operands: register
    );

    return result;
}

int main(void) {
    int val = addvalues(1, 2);
    printf("addvalues = %d\n", val);
    return 0;
}
