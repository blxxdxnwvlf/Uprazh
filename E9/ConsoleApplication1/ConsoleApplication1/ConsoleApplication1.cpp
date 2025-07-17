#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

void inputMatrix(vector<vector<int>>& matrix, int n) {
    matrix.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> matrix[i][j];
        }
    }
}

void findMinMax(const vector<vector<int>>& matrix, int& minVal, int& maxVal, pair<int, int>& minPos, pair<int, int>& maxPos) {
    minVal = numeric_limits<int>::max();
    maxVal = numeric_limits<int>::min();
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
                minPos = { i, j };
            }
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
                maxPos = { i, j };
            }
        }
    }
}

void printMatrix(const vector<vector<int>>& matrix, const pair<int, int>& minPos, const pair<int, int>& maxPos) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            if ((i == minPos.first && j == minPos.second) || (i == maxPos.first && j == maxPos.second)) {
                cout << "\033[1;31m" << setw(4) << matrix[i][j] << "\033[0m";
            }
            else {
                cout << setw(4) << matrix[i][j];
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix;
    inputMatrix(matrix, n);
    int minVal, maxVal;
    pair<int, int> minPos, maxPos;
    findMinMax(matrix, minVal, maxVal, minPos, maxPos);
    printMatrix(matrix, minPos, maxPos);
    return 0;
}