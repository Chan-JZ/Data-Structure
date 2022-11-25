#include <iostream>

class DynamicArray
{
    public:
    int size, capacity;
    int *arr;
    DynamicArray() {
        size = 0;
        capacity = 1;
        arr = new int[capacity];
    }

    void insert(int x) {
        if (size == capacity) {
            capacity *= 2;
            int *temp = new int[capacity];
            for (int i=0; i<size; i++) {
                temp[i] = arr[i];
            }
            arr = temp;
        } 
        arr[size++] = x;
    }

    void printArr() {
        for (int i=0; i<size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    DynamicArray *d1 = new DynamicArray();
    d1->insert(1);
    d1->insert(2);
    d1->insert(3);
    d1->insert(4);
    d1->insert(5);
    d1->printArr();
    std::cout << "size: " << d1->size << ", capacity: " << d1->capacity << std::endl;


}