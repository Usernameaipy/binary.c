#ifndef BINARY_H
#define BINARY_H
#include <stdio.h>
#include <stdlib.h>
struct binary {
    int variable;
    struct binary* max;
    struct binary* min;
};
struct binary* init(int);
#endif