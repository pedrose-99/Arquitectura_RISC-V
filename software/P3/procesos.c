#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

	int ejecutar(int e)
	{
		char *xload = "/usr/bin/xload";
		char *xeyes = "/usr/bin/xeyes";
		char *xlogo = "/usr/bin/xlogo";
		char *xcalc = "/usr/bin/xcalc";
		char *xclock = "/usr/bin/xclock";
		int pid = fork();
		if (pid == -1) {
				perror("Error al crear hijo");
			}        
			else if (pid == 0){ /* Hijo */
				printf("Proceso: %d (Hijo), ", getpid());
				printf("Proceso: %d (Padre)\n", getppid());
				
				if (e == 0) {
					execl(xload, xload, NULL);
				}
				else if (e == 1) {
					execl(xeyes, xeyes, NULL);
				}
				else if (e == 2) {
					execl(xlogo, xlogo, NULL);
				}
				else if (e == 3) {
					execl(xcalc, xcalc, NULL);
				}
				else if (e == 4) {	
					execlp(xclock, xclock, "-update", "1", NULL);
				}
				perror("ERROR HIJO"); 
				exit(EXIT_FAILURE);
				exit(0);
			}
			return pid;
	}

int main (int argc, char *argv[])
{
	int status;
	int hijo1, hijo2, hijo3, hijo4, hijo5;
	pid_t wait(int *status);
	char *xload = "/usr/bin/xload";
	char *xeyes = "/usr/bin/xeyes";
	char *xlogo = "/usr/bin/xlogo";
	char *xcalc = "/usr/bin/xcalc";
	char *xclock = "/usr/bin/xclock";
	
	pid_t pid_muerto = 0;
	for (int i=0; 0 < 1; i++) 
	{
		//sleep(1);
		if (i < 5) 
		{
			if (i == 0) 
			{
				hijo1 = ejecutar(i);
			}
			else if (i == 1) 
			{
				hijo2 = ejecutar(i);
			}
			else if (i == 2) 
			{
				hijo3 = ejecutar(i);
			}
			else if (i == 3) 
			{
				hijo4 = ejecutar(i);
			}
			else if (i == 4) 
			{
				hijo5 = ejecutar(i);
			}
		}
		else 
		{	
			pid_muerto = wait(&status);
			printf("%d\n", status);
			//The  wait()  system call suspends execution of the calling thread until one of its children terminates.
			//RETURN VALUE wait(): on success, returns the process ID of the terminated child; on error, -1 is returned.
			//La llamada devuelve información del estado y el pid del proceso terminado
			
			if (hijo1 == pid_muerto)
			{
				hijo1 = ejecutar(0);
			}
			else if (hijo2 == pid_muerto)
			{
				hijo2 = ejecutar(1);
			}
			else if (hijo3 == pid_muerto)
			{
				hijo3 = ejecutar(2);
			}
			else if (hijo4 == pid_muerto)
			{
				hijo4 = ejecutar(3);
			}
			else if (hijo5 == pid_muerto)
			{
				hijo5 = ejecutar(4);
			}
		}
	}

return 0;
}