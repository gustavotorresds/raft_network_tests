/*
 * main.cpp
 *
 *  Created on: Jan 15, 2019
 *      Author: gustavotorres
 */
#include <string>
#include <thread>

#include "server.h"
#include "client.h"

void run_server(int port) {
	Server s = Server(port);
	s.start();
}

void run_client(int port) {
	Client c = Client(port);
	c.start();
}

// To run, "./main <number of server port> <number port it should send a request to>"
// E.g.:
// In one terminal window: ./main 8080 8081
// In the other terminal window: ./main 8081 8080

int main(int argc, char const *argv[])
{
	int my_port = std::stoi(argv[1], nullptr, 10);
	int server_port = std::stoi(argv[2], nullptr, 10);

	std::thread server_thread(run_server, my_port);
	std::thread client_thread(run_client, server_port);

	server_thread.join();
	client_thread.join();

    return 0;
}
