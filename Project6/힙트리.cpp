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

	bool GetParentIndex(int index, int& returnindex);			// �θ� �ε��� ã��
	bool GetLeftChildIndex(int index, int& indreturnindexex);	// ���� �ڽ� ã��
	bool GetRightChildIndex(int index, int& returnindex);		// ������ �ڽ� ã��
	bool GetPriorityChildIndex(int index, int& returnindex);	// �켱���� ���� �ڽ� ��ȯ

public:
	HeapArray(int size = 10);									// ����
	~HeapArray();												// ����

	bool Insert(int priority, int data);						// ����
	bool Delete(int& data);										// ����
	void PrintAll();											// ���
};


HeapArray::HeapArray(int size)
{
	heapIndex = 0;
	maxSize = size;
	heapArray = new Heap[maxSize + 1];

	printf("������\n");
}

HeapArray::~HeapArray()
{
	printf("�Ҹ���\n");
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
	if (GetLeftChildIndex(index, left) && GetRightChildIndex(index, right)) //�ڽ��� 2�� �ϰ��
	{
		returnindex = heapArray[left].priority <= heapArray[right].priority ? left : right;
		return true;
	}
	else if (GetLeftChildIndex(index, left)) //���� �ڽĸ� �������
	{
		returnindex = left;
		return true;
	}
	else		//�ڽ��� ���� �ܸ� ����� ���
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