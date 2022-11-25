#include <iostream>
#include <vector>
#include <algorithm>

void InsertionSort(std::vector<int>& v) {
    for (int i=1; i<v.size(); i++) {
        int key = v[i];
        int index = i-1;
        while (index >=0 && key < v[index]) {
            v[index+1] = v[index];
            index--;
        }
        v[index+1] = key;
    }
}

int main() {
    std::vector<int> v1 = {-1, 0, 100, -5, 4, -10, 20, 16, 8};
    for (int x : v1) std::cout << x << " "; std::cout << std::endl;
    InsertionSort(v1);
    for (int x : v1) std::cout << x << " "; std::cout << std::endl;

    return 0;
}