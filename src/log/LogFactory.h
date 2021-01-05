/*** 
 * @Author: TimeTravel
 * @FilePath: /Example/src/log/LogFactory.h
 * @Date: 2021-01-05 10:10:44
 * @Description: Log Factory 
 */

#include <string>
#include <log/ILog.h>

enum LogType{
    Log2TTY = 0,
    Log2File = 1,
};

class LogFactory
{
public:
    static LogFactory* instance();

    ~LogFactory();

    void config(const LogType& __type, const unsigned int __level, const std::string& __path);

private:
    //func
    LogFactory();

    //var
    static LogFactory* mSelf;


};

