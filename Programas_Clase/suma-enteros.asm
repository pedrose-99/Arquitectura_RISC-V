#-- Programa para calcular la suma de los números enteros: 1+2+3+4+5+...
#-- El resultado se deja en el registros 6
#-- Usamos el registro x5 como contador: 1,2,3,4,5,6...
#-- En cada vuelta sumamos el valor de x5 a la cuenta acumulada en x6

	.text

	#-- Inicializamos los registros x5,x6 a 0
	addi x5, x0, 0
	addi x6, x0, 0
	
	#-- Bucle principal
bucle:
	#-- Incrementar contador principal
	addi x5, x5, 1   #-- x5 = x5 + 1
	
	#-- Obtener termino i-simo
	add x6, x6, x5  #-- x6 = x6 + x5
	
	#-- Repetir el bucle
	b bucle

#-- Respuestas:

#1. Tiene 5 instrucciones
#2. Ocupa 20 bytes
#3. Tabla:
# 0x00400000- 0x00000293
# 0x00400004- 0x00000313
# 0x00400008- 0x00128293
# 0x0040000c- 0x00530333
# 0x00400010- 0xff9ff06f
#4.Tabla
# 0x0040000- 93
# 0x0040001- 02
# 0x0040002- 00
# 0x0040003- 00
# 0x0040004- 13
# 0x0040005- 03
# 0x0040006- 00
# 0x0040007- 00
# 0x0040008- 00
#5. Resultado: 325
