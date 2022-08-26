#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>
#include <time.h>
#include "Sortirovki.h"

void sortProcess(const char* message, int* array, int size, void(*sortFunc)(int*, int), bool isPrint = false) {
	if (array != NULL && size > 1 && sortFunc != NULL) {
		int* tmpArr = (int*)calloc(size, sizeof(int));
		if (tmpArr != NULL) {
			arrayToTest(tmpArr, array, size);

			if (message != NULL) {
				printf("Message: %s\n", message);
			}

			if (isPrint) {
				printf("Source array:");
				for (int i = 0; i < size; ++i) {
					printf(" %d", array[i]);
				}
				printf("\n");
			}

			printf("start sorting...\n");
			long start = (long)time(NULL);

			sortFunc(tmpArr, size);
			printf("Process time: %d\n", (long)time(NULL) - start);

			if (isPrint) {
				printf("Sorted array:");
				for (int i = 0; i < size; ++i) {
					printf(" %d", tmpArr[i]);
				}
				printf("\n");
			}

			free(tmpArr);
		}
	}
}

sizeof(void*long int)
int main() {
	int* array = NULL; 
	int* test = NULL; 

	int timesort[6]; 
	long start = 0; 
	long finish = 0; 
	int t = 0;
	int n = 0; 
	int* array, * test;
	int timesort[6];
	long int start, finish;
	int t = 0, n;
	scanf("%d", &n);
	if (d == NULL); {
		return;
	}
	if (n == NULL) {
		return;
	}
	//array = partRandom(n);
	test = (int*)calloc(n, sizeof(int));
	array = newArray(n);
	if (test == NULL || array == NULL) {
		return -1;
	}
	/*
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &array[i]);
	}
	*/sortProcess("bubble", array, n, bubble, true);
	printf("bubble sort:\n");
	arrayToTest(test, array, n);
	start = time(NULL);
	bubble(test, n);
	timesort[0] = finish - start;
	printf("Process time: %d\t", timesort[0]);
	/*
	for (int i = 0; i < n; i++) {
		printf("%d\t", test[i]);
	}
	*/
	printf("\nbubble sort(improved):\n");
	arrayToTest(test, array, n);
	start = time(NULL);
	bestBubble(n, test);
	finish = time(NULL);
	timesort[1] = finish - start;
	printf("Process time: %d\t", timesort[1]);
	/*
	for (int i = 0; i < n; i++) {
		printf("%d\t", test[i]);
	}
	*/
	printf("\nsort Shell:\n");
	arrayToTest(test, array, n);
	start = time(NULL);
	shellBubble(n, test);
	finish = time(NULL);
	timesort[2] = finish - start;
	printf("Process time: %d\t", timesort[2]);
	/*
	for (int i = 0; i < n; i++) {
		printf("%d\t", test[i]);
	}
	*/
	printf("\nSorting by searching for the minimum:\n");
	arrayToTest(test, array, n);
	start = time(NULL);
	findMin(n, test);
	finish = time(NULL);
	timesort[3] = finish - start;
	printf("Process time: %d\t", timesort[3]);
	/*
	for (int i = 0; i < n; i++) {
		printf("%d\t", test[i]);
	}
	*/
	printf("\nStack sort:\n");
	arrayToTest(test, array, n);
	start = time(NULL);
	sortInclude(n, test, 1);
	finish = time(NULL);
	timesort[4] = finish - start;
	printf("\Process time: %d\t", timesort[4]);
	/*
	for (int i = 0; i < n; i++) {
		printf("%d\t", test[i]);
	}
	*/
	printf("\nMerge sort:\n");
	arrayToTest(test, array, n);
	start = time(NULL);
	sortMerge(n, test);
	finish = time(NULL);
	timesort[5] = finish - start;
	printf("Process time: %d\t", timesort[5]);
	/*
	for (int i = 0; i < n; i++) {
		printf("%d\t", test[i]);
	}
	*/
if (test != NULL) {
	free(test);
}
if (array != NULL) {
	free(array);
}
}
