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

int binarySearch(struct Array arr, int key) {
    int l = 0, r = arr.length - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr.A[mid] == key)
            return mid;
        else if (arr.A[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int recursiveBinarySearch(const struct Array arr, int l, int r, int key) {
    if (l <= r) {
        int mid = (l + r) / 2;
        if (arr.A[mid] == key)
            return mid;
        else if (arr.A[mid] < key)
            return recursiveBinarySearch(arr, mid + 1, r, key);
        else
            return recursiveBinarySearch(arr, l, mid - 1, key);
    }
    return -1;
}

int main() {
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    displayArray(arr);
    cout << binarySearch(arr, 5) << endl;
    cout << recursiveBinarySearch(arr, 0, arr.length, 4) << endl;
    return 0;
}