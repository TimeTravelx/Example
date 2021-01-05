#include "TCPClient.h"
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


TCPClient::TCPClient()
{
    memset(mBuf, 0 , sizeof(mBuf));
}

TCPClient::~TCPClient()
{
}

// int TCPClient::listen(const std::string& __host, const std::string& __port)
// {
//     if (__host.empty() || __port.empty()) return -1;

//     /* 获取ip地址 */
//     char** pptr;
//     char str[32] = { 0 };
//     struct hostent* hptr = gethostbyname(__host.c_str());
//     if (hptr == nullptr) return -1;
//     pptr = hptr->h_addr_list;
//     const char* ip = inet_ntop(hptr->h_addrtype, hptr->h_addr, str, sizeof(str));

//     /* 初始化socket */
//     mSockfd = ::socket(AF_INET/* ipv4 */, SOCK_STREAM/* tcp*/, 0);
//     if (mSockfd < 0) return -1;

//     // 初始化服务器地址  
//     struct sockaddr_in addr = {0};     
//     addr.sin_family = AF_INET;
//     addr.sin_port = htons(stoi(__port));
//     addr.sin_addr.s_addr = inet_addr(ip);

//     /* connect to server */
//     int confd = ::bind(mSockfd, (sockaddr*)&addr, sizeof(addr));
//     if (confd < 0) {
//         ::close(mSockfd);
//         return -1; 
//     }

//     int listenfd = ::listen(mSockfd, MAXCLIENTSIZE);
//     if (listenfd < 0) {
//         ::close(mSockfd);
//         return -1; 
//     }

//     /* thread to run server loop*/
//     /// thread to run the loop
//     mListen_thread = std::thread(std::bind(&TCPClient::listen_loop, this));
//     printf("success \n");

//     return 0;
// }

int TCPClient::connect(const std::string& __host, const std::string& __port)
{
    printf("connect \n");
    if (__host.empty() || __port.empty()) return -1;

    /* 获取ip地址 */
    char **pptr;
    char str[32] = {0};
    struct hostent *hptr = gethostbyname(__host.c_str());
    if(hptr == nullptr) return -1;

    pptr = hptr->h_addr_list;
    const char* ip = inet_ntop(hptr->h_addrtype, hptr->h_addr, str, sizeof(str));
    printf("connect 1111 \n");
    /* 初始化socket */
    mSockfd = socket(AF_INET/* ipv4 */, SOCK_STREAM/* tcp*/, 0);
    printf("connect 2222 \n");
    /// 配置 socket 地址
    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET/* ipv4 */;
    addr.sin_port = htons(stoi(__port))/* 端口号*/;
    addr.sin_addr.s_addr = inet_addr(ip)/* ip */;
    
    printf("connect 3333 \n");
    /* connect to server */
    int confd = ::connect(mSockfd, (sockaddr*)&addr, sizeof(addr));
    printf("connect 444 : %d \n", confd);
    if (confd < 0) return -1; //TODO:

    /* 设置端口复用 */
    int reuse = 1;
    if(setsockopt(mSockfd, SOL_SOCKET, SO_REUSEADDR, (const void *) &reuse, sizeof(reuse)) != 0) return -1;

    /* 禁止发送合并的Nagle算法，避免粘包*/
    int enable = 1;
    if(setsockopt(mSockfd, IPPROTO_TCP, TCP_NODELAY, (void*)&enable, sizeof(enable)) != 0) return -1;

    /* set send & receive buf*/
    int sndbuf = MAXMSGLEN;
    if(setsockopt(mSockfd, SOL_SOCKET, SO_SNDBUF, (char*)&sndbuf, sizeof(sndbuf)) != 0) return -1;

    int rcvbuf = MAXMSGLEN;
    if(setsockopt(mSockfd, SOL_SOCKET, SO_RCVBUF, (char*)&rcvbuf, sizeof(rcvbuf)) != 0) return -1;

    /* thread to run client loop*/
    /// thread to run the loop
    mConnect_thread = std::thread(std::bind(&TCPClient::connect_loop, this));
    printf("success \n");
    return 0;
}

int TCPClient::send(const void *__buf, size_t __buf_len)
{
    return 0;
}

void TCPClient::register_recv(RECV __recv_function)
{
    mCallbackRecv = __recv_function;
}

void TCPClient::close()
{
    ::shutdown(mSockfd, SHUT_WR);
}

void TCPClient::connect_loop()
{
    while(mSockfd != -1) {
        printf("send \n");
        char buf[] = "hello";
        ::send(mSockfd, buf, sizeof(buf), 0);
        int len = ::recv(mSockfd, (void*)mBuf, MAXMSGLEN, 0);
        if(len < 0)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            continue;
        }
        else if(len == 0)
        {
            ::close(mSockfd);
            mSockfd = -1;
        }
        else
        {
            mCallbackRecv(mBuf, len);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}


// void TCPClient::listen_loop()
// {
//     while (mSockfd != -1) {
        
//     }
// }