#include <iostream>
#include <vector>

int main() {
    std::vector<int> v1 = {1, 2, 3, 4, 5, 6};
    for (int i=0; i<v1.size(); i++) {
        for (int j=0; j<v1.size(); j++) {
            std::cout << v1[j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "---------------------------------" << std::endl;
    for (int i=0; i<v1.size(); i++) {
        for (int j=i; j<v1.size(); j++) {
            std::cout << v1[j] << " ";
        }
        std::cout << std::endl;
    }
}