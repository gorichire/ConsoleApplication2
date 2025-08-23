#include <iostream>

void main(){
	const int nSize = 3;
	int arrScores[nSize];
	int arrSize = sizeof(arrScores) / sizeof(arrScores[0]);
	for (int i = 0; i < arrSize; i++) {
		arrScores[i] = 100 - i * 10;
	}
	printf("arrScore[%d] : %d \n", &arrScores, arrScores);

	for (int i = 0; i < arrSize; i++) {
		printf("%d %d %d \n", &arrScores[i], i, arrScores[i]);
	}

	for (int i = 0; i < arrSize; i++) {
		printf("%d %d %d \n", (arrScores + i), i, *(arrScores + i));
	}

	int* pScores = arrScores;
	printf("PtrScore[%d] : %d \n", pScores, *pScores);
	
	for (int i = 0; i < arrSize; i++) {
		printf("%d %d %d \n", pScores, i, *pScores);
		pScores++;
	}
	int arrCopyArr[nSize];
	//for (int i = 0; i < nSize; i++) {
	//	arrCopyArr[i] = arrScores[i];
	//}
	memcpy(arrCopyArr, arrScores, sizeof arrScores);
	for (int i = 0; i < arrSize; i++) {
		printf("%d %d %d \n", &arrCopyArr[i], i, arrCopyArr[i]);
	}
}