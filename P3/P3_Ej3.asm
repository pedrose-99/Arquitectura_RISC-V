#-- Segmento de datos con 4 variables: v1, v2, v3, v4 = 0x12345678, 0x11223344, 0xCACABACA, 0x00FABADA
	
	
	.data
	
v1:	.word 0x12345678
v2:	.word 0x11223344
v3:	.word 0xCACABACA
v4:	.word 0x00FABADA
	
	.text
	
	li a7, 10
	ecall
	
	#-- 33 a la direccion 0x10010010