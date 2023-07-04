#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#define BUFFER_SIZE 1048576


int main(int argc, char *argv[]) {
	int i;
	int bytes_leidos;
	char *original;
	int posicion;
	int numvidas;
	char *nombrecopia;
	char buffer[BUFFER_SIZE];
	char buffer2[BUFFER_SIZE];
	char extraido[BUFFER_SIZE];
	
	printf("Número de argumentos: %d\n", argc-1);
	for (i = 1; i < argc; i++) {
		printf("argv[%d]=%s\n", i, argv[i]);
	}

	if (argc-1 == 3) {
	
		original = argv[1];
		posicion = atoi(argv[2]);
		numvidas = atoi(argv[3]);
		printf("%s\n", original);
		printf("%d\n", posicion);
		printf("%d\n", numvidas);
			
		int fd = open(original, O_RDWR | O_CREAT, S_IRWXU);  
		
		printf("fd = %d \n", fd); 
		  
		if (fd ==-1) 
		{ 
			printf("Error Número %d \n", errno);   
			perror("Programa");                   
		}
		
		lseek(fd, posicion+1, SEEK_SET);
		bytes_leidos = read(fd, buffer, BUFFER_SIZE);
		lseek(fd, posicion, SEEK_SET);
		int bytes_escritos = write(fd, &numvidas, 1);
		int bytes_escritos1 = write(fd, buffer, bytes_leidos);
		printf("Bytes escritos %d \n" ,bytes_escritos1);
		
		printf("%d\n", numvidas);
		
		close(fd);
	
		
	}
	else if (argc-1 == 4) {
		
		original = argv[1];
		posicion = atoi(argv[2]);
		numvidas = atoi(argv[3]);
		nombrecopia = argv[4];	
		printf("%s\n", original);
		printf("%d\n", posicion);
		printf("%d\n", numvidas);
		printf("%s\n", nombrecopia);
		
		int fd = open(original, O_RDWR | O_CREAT, S_IRWXU);
		
		printf("fd = %d \n", fd); 
		  
		if (fd ==-1) 
		{ 
			printf("Error Número %d \n", errno);  
			perror("Programa");                   
		}
		
		
		int fd1 = open(nombrecopia, O_RDWR | O_CREAT, S_IRWXU |O_TRUNC);
		bytes_leidos = read(fd, buffer, BUFFER_SIZE);
		int bytes_escritos  = write(fd1, buffer, posicion);
		printf("Buffer: %s\n", buffer);
		write(fd1, &numvidas, 1);
		lseek(fd, bytes_escritos + 1, SEEK_SET);
		int bytes_leidos2 = read(fd, buffer2, BUFFER_SIZE);
		write(fd1, buffer2, bytes_leidos2);
		printf("Bytes leídos %d \n" ,bytes_leidos);
		printf("Bytes leídos2 %d \n" ,bytes_leidos2);
		close(fd);
		close(fd1);
			
	}
	else {
		printf("\nNúmero de argumentos inválidos.");
	}

	return 0;
}