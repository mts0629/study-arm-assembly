    .text
    .align  4
    .global sum_struct_values
sum_struct_values:          @ Function "sum_struct_values"
    ldrh    r1, [r0, #4]    @ r1 = simple_struct.val_short
    ldr     r2, [r0, #0]    @ r2 = simple_struct.val_int
    ldrb    r3, [r0, #6]    @ r3 = simple_struct.val_char
    add     r0, r1, r2
    add     r0, r0, r3      @ r0 = r1 + r2 + r3
    bx      lr
