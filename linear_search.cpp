#include <iostream>
#include <vector>

using namespace std;

int linear_search(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i; // Элемент найден, возвращаем индекс
        }
    }
    return -1; // Элемент не найден
}

int main() {
    vector<int> arr = {5, 3, 8, 4, 2};
    int target = 4;
    int result = linear_search(arr, target);
    
    if (result != -1) {
        cout << "Элемент найден на индексе: " << result << endl;
    } else {
        cout << "Элемент не найден." << endl;
    }
    
    return 0;
}
