#include "calc.h"

int main(void) {
/*
 */
    char input[255] = "2+2*2";
    Stack *intstack = stack_create(sizeof(char));
    for (size_t i = 0; i < strlen(input); i++) {
        stack_push(intstack, input + i);  // 2nd arg is a pointer!
        printf("pushed: %s\n", input + i);
    }
    char popped_char;  // storage for next pooped element
    // we must pop all elements from the stack to avoid leaks
    while (stack_pop(intstack, &popped_char)) {
        printf("popped: %c\n", popped_char);
    }
    // and then free(Stack);
    free(intstack);

    // char input[255] = "1-2/3-4*5";

    // printf("postfix: %s", infix_to_postfix(input));

    return 0;
}
