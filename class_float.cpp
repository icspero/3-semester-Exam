#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;   // числитель
    int denominator; // знаменатель

public:
    // Конструктор
    Fraction(int num = 0, int denom = 1) {
        numerator = num;
        denominator = denom;
    }

    // Операции сравнения
    bool operator==(const Fraction& other) const {
        return numerator * other.denominator == other.numerator * denominator;
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator>(const Fraction& other) const {
        return other < *this;
    }

    // Арифметические операции
    Fraction operator+(const Fraction& other) const {
        int commonDenom = denominator * other.denominator;
        int num = numerator * other.denominator + other.numerator * denominator;
        return Fraction(num, commonDenom);
    }

    Fraction operator-(const Fraction& other) const {
        int commonDenom = denominator * other.denominator;
        int num = numerator * other.denominator - other.numerator * denominator;
        return Fraction(num, commonDenom);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    // Вывод
    void print() const {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    Fraction f1(1, 2); // 1/2
    Fraction f2(3, 4); // 3/4

    cout << "f1: ";
    f1.print();
    cout << "f2: ";
    f2.print();

    Fraction sum = f1 + f2;
    cout << "f1 + f2 = ";
    sum.print();

    Fraction diff = f1 - f2;
    cout << "f1 - f2 = ";
    diff.print();

    Fraction product = f1 * f2;
    cout << "f1 * f2 = ";
    product.print();

    // Сравнение
    if (f1 == f2)
        cout << "f1 и f2 равны." << endl;
    else
        cout << "f1 и f2 не равны." << endl;

    return 0;
}
