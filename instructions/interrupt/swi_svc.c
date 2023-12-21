#include <stdint.h>
#include <stdio.h>

char str[] = "hello\n";

void swi(void) {
    __asm__(
        "mov    r0, #1\n\t"     // r0: arg1 unsigned int fd = 1 (= STDOUT)
        "ldr    r1, =str\n\t"   // r1: const char* buf = str
        "mov    r2, #7\n\t"     // r2: size_t count = 7
        "mov    r7, #4\n\t"     // sys# = 4, convension for EABI (Embedded Application Binary Interface)
        "swi    #0x900004\n\t"  // SWI# = 900004, sys_write(fd, str, count)
                                // Old mnemonic: "Software Interrupt"
    );
}

void svc(void) {
    __asm__(
        "mov    r0, #1\n\t"     // r0: arg1 unsigned int fd = 1 (= STDOUT)
        "ldr    r1, =str\n\t"   // r1: const char* buf = str
        "mov    r2, #7\n\t"     // r2: size_t count = 7
        "mov    r7, #4\n\t"     // sys# = 4
        "svc    #0x900004\n\t"  // SVC# = 900004, sys_write(fd, str, count)
                                // Current mnemonic: "Supervisor Call"
    );
}

int main(void) {
    swi();
    svc();

    return 0;
}
