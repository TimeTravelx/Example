#include <stdio.h>

#ifdef OPT_DEMO
#include "demo/opt_demo.h"
#endif //OPT_DEMO

#ifdef LOG_DEMO
#include "demo/log2file_demo.h"
#endif

#include "demo/socket_tcp_demo.hpp"

int print_test()
{
    printf("print_test\n");
    return 0;
}


int main(int argc, char* argv[]) {
#ifdef OPT_DEMO
    opt_demo(argc, argv);
#endif //OPT_DEMO

#ifdef LOG_DEMO
    log2file_demo();
#endif

    socket_tcp_demo();
    return 0;
}
