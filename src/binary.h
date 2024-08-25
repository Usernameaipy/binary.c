#ifndef BINARY.H
#define BINARY.H
#include <stdio.h>
#include <stdlib.h>
struct binary {
    int variable;
    struct binary* max;
    struct binary* min;
};
struct binary* init(int);
#endif