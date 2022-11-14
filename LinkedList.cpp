#include <iostream>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

class LinkedList
{
    Node *head;

public:
    LinkedList(int x) {
        this->head = new Node();
        this->head->data = x;
        this->head->next = NULL;
    }

    Node *getHead() {
        return this->head;
    }

    void addFirst(int x) {
        Node *temp = new Node();
        temp->data = x;
        temp->next = this->head;
        this->head = temp;

        return;
    }

    void addLast(int x) {
        Node *temp = new Node();
        temp->data = x;
        temp->next = NULL;

        Node *ptr = this->head;
        while (ptr->next != NULL) ptr = ptr->next;
        
        ptr->next = temp;

        return;
    }

    void deleteFirst() {
        Node *temp = this->head;
        this->head = this->head->next;
        delete temp;

        return;
    }

    void deleteLast() {
        Node *ptr = this->head;
        while (ptr->next->next != NULL) ptr = ptr->next;

        delete ptr->next;
        ptr->next = NULL;

        return;
    }

    void printList() {
        Node *temp = this->head;

        while(temp != NULL) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }

        std::cout << std::endl;

        return;
    }
};

int main() {
    LinkedList *l1 = new LinkedList(10);
    l1->addFirst(11);
    l1->addFirst(12);
    l1->addFirst(13);
    l1->printList();
    l1->addLast(20);
    l1->addLast(21);
    l1->addLast(22);
    l1->printList();
    l1->deleteFirst();
    l1->printList();
    l1->deleteLast();
    l1->printList();
}
//TYhis is a test