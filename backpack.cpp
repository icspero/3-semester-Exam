#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для нахождения максимальной ценности
int knapsack(int W, const vector<int>& weights, const vector<int>& values, int n) {
    // Базовый случай: если нет предметов или вместимость рюкзака равна 0
    if (n == 0 || W == 0) {
        return 0;
    }

    // Если вес текущего предмета больше доступного веса, пропускаем его
    if (weights[n - 1] > W) {
        return knapsack(W, weights, values, n - 1);
    } else {
        // Возвращаем максимум между двумя случаями:
        // 1. Предмет включен
        // 2. Предмет исключен
        return max(values[n - 1] + knapsack(W - weights[n - 1], weights, values, n - 1),
                   knapsack(W, weights, values, n - 1));
    }
}

int main() {
    int W = 50; // Вместимость рюкзака
    vector<int> values = {60, 100, 120}; // Ценности предметов
    vector<int> weights = {10, 20, 30}; // Веса предметов
    int n = values.size(); // Количество предметов

    int maxValue = knapsack(W, weights, values, n);
    cout << "Максимальная ценность: " << maxValue << endl;

    return 0;
}