#include <iostream>
using namespace std;

// Структура узла двоичного дерева
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Структура узла двусвязного списка
struct DLLNode {
    int val;
    DLLNode* prev;
    DLLNode* next;

    DLLNode(int value) : val(value), prev(nullptr), next(nullptr) {}
};

// Класс для преобразования дерева в двусвязный список
class BinaryTreeToDLL {
private:
    DLLNode* head = nullptr; // Головной узел двусвязного списка
    DLLNode* prev = nullptr; // Предыдущий узел в процессе преобразования

    // Рекурсивная функция преобразования
    void inorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        // Рекурсивный обход левого поддерева
        inorder(root->left);

        // Создание нового узла двусвязного списка
        DLLNode* current = new DLLNode(root->val);

        // Если это первый узел обхода, он становится головой списка
        if (head == nullptr) {
            head = current;
        } else {
            // Связываем текущий узел с предыдущим
            prev->next = current;
            current->prev = prev;
        }
        prev = current; // Обновляем предыдущий узел

        // Рекурсивный обход правого поддерева
        inorder(root->right);
    }

public:
    // Функция для преобразования
    DLLNode* convert(TreeNode* root) {
        inorder(root); // Запуск преобразования
        return head;   // Возвращаем головной узел двусвязного списка
    }

    // Функция для вывода двусвязного списка в прямом порядке
    void printForward(DLLNode* head) {
        DLLNode* temp = head;
        while (temp != nullptr) {
            cout << temp->val;
            if (temp->next != nullptr) {
                cout << "<=>";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    // Функция для вывода двусвязного списка в обратном порядке
    void printBackward(DLLNode* head) {
        DLLNode* tail = head;
        // Находим хвостовой узел
        while (tail->next != nullptr) {
            tail = tail->next;
        }

        // Обратный вывод
        while (tail != nullptr) {
            cout << tail->val;
            if (tail->prev != nullptr) {
                cout << "<=>";
            }
            tail = tail->prev;
        }
        cout << endl;
    }
};

int main() {
    // Создаём дерево
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->right->right = new TreeNode(60);

    // Преобразуем дерево в двусвязный список
    BinaryTreeToDLL converter;
    DLLNode* head = converter.convert(root);

    // Вывод двусвязного списка
    cout << "DLL в прямом порядке: ";
    converter.printForward(head);

    cout << "DLL в обратном порядке: ";
    converter.printBackward(head);

    return 0;
}
