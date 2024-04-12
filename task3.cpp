#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

int gcd(int, int);
int lcm(int, int);

int main() {

    const int area = 50;
    int sum, gcdValue, lcmValue;

    srand(time(NULL));

    for (int i = 1; i <= area; i++) {
        for (int j = 1; j <= area; j++) {
            int c = i * i + j * j;
            if ((i * i + j * j == c) && (i * j / 2 == area)) {
                cout << "i: " << i << endl;
                cout << "j: " << j << endl;

                sum = i + j;

                vector<int> vec(sum);

                for (int k = 0; k < vec.size(); k++) 
                    vec.at(k) = rand() % 100;

                auto min = min_element(vec.begin(), vec.end());
                auto max = max_element(vec.begin(), vec.end());

                cout << "min element is: " << *min << endl;
                cout << "max element is: " << *max << endl;

                gcdValue = gcd(*min, *max);
                lcmValue = lcm(*min, *max);

                cout << "min and max gcd is: " << gcdValue << endl;
                cout << "min and max lcm is: " << lcmValue << endl;
                cout << endl;
            }
        }
    }

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