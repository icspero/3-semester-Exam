#include <iostream>
using namespace std;

// Структура узла бинарного дерева
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

// Класс бинарного дерева поиска
class BST {
private:
    // Вспомогательная функция для вставки
    Node* insert(Node* root, int key) {
        if (!root) return new Node(key);
        if (key < root->key)
            root->left = insert(root->left, key);
        else
            root->right = insert(root->right, key);
        return root;
    }

    // Вспомогательная функция поиска минимального узла в дереве
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left) {
            current = current->left;
        }
        return current;
    }

    // Вспомогательная функция удаления узла
    Node* deleteNode(Node* root, int key) {
        if (!root) return root;

        if (key < root->key) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->key) {
            root->right = deleteNode(root->right, key);
        } else {
            // Узел с одним или без детей
            if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Узел с двумя детьми: берем минимальный узел в правом поддереве
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
        return root;
    }

    // Вспомогательная функция для вывода (LNR - симметричный обход)
    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }

public:
    Node* root;

    BST() : root(nullptr) {}

    void insert(int key) { root = insert(root, key); }
    void deleteNode(int key) { root = deleteNode(root, key); }
    void inorder() { inorder(root); cout << endl; }
};

// Тестирование
int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout << "BST (inorder): ";
    tree.inorder();

    tree.deleteNode(50);
    cout << "BST после удаления 50: ";
    tree.inorder();

    return 0;
}