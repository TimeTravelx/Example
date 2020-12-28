#include <stdio.h>

#ifdef OPT_DEMO
#include "demo/opt_demo.h"
#endif //OPT_DEMO

int main(int argc, char* argv[]) {
#ifdef OPT_DEMO
    opt_demo(argc, argv);
#endif //OPT_DEMO
    return 0;
}
