#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

StackNode* top = NULL;

void push(int data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    int data = top->data;
    StackNode* temp = top;
    top = top->next;
    free(temp);
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
