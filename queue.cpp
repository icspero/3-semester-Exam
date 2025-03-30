#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
    Node* head;
    Node* tail;
public:
    Queue() : head(nullptr), tail(nullptr) {}

    void PUSH(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = tail = newNode;
        }

        tail->next = newNode;
        tail = newNode;
    }

    void PRINT() {
        Node* temp = head;
        while(temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void POP() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    ~Queue () {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {

    Queue q;

    q.PUSH(1);
    q.PUSH(2);
    q.PUSH(3);
    q.PUSH(4);

    q.POP();
    q.POP();

    q.PUSH(5);

    q.PRINT();

}