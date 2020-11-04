	
	.data
a:	.word 1
b:	.word 2
c:	.word 3
d:	.word 4
	
	.text
	la x5, a
	
	lw x10, 0(x5)
	lw x11, 4(x5)
	lw x12, 8(x5)
	lw x13, 12(x5)
	
	li a7, 10
	ecall
	