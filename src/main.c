#include "calc.h"

int main(void) {


    char input[255] = "10-3*3/1-27";
    char *output = infix_to_postfix(input);

    for (int i = 0; i < (int) strlen(input); i++) {
        char *lex = create_lexem(input);
        *input += strlen(lex);
        free(lex);
        infix_to_postfix()
    }


    printf("%s\n", output);
    free(output);

    return 0;
}



// char arr[255] = "1+2*3/4";
// Stack *intstack = stack_create(sizeof(char));
// for (int i = 0; i < (int) strlen(arr); i++) {
//     stack_push(intstack, arr + i);  // 2nd arg is a pointer!
//     printf("pushed: %c ", arr[i]);
// }
//     printf("\n");
// char popped_int;  // storage for next pooped element
// // we must pop all elements from the stack to avoid leaks
// while (stack_pop(intstack, &popped_int)) {
//     printf("popped: %c ", popped_int);
// }
// printf("\n");
// // and then free(Stack);
// free(intstack);