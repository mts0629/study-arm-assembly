	.arch armv8-a
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"main.c"
	.text
	.section	.rodata
	.align	2
.LC0:
	.ascii	"1 + 2 = %d\012\000"
	.align	2
.LC1:
	.ascii	"(sum of 1 to 6) = %d\012\000"
	.align	2
.LC2:
	.ascii	"word_data[%d] = 0x%08x\012\000"
	.align	2
.LC3:
	.ascii	"data.val_int = %d, data.val_short = %d, data.val_ch"
	.ascii	"ar = %d\012\000"
	.align	2
.LC4:
	.ascii	"sum = %d\012\000"
	.text
	.align	2
	.global	main
	.syntax unified
	.arm
	.fpu softvfp
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r4, fp, lr}
	add	fp, sp, #8
	sub	sp, sp, #20
	.syntax divided
@ 14 "main.c" 1
	mov    r0, #1
	mov    r1, #2
	bl     addvalues
	mov    r3, r0
	
@ 0 "" 2
	.arm
	.syntax unified
	str	r3, [fp, #-24]
	ldr	r1, [fp, #-24]
	movw	r0, #:lower16:.LC0
	movt	r0, #:upper16:.LC0
	bl	printf
	.syntax divided
@ 27 "main.c" 1
	mov    r0, #1
	mov    r1, #2
	mov    r2, #3
	mov    r3, #4
	mov    lr, #5
	mov    ip, #6
	stmia  sp, {lr, ip}
	bl     add6values
	mov    r4, r0
	
@ 0 "" 2
	.arm
	.syntax unified
	str	r4, [fp, #-24]
	ldr	r1, [fp, #-24]
	movw	r0, #:lower16:.LC1
	movt	r0, #:upper16:.LC1
	bl	printf
	mov	r3, #0
	str	r3, [fp, #-28]
	b	.L2
.L3:
	movw	r3, #:lower16:word_data
	movt	r3, #:upper16:word_data
	ldr	r2, [fp, #-28]
	ldr	r3, [r3, r2, lsl #2]
	mov	r2, r3
	ldr	r1, [fp, #-28]
	movw	r0, #:lower16:.LC2
	movt	r0, #:upper16:.LC2
	bl	printf
	ldr	r3, [fp, #-28]
	add	r3, r3, #1
	str	r3, [fp, #-28]
.L2:
	ldr	r3, [fp, #-28]
	cmp	r3, #2
	ble	.L3
	mov	r3, #0
	str	r3, [fp, #-20]
	mov	r3, #0
	strh	r3, [fp, #-16]	@ movhi
	mov	r3, #0
	strb	r3, [fp, #-14]
	.syntax divided
@ 66 "main.c" 1
	mov    r1, #10
	mov    r2, #2
	mov    r3, #3
	str    r1, [sp, #8]
	strh   r2, [sp, #12]
	strb   r3, [sp, #14]
	add    r0, sp, #8
	bl     sum_struct_values
	mov    ip, r0
	
@ 0 "" 2
	.arm
	.syntax unified
	str	ip, [fp, #-24]
	ldr	r1, [fp, #-20]
	ldrsh	r3, [fp, #-16]
	mov	r2, r3
	ldrb	r3, [fp, #-14]	@ zero_extendqisi2
	movw	r0, #:lower16:.LC3
	movt	r0, #:upper16:.LC3
	bl	printf
	ldr	r1, [fp, #-24]
	movw	r0, #:lower16:.LC4
	movt	r0, #:upper16:.LC4
	bl	printf
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #8
	@ sp needed
	pop	{r4, fp, pc}
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0"
	.section	.note.GNU-stack,"",%progbits
