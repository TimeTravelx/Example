
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#include "socket/TCPClient.h"
#include "socket/TCPServer.h"
#include "log/LogFactory.h"

int main()
{
    LogFactory::instance()->config(LogType::Log2File, DEBUG_LEVEL, "socket.log");

    pid_t pid = fork();
    if (pid < 0) {
        printf("fork failed \n");
    } else if (pid == 0) {
        printf("chirld \n");
        ::sleep(2);
        TCPClient client;
        while(1) {
            client.connect("127.0.0.1", "6666");
        }


        while(1);
    } else {
        // printf("parent \n");
        // TCPServer server;
        // server.listen("127.0.0.1", "6666");

        while(1);
    }
    // 可以使用wait或waitpid函数等待子进程的结束并获取结束状态
    
    while(1);
}
