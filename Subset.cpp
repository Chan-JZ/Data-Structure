#include <iostream>
#include <vector>

class Subset
{
    public:
    std::vector<std::vector<int>> generateSubset(std::vector<int> v) {
        std::vector<std::vector<int>> result;
        std::vector<int> subset;

        dfs(0, subset, result, v);

        for (auto x : result) {
            for (int i=0; i<x.size(); i++) std::cout << x[i] << " ";
            std::cout << std::endl;
        }

        return result;
    }

    void dfs(int i, std::vector<int>& subset, std::vector<std::vector<int>>& result, std::vector<int>& v) {
        if (i == v.size()) {
            result.push_back(subset);
            return;
        }

        subset.push_back(v[i]);
        dfs(i+1, subset, result, v);

        subset.pop_back();
        dfs(i+1, subset, result, v); // [1, 2, 3], [1, 2], [1, 3], [1], [2,3], [2], [3], []
    }
};

int main() {
    std::vector<int> v = {1, 2, 3, 4};
    Subset *s1 = new Subset();
    std::vector<std::vector<int>> result = s1->generateSubset(v);
}