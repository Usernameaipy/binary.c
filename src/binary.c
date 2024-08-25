#include "binary.h"

struct binary* init(int var){
    struct binary* root = (struct binary*)malloc(sizeof(struct binary));
    root->variable=var;
    root->max=NULL;
    root->min=NULL;
    return root;
}

struct binary* add(struct binary* root, int var){
    int trig=0;
    struct binary* root_cp=root;
    struct binary* line=(root_cp->variable>var) ? root_cp->min : root_cp->max;
    while(line!=NULL){
        root_cp=line;
        if(root_cp->variable>var){
            line=root_cp->min;
        }
        if(root_cp->variable<var){
            line=root_cp->max;
        }
        if(root_cp->variable==var){
            trig=1;
            break;
        }
    }
    if(root_cp->variable>var && trig==0){
        root_cp->min=init(var);
        line=root_cp->min;
    }
    if(root_cp->variable<var && trig==0){
        root_cp->max=init(var);
        line=root_cp->max;
    }
    return line;
}