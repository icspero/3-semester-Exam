#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class CompleteBinaryTree {
public:
    Node* root;

    CompleteBinaryTree() : root(nullptr) {}

    // Вставка элемента в полное бинарное дерево
    void insert(int value) {
        root = insertRec(root, value, 0);
    }

    // Поиск элемента в дереве
    bool search(int value) {
        return searchRec(root, value);
    }

    // Проверка, является ли дерево полным
    bool isComplete() {
        return isCompleteRec(root, 0, countNodes(root));
    }

private:
    // Рекурсивная вставка
    Node* insertRec(Node* node, int value, int index) {
        if (!node) {
            node = new Node(value);
            return node;
        }

        int totalNodes = countNodes(root); // Общее количество узлов в дереве
        if (index < totalNodes / 2) {
            if (index * 2 + 1 < totalNodes) {
                node->left = insertRec(node->left, value, 2 * index + 1);
            }
            if (index * 2 + 2 < totalNodes) {
                node->right = insertRec(node->right, value, 2 * index + 2);
            }
        }

        return node;
    }

    // Рекурсивный поиск элемента
    bool searchRec(Node* node, int value) {
        if (!node) return false;
        if (node->data == value) return true;
        return searchRec(node->left, value) || searchRec(node->right, value);
    }

    // Рекурсивная проверка, является ли дерево полным
    bool isCompleteRec(Node* node, int index, int totalNodes) {
        if (!node) return true;
        if (index >= totalNodes) return false;
        return isCompleteRec(node->left, 2 * index + 1, totalNodes) &&
               isCompleteRec(node->right, 2 * index + 2, totalNodes);
    }

    // Подсчёт общего количества узлов в дереве
    int countNodes(Node* node) {
        if (!node) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    // Вспомогательная функция для обхода дерева в Inorder
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    // Вывод дерева в Inorder
    void printInorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    CompleteBinaryTree tree;

    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);

    cout << "Inorder traversal of the tree: ";
    tree.printInorder(); // Ожидаемый вывод: 4 2 5 1 6 3

    // Поиск элемента в дереве
    int value = 5;
    if (tree.search(value)) {
        cout << "Element " << value << " is found in the tree." << endl;
    } else {
        cout << "Element " << value << " is not found in the tree." << endl;
    }

    // Проверка, является ли дерево полным
    if (tree.isComplete()) {
        cout << "The tree is complete." << endl;
    } else {
        cout << "The tree is not complete." << endl;
    }

    return 0;
}