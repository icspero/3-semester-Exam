#include <iostream>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int data;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() : root(nullptr) {}

    Node* findMin(Node* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }

    Node* delNode(Node* node, int val) {
        if (!node) return nullptr;

        if (val < node->data) {
            node->left = delNode(node->left, val);
        }
        else if (val > node->data) {
            node->right = delNode(node->right, val);
        }
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = delNode(node->right, temp->data);
        }
        return node;
    }

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);

        if (val < node->data) {
            node->left = insert(node->left, val);
        }
        else if (val > node->data) {
            node->right = insert(node->right, val);
        }

        return node;
    }

    bool search(Node* node, int val) {
        if (!node) return false;
        
        if (val == node->data) {
            return true;
        }
        if (val < node->data) {
            return search(node->left, val);
        }
        else if (val > node->data) {
            return search(node->right, val);
        }

        return false;
    }

    void print(Node* node, int space = 0, int indent = 4) {
        if (!node) return;

        space += indent;
        print(node->right, space);

        cout << endl;
        for (int i = indent; i < space; i++) cout << " ";
        cout << node->data << endl;

        print(node->left, space);
    }

    void destroy(Node* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    ~BinarySearchTree () {
        destroy(root);
    }
};

int main() {
    BinarySearchTree t;

    t.root = t.insert(t.root, 50);
    t.insert(t.root, 30);
    t.insert(t.root, 70);
    t.insert(t.root, 20);
    t.insert(t.root, 40);
    t.insert(t.root, 60);
    t.insert(t.root, 80);

    t.print(t.root);
}