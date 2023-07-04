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

int main(int argc, char *argv[])
{
	char *nombre = argv[2];
	char buff[100];
	int sockfd;
	int port = atoi(argv[1]);
	// socket create and varification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created..\n");
	
	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(port);
	memset(buff, 0, sizeof(buff));
	// connect the client socket to server socket
	if (connect(sockfd, (struct sockaddr *)&servaddr,sizeof(servaddr)) != 0) {
		printf("connection with the server failed...\n");
		exit(0);
	}
	else{
		printf("connected to the server..\n");
		strcpy(buff, nombre);
		if ((write(sockfd, buff, sizeof(buff)))==-1)
			{
				printf("Error en recv()\n");
				exit(-1);
			}
	}
}	