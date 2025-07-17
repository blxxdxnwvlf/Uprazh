#include <iostream>

using namespace std;

int Kvadr(double x, double y) {
    if (x > 0 && y > 0) return 1;
    if (x < 0 && y > 0) return 2;
    if (x < 0 && y < 0) return 3;
    if (x > 0 && y < 0) return 4;
    return 0;
}

int main() {
    setlocale(LC_ALL, "Russian");

    double test_points[5][2] = {
        {1, 1},
        {-1, 1},
        {-1, -1},
        {1, -1},
        {0, 0}
    };

    cout << "Проверка функции Kvadr(x, y):" << endl;
    cout << "x\ty\tЧетверть" << endl;
    cout << "---------------------" << endl;

    for (int i = 0; i < 5; i++) {
        double x = test_points[i][0];
        double y = test_points[i][1];
        int quadrant = Kvadr(x, y);

        cout << x << "\t" << y << "\t";
        if (quadrant == 0) {
            cout << "На оси или в начале координат";
        }
        else {
            cout << quadrant << " четверть";
        }
        cout << endl;
    }

    return 0;
}