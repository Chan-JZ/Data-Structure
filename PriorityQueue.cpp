#include <iostream>
#include <vector>

class MinHeap
{
    public:
    int size;
    std::vector<int> heap;

    MinHeap() {
        size = 0;
        heap.clear();
    }

    void insert(int x) {
        heap.push_back(x);
        bubble_up(heap.size() - 1);
    }

    int getParent(int index) {
        if (index == 0) return -1;
        return (index-1)/2; 
    }

    void bubble_up(int p) {
        if (getParent(p) == -1) return;
        if (heap[getParent(p)] < heap[p]) {
            std::swap(heap[getParent(p)], heap[p]);
            bubble_up(getParent(p));
        }
    }

    int getLeft(int i) {
        return i*2 + 1;
    }

    int getRight(int i) {
        return i*2 + 2;
    }

    void bubble_down(int p) {
        int left_child = getLeft(p);
        int right_child = getRight(p);
        int index = p; // [0, 1, 2, 3, 4, 5, 6]

        // std::cout << "left: " << heap[left_child] << ", " << "right: " << heap[right_child] << ", "<< heap[p] << std::endl;

        if (heap[left_child] > heap[right_child] && left_child < heap.size() && heap[left_child] > heap[p]) {
            // std::cout << "performing left" << std::endl;
            std::swap(heap[p], heap[left_child]);
            index = left_child;
        } 
        else if (heap[right_child] > heap[left_child] && right_child < heap.size() && heap[right_child] > heap[p]) {
            std::swap(heap[p], heap[right_child]); 
            index = right_child;
        }

        if (index != p) {
            bubble_down(index);
        }

    }

    int extract() {
        int root = heap[0];
        if (heap.size() == 1) {
            heap.clear();
            return root;
        }
        int last = heap[heap.size()-1];
        heap[0] = last;
        heap.pop_back();
        bubble_down(0);
        return root;
    }
};

int main() {
    MinHeap *m1 = new MinHeap();
    std::vector<int> v1 = {50, 30, 20, 15, 10, 8, 16};
    for (int x : v1) m1->insert(x);
    

    // for (int i=0; i<m1->heap.size(); i++) std::cout << m1->getParent(i) << " ";
    // std::cout << std::endl;

    m1->insert(60);
    m1->insert(1);
    m1->insert(12);
    for (int i=0; i<m1->heap.size(); i++) std::cout << m1->heap[i] << " ";
    std::cout << std::endl;


    while (m1->heap.size() != 0) {
        std::cout << "extracting: " << m1->extract() << std::endl;;
        // std::cout << "Printing heap: ";
        // for (int j=0; j<m1->heap.size(); j++) std::cout << m1->heap[j] << " ";
        // std::cout << std::endl;
        // std::cout << "heap size: " << m1->heap.size() << std::endl;
    }
}