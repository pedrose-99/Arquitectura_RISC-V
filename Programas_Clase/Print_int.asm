#-- Plantilla ejemplo

	#-- codigo del servicio exit
	.eqv EXIT 10
	
	.text
	
	li a0, 300
	li a7, 1
	ecall
	
	
	li a7, EXIT
	ecall