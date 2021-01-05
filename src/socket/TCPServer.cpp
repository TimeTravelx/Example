#include "TCPServer.h"
#include <memory.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <linux/sockios.h>
#include <netdb.h>
#include <cstring>
#include <string>
#include <functional>


TCPServer::TCPServer()
{
    memset(mBuf, 0 , sizeof(mBuf));
}

TCPServer::~TCPServer()
{
}

int TCPServer::listen(const std::string& __host, const std::string& __port)
{
    if (__host.empty() || __port.empty()) return -1;

    /* 获取ip地址 */
    char** pptr;
    char str[32] = { 0 };
    struct hostent* hptr = gethostbyname(__host.c_str());
    if (hptr == nullptr) return -1;
    pptr = hptr->h_addr_list;
    const char* ip = inet_ntop(hptr->h_addrtype, hptr->h_addr, str, sizeof(str));

    /* 初始化socket */
    mSockfd = ::socket(AF_INET/* ipv4 */, SOCK_STREAM/* tcp*/, 0);
    if (mSockfd < 0) return -1;

    // 初始化服务器地址  
    struct sockaddr_in addr = {0};     
    addr.sin_family = AF_INET;
    addr.sin_port = htons(stoi(__port));
    addr.sin_addr.s_addr = inet_addr(ip);

    /* connect to server */
    printf("111111 \n");
    int confd = ::bind(mSockfd, (sockaddr*)&addr, sizeof(addr));
    printf("2222 \n");
    if (confd < 0) {
        ::close(mSockfd);
        return -1; 
    }

    int listenfd = ::listen(mSockfd, MAXCLIENTSIZE);
    printf("3333 \n");
    if (listenfd < 0) {
        ::close(mSockfd);
        return -1; 
    }
    printf("4444 \n");
    /* thread to run server loop*/
    /// thread to run the loop
    mListen_thread = std::thread(std::bind(&TCPServer::listen_loop, this));
    printf("success \n");

    return 0;
}


int TCPServer::send(const void *__buf, size_t __buf_len)
{
    return 0;
}

void TCPServer::register_recv(RECV __recv_function)
{
    mCallbackRecv = __recv_function;
}

void TCPServer::close()
{
    ::shutdown(mSockfd, SHUT_WR);
}

void TCPServer::listen_loop()
{
    printf("5555 \n");
    while (mSockfd != -1) {
        printf("777777777444777 \n");
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(struct sockaddr_in);
        int clientfd = ::accept(mSockfd,(struct sockaddr *)(&client_addr), &client_addr_len);
        printf("777777775557777 \n");
        if (clientfd < 0) continue;
        printf("666666666 \n");
        int len = ::recv(clientfd, (void*)mBuf, MAXMSGLEN, 0);
        if (len < 0)
        {
            printf("999 \n");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            continue;
        }
        else if (len == 0)
        {
            printf("1010 \n");
            ::close(mSockfd);
            mSockfd = -1;
        }
        else
        {
            printf("1212 \n");
            printf("mBuf:%.*s \n", len, mBuf);
            mCallbackRecv(mBuf, len);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}