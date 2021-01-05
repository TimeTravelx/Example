#include <thread>
#include <unistd.h>


int main(int argc, char** argv) {
    std::thread loop;
    while (1) {

        if(loop.joinable()) {
            printf("run \n");
            loop.join();
        } else {
            printf("not run \n");
        }
        loop = std::thread(
            []() {
                while (1) {
                    printf("%d \n", getpid());
                    std::this_thread::sleep_for(std::chrono::seconds(10));
                }
            }

        );
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    printf("~~~~~~~~~~~~~~~~\n");
    while(1);
    return 0;
}