/*
 * configuration.h
 *
 *  Created on: Jan 15, 2019
 *      Author: gustavotorres
 */

#ifndef SRC_CONFIGURATION_H_
#define SRC_CONFIGURATION_H_

#include <map>

struct server_info {
    unsigned long ip;  // load with inet_aton()
    unsigned long port;
};

// Configuration File (config.txt) has the format:
// <total number of servers running>
// <ip of server #1>
// <port of server #1>
// <ip of server #2>
// <port of server #2>
// ...
class Configuration {
	private:
		std::map<int, server_info> servers;

	public:
		Configuration();
		unsigned long get_ith_server_ip(int i);
		unsigned long get_ith_server_port(int i);
		unsigned int get_servers_count();
};

#endif /* SRC_CONFIGURATION_H_ */
