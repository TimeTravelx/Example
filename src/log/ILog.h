/*** 
 * @Author: TimeTravel
 * @FilePath: /Example/src/log/ILog.h
 * @Date: 2020-12-31 16:07:48
 * @Description: abstract log class
 */
#ifndef ILOG_H
#define ILOG_H

#include <string>

#define DEBUG_LEVEL      3
#define INFO_LEVEL       2
#define WARN_LEVEL       1
#define ERR_LEVEL        0

#define LogDebug(format, ...)   do {if (ilog) { ilog->debug(format, ##__VA_ARGS__)}} while(0);
#define LogInfo(format, ...)    do {if (ilog) { ilog->info (format, ##__VA_ARGS__)}} while(0);
#define LogWarn(format, ...)    do {if (ilog) { ilog->warn (format, ##__VA_ARGS__)}} while(0);
#define LogErr(format, ...)     do {if (ilog) { ilog->err  (format, ##__VA_ARGS__)}} while(0);


class ILog
{
public:
    ILog(const int __level, const unsigned long __size);

    virtual ~ILog();

    virtual int openlog(const std::string& __path) = 0;

    virtual void closelog() = 0;

    virtual void debug(const std::string __format, ...) = 0;

    virtual void info(const std::string __format, ...) = 0;

    virtual void warn(const std::string __format, ...) = 0;

    virtual void err(const std::string __format, ...) = 0;

    int mLevel = 0;
    unsigned long mSize = 5 * 1024 * 1024;
};

extern ILog *ilog;


#endif //ILOG_H