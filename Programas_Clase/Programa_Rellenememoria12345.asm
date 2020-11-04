#-- Rellenando la memoria con los valores 1,2,3,4,5

	.data
	
inicio:

	.text
	
	la x5, inicio
	
	li x6, 1
	
bucle:	
	sw x6, 0(x5)
	
	addi x6, x6, 1
	addi x5, x5, 4
	b bucle 