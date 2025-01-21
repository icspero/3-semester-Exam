#include <iostream>
#include <vector>

using namespace std;

void quicksort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int pivot = arr[right]; // Опорный элемент
        int i = left - 1;

        for (int j = left; j < right; ++j) {
            if (arr[j] < pivot) {
                ++i;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[right]);
        int partitionIndex = i + 1;

        quicksort(arr, left, partitionIndex - 1);
        quicksort(arr, partitionIndex + 1, right);
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    quicksort(arr, 0, arr.size() - 1);
    
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}