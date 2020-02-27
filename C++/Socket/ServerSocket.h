#ifndef __SERVER_SOCKET_H__
#define __SERVER_SOCKET_H__

#include <netinet/ip.h>
#include "GenericSocket.h"

class ServerSocket : public GenericSocket
{
	public:
		bool open(Port port);
		bool start(int queueLength) const;
		GenericSocket* acceptClient() const;

	private:
		void setupAddress(Port port);
		bool createSocket();
		bool bindSocket() const;
		bool listenSocket(int queueLength) const;
};

#endif
