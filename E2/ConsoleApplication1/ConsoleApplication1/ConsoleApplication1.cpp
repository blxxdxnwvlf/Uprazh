#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    char choice;
    do {
        double w, h1, r, h2;
        cout << "Введите ширину коробки (w): ";
        cin >> w;
        cout << "Введите высоту коробки (h1): ";
        cin >> h1;
        cout << "Введите радиус основания ведерка (r): ";
        cin >> r;
        cout << "Введите высоту ведерка (h2): ";
        cin >> h2;

        double boxVolume = w * w * h1;
        double bucketVolume = 3.141592653589793 * r * r * h2;

        cout << fixed << setprecision(2);
        cout << "Объем коробки: " << boxVolume << endl;
        cout << "Объем ведерка: " << bucketVolume << endl;

        if (boxVolume > bucketVolume) {
            cout << "Коробка больше по объему." << endl;
        }
        else if (boxVolume < bucketVolume) {
            cout << "Ведерко больше по объему." << endl;
        }
        else {
            cout << "Объемы равны." << endl;
        }

        cout << "Хотите повторить расчет? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
} 