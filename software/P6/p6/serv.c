#include <unistd.h>  

/* sockets */
#include <netdb.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <arpa/inet.h>

/* strings / errors*/
#include <stdlib.h>
#include <errno.h>
#include <stdio.h> 
#include <string.h> 

void logger(int sockfd, const char * text) 
{
	time_t t = time(NULL);
	fprintf(stderr, "%ld - [pid %d] - [sock %d] - %s\n", t, getpid(),sockfd, text);
}

int main(int argc, char *argv[])
{
	char buff[100];
	int sockfd;
	char *address  = "127.0.0.1";
	struct sockaddr_in sockaddr;
	char buffer2[1000];
	int port = atoi(argv[1]);
	
	snprintf(buffer2, strlen("Starting server")+1,"Starting server");
	logger(sockfd, buffer2);
	
	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
	{
		perror("Error creating socket");
		exit(-1);
		}
	snprintf(buffer2, strlen("Socket created")+1,"Socket created");
	logger(sockfd, buffer2);
	bzero((void *)&(sockaddr), sizeof(sockaddr));
	sockaddr.sin_family=AF_INET; // TCP/IP family
	sockaddr.sin_port=htons(port); // Asigning port
	sockaddr.sin_addr.s_addr=INADDR_ANY; // Accept all adresses
	
	
	if (bind (sockfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr))<0)
	{
		perror("Error binding socket");
		exit(-1);
	}

	if (listen (sockfd, 10)<0){
		perror("Error listenining");
		exit(-1);
	}
	snprintf(buffer2, strlen("Accepting new connection")+1,"Accepting new conection");
	logger(sockfd, buffer2);

	while(1)
	{
		int connfd;
		int longitud_cliente = sizeof(struct sockaddr_in);
		struct sockaddr_in client;
		//llamada a accept
		if ((connfd = accept(sockfd, (struct sockaddr *)&client, &longitud_cliente))<0)
		{
			perror("Error accepting connection");
			exit(-1);
		}
		int pid = fork();

		if (pid == -1)
		{
			perror("error al crear hijo");

		}
		else if(pid == 0)
		{//hijo
			snprintf(buffer2, strlen("created child with pid")+1, "created child with pid");
			logger(sockfd,buffer2);

			int numbytes;
			if ((numbytes= read(connfd, buff, 1000))==-1)
			{
				printf("Error en recv()\n");
				exit(-1);
			}
			snprintf(buffer2, strlen("Recieved bytes")+ strlen(buff)+1,"Recieved %d bytes", strlen(buff));
			logger(sockfd, buffer2);
			buff[numbytes] = "\0";

			snprintf(buffer2, strlen("hola")+1,"hola, ");

			strcat(buffer2, buff);
			logger(sockfd, buffer2);
			write(connfd, buffer2, numbytes+26);

			close(connfd);

			snprintf(buffer2, strlen("Exitting the service")+1, "Exiting the service");
			logger(sockfd, buffer2);

		}
	}

}