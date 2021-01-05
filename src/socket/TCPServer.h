/*** 
 * @Author: TimeTravel
 * @FilePath: /Example/src/socket/TCPServer.h
 * @Date: 2021-01-04 15:44:47
 * @Description: TCP Server
 */

#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <string>
#include <thread>
#include "IServer.h"

class TCPServer : public IServer
{

public:
    TCPServer();
    virtual ~TCPServer();

    virtual int listen(const std::string& __host, const std::string& __port) override;   //server

    virtual int send(const void* __buf, size_t __buf_len) override;

    virtual void register_recv(RECV __recv_function) override;

    virtual void close() override;

private:
    void listen_loop();
    std::thread mListen_thread;
    RECV* mCallbackRecv = NULL;
    unsigned char mBuf[MAXMSGLEN];
    int mSockfd = -1;
};




#endif //TCPSERVER_H