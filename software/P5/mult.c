#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define BUFFER_SIZE 80
#define READ_END 0
#define WRITE_END 1

int ejecutar(char *arg)
{
	int pid = fork();
	if (pid == -1)
	{
		perror("Error al crear hijo");
	}
	else if (pid == 0)
	{
		printf("ejecutar comando\n");
		execl(arg, arg, NULL);
	}
	return pid;
}

int main(int argc, char *argv[])
{
	int status;
	if (argc == 3)
	{
		int hijo1, hijo2;
		char *arg1 = argv[1];
		char *arg2 = argv[2];
		char buffer[LINE+1];
		int i;
		int ch;
		
		printf( "Please enter string\n" );
		
		for ( i = 0; ( i  < BUFFER_SIZE) && (( ch = getchar()) != EOF) &&
					( ch !='\n' ); ++i )
			buffer[i] = ch;
		
		buffer[i] = '\0';
		
		printf( "The string is %s\n", buffer );

		int fd1[2], fd2[2];
		
		pipe(fd1);

		int pid1, pid2, pid3;
		pid1 = fork();

		if (pid1 == 0)
		{
			close(fd1[READ_END]);	
			dup2(fd1[WRITE_END], STDOUT_FILENO);
			close(fd1[WRITE_END]);
			execl(arg1, arg1, NULL);
		}
		else{
			close(fd1[READ_END]);
			close(fd2[WRITE_END]);

			pid2 = fork();
			if (pid2 == 0)
			{
				dup2(fd2[READ_END], STDIN_FILENO);
				close(fd2[READ_END]);

				execl(arg2, arg2, NULL);
			}
			else /* padre */
			{
				close(fd1[READ_END]);      /* cerrar extremo no necesario */
				close(fd2[WRITE_END]);     /* cerrar extremo no necesario */
			}
		}
		close(fd2[READ_END]);  /* cerrar extremo que queda abierto en el padre  */
	
	/* wait para cada hijo */
		wait(&status);   
		wait(&status);	
	}
	else
	{
		printf("argumentos no son correctos");
	}
}