#include <iostream>
#include <numeric> // Для std::gcd

using namespace std;

class Fraction {
private:
    int numerator;   // Числитель
    int denominator; // Знаменатель

    // Сокращение дроби
    void simplify() {
        int gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;

        // Если знаменатель отрицательный, переносим знак к числителю
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // Конструктор по умолчанию
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (den == 0) {
            throw invalid_argument("Знаменатель не может быть равен 0");
        }
        simplify();
    }

    // Операция сложения
    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    // Операция вычитания
    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    // Операция умножения
    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    // Операция деления
    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw invalid_argument("Деление на ноль невозможно");
        }
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Fraction(num, den);
    }

    // Операция сравнения (меньше)
    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    // Операция сравнения (равно)
    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    // Операция сравнения (больше)
    bool operator>(const Fraction& other) const {
        return numerator * other.denominator > other.numerator * denominator;
    }

    // Вывод дроби
    friend ostream& operator<<(ostream& os, const Fraction& fraction) {
        os << fraction.numerator;
        if (fraction.denominator != 1) {
            os << "/" << fraction.denominator;
        }
        return os;
    }
};

int main() {
    try {
        Fraction a(3, 4); // 3/4
        Fraction b(2, 5); // 2/5

        cout << "Дробь A: " << a << endl;
        cout << "Дробь B: " << b << endl;

        cout << "A + B = " << (a + b) << endl;
        cout << "A - B = " << (a - b) << endl;
        cout << "A * B = " << (a * b) << endl;
        cout << "A / B = " << (a / b) << endl;

        cout << "A < B: " << (a < b ? "true" : "false") << endl;
        cout << "A == B: " << (a == b ? "true" : "false") << endl;
        cout << "A > B: " << (a > b ? "true" : "false") << endl;
    } catch (const invalid_argument& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}
