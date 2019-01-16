/*
 * configuration.cpp
 *
 *  Created on: Jan 15, 2019
 *      Author: gustavotorres
 */
#include <iostream>
#include <fstream>
#include <string>

#include "configuration.h"

Configuration::Configuration() {
	std::string line;
	std::ifstream myfile ("config.txt");

	if (myfile.is_open()) {
		std::getline(myfile, line);

		int num_servers = std::stoi(line, nullptr, 10);

		for(size_t i = 0; i < num_servers; i++) {
			std::getline(myfile, line);
			int ip = std::stoi(line, nullptr, 10);

			std::getline(myfile, line);
			int port = std::stoi(line, nullptr, 10);

			struct server_info s;
			s.ip = ip;
			s.port= port;

			servers[i] = s;
		}
		myfile.close();
	}

//	std::map<int, server_info>::iterator it;
//	for(it = servers.begin(); it != servers.end(); it++) {
//		std::cout << "Server: " << std::to_string(it->first) << "\n" << std::endl;
//		std::cout << "IP: " << std::to_string(it->second.ip) << " PORT: " << std::to_string(it->second.port) << "\n" << std::endl;
//	}
}

unsigned long Configuration::get_ith_server_ip(int i) {
	return servers[i].ip;
}

unsigned long Configuration::get_ith_server_port(int i) {
	return servers[i].port;
}

unsigned int Configuration::get_servers_count() {
	return servers.size();
}
