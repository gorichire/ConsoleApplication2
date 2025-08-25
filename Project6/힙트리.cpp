#include <stdio.h>

struct Heap {
	int priority;
	int data;
};

class HeapArray {
private:
	int heapIndex;
	int maxSize;
	Heap* heapArray;

	bool GetParentIndex(int index, int& returnindex);			// 부모 인덱스 찾기
	bool GetLeftChildIndex(int index, int& indreturnindexex);	// 왼쪽 자식 찾기
	bool GetRightChildIndex(int index, int& returnindex);		// 오른쪽 자식 찾기
	bool GetPriorityChildIndex(int index, int& returnindex);	// 우선순위 높은 자식 반환

public:
	HeapArray(int size = 10);									// 생성
	~HeapArray();												// 제거

	bool Insert(int priority, int data);						// 삽입
	bool Delete(int& data);										// 삭제
	void PrintAll();											// 출력
};


HeapArray::HeapArray(int size)
{
	heapIndex = 0;
	maxSize = size;
	heapArray = new Heap[maxSize + 1];

	printf("생성자\n");
}

HeapArray::~HeapArray()
{
	printf("소멸자\n");
}

bool HeapArray::Insert(int priority, int data)
{
	if (heapIndex >= maxSize)
		return false;

	Heap newData = { priority ,data };
	int parentIndex;
	int currentIndex = heapIndex + 1;

	while (GetParentIndex(currentIndex, parentIndex))
	{
		if (newData.priority < heapArray[parentIndex].priority)
		{
			heapArray[currentIndex] = heapArray[parentIndex];
			currentIndex = parentIndex;
		}
		else
			break;
	}
	heapArray[currentIndex] = newData;
	heapIndex++;
	return true;
}

bool HeapArray::Delete(int& data)
{
	if (heapIndex <= 0)
		return false;

	data = heapArray[1].data;
	printf("Delete - data : %d\n", data);

	Heap lastData = heapArray[heapIndex];
	int parentIndex = 1;
	int childIndex;

	while (GetPriorityChildIndex(parentIndex, childIndex))
	{
		if (lastData.priority <= heapArray[childIndex].priority)
			break;

		heapArray[parentIndex] = heapArray[childIndex];
		parentIndex = childIndex;
	}

	heapArray[parentIndex] = lastData;
	heapIndex--;

	return true;
}

bool HeapArray::GetParentIndex(int index, int& returnindex)
{
	if (index / 2 == 0)
		return false;

	returnindex = index / 2;
	return true;
}

bool HeapArray::GetLeftChildIndex(int index, int& returnindex)
{
	if (index * 2 > heapIndex)
		return false;

	returnindex = index * 2;
	return true;
}

bool HeapArray::GetRightChildIndex(int index, int& returnindex)
{
	if (index * 2 + 1 > heapIndex)
		return false;

	returnindex = index * 2 + 1;
	return true;
}

bool HeapArray::GetPriorityChildIndex(int index, int& returnindex)
{
	int left;
	int right;
	if (GetLeftChildIndex(index, left) && GetRightChildIndex(index, right)) //자식이 2개 일경우
	{
		returnindex = heapArray[left].priority <= heapArray[right].priority ? left : right;
		return true;
	}
	else if (GetLeftChildIndex(index, left)) //왼쪽 자식만 있을경우
	{
		returnindex = left;
		return true;
	}
	else		//자식이 없는 단말 노드일 경우
		return false;

}

void HeapArray::PrintAll()
{
	for (int i = 1; i <= heapIndex; i++)
	{
		printf("index : %d    pri : %d    data : %d\n", i, heapArray[i].priority, heapArray[i].data);
	}
}

int main()
{
	HeapArray* arrayHeap = new HeapArray();

	arrayHeap->Insert(9, 9);
	arrayHeap->Insert(1, 1);
	arrayHeap->Insert(8, 8);
	arrayHeap->Insert(3, 3);
	arrayHeap->Insert(5, 5);
	arrayHeap->Insert(4, 4);
	arrayHeap->Insert(1, 10);
	arrayHeap->Insert(6, 6);
	arrayHeap->Insert(7, 7);
	arrayHeap->Insert(2, 2);
	arrayHeap->PrintAll();

	printf("\n");
	int data;
	arrayHeap->Delete(data);
	arrayHeap->Delete(data);
	arrayHeap->Delete(data);
	arrayHeap->Delete(data);
	arrayHeap->Delete(data);
	arrayHeap->Delete(data);
	arrayHeap->Delete(data);
	arrayHeap->Delete(data);
	arrayHeap->Delete(data);
	arrayHeap->Delete(data);
	arrayHeap->Delete(data);
	arrayHeap->Delete(data);
	arrayHeap->PrintAll();

	delete arrayHeap;
}