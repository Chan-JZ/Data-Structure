#include <iostream>
#include <vector>

void Merge(std::vector<int>& v, std::vector<int>& left, std::vector<int>& right) {
    int i, j, index;
    i = j = index = 0;

    while (index < left.size()+right.size()) {
        if (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) v[index++] = left[i++];
            else v[index++] = right[j++];
        } 
        else if (i < left.size()) v[index++] = left[i++];
        else v[index++] = right[j++];
    }
}

void MergeSort(std::vector<int>& v) {
    int n = v.size();

    if (n < 2) return;

    int mid = n/2;
    std::vector<int> left(mid); 
    std::vector<int> right(n-mid);

    for (int i=0; i<mid; i++) left[i] = v[i];
    for (int i=mid; i<n; i++) right[i-mid] = v[i];

    MergeSort(left);
    MergeSort(right);
    Merge(v, left, right);
}

int main() {
    std::vector<int> v1 = {-1, 0, 100, -5, 4, -10, 20, 16, 8, 8, -1};
    for (int x : v1) std::cout << x << " "; std::cout << std::endl;
    MergeSort(v1);
    for (int x : v1) std::cout << x << " "; std::cout << std::endl;
}