#include <stdio.h>

#define MAX 100

struct Stack
{
	int arr[MAX];
	int top;
};

void Init(Stack* s) {
	s->top = -1;
}

void Push(Stack* s, int data) {
	if (s->top < MAX - 1) {
		s->arr[++(s->top)] = data;
	}
}

int Pop(Stack* s) {
	if (s->top >= 0) {
		return s->arr[(s->top)--];
	}
	return -1;
}

int Peek(Stack* s) {
	if (s->top >= 0) {
		return s->arr[s->top];
	}
	return -1;
}

void InsertSort()
{
	int arrData[] = { 8,1,7,4,2,3,9,5,6 };

	//-------------------------------
	//배열을 정렬되도록 로직을 짜기
	//
	//-------------------------------

	//다음출력에서 1~9까지 순서대로 정렬되도록 만들기

	int arrSize = sizeof(arrData) / sizeof(arrData[0]);

	for (int i = 0; i < arrSize; i++) {
		int Min = arrData[i];
		int index = i;
		for (int j = i; j < arrSize; j++) {
			if (Min > arrData[j]) {
				Min = arrData[j];
				index = j;
			}
		}
		arrData[index] = arrData[i];
		arrData[i] = Min;
	}

	printf("Data:");
	for (int i = 0; i < 9; i++)
		printf("%d,", arrData[i]);
	printf("\n");
}

void main()
{
	InsertSort();

	Stack s;
	Init(&s);

	Push(&s, 10);
	Push(&s, 20);
	Push(&s, 30);

	printf("%d\n", Pop(&s)); //30
	printf("%d\n", Peek(&s)); //20 
	printf("%d\n", Pop(&s)); //20

}