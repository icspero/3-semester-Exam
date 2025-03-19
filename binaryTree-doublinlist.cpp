#include <iostream>
using namespace std;

// Структура узла бинарного дерева
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Глобальные указатели
Node* head = nullptr; // Голова списка
Node* prev = nullptr; // Предыдущий узел

// Функция преобразования бинарного дерева в двусвязный список
void treeToDoublyLinkedList(Node* root) {
    if (!root) return;

    // Рекурсивно обрабатываем левое поддерево
    treeToDoublyLinkedList(root->left);

    // Связываем текущий узел с предыдущим
    if (::prev == nullptr) {
        head = root;
    }
    else {
        ::prev->right = root;
        root->left = ::prev;
    }
    ::prev = root;

    // Рекурсивно обрабатываем правое поддерево
    treeToDoublyLinkedList(root->right);
}

// Функция вывода двусвязного списка
void printDoublyLinkedList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->data;
        if (curr->right) cout << " <=> ";
        curr = curr->right;
    }
    cout << endl;
}

int main() {
    // Создаем бинарное дерево
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);

    // Преобразуем в двусвязный список
    treeToDoublyLinkedList(root);

    // Выводим двусвязный список
    cout << "DLL: ";
    printDoublyLinkedList(head);

    return 0;
}