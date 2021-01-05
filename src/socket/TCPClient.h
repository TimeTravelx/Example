/*** 
 * @Author: TimeTravel
 * @FilePath: /Example/src/socket/TCPClient.h
 * @Date: 2021-01-04 11:12:57
 * @Description: TCP client 
 */

#include <string>
#include <thread>
#include "IClient.h"

class TCPClient : public IClient
{
public:
    TCPClient();
    virtual ~TCPClient();

    int connect(const std::string& __host, const std::string& __port) override;

    int send(const void *__buf, size_t __buf_len) override;

    void register_recv(RECV __recv_function) override;
    
    void close() override;
    
private:
    void connect_loop();
    std::thread mConnect_thread;
    RECV* mCallbackRecv = NULL;
    unsigned char mBuf[MAXMSGLEN];
    int mSockfd = -1;
};



