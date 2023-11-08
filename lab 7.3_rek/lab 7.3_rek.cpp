#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

void Create(int** a, const int row, const int col, const int Low, const int High, int i = 0, int j = 0)
{
    if (i == row) {
        return;
    }
    else if (j == col) {
        Create(a, row, col, Low, High, i + 1, 0);
    }
    else {
        a[i][j] = Low + rand() % (High - Low + 1);
        Create(a, row, col, Low, High, i, j + 1);
    }
}

void Print(int** a, const int row, const int col, int i = 0, int j = 0)
{
    if (i == row) {
        return;
    }
    else if (j == col) {
        cout << endl;
        Print(a, row, col, i + 1, 0);
    }
    else {
        cout << setw(4) << a[i][j];
        Print(a, row, col, i, j + 1);
    }
}

int SumWithoutNegatives(int** a, const int row, const int col, int i = 0, int j = 0)
{
    if (j == col) {
        return 0;
    }
    else if (i == row) {
        return SumWithoutNegatives(a, row, col, 0, j + 1);
    }
    else {
        bool hasNegative = false;
        for (int k = 0; k < row; k++) {
            if (a[k][j] < 0) {
                hasNegative = true;
                break;
            }
        }
        if (!hasNegative) {
            return a[i][j] + SumWithoutNegatives(a, row, col, i + 1, j);
        }
        else {
            return SumWithoutNegatives(a, row, col, i + 1, j);
        }
    }
}

void DiagonalSum(int** a, const int row, const int col, int i = 0, int j = 0, int sum = 0, int minSum = INT_MAX)
{
    if (i == row) {
        if (sum < minSum) {
            minSum = sum;
        }
        if (j < col - 1) {
            DiagonalSum(a, row, col, 0, j + 1, 0, minSum);
        }
        else {
            cout << "Минимальная сумма абсолютных значений диагоналей: " << minSum << endl;
        }
    }
    else if (j < col) {
        DiagonalSum(a, row, col, i + 1, j + 1, sum + abs(a[i][j]), minSum);
    }
}


int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand((unsigned)time(NULL));
    int Low = -17;
    int High = 15;
    int row, col;
    cout << "row = "; cin >> row;
    cout << "col = "; cin >> col;

    int** a = new int* [row];
    for (int i = 0; i < row; i++)
        a[i] = new int[col];

    Create(a, row, col, Low, High);
    Print(a, row, col);

    int sumWithoutNegatives = SumWithoutNegatives(a, row, col);
    cout << "Сумма элементов в столбцах без минусов: " << sumWithoutNegatives << endl;

    DiagonalSum(a, row, col);

    for (int i = 0; i < row; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
