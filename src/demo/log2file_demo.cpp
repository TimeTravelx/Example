#include "log2file_demo.h"
#include "log/HLog2File.h"

int log2file_demo()
{
    ilog = new HLog2File(DEBUG_LEVEL, 5 * 1024 * 1024);
    ilog->openlog("demo.log");
    ilog->debug("~~~~~debug~~~~~~~~~\n");
    ilog->info("~~~~~~info~~~~~~~~\n");
    ilog->warn("~~~~~~warn~~~~~~~~\n");
    ilog->err("~~~~~~~err~~~~~~~\n");
    ilog->closelog();
    return 0;
}