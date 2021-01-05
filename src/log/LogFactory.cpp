#include "LogFactory.h"
#include "log/HLog2File.h"

LogFactory* LogFactory::mSelf = new LogFactory();


LogFactory* LogFactory::instance()
{
    return mSelf;
}

void LogFactory::config(const LogType& __type, const unsigned int __level, const std::string& __path)
{
    if (__type == Log2TTY)
    {
        //TODO:
    }
    else if (__type == Log2File)
    {
        ilog = new HLog2File(DEBUG_LEVEL, 5 * 1024 * 1024);
        ilog->openlog(__path);
    }
    
}

LogFactory::LogFactory()
{
}

LogFactory::~LogFactory()
{
    if (ilog) { delete ilog; ilog = nullptr; }
}
