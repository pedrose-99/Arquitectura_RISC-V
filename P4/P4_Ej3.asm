
	
	.eqv E1 0
	.eqv E2 4
	.eqv E3 8
	.eqv E4 0xC
	.eqv INC 1
	
	.data
tabla:	.word 0xBEBECAFE, 0xFACEB00C, 0x00FABADA, 0xCACABACA
	
	.text
	
	la x5, tabla
	
	lw x10, E1(x5)
	lw x11, E2(x5)
	lw x12, E3(x5)
	lw x13, E4(x5)
	
	addi x10, x10, INC
	addi x11, x11, INC
	addi x12, x12, INC
	addi x13, x13, INC
	
	sw x10, E1(x5)
	sw x11, E2(x5)
	sw x12, E3(x5)
	sw x13, E4(x5)
	#-- Terminar
	li a7, 10
	ecall