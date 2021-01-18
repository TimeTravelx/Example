#include <iostream>
#include <thread>
#include <list>

std::list<int> gList;


void funcA() {
    printf("funcA \n");
}

void funcB() {
    printf("funcB \n");
}


int main(int argc ,char* argv[])
{
    // std::thread threadA = std::thread(funcA);
    // std::thread threadB = std::thread(funcB);
    gList.emplace_back(3);
    gList.pop_front();
    gList.pop_front();
    while(1);
    return 0;
}