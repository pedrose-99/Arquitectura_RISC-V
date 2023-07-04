#include <stdio.h>

int num = 11;
int inicial = 0;
int inicial2 = 1;
int generado = 0;

int fibonacci()
{
	inicial = inicial2;
	inicial2 = generado;
	generado = inicial + inicial2;
	return generado;
}

int main()
{
	printf("%d\n", inicial);
	for (int i = 0; i < num - 1; i++)
	{
		printf("%d\n", fibonacci());
	}
	return 0;
}