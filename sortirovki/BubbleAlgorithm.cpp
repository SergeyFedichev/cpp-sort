#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>
#include <time.h>
#include "C:\Users\sergo\source\repos\sortirovki\sortirovki\Sortirovki.h"

//17 89 213 0 - 123 4 24 5821 84 999 132 5432 -10 42 53 12 592 99

int main() {
	setlocale(LC_ALL, "ru-RU");

	int* array, * test;
	int timesort[6];
	long int start, finish;
	int t = 0, n;
	scanf_s("%d", &n);

	//array = partRandom(n);
	test = (int*)calloc(n, sizeof(int));
	array = newArray(n);
	/*
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &array[i]);
	}
	*/

	printf("Сортировка пузырьком:\n");
	ArrayToTest(test, array, n);
	start = time(NULL);
	Bubble(test, n);
	finish = time(NULL);
	timesort[0] = finish - start;
	printf("Время выполнения: %d\t", timesort[0]);
	/*
	for (int i = 0; i < n; i++) {
		printf("%d\t", test[i]);
	}
	*/
	printf("\nСортировка пузырьком(Улучшенная):\n");
	ArrayToTest(test, array, n);
	start = time(NULL);
	BestBubble(n, test);
	finish = time(NULL);
	timesort[1] = finish - start;
	printf("Время выполнения: %d\t", timesort[1]);
	/*
	for (int i = 0; i < n; i++) {
		printf("%d\t", test[i]);
	}
	*/
	printf("\nСортировка Shell:\n");
	ArrayToTest(test, array, n);
	start = time(NULL);
	ShellBubble(n, test);
	finish = time(NULL);
	timesort[2] = finish - start;
	printf("Время выполнения: %d\t", timesort[2]);
	/*
	for (int i = 0; i < n; i++) {
		printf("%d\t", test[i]);
	}
	*/
	printf("\nСортировка поиском минимального:\n");
	ArrayToTest(test, array, n);
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
	ArrayToTest(test, array, n);
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
	ArrayToTest(test, array, n);
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
}