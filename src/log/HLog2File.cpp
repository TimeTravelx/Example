#include "HLog2File.h"

#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>

HLog2File::HLog2File() :
    ILog()
{

}

HLog2File::HLog2File(const int __level, const unsigned long __size) :
    ILog()
{
    mLevel = __level;
    mSize = __size;
}

HLog2File::~HLog2File()
{
    if (mFile) { fclose(mFile); mFile = NULL; }
}

/***
 * @description: 打开一份日志文件
 * @param __path:  日志路径
 * @return 1: 该日志文件已经被打开
 *         0: 打开成功
 *        -1: 打开失败
 */
int HLog2File::openlog(const char* __path)
{
    if (!__path) return -1;
    if (mFile) { fclose(mFile); mFile = NULL; }
    mPath = __path;

    /* 获取日志文件大小，如果太大，则重头开始刷写 */
    FILE* file = fopen(__path, "a+");
    if (!file) return -1;
    fseek(file, 0, SEEK_END);
    size_t nFileLen = ftell(file);
    fseek(file, 0, SEEK_SET);
    fclose(file);
    ///////////////////////////////////////////

    if (nFileLen < mSize) {
        mFile = fopen(__path, "a+");
        if (!mFile) return -1;
    }
    else {
        mFile = fopen(__path, "w+");
        if (!mFile) return -1;
    }
    return 0;
}

void HLog2File::closelog()
{
    if (mFile) {
        fclose(mFile);
        mFile = NULL;
    }
}

void HLog2File::config(const int __level, const unsigned long __size)
{
    mLevel = __level;
    mSize = __size;
}

void HLog2File::debug(const char* __format, ...)
{
    if (!mFile) return;
    if (mLevel < DEBUG_LEVEL) return;
    va_list arg;
    va_start(arg, __format);
    time_t time_log = time(NULL);
    struct tm* tm_log = localtime(&time_log);
    fprintf(mFile, "[%04d-%02d-%02d %02d:%02d:%02d] [%d] [DEBUG] ",
        tm_log->tm_year + 1900,
        tm_log->tm_mon + 1,
        tm_log->tm_mday,
        tm_log->tm_hour,
        tm_log->tm_min,
        tm_log->tm_sec,
        getpid());
    vfprintf(mFile, __format, arg);
    va_end(arg);
    fflush(mFile);
}

void HLog2File::info(const char* __format, ...)
{
    if (!mFile) return;
    if (mLevel < INFO_LEVEL) return;
    va_list arg;
    va_start(arg, __format);
    time_t time_log = time(NULL);
    struct tm* tm_log = localtime(&time_log);
    fprintf(mFile, "[%04d-%02d-%02d %02d:%02d:%02d] [%d] [INFO]  ",
        tm_log->tm_year + 1900,
        tm_log->tm_mon + 1,
        tm_log->tm_mday,
        tm_log->tm_hour,
        tm_log->tm_min,
        tm_log->tm_sec,
        getpid());
    vfprintf(mFile, __format, arg);
    va_end(arg);
    fflush(mFile);
}

void HLog2File::warn(const char* __format, ...)
{
    if (!mFile) return;
    if (mLevel < WARN_LEVEL) return;
    va_list arg;
    va_start(arg, __format);
    time_t time_log = time(NULL);
    struct tm* tm_log = localtime(&time_log);
    fprintf(mFile, "[%04d-%02d-%02d %02d:%02d:%02d] [%d] [WARN]  ",
        tm_log->tm_year + 1900,
        tm_log->tm_mon + 1,
        tm_log->tm_mday,
        tm_log->tm_hour,
        tm_log->tm_min,
        tm_log->tm_sec,
        getpid());
    vfprintf(mFile, __format, arg);
    va_end(arg);
    fflush(mFile);
}

void HLog2File::err(const char* __format, ...)
{
    if (!mFile) return;
    if (mLevel < ERR_LEVEL) return;
    va_list arg;
    va_start(arg, __format);
    time_t time_log = time(NULL);
    struct tm* tm_log = localtime(&time_log);
    fprintf(mFile, "[%04d-%02d-%02d %02d:%02d:%02d] [%d] [ERR]   ",
        tm_log->tm_year + 1900,
        tm_log->tm_mon + 1,
        tm_log->tm_mday,
        tm_log->tm_hour,
        tm_log->tm_min,
        tm_log->tm_sec,
        getpid());
    vfprintf(mFile, __format, arg);
    va_end(arg);
    fflush(mFile);
}


