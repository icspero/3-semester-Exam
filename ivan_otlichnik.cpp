#include <iostream>
#include <vector>
#include <iomanip> // Для настройки точности вывода
using namespace std;

// Базовый класс Student, содержащий номер учащегося
class Student {
protected:
    int rollNumber; // Номер учащегося
public:
    // Конструктор для установки номера учащегося
    Student(int roll) : rollNumber(roll) {}
};

// Класс Test, наследующий Student и содержащий оценки
class Test : public Student {
protected:
    vector<float> scores; // Оценки учащегося по 5 предметам
public:
    // Конструктор для установки номера учащегося и его оценок
    Test(int roll, const vector<float>& marks) : Student(roll), scores(marks) {}
};

// Класс Result, наследующий Test и содержащий функцию Display()
class Result : public Test {
public:
    // Конструктор для передачи данных в базовые классы
    Result(int roll, const vector<float>& marks) : Test(roll, marks) {}

    // Функция Display() для вычисления общего и среднего баллов
    void Display() {
        float total = 0;
        for (float score : scores) {
            total += score;
        }
        float average = total / scores.size();

        // Вывод в формате: номер общий_балл средний_балл
        cout << rollNumber << " " << total << " " << fixed << setprecision(0) << average << endl;
    }
};

int main() {
    int T; // Количество тестовых случаев
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int rollNumber;
        cin >> rollNumber;

        vector<float> marks(5); // Оценки по 5 предметам
        for (int j = 0; j < 5; ++j) {
            cin >> marks[j];
        }

        // Создание объекта Result и вызов функции Display()
        Result student(rollNumber, marks);
        student.Display();
    }

    return 0;
}
