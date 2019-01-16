/*
 * server.h
 *
 *  Created on: Jan 15, 2019
 *      Author: gustavotorres
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class Server {
	private:
		int my_port;
		int server_fd;
		struct sockaddr_in address;
		void next_connection(int socket);

	public:
		Server(int port);
		void start(int num_connections);
};

#endif /* SERVER_H_ */
