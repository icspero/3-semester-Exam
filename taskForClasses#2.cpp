#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;
public:

    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    Time operator+(const Time& other) const {
        int totalSeconds = seconds + other.seconds;
        int totalMinutes = minutes + other.minutes + totalSeconds / 60;
        int totalHours = hours + other.hours + totalMinutes / 60;

        totalSeconds %= 60;
        totalMinutes %= 60;
        
        return Time(totalHours, totalMinutes, totalSeconds);
    }

    bool operator<(const Time& other) const {
        int totalTime1 = hours * 3600 + minutes * 60 + seconds;
        int totalTime2 = other.hours * 3600 + other.minutes * 60 + other.seconds;
        return totalTime1 < totalTime2;
    }

    bool operator!=(const Time& other) const {
        int totalTime1 = hours * 3600 + minutes * 60 + seconds;
        int totalTime2 = other.hours * 3600 + other.minutes * 60 + other.seconds;
        return totalTime1 != totalTime2;
    }

    void display() const {
        cout << setw(2) << setfill('0') << hours << ":" 
             << setw(2) << setfill('0') << minutes << ":" 
             << setw(2) << setfill('0') << seconds;
    }
};

int main() {
    Time t1(0, 50, 0);
    Time t2(0, 10, 0);

    Time sum = t1 + t2;
    sum.display();
}