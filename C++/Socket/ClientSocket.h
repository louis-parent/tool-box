#ifndef __CLIENT_SOCKET_H__
#define __CLIENT_SOCKET_H__

#include <netinet/ip.h>
#include "GenericSocket.h"

class ClientSocket : public GenericSocket
{
    public:
        bool open(const char* hostName, Port port);
        bool connectSocket() const;
        void closeSocket() override;

    private:
        struct hostent* host;

        void setupAddress(Port port);
        bool createSocket();
};

#endif
