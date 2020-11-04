#-- Ejemplo seg datos

	.data
	
a:	.word 0xBEBECAFE, 1, 2
#a: comienzo(0x10010000)
b:	.word 0xFACEB00C, 0XABCDEF01
#b :0x1001000c
c:
#c: 0x10010014
	
	.text
codigo:
	#terminar el programa
	li a7, 10
	