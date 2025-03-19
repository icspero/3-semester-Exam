#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        } 
    }
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {2,5,3,7,8,1,4,6,9};
    int n = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, n);
    cout << endl;
    bubbleSort(arr, n);
    printArray(arr, n);
}