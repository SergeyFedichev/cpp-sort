// I see that this file has name with .cpp extension.
// Use .cc/.cpp for C++ and .c for C

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>
#include <time.h>
#include "Sortirovki.h"

// Do not use similar comments, create a static const variable for that
//17 89 213 0 - 123 4 24 5821 84 999 132 5432 -10 42 53 12 592 99

void sortProcess(const char* message, int* array, int size, void(*sortFunc)(int*, int), bool isPrint = false) {
	if (array != NULL && size > 1 && sortFunc != NULL) {
		// Alloc temp array
		int* tmpArr = (int*)calloc(size, sizeof(int));
		if (tmpArr != NULL) {
			// Fill test array
			arrayToTest(tmpArr, array, size);

			// Print message
			if (message != NULL) {
				printf("Message: %s\n", message);
			}

			// Print a source array
			if (isPrint) {
				printf("Source array:");
				for (int i = 0; i < size; ++i) {
					printf(" %d", array[i]);
				}
				printf("\n");
			}

			printf("start sorting...\n");
			long start = (long)time(NULL);

			// Call sort function
			sortFunc(tmpArr, size);
			printf("Process time: %d\n", (long)time(NULL) - start);

			// Print a sorted array
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

int main() {
	setlocale(LC_ALL, "ru-RU"); // avoid that

	// Every variable initialization should be on new line
	int* array = NULL; // need default value initialization. Use NULL for C and nullptr for C++
	int* test = NULL; // need default value initialization

	int timesort[6]; // you do not use time stamp after computing it. I think there is no need to store these values in an array
	long start = 0; // use long instead long int. need default value initialization
	long finish = 0; // use long instead long int. need default value initialization
	int t = 0;
	int n = 0; // need default value initialization

	/*
	The integer type has limit. Limit is maybe different. You need check it. see https://en.cppreference.com/w/cpp/language/types
	Also every machine has limit by RAM. Please limit an array size
	*/

	// Need a text message before that
	scanf("%d", &n); // So, if I enter some invalid value? need to add check for this value

	//array = partRandom(n);

	// Need check for these variables. These may be NULL
	test = (int*)calloc(n, sizeof(int));
	array = newArray(n);
	if (test == NULL || array == NULL) {
		return -1;
	}

	// Use a some flag variable for printing sort array (for command line, for example)
	/*
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &array[i]);
	}
	*/

	// You use the same code for every case. Please create a function for that
	// For example see sortProcess
	sortProcess("bubble", array, n, bubble, true);

	printf("Сортировка пузырьком:\n"); // Use english language here and below
	arrayToTest(test, array, n);
	start = time(NULL); // unsafe convertation to long, please use cast
	bubble(test, n);
	finish = time(NULL); // useless variable. You may use time(NULL) below instead finish
	timesort[0] = finish - start; // compute it in the print function
	printf("Время выполнения: %d\t", timesort[0]);

	/*
	for (int i = 0; i < n; i++) {
		printf("%d\t", test[i]);
	}
	*/
	printf("\nСортировка пузырьком(Улучшенная):\n");
	arrayToTest(test, array, n);
	start = time(NULL);
	bestBubble(n, test);
	finish = time(NULL);
	timesort[1] = finish - start;
	printf("Время выполнения: %d\t", timesort[1]);
	/*
	for (int i = 0; i < n; i++) {
		printf("%d\t", test[i]);
	}
	*/
	printf("\nСортировка Shell:\n");
	arrayToTest(test, array, n);
	start = time(NULL);
	shellBubble(n, test);
	finish = time(NULL);
	timesort[2] = finish - start;
	printf("Время выполнения: %d\t", timesort[2]);
	/*
	for (int i = 0; i < n; i++) {
		printf("%d\t", test[i]);
	}
	*/
	printf("\nСортировка поиском минимального:\n");
	arrayToTest(test, array, n);
	start = time(NULL);
	findMin(n, test);
	finish = time(NULL);
	timesort[3] = finish - start;
	printf("Время выполнения: %d\t", timesort[3]);
	/*
	for (int i = 0; i < n; i++) {
		printf("%d\t", test[i]);
	}
	*/
	printf("\nСортировка встаками:\n");
	arrayToTest(test, array, n);
	start = time(NULL);
	sortInclude(n, test, 1);
	finish = time(NULL);
	timesort[4] = finish - start;
	printf("Время выполнения: %d\t", timesort[4]);
	/*
	for (int i = 0; i < n; i++) {
		printf("%d\t", test[i]);
	}
	*/
	printf("\nСортировка слиянием:\n");
	arrayToTest(test, array, n);
	start = time(NULL);
	sortMerge(n, test);
	finish = time(NULL);
	timesort[5] = finish - start;
	printf("Время выполнения: %d\t", timesort[5]);
	/*
	for (int i = 0; i < n; i++) {
		printf("%d\t", test[i]);
	}
	*/

	// You allocated memory, but do not use free. Memory leaks
	if (test != NULL) {
		free(test);
	}
	if (array != NULL) {
		free(array);
	}
}
