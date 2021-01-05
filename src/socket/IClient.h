/*** 
 * @Author: TimeTravel
 * @FilePath: /Example/src/socket/IClient.h
 * @Date: 2021-01-04 15:37:38
 * @Description: Client Socket
 */

#ifndef ICLIENT_H
#define ICLIENT_H

#include "socket/ISocket.h"

class IClient : public ISocket
{
public:
    ~IClient() {}

    virtual int connect(const std::string& __host, const std::string& __port) = 0;  //client
    
    virtual int send(const void* __buf, size_t __buf_len) = 0;

    virtual void register_recv(RECV __recv_function) = 0;

    virtual void close() = 0;
};

#endif//ICLIENT_H
