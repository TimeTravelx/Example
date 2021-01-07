/*** 
 * @Author: TimeTravel
 * @FilePath: /Example/src/log/ILog.h
 * @Date: 2020-12-31 16:07:48
 * @Description: abstract log class
 */
#ifndef ILOG_H
#define ILOG_H


#define DEBUG_LEVEL      3
#define INFO_LEVEL       2
#define WARN_LEVEL       1
#define ERR_LEVEL        0

class ILog
{
public:

    virtual ~ILog() {}

    virtual int openlog(const char* __path) = 0;

    virtual void closelog() = 0;

    virtual void debug(const char* __format, ...) = 0;

    virtual void info(const char* __format, ...) = 0;

    virtual void warn(const char* __format, ...) = 0;

    virtual void err(const char* __format, ...) = 0;
};


#endif //ILOG_H