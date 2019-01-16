/*
 * main.cpp
 *
 *  Created on: Jan 15, 2019
 *      Author: gustavotorres
 */
#include <string>
#include <thread>
#include <iostream>

#include "configuration.h"
#include "server.h"
#include "client.h"

void run_server(int port, int num_connections) {
	Server s = Server(port);
	s.start(num_connections);
}

void run_client(int port) {
	Client c = Client(port);
	c.start();
}

// To run, "./main <server index>"
// E.g.:
// In one terminal window: ./main 0
// In the other terminal window: ./main 1
// etc...

int main(int argc, char const *argv[])
{
	int server_index = std::stoi(argv[1], nullptr, 10);

	Configuration config = Configuration();

	std::thread threads[config.get_servers_count()];

	threads[server_index] = std::thread(run_server, config.get_ith_server_port(server_index), config.get_servers_count() - 1);

	for(int i = 0; i < config.get_servers_count(); i++) {
		if(i != server_index) {
			threads[i] = std::thread(run_client, config.get_ith_server_port(i));
		}
	}

	for(int i = 0; i < config.get_servers_count(); i++) {
		threads[i].join();
	}

    return 0;
}
