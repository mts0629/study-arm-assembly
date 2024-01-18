ENTRY(vectors_start)        /* Set an entrypoint: vectors_start */
SECTIONS
{
    . = 0x10000;            /* Set a location counter on the address 0x10000 */
    .text : {               /* text section: instructions */
        vectors.o           /* Put .text section of vectors.o */
        *(.text .rodata)    /* Put .text and .rodata sections of intermediate file */
    }
    .data : { *(.data) }    /* data section: static variables with initial values */
                            /* Put .data section of all intermediate files */
    .bss : { *(.bss) }      /* bss section: static variables with no initial values */
                            /* Put .bss section of all intermediate files */
    .stack : {              /* stack section: stack area */
        . = . + 0x1000;     /* Add 0x1000 to the location counter */
        . = ALIGN(4);       /* Align the location counter by 4 bytes */
        stack_top = .;      /* Set the address of the location counter to the top of the stack */
        . = . + 0x1000;
        . = ALIGN(4);
        irq_stack_top = .;  /* Set the address of the location counter to the top of the stack */
                            /* on IRQ mode */
    }
}
