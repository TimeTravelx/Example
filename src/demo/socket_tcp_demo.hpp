#pragma once

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#include "socket/TCPClient.h"
#include "socket/TCPServer.h"

void socket_tcp_demo()
{
    pid_t pid = fork();
    if (pid < 0) {
        printf("fork failed \n");
    } else if (pid == 0) {
        printf("chirld \n");
        ::sleep(5);
        TCPClient client;
        client.connect("127.0.0.0", "8081");

        while(1);
    } else {
        printf("parent \n");
        TCPServer server;
        server.listen("127.0.0.0", "8081");

        while(1);
    }
    // 可以使用wait或waitpid函数等待子进程的结束并获取结束状态
    
    while(1);
}
