#include <stdio.h>
#include <stdlib.h>
#define SUP 96
#define INF -30

float	convertir(int grados)
{
	float fharen;
	fharen = 1.8*grados + 32;
	return fharen;
}

int	main(int argc, char *argv[])
{
	int incre;
	sscanf(argv[1], "%d", &incre);
	int i = INF;
	float fahren;
	if (argc == 2)
	{
		while(i <= SUP)
		{
			fahren = convertir(i);
			printf("%dC    %.2fF\n", i, fahren);
			i = i + incre;
		}
	}
	else
	{
		printf("El número de argumentos es erroneo.\n");
	}
}