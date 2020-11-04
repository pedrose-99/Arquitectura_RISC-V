###

	.eqv DIG3 0xFFFF0010
	
	.eqv num1 6
	.eqv num2 91
	.eqv num3 79
	.eqv num4 102
	
	.data
	
	
	.text
	
	li x5, num3 
	
	li x6, DIG3
	
	sw x5, 0(x6)
	
	li a7, 10
	ecall