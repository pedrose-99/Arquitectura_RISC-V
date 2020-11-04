  
  	.test
 
 	addi x0, x0, 0
  	addi x0, x0, 0xFA
  	addi x0, x0, 0xBB
  	
  	addi x0, x1, 0
	addi x0, x2, 0
	
	addi x0, x0, 0
	addi x31, x0, 0
  	
#1- 0x0000013 y 0x0fa00013
#2 0x0bb00013
#3 diferentes: 13 80 00 00 -- 13 00 01 00
#4 diferentes: 93 0F 00 00 -- 13 00 00 00