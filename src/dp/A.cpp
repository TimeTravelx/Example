#include "dp/A.h"
#include <stdio.h>

class APrivate {
public:
    APrivate(A* __q) : q_ptr(__q){}

    void private_printA() { printf("hello world\n");}

private:

    A* const q_ptr;
    DECLARE_PUBLIC(A);
};

A::A()
    : d_ptr(new APrivate(this))
{

}

void A::printA()
{
    d_ptr->private_printA();
}