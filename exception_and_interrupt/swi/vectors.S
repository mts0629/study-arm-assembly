    .text
    .code   32

    .global vectors_start
    .global vectors_end
/*
 * Vector table
 */
vectors_start:
    ldr     pc, reset_handler_addr
    ldr     pc, undef_handler_addr
    ldr     pc, swi_handler_addr
    ldr     pc, prefetch_abort_handler_addr
    ldr     pc, data_abort_handler_addr
    b       .
    ldr     pc, irq_handler_addr
    ldr     pc, fiq_handler_addr

reset_handler_addr:
    .word   reset_handler
undef_handler_addr:
    .word   halt
swi_handler_addr:
    .word   swi_handler
prefetch_abort_handler_addr:
    .word   halt
data_abort_handler_addr:
    .word   halt
irq_handler_addr:
    .word   halt
fiq_handler_addr:
    .word   halt
vectors_end:
/* Halt this program (infinite loop) */
halt:
    b       .

/*
 * Reset procedure
 * Launch with the supervisor mode
 */
reset_handler:
    /* Set the start address in the supervisor mode */
    ldr     sp, =stack_top
    /* Set the vector table */
    mov     r0, #0x00
    ldr     r1, =vectors_start
    ldr     r3, =vectors_end
keep_loading:
    ldr     r2, [r1, #0x0]
    str     r2, [r0, #0x0]
    add     r0, r0, #0x4
    add     r1, r1, #0x4
    cmp     r1, r3
    bne     keep_loading

    /* Change to the user mode */
    bic     r1, r0, #0x1f
    orr     r1, r1, #0x10
    msr     cpsr, r1
    ldr     sp, =user_stack_top

    /* Jump to a function: boot_main */
    bl      boot_main
    b       .

/*
 * SWI (Software interrupt) handler
 */
    .global swi_handler
swi_handler:
    stmfd   sp!, {r0-r12, lr}   /* Evacuate registers */
    ldr     r1, [lr, #-4]       /* Get a SWI number */
    bic     r1, r1, #0xff000000 /* Get a SWI number (lower 24 bits) */
    bl      c_swi_handler       /* Call a C function: c_swi_handler */
    ldmfd   sp!, {r0-r12, pc}   /* Restore registers */

/*
 * Get the processor mode
 */
    .global get_processor_mode
get_processor_mode:
    mrs     r0, cpsr
    bic     r0, r0, #0xffffffe0
    bx      lr

/*
 * Call SWI
 */
    .global call_swi
call_swi:
    push    {r0-r12, lr}
    swi     0x120001
    pop     {r0-r12, lr}
    bx      lr

    .end
