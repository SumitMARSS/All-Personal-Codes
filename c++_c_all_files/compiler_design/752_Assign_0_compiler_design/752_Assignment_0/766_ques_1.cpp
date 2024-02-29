#include <bits/stdc++.h>
using namespace std;

// Function to check if a word is a valid identifier
bool isValidIdentifier(const string& word) {
    if (!isalpha(word[0]) && word[0] != '_') {
        return false; // An identifier should start with a letter or an underscore
    }

    for (char c : word) {
        if (!isalnum(c) && c != '_') {
            return false; // An identifier can only contain letters, digits, and underscores
        }
    }

    return true;
}

int main() {
    ifstream inputFile("input.cpp");
    unordered_set<string> identifiers;
    string word;
    while (inputFile >> word) {
        if (isValidIdentifier(word)) {
            identifiers.insert(word);
        }
    }
    inputFile.close();
    cout << "Identifiers found in the source code:" << endl;
    for (const string& identifier : identifiers) {
        cout << identifier << endl;
    }
    return 0;
}
