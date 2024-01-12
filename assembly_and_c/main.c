#include <stdio.h>

extern int word_data[3];

typedef struct {
    int val_int;
    short val_short;
    char val_char;
} simple_struct;

int main(void) {
    int sum;

    __asm__(
                                // On register:
        "mov    r0, #1\n\t"     // 1st argument
        "mov    r1, #2\n\t"     // 2nd argument
        "bl     addvalues\n\t"  // Call "addvalues"
        "mov    %[Rd], r0\n\t"  // Return value is stored in r0
        : [Rd] "=r" (sum)
        :
        : "r0", "r1"
    );

    printf("1 + 2 = %d\n", sum); // = 3

    __asm__(
                                    // On register:
        "mov    r0, #1\n\t"         // 1st argument
        "mov    r1, #2\n\t"         // 2nd argument
        "mov    r2, #3\n\t"         // 3rd argument
        "mov    r3, #4\n\t"         // 4th argument
                                    // On stack:
        "mov    lr, #5\n\t"         // 5th argument (lr: r14)
        "mov    ip, #6\n\t"         // 6th argument (ip: r12)
        "stmia  sp, {lr, ip}\n\t"   // 5th, 6th are put on the stack
        "bl     add6values\n\t"     // Call "add6values"
        "mov    %[Rd], r0\n\t"
        : [Rd] "=r" (sum)
        :
        : "r0", "r1", "r2", "r3", "lr", "ip"
    );

    printf("(sum of 1 to 6) = %d\n", sum); // = 21

    for (int i = 0; i < 3; i++) {
        printf("word_data[%d] = 0x%08x\n", i, word_data[i]);
    }

    simple_struct data = { 0, 0, 0 };

    // Stack:
    // (sp)      |
    // (sp) + 4  | sum
    // (sp) + 8  | data.val_int (head of data)
    // (sp) + 12 | data.val_short | (sp) + 10 | data.val_char
    // (sp) + 16 | ...

    __asm__(
        "mov    r1, #10\n\t"            // r1 = 10
        "mov    r2, #2\n\t"             // r2 = 2
        "mov    r3, #3\n\t"             // r3 = 3
        "str    r1, [sp, #8]\n\t"       // *(sp + 8) = data.val_int = 10
        "strh   r2, [sp, #12]\n\t"      // *(sp + 12) = data.val_short = 2
        "strb   r3, [sp, #14]\n\t"      // *(sp + 14) = data.val_char = 3
        "add    r0, sp, #8\n\t"         // r0 = (sp + 8)
        "bl     sum_struct_values\n\t"  // Call "sum_struct_values"
        "mov    %[Rd], r0\n\t"
        : [Rd] "=r" (sum)
        :
        : "r0", "r1", "r2", "r3"
    );

    printf("data.val_int = %d, data.val_short = %d, data.val_char = %d\n", 
        data.val_int, data.val_short, data.val_char
    );
    printf("sum = %d\n", sum); // = 15

    return 0;
}
