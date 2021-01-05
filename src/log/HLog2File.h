/*** 
 * @Author: TimeTravel
 * @FilePath: /Example/src/log/HLog2File.h
 * @Date: 2020-12-31 16:06:44
 * @Description: Log write to File
 */
#ifndef HLOG2FILE_H
#define HLOG2FILE_H

#include "ILog.h"

class HLog2File : public ILog
{
public:
    HLog2File(const int __level, const unsigned long __size);
    virtual ~HLog2File();
    
    virtual int openlog(const std::string& __path) override;
    
    virtual void closelog() override;

    virtual void debug(const std::string __format, ...) override;

    virtual void info(const std::string __format, ...) override;

    virtual void warn(const std::string __format, ...) override;

    virtual void err(const std::string __format, ...) override;

private:
    std::string mPath = "demo.log";
    FILE* mFile = NULL;
};


#endif //HLOG2FILE_H


