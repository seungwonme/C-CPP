#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int data) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    rear++;
    queue[rear] = data;
    if (front == -1) {
        front = rear;
    }
}

int dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue[front];
    front++;
    if (front > rear) {
        front = -1;
        rear = -1;
    }
    return data;
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    printf("%d\n", dequeue()); // 1
    printf("%d\n", dequeue()); // 2
    printf("%d\n", dequeue()); // 3
    return 0;
}
