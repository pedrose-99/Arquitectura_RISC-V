#include "sum.h"
#include <stdio.h>

int	main()
{
	int a;
	int b;
	int c;
	printf("Introduce el primer numero: ");
	scanf("%d", &a);
	printf("Introduce el segundo numero: ");
	scanf("%d", &b);
	c = sum(a, b);
	printf("El resultado es %d\n", c);

}