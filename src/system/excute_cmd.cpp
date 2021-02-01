#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

int excute_cmd(const char* __cmd)
{
    if (!__cmd) return -1;

    pid_t pid = system(__cmd);

    if (pid == -1) { /* system fork err*/ return -1; }

    int ret = 0;
    if ( (ret = WIFEXITED(pid)) == 0) { /* system fork process exit failed */ return ret; }

    if ( (ret = WEXITSTATUS(pid)) != 0) { /* system fork process shell script run failed */ return ret; }

    return 0;
}

int excute_cmd(const char* __cmd, char* __out)
{
    if (!__cmd) return -1;

    int     ret;
    char    buf[100] = {0};
    FILE* fp = popen(__cmd, "r");
    if (!fp) return -1;

    int step = 0;
    while (fgets(buf, sizeof(buf), fp)) {
        memcpy(__out + step, buf, strlen(buf));
        step += strlen(buf);
    }

    if ((ret = pclose(fp)) == -1) return ret;

    return strlen(__out);
}