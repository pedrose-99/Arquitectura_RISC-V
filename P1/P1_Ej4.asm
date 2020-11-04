#-- Ejercicio 4 P1

	.text
	
	#-- x6 = 0
	addi x6, x0, 0
	#-- x6 = x6 - 1
	addi x6, x6, -1
	
	#-- Valor final = 0xfffffff
	
	li a7, 10
	ecall