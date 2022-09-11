#include <iostream>

using namespace std;

void swap(int *, int *);

struct Array {
    int A[20];
    int size;
    int length;
};

void displayArray(const struct Array arr) {
    int i;
    printf("Elements are \n");
    for (i = 0; i < arr.length; ++i) {
        cout << arr.A[i] << " ";
    }
    cout << endl;
}

void insertSort(struct Array *arr, int x) {
    if (arr->length == arr->size)
        return;
    int arrIndex = arr->length - 1;
    while (arr->A[arrIndex] > x && arrIndex >= 0) {
        arr->A[arrIndex + 1] = arr->A[arrIndex];
        --arrIndex;
    }
    arr->A[arrIndex + 1] = x;
    arr->length++;
}

bool isSorted(const struct Array arr) {
    for (int i = 0; i < arr.length - 1; ++i) {
        if (arr.A[i] > arr.A[i + 1])
            return false;
    }
    return true;
}

Array rearrange(struct Array *arr) {
    int i = 0, j = arr->length - 1;
    while (i < j) {
        while (arr->A[i] < 0)++i;
        while (arr->A[j] >= 0)--j;
        if (i < j)swap(&arr->A[i], &arr->A[j]);
    }
    return *arr;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    struct Array arr = {{2, 3, 5, 10, 15}, 10, 5};
    cout << "Array: " << endl;
    displayArray(arr);
    insertSort(&arr, 11);
    cout << endl << endl << "Insertion Sort Array: ";
    displayArray(arr);
    isSorted(arr) ? cout << "true" : cout << "false";
    displayArray(rearrange(new Array{{2, -3, 25, 10, -15, -7}, 12, 6}));
    return 0;
}
