#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class Doubly {
private:
    Node* head;
    Node* tail;
public:
    Doubly() : head(nullptr), tail(nullptr) {}

    void PUSH(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void DELV(int value) {
        if (!head) return;

        Node* temp = head;

        while (temp && temp->data != value) {
            temp = temp->next;
        }

        if (!temp) return;

        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        
        if (temp == head) {
            head = temp->next;
            if (head) {
                head->prev = nullptr;
            }
        }

        if (temp == tail) {
            tail = temp->prev;
            if (tail) {
                tail->next = nullptr;
            }
        }
        
        delete temp;
    }

    void PRINT() {
        Node* temp = head;
        while(temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {
    Doubly d;

    d.PUSH(1);
    d.PUSH(2);
    d.PUSH(3);

    d.DELV(1);

    d.PRINT();
}