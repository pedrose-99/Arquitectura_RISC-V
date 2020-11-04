#-- Defina variable contador cuyo valor inicial sea dado por el identificador inicio


	.eqv INICIO 100
	.eqv INC 10
	.eqv LEDS 0xFFFF0000
	.data
contador: .word 0

	.text
	li x5, INICIO
	
	la x6, contador
	
	li x6, LEDS
	
bucle:
	sw x5, 0(x6)
	
	addi x5, x5, INC
	
	b bucle
