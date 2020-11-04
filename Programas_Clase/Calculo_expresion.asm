#-- Calculo una expresion
#-- F = (a + b) -c +d + 50 (a= 1, b = 2, c = 3, d = 4)

 	.text
 	
 	 addi x1, x0, 1
 	 addi x2, x0, 2
 	 addi x3, x0, 3
 	 addi x4, x0, 4
 	 
 	 #-- Expresion generica
 	 
 	 add x6, x1, x2
 	 
 	 sub x6, x6, x3
 	 
 	 add x6, x6, x4
 	 
 	 addi x10, x6, 50
 	 
 	 li a7, 10
 	 ecall