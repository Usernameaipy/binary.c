#include "binary.h"

struct binary* init(int var){
    struct binary* root = (struct binary*)malloc(sizeof(struct binary));
    if(root!=NULL){
        root->variable=var;
        root->max=NULL;
        root->min=NULL;
    }
    return root;
}

struct binary* add(struct binary* root, int var){
    int trig=0;
    struct binary* root_cp=root;
    struct binary* line=(root_cp->variable>var) ? root_cp->min : root_cp->max;
    // if(root_cp==NULL){
    //     root=init(var);
    //     exit(0);
    // }
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

void print_recursively(struct binary* root) {
    if(root == NULL){
        exit(1);
    }
    else {
        printf("%d ", root->variable);
        if(root->min!=NULL){
            print_recursively(root->min);
        }
        if(root->max!=NULL){
            print_recursively(root->max);
        }
    }
}

void print_sort(struct binary* root){
    if(root!=NULL){
        print_sort(root->min);
        printf("%d ", root->variable);
        print_sort(root->max);
    }
}

int main(){
    struct binary* tree=init(1);
    add(tree, 5);
    add(tree, 3);
    add(tree, 2);
    add(tree, 8);
    add(tree, 4);
    print_recursively(tree);
    printf("\n");
    print_sort(tree);
    return 0;
}