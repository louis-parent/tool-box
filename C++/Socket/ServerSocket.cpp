#include "ServerSocket.h"
#include <strings.h>

bool ServerSocket::open(Port port)
{
	this->port = port;
	this->setupAddress(port);
	return this->createSocket();
}

bool ServerSocket::start(int queueLength) const
{
	bool noError = this->bindSocket();
	noError = noError && this->listenSocket(queueLength);
	return noError;
}

GenericSocket* ServerSocket::acceptClient() const
{
	SocketAddress address;
	Socket sck;
	int length = GenericSocket::ADDRESS_LENGTH;
	sck = accept(this->socketDescriptor, (struct sockaddr*) &address, (socklen_t *) &length);
	return new GenericSocket(this->port, address, sck);
}

void ServerSocket::setupAddress(Port port)
{
	bzero(&this->address, sizeof(this->address));
	this->address.sin_family = AF_INET;
	this->address.sin_port = htons(port);
	this->address.sin_addr.s_addr = INADDR_ANY;
	bzero(&(this->address.sin_zero), 8);
}

bool ServerSocket::createSocket()
{
	this->socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
	return this->socketDescriptor != -1;
}

bool ServerSocket::bindSocket() const
{
	return bind(this->socketDescriptor, (struct sockaddr*) &this->address, GenericSocket::ADDRESS_LENGTH) != -1;
}

bool ServerSocket::listenSocket(int queueLength) const
{
	return listen(this->socketDescriptor, queueLength) != -1;
}
