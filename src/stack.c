#include "calc.h"

Stack *stack_create(int width) {
    Stack *s = malloc(sizeof(Stack));
    s->width = width;
    s->nelems = 0;
    s->top = NULL;
    return s;
}

void stack_push(Stack *s, const void *data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = malloc(s->width);
    memcpy(new_node->data, data, s->width);

    new_node->next = s->top;
    s->top = new_node;
    s->nelems++;
}

bool stack_pop(Stack *s, void *addr) {
    if (s->nelems == 0)
        return false;
    Node *n = s->top;
    memcpy(addr, n->data, s->width);
    s->top = n->next;
    free(n->data);
    free(n);
    s->nelems--;
    return true;
}
