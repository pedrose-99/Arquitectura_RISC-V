#-- Calculo expresion f = (a + b + c) - (d - 3)

	.data
	
a:	.word -5
b:	.word 2
c:	.word 30
d:	.word 5
f:	.word 0

	.text
	
	la x10, a
	la x11, b
	la x12, c
	la x13, d
	la x14, f
	
	lw x15, 0(x10)
	lw x16, 0(x11)
	lw x17, 0(x12)
	lw x18, 0(x13)
	lw x19, 0(x14)
	
	add x19, x15, x16
	add x19, x19, x17
	sub x19, x19, x18
	addi x19, x19, 3
	
	sw x19, 0(x14)
	
	li a7, 10
	ecall