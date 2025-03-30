#include <iostream>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int data;

    Node(int value) : data(value), left(nullptr), right(nullptr) {} 
};

class FBT {
public:
    Node* root;

    FBT() : root(nullptr) {}

    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);

        if (node->left == nullptr) {
            node->left = insert(node->left, key);
        }
        else if (node->right == nullptr) {
            node->right = insert(node->right, key);
        }
        else {
            if (isFBT(node->left)) {
                node->right = insert(node->right, key);
            }
            else {
                node->left = insert(node->left, key);
            } 
        }

        return node;
    }

    bool isFBT(Node* node) {
        if (!node) return true;

        if (node->left == nullptr && node->right == nullptr) {
            return true;
        }

        if (node->left != nullptr && node->right != nullptr) {
            return isFBT(node->left) && isFBT(node->right);
        }

        return false;
    }

};