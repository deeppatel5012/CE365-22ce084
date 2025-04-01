#include <iostream>
#include <string>

using namespace std;

class RDParser {
    string input;
    int pos;

public:
    RDParser(string str) : input(str), pos(0) {}

    bool S() {
        if (match('a')) {
            return true;
        } else if (match('(')) {
            if (L() && match(')')) {
                return true;
            }
        }
        return false;
    }

    bool L() {
        if (S()) {
            return LPrime();
        }
        return false;
    }

    bool LPrime() {
        if (match(',')) {
            if (S()) {
                return LPrime();
            }
            return false;
        }
        return true; // ε (epsilon) case
    }

    bool match(char expected) {
        if (pos < input.length() && input[pos] == expected) {
            pos++;
            return true;
        }
        return false;
    }

    bool parse() {
        return S() && pos == input.length();
    }
};

int main() {
    string testString;
    cout << "Enter a string: ";
    cin >> testString;

    RDParser parser(testString);
    if (parser.parse()) {
        cout << "Valid string" << endl;
    } else {
        cout << "Invalid string" << endl;
    }

    return 0;
}