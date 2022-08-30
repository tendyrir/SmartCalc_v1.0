#include "calc.h"

char *infix_to_postfix(char *infix) {

    Stack *s = stack_create(sizeof(char));
    char *postfix = (char*) malloc(strlen(infix + 1) * sizeof(char));

    int i = 0;       // infix scanner
    int j = 0;       // postfix fill

    int top = 0;    
    int popped_element = 0;

    



    return postfix;

}

    // while (infix[i] != '\0') {


        // if (isdigit(infix[i])) {
        //     postfix[j] = infix[i];
        //     i++;
        //     j++;

        // } else {
            // if (precendence(infix[i]) > precendence(top)) {
            //      stack_push(s, infix + i);
            //      i++;
            // } else {
            //     stack_pop(s, &popped_element);
            //     postfix[j] = popped_element;
            //     j++;
            // }
    //         stack_peek(s, &top);
    //         if (precendence(infix[i]) > precendence(top)) {
    //             stack_push(s, infix + i);
    //             i++;
    //         } else {
    //             while (precendence(infix[i]) <= precendence(top) || stack_empty(s)) {
    //                 stack_pop(s, &popped_element);
    //                 postfix[j] = popped_element;
    //                 j++;
    //                 stack_peek(s, &top);
    //             } 
    //             stack_push(s, infix + i);
    //             i++;            
    //         }
    //     }
    // }

    // while (!stack_empty(s)) {
    //    stack_pop(s, &popped_element);
    //    postfix[j] = popped_element;

    //    printf("popped: %c\npost = %c\n", popped_element, postfix[j]);
    //    j++;
    // }

    // postfix[j] = '\0';
    // free(s);




