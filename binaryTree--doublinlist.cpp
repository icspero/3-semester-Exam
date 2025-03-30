#include <iostream>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int data;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BTree {
public:
    Node* root;    

    BTree() : root(nullptr) {}

    Node* treeToDLL(Node* root) {
        Node* head = nullptr;
        Node* prev = nullptr;

        inorder(root, prev, head);

        return head;
    }

private:
    void inorder(Node* node, Node*& prev, Node*& head) {
        if (!node) return;

        inorder(node->left, prev, head);

        if (prev == nullptr) head = node;
        else {
            prev->right = node;
            node->left = prev;
        }

        prev = node;

        inorder(node->right, prev, head);
    }
};

void printDLL(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
}

int main() {
    BTree t;

    t.root = new Node(50);
    t.root->left = new Node(40);
    t.root->right = new Node(60);
    t.root->left->left = new Node(30);
    t.root->right->right = new Node(70);

    Node* head = t.treeToDLL(t.root);

    printDLL(head);
}