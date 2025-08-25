#include <stdio.h>

struct Node {
	Node* pNext;
	int ndata;
};

struct Stack {
	Node* top;
	int count;
};

Stack* CreateStack(int data) {
	Stack* s = new Stack;
	s->top = new Node;
	s->count = 1;
	s->top->ndata = data;
	s->top->pNext = NULL;

	return s;
}

void PrintAll(Stack* s) {
	if (s->count != 0) {
		Node* temp = s->top;
		while (temp != NULL) {
			printf("%d \n", temp->ndata);
			temp = temp->pNext;
		}
	}
}

bool Push(Stack* s, int data) {
	if (s == NULL) return false;
	Node* temp = s->top;
	s->top = new Node();
	++s->count;
	s->top->ndata = data;
	s->top->pNext = temp;

	return true;
}

bool Pop(Stack* s) {
	if (s == NULL || s->count == 0) return false;
	Node* temp = s->top;
	s->top = s->top->pNext;
	--s->count;
	temp->pNext = NULL;
	delete temp;

	return true;
}

bool Clear(Stack* s) {
	if (s == NULL) return false;
	while (s->count != 0) {
		Pop(s);
	}
	return true;
}

void main()
{
	Stack* stack = CreateStack(10);

	Push(stack, 20);
	Push(stack, 30);
	Push(stack, 40);

	PrintAll(stack);

	Pop(stack);
	PrintAll(stack);

	Clear(stack);
	PrintAll(stack);
}