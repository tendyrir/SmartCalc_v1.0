#include "calc.h"

int main(void) {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Stack *intstack = stack_create(sizeof(int));

    for (int i = 0; i < 10; i++) {
        stack_push(intstack, arr + i);  // 2nd arg is a pointer!
        printf("pushed: %d\n", arr[i]);
    }

    int popped_int;  // storage for next pooped element

    // we must pop all elements from the stack to avoid leaks
    while (stack_pop(intstack, &popped_int)) {
        printf("popped: %d\n", popped_int);
    }
    // and then free(Stack);
    free(intstack);

    return 0;
}
