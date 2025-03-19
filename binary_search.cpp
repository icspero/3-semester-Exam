#include <iostream>

using namespace std;

int binarySearch(int arr[], int left, int right, int target){
    if (left > right) {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (target == arr[mid]) {
        return mid;
    }
    else if (target > arr[mid]) {
        return binarySearch(arr, mid + 1, right, target);
    }
    else {
        return binarySearch(arr, left, mid - 1, target);
    }
}

int main() {
    int arr[] = {1, 5, 7, 9, 15, 34, 87, 102, 1091};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 87;

    int res = binarySearch(arr, 0, n - 1, target);
    if (res != -1) { 
        cout << "Элемент найден по индексу: " << res << endl;
    }
    else {
        cout << "Элемент не найден!" << endl;
    }
}

