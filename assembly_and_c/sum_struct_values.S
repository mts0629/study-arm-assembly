    .data
    .align 4
    .global data
data:                       @ struct "data"
    .word   1               @ 1st data member: 4 bytes
    .hword  2               @ 2nd data member: 2 bytes
    .byte   3               @ 3rd data member: 1 byte

    .text
    .align  4
    .global sum_struct_values
sum_struct_values:          @ Function "sum_struct_values"
    ldrsh   r1, [r0, #4]    @ r1 = simple_struct.val_short
    ldr     r2, [r0, #0]    @ r2 = simple_struct.val_int
    ldrsb   r3, [r0, #6]    @ r3 = simple_struct.val_char
    add     r0, r1, r2
    add     r0, r0, r3      @ r0 = r1 + r2 + r3
    bx      lr
