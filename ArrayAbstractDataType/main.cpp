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

int main() {
    struct Array arr = {{2,3,4,5,6},20, 5};
    displayArray(arr);
    return 0;
}
