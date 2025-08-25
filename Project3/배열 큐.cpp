#include <stdio.h>

#define MAX 100  // Å¥ Å©±â

struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

void Init(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

int IsEmpty(Queue* q) {
    return q->front > q->rear;
}

int IsFull(Queue* q) {
    return q->rear == MAX - 1;
}

void Enqueue(Queue* q, int data) {
    if (!IsFull(q)) {
        q->arr[++(q->rear)] = data;
    }
    else {
        printf("´Ù Âü!\n");
    }
}

int Dequeue(Queue* q) {
    if (!IsEmpty(q)) {
        return q->arr[(q->front)++];
    }
    printf("ºóÄ­\n");
    return -1;
}

int Peek(Queue* q) {
    if (!IsEmpty(q)) {
        return q->arr[q->front];
    }
    printf("ºóÄ­\n");
    return -1;
}

int main() {
    Queue q;
    Init(&q);

    Enqueue(&q, 10);
    Enqueue(&q, 20);
    Enqueue(&q, 30);

    printf("%d\n", Dequeue(&q)); // 10
    printf("%d\n", Peek(&q));    // 20
    printf("%d\n", Dequeue(&q)); // 20
    printf("%d\n", Dequeue(&q)); // 30
    printf("%d\n", Dequeue(&q)); // Empty -> -1
}