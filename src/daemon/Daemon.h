/*** 
 * @Author: TimeTravel
 * @FilePath: /Example/src/daemon/Daemon.h
 * @Date: 2021-01-19 10:19:43
 * @Description: 让一个进程成为守护进程
 */

#ifndef DAEMONIZE_H
#define DAEMONIZE_H

class Daemon
{
public:
    Daemon() = default;
    ~Daemon() = default;
    Daemon(const Daemon & rhs) = delete;
    Daemon& operator=(const Daemon & rhs) = delete;


};





#endif //DAEMONIZE_H