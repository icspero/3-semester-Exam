#include <iostream>
#include <vector> 
using namespace std;

class Employee {
protected:
    int typeEmployee;
public:
    void setType(int type) {
        typeEmployee = type;
    }

    const int display() {
        return typeEmployee;
    }

    virtual double calculateSalary() = 0;
};

class regularEmployee : public Employee {
private:
    double finalSalary;
public:
    void setSalary(double salary) {
        finalSalary = salary;
    }

    double calculateSalary() override {
        return finalSalary;
    }
};

class hourEmployee : public Employee {
private:
    double salaryForHour;
    double hours;
public:
    hourEmployee(double salary, double h) : salaryForHour(salary), hours(h) {}

    double calculateSalary() override {
        return salaryForHour * hours;
    }
};

class orderEmployee : public Employee {
private:
    double salaryForOrder;
    double orders;
public:
    orderEmployee(double salary, double o) : salaryForOrder(salary), orders(o) {}

    double calculateSalary() override {
        return salaryForOrder * orders;
    }
};

int main() {

    int T;
    cin >> T;

    vector<Employee*> emps;

    for (int i = 0; i < T; i++) {
        int type;
        cin >> type;
        Employee* emp = nullptr;

        if (type == 1) {
            double salary;
            cin >> salary;
            emp = new regularEmployee();
            static_cast<regularEmployee*>(emp)->setSalary(salary);
        }
        else if (type == 2) {
            double salary;
            double hours;
            cin >> salary >> hours;
            emp = new hourEmployee(salary, hours);
        }
        else if (type == 3) {
            double salary;
            double orders;
            cin >> salary >> orders;
            emp = new orderEmployee(salary, orders);
        }

        if (emp) {
            emp->setType(i + 1);
            emps.push_back(emp);
        }
    }

    cout << endl << "    Salary" << endl;
    for (auto emp : emps) {
        cout << emp->display() << " " << emp->calculateSalary() << endl;
        delete emp;
    }

}