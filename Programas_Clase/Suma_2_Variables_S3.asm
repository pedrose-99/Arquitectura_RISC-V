#-- Ejemplo suma 2 variables
#.. resultado se deposita en memoria (v3 = v1 + v2)

	.data
	
v1:	.word 1
v2:	.word 2
v3:	.word 0
	
	.text
	
	#-- Punteros a las variables
	la x5, v1
	#la x6, v2,
	#la x7, v3
	
	#-- Lectura de las variables v1, v2
	
	lw x10, 0(x5)
	#lw x11, 0(x6)
	
	#accedes a la direccion 0x10010004(v2)
	lw x11, 4(x5)
	
	#-- Suma de v1 + v2
	add x12, x10, x11
	
	sw x12, 8(x5)
	
	li a7, 10
	ecall