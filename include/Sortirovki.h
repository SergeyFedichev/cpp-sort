#define _CRT_SECURE_NO_WARNINGS
void Bubble(int* b, int n)
{
    int l, f, t;
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


void BestBubble(int n, int* array) {
    int l, start, f, b;
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

void ShellBubble(int n, int* array) {
    int d, f, b;
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

void findMin(int n, int* array) {
    int d, f, b;
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

void sortInclude(int n, int* a, int m) {
    int b, j;
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

void merger(int* first, int NF, int* second, int NS, int k, int* result) {
    int p = 0, q = 0, count = 0;
    first[NF] = abs(first[NF - 1]);
    if (NS > 0) first[NF] += abs(second[NS - 1]);
    second[NS] = first[NF];
    while (count < NF + NS) {
        if (first[p] < second[q]) result[k + count] = first[p++];
        else result[k + count] = second[q++];
        count++;
    }
}
void sortMerge(int n, int* a) {
    int* first = (int*)calloc(n, sizeof(int));
    int* second = (int*)calloc(n / 2 + 1, sizeof(int));
    int NF, NS, d = 1;
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

void ArrayToTest(int* test, int* array, int n) {
    for (int i = 0; i < n; i++) {
        test[i] = array[i];
    }
}

int* newArray(int n) {
    srand(42);
    int* newArray = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        newArray[i] = rand();
    }
    return newArray;
}

int* partRandom(int n) {
    srand((unsigned int)time(NULL));
    int* array = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n / 500; i++) {
        for (int j = 0; j < 500; j++) {
            array[i * 500 + j] = rand() % 500 + i * 500;
        }
    }
    return array;
}