.text
    .align 2
    .global _start

_start:
    adr r1, msg     @address
    mov r0, #1      @stdout
    mov r2, #13     @length
    swi #0x900004   @sys_write

    mov r0, #0
    swi #0x900001   @sys_exit

    .align  2
msg:
    .asciz  "hello, world\n"

