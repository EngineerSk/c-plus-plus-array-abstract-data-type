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

int get(const struct Array arr, int index) {
    if (index >= 0 && index < arr.length) {
        return arr.A[index];
    }
    return -1;
}

void set(struct Array *arr, int index, int x) {
    if (index >= 0 && index < arr->length)
        arr->A[index] = x;
}

int maximum(const struct Array arr) {
    int max = arr.A[0];
    for (int i = 1; i < arr.length; ++i) {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

int minimum(const struct Array arr) {
    int min = arr.A[0];
    for (int i = 1; i < arr.length; ++i) {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

int sum(const struct Array arr) {
    int sum = 0;
    for (int i = 0; i < arr.length; ++i)
        sum += arr.A[i];
    return sum;
}

float average(const struct Array arr) {
    return (float) sum(arr) / (float) (arr.length);
}

int main() {
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    displayArray(arr);
    return 0;
}