#include <iostream>
#include <vector>
#include <algorithm>

void SelectionSort(std::vector<int>& v) {
    for (int i=0; i<v.size(); i++) {
        int curMinIndex = i;
        for (int j=i+1; j<v.size(); j++) {
            if (v[j] < v[curMinIndex]) curMinIndex = j;
        }
        std::swap(v[curMinIndex], v[i]);
    }
}

int main() {
    std::vector<int> v1 = {-1, 0, 100, -5, 4, -10, 20, 16, 8};
    for (int x : v1) std::cout << x << " "; std::cout << std::endl;
    SelectionSort(v1);
    for (int x : v1) std::cout << x << " "; std::cout << std::endl;
}