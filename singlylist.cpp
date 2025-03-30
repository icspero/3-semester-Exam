#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Singly {
private:
    Node* head;
public:
    Singly() : head(nullptr) {}

    void PUSH(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void DELV(int val) {
        Node* prev = head;
        Node* current = head->next;

        // Удаление из середины
        while (current) {
            if (current->data == val) {
                prev->next = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    } 

    void PRINT() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};

int main() {
    Singly s;

    s.PUSH(1);
    s.PUSH(2);
    s.PUSH(3);
    s.PUSH(4);
}
