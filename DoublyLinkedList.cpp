#include <iostream>

typedef struct Node{
    int data;
    Node *next;
    Node *prev;
} Node;

class LinkedList
{
    Node *head;

    public:
    LinkedList() {
        this->head = NULL;
    }

    Node *getNewNode(int x) {
        Node *temp = new Node();
        temp->data = x;
        temp->next = NULL;
        temp->prev = NULL;

        return temp;
    }

    void addFirst(int x) {
        Node *temp = getNewNode(x);
        
        if (this->head == NULL) {
            this->head = temp;
            return;
        }

        this->head->prev = temp;
        temp->next = this->head;
        this->head = temp;      
    }

    void addLast(int x) {
        Node *temp = getNewNode(x);

        if (this->head == NULL) {
            this->head = temp;
            return;
        }

        Node *ptr = this->head;
        while (ptr->next != NULL) ptr = ptr->next;

        ptr->next = temp;
        temp->prev = ptr;
    }

    void printList() {
        Node *ptr = this->head;

        while (ptr != NULL) {
            std::cout << ptr->data << " ";
            ptr = ptr->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList *l1 = new LinkedList();
    l1->addLast(1);
    l1->addLast(2);
    l1->addLast(3);
    l1->addLast(4);
    l1->addLast(5);
    l1->printList();
}