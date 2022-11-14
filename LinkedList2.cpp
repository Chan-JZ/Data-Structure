#include <iostream>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void insertHead(Node **head, int x) {
    Node *temp = new Node();
    temp->data = x;
    temp->next = *head;

    *head = temp;
}

void insertTail(Node *head, int x) {
    while (head->next != NULL) {
        head = head->next;
    }

    Node *temp = new Node();
    temp->data = x;
    temp->next = NULL;

    head->next = temp;
}

void printList(Node *head) {
    while (head != NULL) {
        std::cout << head->data << std::endl;
        head = head->next;
    }
}

int main() {
    Node *head;
    head->data = 1;
    head->next = NULL;

    insertHead(&head, 10);
    insertHead(&head, 11);


    insertTail(head, 100);
    insertTail(head, 101);
    printList(head);

}
//asdasdas