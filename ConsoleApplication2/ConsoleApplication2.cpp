#include <iostream>

void Swap(int a , int b) {
	int temp = a;
	a = b;
	b = temp;
}

void SwapPointer(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SwapRef(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int oriA = 5;
	int oriB = 10;

	printf("주소값 oriA : %d 변수값 oriA : %d || 주소값 oriB : %d 변수값 oriB : %d \n", &oriA,oriA, &oriB,oriB);
	Swap(oriA, oriB);
	printf("(Swap 후) 주소값 oriA : %d 변수값 oriA : %d || 주소값 oriB : %d 변수값 oriB : %d \n", &oriA, oriA, &oriB, oriB);
	SwapPointer(&oriA, &oriB);
	printf("(SwapPointer 후) 주소값 oriA : %d 변수값 oriA : %d || 주소값 oriB : %d 변수값 oriB : %d \n", &oriA, oriA, &oriB, oriB);
	SwapRef(oriA, oriB);
	printf("(SwapRef 후) 주소값 oriA : %d 변수값 oriA : %d || 주소값 oriB : %d 변수값 oriB : %d \n", &oriA, oriA, &oriB, oriB);
}
