#include <iostream>
#include <iomanip>

using namespace std;

void matrixMultiplication(int A[3][3], int B[3][3], int C[3][3], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int C[3][3];

    matrixMultiplication(A, B, C, 3);

    cout << "Resultant matrix:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << setw(5) << C[i][j];
        }
        cout << endl;
    }
    return 0;
}

