#include <iostream>
#include <vector>

class Permutation
{
    public:
    std::vector<std::vector<int>> generatePermutations(std::vector<int> nums) {
        if (nums.size() == 1) return {nums};

        std::vector<std::vector<int>> result;
        for (int i=0; i<nums.size(); i++) {
            std::vector<int> v(nums.begin(), nums.end());
            v.erase(v.begin() + i);
            auto res = generatePermutations(v);

            for (int j=0; j<res.size(); j++) {
                std::vector<int> _v = res[j];
                _v.insert(_v.begin(), nums[i]);
                result.push_back(_v);
            }
        }   

        return result;
    }

};

int main() {
    Permutation *p1 = new Permutation();
    std::vector<int> v = {1, 2, 3};
    std::vector<std::vector<int>> v2 = p1->generatePermutations(v);
    for (auto x : v2) {
        for (auto y : x) std::cout << y << " ";
        std::cout << std::endl;
    }
}