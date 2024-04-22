#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    vector<int> numbers = {};
    int counter = 0;

    for (int i = 100000; i < 1000000; i++) {
        string numb = to_string(i);
        if (numb.substr(0, 3).compare(numb.substr(numb.size() - 3)) == 0) {
            cout << "result number: " << i << endl;
            numbers.push_back(i);
            counter++;
        }
    }

    cout << "total of " << counter << " numbers" << endl;

    return 0;
}