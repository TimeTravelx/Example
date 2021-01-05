#include "ILog.h"

ILog* ilog = nullptr;

ILog::ILog(const int __level, const unsigned long __size)
{
    if (__level < 0 || __level > 3) mLevel = 3;
    mLevel = __level;
    mSize = __size;
}

ILog::~ILog()
{
    mLevel = 0;
    mSize = 0;
}
