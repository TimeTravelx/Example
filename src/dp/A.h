#pragma once 

#include "base/dp_ptr.h"

class APrivate;

class A {
public:
    A();
    void printA();

private:
    APrivate * const d_ptr;
    DECLARE_PRIVATE(A);
};