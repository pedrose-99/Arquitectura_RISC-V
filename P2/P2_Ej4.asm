#-- Calculo una expresion
#-- F = (a + b) -c +d + 50 (a= 1, b = 2, c = 3, d = 4)

 	.text
 	
 	 addi x1, x0, 2
 	 addi x2, x0, 4
 	 addi x3, x0, 6
 	 addi x4, x0, 8
 	 addi x5, x0, 10
 	 #-- Expresion generica
 	 
 	 add x6, x1, x2
 	 
 	 add x6, x6, x3
 	 
 	 sub x8, x4, x1
 	 
 	 addi x9, x5, 3
 	 
 	 add x8, x8, x9
 	 
 	 addi x8, x8, -30
 	 
 	 sub x10, x6, x8
 	 
 	 li a7, 10
 	 ecall
 	 
#-- Respuesta = 23

