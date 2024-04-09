#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 5

typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int is_full() {
    return (top == MAX_STACK_SIZE - 1);
}

void push(element item) {
    if (is_full()) {
        fprintf(stderr, "Stack Overflow\n");
        return;
    }
    else {
        top = top + 1;
        stack[top] = item;
    }
}

int is_empty() {
    return (top == -1);
}

element pop() {
    element r;
    if (is_empty()) {
        fprintf(stderr, "Stack is empty\n");
        return -1;
    }
    else {
        return stack[top--];
    }
}

void print_stack() {
    if (is_empty()) {
        printf("Stack is empty\n");
    }
    else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < 30; i++) {
        element rand_num = (rand() % 100) + 1;

        if (rand_num % 2 == 0) {
            push(rand_num);
            printf("Current rand_sum: %d | Even\npush: %d  \n", rand_num, rand_num);
            print_stack();
        }
        else {
            rand_num = pop();
            printf("Current rand_sum: %d | Odd\npush: %d  \n", rand_num, rand_num);
            print_stack();
        }
    }

    return 0;
}

