#include <iostream>

template<class T>
class Array {
private:
    T *A;
    int length, size;
public:
    Array() {
        size = 10;
        A = new T[size];
        length = 0;
    }

    Array(int size) {
        this->size = size;
        A = new T[size];
        length = 0;
    }

    ~Array() {
        delete[]A;
    }

    void display();

    void insert(int index, T x);

    T deleteElement(int index);
};

template<class T>
void Array<T>::display() {
    for (int i = 0; i < length; ++i) {
        std::cout << A[i] << " ";
    }
}

template<class T>
void Array<T>::insert(int index, T x) {
    if (index >= 0 && index <= length) {
        int i = length-1;
        for (; i >= index; i--) {
            A[i + 1] = A[i];
        }
        A[i + 1] = x;
        length++;
    }
}

template<class T>
T Array<T>::deleteElement(int index) {
    T x;
    if (index >= 0 && index < length) {
        x = A[index];
        for (int i = index; i < length - 1; ++i)
            A[i] = A[i + 1];
        length--;
    }
    return x;
}

int main() {
    Array<int> arr(10);
    arr.insert(0, 3);
    arr.insert(1, 4);
    arr.insert(2, 5);
    arr.display();
    return 0;
}
