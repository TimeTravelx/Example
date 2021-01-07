#include "LogManager.h"
#include "HLog2File.h"

static ILog* gLog = NULL;

void LogManager::create(LogType __type)
{
    if (__type == LogType::Log2TTY) {

    }
    else if(__type == LogType::Log2File) {
        gLog = new HLog2File();
    }
    else {

    }
}

void LogManager::destroy()
{

}

ILog* LogManager::LOG()
{
    return gLog;
}
