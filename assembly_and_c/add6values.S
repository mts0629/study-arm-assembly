    .global add6values
    .text
    .align  4
add6values:             @ Function "addvalues": val1 + val2 + val3 + val4 + val5 + val6
    ;                   @ armeabi: r0 - r3 <- val1 - val4
    add r0, r0, r1      @ r0 = val1 + val2
    add r2, r2, r3      @ r2 = val3 + val4
    add r0, r0, r2      @ r0 = sum(val1, val2, ..., val4)
                        @ armeabi: 5th and 6th arguments are put on the stack
    ldr r1, [sp, #0]    @ r1 = val5
    ldr r2, [sp, #4]    @ r2 = val6
    add r0, r0, r1      @ r0 = sum(val1, val2, ..., val5)
    add r0, r0, r2      @ r0 = sum(val1, val2, ..., val6)
    bx  lr              @ End the subroutine
