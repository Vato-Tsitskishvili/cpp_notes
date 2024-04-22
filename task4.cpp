#include <iostream>
#include <ctime>

using namespace std;

int gcd(int, int);
int lcm(int, int);
void printArray(int [], int);

int main() {

    int A[10] = {};
    int aSize = sizeof(A) / sizeof(A[0]), oddMax = A[1], oddMaxI = 0, evenMin = A[0];

    srand(time(NULL));

    for (int i = 0; i < aSize; i++)
        A[i] = rand() % 31 - 10;

    for (int i = 0; i < aSize; i++) {
        if (i % 2 == 0 && evenMin > A[i]) evenMin = A[i];
        else if (oddMax < A[i]) {
            oddMax = A[i];
            oddMaxI = i;
        }
    }
    
    cout << "even index min number is: " << evenMin << endl;
    cout << "odd index max number is: " << oddMax << endl;

    printArray(A, aSize);

    int gcdV = gcd(evenMin, oddMax);
    int lcmV = lcm(evenMin, oddMax);

    cout << "gcd is: " << gcdV << endl;
    cout << "lcm is: " << lcmV << endl;

    A[oddMaxI] = gcdV;

    printArray(A, aSize);

    return 0;
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

void printArray(int array[], int size) {
    cout << "array: ";
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}