#-- Programa para calcular la sucesion de fibonachi...
#-- El resultado se deja en el registros 6
#-- Usamos el registro x5 como contador: 1,2,3,4,5,6...
#-- En cada vuelta sumamos el valor de x5 a la cuenta acumulada en x6

	.text

	#-- Inicializamos los registros x5,x6 a 0
	addi x5, x0, 0
	addi x6, x0, 1
	addi x7, x0, 0
	#-- Bucle principal
bucle:
	#-- Incrementar contador principal
	
	add x5, x6, x0  #-- x6 = x6 + x5
	add x6, x7, x0
	
	add x7, x5, x6   #-- x5 = x5 + 1
	#-- Repetir el bucle
	b bucle

#Respuestas
#2. 55 
#3. 7
#4. 28
#x5 hacer lo del ej anterior
#x6 hacer lo del ej anterior