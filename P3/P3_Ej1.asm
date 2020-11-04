#-- Inicializar los registros x5,x6,x7,x8 con 5,6,7,8
#-- li para transferir registros a x15,x16,x17, x18 (usa mv)

	.text
	
	li x5, 5
	li x6, 6
	li x7, 7
	li x8, 8
	
	mv x15, x5
	mv x16, x6
	mv x17, x7
	mv x18, x8
	
	li a7, 10
	ecall
	
#-- Respuesta:
#2. Tiene 10 instrucciones
#3. Ocupa 40 bytes
