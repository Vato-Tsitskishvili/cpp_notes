#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

void printMatrix(const vector<vector<int>> &);

int main() {

    int n;

    cout << "Matrix size: ";
    cin >> n;

    vector<int> row(n);
    vector<vector<int>> A(n, row);
    vector<vector<int>> B(n, row);
    int max = -INT_MAX, imax = 0, jmax = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A.at(i).at(j);
        }
    }

    B.at(0).at(0) = A.at(0).at(0);

    for (int j = 1; j < n; j++)
        B.at(0).at(j) = B.at(0).at(j - 1) + A.at(0).at(j);

    for (int i = 1; i < n; i++)
        B.at(i).at(0) = B.at(i - 1).at(0) + A.at(i).at(0);
    
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
            B.at(i).at(j) = A.at(i).at(j) + B.at(i - 1).at(j) + B.at(i).at(j - 1) - B.at(i - 1).at(j - 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (B.at(i).at(j) > max) {
                max = B.at(i).at(j);
                imax = i;
                jmax = j;
            }
        }
    }

    cout << "\nMatrix A:" << endl;
    printMatrix(A);
    cout << "Matrix B:" << endl;
    printMatrix(B);
    cout << "Max area rectangle is " << max << " on " << imax + 1 << " row and " << jmax + 1 << " column";

    return 0;
}

void printMatrix(const vector<vector<int>> &vector) {
    for (int i = 0; i < vector.size(); i++) {
        for (int j = 0; j < vector.at(i).size(); j++)
            cout << setw(4) << vector.at(i).at(j); 
        cout << endl;
    } 
    cout << endl;
}