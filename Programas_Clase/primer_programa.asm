#-- Mi primer programa
#-- Asignar el valor 30 al registro x3
#-- y terminamos

	.text
	
	#-- x3 = 30
	addi x3, x0, 30
	
	#-- Terminar
	li a7, 10
	ecall