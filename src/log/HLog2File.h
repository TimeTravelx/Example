/***
 * @Author: TimeTravel
 * @FilePath: /Example/src/log/HLog2File.h
 * @Date: 2020-12-31 16:06:44
 * @Description: Log write to File
 */
#ifndef HLOG2FILE_H
#define HLOG2FILE_H

#include "ILog.h"
#include <string>

class HLog2File : public ILog
{
public:
    HLog2File();
    HLog2File(const int __level, const unsigned long __size);
    virtual ~HLog2File();

    virtual int openlog(const char* __path) override;

    virtual void closelog() override;

    void config(const int __level, const unsigned long __size);

    virtual void debug(const char* __format, ...) override;

    virtual void info(const char* __format, ...) override;

    virtual void warn(const char* __format, ...) override;

    virtual void err(const char* __format, ...) override;



private:
    unsigned int mLevel = DEBUG_LEVEL;
    unsigned long mSize = 5 * 1024 * 1024;
    std::string mPath = "demo.log";
    FILE* mFile = NULL;
};


#endif //HLOG2FILE_H


