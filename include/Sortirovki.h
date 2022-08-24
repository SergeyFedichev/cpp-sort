// This file has Russian like name. Please use english like name

// Please use double include guards for headers
// see https://itecnote.com/tecnote/c-the-use-of-double-include-guards-in-c/
#ifndef SORT_H
#define SORT_H

#define _CRT_SECURE_NO_WARNINGS // avoid that


// Please use the same signature for every function if possible (for example bubble(array, size)). It has not the same as others
void bubble(int* b, int n) { // please use the same code style
    if (b == NULL) { // need null check for b
        return;
    }

    int l, f, t; // initialize every variable by default value. Also use different lines. Check here and below
    l = n - 1;
    do {
        f = 0;
        for (int i = 0; i < l; i++) {
            if (b[i] > b[i + 1]) {
                t = b[i];
                b[i] = b[i + 1];
                b[i + 1] = t;
                f = 1;
            }
        }
        l--;
    } while (f == 1);
}


void bestBubble(int n, int* array) { // need null check for array
    int l, start, f, b; // initialize every variable by default value. Also use different lines. Check here and below
    l = n - 1;
    start = 0;
    do {
        f = 0;
        for (int i = start; i < l; i++) {
            if (array[i] > array[i + 1]) {
                b = array[i];
                array[i] = array[i + 1];
                array[i + 1] = b;
                f = 1;
            }
        }
        l--;
        if (f == 1) {
            f = 0;
            for (int i = l; i > start; i--) {
                if (array[i] < array[i - 1]) {
                    b = array[i];
                    array[i] = array[i - 1];
                    array[i - 1] = b;
                    f = 1;
                }
            }
            start++;
        }
    } while (f == 1);
}

void shellBubble(int n, int* array) { // need null check fro array
    int d, f, b; // initialize every variable by default value. Also use different lines. Check here and below
    d = n;
    do {
        f = 0;
        d = (d + 1) / 2;
        for (int i = 0; i + d < n; i++) {
            if (array[i] > array[i + d]) {
                b = array[i];
                array[i] = array[i + d];
                array[i + d] = b;
                f = 1;
            }
        }
    } while (d > 1 || f == 1);
}

void findMin(int n, int* array) { // need null check for array
    int d, f, b; // initialize every variable by default value. Also use different lines. Check here and below
    d = n;
    do {
        f = 0;
        d = (d + 1) / 2;
        for (int i = 0; i + d < n; i++) {
            if (array[i] > array[i + d]) {
                b = array[i];
                array[i] = array[i + d];
                array[i + d] = b;
                f = 1;
            }
        }
    } while (d > 1 || f == 1);
}

void sortInclude(int n, int* a, int m) { // need null check for a
    int b, j; // initialize every variable by default value. Also use different lines. Check here and below
    for (int i = m; i < n; i++) {
        b = a[i];
        j = i - 1;
        while ((j >= 0) && (b < a[j])) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = b;
    }
}

void merger(int* first, int NF, int* second, int NS, int k, int* result) { // need null check for first, second, result
    int p = 0, q = 0, count = 0; // use different lines. Check here and below

    first[NF] = abs(first[NF - 1]);
    if (NS > 0) { // please use the same code style
        first[NF] += abs(second[NS - 1]);
    }

    second[NS] = first[NF];

    while (count < NF + NS) {
        if (first[p] < second[q]) { // please use the same code style
            result[k + count] = first[p++];
        }
        else { // please use the same code style
            result[k + count] = second[q++];
        }
        count++;
    }
}
void sortMerge(int n, int* a) { // need null check for a
    int* first = (int*)calloc(n, sizeof(int)); // need null check
    int* second = (int*)calloc(n / 2 + 1, sizeof(int)); // need null check
    int NF, NS, d = 1; // initialize every variable by default value. Also use different lines. Check here and below

    while (d < n) {
        int k = 0;
        while (k + d < n) {
            NF = 0;
            for (int i = 0; (i < d) && (k + i < n); i++) {
                first[NF++] = a[k + i];
            }
            NS = 0;
            for (int i = 0; (i < d) && (k + i + d < n); i++) {
                second[NS++] = a[k + i + d];
            }
            merger(first, NF, second, NS, k, a);
            k += 2 * d;
        }
        d = d * 2;
    }
}

//
// Use the helper functions in the sample file
//
void arrayToTest(int* test, int* array, int n) {// need null check for test, array
    if (test != NULL && array != NULL) {
        for (int i = 0; i < n; i++) {
            test[i] = array[i];
        }
    }
}

int* newArray(int n) {
    srand(42);
    int* newArray = (int*)calloc(n, sizeof(int));
    if (newArray != NULL) { // need null check
        for (int i = 0; i < n; i++) {
            newArray[i] = rand();
        }
    }
    return newArray;
}

int* partRandom(int n) {
    srand((unsigned)time(NULL)); // use unsigned instead unisgned int

    int* array = (int*)calloc(n, sizeof(int));
    if (array != NULL) { // need null check
        for (int i = 0; i < n / 500; i++) {
            for (int j = 0; j < 500; j++) {
                array[i * 500 + j] = rand() % 500 + i * 500;
            }
        }
    }
    return array;
}

#endif // !SORT_H
// Need empty line in every file (using for git parsing)
