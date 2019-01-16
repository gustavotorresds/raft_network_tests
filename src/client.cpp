/*
 * client.cpp
 *
 *  Created on: Jan 15, 2019
 *      Author: gustavotorres
 */

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string>
#include <thread>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>

#include "client.h"

Client::Client(int port) {
	while (true)
	{
		struct sockaddr_in serv_addr;
		memset(&serv_addr, '0', sizeof(serv_addr));

		serv_addr.sin_family = AF_INET;
		serv_addr.sin_port = htons(port);

		// Convert IPv4 and IPv6 addresses from text to binary form
		if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
		{
			printf("\nInvalid address/ Address not supported \n");
		}

		if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		{
			printf("\n Socket creation error \n");
		}

		if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == 0) {
			break;
		}

		// Otherwise, connection failed (prob because server is not open yet), so we
		// retry!

		usleep(1000000);
	}
}

void Client::start() {
	int valread;
	char buffer[1024] = {0};
	std::string hello = "Hello from client!";

	while(true) {
		usleep(1000000);
		send(sock , hello.c_str() , hello.length() , 0 );
		printf("Message sent to server\n");
		valread = read( sock , buffer, 1024);
		printf("%s\n",buffer );
	}
}
