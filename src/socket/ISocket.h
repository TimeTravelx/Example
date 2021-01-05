/*** 
 * @Author: TimeTravel
 * @FilePath: /Example/src/socket/ISocket.h
 * @Date: 2021-01-04 12:03:11
 * @Description: file Content
 */

#ifndef ISOCKET
#define ISOCKET

#include <string>

#define MAXMSGLEN 65535
#define MAXCLIENTSIZE 10

typedef int RECV(const void* __buf, size_t __buf_len);

class ISocket
{
public:
    virtual ~ISocket() {}

    virtual int send(const void *__buf, size_t __buf_len) = 0;

    virtual void register_recv(RECV __recv_function) = 0;

    virtual void close() = 0;

};





#endif //ISOCKET
