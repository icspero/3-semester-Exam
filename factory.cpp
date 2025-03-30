#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() = 0;
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Woof Woof" << endl;
    }
};

class Cat : public Animal {
    public:
        void speak() override {
            cout << "Meow Meow" << endl;
        }
    };

class Factory {
public:
    static Animal* create() { return new Cat(); }
};

int main() {
    Animal* pet = Factory::create();
    pet->speak();
    delete pet;
}