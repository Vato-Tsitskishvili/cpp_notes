#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(const vector<int>);

int main() {

    vector<int> positions;
    string firstName, middleName, lastName, result;
    int age, pos1, count = 0;
    char answer;
    bool cont = true, foundOnce = false;

    while (cont) {

        cout << "Enter your first name: ";
        getline(cin, firstName);
        result.append(firstName);
        cout << result << " size: " << result.size() << endl;
        result.append(" ");

        cout << "Enter your middle name: ";
        getline(cin, middleName);
        result.append(middleName);
        cout << result << " size: " << result.size() << endl;
        result.append(" ");

        cout << "Enter your last name: ";
        getline(cin, lastName);
        result.append(lastName);
        cout << result << " size: " << result.size() << endl;
        result.append(" ");

        cout << "Enter your age: ";
        cin >> age;
        result.append(to_string(age));
        cout << result << " size: " << result.size() << endl;

        auto startPoint = result.begin();

        while (startPoint != result.end()) {
            startPoint = find(startPoint, result.end(), 'a');
            if (startPoint != result.end()) {
                auto const pos = distance(result.begin(), startPoint);
                positions.push_back(pos);
                startPoint++;
                foundOnce = true;
            }
        }

        cout << "char 'a' found on positions: ";
        printVector(positions);
        
        cout << "Do you want to continue(y/n): ";
        cin >> answer;

        if (answer == 'y') {
            result = "";
        }
        else if (answer == 'n') {
            result = "";
            cont = false;
            cout << "Have a nice day!";
        } else {
            cerr << "Not a char type";
        }
    }

    return 0;
}

void printVector(const vector<int> vec) {
    for (int element : vec)
        cout << element << " ";
    cout << endl;
}