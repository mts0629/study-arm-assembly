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
    .word   halt
prefetch_abort_handler_addr:
    .word   halt
data_abort_handler_addr:
    .word   halt
irq_handler_addr:
    .word   irq_handler
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

    /* Get the status register */
    mrs     r0, cpsr

    /* Change to the IRQ mode */
    bic     r1, r0, #0x1f
    orr     r1, r1, #0x12
    msr     cpsr, r1
    /* Set the start address in the IRQ mode */
    ldr     sp, =irq_stack_top

    /* Return to the supervisor mode */
    msr     cpsr, r0
    /* Jump to a boot_main */
    bl      boot_main
    b       .

/*
 * IRQ handler
 */
    .global irq_handler
irq_handler:
    push    {r0-r12, lr}    /* Save the registers */
    bl      c_irq_handler   /* Call a C function: c_irq_handler */
    pop     {r0-r12, lr}    /* Restore the registers */
    subs    pc, lr, #4      /* Set a return address: (lr - 4) */

/*
 * Enable IRQ
 */
    .global enable_irq
enable_irq:
    mrs     r0, cpsr
    bic     r0, r0, #0x80
    msr     cpsr_c, r0
    bx      lr

    .end
