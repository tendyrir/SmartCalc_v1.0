#include "s21_smartcalc.h"

/* Проверяет является ли операция левоассоциативной */
int is_left_associative(char op) {
    if (op == '+' || op == '-' || op== '*' || op == '/' )
        return 1; 
    return 0;
}

/* Проверка символа на оператор */
int is_operator(char op) {
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^' || op == 'm')
        return 1;
    return 0;
}

/* Является ли текущий символ символом функции */
int is_function(char op) {
    if (op == 'c' || op == 's' || op == 't' || op == 'q' || op == 'n' ||
        op == 'o' || op == 'i' || op == 'a' || op == 'k')
        return 1;
    return 0;
}

int is_unary(char op) {
    if (op == '~')
        return 1;
    return 0;
}

/* Функция установки приоритета операции */
int precendence(char op) {
    // TODO: переписать под if else?
    int prec = 0;
    int int_val_op_prec = (int) op;
    switch (int_val_op_prec) {
        case '+':
            prec = 1;
            break;
        case '-':
            prec = 1;
            break;
        case '*':
            prec = 2;
            break;
        case '/':
            prec = 2;
            break;
        case 'm':
            prec = 2;
            break;
        case '^':
            prec = 3;
            break;
        // default:
        //     printf("No cases matched, no precendence applied to %d\n", prec);
    }

    return prec;
}

double binary_arithmetics(double d1, double d2, double op) {
    double res = 0;
    int int_val_op_ar = (int) op;
    switch (int_val_op_ar) {
        case '+':
            res = d2 + d1;
            break;
        case '-':
            res = d2 - d1;
            break;
        case '*':
            res = d2 * d1;
            break;
        case '/':
            // TODO: check for division by zero
            res = d2 / d1;
            break;
        case 'm':
            // TODO: check for division by zero
            res = fmod(d2, d1);
            break;
        case '^':
            res = pow(d2, d1);
            break;
        // default:
        //     printf("No cases matched, no arithmetics applied\n");
    }
    return res;
}

double unary_arithmetics(double d1, double op) {
    double res = 0;
    int int_val_op_ar = (int) op;
    switch (int_val_op_ar) {
        case 'c':
            res = cos(d1);
            break;
        case 's':
            res = sin(d1);
            break;
        case 't':
            res = tan(d1);
            break;
        case 'q':
            res = sqrt(d1);
            break;
        case 'n':
            res = log10(d1);
            break;
        case 'o':
            res = log(d1);
            break;
        case 'i':
            res = asin(d1);
            break;
        case 'a':
            res = atan(d1);
            break;
        case 'k':
            res = acos(d1);
            break;
        case '~':
            res = d1 * (-1);
        // default:
        //     printf("No cases matched, no arithmetics applied\n");
    }
    return res;
}