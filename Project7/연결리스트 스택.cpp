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
		while (s->top != NULL) {
			printf("%d \n", s->top->ndata);
			s->top = s->top->pNext;
		}
	}
}

bool Push(Stack* s, int data) {
	if (s == NULL) return false;
	s->top = new Node();
	++s->count;
	return true;
}

void main()
{
	Stack* stack = CreateStack(10);

	Push(stack, 20);
	Push(stack, 30);
	Push(stack, 40);

	PrintAll(stack);

	//Pop(stack);
	//PrintAll(stack);

	//Clear(stack);
	//PrintAll(stack);

	//Init(stack);
	//stack = NULL;
	//PrintAll(stack);
}