#include "smartcalc.h"

/* Функции стека для хранения символов*/

void char_stack_create_empty(CharStack *stack) {
    stack->top = -1;
    stack->count = 0;
}

int char_stack_is_full(CharStack *stack) {
    if (stack->top == STACK_MAX_SIZE - 1) {
        return STACK_IS_FULL; 
    } else {
        return TRUE;
    } 
}

int char_stack_is_empty(CharStack *stack) {
    if (stack->top == -1) {
        return STACK_IS_EMPTY; 
    } else { 
        return TRUE;
    }
}

void char_stack_push(CharStack *stack, char new_item) {
    if (char_stack_is_full(stack)) {
        printf("\nERROR: CAN'T PUSH --> CHAR STACK IS FULL\n");
        exit(STACK_OVERFLOW);
    } else {
        stack->top++;
        stack->data[stack->top] = new_item;
    }
    stack->count++;
}

char char_stack_pop(CharStack *stack) {
    if (char_stack_is_empty(stack)){
        printf("\nERROR: CAN'T POP --> CAHR STACK_EMPTY\n");
        exit(STACK_UNDERFLOW);
    } else {
        stack->top--;
    }
    stack->count--;
    return stack->data[stack->count];
}

char char_stack_peek(CharStack *stack) {
    if (char_stack_is_empty(stack)) {
        printf("\nERROR: CAN'T PEEK --> CHAR STACK IS EMPTY\n");
        exit(STACK_OVERFLOW);
    } 
    return stack->data[stack->top];
}

void char_stack_print(CharStack *stack) {
    printf("CharStack:\n");
    if (stack->top > -1) {
        for (int i = 0; i < stack->count; i++) {
            printf("#%d: %c \n", i, stack->data[i]);
        }
    } else {
        printf("CHAR STACK IS EMPTY\n");
    }
}

/* Функции стека для хранения вещественных чисел*/
void double_stack_create_empty(DoubleStack *stack) {
    stack->top = -1;
    stack->count = 0;
}

int double_stack_is_full(DoubleStack *stack) {
    if (stack->top == STACK_MAX_SIZE - 1) {
        return STACK_IS_FULL; 
    } else {
        return TRUE;
    } 
}

int double_stack_is_empty(DoubleStack *stack) {
    if (stack->top == -1) {
        return STACK_IS_EMPTY; 
    } else { 
        return TRUE;
    }
}

void double_stack_push(DoubleStack *stack, double new_item) {
    if (double_stack_is_full(stack)) {
        printf("\nERROR: CAN'T PUSH --> DOUBLE STACK IS FULL\n");
        exit(STACK_OVERFLOW);
    } else {
        stack->top++;
        stack->data[stack->top] = new_item;
    }
    stack->count++;
}

double double_stack_pop(DoubleStack *stack) {
    if (double_stack_is_empty(stack)){
        printf("\nERROR: CAN'T POP --> DOUBLE STACK_EMPTY\n");
        exit(STACK_UNDERFLOW);
    } else {
        stack->top--;
    }
    stack->count--;
    return stack->data[stack->count];
}

double double_stack_peek(DoubleStack *stack) {
    if (double_stack_is_empty(stack)) {
        printf("\nERROR: CAN'T PEEK --> DOUBLE STACK IS EMPTY");
        exit(STACK_OVERFLOW);
    }
    return stack->data[stack->top];
}

void double_stack_print(DoubleStack *stack) {
    printf("DoubleStack:\n");
    if (stack->top > -1) {
        for (int i = 0; i < stack->count; i++) {
            printf("#%d: %f \n", i, stack->data[i]);
        }
    } else {
        printf("DOUBLE STACK IS EMPTY\n");
    }
}