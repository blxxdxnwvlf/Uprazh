#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double calculateF(double x, double y) {
    if (x > 0 && y > 0) {
        return 1 - exp(-(x + y));
    }
    else if (x > 0 && y < 0) {
        return x + y;
    }
    else {
        return pow(sin(x + y), 2);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    const double step = 0.5;
    const double y_start = 0.0;
    const double y_end = 2.5;
    const double x_start = 0.0;
    const double x_end = 2.5;

    cout << "y\\x |";
    for (double x = x_start; x <= x_end + 1e-6; x += step) {
        cout << setw(10) << fixed << setprecision(1) << x;
    }
    cout << endl;

    cout << "----+";
    for (double x = x_start; x <= x_end + 1e-6; x += step) {
        cout << "----------";
    }
    cout << endl;

    for (double y = y_start; y <= y_end + 1e-6; y += step) {
        cout << setw(3) << fixed << setprecision(1) << y << " |";
        for (double x = x_start; x <= x_end + 1e-6; x += step) {
            cout << setw(10) << fixed << setprecision(4) << calculateF(x, y);
        }
        cout << endl;
    }

    return 0;
}