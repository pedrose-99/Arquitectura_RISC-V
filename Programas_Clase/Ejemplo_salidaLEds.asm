#-- Ejemplo de escritura de un valor en el puerto de salida de los LEDs

	.eqv VALOR, 0xAA
	.eqv LEDS, 0xFFFF0000
	.text
	
	#-- El puerto de salida esta en la direccion 0xFFFF0000
	li x5, LEDS
	
	li x6, VALOR
	
	sw x6, 0(x5)
	
	li a7, 10
	ecall