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

class Factory {
public:
    static Animal* create() { return new Dog(); }
};

int main() {
    Animal* pet = Factory::create();
    pet->speak();
    delete pet;
}