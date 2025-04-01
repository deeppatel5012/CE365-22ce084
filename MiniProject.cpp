#include<bits/stdc++.h>
using namespace std;

// Function to check if a string is a valid identifier
bool isValidIdentifier(const string &identifier) {
    if (identifier.empty() || (!isalpha(identifier[0]) && identifier[0] != '_'))
        return false;

    for (char ch : identifier) {
        if (!isalnum(ch) && ch != '_') {
            return false;
        }
    }
    return true;
}

// Function to check if a value matches its expected data type
bool isValidValue(const string &value, const string &type) {
    regex intRegex("^-?[0-9]+$");
    regex floatRegex("^-?[0-9]*\\.[0-9]+$");
    regex charRegex("^'.'$");
    regex stringRegex("^\".*\"$");

    if (type == "int" && regex_match(value, intRegex)) return true;
    if (type == "float" && regex_match(value, floatRegex)) return true;
    if (type == "char" && regex_match(value, charRegex)) return true;
    if (type == "string" && regex_match(value, stringRegex)) return true;

    return false;
}

// Function to analyze the syntax of a C++ variable declaration
void analyzeSyntax(const string &statement) {
    vector<string> validTypes = {"int", "float", "char", "double", "string"};

    // Check if the statement ends with a semicolon
    if (statement.back() != ';') {
        cout << "Invalid Statement: Missing semicolon." << endl;
        return;
    }

    // Remove the semicolon for processing
    string trimmedStatement = statement.substr(0, statement.size() - 1);

    // Tokenize the statement
    istringstream iss(trimmedStatement);
    vector<string> tokens;
    string token;
    while (iss >> token) {
        tokens.push_back(token);
    }

    // Check for minimum required tokens
    if (tokens.size() < 2) {
        cout << "Invalid Statement: Incomplete declaration." << endl;
        return;
    }

    // Check if the first token is a valid data type
    if (find(validTypes.begin(), validTypes.end(), tokens[0]) == validTypes.end()) {
        cout << "Invalid Statement: Invalid data type." << endl;
        return;
    }

    // Check if the second token is a valid identifier
    if (!isValidIdentifier(tokens[1])) {
        cout << "Invalid Statement: Invalid variable name." << endl;
        return;
    }

    // If there are more than 2 tokens, check for assignment
    if (tokens.size() > 2) {
        if (tokens[2] != "=") {
            cout << "Invalid Statement: Expected '=' for assignment." << endl;
            return;
        }

        // Ensure there is a value after '='
        if (tokens.size() < 4) {
            cout << "Invalid Statement: Missing value for assignment." << endl;
            return;
        }

        // Validate the value according to the data type
        if (!isValidValue(tokens[3], tokens[0])) {
            cout << "Invalid Statement: Invalid value for data type " << tokens[0] << "." << endl;
            return;
        }
    }

    // If all checks pass, the statement is valid
    cout << "Valid Statement." << endl;
}

int main() {
    string statement;
    cout << "Enter a C++ variable declaration statement: ";
    getline(cin, statement);

    analyzeSyntax(statement);

    return 0;
}
