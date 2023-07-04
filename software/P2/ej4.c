#include <stdio.h>
#define SIZE 6
int main()
{
	int x = 111111;
	double y = -5.4e-12;
	float a = 3.5;
	char l = 'a';
	char pal[SIZE] = "hello";

	printf("El valor de int es: %ld\n", sizeof(x));
	printf("El valor de double es: %ld\n", sizeof(y));
	printf("El valor de float es: %ld\n", sizeof(a));
	printf("El valor de char es: %ld\n", sizeof(l));
	printf("El valor del array es: %ld (dependera del tamaño del array establecido)\n", sizeof(pal));
}