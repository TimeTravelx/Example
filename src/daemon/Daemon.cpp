#include "Daemon.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>
#include <signal.h>
#include <getopt.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#define LOCKFILE "/var/run/daemon.pid"
#define LOCKMODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)

static int fd = 0;

// void daemonize()
// {
//     pid_t pid = 0;
//     int fd;

//     /* Fork off the parent process */
//     pid = fork();

//     /* An error occurred */
//     if (pid < 0) {
//         exit(EXIT_FAILURE);
//     }

//     /* Success: Let the parent terminate */
//     if (pid > 0) {
//         exit(EXIT_SUCCESS);
//     }

//     /* On success: The child process becomes session leader */
//     if (setsid() < 0) {
//         exit(EXIT_FAILURE);
//     }

//     /* Ignore signal sent from child to parent process */
//     signal(SIGCHLD, SIG_IGN);

//     /* Fork off for the second time*/
//     pid = fork();

//     /* An error occurred */
//     if (pid < 0) {
//         exit(EXIT_FAILURE);
//     }

//     /* Success: Let the parent terminate */
//     if (pid > 0) {
//         exit(EXIT_SUCCESS);
//     }

//     /* Set new file permissions */
//     umask(0);

//     /* Change the working directory to the root directory */
//     /* or another appropriated directory */
//     chdir("/");

//     /* Close all open file descriptors */
//     for (fd = sysconf(_SC_OPEN_MAX); fd > 0; fd--) {
//         close(fd);
//     }

//     /* Reopen stdin (fd = 0), stdout (fd = 1), stderr (fd = 2) */
//     stdin = fopen("/dev/null", "r");
//     stdout = fopen("/dev/null", "w+");
//     stderr = fopen("/dev/null", "w+");

//     /* Try to write PID of daemon to lockfile */
//     char str[256];
//     int pid_fd = open(LOCKFILE, O_RDWR | O_CREAT, 0640);
//     if (pid_fd < 0) {
//         /* Can't open lockfile */
//         exit(EXIT_FAILURE);
//     }
//     if (lockf(pid_fd, F_TLOCK, 0) < 0) {
//         /* Can't lock file */
//         exit(EXIT_FAILURE);
//     }
//     /* Get current PID */
//     sprintf(str, "%d\n", getpid());
//     /* Write PID to lockfile */
//     write(pid_fd, str, strlen(str));

// }