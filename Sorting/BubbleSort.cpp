#include <iostream>
#include <vector>
#include <algorithm>

void BubbleSort(std::vector<int>& arr) {
    bool flag = false;
    for (int i=0; i<arr.size()-1; i++) if (arr[i] > arr[i+1]) flag = true;
    if (!flag) return;

    for (int i=0; i<arr.size(); i++) {
        for (int j=0; j<arr.size()-i-1; j++) {
            if (arr[j] > arr[j+1]) std::swap(arr[j], arr[j+1]);
        }
    }
}

int main() {
    std::vector<int> v1 = {-1, 0, 100, -5, 4, -10, 20, 16, 8};
    for (int x : v1) std::cout << x << " "; std::cout << std::endl;
    BubbleSort(v1);
    for (int x : v1) std::cout << x << " "; std::cout << std::endl;
}