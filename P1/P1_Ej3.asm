#-- Ejercicio 3 P1

	.text
	
	#-- x3 = 0
	addi x3, x0, 0
	#-- x4 = 0
	addi x4, x0, 0
	#-- x5 = 0
	addi x5, x0, 0
	
bucle:
	#-- x3 = x3 + 1
	addi x3, x3, 1
	#-- x4 = x4 + 3
	addi x4, x4, 3
	#-- x5 = x5 + 5
	addi x5, x5, 5
	
	#-- Repita en bucle
	b bucle