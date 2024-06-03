#include <iostream>
#include <limits>

using namespace std;

const int ROW = 3;
const int COL = 4;

int main() {

    int A[ROW][COL] = {};
    int B[ROW][COL] = {};
    int minSum = INT_MAX, iMin = 0, jMin = 0;

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    B[2][3] = A[2][3];

    for (int i = ROW - 1; i >= 0; i--)
        B[i][3] = B[i - 1][3] + A[i][3];

    for (int j = COL - 1; j >= 0; j--)
        B[2][j] = B[2][j - 1] + A[2][j];

    for (int i = ROW - 1; i >= 0; i--) {
        for (int j = COL - 1; j >= 0; j--) {
            B[i][j] = A[i][j] + B[i + 1][j] + B[i][j + 1] - B[i + 1][j + 1];
        }
    }

    for (int i = ROW - 1; i >= 0; i--) {
        for (int j = COL - 2; j >= 0; j--) {
            if (B[i][j] < minSum) {
                minSum = B[i][j];
                iMin = i;
                jMin = j;
            }
        }
    }

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Min Sum is: " << minSum << " at " << iMin << " " << jMin << endl;

    return 0;
}