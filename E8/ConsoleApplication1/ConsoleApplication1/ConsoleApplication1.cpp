#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

double calculatePopulation(double current, char year_type) {
    switch (year_type) {
    case 'g': return current * 2.0;       
    case 'n': return current * 1.25;      
    case 'b': return current * 0.75;      
    default: return current;              
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    int N;
    double M;

    cout << "Введите начальное количество кроликов (M): ";
    cin >> M;
    cout << "Введите количество лет (N): ";
    cin >> N;

    vector<char> years(N);
    vector<double> population(N + 1);
    population[0] = M; 

    for (int i = 0; i < N; i++) {
        cout << "Введите тип года " << 1990 + i << " (g - хороший, n - обычный, b - плохой): ";
        cin >> years[i];
    }

    for (int i = 1; i <= N; i++) {
        population[i] = calculatePopulation(population[i - 1], years[i - 1]);
    }

    cout << "\nГод\tТип года\tПопуляция\n";
    cout << "--------------------------------\n";
    cout << 1990 << "\tНачало\t\t" << fixed << setprecision(0) << M << endl;

    for (int i = 0; i < N; i++) {
        string year_type;
        switch (years[i]) {
        case 'g': year_type = "Хороший"; break;
        case 'n': year_type = "Обычный"; break;
        case 'b': year_type = "Плохой"; break;
        }

        cout << 1990 + i + 1 << "\t" << year_type << "\t\t"
            << fixed << setprecision(0) << population[i + 1] << endl;
    }

    cout << "\nИтоговая популяция после " << N << " лет: "
        << fixed << setprecision(0) << population[N] << endl;

    return 0;
}