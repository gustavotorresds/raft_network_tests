/*
 * client.h
 *
 *  Created on: Jan 15, 2019
 *      Author: gustavotorres
 */

#ifndef CLIENT_H_
#define CLIENT_H_


class Client {
	private:
		int sock;

	public:
		Client(int);
		void start();
};

#endif /* CLIENT_H_ */
