#-- Programa contador
#-- el registro x5 srementa indefinidamente

	.text
	
	#-- x5 = 0
	addi x5, x0, 0
	
bucle:
	#-- x5 = x5 +1
	addi x5, x5, 1
	
	#-- Repita en bucle
	b bucle