#ifndef SRC_SMARTCALC_H_
#define SRC_SMARTCALC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define STACK_MAX_SIZE 255

#define TRUE 0
#define STACK_IS_FULL 1
#define STACK_IS_EMPTY 2
#define STACK_OVERFLOW 3
#define STACK_UNDERFLOW 4

typedef struct CharStack {
    char data[STACK_MAX_SIZE];
    int top;
    int count;
} CharStack;

void   char_stack_create_empty(CharStack *stack);
void   char_stack_print(CharStack *stack);
int    char_stack_is_empty(CharStack *stack);
int    char_stack_is_full(CharStack *stack);
void   char_stack_push(CharStack *stack, char new_item);
char   char_stack_pop(CharStack *stack);
char   char_stack_peek(CharStack *stack);

typedef struct DoubleStack {
    double data[STACK_MAX_SIZE];
    int top;
    int count;
} DoubleStack;

void   double_stack_create_empty(DoubleStack *stack);
void   double_stack_print(DoubleStack *stack);
int    double_stack_is_full(DoubleStack *stack);
int    double_stack_is_empty(DoubleStack *stack);
void   double_stack_push(DoubleStack *stack, double new_item);
double double_stack_pop(DoubleStack *stack);
double double_stack_peek(DoubleStack *stack);


char*  infix_to_postfix(char* infix_input_str);
double postfix_to_result(char *input_postfix_str);


char*  create_lexem(char* infix_input_str);
void   sorting_station(char *lexem, CharStack *ops, char *output);
double binary_arithmetics(double d1, double d2, double op);
double unary_arithmetics(double d1, double op) ;
void   calculation(char *lexem, DoubleStack *digits);
int    is_left_associative(char op);
int    precendence(char op);
int    is_operator(char op);
int    is_function(char op);

double create_function_graph(char* input,  double x);
double postfix_to_xy(char *input_postfix_str, double x);
void   calculation_xy(char* lexem, DoubleStack* digits, double x);

#endif /* SRC_SMARTCALC_H_ */
