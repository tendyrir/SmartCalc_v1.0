#ifndef SRC_SMARTCALC_H_
#define SRC_SMARTCALC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define STACK_MAX_SIZE 255


#define OK 0
#define TRUE 0
#define ERROR 1

#define YES 1
#define NO 0

#define STACK_IS_FULL 1
#define STACK_IS_EMPTY 2
#define STACK_OVERFLOW 3
#define STACK_UNDERFLOW 4

#define ER_IN_EMPTY_INPUT 5
#define ER_IN_OP_BRACE_AFTER_DIGIT 6
#define ER_IN_NON_DIGIT_AFTER_DOT 7
#define ER_IN_INV_CHAR_AFTER_OPS 8
#define ER_IN_WRONG_CHAR_AFTER_OPENED_BRACE 9
#define ER_IN_WRONG_CHAR_AFTER_CLOSED_BRACE 10
#define ER_IN_TOO_FEW_BRACERS 11
#define ER_IN_SECOND_DOT 13
#define ER_IN_LAST_CHAR_IS_OPS 14
#define ER_IN_FIRST_CHAR_IS_OPS 15

typedef struct CharStack {
    char data[STACK_MAX_SIZE];
    int top;
    int count;
} CharStack;

typedef struct DoubleStack {
    double data[STACK_MAX_SIZE];
    int top;
    int count;
} DoubleStack;

void   char_stack_create_empty(CharStack *stack);
void   char_stack_print(CharStack *stack);
int    char_stack_is_empty(CharStack *stack);
int    char_stack_is_full(CharStack *stack);
void   char_stack_push(CharStack *stack, char new_item);
char   char_stack_pop(CharStack *stack);
char   char_stack_peek(CharStack *stack);

void   double_stack_create_empty(DoubleStack *stack);
void   double_stack_print(DoubleStack *stack);
int    double_stack_is_full(DoubleStack *stack);
int    double_stack_is_empty(DoubleStack *stack);
void   double_stack_push(DoubleStack *stack, double new_item);
double double_stack_pop(DoubleStack *stack);
double double_stack_peek(DoubleStack *stack);

char*  infix_to_postfix(char* infix_input_str);
double postfix_to_result(char *input_postfix_str);

int    input_validation(char *input);
int    validation_rules(char current_char, char next_char);
int    empty_input(char *input);
int    open_brace_after_digit(char next);
int    invalid_char_after_dot(char next);
int    invalid_char_after_op_brace(char next);
int    invalid_char_after_cl_brace(char next);
int    invalid_char_after_plus_minus(char next);
int    invalid_char_after_other_ops(char next);
int    error_print(int valid);


char*  create_lexem(char* infix_input_str);
void   sorting_station(char *lexem, CharStack *ops, char *output);
double binary_arithmetics(double d1, double d2, double op);
double unary_arithmetics(double d1, double op) ;
void   calculation(char *lexem, DoubleStack *digits, double x);
int    is_left_associative(char op);
int    precendence(char op);
int    is_operator(char op);
int    is_function(char op);
int    is_unary(char op);

double create_function_graph(char* input,  double x);
double postfix_to_xy(char *input_postfix_str, double x);
char*  replace_unary_minus(char* input);


#endif /* SRC_SMARTCALC_H_ */
