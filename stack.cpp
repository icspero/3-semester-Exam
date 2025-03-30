#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {}

    void PUSH(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void POP() {
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void PRINT() {
        Node* temp = top;
        while(temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Stack () {
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack s;

    s.PUSH(1);
    s.PUSH(2);
    s.PUSH(3);
    s.PUSH(4);
    s.POP();
    s.PRINT();
}