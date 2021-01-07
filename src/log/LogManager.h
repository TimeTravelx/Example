#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include "ILog.h"
#include <string>

class LogManager
{
public:
    enum LogType{Log2TTY=0, Log2File=1};

    static void create(LogType __type);

    static void destroy();

    static ILog* LOG();
};



#endif //LOGMANAGER_H