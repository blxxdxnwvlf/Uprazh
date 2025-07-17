#include <iostream>
using namespace std;

void inputArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Введите элемент " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void outputArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void removeFirstPositive(int* arr, int& size) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }
}

void removeFirstNegative(int* arr, int& size) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int SIZE = 5;
    int arr[SIZE];
    int currentSize = SIZE;

    cout << "Ввод массива:\n";
    inputArray(arr, SIZE);

    cout << "Исходный массив: ";
    outputArray(arr, SIZE);

    removeFirstPositive(arr, currentSize);
    removeFirstNegative(arr, currentSize);

    cout << "Массив после удаления: ";
    outputArray(arr, currentSize);

    return 0;
}