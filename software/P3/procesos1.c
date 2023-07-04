#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main (int argc, char *argv[])
{
	pid_t pid = 0;
	pid_t wait(int *status);
	pid_t waitpid(pid_t pid, int *status, int options);
	int i, n;
	int a = 1;
	int r;
	int status;
	void exit(int status);

	if (argc != 2)
	{
		fprintf(stderr, "Uso: %s procesos\n", argv[0]);
		return 1;
	}
	
	n = atoi(argv[1]);
	for (i = 1; i < n; i++) {
		pid = fork();
		if (pid) {
			pid = wait(&status);
			a += i;
			break;
		}
		// proceso hijo
		else {
			// Pintamos algo en el arranque de un proceso
			fprintf(stderr, "i:%d Creado proc ID %ld\n", i, (long)getpid());
		}
	}
	
	// Para cada proceso dormimos un tiempo aleatorio entre 0 y 1 segundo
	// Usamos una semilla diferente para cada proceso para no tener siempre el mismo tiempo
	srand(getpid());
	r = rand() % 1000000;
	usleep(r);

	fprintf(stdout, "i:%d Proceso ID:%ld Padre ID:%ld Hijo ID:%ld a=%d\n", 
			i, (long)getpid(), (long)getppid(), (long)pid, a);
	return 0;
}