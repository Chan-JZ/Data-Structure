#include <iostream>
#include <vector>
#include <algorithm>

int Partition(std::vector<int>& v, int l, int r) {
    int pivot = v[r];
    int partitionIndex = 0;

    for (int i=l; i<r; i++) {
        if (v[i] < pivot) std::swap(v[i], v[partitionIndex++]);
    }
    std::swap(v[partitionIndex], v[r]);

    return partitionIndex;
}

void QuickSort(std::vector<int>& v, int l, int r) {
    if (l >= r) return;

    int partitionIndex = Partition(v, l, r);
    QuickSort(v, l, partitionIndex-1);
    QuickSort(v, partitionIndex+1, l);

}

int main() {
    std::vector<int> v1 = {-1, 0, 100, -5, 4, -10, 20, 16, 8, 8, -1};
    for (int x : v1) std::cout << x << " "; std::cout << std::endl;
    QuickSort(v1, 0, v1.size()-1);
    for (int x : v1) std::cout << x << " "; std::cout << std::endl;

    return 0;
}