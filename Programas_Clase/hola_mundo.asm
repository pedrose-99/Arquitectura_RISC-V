#-- Programa hola mundo RICS-V
#-- Esto son comentarios
	.data
str:	.asciz "hola mundo!\n\n"

	.text

main:

	la a0, str
	li a7, 4
	ecall
	
	li a7, 10
	ecall