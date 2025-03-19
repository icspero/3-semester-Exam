#include <iostream>
using namespace std;

// Структура узла BST
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Функция для поиска минимального узла в правом поддереве
Node* findMin(Node* root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

// Функция удаления узла в BST
Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Узел с одним или нулем потомков
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Узел с двумя потомками: берем минимальный в правом поддереве
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Вспомогательная функция для вставки узлов в BST
Node* insert(Node* root, int value) {
    if (!root) return new Node(value);
    if (value < root->data) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);
    return root;
}

// Функция для вывода дерева (симметричный обход)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "BST до удаления: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 50);

    cout << "BST после удаления 50: ";
    inorder(root);
    cout << endl;

    return 0;
}
