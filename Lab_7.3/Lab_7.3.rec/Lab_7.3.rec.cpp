#include <iostream>
#include <iomanip>
using namespace std;

void Input(int** a, const int n, int i = 0, int j = 0) {
    if (i < n) {
        if (j < n) {
            cout << "a[" << (i + 1) << "][" << (j + 1) << "] = ";
            cin >> a[i][j];
            Input(a, n, (j == n - 1) ? i + 1 : i, (j == n - 1) ? 0 : j + 1);
        }
    }
}
void Print(int** a, const int n, int i = 0, int j = 0) {
    if (i < n) {
        if (j < n) {
            cout << setw(4) << a[i][j];
            Print(a, n, (j == n - 1) ? i + 1 : i, (j == n - 1) ? 0 : j + 1);
        }
        else if (j == n) {
            cout << endl;
            Print(a, n, i, j + 1);
        }
    }
}
void print(int* a, const int size, int i = 0) {
    if (i < size) {
        cout << "k" << i + 1 << " = " << a[i] << endl;
        print(a, size, i + 1);
    }
}
void checkK(int** a, const int n, int* K, int& count, int k, int i = 0) {
    if (i < n) {
        if (a[k][i] != a[i][k]) 
            return;         
        checkK(a, n, K, count, k, i + 1);
    }
    else {
        K[count] = k + 1;
        count++;
    }
}
void if_K_equal_K(int** a, const int n, int* K, int& count, int k = 0) {
    if (k < n) {
        checkK(a, n, K, count, k);
        if_K_equal_K(a, n, K, count, k + 1);
    }
}
int sumOfRow(int* row, const int n, int& ifNegative, int i = 0, int sum = 0) {
    if (i < n) {
        if (row[i] < 0) {
            ifNegative++;
        }
        return sumOfRow(row, n, ifNegative, i + 1, (row[i] < 0) ? sum + row[i] : sum);
    }
    return sum;
}
int sumOfRowsWithNegative(int** a, const int n, int& ifNegative, int i = 0, int sum = 0) {
    if (i < n) {
        int rowSum = sumOfRow(a[i], n, ifNegative);
        return sumOfRowsWithNegative(a, n, ifNegative, i + 1, (rowSum < 0) ? sum + rowSum : sum);
    }
    return sum;
}
int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;
    int** a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }
    Input(a, n);
    cout << "Your matrix: " << endl;
    Print(a, n);

    int* K = new int[n];
    int count = 0;
    if_K_equal_K(a, n, K, count);

    if (count != 0) {
        print(K, count);
    }
    else {
        cout << "Error: k is missing" << endl;
    }

    int ifNegative = 0;
    int sum = sumOfRowsWithNegative(a, n, ifNegative);

    if (ifNegative == 0) {
        cout << "Error: no negative elements";
    }
    else {
        cout << "Sum of elements in rows with negative values: " << sum << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
    delete[] K;

    return 0;
}
