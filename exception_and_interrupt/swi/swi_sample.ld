ENTRY(vectors_start)
SECTIONS
{
    . = 0x10000;
    .text : {
        vectors.o
        *(.text .rodata)
    }
    .data : { *(.data) }
    .bss : { *(.bss) }
    .stack : {
        . = . + 0x1000;     /* Stack area on the supervisor mode, 4 KiB */
        . = ALIGN(4);
        stack_top = .;
        . = . + 0x1000;     /* Stack area on the user mode, 4 KiB */
        . = ALIGN(4);
        user_stack_top = .;
    }
}
