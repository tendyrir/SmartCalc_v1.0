#include "calc.h"

char *infix_to_postfix(char *infix) {
    Stack *s = stack_create(sizeof(char));

    char *postfix = (char*) malloc(strlen(infix + 1) * sizeof(char));

    int i = 0;  // infix scanner
    int j = 0;  // postfix fill
    int top = 0;
    int popped_element = 0;
    while (infix[i] != '\0') {

        if (!is_operator(infix[i])) {
            postfix[j] = infix[i];
            i++;
            j++;
        } else {
            // TODO: stackTop (peek)
            stack_peek(s, &top);
            if (precendence(infix[i]) > precendence(top)) {  
                stack_push(s, infix + i);
                i++;
            } else {
                postfix[j] = stack_pop(s, &popped_element);
                j++;
            }
        }
    }

    while (stack_emplty(s)) { // TODO: is empty stack
       postfix[j] = stack_pop(s, &popped_element);
       printf("popped: %c\n", popped_element);
       j++;
    }

    postfix[j] = '\0';


    return postfix;

}

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