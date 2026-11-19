#include <stdio.h>

#define MAX_LEN 100

static void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

static void heapify(int array[], int n, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;

    if (largest != root) {
        swap(&array[root], &array[largest]);
        heapify(array, n, largest);
    }
}

static void sort(int array[], int n) {
    int i;

    for (i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    for (i = n - 1; i > 0; i--) {
        swap(&array[0], &array[i]);
        heapify(array, i, 0);
    }
}

static void print_array(int *array, int len) {
    int i;

    for (i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[MAX_LEN], len, i;

    printf("What's the length of the array? Maximum length is %d\n", MAX_LEN);
    if (scanf("%d", &len) != 1 || len < 0 || len > MAX_LEN) {
        printf("Invalid array length.\n");
        return 1;
    }

    printf("Gimme the %d elements\n", len);
    for (i = 0; i < len; i++) {
        if (scanf("%d", &array[i]) != 1) {
            printf("Invalid array element.\n");
            return 1;
        }
    }

    printf("Nonsorted array: ");
    print_array(array, len);

    sort(array, len);

    printf("Sorted array: ");
    print_array(array, len);

    return 0;
}
