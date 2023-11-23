#include <stdio.h>

int main(void) {
    int a = 1, b = 2, val;

    __asm__(
        "   mov r0, %[Rs1]\n\t" // Assign a to r0
        "   mov r1, %[Rs2]\n\t" // Assign b to r1
        "   bl  addvalues\n\t"  // Branch to addvalues,
                                // with storing return address into link register
        "   mov %[Rd], r0\n\t"  // Assign r0 to val
        "   b   finish\n\t"     // Branch to "finish"
        "addvalues:\n\t"
        "   add r0, r0, r1\n\t" // r0 = r0 + r1
        "   bx  lr\n\t"         // Branch to return address (stored in link register)
        "finish:\n\t"
        : [Rd] "=r"(val)
        : [Rs1] "r"(a), [Rs2] "r"(b)
        : "r0", "r1", "lr"
    );

    printf("addvalues = %d\n", val);
    return 0;
}
