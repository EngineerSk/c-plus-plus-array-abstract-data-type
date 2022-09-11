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

void reverse(struct Array *arr) {
    for (int i = 0; i < (arr->length - i - 1); ++i) {
        swap(&arr->A[i], &arr->A[arr->length - i - 1]);
    }
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    struct Array arr = {{2, 3, 4, 5, 6, 7, 8}, 10, 7};
    cout << "Array: " << endl;
    displayArray(arr);
    reverse(&arr);
    cout << endl << endl << "Reversed Array: ";
    displayArray(arr);
    return 0;
}
