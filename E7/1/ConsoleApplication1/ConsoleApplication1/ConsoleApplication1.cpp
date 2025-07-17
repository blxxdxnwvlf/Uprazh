#include <iostream>
using namespace std;

int findFirstPositive(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) return i;
    }
    return -1;
}

int findFirstNegative(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) return i;
    }
    return -1;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    if (size <= 0) {
        cout << "Размер массива должен быть положительным числом!" << endl;
        return 1;
    }

    int* arr = new int[size];

    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Элемент " << i + 1 << ": ";
        cin >> arr[i];
    }

    int posIndex = findFirstPositive(arr, size);
    int negIndex = findFirstNegative(arr, size);

    if (posIndex != -1) {
        cout << "Первый положительный элемент: " << arr[posIndex] << " (индекс " << posIndex << ")" << endl;
    }
    else {
        cout << "Положительных элементов нет." << endl;
    }

    if (negIndex != -1) {
        cout << "Первый отрицательный элемент: " << arr[negIndex] << " (индекс " << negIndex << ")" << endl;
    }
    else {
        cout << "Отрицательных элементов нет." << endl;
    }

    delete[] arr;

    return 0;
}