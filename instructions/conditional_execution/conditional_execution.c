#include <stdint.h>
#include <stdio.h>

// Conditional execution by branching
void exec_with_branch(const int val) {
    uint32_t rd1, rd2;

    __asm__(
        "mov    r0, %[Rs1]\n\t" // r0 = val
        "mov    r1, #0\n\t"     // r1 = 0
        "mov    r2, #0\n\t"     // r2 = 0
        "cmp    r0, #0\n\t"
        "beq    finish_\n\t"    // if (r0 == 0) goto finish_
        "blt    minus_\n\t"     // else if (r0 < 0) goto minus_
        "add    r1, r1, #1\n\t" // else r1 = r1 + 1
        "b      finish_\n\t"    // goto finish_
        "minus_:\n\t"           // minus_
        "add    r2, r2, #1\n\t" // r2 = r2 + 1
        "finish_:\n\t"          // finish_
        "mov    %[Rd1], r1\n\t"
        "mov    %[Rd2], r2\n\t"
        : [Rd1] "=r" (rd1), [Rd2] "=r" (rd2)
        : [Rs1] "r" (val)
        : "r0", "r1", "r2"
    );

    printf("%2d : p = %u, m = %u\n", val, rd1, rd2);
}

// Conditional execution by instructions
void cond_exec(const int val) {
    uint32_t rd1, rd2;

    __asm__(
        "mov    r0, %[Rs1]\n\t" // r0 = val
        "mov    r1, #0\n\t"     // r1 = 0
        "mov    r2, #0\n\t"     // r2 = 0
        "cmp    r0, #0\n\t"
        "addgt  r1, r1, #1\n\t" // if (r0 > 0) r1 = r1 + 1
        "addlt  r2, r2, #1\n\t" // if (r0 < 0) r2 = r2 + 1
        "mov    %[Rd1], r1\n\t"
        "mov    %[Rd2], r2\n\t"
        : [Rd1] "=r" (rd1), [Rd2] "=r" (rd2)
        : [Rs1] "r" (val)
        : "r0", "r1", "r2"
    );

    printf("%2d : p = %u, m = %u\n", val, rd1, rd2);
}

int main(void) {
    exec_with_branch(-1);
    exec_with_branch(0);
    exec_with_branch(1);

    cond_exec(-1);
    cond_exec(0);
    cond_exec(1);

    return 0;
}
