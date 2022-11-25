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
        int index = p; 

        if (left_child < heap.size() && right_child < heap.size()) {
            if (heap[left_child] > heap[right_child] && heap[left_child] > heap[p]) {
                std::swap(heap[p], heap[left_child]);
                index = left_child;
            } else if (heap[left_child] < heap[right_child] && heap[left_child] > heap[p]) {
                std::swap(heap[p], heap[right_child]); 
                index = right_child;
            }
        } else if (left_child < heap.size() || right_child < heap.size()) {
            if (left_child < heap.size() && heap[left_child] > heap[p]) {
                std::swap(heap[p], heap[left_child]);
                index = left_child;
            } else if (right_child < heap.size() && heap[right_child] > heap[p]) {
                std::swap(heap[p], heap[right_child]); 
                index = right_child;
            }
        }



        if (index != p) {
            bubble_down(index);
        }

    }

    std::vector<int> HeapSort() {
        std::vector<int> res;
        int n = heap.size();
        for (int i=0; i<n; i++) {
            std::cout << "heap[0]: " << heap[0]  << std::endl;
            res.insert(res.begin(), heap[0]);
            std::swap(heap[0], heap[heap.size()-1]);
            heap.pop_back();
            bubble_down(0);

            std::cout << "printing heap: " << std::endl;
            for (int x : heap) std::cout << x << " ";
            std::cout << std::endl;
        }

        for (int i=0; i<res.size(); i++) {
            insert(res[i]);
        }

        std::cout << "printing heap finally: " << std::endl;
            for (int x : heap) std::cout << x << " ";
            std::cout << std::endl;

        return res;
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


    std::vector<int> sorted = m1->HeapSort();
    for (int x : sorted) std::cout << x << " ";
    std::cout << std::endl;

    std::cout << "------------------------------------" << std::endl;

    std::vector<int> sorted2 = m1->HeapSort();
    for (int x : sorted2) std::cout << x << " ";
    std::cout << std::endl;
}