#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#define BUFFER_SIZE 4096
#define READ_END 0

int ejecutar(int fd1[], char *input_str, char *arg)
{
	int pid = fork();
	if (pid == -1)
	{
		perror("Error al crear hijo");
	}
	else if (pid == 0)
	{
		dup2(fd1[0], STDIN_FILENO);
		close(fd1[1]);
		close(fd1[0]);
		execlp(arg, arg,NULL);
		perror("error HIJO");
		exit(EXIT_FAILURE);
	}
	else
	{
		close(fd1[0]);
		write(fd1[1], input_str, strlen(input_str));
		close(fd1[1]);
	}
	return pid;
}
int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		int hijo1, hijo2;
		char *arg1 = argv[1];
		char *arg2 = argv[2];
		char buffer[BUFFER_SIZE];
		int i;
		int ch;
		int fd1[2];
		int fd2[2];
		if (pipe(fd1)==-1)
		{
			fprintf(stderr, "pipe failed");
			return 1;
		}
		if (pipe(fd2)==-1)
		{
			fprintf(stderr, "pipe failed");
			return 1;
		}

		pid_t pid_terminado = 0;

		for ( i = 0; ( i  < BUFFER_SIZE ) && (( ch = getchar()) != EOF); ++i )
			buffer[i] = ch;
		
		int pid1 = ejecutar(fd1, buffer, arg1);
		int pid2 = ejecutar(fd2, buffer, arg2);
		}
	else
	{
		printf("argumentos no son correctos");
	}
}