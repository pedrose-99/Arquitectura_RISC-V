#-- Ejercicio 6 P1

	.text
	
	addi x5, x0, 5
	addi x6, x0, 6
	addi x7, x0, 0
a:
	beq x5,x0,fin
	add x7, x7, x6
	addi x5, x5, -1
	b a
fin:
	li a7, 10
	ecall
	
	#-- Va disminuyendo X5 hasta que es igual a X0 y aparte va incrementando X7 sumandole X6