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

void append(struct Array *arr, int x) {
    if (arr->length < arr->size) {
        arr->A[arr->length++] = x;
    }
}

void insert(struct Array *arr, int index, int x) {
    if (arr->length < arr->size && index >= 0 && index < arr->length) {
        for (int i = arr->length; i > index; i--) {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int main() {
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    append(&arr, 10);
    displayArray(arr);
    insert(&arr, 5, 7);
    displayArray(arr);
    return 0;
}
