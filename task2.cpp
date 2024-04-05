#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef vector<vector<int>> SpiralMatrix;

SpiralMatrix createSpiral(const int);
void printSpiral(const SpiralMatrix &spiral);

int main() { 

    SpiralMatrix spiral = createSpiral(3);

    printSpiral(spiral);

    return 0;
}

/*
1 2 3
8 0 4
7 6 5
*/

SpiralMatrix createSpiral(const int n) {
    vector<int> row(n);
    SpiralMatrix spiral(n, row);
    int value = 1, minCol = 0, maxCol = n - 1, minRow = 0, maxRow = n - 1;
        
    while (value <= n * n) {
        for (int i = minCol; i <= maxCol; i++) {
            spiral.at(minRow).at(i) = value;
            value++;
        }
            
        for (int i = minRow + 1; i <= maxRow; i++) { 
            spiral.at(i).at(maxCol) = value;
            value++;
        } 
            
        for (int i = maxCol - 1; i >= minCol; i--) {
            spiral.at(maxRow).at(i) = value;
            value++;
        }
            
        for (int i = maxRow - 1; i >= minRow + 1; i--) {
            spiral.at(i).at(minCol) = value;
            value++;
        }
            
        minCol++;
        minRow++;
        maxCol--;
        maxRow--;
    }

    return spiral;
}

void printSpiral(const SpiralMatrix &spiral) {
    for (int i = 0; i < spiral.size(); i++) {
        for (int j = 0; j < spiral.at(i).size(); j++) {
            cout << setw(4) << spiral.at(i).at(j);
        }
        cout << endl;
    }
}