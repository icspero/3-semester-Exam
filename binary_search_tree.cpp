#include <iostream>
using namespace std;

// Структура для представления узла бинарного дерева поиска
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // Конструктор для создания нового узла
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Функция для нахождения минимального значения в правом поддереве
TreeNode* findMin(TreeNode* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Функция для удаления узла с заданным значением
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) {
        return nullptr; // Узел не найден, ничего удалять не нужно
    }

    // Если ключ меньше значения текущего узла, идём в левое поддерево
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    }
    // Если ключ больше значения текущего узла, идём в правое поддерево
    else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    }
    // Если найден узел, который нужно удалить
    else {
        // Узел без дочерних узлов или с одним дочерним узлом
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Узел с двумя дочерними узлами: ищем минимальное значение в правом поддереве
        TreeNode* temp = findMin(root->right);

        // Копируем значение найденного узла в текущий узел
        root->val = temp->val;

        // Удаляем дубликат найденного узла в правом поддереве
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

// Функция для вставки узла в бинарное дерево поиска
TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    return root;
}

// Функция для вывода дерева (обход LNR - симметричный)
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    TreeNode* root = nullptr;

    // Вставка узлов в дерево
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Исходное дерево (inorder): ";
    inorderTraversal(root);
    cout << endl;

    int key;
    cout << "Введите значение для удаления: ";
    cin >> key;

    // Удаление узла
    root = deleteNode(root, key);

    cout << "Дерево после удаления " << key << " (inorder): ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
