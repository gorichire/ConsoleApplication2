#include <stdio.h>

struct Heap {
	int* arr;
	int size;
	int capacity;
	bool isMin;
};

inline bool prior(const Heap* h, int x, int y) {
	return h->isMin ? (x < y) : (x > y);
}

Heap* CreateHeap(int capacity, bool isMin = true) {
	Heap* h = new Heap;
	h->arr = new int[capacity + 1];
	h->size = 0;
	h->capacity = capacity;
	h->isMin = isMin;
	return h;
}

void Swap(int& x, int& y) {
	int t = x;
	x = y;
	y = t;
}

void HeapifyUp(Heap* h, int idx) {
	if (!h || idx <= 1) return;
	int p = idx / 2;
	if (prior(h, h->arr[idx], h->arr[p])) {
		Swap(h->arr[idx], h->arr[p]);
		HeapifyUp(h, p);
	}
}

void HeapifyDownRec(Heap* h, int idx) {
	if (!h || idx < 1) return;
	int n = idx * 2;
	int m = n + 1;
	int min = idx;
	
	if (n <= h->size && prior(h, h->arr[n], h->arr[min])) min = n;
	if( m <= h->size && prior(h, h->arr[m], h->arr[min])) min = m;

	if (min != idx) {
		Swap(h->arr[idx], h->arr[min]);
		HeapifyDownRec(h, min);
	}
}

bool Push(Heap* h, int value) {
	if (h == NULL || h->size >= h->capacity) return false;
	h->arr[++h->size] = value;
	HeapifyUp(h, h->size);
	return true;
}

void PrintAll(Heap* h) {
	if (h == NULL || h->size == 0) return;
	for (int i = 1; i <= h->size; ++i) {
		printf("arr[%d] = %d \n", i, h->arr[i]);
	}
	printf("\n");
}

bool Pop(Heap* h) {
	if (h == NULL || h->size == 0) return false;
	h->arr[1] = h->arr[h->size--];
	if (h->size > 0) HeapifyDownRec(h, 1);

	return true;

}

void Clear(Heap* h) { if (h) h->size = 0; }

void Init(Heap* h) {
	if (!h) return;
	delete[] h->arr;
	delete h;
}

int main() {

	Heap* minHeap = CreateHeap(10, true);

	Push(minHeap, 30);
	Push(minHeap, 10);
	Push(minHeap, 20);
	Push(minHeap, 40);
	Push(minHeap, 50);
	Push(minHeap, 5);
	
	PrintAll(minHeap);

	Pop(minHeap);

	PrintAll(minHeap);
	Pop(minHeap);

	Clear(minHeap);
	Init(minHeap);
	PrintAll(minHeap);
}