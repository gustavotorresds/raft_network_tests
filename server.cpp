#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string>
#include <thread>
#include <arpa/inet.h>
#include <iostream>

#include "server.h"

Server::Server(int port) {
	int server_fd;
	struct sockaddr_in address;
	int addrlen = sizeof(address);
	this->my_port = port;

	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

//	TODO: check if we'd ever need any of this config.
//	int opt = 1;
//    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
//                                                  &opt, sizeof(opt)))
//    {
//        perror("setsockopt");
//        exit(EXIT_FAILURE);
//    }

	address.sin_family = AF_INET;
	// This defines the IP. #TODO: figure out a good way to make this flexible
	// while keeping a good interface.
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons( port );

	// Forcefully attaching socket to the port 8080
	if (bind(server_fd, (struct sockaddr *)&address,
								 sizeof(address))<0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}

	if (listen(server_fd, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}

	if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
					   (socklen_t*)&addrlen))<0)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}
}

void Server::start() {
	int valread;
	char buffer[1024] = {0};

	std::string str_response = "Got it from server " + std::to_string(my_port);
	const char *response = str_response.c_str();

	while(true) {
		valread = read( new_socket , buffer, 1024);
		printf("%s\n",buffer );
		send(new_socket , response , strlen(response) , 0 );
		printf("Response sent to client\n");
	}
}
