#include <stdio.h>

struct Queue
{
	int* arr;
	int front;
	int rear;
	int count;
	int maxsize;
};

Queue* CreateQueue(int size) {
	Queue* q = new Queue;
	q->front = 0;
	q->rear = -1;
	q->count = 0;
	q->arr = new int[size];
	q->maxsize = size;

	return q;
}

bool Enqueue(Queue* q, int data) {
	if (q->count >= q->maxsize) {
		return false;
	}
	q->rear = (q->rear + 1) % q->maxsize;
	q->arr[q->rear] = data;
	q->count++;

	return true;
}

void PrintAll(Queue* q) {
	if (q != NULL) {
		int idx = q->front;
		for (int i = 0; i < q->count; i++) {
			printf("arr[%d] = %d\n", idx, q->arr[idx]);
			idx = (idx + 1) % q->maxsize;
		}
		printf("\n");
	}
}

bool Dequeue(Queue* q) {
	if (q->count == 0) {
		return false;
	}
	q->front = (q->front+1) % q->maxsize;
	q->count--;

	return true;
}

void Clear(Queue* q) {
	if (q == NULL) return;
	q->front = 0;
	q->rear = -1;
	q->count = 0;
}

void Init(Queue* q) {
	if (q == NULL) return;
	delete[] q->arr;
	delete q;
	q = nullptr;
}

void main() {

	Queue* queue = CreateQueue(5);

	Enqueue(queue, 10);
	Enqueue(queue, 20);
	Enqueue(queue, 30);
	Enqueue(queue, 40);
	PrintAll(queue);

	Dequeue(queue);
	PrintAll(queue);
	Clear(queue);
	PrintAll(queue);
	Init(queue);
	PrintAll(queue);
}