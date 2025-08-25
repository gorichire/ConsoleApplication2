#include <stdio.h>

struct Node
{
	int nData;
	Node* pNext;
};

Node* CreateNode(Node* pNode, int Data);
void printNode(Node* pNode);
Node* InsertNode(Node* pNode,int pData, int data);
Node* DeleteNode(Node* pNode, int data);


int main() {

	Node* pBegin = NULL;
	Node* pEnd = NULL;

	pEnd = CreateNode(pEnd,10);
	pBegin = pEnd;
	printNode(pBegin);

	pEnd = CreateNode(pEnd, 20);
	pEnd = CreateNode(pEnd, 30);
	pEnd = CreateNode(pEnd, 40);
	printNode(pBegin);

	InsertNode(pBegin, 20, 25);
	printNode(pBegin);

	DeleteNode(pBegin, 30);
	printNode(pBegin);	

	return 0;
}

Node* CreateNode(Node* pNode, int Data) {
	
	Node* pTemp = pNode;

	pNode = new Node;
	pNode->nData = Data;
	pNode->pNext = NULL;

	if (pTemp != NULL) {
		pTemp->pNext = pNode;
	}

	return pNode;
}

void printNode(Node* pNode) {
	while (pNode != NULL) {
		printf("%d ", pNode->nData);
		pNode = pNode->pNext;
	}
	printf("\n");	
}

Node* InsertNode(Node* pNode,int pData ,int data) {

	Node* pTemp = new Node;
	pTemp->nData = data;

	while (pNode != NULL) {
		if (pNode->nData == pData) {
			break;
		}
		pNode = pNode->pNext;
	}

	pTemp->pNext = pNode->pNext;	
	pNode->pNext = pTemp;

	return pTemp;
}

Node* DeleteNode(Node* pNode, int data) {
	Node* pTemp = pNode;
	Node* pPrev = NULL;
	while (pTemp != NULL) {
		if (pTemp->nData == data) {
			if (pPrev != NULL) {
				pPrev->pNext = pTemp->pNext;
			}
			else {
				pNode = pTemp->pNext;
			}
			delete pTemp;
			return pNode;
		}
		pPrev = pTemp;
		pTemp = pTemp->pNext;
	}
	return pNode;
}