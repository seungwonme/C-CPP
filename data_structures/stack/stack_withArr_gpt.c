#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int data) {
    if (top == MAX_SIZE - 1) {
        printf("Stack is full\n");
        return;
    }
    top++;
    stack[top] = data;
}

int pop() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    int data = stack[top];
    top--;
    return data;
}

int main() {
    push(1);
    push(2);
    push(3);
    printf("%d\n", pop()); // 3
    printf("%d\n", pop()); // 2
    printf("%d\n", pop()); // 1
    return 0;
}
