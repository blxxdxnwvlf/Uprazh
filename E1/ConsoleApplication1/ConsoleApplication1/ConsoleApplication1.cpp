#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    double N, P;
    cout << "Введите количество листов бумаги (N): ";
    cin >> N;
    cout << "Введите плотность бумаги (P) в г/см²: ";
    cin >> P;

    double weight = N * P;

    cout << fixed << setprecision(2);
    cout << "Вес пачки бумаги: " << weight << " г" << endl;

    return 0;
}