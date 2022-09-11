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

int deleteElement(struct Array *arr, int index) {
    int x = 0;
    if (index >= 0 && index < arr->length) {
        x = arr->A[index];
        for (int i = index; i < arr->length - 1; i++) {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

int main() {
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    displayArray(arr);
    cout << deleteElement(&arr, 0) << " is deleted." << endl;
    displayArray(arr);
    return 0;
}