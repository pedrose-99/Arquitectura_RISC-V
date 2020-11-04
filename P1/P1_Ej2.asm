#-- Ejercicio 2 p1

	.text
	
	#-- x5 = 0
	addi x5, x0, 0
	
bucle:
	#-- x5 = x5 + 2
	addi x5, x5, 2
	
	#-- Repita en bucle
	b bucle