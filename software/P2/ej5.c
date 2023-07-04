#include <stdio.h>
#define SUP 96
#define INF -30

float	convertir(int grados)
{
	float fharen;
	fharen = 1.8*grados + 32;
	return fharen;
}

int	main()
{
	int incre = 6;
	int i = INF;
	float fahren;

	while(i <= SUP)
	{
		fahren = convertir(i);
		printf("%dC    %.2fF\n", i, fahren);
		i = i + incre;
	}
}