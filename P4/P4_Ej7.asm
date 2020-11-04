	
	.eqv DIG 0xFFFF0010
	.eqv E1 0
	.eqv E2 4
	.eqv E3 8
	.eqv E4 0xC
	
	.data
tabla:	.word 0x0000004f, 0xFACEB00C, 0x00FABADA, 0xCACABACA
	
	.text
	
	la x5, tabla
	
	li x6, DIG
	
	lw x10, E1(x5)
	lw x11, E2(x5)
	lw x12, E3(x5)
	lw x13, E4(x5)
	sw x10, E1(x6)
	
	#-- Terminar
	li a7, 10
	ecall