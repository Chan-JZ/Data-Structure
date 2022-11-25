#include <iostream>

typedef struct Node {
    int data;
    Node *left;
    Node *right;
} Node;

class BST
{
    public:
    Node *root;

    BST() {
        root = NULL;
    }

    Node *getNewNode(int x) {
        Node *temp = new Node();
        temp->data = x;
        temp->left = NULL;
        temp->right = NULL;

        return temp;
    }

    void insert(int x, Node **ptr) {
        if (*ptr == NULL) {
            *ptr = getNewNode(x);
            return;
        }
        else if ((*ptr)->data < x) insert(x, &(*ptr)->right); 
        else insert(x, &(*ptr)->left);
    }

    void deleteNode(int x, Node **ptr) {
        if ((*ptr)->data < x) deleteNode(x, &((*ptr)->right));
        else if ((*ptr)->data > x) deleteNode(x, &((*ptr)->left));
        else if ((*ptr)->data == x) {
            if ((*ptr)->left == NULL && (*ptr)->right == NULL) {
                delete *ptr;
                *ptr = NULL;
                return;
            } else if ((*ptr)->left != NULL && (*ptr)->right != NULL) {
                Node *temp = (*ptr)->left;
                while (temp->right != NULL) temp = temp->right;
                (*ptr)->data = temp->data;

                deleteNode(temp->data, &((*ptr)->left));
            } else {
                if ((*ptr)->right != NULL) {
                    (*ptr)->data = (*ptr)->right->data;
                    delete (*ptr)->right;
                    (*ptr)->right = NULL;
                } else {
                    (*ptr)->data = (*ptr)->left->data;
                    delete (*ptr)->left;
                    (*ptr)->left = NULL;
                }
            }
        }
        
        
    }

    void preOrderTraverse(Node *ptr) {
        if (ptr == NULL) return;
        std::cout << ptr->data << " ";
        preOrderTraverse(ptr->left);
        preOrderTraverse(ptr->right);
    }
};

int main() {
    BST *b1 = new BST();
    b1->insert(2, &(b1->root));
    b1->insert(1, &(b1->root));
    b1->insert(7, &(b1->root));
    b1->insert(4, &(b1->root));
    b1->insert(3, &(b1->root));
    b1->insert(6, &(b1->root));
    b1->insert(5, &(b1->root));
    b1->insert(8, &(b1->root));
    b1->preOrderTraverse(b1->root);
    std::cout << std::endl;
    b1->deleteNode(4, &(b1->root));
    b1->preOrderTraverse(b1->root);
    std::cout << std::endl;
}