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
	if (!h || idx < 1 || idx > h->size) return;
	while (true) {
		int l = idx * 2, r = l + 1;
		int best = idx;
		if (l <= h->size && prior(h, h->arr[l], h->arr[best])) best = l;
		if (r <= h->size && prior(h, h->arr[r], h->arr[best])) best = r;
		if (best == idx) break;
		Swap(h->arr[idx], h->arr[best]);
		idx = best;
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

void Destroy(Heap*& h) {
	if (!h) return;
	delete[] h->arr;
	h->arr = nullptr;
	delete h;
	h = nullptr; 
}

int main() {

	Heap* minHeap = CreateHeap(10, true);

	Push(minHeap, 30);
	Push(minHeap, 10);
	Push(minHeap, 20);
	Push(minHeap, 40);
	Push(minHeap, 50);
	
	PrintAll(minHeap);

	Pop(minHeap);

	PrintAll(minHeap);
	Pop(minHeap);

	Clear(minHeap);
	Destroy(minHeap);
	PrintAll(minHeap);
}