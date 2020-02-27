#ifndef __GENERIC_SOCKET_H__
#define __GENERIC_SOCKET_H__

#include <netinet/ip.h>
#include <arpa/inet.h>

typedef int Port;
typedef struct sockaddr_in SocketAddress;
typedef int Socket;

class GenericSocket
{
    public:
        GenericSocket(Port port = -1, SocketAddress address = {AF_INET, 0, {0}, 0}, Socket descriptor = -1);
        virtual ~GenericSocket() {}

        virtual void closeSocket();

        virtual size_t recvData(void* buffer, size_t length) const;
        virtual size_t sendData(void* buffer, size_t length) const;

        bool isValid() const;

        Port getPort() const;
        Socket getDescriptor() const;
        char* getAddress() const;

    protected:
        Port port;
        SocketAddress address;
		Socket socketDescriptor;

        static const socklen_t ADDRESS_LENGTH;
};

#endif
