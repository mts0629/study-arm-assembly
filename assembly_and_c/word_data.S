    .global word_data
    .data                                       @ Data section
    .align  4
word_data:
    .word 0x01234567, 0x11223344, 0x00000000    @ An array of words (4 byte x 3)
