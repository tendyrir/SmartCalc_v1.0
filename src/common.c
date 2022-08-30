#include "calc.h"

int precendence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

int is_operator(char op) {
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
        return 1;
    else
        return 0;
}

int is_left_associative(char op) {
    if (op == '+' || 
        op == '-' || 
        op == '*' || 
        op == '/' ) {
        return 1;
    }
    return 0;
}

char* create_lexem(char* input) {
    char* str_of_delims = "+-*/()^";
    int index = strcspn(input, str_of_delims);
    char* lexem = calloc(1, sizeof(index));
    if (!index) {
        lexem[index] = input[index];
    } else {
        for (int i = 0; i < index; i++) {
            lexem[i] = input[i];
        }
    }
    return lexem;
}
