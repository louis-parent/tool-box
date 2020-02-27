#include "GenericSocket.h"
#include <unistd.h>
#include <strings.h>

const socklen_t GenericSocket::ADDRESS_LENGTH = sizeof(SocketAddress);

GenericSocket::GenericSocket(Port port, SocketAddress address, Socket descriptor) : port(port), address(address), socketDescriptor(descriptor) {}

void GenericSocket::closeSocket()
{
    close(this->socketDescriptor);
    bzero(&this->address, sizeof(this->address));

    this->socketDescriptor = -1;
    this->port = -1;
}

size_t GenericSocket::recvData(void* buffer, size_t length) const
{
    return recv(this->socketDescriptor, buffer, length, 0);
}

size_t GenericSocket::sendData(void* buffer, size_t length) const
{
    return send(this->socketDescriptor, buffer, length, 0);
}

bool GenericSocket::isValid() const
{
    return this->socketDescriptor != -1 && this->port != -1 && this->address.sin_addr.s_addr != 0;
}

Port GenericSocket::getPort() const
{
    return this->port;
}
Socket GenericSocket::getDescriptor() const
{
    return this->socketDescriptor;
}

char* GenericSocket::getAddress() const
{
    return inet_ntoa(this->address.sin_addr);
}
