                        @ Pseudo instructions
    .global addvalues   @ Enable a label "addvalues" to be refered externally
    .text               @ Text section
    .align  4           @ 4 bytes alignment
addvalues:              @ Function "addvalues": val1 + val2
    ;                   @ armeabi: r0 <- val1, r1 <- val2, 1st to 4th argument are put on r0 to r3
                        @ armeabi: a return value is put on r0
    add r0, r0, r1      @ r0 = r0 + r1
    bx  lr              @ End the subroutine
