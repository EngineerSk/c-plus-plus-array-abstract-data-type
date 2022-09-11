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

struct Array *mergeArrays(const struct Array *arr1, const struct Array *arr2) {
    auto *arr3 = new Array();
    int i = 0, j = 0, k = 0;
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
        } else {
            arr3->A[k++] = arr2->A[j++];
        }
    }
    while (i < arr1->length)
        arr3->A[k++] = arr1->A[i++];
    while (j < arr2->length)
        arr3->A[k++] = arr2->A[j++];
    arr3->size = k * 2;
    arr3->length = k;

    return arr3;
}

struct Array *unionOfArrays(const struct Array *arr1, const struct Array *arr2) {
    auto *arr3 = new Array();
    int i = 0, j = 0, k = 0;
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr1->A[i] > arr2->A[j])
            arr3->A[k++] = arr2->A[j++];
        else {
            arr3->A[k++] = arr1->A[i++];
            ++j;
        }
    }
    while (i < arr1->length)
        arr3->A[k++] = arr1->A[i++];
    while (j < arr2->length)
        arr3->A[k++] = arr2->A[j++];
    arr3->size = k * 2;
    arr3->length = k;
    return arr3;
}

struct Array *intersectionOfArrays(const struct Array *arr1, const struct Array *arr2) {
    auto *arr3 = new Array();

    int i = 0, j = 0, k = 0;

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr1->A[i] > arr2->A[j])
            ++j;
        else {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    arr3->size = k * 2;
    arr3->length = k;
    return arr3;
}

struct Array *differenceElementsOfArray1NotArray2(const struct Array *arr1, const struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    auto *arr3 = (struct Array *) malloc(sizeof(struct Array));
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
        } else if (arr1->A[i] > arr2->A[j]) {
            ++j;
        } else {
            ++i;
            ++j;
        }
    }
    while (i < arr1->length)
        arr3->A[k++] = arr1->A[i++];
    arr3->length = k;
    arr3->size = k * 2;
    return arr3;
}

int main() {
    struct Array arr1 = {{2, 6, 10, 15, 25}, 10, 5};
    struct Array arr2 = {{3, 4, 6, 10, 18, 20}, 10, 6};
    cout << "Array 1: " << endl;
    displayArray(arr1);
    cout << "Array 2: " << endl;
    displayArray(arr2);
    cout << endl;
    cout << "Merging Array 1 and Array 2: " << endl;
    displayArray(*mergeArrays(&arr1, &arr2));
    cout << endl;
    cout << "Union of Array 1 and Array 2: " << endl;
    displayArray(*unionOfArrays(&arr1, &arr2));
    cout << endl;
    cout << "Intersection or common elements in Array 1 and Array 2: " << endl;
    displayArray(*intersectionOfArrays(&arr1, &arr2));
    cout << endl;
    cout << "Difference elements of Array 1 not Array 2: " << endl;
    displayArray(*differenceElementsOfArray1NotArray2(&arr1, &arr2));
    cout << endl;
    cout << "Difference elements of Array 2 not Array 1: " << endl;
    displayArray(*differenceElementsOfArray1NotArray2(&arr2, &arr1));
    return 0;
}