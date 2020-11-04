#-- Hacer fibonachi

	.data
	
fib0:	.word 0
fib1:	.word 1

	.text
	
	la x11, fib0
	
	lw x12, 0(x11)
	lw x13, 4(x11)
	
	addi x11, x11, 8	
bucle:
	
	add x14, x13, x12
	
	sw x14, 0(x11)
	
	addi x11, x11, 4
	
	mv x12, x13
	mv x13, x14	
	
	b bucle	