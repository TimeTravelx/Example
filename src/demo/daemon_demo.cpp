/*** 
 * @Author: TimeTravel
 * @FilePath: /Example/src/demo/daemon_demo.cpp
 * @Date: 2021-01-18 10:11:21
 * @Description: how to create a daemon
 */

#include "daemon/Daemon.h"
#include "system/excute_cmd.h"

#include <string>
int main(int argc, char* argv[])
{
	char buf[1024] = {0};
	excute_cmd("ls -al", buf);
	printf("buf:%s \n", buf);
	// while(1);
	return 0;
}