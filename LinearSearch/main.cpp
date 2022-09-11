#include <iostream>

using namespace std;

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

int linearSearch(struct Array arr, int key) {

    for (int i = 0; i < arr.length; i++) {
        if (arr.A[i] == key)
            return i;
    }
    return -1;
}

int linearSearchByTransposition(struct Array *arr, int key) {
    for (int i = 0; i < arr->length; ++i) {
        if (arr->A[i] == key) {
            if (i > 0) {
                swap(arr->A[i - 1], arr->A[i]);
                return (i - 1);
            }
            return i;
        }
    }
    return -1;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    displayArray(arr);
    cout << linearSearch(arr, 2) << endl;
    cout << linearSearchByTransposition(&arr, 6) << endl;
    displayArray(arr);
    return 0;
}
