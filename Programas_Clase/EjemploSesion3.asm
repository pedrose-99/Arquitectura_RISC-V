#-- Ejemplo de lectura de una variable en memoria

		.data
		
v1:		.word 0xCAFEBACA
		
		.text
		#-- Meter la direccion de la variable en el registro x6
		#li x6, 0x10010000
		la x6, v1
		
		#- Leer la variable(la cargamos en x5)
		lw x5, 0(x6)
		#-- Solo se accede asi en el RISC-V
		
		#-- Se incrementa x5
		addi x5, x5, 1
		
		#-- Almacena x5 en la variable
		sw x5, 0(x6)
		
		#-- Terminar
		li a7, 10
		ecall