#-- Defina variable contador cuyo valor inicial sea dado por el identificador inicio


	.eqv INICIO 0
	.eqv INC 1
	.eqv DISPLAY 0xFFFF0010
	
	.data
contador: .word 0

	.text
	li x5, INICIO
	
	li x6, DISPLAY
	
bucle:
	sw x5, 0(x6)
	
	addi x5, x5, INC
	
	b bucle