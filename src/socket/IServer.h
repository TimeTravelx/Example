/*** 
 * @Author: TimeTravel
 * @FilePath: /Example/src/socket/IServer.h
 * @Date: 2021-01-04 15:37:29
 * @Description: Socket Server
 */

#ifndef ISERVER_H
#define ISERVER_H

#include "ISocket.h"

class IServer : public ISocket
{
public:
    ~IServer() {}

    virtual int listen(const std::string& __host, const std::string& __port) = 0;   //server

    virtual int send(const void* __buf, size_t __buf_len) = 0;

    virtual void register_recv(RECV __recv_function) = 0;

    virtual void close() = 0;
};





#endif //ISERVER_H
