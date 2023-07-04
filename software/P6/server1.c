#include <unistd.h>  

/* sockets */
#include <netdb.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <arpa/inet.h>

/* strings / errors*/
#include <errno.h>
#include <stdio.h> 
#include <string.h> 

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		int fd, fd2, longitud_cliente, puerto;
		puerto = atoi(argv[1]);

		struct sockaddr_in server;
		struct sockaddr_in client;

		server.sin_family = AF_INET;//familia tcp
		server.sin_port = htons(puerto);//puerto
		server.sin_addr.s_addr = INADDR_ANY;//cualquier cliente puede conectarse
		bzero(&(server.sin_zero), 8);//funcion que rellena con 0's
		
		//definicion de socket
		if ((fd=socket(AF_INET, SOCK_STREAM, 0) )<0)
		{
			perror("Error de apertura de socket");
			exit(-1);
		}

		//avisar al sistema de que se creo un socket
		if (bind(fd,(struct sockaddr*)&server, sizeof(struct sockaddr)) == -1)
		{
			printf("error en bind()\n");
			exit(-1);
		}

		//establecer el socket en modo escucha
		if (listen(fd, 5) == -1)
		{
			printf("error en listen()\n");
			exit(-1);
		}

		//aceptar conexines
		while(1)
		{
			longitud_cliente = sizeof(struct sockaddr_in);
			//llamada a accept
			if ((fd2 = accept(fd, (struct sockaddr *)&client, &longitud_cliente))== -1)
			{
				printf("error en acept()\n");
				exit(-1);
			}
			send(fd2, "Bienvenido a mi servidor.\n", 26, 0);
			close(fd2);
		}
	close(fd);
	}
	else
	{
		printf("No se ingreso el puerto por parametro");
	}
	return 0;
}