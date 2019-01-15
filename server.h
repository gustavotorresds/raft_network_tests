/*
 * server.h
 *
 *  Created on: Jan 15, 2019
 *      Author: gustavotorres
 */

#ifndef SERVER_H_
#define SERVER_H_

class Server {
	private:
		int new_socket;
		int my_port;

	public:
		Server(int port);
		void start();
};

#endif /* SERVER_H_ */
