#include <stdio.h>

struct Stack
{
	int top;		// 가장 위 가르키는거 값 업으면 -1 첫번째 값은 0
	int maxSize;	// 배열 크기
	int* arrays;	// 동적 할당할 배열
};

Stack* CreateStack(int size) {
	Stack* s = new Stack;
	s->top = -1;
	s->maxSize = size;
	s->arrays = new int[size];
	return s;
}

bool Push(Stack* s,int data) {
	if (s->top >= s->maxSize - 1) {
		return false;
	}
	s->arrays[++(s->top)] = data;
	return true;
}

void PrintAll(Stack* s) {
	if (s != NULL) {
		for (int i = 0; i <= s->top; i++) {
			printf("s[%d] = %d \n", i, s->arrays[i]);
		}
	}
	printf("\n");
}

bool Pop(Stack* s) {
	if (s->top == -1) {
		return false;
	}
	return s->arrays[--(s->top)];
}

void Clear(Stack* s) {
	s->top = -1;
}

void Init(Stack* s) {
	delete[] s->arrays;
	delete s;
	s = nullptr;
}

void main()
{
	Stack* stack = CreateStack(100);

	Push(stack,10);
	Push(stack,20);
	Push(stack,30);
	Push(stack,40);

	PrintAll(stack);

	Pop(stack);
	PrintAll(stack);

	Clear(stack);
	PrintAll(stack);

	Init(stack);
	stack = NULL;
	PrintAll(stack);
}