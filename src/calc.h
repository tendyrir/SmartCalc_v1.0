#ifndef SRC_CALC_H_
#define SRC_CALC_H_

#include <stdio.h>          // printf
#include <stdlib.h>         // malloc, free
#include <stdbool.h>        // true, false
#include <string.h>         // memcpy

/* define a node that will hold a pointer to a next node and some data */
typedef struct node {
    struct node *next;  // pointer to next node; 8 bytes
    void *data;         // pointer to some data; 8 bytes
} Node;     // node size = 16 bytes

/* define stack type */
typedef struct stack {
    int width;          // size of stored data;     4 bytes
    int nelems;         // number of elements;      4 bytes
    Node *top;          // pointert to stack top;   8 bytes
} Stack;    // stack size = 16 byte


Stack *stack_create(int width);
void stack_push(Stack *s, const void *data);
bool stack_pop(Stack *s, void *addr);


#endif  // SRC_CALC_H_
