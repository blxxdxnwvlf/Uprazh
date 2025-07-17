#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void generateRandomArray(int* arr, int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 - 50;
    }
}

void mergeArrays(int* arr1, int* arr2, int* result, int size) {
    for (int i = 0; i < size; i++) {
        result[2 * i] = arr1[i];
        result[2 * i + 1] = arr2[i];
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int SIZE = 5;
    int arr1[SIZE], arr2[SIZE], merged[SIZE * 2];

    cout << "Генерация первого массива:\n";
    generateRandomArray(arr1, SIZE);
    cout << "Первый массив: ";
    for (int i = 0; i < SIZE; i++) cout << arr1[i] << " ";
    cout << endl;

    cout << "Генерация второго массива:\n";
    generateRandomArray(arr2, SIZE);
    cout << "Второй массив: ";
    for (int i = 0; i < SIZE; i++) cout << arr2[i] << " ";
    cout << endl;

    mergeArrays(arr1, arr2, merged, SIZE);
    cout << "Объединенный массив: ";
    for (int i = 0; i < SIZE * 2; i++) cout << merged[i] << " ";

    return 0;
}