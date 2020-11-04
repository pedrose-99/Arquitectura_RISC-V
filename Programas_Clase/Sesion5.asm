#-- Implementar expresion f = (a-b) + (c +5)

	.text
	
	#-- inicializas variables
	# t0 = a, t1 = b, t2 = c
	
	li t0, 1
	li t1, 2
	li t2, 3
	
	#-- Calculo expresion
	
	sub t3, t0, t1
	
	addi t4, t2, 5
	
	add t6, t3, t4
	
	li a7, 10
	ecall