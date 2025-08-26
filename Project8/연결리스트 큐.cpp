#include <stdio.h>

struct Node {
	int ndata;
	Node* pNext;
};

struct Queue {
	Node* front;
	Node* rear;
	int count;
};

Queue* CreateQueue() {
	Queue* q = new Queue;
	q->front = nullptr;
	q->rear = nullptr;
	q->count = 0;
	return q;
}

bool EnQueue(Queue* q, int data) {
	if (q == NULL) return false;

	Node* temp = new Node;
	temp->ndata = data;
	temp->pNext = nullptr;

	if (q->count == 0) {
		q->front = temp;
		q->rear = temp;
	}
	else {
		q->rear->pNext = temp;
		q->rear = temp;
	}
	q->count++;

	return true;
}

void PrintAll(Queue* q) {
	if (q == NULL || q->count == 0) return;
	Node* temp = q->front;
	while (temp != nullptr) {
		printf("[%d] \n", temp->ndata);
		temp = temp->pNext;
	}
	printf("\n");
}

bool Dequeue(Queue* q) {
	if (q == NULL || q->count ==0) return false;

	Node* temp = q->front;
	q->front = q->front->pNext;
	q->count--;

	if (q->count == 0) {
		q->rear = nullptr;
	}

	delete temp;
	return true;
}

void Clear(Queue* q) {
	if (q == NULL) return;

	while (Dequeue(q));
}

void Init(Queue* q) {
	if (q == NULL) return;

	Clear(q);
	delete q;
	q = nullptr;
}

void main() {
	Queue* queue = CreateQueue();

	EnQueue(queue, 10);
	EnQueue(queue, 20);
	EnQueue(queue, 30);
	EnQueue(queue, 40);
	PrintAll(queue);

	Dequeue(queue);
	PrintAll(queue);

	Clear(queue);
	PrintAll(queue);
	Init(queue);
	queue = nullptr;
	PrintAll(queue);
}