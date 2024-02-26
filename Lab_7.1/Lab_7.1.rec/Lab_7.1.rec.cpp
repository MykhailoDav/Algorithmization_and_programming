#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
void Sort(int** a, const int rowCount, const int colCount, int i0, int i1);
void Change(int** a, const int row1, const int row2, const int colCount, int j);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int i, int j);

int main() {
    srand((unsigned)time(NULL));
    int Low = 4;
    int High = 51;
    int rowCount = 8;
    int colCount = 5;
    int** R = new int* [rowCount];
    for (int i = 0; i < rowCount; i++) {
        R[i] = new int[colCount];
    }
        
    Create(R, rowCount, colCount, Low, High, 0, 0);
    

    Print(R, rowCount, colCount, 0, 0);
    Sort(R, rowCount, colCount, 0, 0);
    cout << endl;
    Print(R, rowCount, colCount, 0, 0);
    int S = 0;
    int k = 0;
    Calc(R, rowCount, colCount, S, k, 0, 0);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(R, rowCount, colCount, 0, 0);

    for (int i = 0; i < rowCount; i++)
        delete[] R[i];
    delete[] R;
    return 0;
}

void Create(int** R, const int rowCount, const int colCount, const int Low, const int High, int i, int j) {
    if (i < rowCount) {
        if (j < colCount) {
            R[i][j] = Low + rand() % (High - Low + 1);
            Create(R, rowCount, colCount, Low, High, i, j + 1);
        }
        else {
            Create(R, rowCount, colCount, Low, High, i + 1, 0);
        }
    }
}

void Print(int** R, const int rowCount, const int colCount, int i, int j) {
  
    if (i < rowCount) {
        if (j < colCount) {
            cout << setw(4) << R[i][j];
            Print(R, rowCount, colCount, i, j + 1);
        }
        else {
            cout << endl;
            Print(R, rowCount, colCount, i + 1, 0);
        }
    }
}

void Sort(int** R, const int rowCount, const int colCount, int i0, int i1) {
    if (i0 < rowCount - 1) {
        if (i1 < rowCount - i0 - 1) {
            if ((R[i1][0] > R[i1 + 1][0]) ||
                (R[i1][0] == R[i1 + 1][0] &&
                 R[i1][1] < R[i1 + 1][1]) ||
                (R[i1][0] == R[i1 + 1][0] &&
                    R[i1][1] == R[i1 + 1][1] &&
                    R[i1][2] < R[i1 + 1][2])) {
                Change(R, i1, i1 + 1, colCount, 0);
            }
            Sort(R, rowCount, colCount, i0, i1 + 1);
        }
        else {
            Sort(R, rowCount, colCount, i0 + 1, 0);
        }
    }
}

void Change(int** R, const int row1, const int row2, const int colCount, int j) {
    if (j < colCount) {
        int tmp = R[row1][j];
        R[row1][j] = R[row2][j];
        R[row2][j] = tmp;
        Change(R, row1, row2, colCount, j + 1);
    }
}

void Calc(int** R, const int rowCount, const int colCount, int& S, int& k, int i, int j) {
    if (i < rowCount) {
        if (j < colCount) {
            if (!(R[i][j] % 2 != 0 || (i % 3 == 0 && j % 3 == 0))) {
                S += R[i][j];
                k++;
                R[i][j] = 0;
            }
            Calc(R, rowCount, colCount, S, k, i, j + 1);
        }
        else {
            Calc(R, rowCount, colCount, S, k, i + 1, 0);
        }
    }
}
