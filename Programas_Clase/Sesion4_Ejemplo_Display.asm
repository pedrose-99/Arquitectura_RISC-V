#-- Ejemplo de manejo de display 7segmentos derecho
#.. Direccion de manejo es 0xFFFF0010

	.eqv DISP_R 0xFFFF0010
	
	.text
	
	li x5, DISP_R
	
	li x6, 0xFF
	
	sw x6, 0(x5)
	
stop: b stop