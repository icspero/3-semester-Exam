#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
public:
    Node* root;

    AVLTree() : root(nullptr) {}

    // Вставка в AVL дерево
    Node* insert(Node* node, int key) {
        // Шаг 1: Обычная вставка в бинарное дерево поиска
        if (!node) return new Node(key);

        if (key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);
        else
            return node; // Дубликаты не добавляются

        // Шаг 2: Обновление высоты текущего узла
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // Шаг 3: Балансировка дерева
        int balance = getBalance(node);

        // Если узел стал несбалансированным, то выполняем повороты

        // Левый левый случай
        if (balance > 1 && key < node->left->data)
            return rightRotate(node);

        // Правый правый случай
        if (balance < -1 && key > node->right->data)
            return leftRotate(node);

        // Левый правый случай
        if (balance > 1 && key > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Правый левый случай
        if (balance < -1 && key < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Удаление узла из AVL дерева
    Node* deleteNode(Node* root, int key) {
        if (!root) return root;

        // Шаг 1: Обычное удаление
        if (key < root->data)
            root->left = deleteNode(root->left, key);
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        else {
            // Узел с одним или двумя потомками
            if (!root->left || !root->right) {
                Node* temp = root->left ? root->left : root->right;
                if (!temp) {
                    temp = root;
                    root = nullptr;
                } else {
                    *root = *temp;
                }
                delete temp;
            } else {
                // Узел с двумя потомками
                Node* temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }

        if (!root) return root;

        // Шаг 2: Обновляем высоту текущего узла
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        // Шаг 3: Балансировка дерева
        int balance = getBalance(root);

        // Левый левый случай
        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        // Правый правый случай
        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        // Левый правый случай
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Правый левый случай
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    // Печать дерева в порядке Inorder
    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

private:
    // Получить высоту узла
    int getHeight(Node* node) {
        if (!node) return 0;
        return node->height;
    }

    // Получить баланс узла
    int getBalance(Node* node) {
        if (!node) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    // Правый поворот
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Поворот
        x->right = y;
        y->left = T2;

        // Обновление высот
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    // Левый поворот
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Поворот
        y->left = x;
        x->right = T2;

        // Обновление высот
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    // Найти узел с минимальным значением в дереве
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left) current = current->left;
        return current;
    }
};

int main() {
    AVLTree tree;

    // Вставка элементов в дерево
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 25);
    tree.root = tree.insert(tree.root, 15);

    cout << "Inorder traversal of AVL tree: ";
    tree.inorder(tree.root);
    cout << endl;

    // Удаление элемента
    tree.root = tree.deleteNode(tree.root, 20);

    cout << "Inorder traversal after deletion of 20: ";
    tree.inorder(tree.root);
    cout << endl;

    return 0;
}
