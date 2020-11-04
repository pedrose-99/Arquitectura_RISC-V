#-- Leer int

	.eqv EXIT 10
	.eqv READ_INT 5
	.eqv PRINT_CHAR 11
	
	.text
	
	li a7, READ_INT
	ecall
	li a0, 'A'
	li a7, PRINT_CHAR
	ecall
	
	li a7, EXIT
	ecall