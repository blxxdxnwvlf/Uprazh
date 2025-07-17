#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    double V1, V2;
    cout << "Введите начальную скорость V1 (км/ч): ";
    cin >> V1;
    cout << "Введите минимальную скорость V2 (км/ч): ";
    cin >> V2;

    if (V1 <= 0 || V2 <= 0) {
        cout << "Скорости должны быть положительными числами!" << endl;
        return 1;
    }

    if (V2 >= V1) {
        cout << "Минимальная скорость должна быть меньше начальной!" << endl;
        return 1;
    }

    vector<double> speeds;
    int lap = 1;
    double current_speed = V1;

    cout << "\nТаблица скоростей:\n";
    cout << "Круг\tСкорость (км/ч)\n";
    cout << "--------------------\n";

    while (current_speed >= V2) {
        speeds.push_back(current_speed);
        cout << lap << "\t" << fixed << setprecision(2) << current_speed << endl;

        current_speed *= 0.9; // Уменьшаем скорость на 10%
        lap++;
    }

    cout << "\nТренировку следует закончить на круге " << lap - 1 << endl;
    cout << "Скорость на последнем круге: " << speeds.back() << " км/ч" << endl;

    return 0;
}