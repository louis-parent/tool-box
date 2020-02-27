#include "ClientSocket.h"
#include <netdb.h>
#include <strings.h>

bool ClientSocket::open(const char* hostName, Port port)
{
    this->host = gethostbyname(hostName);
    bool error = !this->host;

    if(!error)
    {
        this->setupAddress(port);
        return this->createSocket();
    }
    else
    {
        return false;
    }
}

bool ClientSocket::connectSocket() const
{
    return connect(this->socketDescriptor, (struct sockaddr*) &this->address, sizeof(struct sockaddr)) != -1;
}

void ClientSocket::closeSocket()
{
	GenericSocket::closeSocket();
    this->host = nullptr;
}

void ClientSocket::setupAddress(Port port)
{
    bzero(&this->address, sizeof(this->address));
	this->address.sin_family = AF_INET;
	this->address.sin_port = htons(port);
	bcopy(this->host->h_addr_list[0], &this->address.sin_addr.s_addr, this->host->h_length);
}

bool ClientSocket::createSocket()
{
    this->socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    return this->socketDescriptor != -1;
}
